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


Variable Def::parse_if(size_t& p, Types& types, Variable curry, size_t first_token_pos) {
    auto temp = Variable{create_temp()};
    auto finally_var = temp+IF_VAR;
    auto closeif_var = temp+FI_VAR;
    // uplifting_targets.push_back(finally_var);
    // if(uplifiting_is_loop.size())
    //     uplifiting_is_loop.push_back(uplifiting_is_loop.back());
    // else 
    //     uplifiting_is_loop.push_back(false);
    uplifting.emplace_back(finally_var, uplifting.size(), false, uplifting.size() && uplifting.back().is_loop);
    if(uplifting.size()>=2)
        uplifting[uplifting.size()-1].context = uplifting[uplifting.size()-2].context;
    vars[finally_var] = types.vars[LABEL_VAR];
    vars[closeif_var] = types.vars[LABEL_VAR];
    auto next = imp->at(p++);
    auto var = parse_expression(p, next, types, curry);
    if(!contains(var)) 
        imp->error(--p, "`if` condition did not evaluate to anything");
    if(vars.find(var)->second!=types.vars[BOOL_VAR]) 
        imp->error(--p, "`if` expects bool condition but got "
            +vars.find(var)->second->name.to_string()
            +" "+pretty_var(var.to_string())
        );
    implementation += Code(token_ifnot,var,token_goto,closeif_var,SEMICOLON_VAR);
    if(p<imp->size()-1 && imp->at(p)=="then" && imp->at(p+1)=="ok")
        imp->error(first_token_pos, "Empty code block");
    parse(imp, p, types, false);
    p++; // offset p-- after parse_return above
    auto else_var = EMPTY_VAR;
    auto rfinally_var = finally_var+Variable("r");

    bool has_else = false;
    auto else_skip = temp+EL_VAR;
    if(p<imp->size()-1 && imp->at(p)=="else") {
        has_else = true;
        if(uplifting.size() && uplifting[uplifting.size()-1].has_returned && contains(uplifting[uplifting.size()-1].target+Variable("r")))
            imp->error(p, "You have already returned from `if`, so an `else` block is redundant here");
        next = imp->at(++p); // keep the ++ if not in elif

        if(p<imp->size()-1 && next=="then" && imp->at(p+1)=="ok")
            imp->error(first_token_pos, "Empty code block");
        // if(next=="elif") {
        //     next = imp->at(++p);
        //     p++;
        //     auto elif_var = parse_expression(p, next, types, curry);
        //     if(!contains(elif_var)) 
        //         imp->error(--p, "`elif` condition did not evaluate to anything");
        //     if(vars.find(elif_var)->second!=types.vars[BOOL_VAR]) 
        //         imp->error(--p, "`elif` expects bool condition but got "
        //             +vars.find(elif_var)->second->name.to_string()
        //             +" "+pretty_var(var.to_string())
        //         );
        //     implementation += Code(token_ifnot,elif_var,token_goto,closeif_var,SEMICOLON_VAR);
        // }
        else_var = temp+LE_VAR;
        auto relse_var = else_var+Variable("r");
        vars[else_var] = types.vars[LABEL_VAR];
        vars[else_skip] = types.vars[LABEL_VAR];
        uplifting.pop_back();
        uplifting.emplace_back(else_var, uplifting.size(), false, uplifting.size() && uplifting.back().is_loop);
        if(uplifting.size()>=2)
            uplifting[uplifting.size()-1].context = uplifting[uplifting.size()-2].context;
        implementation += Code(finally_var,COLON_VAR,Variable("goto"), else_skip, SEMICOLON_VAR, closeif_var, COLON_VAR);
        parse(imp, p, types, false);
        p++; // offset p-- after parse_return above
        implementation += Code(else_var,COLON_VAR);
        if(contains(relse_var) && !contains(rfinally_var)) 
            imp->error(first_token_pos, "There was a non-empty return "
                +vars[relse_var]->name.to_string()
                +" `else` but no such value from `if`"
            );
        if(!contains(relse_var) && contains(rfinally_var)) 
            imp->error(first_token_pos, "There was a non-empty return "
                +vars[rfinally_var]->name.to_string()
                +" `if` but no such value from `else` "
            );
        if(contains(relse_var) && contains(rfinally_var)) {
            if(vars[rfinally_var]!=vars[relse_var]) 
                imp->error(first_token_pos, "There were mismatching return "
                    +vars[rfinally_var]->name.to_string()
                    +" `if` and "+vars[relse_var]->name.to_string()+" `else`"
                );
            assign_variable(
                vars[rfinally_var], 
                rfinally_var, 
                relse_var, 
                first_token_pos, 
                false, 
                false
            );
        }
    }
    if(has_else) 
        implementation += Code(else_skip,COLON_VAR);
    else
        implementation += Code(finally_var,COLON_VAR,closeif_var,COLON_VAR);
    // uplifting_targets.pop_back();
    // uplifiting_is_loop.pop_back();
    uplifting.pop_back();
    if(contains(rfinally_var)) {
        if(else_var.exists()==0) 
            imp->error(first_token_pos, "There was a non-empty return "
                +vars[rfinally_var]->name.to_string()
                +" `if` but no `else` statement for the alternative"
            ); 
        return rfinally_var;
    }
    return EMPTY_VAR;
}