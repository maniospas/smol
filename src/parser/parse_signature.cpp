int Def::log_depth = 0;

void Def::parse_signature(const shared_ptr<Import>& imp, size_t& p, Memory& types) {
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
        if(next=="nom" && args.size()) imp->error(--p, "Misplaced align\nCan only be the first argument of a runtype\nor the argument of dependent runtypes");
        Type argType = types.vars[next];
        if(argType->lazy_compile && debug) {
            //cout << arg_name<<"\n";
            auto def = make_shared<Def>();
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
                for(const string& pre : it.type->preample) add_preample(it.type->rebase(pre, arg_name));
                for(const auto& final : it.type->finals) finals[arg_name+"__"+final.first] += it.type->rebase(final.second, arg_name); 
                //finals = it.type->rebase(it.type->finals, arg_name)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
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
            args.emplace_back(arg_name, argType, mut);
            internalTypes.vars[arg_name] = argType;
            if(argType->name=="nom") alignments[arg_name] = alignment_labels[this];
        }
        if(p>=imp->size()) imp->error(pos+2, "Missing matching right parenthesis");
    }
}


void Def::signature_until_position(vector<unordered_map<string, Type>>& results, const vector<string>& parametric_names, size_t i, const unordered_map<string, Type>& current, const Memory& types) {
    unordered_map<string, Type> next(current);
    if(i>=parametric_names.size()) {results.push_back(next);return;}
    // will always have a lazy compilation here
    string parametric_name = parametric_names[i];
    for(const Type& option : types.vars.find(parametric_name)->second->options) if(!option->is_union) {
        next[parametric_name] = option;
        signature_until_position(results, parametric_names, i+1, next, types);
    }
}

vector<Type> Def::get_options(Memory& types) {
    if(lazy_compile) {
        vector<Type> newOptions;
        for(const auto& option : options) if(option->lazy_compile) {for(const auto& parametric_option : option->get_lazy_options(types)) newOptions.push_back(parametric_option);} else newOptions.push_back(option);
        options = newOptions;
        lazy_compile = false;
    }
    return options;
}

void Def::print_depth() {for(int i=0;i<log_depth;++i) cout<<"| "; }

