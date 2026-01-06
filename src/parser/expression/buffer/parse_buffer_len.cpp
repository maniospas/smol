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
#include "../../../def.h"


Variable Def::parse_buffer_len(size_t& p, Types& types, Variable curry) {
    if(active_calls[curry].exists() && active_calls[active_calls[curry]].exists()) {
        static const Variable token_print = Variable(":\n__result__error_code=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
        const Variable& call_var = active_calls[curry];
        implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
        vars[curry+ERR_VAR] = types.vars[ERRCODE_VAR];
        implementation += Code(
            call_var+ERR_VAR, 
            ASSIGN_VAR, 
            call_var+STATE_VAR, 
            ARROW_VAR, 
            ERR_VAR, 
            SEMICOLON_VAR
        );
        implementation += Code(
            curry+ERR_VAR, 
            ASSIGN_VAR, 
            call_var+ERR_VAR,
            SEMICOLON_VAR
        );
        Variable fail_var = create_temp();
        vars[fail_var] = types.vars[LABEL_VAR];
        implementation += Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
        errors.insert(Code(fail_var, token_print));
        add_preamble("#include <stdio.h>");
        if(active_calls[curry].exists() && active_calls[active_calls[curry]].exists()) 
            active_calls[active_calls[curry]] = EMPTY_VAR;
    }
    
    curry = curry+Variable("dynamic");
    vars[Variable("__buffer_size")] = types.vars[Variable("u64")];
    implementation += Code(
        Variable("__buffer_size"), 
        ASSIGN_VAR, 
        curry,
        Variable("?"),
        Variable("((u64*)"), 
        curry, 
        Variable(")[1]:0"), 
        SEMICOLON_VAR
    );
    if(imp->at(p++)!="(")
        imp->error(--p, "Expected opening parenthesis");
    if(imp->at(p++)!=")")
        imp->error(--p, "Expected closing parenthesis");
    return next_var(p, Variable("__buffer_size"), types);
}