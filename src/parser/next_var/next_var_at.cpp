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

Variable Def::next_var_at(Variable next, const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test) {
    if(!internalTypes.contains(next)) 
        imp->error(--p, "Not found: "
            +pretty_var(next.to_string())
            +recommend_variable(types, next)
        );
    ++p;
    Variable arg = parse_expression(i, p, imp->at(p++), types);
    if(!internalTypes.contains(arg)) 
        imp->error(--p, "Not found: "
            +pretty_var(arg.to_string())
            +recommend_variable(types, next)
        );
    string end("");
    string method("at");
    if(imp->at(p)=="to") {
        p++;
        method = "slice";
        end = parse_expression(i, p, imp->at(p++), types).to_string();
        if(!internalTypes.contains(end)) 
            imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
    }
    else if(imp->at(p)=="upto") {
        if(internalTypes.vars[arg]->name!=U64_VAR) 
            imp->error(--p, "Expected u64 but found: "
                +internalTypes.vars.find(arg)->second->name.to_string()
                +" "+pretty_var(arg.to_string())
                +"\nYou can only use element access [pos] or non-inclusive"
                +" `to` ranges [pos to end] for non-u64 pos."
            );
        p++;
        end = parse_expression(i, p, imp->at(p++), types).to_string();
        if(!internalTypes.contains(end)) 
            imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
        if(internalTypes.vars[end]->name!=U64_VAR) 
            imp->error(--p, "Expected u64 but found: "
                +internalTypes.vars.find(end)->second->name.to_string()
                +" "+pretty_var(end)
                +"\nYou can only use `upto` with u64. Move to `to`"
                +" bounds for other end index runtypes."
            );
        method = "slice";
        string tmp = create_temp();
        assign_variable(internalTypes.vars[end], tmp, end, imp, p);
        implementation += Code(
            tmp,
            ASSIGN_VAR,
            tmp,
            token_plus_one,
            SEMICOLON_VAR
        );
        end = tmp;
    }
    else if(imp->at(p)=="lento") {
        if(internalTypes.vars[arg]->name!=U64_VAR) 
            imp->error(--p, "Expected u64 but found: "
                +internalTypes.vars.find(arg)->second->name.to_string()
                +" "+pretty_var(arg.to_string())
                +"\nYou can only use element access [pos] or non-inclusive `to`"
                +" ranges [pos to end] for non-u64 pos."
            );
        p++;
        end = parse_expression(i, p, imp->at(p++), types).to_string();
        if(!internalTypes.contains(end)) 
            imp->error(--p, "Not found: "
                +pretty_var(end)
                +recommend_variable(types, next)
            );
        if(internalTypes.vars[end]->name!=U64_VAR) 
            imp->error(--p, "Expected u64 but found: "
                +internalTypes.vars.find(end)->second->name.to_string()+" "+pretty_var(end)
                +"\nYou can only use `lento` with u64. Move to `to`"
                +" bounds for other end index runtypes."
            );
        method = "slice";
        Variable tmp = create_temp();
        assign_variable(internalTypes.vars[end], tmp, end, imp, p);
        implementation += Code(tmp,ASSIGN_VAR,tmp,PLUS_VAR,arg,SEMICOLON_VAR);
        end = tmp.to_string();
    }
    if(!types.contains(method)) 
        imp->error(--p, "No implementation for "+method);
    Type type = types.vars[method];
    vector<Variable> unpacks;

    if(active_calls[next].exists()) {
        if(active_calls[active_calls[next]].exists()) {
            static const Variable token_print = Variable(":\nprintf(\"Runtime error from");
            static const Variable token_failsafe = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
            const Variable& call_var = active_calls[next];
            implementation += Code(
                Variable("__smolambda_task_wait"),\
                LPAR_VAR,
                call_var+TASK_VAR,
                RPAR_VAR,
                SEMICOLON_VAR
            );
            internalTypes.vars[next+ERR_VAR] = types.vars[ERRCODE_VAR];
            implementation += Code(
                call_var+ERR_VAR, 
                ASSIGN_VAR, 
                call_var+STATE_VAR, 
                ARROW_VAR, 
                ERR_VAR, 
                SEMICOLON_VAR
            );
            implementation += Code(
                next+ERR_VAR, 
                ASSIGN_VAR, 
                call_var+ERR_VAR,
                SEMICOLON_VAR
            );
            Variable fail_var = create_temp();
            internalTypes.vars[fail_var] = types.vars[LABEL_VAR];
            implementation += Code(
                token_if, 
                call_var+ERR_VAR, 
                token_goto, 
                fail_var, 
                SEMICOLON_VAR
            );
            errors += Code(
                fail_var, 
                token_print, 
                internalTypes.vars[next]->name, 
                call_var, 
                token_failsafe
            );
            add_preample("#include <stdio.h>");
        }
        if(active_calls[next].exists() && active_calls[active_calls[next]].exists()) 
            active_calls[active_calls[next]] = EMPTY_VAR;
    }

    if(internalTypes.vars[next]->not_primitive()) 
        for(const Variable& pack : internalTypes.vars[next]->packs) 
            unpacks.push_back(next+pack);
    else 
        unpacks.push_back(next);
    unpacks.push_back(arg);
    if(end.size()) 
        unpacks.push_back(end);
    string inherit_buffer = "";
    next = call_type(i, p, type, unpacks, p-1, method, types);
    if(imp->at(p++)!="]") 
        imp->error(--p, "Expecting : or closing square bracket");
    return next;
}