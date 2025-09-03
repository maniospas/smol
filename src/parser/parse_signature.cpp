#include "../def.h"

int Def::log_depth = 0;
void Def::parse_signature(const shared_ptr<Import>& imp, size_t& p, Types& types) {
    bool is_as = false;
    if(p>=imp->size()) 
        ERROR("Internal error: parsing "+name.to_string()+" has misjudged end of file");
    if(imp->at(p)=="as") 
        is_as = true;
    else if(imp->at(p)=="service") 
        is_service = true;
    else if(imp->at(p)!="smo") 
        imp->error(--p, "Missing `service` or `smo` to declare runtype");
    p++;
    if(!is_as) 
        name = imp->at(p++); 
    else 
        name = create_temp();
    /*if(types.contains(name)) {
        if(is_service && types.vars[name]->is_service) imp->error(--p, "A service cannot overload a runtype with the same name");
        if(!is_service && types.vars[name]->is_service) imp->error(--p, "A runtype cannot overload a service with the same name");
    }*/
    if(imp->at(p++)!="(") 
        imp->error(--p, "Missing left parenthesis");
    while(true) {
        bool autoconstruct = false;
        bool mut = false;
        bool nolex = false;
        string next = imp->at(p++);
        if(next==")") 
            break;
        if(args.size()) {
            if(next!=",")
                imp->error(--p, "Missing comma between arguments");
            next = imp->at(p++);
        }
        if(next=="@") {
            next = imp->at(p++);
            if(next!="struct") 
                imp->error(--p, "@struct is expected here");
            next = imp->at(p++);
            nolex = true;
        }
        if(next==":") {
            autoconstruct=true;
            imp->error(--p, "Unexpected :"); // deprecated autoconstruct
            next = imp->at(p++);
        }
        if(next==",") 
            next = imp->at(p++);//spaghetios
        if(!accepted_var_name(next)) 
            imp->error(--p, "Not a valid name: "+next);
        if(types.vars.find(next)==types.vars.end()) 
            imp->error(--p, "Missing runtype: "+next);
        Variable arg_name = imp->at(p++);
        bool arg_is_buffer = false;
        if(arg_name=="[") {
            arg_is_buffer = true;
            if(imp->at(p++)!="]") 
                imp->error(--p, "Expecting [] here to indicate buffer argument");
            arg_name = imp->at(p++);
        }
        if(arg_name=="&") {
            mut = true;
            arg_name = imp->at(p++);
        }
        if(mut && is_service) 
            imp->error(p-2, "Services do not accept values by reference\nThis ensures failsafe-compliant extensibility."
                "\nDid you mean to declare a runtype instead?"
            );
        
        if(!types.contains(next)) 
            imp->error(--p, "Missing runtype: "+next);
        if(next==NOM_VAR && args.size()) 
            imp->error(--p, "Misplaced align\nCan only be the first argument of a runtype\nor the argument of dependent runtypes");
        Type argType = types.vars[next];
        if(arg_name=="," || arg_name==")") {
            arg_name = create_temp();
            --p;
        }
        if(!accepted_var_name(arg_name.to_string())) 
            imp->error(--p, "Not a valid name");
        if(types.vars.find(arg_name)!=types.vars.end()) 
            imp->error(--p, "Invalid variable name\nIt is a previous runtype or union");
        if(argType->lazy_compile && nolex) {
            if(argType->options.size()==0) imp->error(--p, "Internal error: no options for argument: "
                +arg_name.to_string()
            );
            double option_power = -1;
            int conflicts = 0;
            for(const auto& it : argType->options) {
                if(it->choice_power>option_power) {// && it->name==argType->name) {
                    option_power = it->choice_power;
                    argType = it;
                    conflicts = 0;
                }
                else if(it->choice_power==option_power) 
                    conflicts++;
            }
            if(option_power<0) 
                imp->error(--p, "No resolution options for @struct argument: "
                    +arg_name.to_string()
                );
            if(conflicts) 
                imp->error(--p, "There was no criterion for resolving @struct argument to one option: "
                    +arg_name.to_string()
                    +"\nMultiple options are available"
                );
        }
        if(argType->lazy_compile) {
            args.emplace_back(arg_name, argType, mut);
            mutables.insert(arg_name);
            internalTypes.vars[arg_name] = argType;
            parametric_types[argType->name] = argType;
            //for(const auto& it : argType->parametric_types) parametric_types[it.first] = it.second;
            this->lazy_compile = true; // indicate that we want to compile lazily with a second pass across all
        }
        else if(arg_is_buffer) {
            if(argType->options.size()==0) 
                imp->error(--p, "Internal error: no options to determine buffer elements "+argType->name.to_string());
            double option_power = -1;
            int conflicts = 0;
            auto original_type = argType;
            for(const auto& it : argType->options) {
                if(it->choice_power>option_power) {
                    option_power = it->choice_power;
                    argType = it;
                    conflicts = 0;
                }
                else if(it->choice_power==option_power) 
                    conflicts++;
            }
            if(option_power<0) 
                imp->error(--p, "No resolution options for determining buffer elements: "+original_type->name.to_string());
            if(conflicts) 
                imp->error(--p, "There was no criterion for resolving buffer element to one option: "+original_type->name.to_string()+"\nMultiple options are available");
            
            internalTypes.vars[arg_name] = types.vars[BUFFER_VAR];
            buffer_types[arg_name] = argType;
            if(mut) 
                mutables.insert(arg_name);
            args.emplace_back(arg_name, types.vars[BUFFER_VAR], mut);
        }
        else if(argType->not_primitive()) {
            retrievable_parameters[argType->name] = argType;
            internalTypes.vars[arg_name] = argType;
            if(autoconstruct) for(const auto& it : argType->args) {
                args.emplace_back(arg_name+it.name, it.type, mut || it.mut);
                internalTypes.vars[arg_name+it.name] = it.type;
                implementation += it.type->rebase(it.type->implementation, arg_name);
                for(const string& pre : it.type->preample) 
                    add_preample(pre);
                for(const string& pre : it.type->linker) 
                    add_linker(pre);
                for(const auto& it : it.type->buffer_types)
                    buffer_types[arg_name+it.first] = it.second;
                for(const auto& final : it.type->finals) 
                    finals[arg_name+final.first] = finals[arg_name+final.first] + it.type->rebase(final.second, arg_name); 
                for(const auto& it : it.type->current_renaming) 
                    current_renaming[arg_name+it.first] = arg_name+it.second;
                for(const auto& it : it.type->alignments) 
                    if(it.second) 
                        alignments[arg_name+it.first] = it.second;
                for(const auto& it : it.type->active_calls) 
                    if(it.second.exists()) 
                        active_calls[arg_name+it.first] = it.second;
                errors = errors+it.type->rebase(it.type->errors, arg_name);
                for(const auto& it2 : it.type->internalTypes.vars) {
                    Variable arg = arg_name+it2.first;
                    internalTypes.vars[arg] = it2.second;
                }
            }
            else {
                internalTypes.vars[arg_name] = argType;
                if(mut) mutables.insert(arg_name);
                if(!mut && argType->noborrow) 
                    imp->error(--p, "Argument's "
                        +arg_name.to_string()
                        +" runtype has been set as @noborrow\nThis means that arguments and variables of it can only be mutable"
                        +"\nand therefore it becomes impossible to share it with service\n(mutables cannot be assinged anywhere)."
                        +"\nAdd & before the argument name to make it mutable"
                    );
                if(mut) for(const Variable& mut : argType->mutables) 
                    mutables.insert(arg_name+mut);
                for(const auto& itarg : argType->packs) {
                    //cout << name << " " <<itarg << " " << mut << " "<<(argType->mutables.find(itarg)!=argType->mutables.end())<<"\n";
                    args.emplace_back(
                        arg_name+itarg, 
                        argType->internalTypes.vars[itarg], 
                        (mut || (argType->mutables.find(itarg)!=argType->mutables.end()))
                    );
                    internalTypes.vars[arg_name+itarg] = argType->internalTypes.vars[itarg];
                    for(const auto& it : argType->alignments) if(it.second) 
                        alignments[arg_name+it.first] = it.second;
                    //if(is_service && argType->mutables.find(itarg)!=argType->mutables.end()) imp->error(p-2, "Services do not accept values by reference (even implicit ones): "+pretty_var((arg_name+itarg).to_string())+"\nImplicit services could cause services to race on a shared state and are prevented.\nThis ensures failsafe-compliant extensibility.\nDid you mean to declare a runtype instead?");
                }
                for(const auto& itarg : argType->internalTypes.vars) {
                    // TODO: this may be too expensive - consider tracking only packs parents
                    internalTypes.vars[arg_name+itarg.first] = itarg.second;
                }
            }
        }
        else {
            if(mut) 
                mutables.insert(arg_name);
            retrievable_parameters[argType->name] = argType;
            args.emplace_back(arg_name, argType, mut);
            internalTypes.vars[arg_name] = argType;
            if(argType->name==NOM_VAR) {
                alignments[arg_name] = types.alignment_labels[this];
                if(!types.alignment_labels[this]) 
                    imp->error(--p, "Internal error: Failed to assign itself as an alignment label");
            }
        }
        
        if(p>=imp->size()) 
            imp->error(pos+2, "Missing matching right parenthesis");
    }
}

