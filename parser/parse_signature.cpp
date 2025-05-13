void parse_signature(const shared_ptr<Import>& imp, size_t& p, Memory& types) {
    if(imp->at(p)=="service") is_service = true;
    else if(imp->at(p)!="smo") imp->error(--p, "Missing `service` or `smo` to declare runtype");
    p++;
    name = imp->at(p++);
    //cout << "parsing  "<<name<<"\n";
    if(imp->at(p++)!="(") imp->error(--p, "Missing left parenthesis");
    while(true) {
        bool autoconstruct = false;
        bool mut = false;
        string next = imp->at(p++);
        if(next==")") break;
        if(args.size()) {
            if(next!=",")imp->error(--p, "Missing comma between arguments");
            next = imp->at(p++);
        }
        if(next==":") {
            autoconstruct=true;
            next = imp->at(p++);
        }
        if(!accepted_var_name(next)) imp->error(--p, "Not a valid name");
        if(types.vars.find(next)==types.vars.end()) imp->error(--p, "Missing runtype");
        string arg_name = imp->at(p++);
        if(arg_name=="&") {mut = true;arg_name = imp->at(p++);}
        if(mut && is_service) imp->error(p-2, "Services do not accept values by reference\nThis ensures failsafe-compliant extensibility.\nDid you mean to declare a runtype instead?");
        if(arg_name=="," || arg_name==")") {
            arg_name = create_temp();
            --p;
        }
        if(!accepted_var_name(arg_name)) imp->error(--p, "Not a valid name");
        if(types.vars.find(arg_name)!=types.vars.end()) imp->error(--p, "Invalid variable name\nIt is a previous runtype or union");
        Type argType = types.vars.find(next)->second;
        if(argType->lazy_compile && debug) {
            //cout << arg_name<<"\n";
            auto def = make_shared<Def>();
            def->debug = true;
            size_t p2 = argType->pos;
            def->parse(imp, p2, types);
            argType = def;
            types.vars[next] = def;
            //cout << "parsed "<<next<<"\n";
        }
        if(argType->lazy_compile && !debug) {
            args.emplace_back(arg_name, argType, mut);
            internalTypes.vars[arg_name] = argType;
            parametric_types[argType->name] = argType;
            for(const auto& it : argType->parametric_types) parametric_types[it.first] = it.second;
            this->lazy_compile = true; // indicate that we want to compile lazily later again
        }
        else if(argType->not_primitive()) {
            //if(debug) cout << "parametric "<<arg_name<<" "<<argType->signature()<<"\n";
            internalTypes.vars[arg_name] = argType;
            if(autoconstruct) for(const auto& it : argType->args) {
                //if(debug) cout << arg_name<<" "<<it.type->name<<"\n";
                args.emplace_back(arg_name+"__"+it.name, it.type, mut);
                internalTypes.vars[arg_name+"__"+it.name] = it.type;
                // vardecl += it.type->rebase(it.type->vardecl, arg_name);
                implementation += it.type->rebase(it.type->implementation, arg_name);
                preample += it.type->rebase(it.type->preample, arg_name);
                for(const auto& final : it.type->finals) finals[arg_name+"__"+final.first] += it.type->rebase(final.second, arg_name); 
                //finals = it.type->rebase(it.type->finals, arg_name)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
                for(const auto& it : it.type->current_renaming) current_renaming[arg_name+"__"+it.first] = arg_name+"__"+it.second;
                errors = errors+it.type->rebase(it.type->errors, arg_name);
                for(const auto& it2 : it.type->internalTypes.vars) {
                    string arg = arg_name+"__"+it2.first;
                    internalTypes.vars[arg] = it2.second;
                    if(it2.second->name=="buffer") buffer_primitive_associations[arg] = it.type->buffer_primitive_associations[it2.first];
                }
            }
            else for(const auto& itarg : argType->packs) {
                args.emplace_back(arg_name+"__"+itarg, argType->internalTypes.vars[itarg], mut);
                internalTypes.vars[arg_name+"__"+itarg] = argType->internalTypes.vars[itarg];
            }
        }
        else {
            args.emplace_back(arg_name, argType, mut);
            internalTypes.vars[arg_name] = argType;
        }
        if(p>=imp->size()) imp->error(pos+2, "Missing matching right parenthesis");
    }
}


void signature_until_position(const shared_ptr<Import>& imp, vector<unordered_map<string, Type>>& results, const vector<string>& parametric_names, size_t i, const unordered_map<string, Type>& current) {
    unordered_map<string, Type> next(current);
    if(i>=parametric_names.size()) {results.push_back(next);return;}
    // will always have a lazy compilation here
    string parametric_name = parametric_names[i];
    for(const Type& option : parametric_types[parametric_name]->options) {
        next[parametric_name] = option;
        signature_until_position(imp, results, parametric_names, i+1, next);
    }
}

vector<Type> get_options(const shared_ptr<Import>& imp, Memory& types) {
    if(debug) return options;
    vector<Type> newOptions;
    for(const auto& option : options) if(option->lazy_compile) {for(const auto& parametric_option : option->get_lazy_options(imp, types)) newOptions.push_back(parametric_option);} else newOptions.push_back(option);
    return newOptions;
}

vector<Type> get_lazy_options(const shared_ptr<Import>& imp, Memory& types) {
    // store prev state
    //cout << "---------------------------\n";
    //cout << signature() << " " <<  this << "\n";
    //cout << "---------------------------\n";
    Memory prevTypes;
    prevTypes.vars = types.vars;
    vector<string> parametric_names;
    for(const auto& it : parametric_types) parametric_names.push_back(it.first);
    // gather variations
    vector<unordered_map<string, Type>> argoptions;
    unordered_map<string, size_t> positions; // avoids setting again the same parameter and thus creating too many varations
    signature_until_position(imp, argoptions, parametric_names, 0, unordered_map<string, Type>());
    // iterate through variations
    debug = true;
    vector<Type> newOptions;
    for(const auto& argoption : argoptions) {
        for(const auto& it : argoption) {
            types.vars[it.first] = it.second;
            //cout<<it.first<<" "<<it.second->signature()<<" "<<it.second.get()<<"\n";
        }
        //cout << "---------\n";
        size_t p = pos;
        auto def = make_shared<Def>();
        def->parse(imp, p, types);
        newOptions.push_back(def);
        //cout << def->signature() <<"\n";
        //cout << "---------------------------\n";
    }
    // restore proper type system
    types.vars = prevTypes.vars;
    debug = false;
    return newOptions;
}
