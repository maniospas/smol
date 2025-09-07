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

void Def::parse_return(const shared_ptr<Import>& imp, size_t& p, Variable next, Types& types) {
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
        next = parse_expression(imp, p, next, types);
        if(internalTypes.contains(next)) 
            assign_variable(internalTypes.vars[next], uplifting_targets[uplifting_targets.size()-uplifting-1]+Variable("r"), next, imp, p);
        implementation +=Code(token_goto,uplifting_targets[uplifting_targets.size()-uplifting-1],SEMICOLON_VAR);
        return;
    }

    vector<Variable> tentative = map_to_return(imp, p, types, true);

    if(!has_returned) 
        packs = tentative;
    else if(packs.size()!=tentative.size()) 
        imp->error(--p, "Incompatible returns\nprevious "
            +signature_like(types, packs)
            +" vs last "+signature_like(types, tentative)
        );
    else 
        for(size_t i=0;i<packs.size();++i) {
            if(internalTypes.vars[packs[i]]!=internalTypes.vars[tentative[i]]) 
                imp->error(--p, 
                    "Incompatible returns\nprevious "
                    +signature_like(types, packs)
                    +" vs last "+signature_like(types, tentative)
                );
            assign_variable(internalTypes.vars[packs[i]], tentative[i], packs[i], imp, p, false, false);
        }
    implementation += Code(token_goto,uplifting_targets[0],SEMICOLON_VAR);
    has_returned = true;
}