void Def::print_depth() {for(int i=0;i<log_depth;++i) cout<<"| "; }
vector<Type>& Def::get_options(const Types& types) { 
    // //if(log_type_resolution) {print_depth(); cout<< name <<" "<<this<<"\n";}
    // log_depth += 1;
    // for(auto& def : options) {
    //     if(def.get()==this) break; // refrence only previously declared versions
    //     if(def->unresolved_options && !def->has_tried_to_resolve_before) {
    //         def->has_tried_to_resolve_before = true;
    //         //try {
    //             if(!def->complete_option_resolution(types)) continue;
    //         /*}
    //         catch(std::runtime_error& err) {
    //             if(err. continue;
    //             throw err;
    //         }*/
    //         def->unresolved_options = false;
    //     }
    // }
    // log_depth -= 1;
    // if(options.size()==0) imp->error(pos, "Failed to resolve to any valid version\nCheck your `with` statements that have no `else`\nor if you have runtypes that serve as constructors of others with the same name or in the same union");
    return options;
}
void Def::signature_until_position(vector<unordered_map<Variable, Type>>& results, const vector<Variable>& parametric_names, size_t i, const unordered_map<Variable, Type>& current, const Types& types) {
    unordered_map<Variable, Type> next(current);
    if(i>=parametric_names.size()) {results.push_back(next);return;}
    // will always have a lazy compilation here
    Variable parametric_name = parametric_names[i];
    //cout << "for name "<<parametric_name<<" will consider "<<types.vars.find(parametric_name)->second->options.size() << " options\n";
    if(current.find(parametric_name)!=current.end()) 
        return signature_until_position(results, parametric_names, i+1, current, types);
    auto& arg_options = types.vars.find(parametric_name)->second->get_options(types);
    bool progressed = false;
    for(const Type& option : arg_options) {
        if(option->alias_for.exists()) {
            if (option->alias_for.exists() && ranges::find(arg_options, option->internalTypes.vars[option->alias_for]) != arg_options.end()) 
                continue;
        }
        next[parametric_name] = option;
        signature_until_position(results, parametric_names, i+1, next, types);
        progressed = true;
    }
    if(!progressed) 
        signature_until_position(results, parametric_names, i+1, next, types);
}


