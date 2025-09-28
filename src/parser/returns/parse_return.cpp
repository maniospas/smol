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

void Def::parse_return(size_t& p, Variable next, Types& types) {
    size_t uplifting = 0;
    static const Variable token_goto = Variable("goto");
    if(next=="|") {
        --p;
        while(p+uplifting<imp->size() && imp->at(p+uplifting)=="|") 
            ++uplifting;
        p += uplifting;
        if(imp->at(p++)!="-") 
            imp->error(--p, "Expecting `--` or `->` after uplifting operator `|`");
    }
    if(imp->at(p)=="-") {
        ++p;
        if(uplifting) 
            implementation += Code(token_goto,uplifting_targets[0],SEMICOLON_VAR);
        return;
    }
    if(imp->at(p++)!=">") 
        imp->error(p-2, "Expecting return.\nUse `->` to return a value or `--` (or end of file) to return without a value for expressions starting with `-`");
    if(uplifting>=uplifting_targets.size()) 
        imp->error(p-3, "Too many levels of uplifting.\nYou are currently on "
            +to_string(uplifting_targets.size()-1)
            +" nested blocks in."
        );
    if(p<imp->size() && imp->at(p)=="-") {
        p++;
        implementation += Code(token_goto,uplifting_targets[uplifting_targets.size()-uplifting-1],SEMICOLON_VAR);
        if(has_returned && uplifting_targets.size()-uplifting==1 && packs.size()) 
            imp->error(p-1, "Cannot mix a no-return and a return");
        if(uplifting_targets.size()==1+uplifting) 
            has_returned = true;
        return;
    }
    if(uplifting_targets.size()>1+uplifting) {
        if(uplifting>=uplifting_targets.size()) 
            imp->error(p-3, "Too many levels of uplifting.\nYou are currently on "
                +to_string(uplifting_targets.size()-1)+" nested blocks in."
            );
        next = imp->at(p++);
        next = parse_expression(p, next, types);
        if(contains(next)) 
            assign_variable(vars[next], uplifting_targets[uplifting_targets.size()-uplifting-1]+Variable("r"), next, p);
        implementation +=Code(token_goto,uplifting_targets[uplifting_targets.size()-uplifting-1],SEMICOLON_VAR);
        return;
    }

    auto tentative = map_to_return(p, types, true);

    if(is_service) {
        auto cleaned_tentative = vector<Variable>{};
        cleaned_tentative.reserve(tentative.size());
        for(size_t i=0;i<packs.size();++i) if(i==0 || packs[i]!=ERR_VAR)
            cleaned_tentative.push_back(tentative[i]); 
        if(cleaned_tentative.size()!=tentative.size())
           tentative = cleaned_tentative;
    }

    if(!has_returned) 
        packs = tentative;
    else if(packs.size()!=tentative.size()) 
        imp->error(--p, "Incompatible returns\nprevious "
            +signature_like(types, packs)
            +" vs last "+signature_like(types, tentative)
        );
    else 
        for(size_t i=0;i<packs.size();++i) {
            if(vars[packs[i]]!=vars[tentative[i]]) 
                imp->error(--p, 
                    "Incompatible returns\nprevious "
                    +signature_like(types, packs)
                    +" vs previous "+signature_like(types, tentative)
                );
            // if(packs[i]!=tentative[i] && !tentative[i].is_private() && !packs[i].is_private() && packs.size()>=(is_service?2:1))
            //     imp->error(--p, "You are returning a differently named value : "
            //         +pretty_var(packs[i].to_string())
            //         +" vs previous "
            //         +pretty_var(tentative[i].to_string())
            //         +"\nThis would create ambiguity on what field access looks like"
            //     );
            assign_variable(vars[packs[i]], packs[i], tentative[i], p, false, false);
        }
    implementation += Code(token_goto,uplifting_targets[0],SEMICOLON_VAR);
    has_returned = true;
}
