// Copyright 2025 Emmanouil Krasanakis (maniospas@hotmail.com)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "../def.h"


Variable Def::call_type(
    
    size_t& p, 
    Type& type, 
    vector<Variable>& unpacks, 
    const size_t first_token_pos, 
    const Variable& first_token, 
    Types& types
) {
    static const Variable token_if = Variable("if(");
    static const Variable token_goto = Variable(")goto");
    string overloading_errors("");
    Variable var = create_temp();
    Type successfullType = nullptr;
    string multipleFound("");
    int numberOfFound = 0;
    int numberOfErrors = 0;
    if(!type) 
        imp->error(first_token_pos, "Not found runtype: "
            +first_token.to_string()
            +recommend_runtype(types, first_token)
        );
    Type previousType = type;
    int highest_choice_power = 0;
    for(size_t i=0;i<unpacks.size();++i) {
        if(!contains(unpacks[i])) 
            imp->error(p-1, "Not found: "
                +pretty_var(unpacks[i].to_string())
                +recommend_variable(types, unpacks[i])
            );
        if(released[unpacks[i]])
            imp->error(p-1, "Already released (this includes implicit releases): "
                +pretty_var(unpacks[i].to_string())
                +recommend_variable(types, unpacks[i])
            );
    }
    type->number_of_calls++;
    size_t max_arg_progress = 0;
    size_t arg_progress = 0;
    for(const Type& type : previousType->get_options()) { // options encompases all overloads, in case of unions it may not have the base overloadv
        if(!type) 
            imp->error(--p, "Internal error: obained a null option for "
                +previousType->name.to_string()
            );
        if(type->unresolved_options) 
            continue;
        try {
            //if(type->lazy_compile) throw runtime_error("Failed to resolve parametric type: "+type->signature());//+"\nParameters need to be determined by arguments");
            size_t type_args = type->not_primitive()?type->args.size():1;
            if(unpacks.size()!=type_args) throw runtime_error(type->signature(types));
            arg_progress = 0;
            for(size_t i=0;i<unpacks.size();++i) {
                arg_progress++;
                auto arg_type = type->_is_primitive?type:type->args[i].type;
                if(type->not_primitive() && arg_type->not_primitive()) 
                    throw runtime_error(type->signature(types)+": Cannot unpack abstract " + arg_type->signature(types) + " "+type->args[i].name.to_string());
                if(!contains(unpacks[i])) 
                    throw runtime_error(type->signature(types)+": No runtype for "+pretty_var(unpacks[i].to_string()));
                if(type->not_primitive() 
                    && arg_type!=vars[unpacks[i]] 
                    && !is_primitive(unpacks[i].to_string())
                ) 
                    throw runtime_error(type->signature(types));
                if(type->not_primitive() && arg_type->_is_primitive && arg_type->name==NOM_VAR && alignments[unpacks[i]]!=type->alignments[type->args[i].name]) {
                    if(type->alignments[type->args[i].name] && !types.reverse_alignment_labels[type->alignments[type->args[i].name]]) 
                        imp->error(first_token_pos, "Internal error: cannot find alignment "
                            +to_string(type->alignments[type->args[i].name])
                            +" of "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())
                            +" within "+signature(types)
                        );
                    if(alignments[unpacks[i]] && !types.reverse_alignment_labels[alignments[unpacks[i]]]) 
                        imp->error(first_token_pos, "Internal error: cannot find alignment "
                            +to_string(alignments[unpacks[i]])
                            +" for "+unpacks[i].to_string()
                            +" argument "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())
                            +" within "+signature(types)
                        );
                    if(!alignments[unpacks[i]] || types.reverse_alignment_labels[alignments[unpacks[i]]]==type.get()) 
                        {}//REMINDER THAT THIS IS AN ERROR THAT POLUTES NEXT LOOP: alignments[unpacks[i]] = type->alignments[type->args[i].name];
                    else 
                        throw runtime_error(type->signature(types));
                }
                arg_progress++;
                if(buffer_types.find(unpacks[i])!=buffer_types.end() && buffer_types[unpacks[i]]!=type->buffer_types[type->args[i].name]) 
                    throw runtime_error(type->signature(types));
                    
                arg_progress++;
                if(type->not_primitive() && (type->args[i].mut || type->mutables.find(type->args[i].name)!=type->mutables.end()) && !can_mutate(unpacks[i], p)) {
                    throw runtime_error(type->signature(types));     
                }
            }
            if(type->choice_power>highest_choice_power) {
                highest_choice_power = type->choice_power;
                numberOfFound = 0;
                multipleFound = "";
            }
            if(type->choice_power<highest_choice_power) continue;
            successfullType = type;
            if(lsp) 
                multipleFound += "\n";
            else 
                multipleFound += "\n- ";
            multipleFound += type->signature(types);
            numberOfFound++;
        }
        catch (const std::runtime_error& e) {
            if(arg_progress>max_arg_progress) {
                overloading_errors = "";
                numberOfErrors = 0;
            }
            if(lsp) 
                overloading_errors += "\n";
            else 
                overloading_errors += "\n- ";
            overloading_errors += e.what();
            numberOfErrors++;
        }
    }
    type = successfullType;
    string prev_errors("");
    if(!type && active_context.exists()) { // 
        vector<Variable> new_unpacks;
        if(vars[active_context]->_is_primitive) 
            new_unpacks.push_back(active_context);
        else for(const Variable& pack : vars[active_context]->packs) 
            new_unpacks.push_back(active_context+pack);
        for(const Variable& pack : unpacks) 
            new_unpacks.push_back(pack);
        prev_errors = previousType->name.to_string()
            +signature_like(types, unpacks)
            +"\namong "+to_string(numberOfErrors)
            +" candidates"+overloading_errors
            +"\nand not found `on` context\n  ";
        overloading_errors = "";
        unpacks = new_unpacks;

        // COPY OF ABOVE CODE HERE TO RETRY
        for(const Type& type : previousType->get_options()) { // options encompases all overloads, in case of unions it may not have the base overloadv
            if(!type) 
                imp->error(--p, "Internal error: obained a null option for "
                    +previousType->name.to_string()
                );
            if(type->unresolved_options) 
                continue;
            try {
                //if(type->lazy_compile) throw runtime_error("Failed to resolve parametric type: "+type->signature());//+"\nParameters need to be determined by arguments");
                size_t type_args = type->not_primitive()?type->args.size():1;
                if(unpacks.size()!=type_args) 
                    throw runtime_error(type->signature(types));
                arg_progress = 0;
                for(size_t i=0;i<unpacks.size();++i) {
                    arg_progress++;
                    auto arg_type = type->_is_primitive?type:type->args[i].type;
                    if(type->not_primitive() && arg_type->not_primitive()) 
                        throw runtime_error(type->signature(types)
                            +": Cannot unpack abstract " 
                            + arg_type->signature(types) 
                            + " "+type->args[i].name.to_string()
                        );
                    if(!contains(unpacks[i])) 
                        throw runtime_error(type->signature(types)
                            +": No runtype for "
                            +pretty_var(unpacks[i].to_string())
                        );
                    if(type->not_primitive() 
                        && arg_type!=vars[unpacks[i]] 
                        && !is_primitive(unpacks[i].to_string())
                    ) 
                        throw runtime_error(type->signature(types));
                    if(type->not_primitive() 
                        && arg_type->_is_primitive 
                        && arg_type->name==NOM_VAR 
                        && alignments[unpacks[i]]!=type->alignments[type->args[i].name]
                    ) {
                        if(type->alignments[type->args[i].name] && !types.reverse_alignment_labels[type->alignments[type->args[i].name]]) 
                            imp->error(first_token_pos, "Internal error: cannot find alignment "
                                +to_string(type->alignments[type->args[i].name])
                                +" of "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())
                                +" within "+signature(types)
                            );
                        if(alignments[unpacks[i]] && !types.reverse_alignment_labels[alignments[unpacks[i]]]) 
                            imp->error(first_token_pos, "Internal error: cannot find alignment "
                                +to_string(alignments[unpacks[i]])
                                +" for "+unpacks[i].to_string()
                                +" argument "+pretty_var(type->name.to_string()+"__"+type->args[i].name.to_string())
                                +" within "+signature(types)
                            );
                        if(!alignments[unpacks[i]] || types.reverse_alignment_labels[alignments[unpacks[i]]]==type.get()) 
                            {}//REMINDER THAT THIS IS AN ERROR THAT POLUTES NEXT LOOP: alignments[unpacks[i]] = type->alignments[type->args[i].name];
                        else 
                            throw runtime_error(type->signature(types)+": nom "+pretty_var(type->name.to_string())+"__"+ pretty_var(type->args[i].name.to_string())
                                +" expects data from "+((!type->alignments[type->args[i].name] || !types.reverse_alignment_labels[type->alignments[type->args[i].name]])?"nothing":types.reverse_alignment_labels[type->alignments[type->args[i].name]]->signature(types))+" with id "+to_string(type->alignments[type->args[i].name])
                                +" but got "+((alignments[unpacks[i]] && types.reverse_alignment_labels[alignments[unpacks[i]]])?types.reverse_alignment_labels[alignments[unpacks[i]]]->signature(types):"nothing")+" with id "+to_string(alignments[unpacks[i]])
                            );
                    }
                    arg_progress++;
                    if(buffer_types.find(unpacks[i])!=buffer_types.end() && buffer_types[unpacks[i]]!=type->buffer_types[type->args[i].name]) 
                        throw runtime_error(type->signature(types));
                    arg_progress++;
                    if(type->not_primitive() && (type->args[i].mut || type->mutables.find(type->args[i].name)!=type->mutables.end()) && !can_mutate(unpacks[i], p)) 
                        throw runtime_error(type->signature(types));     
                }
                if(type->choice_power>highest_choice_power) {
                    highest_choice_power = type->choice_power;
                    numberOfFound = 0;
                    multipleFound = "";
                }
                if(type->choice_power<highest_choice_power) 
                    continue;
                successfullType = type;
                if(lsp) 
                    multipleFound += "\n";
                else 
                    multipleFound += "\n- ";
                multipleFound += type->signature(types);
                numberOfFound++;
            }
            catch (const std::runtime_error& e) {
                if(arg_progress>max_arg_progress) {
                    overloading_errors = "";
                    numberOfErrors = 0;
                }
                if(lsp) 
                    overloading_errors += "\n";
                else 
                    overloading_errors += "\n- ";
                overloading_errors += e.what();
                numberOfErrors++;
            }
        }
    }
    type = successfullType;

    if(type.get()!=successfullType.get()) 
        type->number_of_calls++;
    if(!type && numberOfErrors) 
        imp->error(first_token_pos, "Not found\n"
            +prev_errors
            +string(lsp?"```rust\n":"")
            +previousType->name.to_string()
            +signature_like(types, unpacks)+(lsp?"\n```\n":"")
            +"\namong "+to_string(numberOfErrors)
            +" candidates"+(lsp?"\n```rust":"")
            +overloading_errors
            +(lsp?"\n```\n":"")
        );
    if(!type) 
        imp->error(first_token_pos, "Not found runtype version: "
            +first_token.to_string()+" among "
            +to_string(previousType->options.size())
            +" candidates of "
            +previousType->signature(types)
        );
    if(type->lazy_compile) 
        imp->error(pos, "Internal error: Runtype has not been compiled");
    
    // singleton resources should never be called twice in a program
    for(const Variable& singleton : type->singletons) 
        if(singletons.find(singleton)==singletons.end())
            singletons.insert(singleton);
        else
            imp->error(--p, "This resource family "
                +singleton.to_string()
                +" has been claimed by a previous @noother (e.g., in a call)"
            );
    
    // acquired resources should never be called twice by services because they require sequential execution
    if(type->is_service) {
        for(const Variable& acq : type->acquired) 
            if(acquired.find(acq)==acquired.end())
                acquired.insert(acq);
            else
                imp->error(--p, "This resource family "
                    +acq.to_string()
                    +" has @acquire in a previous service call"
                );
    }

    // repeat here to properly handle alignment (which we couldn't previously)
    for(size_t i=0;i<unpacks.size();++i) {
        auto arg_type = type->_is_primitive?type:type->args[i].type;
        if(type->not_primitive() && arg_type->not_primitive()) 
            throw runtime_error(type->signature(types)+": Cannot unpack abstract " 
                + arg_type->signature(types) 
                + " "+type->args[i].name.to_string()
            );
        if(!contains(unpacks[i])) 
            throw runtime_error(type->signature(types)
                +": No runtype for "
                +pretty_var(unpacks[i].to_string())
            );
        if(type->not_primitive() 
            && arg_type!=vars[unpacks[i]] 
            && !is_primitive(unpacks[i].to_string())
        ) 
            throw runtime_error(type->signature(types)
                +": Expects " + arg_type->name.to_string()
                 + " "+pretty_var(type->name.to_string()
                 +"__"+type->args[i].name.to_string())
                 +" but got "+vars[unpacks[i]]->name.to_string()
                 +" "+pretty_var(unpacks[i].to_string())
            );
        if(type->not_primitive() 
            && arg_type->_is_primitive 
            && arg_type->name==NOM_VAR
            && alignments[unpacks[i]]!=type->alignments[type->args[i].name]
        ) {
            if(type->alignments[type->args[i].name] && !types.reverse_alignment_labels[type->alignments[type->args[i].name]]) 
                imp->error(pos, "Internal error: cannot find alignment "
                    +to_string(type->alignments[type->args[i].name])
                    +" of "+pretty_var(type->name.to_string()
                    +"__"+type->args[i].name.to_string())
                    +" within "+signature(types)
                );
            if(alignments[unpacks[i]] && !types.reverse_alignment_labels[alignments[unpacks[i]]]) 
                imp->error(pos, "Internal error: cannot find alignment "
                    +to_string(alignments[unpacks[i]])
                    +" for "+unpacks[i].to_string()
                    +" argument "+pretty_var(type->name.to_string()
                    +"__"+type->args[i].name.to_string())
                    +" within "+signature(types)
                );
            if(!alignments[unpacks[i]] || types.reverse_alignment_labels[alignments[unpacks[i]]]==type.get()) 
                alignments[unpacks[i]] = type->alignments[type->args[i].name];
            else throw runtime_error(type->signature(types)
                +": nom "+pretty_var(type->name.to_string()
                +"__"+type->args[i].name.to_string())
                +" expects data from "
                +((!type->alignments[type->args[i].name] || !types.reverse_alignment_labels[type->alignments[type->args[i].name]])
                        ?"nothing":types.reverse_alignment_labels[type->alignments[type->args[i].name]]->signature(types))
                +" with id "+to_string(type->alignments[type->args[i].name])
                +" but got "+((alignments[unpacks[i]] && types.reverse_alignment_labels[alignments[unpacks[i]]])
                    ?types.reverse_alignment_labels[alignments[unpacks[i]]]->signature(types):"nothing")+" with id "+to_string(alignments[unpacks[i]])
            );
        }
        if(type->not_primitive() 
            && (type->args[i].mut || type->mutables.find(type->args[i].name)!=type->mutables.end()) && !can_mutate(unpacks[i], p)
        ) 
            throw runtime_error(type->signature(types));
    }


    // TODO: reinstate this but improve inference
    //if(numberOfFound>1) imp->error(first_token_pos, "Ambiguous use of ["+to_string(unpacks.size())+"] structural arguments - they match "+to_string(numberOfFound)+" candidates"+(lsp?"\n```rust":"")+multipleFound+(lsp?"\n```\n":""));

    for(const Variable& pack : type->packs) 
        type->coallesce_finals(pack);
    auto transfer_finals = type->finals;
    unordered_map<Variable, Code> transferring;
    for(const Variable& pack : type->packs) 
        if(type->finals[pack].exists()) {
            type->coallesce_finals(pack);
            finals[var+pack] = finals[var+pack] + type->rebase(type->finals[pack], var);
            transferring[var+pack] = finals[var+pack];
            transfer_finals[pack] = Code();
        }
    for(const auto& arg : type->args) 
        if(arg.mut && type->finals[arg.name].exists()) {
            type->coallesce_finals(arg.name);
            finals[var+arg.name] = finals[var+arg.name]+type->rebase(type->finals[arg.name], var);
            transferring[var+arg.name] = finals[var+arg.name];
            transfer_finals[arg.name] = Code();
        }
    for(const auto& it : type->buffer_types) 
        buffer_types[var+it.first] = it.second;
    for(const auto& it : type->current_renaming) 
        current_renaming[var+it.first] = var+it.second;
    for(const auto& it : type->active_calls) 
        if(it.second.exists()) 
            active_calls[var+it.first] = var+it.second;

    // prevent memory leaks in loops
    if(uplifiting_is_loop.size() && uplifiting_is_loop.back() && type->finals.size()) {
        string desc("");
        for(const auto& it : transferring) 
            if(it.first.exists() && it.second.exists()) 
                desc += "\n- "+pretty_var(type->name.to_string()+"__"+it.first.to_string());
        if(desc.size()) 
            imp->error(--p, "Loop cannot call: "
                +type->signature(types)
                +"\nThis could leak the following resources:"
                +desc
            );
    }

    for(const Variable& mut : type->mutables) 
        mutables.insert(var+mut);
    mutables.insert(var); // MAKE ALL CALL OUTCOMES MUTABLE BY DEFAULT

    // make actual call
    if(type->is_service) {
        vardecl += Code(STRUCT_VAR, Variable(type->raw_signature_state_name()+"*"), var+STATE_VAR, ASSIGN_VAR, ZERO_VAR, SEMICOLON_VAR);
        vars[var+STATE_VAR] = types.vars[STATE_VAR];

        Code impl;
        if(!Def::calls_on_heap){
            impl = Code(Variable("{char mark;if(__service_stack_floor+"), Variable(to_string(type->estimate_stack_size())), Variable(">=(char*)&mark) goto __service_stack_floor_handler;}"));
            errors.insert(Code(Variable("__service_stack_floor_handler:\nprintf(\"Insufficient stack for safe service call\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n")));
    
            impl += Code(var+STATE_VAR, ASSIGN_VAR, Variable("(struct "+type->raw_signature_state_name()+"*)alloca(sizeof(struct "+type->raw_signature_state_name()+"))"),SEMICOLON_VAR);
            impl += Code(Variable("__smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results,"), var+STATE_VAR, RPAR_VAR, SEMICOLON_VAR);
            
            impl += Code(
                Variable("memset("), 
                var+STATE_VAR, 
                COMMA_VAR, 
                Variable("0"), 
                COMMA_VAR, 
                Variable("sizeof(struct "+type->raw_signature_state_name()+"))"), 
                SEMICOLON_VAR
            );
        }
        else {
            impl = Code(Variable("{char mark;if(__service_stack_floor+"), Variable(to_string(type->estimate_stack_size())), Variable(">=(char*)&mark) goto __service_stack_floor_handler;}"));
            errors.insert(Code(Variable("__service_stack_floor_handler:\nprintf(\"Insufficient stack for safe service call\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n")));
            impl += Code(var+STATE_VAR, ASSIGN_VAR, Variable("(struct "+type->raw_signature_state_name()+"*)__runtime_calloc(sizeof(struct "+type->raw_signature_state_name()+"))"),SEMICOLON_VAR);
        
        }
        impl += Code(Variable("__smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results,"), var+STATE_VAR, RPAR_VAR, SEMICOLON_VAR);
        vars[var+ERR_VAR] = types.vars[ERRCODE_VAR];
        vars[var+TASK_VAR] = types.vars[PTR_VAR];
        vars[var] = type;
        active_calls[var] = var;
        for(const Variable& pack : type->packs) 
            if(type->alignments[pack]) 
                alignments[var+pack] = type->alignments[pack];
        for(size_t i=1;i<type->packs.size();++i) { // first service output is the error code, which we return instead of parsing by reference
            const Variable& ret = type->packs[i];
            size_t fp = first_token_pos;
            Variable arg = var+ret;
            assign_variable(type->vars[ret], arg, ZERO_VAR, fp);
            mutables.insert(arg);
            impl += Code(var+STATE_VAR, ARROW_VAR, ret+RET_VAR, ASSIGN_VAR, REF_VAR, arg, SEMICOLON_VAR);
            //type->coallesce_finals(ret);
            //finals[var+"__"+ret] += type->rebase(type->finals[ret], var);
        }
        for(const auto& it : type->vars) 
            vars[var+it.first] = it.second;
        for(size_t i=0;i<type->args.size();++i) {
            notify_service_arg(unpacks[i]);
            if(type->args[i].mut) {
                impl += Code(var+STATE_VAR, ARROW_VAR, type->args[i].name, ASSIGN_VAR, REF_VAR, unpacks[i],SEMICOLON_VAR);
                type->coallesce_finals(type->args[i].name);
                finals[unpacks[i]] = finals[unpacks[i]]+type->rename_var(type->finals[type->args[i].name], type->args[i].name, unpacks[i]);
            }
            else 
                impl += Code(var+STATE_VAR, ARROW_VAR, type->args[i].name, ASSIGN_VAR, unpacks[i],SEMICOLON_VAR);
        }
        impl += Code(var+TASK_VAR, ASSIGN_VAR, Variable("__smolambda_add_task"),LPAR_VAR)
                +Code(type->name+Variable(to_string(type->identifier)), COMMA_VAR, var+STATE_VAR)
                +Code(RPAR_VAR, SEMICOLON_VAR);
        impl += Code(Variable("__smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks,"), var+TASK_VAR, RPAR_VAR, SEMICOLON_VAR);
        implementation +=impl;
        vars[var] = type->alias_for.exists()?type->vars[type->alias_for]:type;
        return next_var(p, var, types);
    }
    if(type->_is_primitive) {
        if(unpacks.size()!=1) imp->error(--p, "Primitive types only accept one argument");
        size_t fp = first_token_pos;
        assign_variable(type, var, unpacks[0], fp);
        return next_var(p, var, types);
    }
    for(const auto& it : type->alignments) if(it.second) alignments[var+it.first] = it.second; 
    Code immediate_finals;
    for(size_t i=0;i<unpacks.size();++i) {
        size_t fp = first_token_pos;
        assign_variable(type->args[i].type, var+type->args[i].name, unpacks[i], fp);
        if(type->args[i].mut) {
            immediate_finals = immediate_finals+Code(unpacks[i],ASSIGN_VAR,var+type->args[i].name,SEMICOLON_VAR);
            current_renaming[unpacks[i]] = var.to_string()+"__"+type->args[i].name.to_string();
            current_renaming[var+type->args[i].name] = unpacks[i];
            current_renaming[unpacks[i]] = var+type->args[i].name;
        }
    }
    for(const auto& it : type->vars) 
        vars[var+it.first] = it.second;
    for(const auto& final : transfer_finals) 
        immediate_finals = immediate_finals+type->rebase(final.second, var);
    vars[var] = type->alias_for.exists()?type->vars[type->alias_for]:type;
    implementation +=type->rebase(type->implementation, var)+immediate_finals;
    for(const string& pre : type->preample) 
        add_preample(pre);
    for(const string& pre : type->linker) 
        add_linker(pre);
    for(const auto& it : type->buffer_types) 
        buffer_types[var+it.first] = it.second;

    //for(const auto& final : type->finals) finals[var+"__"+final.first] += type->rebase(final.second, var); // splt into immediate and delayed finals
    //finals = type->rebase(type->finals, var)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
    for(const auto& error : type->errors)
        errors.insert(type->rebase(error, var));
    for(const auto& it : type->current_renaming) 
        current_renaming[var+it.first] = var+it.second;
    for(const auto& it : type->active_calls) 
        active_calls[var+it.first] = var+it.second;
    for(const auto& it : type->vars) 
        if(it.second) { // TODO: remove this if(currently it guards against some leftover labels)
            if(!it.second) 
                imp->error(--p, type->name.to_string()+"."+pretty_var(it.first.to_string())+" is undefined");
            vars[var+it.first] = it.second;
        }
    //finals[""] += immediate_finals; // TODO maybe it's a good idea to have some deallocations at the end of runtype implementations
    if(type->packs.size()==1) 
        return next_var(p, var+type->packs[0], types);
    return next_var(p, var, types);
}
