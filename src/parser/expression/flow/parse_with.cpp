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


Variable Def::parse_with(size_t& p, Types& types, Variable curry, size_t first_token_pos) {
    // TODO: this implementation does not account for nesting
    auto temp = Variable{create_temp()};
    auto finally_var = temp+Variable("with");
    auto numberOfCandidates = 0;
    auto overloading_errors = string{""};
    auto competing = string{""};
    auto with_start = p-1;
    // uplifting_targets.push_back(finally_var);
    // if(uplifiting_is_loop.size()) 
    //     uplifiting_is_loop.push_back(uplifiting_is_loop.back());
    // else 
    //     uplifiting_is_loop.push_back(false);
    uplifting.emplace_back(finally_var, uplifting.size(), false, uplifting.back().is_loop);
    vars[finally_var] = types.vars[LABEL_VAR];
    auto next = string{""};
    try {
        if(curry.exists()) 
            imp->error(first_token_pos, "Cannot have a curry onto `with`.");
        parse(nullptr, p, types, false);
        p++;
        next = imp->at(p++);
        numberOfCandidates++;
        implementation += Code(Variable("goto"),finally_var,SEMICOLON_VAR);
        if(numberOfCandidates) 
            competing = "\n"+imp->tokens[with_start].show();
    }
    catch (const runtime_error& e) {
        string what = e.what();
        if(what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found" 
            && (what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found")
        ) 
            throw e;
        if(Def::lsp) 
            overloading_errors += "\n";
        else overloading_errors += "\n- ";
        overloading_errors += what;
        end_block(p);
        next = imp->at(p++);
        if(next!="else") 
            imp->error(with_start, "`with` with no `else`\nCan guard parametric types but is a code smell otherwise\nHere it is redundant as enclosed code always succeeds");
    }
    while(next=="else") {
        if(!numberOfCandidates) {
            try {
                size_t else_start = p-1;
                parse(nullptr, p, types, false);
                numberOfCandidates++;
                implementation += Code(Variable("goto"), finally_var, SEMICOLON_VAR);
                ++p;
                if(numberOfCandidates) 
                    competing = "\n"+imp->tokens[else_start].show();
            }
            catch (const std::runtime_error& e) {
                string what = e.what();
                if(what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found") 
                    throw e;
                if(Def::lsp) 
                    overloading_errors += "\n";
                else 
                    overloading_errors += "\n- ";
                overloading_errors += what;
                end_block(p);
            }
        }
        else 
            end_block(p);
        next = p<imp->size()?imp->at(p):"";
        p++;
    }
    p--;
    if(numberOfCandidates>1) 
        ERROR("Competes with previous branch of `with`"+competing);
    if(numberOfCandidates==0) 
        imp->error(with_start, "No valid branch of `with`"+string(Def::lsp?"\n```rust":"")+overloading_errors+(Def::lsp?"\n```\n":""));

    implementation += Code(finally_var,COLON_VAR);
    uplifting.pop_back();
    // uplifting_targets.pop_back();
    // uplifiting_is_loop.pop_back();
    return EMPTY_VAR;

}