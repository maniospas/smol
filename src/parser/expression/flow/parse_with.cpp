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
    auto finally_var = temp+Variable("case");
    auto numberOfCandidates = 0;
    auto overloading_errors = string{""};
    auto competing = string{""};
    auto with_start = p-1;
    //uplifting.emplace_back(finally_var, uplifting.size(), false, uplifting.size() && uplifting.back().is_loop);
    vars[finally_var] = types.vars[LABEL_VAR];
    auto next = string{""};
    proving = true;
    try {
        if(curry.exists()) 
            imp->error(first_token_pos, "Cannot have a curry onto `case`.");
        parse(nullptr, p, types, false);
        next = imp->at(p++);
        numberOfCandidates++;
        implementation += Code(Variable("goto"),finally_var,SEMICOLON_VAR);
        competing = "\n"+imp->tokens[with_start].show();
    }
    catch (const runtime_error& e) {
        auto what = string{e.what()};
        if(!what.starts_with("\033[33mNot found")) 
            throw e;
        if(Def::lsp) 
            overloading_errors += "\n";
        else overloading_errors += "\n- ";
        overloading_errors += what;
        end_block(p);
        next = imp->at(p++);
        if(next=="qed") 
            imp->error(with_start, "`case` with no alternative always fails");
    }
    if(next=="qed" && numberOfCandidates) 
        imp->error(with_start, "`case` with no alternative\nCan guard parametric types but is a code smell otherwise\nHere it is redundant as enclosed code always succeeds");
    
    while(true) {
        // cout << next << "\n";
        // cout << numberOfCandidates << "\n";
        if(next=="qed") {
            p++;
            break;
        }
        if(next!="case")
            imp->error(p, "A `case` segment can only be followed by another one or `qed`");

        if(!numberOfCandidates) {
            try {
                size_t else_start = p-1;
                parse(nullptr, p, types, false);
                numberOfCandidates++;
                implementation += Code(Variable("goto"), finally_var, SEMICOLON_VAR);
                if(numberOfCandidates) 
                    competing = "\n"+imp->tokens[else_start].show();
            }
            catch (const std::runtime_error& e) {
                string what = e.what();
                if(what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found") 
                    throw e;
                overloading_errors += Def::lsp?"\n":"\n- ";
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
    //cout <<name << numberOfCandidates << " throtling "<<overloading_errors<<" "<<signature(types)<<"\n";
    if(numberOfCandidates>1) 
        ERROR("Competes with previous branch of `case`"+CODE_START()+competing+CODE_END());
    if(numberOfCandidates==0) 
        imp->error(with_start, "No valid branch of `case`"+CODE_START()+overloading_errors+CODE_END());

    implementation += Code(finally_var,COLON_VAR);
    proving = false;
    //uplifting.pop_back();
    return EMPTY_VAR;

}