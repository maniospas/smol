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

Variable Def::next_var_and(Variable next, size_t& p, Types& types) {
    if(active_calls[next].exists() && active_calls[active_calls[next]].exists()) {
        static const Variable token_print = Variable(":\n__result__error_code=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
        const Variable& call_var = active_calls[next];
        implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
        vars[next+ERR_VAR] = types.vars[ERRCODE_VAR];
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
        vars[fail_var] = types.vars[LABEL_VAR];
        implementation += Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
        errors.insert(Code(fail_var, token_print));
        add_preamble("#include <stdio.h>");
        if(active_calls[next].exists() && active_calls[active_calls[next]].exists()) 
            active_calls[active_calls[next]] = EMPTY_VAR;
    }
    
    if(!contains(next)) 
        imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
    if(vars[next]!=types.vars[BOOL_VAR]) 
        imp->error(--p, "Left hand side of `and` expected bool but got "
            +vars[next]->name.to_string()
            +" "+pretty_var(next.to_string())
        );
    ++p;
    Variable prev = next;
    Variable tmp = create_temp();
    vars[tmp] = types.vars[LABEL_VAR];
    implementation +=Code(
        token_ifnot, 
        next, 
        token_goto, 
        tmp, 
        SEMICOLON_VAR
    );
    next = parse_expression(p, imp->at(p++), types);
    if(!contains(next)) 
        imp->error(--p, "Unknown symbol "
            +pretty_var(next.to_string())
        );
    if(vars[next]!=types.vars[BOOL_VAR]) 
        imp->error(--p, "Right hand side of `and` expected bool but got "
            +vars[next]->name.to_string()
            +" "+pretty_var(next.to_string())
        );
    implementation += Code(
        prev,
        ASSIGN_VAR,
        next,
        SEMICOLON_VAR,
        tmp,
        COLON_VAR
    );
    next = prev;
    return next;
}