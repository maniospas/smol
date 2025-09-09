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

Variable Def::next_var_and(Variable next, const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test) {
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
    next = parse_expression(i, p, imp->at(p++), types);
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