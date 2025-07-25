#include "../def.h"

Variable Def::parse_expression(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, const Variable& curry) {
    if(first_token=="(") {
        Variable ret = parse_expression(imp, p, imp->at(p++), types, curry);
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        return next_var(imp, p, ret, types);
    }
    return parse_expression_no_par(imp, p, first_token, types, curry);
}


Variable Def::call_type(const shared_ptr<Import>& imp, size_t& p, Type& type, vector<Variable>& unpacks, const size_t first_token_pos, const Variable& first_token, const Variable& inherit_buffer, Types& types) {
    
    static const Variable token_if = Variable("if(");
    static const Variable token_goto = Variable(")goto");
    string overloading_errors("");
    Variable var = create_temp();
    Type successfullType = nullptr;
    string multipleFound("");
    int numberOfFound = 0;
    int numberOfErrors = 0;
    if(!type) imp->error(first_token_pos, "Not found runtype: "+first_token.to_string()+recommend_runtype(types, first_token));
    Type previousType = type;
    int highest_choice_power = 0;
    for(size_t i=0;i<unpacks.size();++i) if(!internalTypes.contains(unpacks[i])) imp->error(p-3, "Not found: "+pretty_var(unpacks[i].to_string())+recommend_variable(types, unpacks[i]));
    type->number_of_calls++;
    for(const Type& type : previousType->get_options(types)) { // options encompases all overloads, in case of unions it may not have the base overloadv
        if(!type) imp->error(--p, "Internal error: obained a null option for "+previousType->name.to_string());
        try {
            //if(type->lazy_compile) throw runtime_error("Failed to resolve parametric type: "+type->signature());//+"\nParameters need to be determined by arguments");
            size_t type_args = type->not_primitive()?type->args.size():1;
            if(inherit_buffer.exists() && unpacks.size()>=type_args) throw runtime_error(type->signature(types));
            else if(unpacks.size()!=type_args) throw runtime_error(type->signature(types));
            for(size_t i=0;i<unpacks.size();++i) {
                auto arg_type = type->_is_primitive?type:type->args[i].type;
                if(type->not_primitive() && arg_type->not_primitive()) throw runtime_error(type->signature(types)+": Cannot unpack abstract " + arg_type->signature(types) + " "+type->args[i].name.to_string());
                if(!internalTypes.contains(unpacks[i])) throw runtime_error(type->signature(types)+": No runtype for "+pretty_var(unpacks[i].to_string()));
                if(type->not_primitive() && arg_type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i].to_string())) 
                    throw runtime_error(type->signature(types));
                    //throw runtime_error(type->signature(types)+": Expects " + arg_type->name + " "+pretty_var(type->name+"__"+type->args[i].name)+" but got "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
                if(type->not_primitive() && arg_type->_is_primitive && arg_type->name=="nom" && alignments[unpacks[i]]!=type->alignments[type->args[i].name]) {
                    if(type->alignments[type->args[i].name] && !types.reverse_alignment_labels[type->alignments[type->args[i].name]]) imp->error(first_token_pos, "Internal error: cannot find alignment "+to_string(type->alignments[type->args[i].name])+" of "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())+" within "+signature(types));
                    if(alignments[unpacks[i]] && !types.reverse_alignment_labels[alignments[unpacks[i]]]) imp->error(first_token_pos, "Internal error: cannot find alignment "+to_string(alignments[unpacks[i]])+" for "+unpacks[i].to_string()+" argument "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())+" within "+signature(types));
                    if(!alignments[unpacks[i]] || types.reverse_alignment_labels[alignments[unpacks[i]]]==type.get()) {}//REMINDER THAT THIS IS AN ERROR THAT POLUTES NEXT LOOP: alignments[unpacks[i]] = type->alignments[type->args[i].name];
                    else throw runtime_error(type->signature(types)+": nom "+pretty_var(type->name.to_string())+"__"+ pretty_var(type->args[i].name.to_string())
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
    if(!type && active_context.exists()) { // 
        vector<Variable> new_unpacks;
        if(internalTypes.vars[active_context]->_is_primitive) new_unpacks.push_back(active_context);
        else for(const Variable& pack : internalTypes.vars[active_context]->packs) new_unpacks.push_back(active_context+pack);
        for(const Variable& pack : unpacks) new_unpacks.push_back(pack);
        prev_errors = string(markdown_errors?"```rust\n":"")+previousType->name.to_string()+signature_like(types, unpacks)+(inherit_buffer.exists()?" followed by a buffer (unpacks at least one value)":"")+(markdown_errors?"\n```\n":"")+"\namong "+to_string(numberOfErrors)+" candidates"+(markdown_errors?"\n```rust":"")+overloading_errors+(markdown_errors?"\n```\n":"")+"\nand not found `on` context\n  ";
        overloading_errors = "";
        unpacks = new_unpacks;

        // COPY OF ABOVE CODE HERE TO RETRY
        for(const Type& type : previousType->get_options(types)) { // options encompases all overloads, in case of unions it may not have the base overloadv
            if(!type) imp->error(--p, "Internal error: obained a null option for "+previousType->name.to_string());
            try {
                //if(type->lazy_compile) throw runtime_error("Failed to resolve parametric type: "+type->signature());//+"\nParameters need to be determined by arguments");
                size_t type_args = type->not_primitive()?type->args.size():1;
                if(inherit_buffer.exists()) {
                    if(unpacks.size()>=type_args) throw runtime_error(type->signature(types));
                }
                else if(unpacks.size()!=type_args) throw runtime_error(type->signature(types));
                for(size_t i=0;i<unpacks.size();++i) {
                    auto arg_type = type->_is_primitive?type:type->args[i].type;
                    if(type->not_primitive() && arg_type->not_primitive()) throw runtime_error(type->signature(types)+": Cannot unpack abstract " + arg_type->signature(types) + " "+type->args[i].name.to_string());
                    if(!internalTypes.contains(unpacks[i])) throw runtime_error(type->signature(types)+": No runtype for "+pretty_var(unpacks[i].to_string()));
                    if(type->not_primitive() && arg_type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i].to_string())) 
                        throw runtime_error(type->signature(types));
                        //throw runtime_error(type->signature(types)+": Expects " + arg_type->name + " "+pretty_var(type->name+"__"+type->args[i].name)+" but got "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
                    if(type->not_primitive() && arg_type->_is_primitive && arg_type->name=="nom" && alignments[unpacks[i]]!=type->alignments[type->args[i].name]) {
                        if(type->alignments[type->args[i].name] && !types.reverse_alignment_labels[type->alignments[type->args[i].name]]) imp->error(first_token_pos, "Internal error: cannot find alignment "+to_string(type->alignments[type->args[i].name])+" of "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())+" within "+signature(types));
                        if(alignments[unpacks[i]] && !types.reverse_alignment_labels[alignments[unpacks[i]]]) imp->error(first_token_pos, "Internal error: cannot find alignment "+to_string(alignments[unpacks[i]])+" for "+unpacks[i].to_string()+" argument "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())+" within "+signature(types));
                        if(!alignments[unpacks[i]] || types.reverse_alignment_labels[alignments[unpacks[i]]]==type.get()) {}//REMINDER THAT THIS IS AN ERROR THAT POLUTES NEXT LOOP: alignments[unpacks[i]] = type->alignments[type->args[i].name];
                        else throw runtime_error(type->signature(types)+": nom "+pretty_var(type->name.to_string())+"__"+ pretty_var(type->args[i].name.to_string())
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
    if(!type && numberOfErrors) imp->error(first_token_pos, "Not found\n  "+prev_errors+string(markdown_errors?"```rust\n":"")+previousType->name.to_string()+signature_like(types, unpacks)+(inherit_buffer.exists()?" followed by a buffer (unpacks at least one value)":"")+(markdown_errors?"\n```\n":"")+"\namong "+to_string(numberOfErrors)+" candidates"+(markdown_errors?"\n```rust":"")+overloading_errors+(markdown_errors?"\n```\n":""));
    if(!type) imp->error(first_token_pos, "Not found runtype version: "+first_token.to_string()+" among "+to_string(previousType->options.size())+" candidates of "+previousType->signature(types));
    if(type->lazy_compile) imp->error(pos, "Internal error: Runtype has not been compiled");

    // repeat here to properly handle alignment (which we couldn't previously)
    for(size_t i=0;i<unpacks.size();++i) {
        auto arg_type = type->_is_primitive?type:type->args[i].type;
        if(type->not_primitive() && arg_type->not_primitive()) throw runtime_error(type->signature(types)+": Cannot unpack abstract " + arg_type->signature(types) + " "+type->args[i].name.to_string());
        if(!internalTypes.contains(unpacks[i])) throw runtime_error(type->signature(types)+": No runtype for "+pretty_var(unpacks[i].to_string()));
        if(type->not_primitive() && arg_type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i].to_string())) throw runtime_error(type->signature(types)+": Expects " + arg_type->name.to_string() + " "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())+" but got "+internalTypes.vars[unpacks[i]]->name.to_string()+" "+pretty_var(unpacks[i].to_string()));
        if(type->not_primitive() && arg_type->_is_primitive && arg_type->name=="nom" && alignments[unpacks[i]]!=type->alignments[type->args[i].name]) {
            if(type->alignments[type->args[i].name] && !types.reverse_alignment_labels[type->alignments[type->args[i].name]]) imp->error(pos, "Internal error: cannot find alignment "+to_string(type->alignments[type->args[i].name])+" of "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())+" within "+signature(types));
            if(alignments[unpacks[i]] && !types.reverse_alignment_labels[alignments[unpacks[i]]]) imp->error(pos, "Internal error: cannot find alignment "+to_string(alignments[unpacks[i]])+" for "+unpacks[i].to_string()+" argument "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())+" within "+signature(types));
            if(!alignments[unpacks[i]] || types.reverse_alignment_labels[alignments[unpacks[i]]]==type.get()) alignments[unpacks[i]] = type->alignments[type->args[i].name];
            else throw runtime_error(type->signature(types)+": nom "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())
                +" expects data from "+((!type->alignments[type->args[i].name] || !types.reverse_alignment_labels[type->alignments[type->args[i].name]])?"nothing":types.reverse_alignment_labels[type->alignments[type->args[i].name]]->signature(types))+" with id "+to_string(type->alignments[type->args[i].name])
                +" but got "+((alignments[unpacks[i]] && types.reverse_alignment_labels[alignments[unpacks[i]]])?types.reverse_alignment_labels[alignments[unpacks[i]]]->signature(types):"nothing")+" with id "+to_string(alignments[unpacks[i]]));
        }
        if(type->not_primitive() && (type->args[i].mut || type->mutables.find(type->args[i].name)!=type->mutables.end()) && !can_mutate(unpacks[i])) throw runtime_error(type->signature(types)+": Expects mutable " + arg_type->name.to_string() + " "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())+" but got immutable "+internalTypes.vars[unpacks[i]]->name.to_string()+" "+pretty_var(unpacks[i].to_string()));
           
    }

    // TODO: reinstate this but improve inference
    //if(numberOfFound>1) imp->error(first_token_pos, "Ambiguous use of ["+to_string(unpacks.size())+"] structural arguments - they match "+to_string(numberOfFound)+" candidates"+(markdown_errors?"\n```rust":"")+multipleFound+(markdown_errors?"\n```\n":""));
    if(inherit_buffer.exists()) { // unpack buffer
        static const Variable token_err1 = Variable(":\nprintf(\"Runtime error: buffer is empty\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n");
        static const Variable token_err2 = Variable(":\nprintf(\"Runtime error: buffer element has the wrong type\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n");
        Variable arg = inherit_buffer;
        int remaining = (int)(type->args.size()-unpacks.size());
        if(type->_is_primitive) remaining++;
        Variable fail_var = create_temp();
        Variable fail_var_type = create_temp();
        if(remaining==1) implementation +=Code(token_if,arg+Variable("__size"),COMP_LE_VAR,arg+Variable("__offset"), token_goto, fail_var, SEMICOLON_VAR);
        else implementation +=Code(token_if,arg+Variable("__size"), COMP_LT_VAR, arg+Variable("__offset"),Variable("+"+to_string(remaining)+")goto"), fail_var, SEMICOLON_VAR);
        errors = errors+Code(fail_var, token_err1, fail_var_type, token_err2);
        add_preample("#include <stdio.h>");
        string tmp = create_temp();
        for(int i=0;i<remaining;++i) {
            Type desiredType = type->_is_primitive?type:type->args[unpacks.size()].type;// don't add i because we push back the element
            bool typecheck = !buffer_primitive_associations[inherit_buffer];//desiredType!=buffer_primitive_associations[inherit_buffer];
            if(!typecheck && desiredType!=buffer_primitive_associations[inherit_buffer]) imp->error(--p, "Buffer contains only "+buffer_primitive_associations[inherit_buffer]->name.to_string()+" primitives but tried to extract "+desiredType->name.to_string());
            Variable element = "__"+tmp+"__"+to_string(i);
            if(typecheck) {
                Variable trelement = element+string("t");
                internalTypes.vars[trelement] = types.vars[U64_VAR];
                implementation +=Code(trelement+Variable(" = ((u64*)"), arg+Variable("__typetag"), Variable(")[("+ to_string(i)+"+"), arg+Variable("__offset"), Variable(")/16];\n"));
                Code pos = Code(Variable("((("+ to_string(i)+"+"), arg+Variable("__offset"), Variable(")%16)*4)"));
                implementation +=Code(Variable("if((("), trelement, Variable(">>"))+pos+Code(Variable(")& 0xF)!=__IS_"+desiredType->name.to_string()+")goto"), fail_var_type, SEMICOLON_VAR);
            }
            implementation +=Code(Variable("std::memcpy(&"), element, Variable(",(unsigned char*)"), arg+Variable("__contents"), Variable("+sizeof(u64)*("+ to_string(i)+"+"), arg+Variable("__offset"), Variable("), sizeof("), element, Variable("));\n"));
            if(desiredType) internalTypes.vars[element] = desiredType;
            unpacks.push_back(element);
        }
        implementation +=Code(arg+Variable("__offset"), Variable("+= "+to_string(remaining)+";\n"));
    }

    for(const Variable& pack : type->packs) type->coallesce_finals(pack);
    auto transfer_finals = type->finals;
    unordered_map<Variable, Code> transferring;
    for(const Variable& pack : type->packs) if(type->finals[pack].exists()) {
        type->coallesce_finals(pack);
        finals[var+pack] = finals[var+pack] + type->rebase(type->finals[pack], var);
        transferring[var+pack] = finals[var+pack];
        transfer_finals[pack] = Code();
    }
    for(const auto& arg : type->args) if(arg.mut && type->finals[arg.name].exists()) {
        type->coallesce_finals(arg.name);
        finals[var+arg.name] = finals[var+arg.name]+type->rebase(type->finals[arg.name], var);
        transferring[var+arg.name] = finals[var+arg.name];
        transfer_finals[arg.name] = Code();
    }
    for(const auto& it : type->current_renaming) current_renaming[var+it.first] = var+it.second;

    // prevent memory leaks in loops
    if(uplifiting_is_loop.size() && uplifiting_is_loop.back() && type->finals.size()) {
        string desc("");
        for(const auto& it : transferring) if(it.first.exists() && it.second.exists()) desc += "\n- "+pretty_var(type->name.to_string()+"__"+it.first.to_string());
        if(desc.size()) imp->error(--p, "Loop cannot call: "+type->signature(types)+"\nThis could leak the following resources:"+desc);
    }

    for(const Variable& mut : type->mutables) mutables.insert(var+mut);
    mutables.insert(var); // MAKE ALL CALL OUTCOMES MUTABLE BY DEFAULT

    // make actual call
    if(type->is_service) {
        // vardecl += "errcode "+var+"__err = 0;\n";
        Code impl = Code(var+ERR_VAR,ASSIGN_VAR,type->name,LPAR_VAR);
        internalTypes.vars[var+ERR_VAR] = types.vars[ERRCODE_VAR];
        internalTypes.vars[var] = type;
        for(const Variable& pack : type->packs) if(type->alignments[pack]) alignments[var+pack] = type->alignments[pack];
        bool toadd = false;
        for(size_t i=1;i<type->packs.size();++i) { // first service output is the error code, which we return instead of parsing by reference
            const Variable& ret = type->packs[i];
            size_t fp = first_token_pos;
            Variable arg = var+ret;
            assign_variable(type->internalTypes.vars[ret], arg, ZERO_VAR, imp, fp);
            if(toadd) impl = impl+Code(COMMA_VAR);
            impl += Code(REF_VAR,arg);
            mutables.insert(arg);
            toadd = true;
            //type->coallesce_finals(ret);
            //finals[var+"__"+ret] += type->rebase(type->finals[ret], var);
            if(type->internalTypes.vars[ret]->name==BUFFER_VAR) buffer_primitive_associations[arg] = type->buffer_primitive_associations[ret];
        }
        for(const auto& it : type->internalTypes.vars) internalTypes.vars[var+it.first] = it.second;
        for(size_t i=0;i<unpacks.size();++i) {
            if(toadd) impl = impl+Code(COMMA_VAR);
            toadd = true;
            if(type->args[i].mut) {
                impl += Code(REF_VAR, unpacks[i]);
                const Variable &ret = unpacks[i];
                type->coallesce_finals(type->args[i].name);
                finals[unpacks[i]] = finals[unpacks[i]]+type->rename_var(type->finals[type->args[i].name], type->args[i].name, unpacks[i]);
                if(type->internalTypes.vars[ret]->name==BUFFER_VAR) buffer_primitive_associations[unpacks[i]] = type->buffer_primitive_associations[type->args[i].name];
            }
            else impl += Code(unpacks[i]);
        }
        impl = impl+Code(Variable(");\n"));
        implementation +=impl;
        internalTypes.vars[var] = type->alias_for.exists()?type->internalTypes.vars[type->alias_for]:type;
        if(internalTypes.vars[var]->name==BUFFER_VAR) buffer_primitive_associations[var] = type->buffer_primitive_associations[type->alias_for];
        return next_var(imp, p, var, types);
    }
    if(type->_is_primitive) {
        if(unpacks.size()!=1) imp->error(--p, "Primitive types only accept one argument");
        size_t fp = first_token_pos;
        assign_variable(type, var, unpacks[0], imp, fp);
        return next_var(imp, p, var, types);
    }
    for(const auto& it : type->alignments) if(it.second) alignments[var+it.first] = it.second; 
    Code immediate_finals;
    for(size_t i=0;i<unpacks.size();++i) {
        size_t fp = first_token_pos;
        assign_variable(type->args[i].type, var+type->args[i].name, unpacks[i], imp, fp);
        if(type->args[i].mut) {
            immediate_finals = immediate_finals+Code(unpacks[i],ASSIGN_VAR,var+type->args[i].name,SEMICOLON_VAR);
            current_renaming[unpacks[i]] = var.to_string()+"__"+type->args[i].name.to_string();
            current_renaming[var+type->args[i].name] = unpacks[i];
            current_renaming[unpacks[i]] = var+type->args[i].name;
            buffer_primitive_associations[unpacks[i]] = type->buffer_primitive_associations[var+type->args[i].name];
        }
    }
    for(const auto& it : type->internalTypes.vars) internalTypes.vars[var+it.first] = it.second;
    for(const auto& final : transfer_finals) immediate_finals = immediate_finals+type->rebase(final.second, var);
    internalTypes.vars[var] = type->alias_for.exists()?type->internalTypes.vars[type->alias_for]:type;
    implementation +=type->rebase(type->implementation, var)+immediate_finals;
    for(const string& pre : type->preample) add_preample(pre);

    //for(const auto& final : type->finals) finals[var+"__"+final.first] += type->rebase(final.second, var); // splt into immediate and delayed finals
    //finals = type->rebase(type->finals, var)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
    errors = errors+type->rebase(type->errors, var);
    for(const auto& it : type->current_renaming) current_renaming[var+it.first] = var+it.second;
    for(const auto& it : type->internalTypes.vars) if(it.second) { // TODO: remove this if (currently it guards against some leftover labels)
        if(!it.second) imp->error(--p, type->name.to_string()+"."+pretty_var(it.first.to_string())+" is undefined");
        internalTypes.vars[var+it.first] = it.second;
        if(it.second->name==BUFFER_VAR) buffer_primitive_associations[var+it.first] = type->buffer_primitive_associations[it.first];
    }
    //finals[""] += immediate_finals; // TODO maybe it's a good idea to have some deallocations at the end of runtype implementations
    if(internalTypes.contains(var) && internalTypes.vars[var]->name==BUFFER_VAR) buffer_primitive_associations[var] = type->buffer_primitive_associations[type->alias_for];
    if(type->packs.size()==1) return next_var(imp, p, var+type->packs[0], types);
    return next_var(imp, p, var, types);
}


