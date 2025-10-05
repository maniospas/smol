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


Variable Def::parse_on(size_t& p, Types& types, Variable curry, size_t first_token_pos) {
    if(curry.exists()) 
        imp->error(p, "Cannot curry onto `on`");
    // if(active_context.exists()) 
    //     imp->error(p, "There is already an active `on` context\nEnclose this within a scope per `scope on ... end`.");
    string next = imp->at(p++);
    active_context = EMPTY_VAR;
    active_context = parse_expression(p,next,types,curry);
    if(!active_context.exists() || !contains(active_context))
        imp->error(first_token_pos, "Expression does not evaluate to a variable to use as `on` context");
    if(vars[active_context]->noassign && !imp->allow_unsafe)
        imp->error(first_token_pos, "Cannot use `on` context a variable marked as @noassign\nThis is considered unsafe behavior and can only be enabled with @unsafe");
    // Variable temp = create_temp();
    // Variable finally_var = temp+Variable("on");
    // vars[finally_var] = types.vars[LABEL_VAR];
    // //int on_start = p-1;
    // // uplifting_targets.push_back(finally_var);
    // // if(uplifiting_is_loop.size()) 
    // //     uplifiting_is_loop.push_back(uplifiting_is_loop.back());
    // // else 
    // //     uplifiting_is_loop.push_back(false);
    // uplifting.emplace_back(finally_var, uplifting.size(), false, uplifting.size() && uplifting.back().is_loop);
    // parse(imp, p, types, false);
    // // uplifting_targets.pop_back();
    // // uplifiting_is_loop.pop_back();
    // uplifting.pop_back();
    // p++;
    // Variable var = finally_var+Variable("r");
    // if(!contains(var)) 
    //     var = EMPTY_VAR;
    // implementation +=Code(finally_var,COLON_VAR);
    // active_context = EMPTY_VAR;
    // return var;
    return active_context;
}