bool Def::start_option_resolution(const Types& _types) {
    has_tried_to_resolve_before = false;
    unresolved_options = true;
    Types types;
    types.vars.reserve(_types.vars.size());
    types.alignment_labels.reserve(_types.alignment_labels.size());
    types.reverse_alignment_labels.reserve(_types.reverse_alignment_labels.size());
    for(const auto& it : _types.vars) 
        types.vars[it.first] = it.second;
    for(const auto& it : _types.alignment_labels) 
        types.alignment_labels[it.first] = it.second;
    for(const auto& it : _types.reverse_alignment_labels) 
        types.reverse_alignment_labels[it.first] = it.second;

    double power = 0;
    for(const auto& it : this->retrievable_parameters) {
        //power += (1+it.second->choice_power)*0.5;
        if(!_types.contains(it.first)) 
            imp->error(pos, "Internal error: global typesystem is unaware of runtype "+it.first.to_string());
        if(!it.second) 
            imp->error(pos, "Internal error: null runtype for "+it.first.to_string());
        //if(log_type_resolution) {print_depth();cout<<"- "<<pretty_runtype(it.first)<<" could be "<<it.second->signature(_types)<<" "<<it.second.get()<<"\n";}
        if(it.second->lazy_compile) 
            imp->error(pos, "Failed to previously compile type: "
                +types.vars[it.first]->signature(types)
            );
        if(!types.vars[it.first]->lazy_compile && types.vars[it.first]!=it.second) {
            power = -1;
            //if(log_type_resolution) {print_depth(); cout<<"Incompatibility will skip this combination (this is ok) : "<<it.second->name<<"\n";}
            break;
        }
        types.vars[it.first] = it.second;
    }

    log_depth += 1;
    size_t p = pos;
    try {
        parse_signature(imp, p, types);
    }
    catch(const runtime_error& e) {
        string what = e.what();
        log_depth -= 1;
        const std::string expected = "\033[33m`with` with no `else`";
        if(what.compare(0, expected.size(), expected) != 0) 
            throw e;
        return false;
    }
    log_depth -= 1;
    if(lazy_compile) 
        imp->error(pos, "Failed to resolve all dependent types");
    choice_power += power;
    if(log_type_resolution) {
        print_depth();cout << signature(types) <<"\n";
        for(const auto& it : retrievable_parameters) {
            print_depth();
            cout<<"- "
                <<pretty_runtype(it.first.to_string())
                <<" is "<<it.second->signature(types)
                <<"\n";
        }
    }
    unresolved_options = false;
    return true;
}

