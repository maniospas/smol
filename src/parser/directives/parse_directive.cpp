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

void Def::parse_directive(const shared_ptr<Import>& imp, size_t& p, string next, Types& types) {
    next = imp->at(p++);
    if(next=="body")  // do this first for speedup (it's the most frequent kind)
        parse_directive_body(imp, p, next, types);
    else if(next=="head") 
        parse_directive_head(imp, p, next, types);
    else if(next=="noborrow") 
        noborrow = true;
    else if(next=="noassign") {
        noassign = true;
    }
    else if(next=="noshare") {
        static const Variable token_transient_end = Variable(")\n");
        next = imp->at(p++);
        this->finals[next] += Code(
            TRANSIENT_VAR,
            Variable(next),
            token_transient_end
        );
    }
    else if(next=="link") 
        parse_directive_link(imp, p, next, types);
    else if(next=="buffer") {
        if(!imp->allow_unsafe) 
            imp->error(--p, "@body is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        buffer_ptr = imp->at(p++);
        if(!contains(buffer_ptr) || vars[buffer_ptr]->name!=PTR_VAR)
            imp->error(--p, "Expecting ptr for buffer pointer interpretation");
        buffer_size = imp->at(p++);
        if(!contains(buffer_size) || vars[buffer_size]->name!=U64_VAR)
            imp->error(--p, "Expecting u64 for buffer size interpretation");
        buffer_release = imp->at(p++);
        if(!contains(buffer_release) || vars[buffer_release]->name!=PTR_VAR)
            imp->error(--p, "Expecting ptr for buffer release pointer interpretation");
    }
    else if(next=="finally") 
        parse_directive_finally(imp, p, next, types);
    else if(next=="fail") 
        parse_directive_fail(imp, p, next, types);
    else if(next=="release") 
        parse_directive_release(imp, p, next, types);
    else
        imp->error(--p, "Invalid symbol after @\nOnly @head, @body, @fail, @finally, @noshare, @release, @noborrow are allowed here.");
}
