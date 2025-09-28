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

void Def::parse_directive_link(size_t& p, string next) {
    if(!imp->allow_unsafe) 
        imp->error(--p, "@link is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
    next = imp->at(p++);
    if(next!="{") 
        imp->error(--p, "Expected brackets");
    int depth = 1;
    string preample("");
    while(true) {
        next = imp->at(p++);
        if(next=="{") 
            depth++;
        if(next=="}") {
            depth--;
            if(depth==0) 
                break;
        }
        if(next=="#" && preample.size()) {
            preample += "\n#"; 
            continue;
        }
        string nextnext = imp->at(p);
        preample += next;
    }
    add_linker(preample);
}