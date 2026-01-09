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

size_t get_precedence_level(const std::string& name) {
    static const std::unordered_map<std::string, size_t> prec {
        {".", 0},
        {"mul", 1},
        {"div", 1},
        {"mod", 1},
        {"add", 2},
        {"sub", 2},
        {"lt", 3},
        {"gt", 3},
        {"leq", 3},
        {"geq", 3},
        {"eq", 4},
        {"neq", 4},
    };
    auto it = prec.find(name);
    if (it != prec.end())
        return it->second;
    return 10000;
}


Variable Def::parse_runtype(size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos) {
    auto type = types.contains(first_token)?types.vars.find(first_token)->second:(first_token==name?shared_from_this():nullptr);
    if(!type)
        imp->error(--p, "Unknown type: "
            +pretty_runtype(first_token.to_string())
            +recommend_runtype(types, first_token)
        );
    if(type.get()==this && options.size()==0) {
        if(!is_service)
            imp->error(--p, "def definition cannot return itself\nConsider converting it to a service or use a previous runtype.");
        if(!uplifting[0].has_returned)
            imp->error(--p, "Service has not yet returned\nFor a runtype to call itself, a previous return needs to have determined its format");
        options.push_back(shared_from_this());
    }
    if(p<imp->size()-1 && imp->at(p)=="[" && !curry.exists()) {
        p++;
        return parse_buffer_create(p, first_token, types, curry, first_token_pos, type);
    }
    vector<Variable> unpacks;
    bool autoreduce = false;
    if(p>=imp->size()-1) {
        if(curry.exists()) {
            if(!contains(curry)) 
                imp->error(first_token_pos-2, "Not found: "
                    +pretty_var(curry.to_string())
                    +recommend_runtype(types, curry)
                );
            else if(vars.find(curry)->second->not_primitive()) {
                for(const Variable& pack : vars.find(curry)->second->packs) 
                    unpacks.push_back(curry+pack);
            }
            else 
                unpacks.push_back(curry);
        }
    }
    else if(imp->at(p)=="__consume") {
        auto current_operator = imp->at(p-1);
        auto operation_pos = p-1;
        if(!curry.exists()) imp->error(p-2, "Unexpected usage of operator\nThere is no left-hand-side");
        if(!contains(curry)) imp->error(first_token_pos-2, "Not found: "+pretty_var(curry.to_string())+recommend_runtype(types, curry));
        else if(vars.find(curry)->second->not_primitive()) {
            for(const Variable& pack : vars.find(curry)->second->packs) 
                unpacks.push_back(curry+pack);
        }
        else 
            unpacks.push_back(curry);
        p++;
        auto next = imp->at(p++);
        if(!operator_precedence.size()) operator_precedence.emplace_back(0);
        if(operator_precedence[operator_precedence.size()-1]) {
            auto precedence_at = imp->at(operator_precedence[operator_precedence.size()-1]);
            auto prev_precedence_level = get_precedence_level(precedence_at);
            auto current_precendence_level = get_precedence_level(current_operator);
            if(prev_precedence_level<=current_precendence_level)
                imp->error(operation_pos, "Ambiguous operator precedence\n"
                    "Smoλ's parsing of operators is left-to-right, "
                    "meaning that this operator would be parsed within the last "+imp->at(operator_precedence[operator_precedence.size()-1])+
                    "'s argument. However this operator contradicts the assumed mathematical notation by having lower "
                    "or the same precedence than a PREVIOUS one. "
                    "Consider adjusting operant order, or add parentheses from the start of the expression till this point to make the "
                    "expected behavior explicit."
                );
        }
        operator_precedence[operator_precedence.size()-1] = operation_pos;
        Variable rhs = parse_expression(p, next, types);
        operator_precedence[operator_precedence.size()-1] = 0;
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
                static const Variable token_print = Variable(":\n__result__error_code=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
                implementation += Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
                errors.insert(Code(fail_var, token_print));
                add_preamble("#include <stdio.h>");
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
        imp->error(first_token_pos-2, "Not found: "
            +pretty_var(curry.to_string())
            +recommend_runtype(types, curry)
        );
        // if(!contains(curry)) 
        //     imp->error(first_token_pos-2, "Not found: "
        //         +pretty_var(curry.to_string())
        //         +recommend_runtype(types, curry)
        //     );
        // else if(vars.find(curry)->second->not_primitive()) {
        //     for(const Variable& pack : vars.find(curry)->second->packs) 
        //         unpacks.push_back(curry.to_string()+"__"+pack.to_string());
        // }
        // else unpacks.push_back(curry);
    }
    else if(imp->at(p)==")" || imp->at(p)=="]" || imp->at(p)=="," 
        //|| imp->at(p)==":" 
        //|| (imp->at(p)=="." && p<imp->size()-2 && imp->at(p+2)=="(")
        || (imp->at(p)=="." && p<imp->size()-2 && imp->at(p+2)=="(")
        || (imp->at(p)=="." && p<imp->size()-2 && imp->at(p+2)=="__consume")
        || (imp->at(p)=="." && imp->at(p+1)=="if")
        || (imp->at(p)=="." && imp->at(p+1)=="on")
        || (imp->at(p)=="." && imp->at(p+1)=="while")
    ){// || imp->at(p)=="and" || imp->at(p)=="or" 
        //|| types.vars.find(imp->at(p))!=types.vars.end() || (imp->at(p)=="-" && p<imp->size()-1 && (imp->at(p+1)=="-" || imp->at(p+1)==">"))) {
        int num_choices = 0;
        int highest_choice_power = 0;
        if(parametric_types.find(type->name)!=parametric_types.end()) 
            type = parametric_types[type->name];
        string candidates("");
        for(const auto& option : type->get_options()) {
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
                    "\nConsider defining exactly one of them as new (with nom first argument)"
                    "\nto break the priority stalemate."
                    "\nCandidates:"+candidates
                );
            else 
                imp->error(--p, "Overloaded or union runtype names are ambiguous."
                    "\nYou have already defined several of those as new (with nom first argument)."
                    "\nCandidates:"+candidates
                );
        }

        if(type->nozero && !imp->allow_unsafe)
            imp->error(--p, "Cannot create empty runtype marked as @c_nozero"
                "\nThe runtype definition is marked as @c_nozero or contains such data."
                " That annotation makes empty ('zero') initialization to be considered unsafe."
                " Mark this file @unsafe to enable this option."
            );
        
        if(type->not_primitive()) 
            for(size_t i=0;i<type->args.size();++i) {
                Variable var = create_temp();
                if(p<imp->size()-1 && imp->at(p+1)=="&") 
                    mutables.insert(var);
                assign_variable(type->args[i].type, var+type->args[i].name, ZERO_VAR, first_token_pos, true);
                type_trackers.insert(var);
                unpacks.push_back(var+type->args[i].name);
            }
        else {
            string var = create_temp();
            if(p<imp->size()-1 && imp->at(p+1)=="&") 
                mutables.insert(var);
            assign_variable(type, var, ZERO_VAR, first_token_pos, true);
            type_trackers.insert(var);
            unpacks.push_back(var);
        }
    }
    else if(((p<imp->size()-1 
        && imp->at(p)!="(" 
        && (imp->at(p+1)==")" || imp->at(p+1)==",")) 
            || (p<imp->size()-2 && imp->at(p)=="&" && imp->at(p+1)!="(" && (imp->at(p+2)==")" || imp->at(p+2)==",")))
    ){
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
        for(const auto& option : type->get_options()) {
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
            imp->error(--p, "Function has no alternative");
        if(num_choices!=1) {
            if(!highest_choice_power) 
                imp->error(--p, "Type names are ambiguous."
                    "\nConsider defining exactly one of them as new (with nom first argument)"
                    " to break the priority stalemate."
                    " Candidates:"+candidates
                );
            else 
                imp->error(--p, "Type names are ambiguous."
                    " You have already defined several of those as new (with nom first argument)."
                    " Candidates:"+candidates
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
        if(type->nozero && !imp->allow_unsafe)
            imp->error(--p, "Cannot create empty type for: "
                +pretty_runtype(type->name.to_string())
                +"\nThe type's function definition is marked as `@c_nozero` or returns such data."
                " That annotation makes empty ('zero') initialization to be considered unsafe."
                " Mark this file @unsafe to enable this option."
            );
        Variable var = create_temp();
        vars[var] = type;
        type_trackers.insert(var);
        if(p<imp->size()-1 && imp->at(p+1)=="&") 
            mutables.insert(var);
        for(const Variable& pack : type->packs) 
            assign_variable(type->vars[pack], var+pack, ZERO_VAR, first_token_pos);
        if(type->args.size() && type->args[0].type->name==NOM_VAR) 
            alignments[var+type->args[0].name] = types.alignment_labels[type.get()];
        return next_var(p, var, types);
    }
    else {
        if(imp->at(p++)!="(") 
            imp->error(--p, "Expecting opening parenthesis");
        autoreduce = imp->at(p)=="@" && imp->at(p+1)=="all";
        unpacks = gather_tuple(p, types, curry);
        if(imp->at(p++)!=")") 
            imp->error(--p, "Expecting closing parenthesis");
    }
    if(!autoreduce)
        return call_type(p, type, unpacks, first_token_pos, first_token, types, false);

    auto leftover_unpacks_size = unpacks.size();
    auto ret = EMPTY_VAR;
    auto prev_type = type;
    while(true) {
        //cout << signature_like(types, unpacks) << "\n";
        type = prev_type; // type is modified by the call
        ret = call_type(p, type, unpacks, first_token_pos, first_token, types, true);
        if(!unpacks.size()) return ret;
        if(ret.exists())
            for(size_t i=0;i<vars[ret]->packs.size();++i)
                unpacks.insert(unpacks.begin()+i, ret+vars[ret]->packs[i]);
        leftover_unpacks_size--;
        if(leftover_unpacks_size<=0) 
            imp->error(first_token_pos, "Reduction via @all is too slow"
                "\nThe reduction's converge to a stable state is too stable for this function; perhaps it never converges."
            );
    }

    return ret;
}