vector<Type> Def::get_lazy_options(Memory& types) {
    // store prev state
    if(log_type_resolution) print_depth();
    if(log_type_resolution) cout << signature() <<" "<< this << "\n";
    log_depth += 1;
    Memory prevTypes;
    for(const auto& it : types.vars) prevTypes.vars[it.first] = it.second;
    //prevTypes.vars = types.vars;

    vector<string> parametric_names;
    for(const auto& it : parametric_types) parametric_names.push_back(it.first);
    // gather variations
    vector<unordered_map<string, Type>> argoptions;
    unordered_map<string, size_t> positions; // avoids setting again the same parameter and thus creating too many varations
    signature_until_position(argoptions, parametric_names, 0, unordered_map<string, Type>(), types);
    // iterate through variations
    vector<Type> newOptions;

    std::queue<unordered_map<string, Type>> processingQueue;
    for (auto& opt : argoptions) processingQueue.push(opt);
    argoptions.clear();


    while(!processingQueue.empty()) {
        types.vars.clear();
        for(const auto& it : prevTypes.vars) types.vars[it.first] = it.second;

        auto argoption = processingQueue.front();
        processingQueue.pop();
        int power = 0;
        bool retry = true;
        while(retry) {
            power = 0;
            retry = false;
            for(const auto& it : argoption) {
                power += (it.second->choice_power+1)/2;
                //if(log_type_resolution) print_depth();
                //if(log_type_resolution) cout<<"- "<<pretty_runtype(it.first)<<" could be "<<it.second->signature()<<" "<<it.second.get()<<"\n";
                if(it.second->lazy_compile) retry = true;
                //if(it.second->lazy_compile) ERROR("Internal error: not fully resolved\nFailed to resolve "+pretty_runtype(it.first)+" required by "+pretty_runtype(name));
                types.vars[it.first] = it.second;
                /*if(types.vars.find(it.first)==types.vars.end() || types.vars[it.first]->lazy_compile) types.vars[it.first] = it.second;
                else if(types.vars[it.first]!=it.second) {
                    imp->error(pos, "SKIPPING - Would replace already resolved: "+types.vars[it.first]->signature());
                    // forcefully stop looping
                    power = -1;
                    retry = false;
                    break;
                }*/
            }
            if(power<0) {continue;}
            //if(retry && log_type_resolution) {print_depth();cout <<"resolving\n";}
            if(retry) {
                bool anysuccess = false;
                for(auto& it : argoption) if(it.second->lazy_compile) {
                    //if(log_type_resolution) print_depth();if(log_type_resolution) cout << "========  DEPENDENT RESOLUTION  ========\n";
                    //if(log_type_resolution) print_depth();if(log_type_resolution) cout << "resolving "<<it.second->signature() << "\n";
                    log_depth += 1;
                    vector<Type> dependent_options = it.second->get_options(types);
                    log_depth -= 1;
                    if(dependent_options.size()==0) {
                        /*if(log_type_resolution) print_depth();
                        if(log_type_resolution) cout << "SKIPPED\n";
                        power = -1;
                        retry = false;
                        anysuccess = true;
                        break;*/
                        imp->error(pos, "Runtype not found: "+pretty_runtype(it.first)+" requested by "+pretty_runtype(name));
                    }//imp->error(pos, "Runtype not found: "+pretty_runtype(it.first)+" requested by "+pretty_runtype(name));
                    if(dependent_options.size()>1) {
                        /*if(log_type_resolution) print_depth();
                        if(log_type_resolution) cout << "SKIPPED & changing resolution of "+pretty_runtype(it.first)+" to be considered once for every option\n";
                        for(const auto& dep : dependent_options) {
                            // replace and copy
                            it.second = dep;
                            auto newoptions = argoption; 
                            processingQueue.push(argoption);
                        }
                        // forcefully stop looping
                        power = -1;
                        retry = false;
                        anysuccess = true;
                        break;*/
                        string cand("");
                        for(const auto& opt : dependent_options) cand += "\n"+opt->signature(); 
                        imp->error(pos, "A call of "+pretty_runtype(name)+" failed to resolve "+pretty_runtype(it.first)+" due to multiple candidates:"+cand);
                    }
                    size_t p = dependent_options[0]->pos;
                    auto def = make_shared<Def>();
                    Def::log_depth += 1;
                    def->parse(dependent_options[0]->imp, p, types);
                    Def::log_depth -= 1;
                    if(def->args.size() && def->args[0].type->name=="nom") def->alignments[def->args[0].name] = dependent_options[0]->alignments[def->args[0].name];
                    it.second = def;
                    if(!it.second->lazy_compile) anysuccess = true;
                    def->options.push_back(def);
                    //if(dependent_options[0]->lazy_compile) ERROR("Internal error: not fully resolved\nFailed to resolve "+pretty_runtype(it.first)+" required by "+pretty_runtype(name));
                    //if(log_type_resolution) print_depth();if(log_type_resolution) cout << "resolved to "<<it.second->signature() << "\n";
                    //if(log_type_resolution) print_depth();if(log_type_resolution) cout << "========================================\n";
                }
                if(!anysuccess) {
                    string deps;
                    for(auto& it : argoption) if(it.second->lazy_compile) deps += "\n- "+it.second->signature();
                    imp->error(pos, "Incomplete union/overload resolution\nResolve the following runtype dependencies\n"+deps);
                }
            }
            if(retry && log_type_resolution) {print_depth();cout <<"RETRY with resolution\n";}
        }
        if(power<0) continue;
        //if(log_type_resolution) print_depth();
        //if(log_type_resolution) cout << "resolving\n";
        size_t p = pos;
        auto def = make_shared<Def>();
        log_depth += 1;
        def->parse(imp, p, types);
        log_depth -= 1;
        if(args.size() && args[0].type->name=="nom") def->alignments[def->args[0].name] = alignments[args[0].name];
        if(def->lazy_compile) def->imp->error(def->pos, "Failed resolved all dependent types");
        def->choice_power += power;
        def->options.push_back(def);
        newOptions.push_back(def);
        if(log_type_resolution) print_depth();
        if(log_type_resolution) cout << def->signature() <<"\n";
    }
    // restore proper type system
    types.vars = move(prevTypes.vars);
    log_depth -= 1;
    return newOptions;
}
