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
    size_t return_to = uplifting.size()-1;
    size_t return_p = p; // TODO: fix this when we fully migrate to "return" as a keyword instead of a macro for "->"
    static const Variable token_goto = Variable("goto");
    if(next=="else" || next=="elif") {
        implementation += Code(token_goto,this->uplifting[return_to].target,SEMICOLON_VAR);
        if(uplifting[return_to].has_returned) {
            if(!return_to && packs.size())
                imp->error(p-1, "Cannot end block with `else` given a previous function return: "
                    +signature_like(types, packs)
                );
            else if(contains(uplifting[return_to].target+Variable("r")))
                imp->error(p-1, "Cannot end block with `else` given a previous `algorithm` return: "
                    +vars[uplifting[return_to].target+Variable("r")]->signature(types)
                );
        }
        uplifting[return_to].has_returned = true;
        return;
    }
    // "return" statement from hereon - find capture
    while(return_to && !uplifting[return_to].mandate_return) {
        //uplifting[return_to].has_exited = true;
        if(uplifting[return_to].has_returned && !contains(uplifting[return_to].target+Variable("var")))
            imp->error(p, "Ending a code block that is expecting a returned value");
        uplifting[return_to].has_returned = true;
        --return_to;
    }
    
    // return to intermediate capture
    if(return_to) {
        next = imp->at(p++);
        next = parse_expression(p, next, types);
        if(next.exists() && contains(next)) {
            if(uplifting[return_to].has_returned && !contains(uplifting[return_to].target+Variable("r"))) {
                if(vars[next]->packs.size())
                    imp->error(return_p, "Previously returned no value, but here a value is obtainted: "
                        +vars[next]->signature(types)
                    );
            }
            else {
                assign_variable(vars[next], uplifting[return_to].target+Variable("r"), next, p);
                mutables.insert(uplifting[return_to].target+Variable("r"));
            }
        }
        else if(contains(uplifting[return_to].target+Variable("r"))) 
            imp->error(return_p, "Cannot mix a capture return with a previously unset on");
        implementation += Code(token_goto,uplifting[return_to].target,SEMICOLON_VAR);
        uplifting[return_to].has_returned = true;
        --p;
        return;
    }

    // return from function
    auto tentative = map_to_return(p, types, true);
    if(!uplifting[0].has_returned) 
        packs = tentative;
    else if(packs.size()!=tentative.size()) 
        imp->error(return_p, "Incompatible returns\nprevious "
            +signature_like(types, packs)
            +" vs last "+signature_like(types, tentative)
        );
    else for(size_t i=0;i<packs.size();++i) {
        if(is_service) cout << packs[i] << "--------------------------"<<"\n";
        if(vars[packs[i]]!=vars[tentative[i]]) 
            imp->error(return_p, 
                "Incompatible returns\nprevious "
                +signature_like(types, packs)
                +" vs previous "+signature_like(types, tentative)
            );
        assign_variable(vars[packs[i]], packs[i], tentative[i], p, false, false);
    }
    implementation += Code(token_goto,this->uplifting[0].target,SEMICOLON_VAR);
    uplifting[0].has_returned = true;
}
