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
#include "../../def.h"

Variable Def::parse_expression(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, const Variable& curry) {
    if(first_token=="(") {
        Variable ret = parse_expression(imp, p, imp->at(p++), types, curry);
        if(imp->at(p++)!=")") 
            imp->error(--p, "Expecting closing parenthesis");
        return next_var(imp, p, ret, types);
    }
    return parse_expression_no_par(imp, p, first_token, types, curry);
}

Variable Def::parse_expression_no_par(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry) {
    size_t first_token_pos = p-1;
    if(first_token==DOT_VAR 
        || first_token==CURRY_VAR
        || first_token==LBRACKET_VAR 
        || first_token==RBRACKET_VAR 
        || first_token=="{" 
        || first_token=="}" 
        || first_token==";"
        || first_token=="&"
        || first_token=="and"
        || first_token=="or"
    ) 
        imp->error(p-1, "Unexpected symbol\nThe previous expression already ended.");
    if(first_token=="if") 
        return parse_if(imp, p, first_token, types, curry, first_token_pos);
    if(first_token=="while") 
        return parse_while(imp, p, first_token, types, curry, first_token_pos);
    if(first_token=="on") 
        return parse_on(imp, p, first_token, types, curry, first_token_pos);
    if(first_token=="with") 
        return parse_with(imp, p, first_token, types, curry, first_token_pos);
    if(curry.exists() 
        && contains(curry) 
        && vars[curry]->name==BUFFER_VAR
    ) {
        if(first_token=="len")
            return parse_buffer_len(imp, p, first_token, types, curry, first_token_pos);
        if(first_token=="put")
            return parse_buffer_put(imp, p, first_token, types, curry, first_token_pos);
        if(first_token=="push")
            return parse_buffer_push(imp, p, first_token, types, curry, first_token_pos);
        if(first_token=="expect")
            return parse_buffer_expect(imp, p, first_token, types, curry, first_token_pos);
    }

    if(is_primitive(first_token.to_string())) {
        if(curry.exists())
            imp->error(p-1, "Cannot curry into :primitive.");
        string vartype = type_primitive(first_token.to_string());
        string defval = "0";
        if(p<imp->size() && imp->at(p)=="@" && imp->at(p+1)=="else") {
            defval = imp->at(p+2);
            p += 3;
            if(type_primitive(defval)!=vartype) 
                imp->error(p-1, "Required "+vartype+" primitive");
        }
        string var = create_temp();
        if(!types.contains(vartype)) 
            return first_token;// fallback
        vars[var] = types.vars[vartype];
        // vardecl += vartype+" "+var+" = "+defval+";\n"; // always set vars to zero because they may reside in if blocks
        implementation += Code(var,ASSIGN_VAR,first_token.to_string(),SEMICOLON_VAR);
        //mutables.insert(var);
        return next_var(imp, p, var, types);
    }
    if(contains(first_token)) {
        if(curry.exists()) 
            imp->error(p, "Expecting runtype but got variable: "
                +first_token.to_string()
            );
        return next_var(imp, p, first_token, types); //ASSIGNMENT TO ALREADY EXISTING VARIABLE
    }
    if(types.contains(first_token)) {
        auto type = types.vars.find(first_token)->second;
        Variable surface = EMPTY_VAR;
        if(p<imp->size()-1 && imp->at(p)=="[" && !curry.exists()) {
            p++;
            if(imp->at(p)!="]") {
                string next = imp->at(p);
                p++;
                surface = parse_expression(imp, p, next, types, EMPTY_VAR);
                if(!contains(surface) || !vars[surface]->buffer_ptr.exists())
                    imp->error(--p, "Given that "
                        +first_token.to_string()
                        +" is a runtype (not a local variable), [] is expected to declare a buffer here"
                        +" or a @buffer runtype must be returned to serve as the buffer's allocation"
                    );
                if(!can_mutate(surface) && !imp->allow_unsafe)
                    imp->error(--p, "Buffer surface is not mutable: "+pretty_var(surface.to_string())+"\nIt might have been used elsewhere. Mark this file as @unsafe to allow a union view.");
            }
            p++;
            if(type->options.size()==0) 
                imp->error(--p, "No options to determine buffer elements "
                    +type->name.to_string()
                    +"\nAdding before the argument's type may resolve this issue"
                    +"\nby forcing usage of the a runtype with ->in its return"
                    +"\namong those overloaded with the same name/union."
                    +"\nThis annoation directly interleaves the type in the definition"
                    +"\nand removes its lexical scoping."
                );
            double option_power = -1;
            int conflicts = 0;
            auto original_type = type;
            for(const auto& it : type->options) {
                if(it->choice_power>option_power) {// && it->name==argType->name) {
                    option_power = it->choice_power;
                    type = it;
                    conflicts = 0;
                }
                else if(it->choice_power==option_power) 
                    conflicts++;
            }
            if(option_power<0) 
                imp->error(--p, "No resolution options for determining buffer elements: "
                    +original_type->name.to_string()
                );
            if(conflicts) 
                imp->error(--p, "There was no criterion for resolving buffer element to one option: "
                    +original_type->name.to_string()
                    +"\nMultiple options are available"
                );
        
            Variable var = create_temp();
            mutables.insert(var);
            Variable dynamic_var = var+Variable("dynamic");
            Variable surface_var = var+Variable("surface");
            buffer_types[dynamic_var] = type;
            vars[var] = types.vars[BUFFER_VAR];
            vars[dynamic_var] = types.vars[PTR_VAR];
            //vars[var+Variable("surface")] = types.vars[PTR_VAR];
            Variable raw_var = var;
            var = dynamic_var;
            implementation += Code(
                var,
                ASSIGN_VAR,
                Variable("__runtime_calloc(3*sizeof(u64))"),
                SEMICOLON_VAR
            ); // ZERO OUT MEMORY, SIZE, CAPACITY (MSB of capacity holds whether the buffer is statically initialized)
            if(surface.exists()) {
                size_t count_packs = 0;
                for(const auto& pack : type->packs)
                    if(type->contains(pack) && type->vars[pack]->name!=NOM_VAR)
                        count_packs++;
                if(type->_is_primitive) 
                    count_packs++;
                implementation += Code(
                    Variable("((u64*)"),var,Variable(")[0]"), 
                    ASSIGN_VAR, Variable("(u64)(u64*)"), 
                    surface+vars[surface]->buffer_ptr, 
                    SEMICOLON_VAR
                );
                implementation += Code(
                    Variable("((u64*)"),
                    var,
                    Variable(")[2]"), 
                    ASSIGN_VAR, 
                    LPAR_VAR,
                    surface+vars[surface]->buffer_size, 
                    Variable("/(sizeof(u64)*"+to_string(count_packs)+")) | (1ULL <<63)"), 
                    SEMICOLON_VAR
                );
                finals[var] += Code(
                    token_if, var, RPAR_VAR,
                    Variable("__runtime_free("),var,RPAR_VAR,SEMICOLON_VAR,
                    var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR
                );
                assign_variable(
                    types.vars[PTR_VAR], 
                    surface_var, 
                    surface+vars[surface]->buffer_release, 
                    imp, 
                    p
                );

                // returning simplifcations may split the memory poiters into two independent sets of finals that reference the same memory - gather in one place
                coallesce_finals(surface+vars[surface]->buffer_ptr);
                coallesce_finals(surface+vars[surface]->buffer_release);
                finals[surface_var] = 
                        rename_var(finals[surface+vars[surface]->buffer_ptr], surface+vars[surface]->buffer_ptr, surface_var)
                        +rename_var(finals[surface+vars[surface]->buffer_release], surface+vars[surface]->buffer_release, surface_var);
                finals[surface+vars[surface]->buffer_ptr] = Code();
                finals[surface+vars[surface]->buffer_release] = Code();
            }
            else {
                assign_variable(
                    types.vars[PTR_VAR], 
                    surface_var,
                    ZERO_VAR, 
                    imp, 
                    p
                );
                finals[var] += Code(
                    token_if, var, Variable("){if((u64*)((u64*)"),var,Variable(")[2])"), // deallocate only if we have allocated any capacity
                    Variable("__runtime_free((u64*)((u64*)"),var,Variable(")[0])"),SEMICOLON_VAR,
                    Variable("__runtime_free("),var,RPAR_VAR,SEMICOLON_VAR,
                    var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR,
                    Variable("}"));
            }
            return next_var(imp, p, raw_var, types);
        }
        vector<Variable> unpacks;
        if(p>=imp->size()-1) {
            if(curry.exists()) {
                if(!contains(curry)) 
                    imp->error(first_token_pos-2, "Not found: "+pretty_var(curry.to_string())+recommend_runtype(types, curry));
                else if(vars.find(curry)->second->not_primitive()) {
                    for(const Variable& pack : vars.find(curry)->second->packs) unpacks.push_back(curry.to_string()+"__"+pack.to_string());
                }
                else 
                    unpacks.push_back(curry);
            }
        }
        else if(imp->at(p)=="__consume") {
            if(!curry.exists()) imp->error(p-2, "Unexpected usage of operator\nThere is no left-hand-side");
            if(!contains(curry)) imp->error(first_token_pos-2, "Not found: "+pretty_var(curry.to_string())+recommend_runtype(types, curry));
            else if(vars.find(curry)->second->not_primitive()) {
                for(const Variable& pack : vars.find(curry)->second->packs) 
                    unpacks.push_back(curry+pack);
            }
            else 
                unpacks.push_back(curry);
            p++;
            string next = imp->at(p++);
            Variable rhs = parse_expression(imp, p, next, types);
            if(!contains(rhs)) 
                imp->error(--p, "Failed to parse the right-hand-side of "+first_token.to_string());
            const auto& rhsType = vars.find(rhs)->second;
            if(rhsType->_is_primitive) 
                unpacks.push_back(rhs);
            else if(type->is_service) {
                Variable fail_var = create_temp();
                if(active_calls[rhs].exists() && active_calls[active_calls[rhs]].exists()) {
                    const Variable& call_var = active_calls[rhs];
                    implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
                    vars[rhs+ERR_VAR] = types.vars[ERRCODE_VAR];
                    implementation += Code(
                        call_var+ERR_VAR, 
                        ASSIGN_VAR, 
                        call_var+STATE_VAR, 
                        ARROW_VAR, 
                        ERR_VAR, 
                        SEMICOLON_VAR
                    );
                    implementation += Code(
                        rhs+ERR_VAR, 
                        ASSIGN_VAR, 
                        call_var+ERR_VAR,
                        SEMICOLON_VAR
                    );
                    static const Variable token_err1 = Variable(":\nprintf(\"Runtime error from ");
                    static const Variable token_err2 = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
                    implementation += Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
                    errors += Code(fail_var, token_err1, rhsType->name, call_var, token_err2);
                    add_preample("#include <stdio.h>");
                }
                for(size_t i=1;i<rhsType->packs.size();++i)
                    unpacks.push_back(active_calls[rhs]+rhsType->packs[i]);
                for(const auto& it : rhsType->buffer_types)
                    buffer_types[active_calls[rhs]+it.first] = it.second;
                if(active_calls[rhs].exists() && active_calls[active_calls[rhs]].exists())
                    active_calls[active_calls[rhs]] = EMPTY_VAR;
            }
            else 
                for(const Variable& pack : rhsType->packs)
                    unpacks.push_back(rhs+pack);
        }
        else if(imp->at(p)!="(" && curry.exists()) {
            if(!contains(curry)) 
                imp->error(first_token_pos-2, "Not found: "
                    +pretty_var(curry.to_string())
                    +recommend_runtype(types, curry)
                );
            else if(vars.find(curry)->second->not_primitive()) {
                for(const Variable& pack : vars.find(curry)->second->packs) 
                    unpacks.push_back(curry.to_string()+"__"+pack.to_string());
            }
            else unpacks.push_back(curry);
        }
        else if(imp->at(p)==")" || imp->at(p)=="]" || imp->at(p)=="," || imp->at(p)==":"){// || imp->at(p)=="and" || imp->at(p)=="or" 
            //|| types.vars.find(imp->at(p))!=types.vars.end() || (imp->at(p)=="-" && p<imp->size()-1 && (imp->at(p+1)=="-" || imp->at(p+1)==">"))) {
            int num_choices = 0;
            int highest_choice_power = 0;
            if(parametric_types.find(type->name)!=parametric_types.end()) 
                type = parametric_types[type->name];
            string candidates("");
            for(const auto& option : type->get_options(types)) {
                if(option->choice_power>highest_choice_power) {
                    highest_choice_power = option->choice_power;
                    num_choices = 0;
                    candidates = "";
                }
                if(option->choice_power<highest_choice_power) 
                    continue;
                num_choices ++;
                type = option;
                candidates += "\n"+option->signature(types);
            }

            if(num_choices==0) 
                imp->error(--p, "Overloaded or union runtype has no alternative");
            if(num_choices!=1) {
                if(!highest_choice_power) 
                    imp->error(--p, "Overloaded or union runtype names are ambiguous."
                        "\nConsider defining exactly one of them as nominal (with nom first argument)"
                        "\nto break the priority stalemate."
                        "\nCandidates:"+candidates
                    );
                else 
                    imp->error(--p, "Overloaded or union runtype names are ambiguous."
                        "\nYou have already defined several of those as nominal (with nom first argument)."
                        "\nCandidates:"+candidates
                    );
            }
            
            if(type->not_primitive()) for(size_t i=0;i<type->args.size();++i) {
                Variable var = create_temp();
                if(p<imp->size()-1 && imp->at(p+1)=="&") 
                    mutables.insert(var);
                assign_variable(type->args[i].type, var+type->args[i].name, ZERO_VAR, imp, first_token_pos, true);
                type_trackers.insert(var);
                unpacks.push_back(var+type->args[i].name);
            }
            else {
                string var = create_temp();
                if(p<imp->size()-1 && imp->at(p+1)=="&") 
                    mutables.insert(var);
                assign_variable(type, var, ZERO_VAR, imp, first_token_pos, true);
                type_trackers.insert(var);
                unpacks.push_back(var);
            }
        }
        else if(((p<imp->size()-1 && imp->at(p)!="(" && (imp->at(p+1)==")" || imp->at(p+1)==",")) || (p<imp->size()-2 && imp->at(p)=="&" && imp->at(p+1)!="(" && (imp->at(p+2)==")" || imp->at(p+2)==",")))){
            Variable var = imp->at(p++);
            if(var==REF_VAR) {
                var = imp->at(p++);
                mutables.insert(var);
            }
            if(contains(var)) 
                imp->error(--p, "Cannot redeclare local variable "+vars[var]->name.to_string()+" "+pretty_var(var.to_string()));
            if(parametric_types.find(type->name)!=parametric_types.end()) 
                type = parametric_types[type->name];
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
            if(num_choices==0) 
                imp->error(--p, "Overloaded or union runtype has no alternative");
            if(num_choices!=1) {
                if(!highest_choice_power) 
                    imp->error(--p, "Overloaded or union runtype names are ambiguous."
                        "\nConsider defining exactly one of them as nominal (with nom first argument)"
                        "\nto break the priority stalemate."
                        "\nCandidates:"+candidates
                    );
                else 
                    imp->error(--p, "Overloaded or union runtype names are ambiguous."
                        "\nYou have already defined several of those as nominal (with nom first argument)."
                        "\nCandidates:"+candidates
                    );
            } 
            if(type->not_primitive()) 
                for(size_t i=0;i<type->args.size();++i) {
                    vars[var+type->args[i].name] = type->args[i].type;
                    unpacks.push_back(var+type->args[i].name);
                }
            else 
                unpacks.push_back(var);
            if(type->args.size() && type->args[0].type->name==NOM_VAR) 
                alignments[var+type->args[0].name] = types.alignment_labels[type.get()];
            vars[var] = type;
            return var;
        }
        else if(imp->at(p)!="(") {
            Variable var = create_temp();
            vars[var] = type;
            type_trackers.insert(var);
            if(p<imp->size()-1 && imp->at(p+1)=="&") 
                mutables.insert(var);
            for(const Variable& pack : type->packs) 
                assign_variable(type->vars[pack], var+pack, ZERO_VAR, imp, first_token_pos);
            if(type->args.size() && type->args[0].type->name==NOM_VAR) 
                alignments[var+type->args[0].name] = types.alignment_labels[type.get()];
            return next_var(imp, p, var, types);
        }
        else {
            if(imp->at(p++)!="(") 
                imp->error(--p, "Expecting opening parenthesis");
            unpacks = gather_tuple(imp, p, types, curry);
            if(imp->at(p++)!=")") 
                imp->error(--p, "Expecting closing parenthesis");
        }
        return call_type(imp, p, type, unpacks, first_token_pos, first_token, types);
    }
    if(curry.exists() || (p<imp->size() && (imp->at(p)=="(" || imp->at(p)=="__consume"))) 
        imp->error(--p, "Missing runtype: "
            +first_token.to_string()
            +recommend_runtype(types, first_token)
        );
    return next_var(imp, p, first_token, types);
}
