#include "../def.h"

int Def::log_depth = 0;
void Def::parse_signature(const shared_ptr<Import>& imp, size_t& p, Types& types) {
    bool is_as = false;
    if(p>=imp->size()) ERROR("Internal error: parsing "+name+" has misjudged end of file");
    if(imp->at(p)=="as") is_as = true;
    else if(imp->at(p)=="service") is_service = true;
    else if(imp->at(p)!="smo") imp->error(--p, "Missing `service` or `smo` to declare runtype");
    p++;
    if(!is_as) name = imp->at(p++); else name = create_temp();
    if(types.contains(name)) {
        if(is_service) imp->error(--p, "A service cannot overload a runtype or service with the same name");
        else if(types.vars[name]->is_service) imp->error(--p, "A runtype cannot overload a service with the same name");
    }
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
        if(next==",") next = imp->at(p++);//spaghetios
        if(!accepted_var_name(next)) imp->error(--p, "Not a valid name: "+next);
        if(types.vars.find(next)==types.vars.end()) imp->error(--p, "Missing runtype: "+next);
        string arg_name = imp->at(p++);
        if(arg_name=="&") {mut = true;arg_name = imp->at(p++);}
        if(mut && is_service) imp->error(p-2, "Services do not accept values by reference\nThis ensures failsafe-compliant extensibility.\nDid you mean to declare a runtype instead?");
        
        if(!types.contains(next)) imp->error(--p, "Missing runtype: "+next);
        if(next=="nom" && args.size()) imp->error(--p, "Misplaced align\nCan only be the first argument of a runtype\nor the argument of dependent runtypes");
        Type argType = types.vars[next];
        if(arg_name=="," || arg_name==")") {
            arg_name = create_temp();
            --p;
        }
        if(!accepted_var_name(arg_name)) imp->error(--p, "Not a valid name");
        if(types.vars.find(arg_name)!=types.vars.end()) imp->error(--p, "Invalid variable name\nIt is a previous runtype or union");
        if(argType->lazy_compile) {
            args.emplace_back(arg_name, argType, mut);
            internalTypes.vars[arg_name] = argType;
            parametric_types[argType->name] = argType;
            //for(const auto& it : argType->parametric_types) parametric_types[it.first] = it.second;
            this->lazy_compile = true; // indicate that we want to compile lazily with a second pass across all
        }
        else if(argType->not_primitive()) {
            retrievable_parameters[argType->name] = argType;
            internalTypes.vars[arg_name] = argType;
            if(autoconstruct) for(const auto& it : argType->args) {
                args.emplace_back(arg_name+"__"+it.name, it.type, mut);
                internalTypes.vars[arg_name+"__"+it.name] = it.type;
                implementation += it.type->rebase(it.type->implementation, arg_name);
                for(const string& pre : it.type->preample) add_preample(it.type->rebase(pre, arg_name));
                for(const auto& final : it.type->finals) finals[arg_name+"__"+final.first] += it.type->rebase(final.second, arg_name); 
                for(const auto& it : it.type->current_renaming) current_renaming[arg_name+"__"+it.first] = arg_name+"__"+it.second;
                for(const auto& it : it.type->alignments) if(it.second) {alignments[arg_name+"__"+it.first] = it.second;}
                errors = errors+it.type->rebase(it.type->errors, arg_name);
                for(const auto& it2 : it.type->internalTypes.vars) {
                    string arg = arg_name+"__"+it2.first;
                    internalTypes.vars[arg] = it2.second;
                    if(it2.second->name=="buffer") buffer_primitive_associations[arg] = it.type->buffer_primitive_associations[it2.first];
                }
            }
            else {
                internalTypes.vars[arg_name] = argType;
                for(const auto& itarg : argType->packs) {
                    args.emplace_back(arg_name+"__"+itarg, argType->internalTypes.vars[itarg], mut);
                    internalTypes.vars[arg_name+"__"+itarg] = argType->internalTypes.vars[itarg];
                    for(const auto& it : argType->alignments) if(it.second) alignments[arg_name+"__"+it.first] = it.second;
                }
                for(const auto& itarg : argType->internalTypes.vars) {
                    // TODO: this may be too expensive - consider tracking only packs parents
                    internalTypes.vars[arg_name+"__"+itarg.first] = itarg.second;
                }
            }
        }
        else {
            retrievable_parameters[argType->name] = argType;
            args.emplace_back(arg_name, argType, mut);
            internalTypes.vars[arg_name] = argType;
            if(argType->name=="nom") {
                alignments[arg_name] = types.alignment_labels[this];
                if(!types.alignment_labels[this]) imp->error(--p, "Internal error: Failed to assign itself as an alignment label");
            }
        }
        
        if(p>=imp->size()) imp->error(pos+2, "Missing matching right parenthesis");
    }
}