Variable Def::parse_expression_no_par(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry) {
    
    static const Variable token_if = Variable("if(");
    static const Variable token_ifnot = Variable("if(!");
    static const Variable token_goto = Variable(")goto");
    
    size_t first_token_pos = p-1;
    if(first_token==DOT_VAR || first_token==CURRY_VAR|| first_token=="[" || first_token=="]" || first_token=="{" || first_token=="}" || first_token==";"|| first_token=="&") imp->error(p-1, "Unexpected symbol\nThe previous expression already ended.");

    if(first_token==IF_VAR) {
        Variable temp = create_temp();
        Variable finally_var = temp+IF_VAR;
        Variable closeif_var = temp+FI_VAR;
        uplifting_targets.push_back(finally_var);
        if(uplifiting_is_loop.size()) uplifiting_is_loop.push_back(uplifiting_is_loop.back());
        else uplifiting_is_loop.push_back(false);
        internalTypes.vars[finally_var] = types.vars[LABEL_VAR];
        internalTypes.vars[closeif_var] = types.vars[LABEL_VAR];
        string next = imp->at(p++);
        Variable var = parse_expression(imp, p, next, types, curry);
        if(!internalTypes.contains(var)) imp->error(--p, "Expression did not evaluate to anything");
        if(internalTypes.vars.find(var)->second!=types.vars[BOOL_VAR]) imp->error(--p, "If expects bool condition but got "+internalTypes.vars.find(var)->second->name.to_string()+" "+pretty_var(var.to_string()));
        implementation +=Code(token_ifnot,var,token_goto,closeif_var,SEMICOLON_VAR);
        parse(imp, p, types, false);
        p++; // offset p-- after parse_return above
        Variable else_var = EMPTY_VAR;
        Variable rfinally_var = finally_var+Variable("r");
        if(p<imp->size()-1 && imp->at(p)=="else") {
            p++;
            else_var = temp+LE_VAR;
            Variable relse_var = else_var+Variable("r");
            internalTypes.vars[else_var] = types.vars[LABEL_VAR];
            Variable else_skip = temp+EL_VAR;
            internalTypes.vars[else_skip] = types.vars[LABEL_VAR];
            uplifting_targets.pop_back();
            uplifting_targets.push_back(else_var);
            implementation +=Code(finally_var,COLON_VAR,Variable("goto"), else_skip, SEMICOLON_VAR, closeif_var, COLON_VAR);
            parse(imp, p, types, false);
            implementation +=Code(else_var,COLON_VAR);
            p++; // offset p-- after parse_return above
            if(internalTypes.contains(relse_var) && !internalTypes.contains(rfinally_var)) imp->error(first_token_pos, "There was a non-empty return "+internalTypes.vars[relse_var]->name.to_string()+" `else` but no such value from `if`");
            if(!internalTypes.contains(relse_var) && internalTypes.contains(rfinally_var)) imp->error(first_token_pos, "There was a non-empty return "+internalTypes.vars[rfinally_var]->name.to_string()+" `if` but no such value from `else` ");
            if(internalTypes.contains(relse_var) && internalTypes.contains(rfinally_var)) {
                if(internalTypes.vars[rfinally_var]!=internalTypes.vars[relse_var]) imp->error(first_token_pos, "There were mismatching return "+internalTypes.vars[rfinally_var]->name.to_string()+" `if` and "+internalTypes.vars[relse_var]->name.to_string()+" `else`");
                assign_variable(internalTypes.vars[rfinally_var],rfinally_var, relse_var, imp, first_token_pos, false, false);
            }
            implementation +=Code(else_skip,COLON_VAR);
        }
        else implementation +=Code(finally_var,COLON_VAR,closeif_var,COLON_VAR);
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        if(internalTypes.contains(rfinally_var)) {
            if(else_var.exists()==0) imp->error(first_token_pos, "There was a non-empty return "+internalTypes.vars[rfinally_var]->name.to_string()+" `if` but no `else` statement for the alternative"); 
            return rfinally_var;
        }
        return EMPTY_VAR;
    }
    if(first_token==WHILE_VAR) {
        Variable temp = create_temp();
        Variable finally_var = temp+WHILE_VAR;
        uplifting_targets.push_back(finally_var);
        uplifiting_is_loop.push_back(true);
        Variable start_var = temp+LOOP_VAR;
        internalTypes.vars[start_var] = types.vars[LABEL_VAR];
        internalTypes.vars[finally_var] = types.vars[LABEL_VAR];
        implementation +=Code(start_var,COLON_VAR);
        Variable next = imp->at(p++);
        Variable var = parse_expression(imp, p, next, types, curry);
        if(!internalTypes.contains(var)) imp->error(--p, "Expression did not evaluate to anything");
        if(internalTypes.vars.find(var)->second!=types.vars[BOOL_VAR]) imp->error(--p, "If expects bool condition but got "+internalTypes.vars.find(var)->second->name.to_string()+" "+pretty_var(var.to_string()));
        implementation +=Code(token_ifnot,var,token_goto,finally_var,SEMICOLON_VAR);
        parse(imp, p, types, false);
        p++; // offset p-- after parse_return above
        implementation +=Code(Variable("goto"),start_var,SEMICOLON_VAR,finally_var,COLON_VAR);
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        return EMPTY_VAR;
    }
    if(first_token=="on") {
        if(curry.exists()) imp->error(p, "Cannot curry onto `on`");
        if(active_context.exists()) imp->error(p, "There is already an active context in this implementation\nEnd its code block to enter a new context with `on`.");
        string next = imp->at(p++);
        active_context = parse_expression(imp,p,next,types,curry);
        if(!active_context.exists() || !internalTypes.contains(active_context)) imp->error(--p, "Expression does not evaluate to a variable to use as `on` context");
        Variable temp = create_temp();
        Variable finally_var = temp+Variable("on");
        internalTypes.vars[finally_var] = types.vars[LABEL_VAR];
        //int on_start = p-1;
        uplifting_targets.push_back(finally_var);
        if(uplifiting_is_loop.size()) uplifiting_is_loop.push_back(uplifiting_is_loop.back());
        else uplifiting_is_loop.push_back(false);
        parse(imp, p, types, false);
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        p++;
        Variable var = finally_var+Variable("r");
        if(!internalTypes.contains(var)) var = EMPTY_VAR;
        implementation +=Code(finally_var,COLON_VAR);
        active_context = EMPTY_VAR;
        return var;
    }
    if(first_token=="with") { // TODO: this implementation does not account for nesting
        Variable temp = create_temp();
        Variable finally_var = temp+Variable("with");
        size_t numberOfCandidates = 0;
        string overloading_errors = "";
        string competing = "";
        int with_start = p-1;
        uplifting_targets.push_back(finally_var);
        if(uplifiting_is_loop.size()) uplifiting_is_loop.push_back(uplifiting_is_loop.back());
        else uplifiting_is_loop.push_back(false);
        internalTypes.vars[finally_var] = types.vars[LABEL_VAR];
        string next;
        try {
            if(curry.exists()) imp->error(--p, "Cannot have a curry onto `with`.");
            parse(imp, p, types, false);
            p++;
            next = imp->at(p++);
            numberOfCandidates++;
            implementation +=Code(Variable("goto"),finally_var,SEMICOLON_VAR);
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
                    implementation +=Code(Variable("goto"), finally_var, SEMICOLON_VAR);
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

        implementation +=Code(finally_var,COLON_VAR);
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        return EMPTY_VAR;
    }

    if(is_primitive(first_token.to_string())) {
        string vartype = type_primitive(first_token.to_string());
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
        implementation += Code(var,ASSIGN_VAR,first_token.to_string(),SEMICOLON_VAR);
        //mutables.insert(var);
        return next_var(imp, p, var, types);
    }
    if(first_token == "len" && curry.exists() && internalTypes.contains(curry) && internalTypes.vars[curry]->name=="buffer") {
        Variable var = create_temp();
        implementation +=Code(var,ASSIGN_VAR, curry+Variable("__size"), MINUS_VAR, curry+Variable("__offset"), Variable(";\n")); 
        internalTypes.vars[var] = types.vars[U64_VAR];
        return next_var(imp, p, var, types);
    }
    if(first_token == "put" && curry.exists() && internalTypes.contains(curry) && internalTypes.vars[curry]->name=="buffer") {
        static const Variable token_err1 = Variable(":\nprintf(\"Runtime error: buffer is empty\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n");
        static const Variable token_err2 = Variable(":\nprintf(\"Runtime error: buffer element would replace a different type\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n");
        Variable arg = curry;
        if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
        Variable inherit_buffer = EMPTY_VAR;
        vector<Variable> unpacks = gather_tuple(imp, p, types, inherit_buffer, EMPTY_VAR);
        if(inherit_buffer.exists()) imp->error(--p, "Cannot unpack from a buffer to put elements in a buffer");
        int remaining = unpacks.size();
        if(!remaining) imp->error(--p, "Need to set at least one element to the buffer");
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        Variable fail_var = create_temp();
        Variable fail_var_type = create_temp();
        if(remaining==1) implementation +=Code(token_if, arg+Variable("__size"), COMP_LE_VAR, arg+Variable("__offset"), token_goto, fail_var, SEMICOLON_VAR);
        else implementation +=Code(token_if, arg+Variable("__size"), COMP_LT_VAR, arg+Variable("__offset"),Variable("+"+to_string(remaining)+")goto"),fail_var,SEMICOLON_VAR);
        errors = errors + Code(fail_var, token_err1, fail_var_type, token_err2);
        add_preample("#include <stdio.h>");
        string tmp = create_temp();
        for(int i=0;i<remaining;++i) {
            if(!internalTypes.contains(unpacks[i])) imp->error(p-2, "Non-existing variable: "+pretty_var(unpacks[i].to_string()));
            Type desiredType = internalTypes.vars[unpacks[i]];
            bool typecheck = !buffer_primitive_associations[arg];
            if(!typecheck && desiredType!=buffer_primitive_associations[arg]) imp->error(p-2, "Buffer contains only "+buffer_primitive_associations[arg]->name.to_string()+" primitives but tried to replace one with "+desiredType->name.to_string());
            Variable element = "__"+tmp+"__"+to_string(i);
            Variable telement = element + string("t");
            if(typecheck) {
                internalTypes.vars[telement] = types.vars[U64_VAR];
                implementation +=Code(telement, Variable(" = ((u64*)"),arg+Variable("__typetag"), Variable(")[("+ to_string(i)+"+"),arg+Variable("__offset"), Variable(")/16];\n"));
                Code pos = Code(Variable("((("+ to_string(i)+"+"), arg+Variable("__offset"), Variable(")%16)*4)"));
                implementation +=Code(Variable("if((("), telement, Variable(">>"))+pos+Code(Variable(")& 0xF)!=__IS_"+desiredType->name.to_string()+")goto"), fail_var_type, SEMICOLON_VAR);
            }
            //if(desiredType->name=="i64" || desiredType->name=="f64" || desiredType->name=="ptr" || desiredType->name=="cstr") implementation += "((u64*)" + arg + "____contents)["+ to_string(i)+"+"+arg+"____offset] = std::bit_cast<u64>("+unpacks[i]+");\n";
            implementation +=Code(Variable("std::memcpy((unsigned char*)"), arg+Variable("__contents"), Variable("+sizeof(u64)*("+ to_string(i)+"+"), arg+Variable("__offset"), Variable("), &"), unpacks[i], Variable(", sizeof("), unpacks[i], Variable("));\n"));
        }
        implementation +=Code(arg+Variable("__offset"), Variable("+="+to_string(remaining)+";\n"));
        return next_var(imp, p, arg, types);
    }
    if(internalTypes.contains(first_token)) {
        if(curry.exists()) imp->error(p, "Expecting runtype but got variable: "+first_token.to_string());
        return next_var(imp, p, first_token, types); //ASSIGNMENT TO ALREADY EXISTING VARIABLE
    }
    if(first_token==BUFFER_VAR) {
        Variable var = create_temp();
        add_preample("#include<cstdlib>");
        Variable inherit_buffer = EMPTY_VAR;
        Variable prototype_buffer = EMPTY_VAR;
        vector<Variable> unpacks;
        if(imp->at(p)=="(") {
            if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
            if(curry.exists() && !internalTypes.contains(curry)) imp->error(--p, "Non-existing curry: "+pretty_var(curry.to_string()));
            if(curry.exists() && internalTypes.vars[curry]==types.vars[BUFFER_VAR]) {prototype_buffer = curry;curry=EMPTY_VAR;}
            unpacks = gather_tuple(imp, p, types, inherit_buffer, curry);
            if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        }
        else {
            if(!curry.exists()) imp->error(p, "Expecting opening parenthesis when there is no curry");
            if(!internalTypes.contains(curry)) imp->error(--p, "Non-existing curry: "+pretty_var(curry.to_string()));
            if(internalTypes.vars[curry]==types.vars[BUFFER_VAR]) {prototype_buffer=curry;curry=EMPTY_VAR;}
            else if(internalTypes.vars[curry]->_is_primitive) unpacks.push_back(curry);
            else if(internalTypes.vars[curry]->is_service) {
                Variable fail_var = create_temp();
                implementation += Code(token_if,var+ERR_VAR,Variable(")goto"),fail_var,SEMICOLON_VAR);
                errors += Code(fail_var, Variable(":\nprintf(\"Runtime error from "), internalTypes.vars[curry]->name, curry, Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n"));
                add_preample("#include <stdio.h>");
                for(size_t i=1;i<internalTypes.vars[curry]->packs.size();++i) unpacks.push_back(curry+internalTypes.vars[curry]->packs[i]);
            }
            else for(const Variable& pack : internalTypes.vars[curry]->packs) unpacks.push_back(curry+pack);
        }
        implementation +=Code(token_if, var+Variable("__size"), MINUS_VAR, var+Variable("__offset"), Variable(") free("), var+Variable("__contents"), Variable(");\n"));
        implementation +=Code(var+Variable("__size"), "="+to_string(unpacks.size()));
        if(inherit_buffer.exists()) implementation +=Code(PLUS_VAR, inherit_buffer+Variable("__size"));
        if(prototype_buffer.exists()) implementation +=Code(PLUS_VAR, prototype_buffer+Variable("__size"));
        implementation +=Code(SEMICOLON_VAR, var+Variable("__offset"), ASSIGN_VAR, ZERO_VAR, SEMICOLON_VAR);
        implementation +=Code(var+Variable("__contents"), Variable("=malloc(sizeof(i64)*"), var+Variable("__size"), Variable(");\n"));
        implementation +=Code(var+Variable("__typetag"),Variable("=calloc("), var+Variable("__size"), Variable("/16+1, sizeof(u64));\n"));
        if(unpacks.size() && internalTypes.contains(unpacks[0])) buffer_primitive_associations[var] = internalTypes.vars[unpacks[0]];
        else if(prototype_buffer.exists()) buffer_primitive_associations[var] = buffer_primitive_associations[prototype_buffer];
        else if(inherit_buffer.exists()) buffer_primitive_associations[var] = buffer_primitive_associations[inherit_buffer];

        if(prototype_buffer.exists() && buffer_primitive_associations[prototype_buffer]!=buffer_primitive_associations[var]) buffer_primitive_associations[var] = nullptr;
        if(inherit_buffer.exists() && buffer_primitive_associations[inherit_buffer]!=buffer_primitive_associations[var]) buffer_primitive_associations[var] = nullptr;

        Code offset = Code(Variable(to_string(unpacks.size())));
        if (prototype_buffer.exists()) {
            implementation += Code(Variable("std::memcpy((unsigned char*)"), var+Variable("__contents"), COMMA_VAR, Variable("unsigned char*)"), prototype_buffer+Variable("__contents"), Variable(", sizeof(u64)*"),prototype_buffer+Variable("__size)"), SEMICOLON_VAR);
            implementation += Code(Variable("memcpy((unsigned char*)"), var+Variable("__typetag"), COMMA_VAR, Variable("(unsigned char*)"), prototype_buffer+Variable("__typetag"), Variable(", sizeof(u64)*("), prototype_buffer+Variable("__size"), Variable("/16+1));\n"));
            offset += Code(PLUS_VAR, prototype_buffer+Variable("__size"));

            for(size_t i = 0; i < unpacks.size(); ++i) {
            if(buffer_primitive_associations[var]!=internalTypes.vars[unpacks[i]]) buffer_primitive_associations[var] = nullptr;
            //if(buffer_primitive_associations[var]) 
            // for now it's mandatory to set the type because we might lose the primitive association in the future - the optimizer may just remove if if unused though
            implementation += Code(Variable("((u64*)"), var+Variable("__typetag"), Variable(")[("+to_string(i)+"+"), prototype_buffer+Variable("__size"), Variable(")/16] |= ((u64)__IS_"+internalTypes.vars[unpacks[i]]->name.to_string()+")<<("+to_string(i)+"+"), prototype_buffer+Variable("__size"), Variable(")%16)*4;\n"));
            implementation += Code(Variable("std::memcpy((unsigned char*)"), var+Variable("__contents"), Variable("+sizeof(u64)*("+to_string(i)+"+"),prototype_buffer+Variable("__size"), Variable("), &"), unpacks[i], Variable(",sizeof("), unpacks[i], Variable("));\n"));
        }
        }
        else for(size_t i = 0; i < unpacks.size(); ++i) {
            if(buffer_primitive_associations[var]!=internalTypes.vars[unpacks[i]]) buffer_primitive_associations[var] = nullptr;
            //if(buffer_primitive_associations[var]) 
            // for now it's mandatory to set the type because we might lose the primitive association in the future - the optimizer may just remove if if unused though
            implementation += Code(Variable("((u64*)"), var+Variable("__typetag"), Variable(")["+to_string(i/16)+"] |= ((u64)__IS_"+internalTypes.vars[unpacks[i]]->name.to_string()+")<<"+to_string((i%16)*4)+";\n"));
            implementation += Code(Variable("std::memcpy((unsigned char*)"), var+Variable("__contents"), Variable("+sizeof(u64) * " + to_string(i) + ", &"), unpacks[i], COMMA_VAR, Variable("sizeof("),unpacks[i], Variable("));\n"));
        }
        if(inherit_buffer.exists()) {
            implementation += Code(Variable("std::memcpy((unsigned char*)"), var+Variable("__contents"), Variable("+sizeof(u64)*("))+offset+Code(Variable("),  (unsigned char*)")+inherit_buffer+Variable("__contents"), Variable(", sizeof(u64)*"),inherit_buffer+Variable("__size"), Variable(");\n"));
            implementation += Code(Variable("for(u64 i=0;i<"), inherit_buffer+Variable("__size"), Variable("; ++i) ((u64*)"), var+Variable("__typetag"), Variable(")[(i+"))+offset+Code(Variable(")/16] |=((u64*)"), prototype_buffer+Variable("__typetag"), Variable(")[(i+"))+offset+Code(Variable(")/16]<<(((i+"))+offset+Code(Variable(")%16)*4);\n"));
            offset += Code(PLUS_VAR, prototype_buffer+Variable("__size"));
        }


        internalTypes.vars[var] = types.vars.find(first_token)->second;
        internalTypes.vars[var+Variable("__size")] = types.vars[U64_VAR];
        internalTypes.vars[var+Variable("__offset")] = types.vars[U64_VAR];
        internalTypes.vars[var+Variable("__contents")] = types.vars[PTR_VAR];
        internalTypes.vars[var+Variable("__typetag")] = types.vars[PTR_VAR];
        finals[var+Variable("__contents")] += Code(token_if, var+Variable("__contents"), Variable(")free("), var+Variable("__contents"),Variable(");\n"), var+Variable("__contents"), ASSIGN_VAR, ZERO_VAR, SEMICOLON_VAR);
        finals[var+Variable("__typetag")] += Code(token_if, var+Variable("__typetag"), Variable(")free("), var+Variable("__typetag"),Variable(");\n"), var+Variable("__typetag"), ASSIGN_VAR, ZERO_VAR, SEMICOLON_VAR);
        return next_var(imp, p, var, types);
    }
    if(types.contains(first_token)) {
        auto type = types.vars.find(first_token)->second;
        Variable inherit_buffer = EMPTY_VAR;
        vector<Variable> unpacks;
        if(imp->at(p)=="__consume") {
            if(!curry.exists()) imp->error(p-2, "Unexpected usage of operator\nThere is no left-hand-side");
            if(!internalTypes.contains(curry)) imp->error(first_token_pos-2, "Not found: "+pretty_var(curry.to_string())+recommend_runtype(types, curry));
            else if(internalTypes.vars.find(curry)->second==types.vars[BUFFER_VAR]) imp->error(p-2, "Operator does not accept buffer as the first input");
            else if(internalTypes.vars.find(curry)->second->not_primitive()) {
                for(const Variable& pack : internalTypes.vars.find(curry)->second->packs) unpacks.push_back(curry+pack);
            }
            else unpacks.push_back(curry);
            p++;
            string next = imp->at(p++);
            Variable rhs = parse_expression(imp, p, next, types);
            if(!internalTypes.contains(rhs)) imp->error(--p, "Failed to parse the right-hand-side of "+first_token.to_string());
            const auto& rhsType = internalTypes.vars.find(rhs)->second;
            if(rhsType->name==BUFFER_VAR) imp->error(--p, "Cannot involve a buffer in operation "+first_token.to_string());
            if(rhsType->_is_primitive) unpacks.push_back(rhs);
            else if(type->is_service) {
                Variable fail_var = create_temp();
                static const Variable token_err1 = Variable(":\nprintf(\"Runtime error from ");
                static const Variable token_err2 = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
                implementation +=Code(token_if, rhs+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
                errors = errors+Code(fail_var, token_err1, rhsType->name, rhs, token_err2);
                add_preample("#include <stdio.h>");
                for(size_t i=1;i<rhsType->packs.size();++i) unpacks.push_back(rhs+rhsType->packs[i]);
            }
            else for(const Variable& pack : rhsType->packs) unpacks.push_back(rhs+pack);
        }
        else if(imp->at(p)!="(" && curry.exists()) {
            if(!internalTypes.contains(curry)) imp->error(first_token_pos-2, "Not found: "+pretty_var(curry.to_string())+recommend_runtype(types, curry));
            else if(internalTypes.vars.find(curry)->second==types.vars[BUFFER_VAR]) inherit_buffer = curry;
            else if(internalTypes.vars.find(curry)->second->not_primitive()) {
                for(const Variable& pack : internalTypes.vars.find(curry)->second->packs) unpacks.push_back(curry.to_string()+"__"+pack.to_string());
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
                Variable var = create_temp();
                if(p<imp->size()-1 && imp->at(p+1)=="&") mutables.insert(var);
                assign_variable(type->args[i].type, var+type->args[i].name, ZERO_VAR, imp, first_token_pos, true);
                type_trackers.insert(var);
                unpacks.push_back(var+type->args[i].name);
            }
            else {
                string var = create_temp();
                if(p<imp->size()-1 && imp->at(p+1)=="&") mutables.insert(var);
                assign_variable(type, var, ZERO_VAR, imp, first_token_pos, true);
                type_trackers.insert(var);
                unpacks.push_back(var);
            }
        }
        else if(((p<imp->size()-1 && imp->at(p)!="(" && (imp->at(p+1)==")" || imp->at(p+1)==",")) || (p<imp->size()-2 && imp->at(p)=="&" && imp->at(p+1)!="(" && (imp->at(p+2)==")" || imp->at(p+2)==",")))){
            Variable var = imp->at(p++);
            if(var=="&") {
                var = imp->at(p++);
                mutables.insert(var);
            }
            if(internalTypes.contains(var)) imp->error(--p, "Cannot redeclare local variable "+internalTypes.vars[var]->name.to_string()+" "+pretty_var(var.to_string()));
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
                internalTypes.vars[var+type->args[i].name] = type->args[i].type;
                unpacks.push_back(var+type->args[i].name);
                
            }
            else unpacks.push_back(var);
            if(type->args.size() && type->args[0].type->name=="nom") alignments[var+type->args[0].name] = types.alignment_labels[type.get()];
            internalTypes.vars[var] = type;
            return var;
        }
        else if(imp->at(p)!="(") {
            Variable var = create_temp();
            internalTypes.vars[var] = type;
            type_trackers.insert(var);
            if(p<imp->size()-1 && imp->at(p+1)=="&") mutables.insert(var);
            for(const Variable& pack : type->packs) assign_variable(type->internalTypes.vars[pack], var+pack, ZERO_VAR, imp, first_token_pos);
            if(type->args.size() && type->args[0].type->name=="nom") alignments[var+type->args[0].name] = types.alignment_labels[type.get()];
            return next_var(imp, p, var, types);
        }
        else {
            if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
            unpacks = gather_tuple(imp, p, types, inherit_buffer, curry);
            if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        }

        return call_type(imp, p, type, unpacks, first_token_pos, first_token, inherit_buffer, types);
    }
    if(curry.exists() || (p<imp->size() && (imp->at(p)=="(" || imp->at(p)=="__consume"))) imp->error(--p, "Missing runtype: "+first_token.to_string()+recommend_runtype(types, first_token));
    return next_var(imp, p, first_token, types);
}



