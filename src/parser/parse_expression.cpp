#include "../def.h"

string Def::parse_expression(const shared_ptr<Import>& imp, size_t& p, const string& first_token, Types& types, string curry) {
    if(first_token=="(") {
        string ret = parse_expression(imp, p, imp->at(p++), types, curry);
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        return next_var(imp, p, ret, types);
    }
    return parse_expression_no_par(imp, p, first_token, types, curry);
}


string Def::call_type(const shared_ptr<Import>& imp, size_t& p, Type& type, vector<string>& unpacks, const size_t first_token_pos, const string& first_token, const string& inherit_buffer, Types& types) {
    string overloading_errors("");
    string var = create_temp();
    Type successfullType = nullptr;
    string multipleFound("");
    int numberOfFound = 0;
    int numberOfErrors = 0;
    if(!type) imp->error(first_token_pos, "Not found runtype: "+first_token+recommend_runtype(types, first_token));
    Type previousType = type;
    int highest_choice_power = 0;
    for(size_t i=0;i<unpacks.size();++i) if(!internalTypes.contains(unpacks[i])) imp->error(p-3, "Not found: "+pretty_var(unpacks[i])+recommend_variable(types, unpacks[i]));
    type->number_of_calls++;
    for(const Type& type : previousType->get_options(types)) { // options encompases all overloads, in case of unions it may not have the base overloadv
        if(!type) imp->error(--p, "Internal error: obained a null option for "+previousType->name);
        try {
            //if(type->lazy_compile) throw runtime_error("Failed to resolve parametric type: "+type->signature());//+"\nParameters need to be determined by arguments");
            size_t type_args = type->not_primitive()?type->args.size():1;
            if(inherit_buffer.size()) {
                if(unpacks.size()>type_args) throw runtime_error(type->signature(types));
            }
            else if(unpacks.size()!=type_args) throw runtime_error(type->signature(types));
            for(size_t i=0;i<unpacks.size();++i) {
                auto arg_type = type->_is_primitive?type:type->args[i].type;
                if(type->not_primitive() && arg_type->not_primitive()) throw runtime_error(type->signature(types)+": Cannot unpack abstract " + arg_type->signature(types) + " "+type->args[i].name);
                if(!internalTypes.contains(unpacks[i])) throw runtime_error(type->signature(types)+": No runtype for "+pretty_var(unpacks[i]));
                if(type->not_primitive() && arg_type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i])) 
                    throw runtime_error(type->signature(types));
                    //throw runtime_error(type->signature(types)+": Expects " + arg_type->name + " "+pretty_var(type->name+"__"+type->args[i].name)+" but got "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
                if(type->not_primitive() && arg_type->_is_primitive && arg_type->name=="nom" && alignments[unpacks[i]]!=type->alignments[type->args[i].name]) {
                    if(type->alignments[type->args[i].name] && !types.reverse_alignment_labels[type->alignments[type->args[i].name]]) imp->error(first_token_pos, "Internal error: cannot find alignment "+to_string(type->alignments[type->args[i].name])+" of "+pretty_var(type->name+"__"+type->args[i].name)+" within "+signature(types));
                    if(alignments[unpacks[i]] && !types.reverse_alignment_labels[alignments[unpacks[i]]]) imp->error(first_token_pos, "Internal error: cannot find alignment "+to_string(alignments[unpacks[i]])+" for "+unpacks[i]+" argument "+pretty_var(type->name+"__"+type->args[i].name)+" within "+signature(types));
                    if(!alignments[unpacks[i]] || types.reverse_alignment_labels[alignments[unpacks[i]]]==type.get()) {}//REMINDER THAT THIS IS AN ERROR THAT POLUTES NEXT LOOP: alignments[unpacks[i]] = type->alignments[type->args[i].name];
                    else throw runtime_error(type->signature(types)+": nom "+pretty_var(type->name)+"__"+ pretty_var(type->args[i].name)
                        +" expects data from "+((!type->alignments[type->args[i].name] || !types.reverse_alignment_labels[type->alignments[type->args[i].name]])?"nothing":types.reverse_alignment_labels[type->alignments[type->args[i].name]]->signature(types))+" with id "+to_string(type->alignments[type->args[i].name])
                        +" but got "+((alignments[unpacks[i]] && types.reverse_alignment_labels[alignments[unpacks[i]]])?types.reverse_alignment_labels[alignments[unpacks[i]]]->signature(types):"nothing")+" with id "+to_string(alignments[unpacks[i]]));
                }
                if(type->not_primitive() && (type->args[i].mut || type->mutables.find(type->args[i].name)!=type->mutables.end()) && !can_mutate(unpacks[i])) 
                    throw runtime_error(type->signature(types));
                    //throw runtime_error(type->signature(types)+": Expects mutable " + arg_type->name + " "+pretty_var(type->name+"__"+type->args[i].name)+" but got immutable "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
            }
            if(type->choice_power>highest_choice_power) {
                highest_choice_power = type->choice_power;
                numberOfFound = 0;
                multipleFound = "";
            }
            if(type->choice_power<highest_choice_power) continue;
            /*bool equivalentTypes = true;
            if(!successfullType) equivalentTypes = false;
            else if(successfullType->name!=type->name) equivalentTypes = false;
            else if(successfullType->args.size()!=type->args.size()) equivalentTypes = false;
            else for(size_t i=0;i<type->args.size();++i) if(type->args[i].name!=successfullType->args[i].name || type->args[i].type!=successfullType->args[i].type) {equivalentTypes=false;break;}
            if(equivalentTypes) continue;
            */
            successfullType = type;
            if(markdown_errors) multipleFound += "\n";
            else multipleFound += "\n- ";
            multipleFound += type->signature(types);
            numberOfFound++;
        }
        catch (const std::runtime_error& e) {
            if(markdown_errors) overloading_errors += "\n";
            else overloading_errors += "\n- ";
            overloading_errors += e.what();
            numberOfErrors++;
        }
    }
    type = successfullType;
    string prev_errors("");
    if(!type && active_context.size()) { // 
        vector<string> new_unpacks;
        if(internalTypes.vars[active_context]->_is_primitive) new_unpacks.push_back(active_context);
        else for(const string& pack : internalTypes.vars[active_context]->packs) new_unpacks.push_back(active_context+"__"+pack);
        for(const string& pack : unpacks) new_unpacks.push_back(pack);
        prev_errors = string(markdown_errors?"```rust\n":"")+previousType->name+signature_like(types, unpacks)+(inherit_buffer.size()?" followed by a buffer (unpacks at least one value)":"")+(markdown_errors?"\n```\n":"")+"\namong "+to_string(numberOfErrors)+" candidates"+(markdown_errors?"\n```rust":"")+overloading_errors+(markdown_errors?"\n```\n":"")+"\nand not found `on` context\n  ";
        overloading_errors = "";
        unpacks = new_unpacks;

        // COPY OF ABOVE CODE HERE TO RETRY
        for(const Type& type : previousType->get_options(types)) { // options encompases all overloads, in case of unions it may not have the base overloadv
            if(!type) imp->error(--p, "Internal error: obained a null option for "+previousType->name);
            try {
                //if(type->lazy_compile) throw runtime_error("Failed to resolve parametric type: "+type->signature());//+"\nParameters need to be determined by arguments");
                size_t type_args = type->not_primitive()?type->args.size():1;
                if(inherit_buffer.size()) {
                    if(unpacks.size()>type_args) throw runtime_error(type->signature(types));
                }
                else if(unpacks.size()!=type_args) throw runtime_error(type->signature(types));
                for(size_t i=0;i<unpacks.size();++i) {
                    auto arg_type = type->_is_primitive?type:type->args[i].type;
                    if(type->not_primitive() && arg_type->not_primitive()) throw runtime_error(type->signature(types)+": Cannot unpack abstract " + arg_type->signature(types) + " "+type->args[i].name);
                    if(!internalTypes.contains(unpacks[i])) throw runtime_error(type->signature(types)+": No runtype for "+pretty_var(unpacks[i]));
                    if(type->not_primitive() && arg_type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i])) 
                        throw runtime_error(type->signature(types));
                        //throw runtime_error(type->signature(types)+": Expects " + arg_type->name + " "+pretty_var(type->name+"__"+type->args[i].name)+" but got "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
                    if(type->not_primitive() && arg_type->_is_primitive && arg_type->name=="nom" && alignments[unpacks[i]]!=type->alignments[type->args[i].name]) {
                        if(type->alignments[type->args[i].name] && !types.reverse_alignment_labels[type->alignments[type->args[i].name]]) imp->error(first_token_pos, "Internal error: cannot find alignment "+to_string(type->alignments[type->args[i].name])+" of "+pretty_var(type->name+"__"+type->args[i].name)+" within "+signature(types));
                        if(alignments[unpacks[i]] && !types.reverse_alignment_labels[alignments[unpacks[i]]]) imp->error(first_token_pos, "Internal error: cannot find alignment "+to_string(alignments[unpacks[i]])+" for "+unpacks[i]+" argument "+pretty_var(type->name+"__"+type->args[i].name)+" within "+signature(types));
                        if(!alignments[unpacks[i]] || types.reverse_alignment_labels[alignments[unpacks[i]]]==type.get()) {}//REMINDER THAT THIS IS AN ERROR THAT POLUTES NEXT LOOP: alignments[unpacks[i]] = type->alignments[type->args[i].name];
                        else throw runtime_error(type->signature(types)+": nom "+pretty_var(type->name)+"__"+ pretty_var(type->args[i].name)
                            +" expects data from "+((!type->alignments[type->args[i].name] || !types.reverse_alignment_labels[type->alignments[type->args[i].name]])?"nothing":types.reverse_alignment_labels[type->alignments[type->args[i].name]]->signature(types))+" with id "+to_string(type->alignments[type->args[i].name])
                            +" but got "+((alignments[unpacks[i]] && types.reverse_alignment_labels[alignments[unpacks[i]]])?types.reverse_alignment_labels[alignments[unpacks[i]]]->signature(types):"nothing")+" with id "+to_string(alignments[unpacks[i]]));
                    }
                    if(type->not_primitive() && (type->args[i].mut || type->mutables.find(type->args[i].name)!=type->mutables.end()) && !can_mutate(unpacks[i])) 
                        throw runtime_error(type->signature(types));
                        //throw runtime_error(type->signature(types)+": Expects mutable " + arg_type->name + " "+pretty_var(type->name+"__"+type->args[i].name)+" but got immutable "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
                }
                if(type->choice_power>highest_choice_power) {
                    highest_choice_power = type->choice_power;
                    numberOfFound = 0;
                    multipleFound = "";
                }
                if(type->choice_power<highest_choice_power) continue;
                /*bool equivalentTypes = true;
                if(!successfullType) equivalentTypes = false;
                else if(successfullType->name!=type->name) equivalentTypes = false;
                else if(successfullType->args.size()!=type->args.size()) equivalentTypes = false;
                else for(size_t i=0;i<type->args.size();++i) if(type->args[i].name!=successfullType->args[i].name || type->args[i].type!=successfullType->args[i].type) {equivalentTypes=false;break;}
                if(equivalentTypes) continue;
                */
                successfullType = type;
                if(markdown_errors) multipleFound += "\n";
                else multipleFound += "\n- ";
                multipleFound += type->signature(types);
                numberOfFound++;
            }
            catch (const std::runtime_error& e) {
                if(markdown_errors) overloading_errors += "\n";
                else overloading_errors += "\n- ";
                overloading_errors += e.what();
                numberOfErrors++;
            }
        }
    }
    type = successfullType;

    if(type.get()!=successfullType.get()) type->number_of_calls++;
    if(!type && numberOfErrors) imp->error(first_token_pos, "Not found\n  "+prev_errors+string(markdown_errors?"```rust\n":"")+previousType->name+signature_like(types, unpacks)+(inherit_buffer.size()?" followed by a buffer (unpacks at least one value)":"")+(markdown_errors?"\n```\n":"")+"\namong "+to_string(numberOfErrors)+" candidates"+(markdown_errors?"\n```rust":"")+overloading_errors+(markdown_errors?"\n```\n":""));
    if(!type) imp->error(first_token_pos, "Not found runtype version: "+first_token+" among "+to_string(previousType->options.size())+" candidates of "+previousType->signature(types));
    if(type->lazy_compile) imp->error(pos, "Internal error: Runtype has not been compiled");

    // repeat here to properly handle alignment (which we couldn't previously)
    for(size_t i=0;i<unpacks.size();++i) {
        auto arg_type = type->_is_primitive?type:type->args[i].type;
        if(type->not_primitive() && arg_type->not_primitive()) throw runtime_error(type->signature(types)+": Cannot unpack abstract " + arg_type->signature(types) + " "+type->args[i].name);
        if(!internalTypes.contains(unpacks[i])) throw runtime_error(type->signature(types)+": No runtype for "+pretty_var(unpacks[i]));
        if(type->not_primitive() && arg_type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i])) throw runtime_error(type->signature(types)+": Expects " + arg_type->name + " "+pretty_var(type->name+"__"+type->args[i].name)+" but got "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
        if(type->not_primitive() && arg_type->_is_primitive && arg_type->name=="nom" && alignments[unpacks[i]]!=type->alignments[type->args[i].name]) {
            if(type->alignments[type->args[i].name] && !types.reverse_alignment_labels[type->alignments[type->args[i].name]]) imp->error(pos, "Internal error: cannot find alignment "+to_string(type->alignments[type->args[i].name])+" of "+pretty_var(type->name+"__"+type->args[i].name)+" within "+signature(types));
            if(alignments[unpacks[i]] && !types.reverse_alignment_labels[alignments[unpacks[i]]]) imp->error(pos, "Internal error: cannot find alignment "+to_string(alignments[unpacks[i]])+" for "+unpacks[i]+" argument "+pretty_var(type->name+"__"+type->args[i].name)+" within "+signature(types));
            if(!alignments[unpacks[i]] || types.reverse_alignment_labels[alignments[unpacks[i]]]==type.get()) alignments[unpacks[i]] = type->alignments[type->args[i].name];
            else throw runtime_error(type->signature(types)+": nom "+pretty_var(type->name+"__"+type->args[i].name)
                +" expects data from "+((!type->alignments[type->args[i].name] || !types.reverse_alignment_labels[type->alignments[type->args[i].name]])?"nothing":types.reverse_alignment_labels[type->alignments[type->args[i].name]]->signature(types))+" with id "+to_string(type->alignments[type->args[i].name])
                +" but got "+((alignments[unpacks[i]] && types.reverse_alignment_labels[alignments[unpacks[i]]])?types.reverse_alignment_labels[alignments[unpacks[i]]]->signature(types):"nothing")+" with id "+to_string(alignments[unpacks[i]]));
        }
        if(type->not_primitive() && (type->args[i].mut || type->mutables.find(type->args[i].name)!=type->mutables.end()) && !can_mutate(unpacks[i])) throw runtime_error(type->signature(types)+": Expects mutable " + arg_type->name + " "+pretty_var(type->name+"__"+type->args[i].name)+" but got immutable "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
           
    }

    // TODO: reinstate this but improve inference
    //if(numberOfFound>1) imp->error(first_token_pos, "Ambiguous use of ["+to_string(unpacks.size())+"] structural arguments - they match "+to_string(numberOfFound)+" candidates"+(markdown_errors?"\n```rust":"")+multipleFound+(markdown_errors?"\n```\n":""));
    if(inherit_buffer.size()) { // unpack buffer
        string arg = inherit_buffer;
        int remaining = (int)(type->args.size()-unpacks.size());
        if(type->_is_primitive) remaining++;
        string fail_var = create_temp();
        string fail_var_type = create_temp();
        if(remaining==1) implementation += "if("+arg+"____size<="+arg+"____offset) goto "+fail_var+";\n";
        else implementation += "if("+arg+"____size<"+arg+"____offset+"+to_string(remaining)+") goto "+fail_var+";\n";
        errors += fail_var+":\nprintf(\"Runtime error: buffer is empty\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
        errors += fail_var_type+":\nprintf(\"Runtime error: buffer element has the wrong type\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
        add_preample("#include <stdio.h>");
        string tmp = create_temp();
        for(int i=0;i<remaining;++i) {
            Type desiredType = type->_is_primitive?type:type->args[unpacks.size()].type;// don't add i because we push back the element
            bool typecheck = !buffer_primitive_associations[inherit_buffer];//desiredType!=buffer_primitive_associations[inherit_buffer];
            if(!typecheck && desiredType!=buffer_primitive_associations[inherit_buffer]) imp->error(--p, "Buffer contains only "+buffer_primitive_associations[inherit_buffer]->name+" primitives but tried to extract "+desiredType->name);
            string element = "__"+tmp+"__"+to_string(i);
            if(typecheck) {
                internalTypes.vars[element+"t"] = types.vars["u64"];
                implementation += element+"t = ((u64*)"+arg+"____typetag)[("+ to_string(i)+"+"+arg+"____offset)/16];\n";
                string pos = "((("+ to_string(i)+"+"+arg+"____offset)%16)*4)";
                implementation += "if((("+element+"t>>"+pos+")& 0xF)!=__IS_"+desiredType->name+") goto "+fail_var_type+";\n";
            }
            implementation += "std::memcpy(&" + element + ", (unsigned char*)" + arg + "____contents+sizeof(u64)*("+ to_string(i)+"+"+arg+"____offset), sizeof("+element+"));\n";
            if(desiredType) internalTypes.vars[element] = desiredType;
            unpacks.push_back(element);
        }
        implementation += arg+"____offset += "+to_string(remaining)+";\n";
    }


    for(const string& pack : type->packs) type->coallesce_finals(pack);
    auto transfer_finals = type->finals;
    unordered_map<string, string> transferring;
    for(const string& pack : type->packs) if(type->finals[pack].size()) {
        type->coallesce_finals(pack);
        finals[var+"__"+pack] += type->rebase(type->finals[pack], var);
        transferring[var+"__"+pack] = finals[var+"__"+pack];
        transfer_finals[pack] = "";
    }
    for(const auto& arg : type->args) if(arg.mut && type->finals[arg.name].size()) {
        type->coallesce_finals(arg.name);
        finals[var+"__"+arg.name] += type->rebase(type->finals[arg.name], var);
        transferring[var+"__"+arg.name] = finals[var+"__"+arg.name];
        transfer_finals[arg.name] = "";
    }
    for(const auto& it : type->current_renaming) current_renaming[var+"__"+it.first] = var+"__"+it.second;

    // prevent memory leaks in loops
    if(uplifiting_is_loop.size() && uplifiting_is_loop.back() && type->finals.size()) {
        string desc("");
        for(const auto& it : transferring) if(it.first.size() && it.second.size()) desc += "\n- "+pretty_var(type->name+"__"+it.first);
        if(desc.size()) imp->error(--p, "Loop cannot call: "+type->signature(types)+"\nThis could leak the following resources:"+desc);
    }

    for(const string& mut : type->mutables) mutables.insert(var+"__"+mut);
    mutables.insert(var); // MAKE ALL CALL OUTCOMES MUTABLE BY DEFAULT

    // make actual call
    if(type->is_service) {
        // vardecl += "errcode "+var+"__err = 0;\n";
        string impl = var+"__err = "+type->name+"(";
        internalTypes.vars[var+"__err"] = types.vars["errcode"];
        internalTypes.vars[var] = type;
        for(const string& pack : type->packs) if(type->alignments[pack]) alignments[var+"__"+pack] = type->alignments[pack];
        bool toadd = false;
        for(size_t i=1;i<type->packs.size();++i) { // first service output is the error code, which we return instead of parsing by reference
            const string& ret = type->packs[i];
            size_t fp = first_token_pos;
            assign_variable(type->internalTypes.vars[ret], var+"__"+ret, "0", imp, fp);
            if(toadd) impl += ",";
            impl += var+"__"+ret;
            toadd = true;
            //type->coallesce_finals(ret);
            //finals[var+"__"+ret] += type->rebase(type->finals[ret], var);
            if(type->internalTypes.vars[ret]->name=="buffer") buffer_primitive_associations[var+"__"+ret] = type->buffer_primitive_associations[ret];
        }
        for(const auto& it : type->internalTypes.vars) internalTypes.vars[var+"__"+it.first] = it.second;
        for(size_t i=0;i<unpacks.size();++i) {
            if(toadd) impl += ",";
            impl += unpacks[i];
            toadd = true;
            if(type->args[i].mut) {
                string ret = unpacks[i];
                type->coallesce_finals(type->args[i].name);
                finals[unpacks[i]] += type->rename_var(type->finals[type->args[i].name], type->args[i].name, unpacks[i]);
                if(type->internalTypes.vars[ret]->name=="buffer") buffer_primitive_associations[unpacks[i]] = type->buffer_primitive_associations[type->args[i].name];
            }
        }
        impl += ");\n";
        implementation += impl;
        finals[var] = type->rebase(type->finals_when_used, var);
        internalTypes.vars[var] = type->alias_for.size()?type->internalTypes.vars[type->alias_for]:type;
        if(internalTypes.vars[var]->name=="buffer") buffer_primitive_associations[var] = type->buffer_primitive_associations[type->alias_for];
        return next_var(imp, p, var, types);
    }
    if(type->_is_primitive) {
        if(unpacks.size()!=1) imp->error(--p, "Primitive types only accept one argument");
        size_t fp = first_token_pos;
        assign_variable(type, var, unpacks[0], imp, fp);
        return next_var(imp, p, var, types);
    }
    for(const auto& it : type->alignments) if(it.second) alignments[var+"__"+it.first] = it.second; 
    string immediate_finals("");
    for(size_t i=0;i<unpacks.size();++i) {
        size_t fp = first_token_pos;
        assign_variable(type->args[i].type, var+"__"+type->args[i].name, unpacks[i], imp, fp);
        if(type->args[i].mut) {
            immediate_finals += unpacks[i]+ " = "+var+"__"+type->args[i].name+";\n";
            current_renaming[unpacks[i]] = var+"__"+type->args[i].name;
            current_renaming[var+"__"+type->args[i].name] = unpacks[i];

            current_renaming[unpacks[i]] = var+"__"+type->args[i].name;
            buffer_primitive_associations[unpacks[i]] = type->buffer_primitive_associations[var+"__"+type->args[i].name];
        }
    }

    for(const auto& it : type->internalTypes.vars) internalTypes.vars[var+"__"+it.first] = it.second;
    for(const auto& final : transfer_finals) immediate_finals += type->rebase(final.second, var);

    internalTypes.vars[var] = type->alias_for.size()?type->internalTypes.vars[type->alias_for]:type;
    implementation += type->rebase(type->implementation, var);
    implementation += immediate_finals;
    for(const string& pre : type->preample) add_preample(type->rebase(pre, var));

    //for(const auto& final : type->finals) finals[var+"__"+final.first] += type->rebase(final.second, var); // splt into immediate and delayed finals
    //finals = type->rebase(type->finals, var)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
    errors = errors+type->rebase(type->errors, var);
    for(const auto& it : type->current_renaming) current_renaming[var+"__"+it.first] = var+"__"+it.second;
    for(const auto& it : type->internalTypes.vars) if(it.second) { // TODO: remove this if (currently it guards against some leftover labels)
        if(!it.second) imp->error(--p, type->name+"."+pretty_var(it.first)+" is undefined");
        internalTypes.vars[var+"__"+it.first] = it.second;
        if(it.second->name=="buffer") buffer_primitive_associations[var+"__"+it.first] = type->buffer_primitive_associations[it.first];
    }
    //finals[""] += immediate_finals; // TODO maybe it's a good idea to have some deallocations at the end of runtype implementations
    finals[var] = type->rebase(type->finals_when_used, var);
    if(internalTypes.contains(var) && internalTypes.vars[var]->name=="buffer") buffer_primitive_associations[var] = type->buffer_primitive_associations[type->alias_for];
    if(type->packs.size()==1) return next_var(imp, p, var+"__"+type->packs[0], types);
    return next_var(imp, p, var, types);
}