void Def::print_depth() {for(int i=0;i<log_depth;++i) cout<<"| "; }
unordered_set<Type> Def::get_options(Types& types) {return options;}
void Def::signature_until_position(vector<unordered_map<string, Type>>& results, const vector<string>& parametric_names, size_t i, const unordered_map<string, Type>& current, const Types& types) {
    unordered_map<string, Type> next(current);
    if(i>=parametric_names.size()) {results.push_back(next);return;}
    // will always have a lazy compilation here
    string parametric_name = parametric_names[i];
    //cout << "for name "<<parametric_name<<" will consider "<<types.vars.find(parametric_name)->second->options.size() << " options\n";
    if(current.find(parametric_name)!=current.end()) return signature_until_position(results, parametric_names, i+1, current, types);
    auto& arg_options = types.vars.find(parametric_name)->second->options;
    for(const Type& option : arg_options) {
        if(option->alias_for.size() && arg_options.find(option->internalTypes.vars[option->alias_for])!=arg_options.end()) continue;
        next[parametric_name] = option;
        signature_until_position(results, parametric_names, i+1, next, types);
    }
}

vector<Type> Def::get_lazy_options(Types& _types) {
    // store prev state
    if(log_type_resolution) {print_depth(); cout<< signature(_types)<<" "<<this<<"\n";}
    log_depth += 1;

    vector<string> parametric_names;
    for(const auto& it : parametric_types) {parametric_names.push_back(it.first);}
    vector<unordered_map<string, Type>> argoptions;
    signature_until_position(argoptions, parametric_names, 0, unordered_map<string, Type>(), _types);

    vector<Type> newOptions;
    for(const unordered_map<string, Type>& argoption : argoptions) {
        // create a copy of types
        Types types;
        types.vars.reserve(_types.vars.size());
        types.alignment_labels.reserve(_types.alignment_labels.size());
        types.reverse_alignment_labels.reserve(_types.reverse_alignment_labels.size());
        for(const auto& it : _types.vars) types.vars[it.first] = it.second;
        for(const auto& it : _types.alignment_labels) types.alignment_labels[it.first] = it.second;
        for(const auto& it : _types.reverse_alignment_labels) types.reverse_alignment_labels[it.first] = it.second;

        int power = 0;
        for(const auto& it : argoption) {
            if(power<it.second->choice_power) power = it.second->choice_power;
            if(!_types.contains(it.first)) imp->error(pos, "Internal error: global typesystem is unaware of runtype "+it.first);
            if(!it.second) imp->error(pos, "Internal error: null runtype for "+it.first);
            //if(log_type_resolution) {print_depth();cout<<"- "<<pretty_runtype(it.first)<<" could be "<<it.second->signature(_types)<<" "<<it.second.get()<<"\n";}
            if(it.second->lazy_compile) imp->error(pos, "Failed to previously compile type: "+types.vars[it.first]->signature(_types));
            if(!types.vars[it.first]->lazy_compile && types.vars[it.first]!=it.second) {
                power = -1;
                //if(log_type_resolution) {print_depth(); cout<<"Incompatibility will skip this combination (this is ok) : "<<it.second->name<<"\n";}
                break;
            }
            types.vars[it.first] = it.second;
        }
        if(power<0) continue;
        size_t p = pos;
        auto def = make_shared<Def>(types);
        def->retrievable_parameters = argoption;
        log_depth += 1;
        try {def->parse(imp, p, types);}
        catch(const runtime_error& e) {
            string what = e.what();
            log_depth -= 1;
            const std::string expected = "\033[33m`with` with no `else`";
            if(what.compare(0, expected.size(), expected) != 0) throw e;
            //if(log_type_resolution) {print_depth();cout << "Skipped due to unprocessable `with` with no `else`\n";}
            continue;
        }
        all_types.push_back(def);
        log_depth -= 1;
        //if(args.size() && args[0].type && args[0].type->name=="nom") def->alignments[def->args[0].name] = types.alignment_labels[def.get()];
        if(def->lazy_compile) def->imp->error(def->pos, "Failed resolved all dependent types");
        def->choice_power += power;
        newOptions.push_back(def);
        if(log_type_resolution) {
            print_depth();cout << def->signature(types) <<"\n";
            for(const auto& it : argoption) {print_depth();cout<<"- "<<pretty_runtype(it.first)<<" is "<<it.second->signature(_types)<<"\n";}
        }

        // get back the alignment labels to the real type
        _types.alignment_labels[def.get()] = types.alignment_labels[def.get()];
        _types.reverse_alignment_labels[_types.alignment_labels[def.get()]] = def.get();
    }
    log_depth -= 1;
    if(newOptions.size()==0) imp->error(pos, "Failed to resolve to any valid version\nCheck your `with` statements that have no `else`\nor if you have runtypes that serve as constructors of others with the same name or in the same union");
    return newOptions;
}
