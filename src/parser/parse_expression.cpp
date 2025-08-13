#include "../def.h"

Variable Def::parse_expression(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, const Variable& curry) {
    if(first_token=="(") {
        Variable ret = parse_expression(imp, p, imp->at(p++), types, curry);
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        return next_var(imp, p, ret, types);
    }
    return parse_expression_no_par(imp, p, first_token, types, curry);
}


Variable Def::call_type(const shared_ptr<Import>& imp, size_t& p, Type& type, vector<Variable>& unpacks, const size_t first_token_pos, const Variable& first_token, Types& types) {
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
    for(size_t i=0;i<unpacks.size();++i) {
        if(!internalTypes.contains(unpacks[i])) imp->error(p-1, "Not found: "+pretty_var(unpacks[i].to_string())+recommend_variable(types, unpacks[i]));
        if(released[unpacks[i]]) imp->error(p-1, "Already released (this includes implicit releases): "+pretty_var(unpacks[i].to_string())+recommend_variable(types, unpacks[i]));
    }
    type->number_of_calls++;
    size_t max_arg_progress = 0;
    size_t arg_progress = 0;
    for(const Type& type : previousType->get_options(types)) { // options encompases all overloads, in case of unions it may not have the base overloadv
        if(!type) imp->error(--p, "Internal error: obained a null option for "+previousType->name.to_string());
        if(type->unresolved_options) continue;
        try {
            //if(type->lazy_compile) throw runtime_error("Failed to resolve parametric type: "+type->signature());//+"\nParameters need to be determined by arguments");
            size_t type_args = type->not_primitive()?type->args.size():1;
            if(unpacks.size()!=type_args) throw runtime_error(type->signature(types));
            for(size_t i=0;i<unpacks.size();++i) {
                arg_progress = i;
                auto arg_type = type->_is_primitive?type:type->args[i].type;
                if(type->not_primitive() && arg_type->not_primitive()) throw runtime_error(type->signature(types)+": Cannot unpack abstract " + arg_type->signature(types) + " "+type->args[i].name.to_string());
                if(!internalTypes.contains(unpacks[i])) throw runtime_error(type->signature(types)+": No runtype for "+pretty_var(unpacks[i].to_string()));
                if(type->not_primitive() && arg_type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i].to_string())) 
                    throw runtime_error(type->signature(types));
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
            }
            if(type->choice_power>highest_choice_power) {
                highest_choice_power = type->choice_power;
                numberOfFound = 0;
                multipleFound = "";
            }
            if(type->choice_power<highest_choice_power) continue;
            successfullType = type;
            if(markdown_errors) multipleFound += "\n";
            else multipleFound += "\n- ";
            multipleFound += type->signature(types);
            numberOfFound++;
        }
        catch (const std::runtime_error& e) {
            if(arg_progress>max_arg_progress) {
                overloading_errors = "";
                numberOfErrors = 0;
            }
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
        prev_errors = string(markdown_errors?"```rust\n":"")+previousType->name.to_string()+signature_like(types, unpacks)+(markdown_errors?"\n```\n":"")+"\namong "+to_string(numberOfErrors)+" candidates"+(markdown_errors?"\n```rust":"")+overloading_errors+(markdown_errors?"\n```\n":"")+"\nand not found `on` context\n  ";
        overloading_errors = "";
        unpacks = new_unpacks;

        // COPY OF ABOVE CODE HERE TO RETRY
        for(const Type& type : previousType->get_options(types)) { // options encompases all overloads, in case of unions it may not have the base overloadv
            if(!type) imp->error(--p, "Internal error: obained a null option for "+previousType->name.to_string());
            if(type->unresolved_options) continue;
            try {
                //if(type->lazy_compile) throw runtime_error("Failed to resolve parametric type: "+type->signature());//+"\nParameters need to be determined by arguments");
                size_t type_args = type->not_primitive()?type->args.size():1;
                if(unpacks.size()!=type_args) throw runtime_error(type->signature(types));
                for(size_t i=0;i<unpacks.size();++i) {
                    arg_progress = i;
                    auto arg_type = type->_is_primitive?type:type->args[i].type;
                    if(type->not_primitive() && arg_type->not_primitive()) throw runtime_error(type->signature(types)+": Cannot unpack abstract " + arg_type->signature(types) + " "+type->args[i].name.to_string());
                    if(!internalTypes.contains(unpacks[i])) throw runtime_error(type->signature(types)+": No runtype for "+pretty_var(unpacks[i].to_string()));
                    if(type->not_primitive() && arg_type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i].to_string())) 
                        throw runtime_error(type->signature(types));
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
                }
                if(type->choice_power>highest_choice_power) {
                    highest_choice_power = type->choice_power;
                    numberOfFound = 0;
                    multipleFound = "";
                }
                if(type->choice_power<highest_choice_power) continue;
                successfullType = type;
                if(markdown_errors) multipleFound += "\n";
                else multipleFound += "\n- ";
                multipleFound += type->signature(types);
                numberOfFound++;
            }
            catch (const std::runtime_error& e) {
                if(arg_progress>max_arg_progress) {
                    overloading_errors = "";
                    numberOfErrors = 0;
                }
                if(markdown_errors) overloading_errors += "\n";
                else overloading_errors += "\n- ";
                overloading_errors += e.what();
                numberOfErrors++;
            }
        }
    }
    type = successfullType;

    if(type.get()!=successfullType.get()) type->number_of_calls++;
    if(!type && numberOfErrors) imp->error(first_token_pos, "Not found\n  "+prev_errors+string(markdown_errors?"```rust\n":"")+previousType->name.to_string()+signature_like(types, unpacks)+(markdown_errors?"\n```\n":"")+"\namong "+to_string(numberOfErrors)+" candidates"+(markdown_errors?"\n```rust":"")+overloading_errors+(markdown_errors?"\n```\n":""));
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
    for(const auto& it : type->active_calls) if(it.second.exists()) active_calls[var+it.first] = var+it.second;

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
        vardecl += Code(STRUCT_VAR, Variable(type->raw_signature_state_name()), var+STATE_VAR,Variable("={0}"), SEMICOLON_VAR);
        internalTypes.vars[var+STATE_VAR] = types.vars[STATE_VAR];
        Code impl = Code();
        internalTypes.vars[var+ERR_VAR] = types.vars[ERRCODE_VAR];
        internalTypes.vars[var+TASK_VAR] = types.vars[PTR_VAR];
        internalTypes.vars[var] = type;
        active_calls[var] = var;
        for(const Variable& pack : type->packs) if(type->alignments[pack]) alignments[var+pack] = type->alignments[pack];
        for(size_t i=1;i<type->packs.size();++i) { // first service output is the error code, which we return instead of parsing by reference
            const Variable& ret = type->packs[i];
            size_t fp = first_token_pos;
            Variable arg = var+ret;
            assign_variable(type->internalTypes.vars[ret], arg, ZERO_VAR, imp, fp);
            mutables.insert(arg);
            impl += Code(var+STATE_VAR, DOT_VAR, ret, ASSIGN_VAR, REF_VAR, arg, SEMICOLON_VAR);
            //type->coallesce_finals(ret);
            //finals[var+"__"+ret] += type->rebase(type->finals[ret], var);
        }
        for(const auto& it : type->internalTypes.vars) internalTypes.vars[var+it.first] = it.second;
        for(size_t i=0;i<unpacks.size();++i) {
            notify_service_arg(unpacks[i]);
            if(type->args[i].mut) {
                impl += Code(var+STATE_VAR, DOT_VAR, type->args[i].name, ASSIGN_VAR, REF_VAR, unpacks[i],SEMICOLON_VAR);
                type->coallesce_finals(type->args[i].name);
                finals[unpacks[i]] = finals[unpacks[i]]+type->rename_var(type->finals[type->args[i].name], type->args[i].name, unpacks[i]);
            }
            else impl += Code(var+STATE_VAR, DOT_VAR, type->args[i].name, ASSIGN_VAR, unpacks[i],SEMICOLON_VAR);
        }
        impl += Code(var+TASK_VAR, ASSIGN_VAR, Variable("__smolambda_add_task"),LPAR_VAR)
                +Code(type->name+Variable(to_string(type->identifier)), COMMA_VAR, REF_VAR, var+STATE_VAR)
                +Code(RPAR_VAR, SEMICOLON_VAR);
        implementation +=impl;
        internalTypes.vars[var] = type->alias_for.exists()?type->internalTypes.vars[type->alias_for]:type;
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
    for(const auto& it : type->active_calls) active_calls[var+it.first] = var+it.second;
    for(const auto& it : type->internalTypes.vars) if(it.second) { // TODO: remove this if (currently it guards against some leftover labels)
        if(!it.second) imp->error(--p, type->name.to_string()+"."+pretty_var(it.first.to_string())+" is undefined");
        internalTypes.vars[var+it.first] = it.second;
    }
    //finals[""] += immediate_finals; // TODO maybe it's a good idea to have some deallocations at the end of runtype implementations
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
    if(internalTypes.contains(first_token)) {
        if(curry.exists()) imp->error(p, "Expecting runtype but got variable: "+first_token.to_string());
        return next_var(imp, p, first_token, types); //ASSIGNMENT TO ALREADY EXISTING VARIABLE
    }
    if(types.contains(first_token)) {
        auto type = types.vars.find(first_token)->second;
        vector<Variable> unpacks;
        if(imp->at(p)=="__consume") {
            if(!curry.exists()) imp->error(p-2, "Unexpected usage of operator\nThere is no left-hand-side");
            if(!internalTypes.contains(curry)) imp->error(first_token_pos-2, "Not found: "+pretty_var(curry.to_string())+recommend_runtype(types, curry));
            else if(internalTypes.vars.find(curry)->second->not_primitive()) {
                for(const Variable& pack : internalTypes.vars.find(curry)->second->packs) unpacks.push_back(curry+pack);
            }
            else unpacks.push_back(curry);
            p++;
            string next = imp->at(p++);
            Variable rhs = parse_expression(imp, p, next, types);
            if(!internalTypes.contains(rhs)) imp->error(--p, "Failed to parse the right-hand-side of "+first_token.to_string());
            const auto& rhsType = internalTypes.vars.find(rhs)->second;
            if(rhsType->_is_primitive) unpacks.push_back(rhs);
            else if(type->is_service) {
                Variable fail_var = create_temp();
                if(active_calls[rhs].exists() && active_calls[active_calls[rhs]].exists()) {
                    const Variable& call_var = active_calls[rhs];
                    implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
                    implementation += Code(Variable("__smolambda_task_destroy"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
                    implementation += Code(rhs+ERR_VAR, ASSIGN_VAR, call_var+STATE_VAR, DOT_VAR, ERR_VAR, SEMICOLON_VAR);
                    static const Variable token_err1 = Variable(":\nprintf(\"Runtime error from ");
                    static const Variable token_err2 = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
                    implementation +=Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
                    errors = errors+Code(fail_var, token_err1, rhsType->name, call_var, token_err2);
                    add_preample("#include <stdio.h>");
                }
                for(size_t i=1;i<rhsType->packs.size();++i) unpacks.push_back(active_calls[rhs]+rhsType->packs[i]);
                if(active_calls[rhs].exists() && active_calls[active_calls[rhs]].exists()) active_calls[active_calls[rhs]] = EMPTY_VAR;
            }
            else for(const Variable& pack : rhsType->packs) unpacks.push_back(rhs+pack);
        }
        else if(imp->at(p)!="(" && curry.exists()) {
            if(!internalTypes.contains(curry)) imp->error(first_token_pos-2, "Not found: "+pretty_var(curry.to_string())+recommend_runtype(types, curry));
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
            for(const auto& option : type->get_options(types)) {
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
            for(const auto& option : type->get_options(types)) {
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
            unpacks = gather_tuple(imp, p, types, curry);
            if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        }

        return call_type(imp, p, type, unpacks, first_token_pos, first_token, types);
    }
    if(curry.exists() || (p<imp->size() && (imp->at(p)=="(" || imp->at(p)=="__consume"))) imp->error(--p, "Missing runtype: "+first_token.to_string()+recommend_runtype(types, first_token));
    return next_var(imp, p, first_token, types);
}



