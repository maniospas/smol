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

void Def::parse_directive_body(const shared_ptr<Import>& imp, size_t& p, string next, Types& types) {
    if(!imp->allow_unsafe) 
        imp->error(--p, "@body is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
    next = imp->at(p++);
    if(next!="{") 
        imp->error(--p, "Expected brackets");
    int depth = 1;
    while(true) {
        size_t pos = p;
        next = imp->at(p++);
        if(next=="{") 
            depth++;
        if(next=="}") {
            depth--;
            if(depth==0) 
                break;
        }
        string nextnext = imp->at(p);
        if(p<imp->size()-2 
            && imp->at(p+1)=="=" 
            && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") 
            && !is_symbol(next) 
            && !is_symbol(nextnext)
        ) {
            // identified assignment so we are creating a primitive
            string argname = nextnext;
            string argtype = next;
            if(types.vars.find(argtype)==types.vars.end() || types.vars.find(argtype)->second->not_primitive()) 
                imp->error(pos, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
            vars[argname] = types.vars.find(argtype)->second;
        }
        else {
            string prev_nextnext = next;
            if(is_symbol_or_digit(next)) 
                while(is_symbol_or_digit(nextnext) && nextnext!="{" && nextnext!="}" && p<imp->size()-1) {
                    next += nextnext;
                    ++p;
                    nextnext = imp->at(p);
                }
            if(next=="goto" && nextnext!="__failsafe") 
                vars[nextnext] = types.vars[LABEL_VAR];
            implementation += move(Variable(next));
        }
    }
    implementation += move(Variable(ENDL_VAR));
}