bool Def::complete_option_resolution(const Types& _types) {
    if(has_tried_to_resolve_before) 
        return !unresolved_options;
    has_tried_to_resolve_before = true;
    unresolved_options = true;
    Types types;
    types.vars.reserve(_types.vars.size());
    types.alignment_labels.reserve(_types.alignment_labels.size());
    types.reverse_alignment_labels.reserve(_types.reverse_alignment_labels.size());
    for(const auto& it : _types.vars) 
        types.vars[it.first] = it.second;
    for(const auto& it : _types.alignment_labels) 
        types.alignment_labels[it.first] = it.second;
    for(const auto& it : _types.reverse_alignment_labels) 
        types.reverse_alignment_labels[it.first] = it.second;

    double power = 0;
    for(const auto& it : this->retrievable_parameters) {
        //power += (1+it.second->choice_power)*0.5;
        if(!_types.contains(it.first)) 
            imp->error(pos, "Internal error: global typesystem is unaware of runtype "+it.first.to_string());
        if(!it.second) 
            imp->error(pos, "Internal error: null runtype for "+it.first.to_string());
        //if(log_type_resolution) {print_depth();cout<<"- "<<pretty_runtype(it.first)<<" could be "<<it.second->signature(_types)<<" "<<it.second.get()<<"\n";}
        if(it.second->lazy_compile) 
            imp->error(pos, "Failed to previously compile type: "+types.vars[it.first]->signature(types));
        if(!types.vars[it.first]->lazy_compile && types.vars[it.first]!=it.second) {
            power = -1;
            //if(log_type_resolution) {print_depth(); cout<<"Incompatibility will skip this combination (this is ok) : "<<it.second->name<<"\n";}
            break;
        }
        types.vars[it.first] = it.second;
    }

    log_depth += 1;
    size_t p = pos;
    try {parse(imp, p, types);}
    catch(const runtime_error& e) {
        string what = e.what();
        log_depth -= 1;
        const std::string expected = "\033[33m`with` with no `else`";
        if(what.compare(0, expected.size(), expected) != 0) 
            throw e;
        //if(log_type_resolution) {print_depth();cout << "Skipped: caught an error using `with` without `else`\n";}
        return false;
    }
    log_depth -= 1;
    //if(args.size() && args[0].type && args[0].type->name=="nom") def->alignments[def->args[0].name] = types.alignment_labels[def.get()];
    if(lazy_compile) 
        imp->error(pos, "Failed to resolve all dependent types");
    choice_power += power;
    if(log_type_resolution) {
        print_depth();cout << signature(types) <<"\n";
        for(const auto& it : retrievable_parameters) {
            print_depth();
            cout<<"- "
                <<pretty_runtype(it.first.to_string())
                <<" is "<<it.second->signature(types)
                <<"\n";
        }
    }
    unresolved_options = false;
    return true;
}


vector<Type> Def::get_lazy_options(Types& _types) {
    // store prev state

    vector<Variable> parametric_names;
    for(const auto& it : parametric_types) {parametric_names.push_back(it.first);}
    vector<unordered_map<Variable, Type>> argoptions;
    signature_until_position(argoptions, parametric_names, 0, unordered_map<Variable, Type>(), _types);

    for(const unordered_map<Variable, Type>& argoption : argoptions) {
        auto def = make_shared<Def>(_types);
        def->retrievable_parameters = argoption;
        def->pos = pos;
        def->imp = imp;
        def->name = name;
        def->has_tried_to_resolve_before = false;
        if(!def->complete_option_resolution(_types)) continue;
        options.push_back(def);
        all_types.push_back(def);
    }
    if(options.size()==0) imp->error(pos, "Failed to resolve to any valid version\nCheck your `with` statements that have no `else`\nor if you have runtypes that serve as constructors of others with the same name or in the same union");
    return options;
}
