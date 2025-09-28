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


vector<Variable> Def::gather_tuple(size_t& p, Types& types, const Variable& curry) {
    static const Variable token_print = Variable(":\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");

    vector<Variable> ret;
    if(curry.exists()) {
        Variable var = curry;
        if(!contains(var)) 
            imp->error(p, "Not found: "
                +pretty_var(var.to_string())
                +recommend_variable(types, var)
            );
        const auto& type = vars.find(var)->second;
        if(!type->not_primitive()) 
            ret.push_back(var);
        else if(type->is_service) {
            if(active_calls[var].exists() && active_calls[active_calls[var]].exists()) {
                const Variable& call_var = active_calls[var];
                implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
                vars[var+ERR_VAR] = types.vars[ERRCODE_VAR];
                implementation += Code(
                    call_var+ERR_VAR, 
                    ASSIGN_VAR, 
                    call_var+STATE_VAR, 
                    ARROW_VAR, 
                    ERR_VAR, 
                    SEMICOLON_VAR
                );
                implementation += Code(
                    var+ERR_VAR, 
                    ASSIGN_VAR, 
                    call_var+ERR_VAR,
                    SEMICOLON_VAR
                );
                Variable fail_var = create_temp();
                vars[fail_var] = types.vars[LABEL_VAR];
                implementation += Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
                errors.insert(Code(fail_var, token_print));
                add_preample("#include <stdio.h>");
            }
            for(size_t i=1;i<type->packs.size();++i) 
                ret.push_back(active_calls[var]+type->packs[i]);
            if(active_calls[var].exists() && active_calls[active_calls[var]].exists()) 
                active_calls[active_calls[var]] = EMPTY_VAR;
        }
        else 
            for(const Variable& pack : type->packs) 
                ret.push_back(var+pack);
        string next = imp->at(p);
        if(next==")") 
            return ret;
    }
    while(true) {
        size_t expression_start = p;
        string next = imp->at(p++);
        if(next==")") {
            --p;
            break;
        }
        Variable var = parse_expression(p, next, types);
        if(!contains(var)) 
            imp->error(expression_start, "Failed to parse expression");
        const auto& type = vars[var];
        if(!type->not_primitive()) 
            ret.push_back(var);
        else if(type->is_service) {
            if(active_calls[var].exists() && active_calls[active_calls[var]].exists()) {
                const Variable& call_var = active_calls[var];
                implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
                implementation += Code(var+ERR_VAR, ASSIGN_VAR, call_var+STATE_VAR, ARROW_VAR, ERR_VAR, SEMICOLON_VAR);
                Variable fail_var = create_temp();
                vars[fail_var] = types.vars[LABEL_VAR];
                implementation +=Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
                errors.insert(Code(fail_var, token_print));
                add_preample("#include <stdio.h>");
            }
            for(size_t i=1;i<type->packs.size();++i) 
                ret.push_back(active_calls[var]+type->packs[i]);
            if(active_calls[var].exists() && active_calls[active_calls[var]].exists()) 
                active_calls[active_calls[var]] = EMPTY_VAR;
        }
        else 
            for(const Variable& pack : type->packs)
                ret.push_back(var+pack);
        next = imp->at(p++);
        if(next==")") {
            --p;
            break;
        }
        if(next!=",") 
            imp->error(--p, "Missing comma");
    }
    return ret;
}
