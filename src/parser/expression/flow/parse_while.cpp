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


Variable Def::parse_while(size_t& p, Types& types, Variable curry, size_t first_token_pos) {
    Variable temp = create_temp();
    Variable finally_var = temp+WHILE_VAR;
    uplifting_targets.push_back(finally_var);
    uplifiting_is_loop.push_back(true);
    Variable start_var = temp+LOOP_VAR;
    vars[start_var] = types.vars[LABEL_VAR];
    vars[finally_var] = types.vars[LABEL_VAR];
    implementation +=Code(start_var,COLON_VAR);
    Variable next = imp->at(p++);
    Variable var = parse_expression(p, next, types, curry);
    if(!contains(var)) 
        imp->error(first_token_pos, "Expression did not evaluate to anything");
    if(vars.find(var)->second!=types.vars[BOOL_VAR]) 
        imp->error(--p, "While expects bool condition but got "
            +vars.find(var)->second->name.to_string()
            +" "+pretty_var(var.to_string())
        );
    implementation += Code(token_ifnot,var,token_goto,finally_var,SEMICOLON_VAR);
    parse(imp, p, types, false);
    p++; // offset p-- after parse_return above
    implementation += Code(Variable("goto"),start_var,SEMICOLON_VAR,finally_var,COLON_VAR);
    uplifting_targets.pop_back();
    uplifiting_is_loop.pop_back();
    return EMPTY_VAR;
}