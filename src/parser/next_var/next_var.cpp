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

#define CHECK_RELEASE(next) if(released[next]) imp->error(--p, "Cannot use already released value: "+next.to_string());
#define CHECK_ERRCODE(next) if(contains(next+ERR_VAR)) {implementation += Code(token_if, next+ERR_VAR, Variable(") goto "), Variable("__result_unhandled_error"), SEMICOLON_VAR); errors.insert(Code(Variable("__result_unhandled_error"), COLON_VAR, Variable("printf(\"Unhandled error\\n\")"),SEMICOLON_VAR, Variable("__result__errocode"), Variable("=__UNHANDLED__ERROR;\ngoto __failsafe"), SEMICOLON_VAR));}

Variable Def::next_var(size_t& p, const Variable& first_token, Types& types, bool test) {
    if(first_token.is_empty()) 
        return EMPTY_VAR;
    auto n = imp->size();
    CHECK_RELEASE(first_token);
    CHECK_ERRCODE(first_token);
    if(p>=n) 
        return first_token;
    auto next = first_token;
    if(types.contains(next)) {
        auto type = types.vars[next];
        next = create_temp();
        vars[next] = type;
        mutables.insert(next);
        for(const auto& pack : type->packs) {
            if(type->alignments[pack])
                alignments[next+pack] = type->alignments[pack];
            assign_variable(type->vars[pack], next+pack, ZERO_VAR, p);
            mutables.insert(next+pack);
        }
    }
    while(true) {
        if(next!=first_token) {
            CHECK_RELEASE(next);
            CHECK_ERRCODE(next);
        }
        if(p>=n) 
            break;
        if((/*imp->at(p)==":" 
            ||*/ (imp->at(p)=="." && p<imp->size()-2 && imp->at(p+2)=="(")
            || (imp->at(p)=="." && p<imp->size()-2 && imp->at(p+2)=="__consume")
            || (imp->at(p)=="." && imp->at(p+1)=="if")
            || (imp->at(p)=="." && imp->at(p+1)=="on")
            || (imp->at(p)=="." && imp->at(p+1)=="while")) 
        ) {
            ++p;
            next = parse_expression(p, imp->at(p++), types, next);
        }
        else if(imp->at(p)=="and") 
            next = next_var_and(next, p, types);
        else if(imp->at(p)=="or") 
            next = next_var_or(next, p, types);
        else if(imp->at(p)==".") {
            bool skip = false;
            next = next_var_field(next, p, first_token, types, test, skip);
            if(skip)
                continue;
        }
        else if(imp->at(p)=="[" 
            && contains(next) 
            && vars[next]->is_service
            && vars[next]->packs.size()==2
            && vars[next]->contains(vars[next]->packs[1])
            && vars[next]->vars[vars[next]->packs[1]]->name==BUFFER_VAR
        ) {
            imp->error(--p, "Internal error: deprecated branch");
            //next = next_var_buffer_ret_at(next, p, first_token, types, test);
            continue;
        }
        else if(imp->at(p)=="[" 
            && contains(next) 
            && vars[next]->name==BUFFER_VAR
        ) 
            next = next_var_buffer_at(next, p, types);
        else if(imp->at(p)=="[") 
            next = next_var_at(next, p, types);
        else 
            break;
    }
    if(test && next.exists() && !contains(next)) 
        imp->error(--p, "Not found: "
            +pretty_var(next.to_string())
            +recommend_variable(types, next)
        );
    CHECK_RELEASE(next);
    return next;
}