string Def::parse_expression_no_par(const shared_ptr<Import>& imp, size_t& p, const string& first_token, Types& types, string curry) {
    size_t first_token_pos = p-1;
    if(first_token=="." || first_token==":" || first_token=="[" || first_token=="]" || first_token=="{" || first_token=="}" || first_token==";"|| first_token=="&") imp->error(p-1, "Unexpected symbol\nThe previous expression already ended.");

    if(first_token=="if") {
        string temp = create_temp();
        string finally_var = temp+"__if";
        string closeif_var = temp+"__fi";
        uplifting_targets.push_back(finally_var);
        if(uplifiting_is_loop.size()) uplifiting_is_loop.push_back(uplifiting_is_loop.back());
        else uplifiting_is_loop.push_back(false);
        internalTypes.vars[finally_var] = types.vars["__label"];
        internalTypes.vars[closeif_var] = types.vars["__label"];
        string next = imp->at(p++);
        string var = parse_expression(imp, p, next, types, curry);
        if(!internalTypes.contains(var)) imp->error(--p, "Expression did not evaluate to anything");
        if(internalTypes.vars.find(var)->second!=types.vars["bool"]) imp->error(--p, "If expects bool condition but got "+internalTypes.vars.find(var)->second->name+" "+pretty_var(var));
        implementation += "if(!"+var+") goto "+closeif_var+";\n";
        parse(imp, p, types, false);
        p++; // offset p-- after parse_return above
        string else_var("");
        if(p<imp->size()-1 && imp->at(p)=="else") {
            p++;
            else_var = temp+"__le";
            internalTypes.vars[else_var] = types.vars["__label"];
            string else_skip = temp+"__el";
            internalTypes.vars[else_skip] = types.vars["__label"];
            uplifting_targets.pop_back();
            uplifting_targets.push_back(else_var);
            implementation += finally_var+":\n";
            implementation += "goto "+else_skip+";\n";
            implementation += closeif_var+":\n";
            parse(imp, p, types, false);
            implementation += else_var+":\n";
            p++; // offset p-- after parse_return above
            if(internalTypes.contains(else_var+"r") && !internalTypes.contains(finally_var+"r")) imp->error(first_token_pos, "There was a non-empty return "+internalTypes.vars[else_var+"r"]->name+" `else` but no such value from `if`");
            if(!internalTypes.contains(else_var+"r") && internalTypes.contains(finally_var+"r")) imp->error(first_token_pos, "There was a non-empty return "+internalTypes.vars[finally_var+"r"]->name+" `if` but no such value from `else`");
            if(internalTypes.contains(else_var+"r")&& internalTypes.contains(finally_var+"r")) {
                if(internalTypes.vars[finally_var+"r"]!=internalTypes.vars[else_var+"r"]) imp->error(first_token_pos, "There were mismatching return "+internalTypes.vars[finally_var+"r"]->name+" `if` and "+internalTypes.vars[else_var+"r"]->name+" `else`");
                assign_variable(internalTypes.vars[finally_var+"r"],finally_var+"r", else_var+"r", imp, first_token_pos, false, false);
            }
            implementation += else_skip+":\n";
        }
        else implementation += finally_var+":\n"+closeif_var+":\n";
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        if(internalTypes.contains(finally_var+"r")) {
            if(else_var.size()==0) imp->error(first_token_pos, "There was a non-empty return "+internalTypes.vars[finally_var+"r"]->name+" `if` but no `else` statement for the alternative"); 
            return finally_var+"r";
        }
        return "";
    }
    if(first_token=="while") {
        string temp = create_temp();
        string finally_var = temp+"__while";
        uplifting_targets.push_back(finally_var);
        uplifiting_is_loop.push_back(true);
        string start_var = temp+"__loop";
        internalTypes.vars[start_var] = types.vars["__label"];
        internalTypes.vars[finally_var] = types.vars["__label"];
        implementation += start_var+":\n";
        string next = imp->at(p++);
        string var = parse_expression(imp, p, next, types, curry);
        if(!internalTypes.contains(var)) imp->error(--p, "Expression did not evaluate to anything");
        if(internalTypes.vars.find(var)->second!=types.vars["bool"]) imp->error(--p, "If expects bool condition but got "+internalTypes.vars.find(var)->second->name+" "+pretty_var(var));
        implementation += "if(!"+var+") goto "+finally_var+";\n";
        parse(imp, p, types, false);
        p++; // offset p-- after parse_return above
        implementation += "goto "+start_var+";\n";
        implementation += finally_var+":\n";
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        return "";
    }
    if(first_token=="on") {
        if(curry.size()) imp->error(p, "Cannot curry onto `on`");
        if(active_context.size()) imp->error(p, "There is already an active context in this implementation\nEnd its code block to enter a new context with `on`.");
        string next = imp->at(p++);
        active_context = parse_expression(imp,p,next,types,curry);
        if(!active_context.size() || !internalTypes.contains(active_context)) imp->error(--p, "Expression does not evaluate to a variable to use as `on` context");
        string temp = create_temp();
        string finally_var = temp+"__on";
        internalTypes.vars[finally_var] = types.vars["__label"];
        //int on_start = p-1;
        uplifting_targets.push_back(finally_var);
        if(uplifiting_is_loop.size()) uplifiting_is_loop.push_back(uplifiting_is_loop.back());
        else uplifiting_is_loop.push_back(false);
        parse(imp, p, types, false);
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        p++;
        string var = finally_var+"r";
        if(!internalTypes.contains(var)) var = "";
        implementation += finally_var+":\n";
        active_context = "";
        return var;
    }
    if(first_token=="with") { // TODO: this implementation does not account for nesting
        string temp = create_temp();
        string finally_var = temp+"__with";
        size_t numberOfCandidates = 0;
        string overloading_errors = "";
        string competing = "";
        int with_start = p-1;
        uplifting_targets.push_back(finally_var);
        if(uplifiting_is_loop.size()) uplifiting_is_loop.push_back(uplifiting_is_loop.back());
        else uplifiting_is_loop.push_back(false);
        internalTypes.vars[finally_var] = types.vars["__label"];
        string next;
        try {
            if(curry.size()) imp->error(--p, "Cannot have a curry onto `with`.");
            parse(imp, p, types, false);
            p++;
            next = imp->at(p++);
            numberOfCandidates++;
            implementation += "goto "+finally_var+";\n";
            if(numberOfCandidates) competing = "\n"+imp->tokens[with_start].show();
        }
        catch (const runtime_error& e) {
            string what = e.what();
            if(what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found" && (what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found")) throw e;
            if(Def::markdown_errors) overloading_errors += "\n";
            else overloading_errors += "\n- ";
            overloading_errors += what;
            end_block(imp, p);
            next = imp->at(p++);
            if(next!="else") imp->error(with_start, "`with` with no `else`\nCan guard parametric types but is a code smell otherwise\nHere it is redundant as enclosed code always succeeds");
        }
        while(next=="else") {
            if(!numberOfCandidates) {
                try {
                    size_t else_start = p-1;
                    parse(imp, p, types, false);
                    numberOfCandidates++;
                    implementation += "goto "+finally_var+";\n";
                    ++p;
                    if(numberOfCandidates) competing = "\n"+imp->tokens[else_start].show();
                }
                catch (const std::runtime_error& e) {
                    string what = e.what();
                    if(what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found") throw e;
                    if(Def::markdown_errors) overloading_errors += "\n";
                    else overloading_errors += "\n- ";
                    overloading_errors += what;
                    end_block(imp, p);
                }
            }
            else end_block(imp, p);
            next = p<imp->size()?imp->at(p):"";
            p++;
        }
        p--;
        if(numberOfCandidates>1) ERROR("Competes with previous branch of `with`"+competing);
        if(numberOfCandidates==0) imp->error(with_start, "No valid branch of `with`"+string(Def::markdown_errors?"\n```rust":"")+overloading_errors+(Def::markdown_errors?"\n```\n":""));

        implementation += finally_var+":\n";
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        return "";
    }

    if(is_primitive(first_token)) {
        string vartype = type_primitive(first_token);
        string defval = "0";
        if(p<imp->size() && imp->at(p)=="@" && imp->at(p+1)=="else") {
            defval = imp->at(p+2);
            p += 3;
            if(type_primitive(defval)!=vartype) imp->error(p-1, "Required "+vartype+" primitive");
        }
        string var = create_temp();
        if(!types.contains(vartype)) return first_token;// fallback
        internalTypes.vars[var] = types.vars[vartype];
        // vardecl += vartype+" "+var+" = "+defval+";\n"; // always set vars to zero because they may reside in if blocks
        implementation += var+" = "+first_token+";\n";
        //mutables.insert(var);
        return next_var(imp, p, var, types);
    }
    if(first_token == "len" && curry.size() && internalTypes.contains(curry) && internalTypes.vars[curry]->name=="buffer") {
        string var = create_temp();
        implementation += var + " = " + curry+"____size-"+curry+"____offset;\n"; 
        internalTypes.vars[var] = types.vars["u64"];
        return next_var(imp, p, var, types);
    }
    if(first_token == "put" && curry.size() && internalTypes.contains(curry) && internalTypes.vars[curry]->name=="buffer") {
        string arg = curry;
        if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
        string inherit_buffer("");
        vector<string> unpacks = gather_tuple(imp, p, types, inherit_buffer, "");
        if(inherit_buffer.size()) imp->error(--p, "Cannot unpack from a buffer to put elements in a buffer");
        int remaining = unpacks.size();
        if(!remaining) imp->error(--p, "Need to set at least one element to the buffer");
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        string fail_var = create_temp();
        string fail_var_type = create_temp();
        if(remaining==1) implementation += "if("+arg+"____size<="+arg+"____offset) goto "+fail_var+";\n";
        else implementation += "if("+arg+"____size<"+arg+"____offset+"+to_string(remaining)+") goto "+fail_var+";\n";
        errors += fail_var+":\nprintf(\"Runtime error: buffer is empty\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
        errors += fail_var_type+":\nprintf(\"Runtime error: buffer element would replace a different type\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
        add_preample("#include <stdio.h>");
        string tmp = create_temp();
        for(int i=0;i<remaining;++i) {
            if(!internalTypes.contains(unpacks[i])) imp->error(p-2, "Non-existing variable: "+pretty_var(unpacks[i]));
            Type desiredType = internalTypes.vars[unpacks[i]];
            bool typecheck = !buffer_primitive_associations[arg];
            if(!typecheck && desiredType!=buffer_primitive_associations[arg]) imp->error(p-2, "Buffer contains only "+buffer_primitive_associations[arg]->name+" primitives but tried to replace one with "+desiredType->name);
            string element = "__"+tmp+"__"+to_string(i);
            if(typecheck) {
                internalTypes.vars[element+"t"] = types.vars["u64"];
                implementation += element+"t = ((u64*)"+arg+"____typetag)[("+ to_string(i)+"+"+arg+"____offset)/16];\n";
                string pos = "((("+ to_string(i)+"+"+arg+"____offset)%16)*4)";
                implementation += "if((("+element+"t>>"+pos+")& 0xF)!=__IS_"+desiredType->name+") goto "+fail_var_type+";\n";
            }
            //if(desiredType->name=="i64" || desiredType->name=="f64" || desiredType->name=="ptr" || desiredType->name=="cstr") implementation += "((u64*)" + arg + "____contents)["+ to_string(i)+"+"+arg+"____offset] = std::bit_cast<u64>("+unpacks[i]+");\n";
            implementation += "std::memcpy((unsigned char*)" + arg + "____contents+sizeof(u64)*("+ to_string(i)+"+"+arg+"____offset), &"+unpacks[i]+", sizeof("+unpacks[i]+"));\n";
        }
        implementation += arg+"____offset += "+to_string(remaining)+";\n";
        return next_var(imp, p, arg, types);
    }
    if(internalTypes.contains(first_token)) {
        if(curry.size()) imp->error(p, "Expecting runtype but got variable: "+first_token);
        return next_var(imp, p, first_token, types); //ASSIGNMENT TO ALREADY EXISTING VARIABLE
    }
    if(first_token=="buffer") {
        string var = create_temp();
        add_preample("#include<cstdlib>");
        string inherit_buffer("");
        string prototype_buffer("");
        vector<string> unpacks;
        if(imp->at(p)=="(") {
            if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
            if(curry.size() && !internalTypes.contains(curry)) imp->error(--p, "Non-existing curry: "+pretty_var(curry));
            if(curry.size() && internalTypes.vars[curry]==types.vars["buffer"]) {prototype_buffer = curry;curry="";}
            unpacks = gather_tuple(imp, p, types, inherit_buffer, curry);
            if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        }
        else {
            if(!curry.size()) imp->error(p, "Expecting opening parenthesis when there is no curry");
            if(!internalTypes.contains(curry)) imp->error(--p, "Non-existing curry: "+pretty_var(curry));
            if(internalTypes.vars[curry]==types.vars["buffer"]) {prototype_buffer=curry;curry="";}
            else if(internalTypes.vars[curry]->_is_primitive) unpacks.push_back(curry);
            else if(internalTypes.vars[curry]->is_service) {
                string fail_var = create_temp();
                implementation += "if("+var+"__err) goto "+fail_var+";\n";
                errors += fail_var+":\nprintf(\"Runtime error from "+internalTypes.vars[curry]->name+" "+pretty_var(curry)+"\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n";
                add_preample("#include <stdio.h>");
                for(size_t i=1;i<internalTypes.vars[curry]->packs.size();++i) unpacks.push_back(curry+"__"+internalTypes.vars[curry]->packs[i]);
            }
            else for(const string& pack : internalTypes.vars[curry]->packs) unpacks.push_back(curry+"__"+pack);
        }
        implementation += "if("+var+"____size-"+var+"____offset) free("+var+"____contents);\n";
        implementation += var+"____size = "+to_string(unpacks.size())+(inherit_buffer.size()?(" + "+inherit_buffer+"____size"):"")+(prototype_buffer.size()?(" + "+prototype_buffer+"____size"):"")+";\n";
        implementation += var+"____offset = 0;\n";
        implementation += var + "____contents = malloc(sizeof(i64)*" + var + "____size);\n";
        implementation += var + "____typetag = calloc(" + var + "____size/16+1, sizeof(u64));\n";
        //implementation += "std::memcpy((unsigned char*)" + var + "____contents, &" + var + "____size, sizeof(u64));\n";
        if(unpacks.size() && internalTypes.contains(unpacks[0])) buffer_primitive_associations[var] = internalTypes.vars[unpacks[0]];
        else if(prototype_buffer.size()) buffer_primitive_associations[var] = buffer_primitive_associations[prototype_buffer];
        else if(inherit_buffer.size()) buffer_primitive_associations[var] = buffer_primitive_associations[inherit_buffer];

        if(prototype_buffer.size() && buffer_primitive_associations[prototype_buffer]!=buffer_primitive_associations[var]) buffer_primitive_associations[var] = nullptr;
        if(inherit_buffer.size() && buffer_primitive_associations[inherit_buffer]!=buffer_primitive_associations[var]) buffer_primitive_associations[var] = nullptr;

        string offset = to_string(unpacks.size());
        if (prototype_buffer.size()) {
            implementation += "std::memcpy((unsigned char*)"+var+"____contents,  (unsigned char*)"+prototype_buffer+"____contents, sizeof(u64)*"+prototype_buffer+"____size);\n";
            implementation += "memcpy((unsigned char*)"+var+"____typetag, (unsigned char*)"+prototype_buffer+"____typetag, sizeof(u64) * ("+prototype_buffer+"____size / 16+1));\n";
            offset += "+"+prototype_buffer+"____size";


            for(size_t i = 0; i < unpacks.size(); ++i) {
            if(buffer_primitive_associations[var]!=internalTypes.vars[unpacks[i]]) buffer_primitive_associations[var] = nullptr;
            //if(buffer_primitive_associations[var]) 
            // for now it's mandatory to set the type because we might lose the primitive association in the future - the optimizer may just remove if if unused though
            implementation += "((u64*)" + var + "____typetag)[("+to_string(i)+"+"+prototype_buffer+"__size)/16] |= ((u64)__IS_"+internalTypes.vars[unpacks[i]]->name+")<<("+to_string(i)+"+"+prototype_buffer+"__size)%16)*4;\n";
            implementation += "std::memcpy((unsigned char*)" + var + "____contents + sizeof(u64) * (" + to_string(i)+"+"+prototype_buffer+ "__size), &" + unpacks[i] + ", sizeof("+unpacks[i]+"));\n";
        }
        }
        else for(size_t i = 0; i < unpacks.size(); ++i) {
            if(buffer_primitive_associations[var]!=internalTypes.vars[unpacks[i]]) buffer_primitive_associations[var] = nullptr;
            //if(buffer_primitive_associations[var]) 
            // for now it's mandatory to set the type because we might lose the primitive association in the future - the optimizer may just remove if if unused though
            implementation += "((u64*)" + var + "____typetag)["+to_string(i/16)+"] |= ((u64)__IS_"+internalTypes.vars[unpacks[i]]->name+")<<"+to_string((i%16)*4)+";\n";
            implementation += "std::memcpy((unsigned char*)" + var + "____contents + sizeof(u64) * " + to_string(i) + ", &" + unpacks[i] + ", sizeof("+unpacks[i]+"));\n";
        }
        if(inherit_buffer.size()) {
            implementation += "std::memcpy((unsigned char*)"+var+"____contents+sizeof(u64)*("+offset+"),  (unsigned char*)"+inherit_buffer+"____contents, sizeof(u64)*"+inherit_buffer+"____size);\n";
            implementation += "for(u64 i = 0; i < "+inherit_buffer+"____size; ++i) ((u64*)"+var+"____typetag)[(i+"+offset+")/16] |=((u64*)"+prototype_buffer+"____typetag)[(i+"+offset+")/16] << (((i+"+offset+")%16)*4);\n";
            offset += "+"+prototype_buffer+"____size";
        }


        internalTypes.vars[var] = types.vars.find(first_token)->second;
        internalTypes.vars[var+"____size"] = types.vars["u64"];
        internalTypes.vars[var+"____offset"] = types.vars["u64"];
        internalTypes.vars[var+"____contents"] = types.vars["ptr"];
        internalTypes.vars[var+"____typetag"] = types.vars["ptr"];
        finals[var+"____contents"] += "if("+var+"____contents) free(" + var + "____contents);\n"+var+"____contents = 0;\n";
        finals[var+"____typetag"] += "if("+var+"____typetag) free(" + var + "____typetag);\n"+var+"____typetag = 0;\n";
        return next_var(imp, p, var, types);
    }
    if(types.contains(first_token)) {
        auto type = types.vars.find(first_token)->second;
        string inherit_buffer("");
        vector<string> unpacks;
        if(imp->at(p)=="__consume") {
            if(!curry.size()) imp->error(p-2, "Unexpected usage of operator\nThere is no left-hand-side");
            if(!internalTypes.contains(curry)) imp->error(first_token_pos-2, "Not found: "+pretty_var(curry)+recommend_runtype(types, curry));
            else if(internalTypes.vars.find(curry)->second==types.vars["buffer"]) imp->error(p-2, "Operator does not accept buffer as the first input");
            else if(internalTypes.vars.find(curry)->second->not_primitive()) {
                for(const string& pack : internalTypes.vars.find(curry)->second->packs) unpacks.push_back(curry+"__"+pack);
            }
            else unpacks.push_back(curry);
            p++;
            string next = imp->at(p++);
            string rhs = parse_expression(imp, p, next, types);
            if(!internalTypes.contains(rhs)) imp->error(--p, "Failed to parse the right-hand-side of "+first_token);
            const auto& rhsType = internalTypes.vars.find(rhs)->second;
            if(rhsType->name=="buffer") imp->error(--p, "Cannot involve a buffer in operation "+first_token);
            if(rhsType->_is_primitive) unpacks.push_back(rhs);
            else if(type->is_service) {
                string fail_var = create_temp();
                implementation += "if("+rhs+"__err) goto "+fail_var+";\n";
                errors += fail_var+":\nprintf(\"Runtime error from "+rhsType->name+" "+pretty_var(rhs)+"\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n";
                add_preample("#include <stdio.h>");
                for(size_t i=1;i<rhsType->packs.size();++i) unpacks.push_back(rhs+"__"+rhsType->packs[i]);
            }
            else for(const string& pack : rhsType->packs) unpacks.push_back(rhs+"__"+pack);
        }
        else if(imp->at(p)!="(" && curry.size()) {
            if(!internalTypes.contains(curry)) imp->error(first_token_pos-2, "Not found: "+pretty_var(curry)+recommend_runtype(types, curry));
            else if(internalTypes.vars.find(curry)->second==types.vars["buffer"]) inherit_buffer = curry;
            else if(internalTypes.vars.find(curry)->second->not_primitive()) {
                for(const string& pack : internalTypes.vars.find(curry)->second->packs) unpacks.push_back(curry+"__"+pack);
                //if(type->args.size() && type->args[0].type->name=="nom") alignments[curry+"__"+type->args[0].name] = alignment_labels[type.get()]; (should be already done)
            }
            else unpacks.push_back(curry);
        }
        else if(imp->at(p)==")" || imp->at(p)=="]" || imp->at(p)=="," || imp->at(p)==":"){// || imp->at(p)=="and" || imp->at(p)=="or" 
            //|| types.vars.find(imp->at(p))!=types.vars.end() || (imp->at(p)=="-" && p<imp->size()-1 && (imp->at(p+1)=="-" || imp->at(p+1)==">"))) {
            int num_choices = 0;
            int highest_choice_power = 0;
            if(parametric_types.find(type->name)!=parametric_types.end()) type = parametric_types[type->name];
            string candidates("");
            for(const auto& option : type->options) {
                if(option->choice_power>highest_choice_power) {
                    highest_choice_power = option->choice_power;
                    num_choices = 0;
                    candidates = "";
                }
                if(option->choice_power<highest_choice_power) continue;
                num_choices ++;
                type = option;
                candidates += "\n"+option->signature(types);
            }

            if(num_choices==0) imp->error(--p, "Overloaded or union runtype has no alternative");
            if(num_choices!=1) imp->error(--p, "Overloaded or union runtype names are ambiguous.\nConsider defining exactly one of them with ->@new return\nto break the priority stalemate.\nCandidates:"+candidates);
            
            if(type->not_primitive()) for(size_t i=0;i<type->args.size();++i) {
                string var = create_temp();
                if(p<imp->size()-1 && imp->at(p+1)=="&") mutables.insert(var);
                assign_variable(type->args[i].type, var+"__"+type->args[i].name, "0", imp, first_token_pos, true);
                type_trackers.insert(var);
                unpacks.push_back(var+"__"+type->args[i].name);
            }
            else {
                string var = create_temp();
                if(p<imp->size()-1 && imp->at(p+1)=="&") mutables.insert(var);
                assign_variable(type, var, "0", imp, first_token_pos, true);
                type_trackers.insert(var);
                unpacks.push_back(var);
            }
        }
        else if(((p<imp->size()-1 && imp->at(p)!="(" && (imp->at(p+1)==")" || imp->at(p+1)==",")) || (p<imp->size()-2 && imp->at(p)=="&" && imp->at(p+1)!="(" && (imp->at(p+2)==")" || imp->at(p+2)==",")))){
            string var = imp->at(p++);
            if(var=="&") {
                var = imp->at(p++);
                mutables.insert(var);
            }
            if(internalTypes.contains(var)) imp->error(--p, "Cannot redeclare local variable "+internalTypes.vars[var]->name+" "+pretty_var(var));
            if(parametric_types.find(type->name)!=parametric_types.end()) type = parametric_types[type->name];
            int num_choices = 0;
            int highest_choice_power = 0;
            string candidates("");
            for(const auto& option : type->options) {
                if(option->choice_power>highest_choice_power) {
                    highest_choice_power = option->choice_power;
                    num_choices = 0;
                    candidates = "";
                }
                if(option->choice_power<highest_choice_power) continue;
                num_choices ++;
                type = option;
                candidates += "\n"+option->signature(types);
            }
            if(num_choices!=1) imp->error(--p, "Overloaded or union runtype names are ambiguous.\nConsider defining exactly one of them with ->@new return\nto break the priority stalemate.\nCandidates:"+candidates);
            if(type->not_primitive()) for(size_t i=0;i<type->args.size();++i) {
                internalTypes.vars[var+"__"+type->args[i].name] = type->args[i].type;
                unpacks.push_back(var+"__"+type->args[i].name);
                
            }
            else unpacks.push_back(var);
            if(type->args.size() && type->args[0].type->name=="nom") alignments[var+"__"+type->args[0].name] = types.alignment_labels[type.get()];
            internalTypes.vars[var] = type;
            return var;
        }
        else if(imp->at(p)!="(") {
            string var = create_temp();
            internalTypes.vars[var] = type;
            type_trackers.insert(var);
            if(p<imp->size()-1 && imp->at(p+1)=="&") mutables.insert(var);
            for(const string& pack : type->packs) assign_variable(type->internalTypes.vars[pack], var+"__"+pack, "0", imp, first_token_pos);
            if(type->args.size() && type->args[0].type->name=="nom") alignments[var+"__"+type->args[0].name] = types.alignment_labels[type.get()];
            return next_var(imp, p, var, types);
        }
        else {
            if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
            unpacks = gather_tuple(imp, p, types, inherit_buffer, curry);
            if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        }

        return call_type(imp, p, type, unpacks, first_token_pos, first_token, inherit_buffer, types);
    }
    if(curry.size() || (p<imp->size() && (imp->at(p)=="(" || imp->at(p)=="__consume"))) imp->error(--p, "Missing runtype: "+first_token+recommend_runtype(types, first_token));
    return next_var(imp, p, first_token, types);
}



