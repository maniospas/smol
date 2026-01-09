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

void Def::parse_directive(size_t& p, string next, Types& types) {
    next = imp->at(p++);
    if(next=="c_body")  // do this first for speedup (it's the most frequent kind)
        parse_directive_body(p, next, types);
    else if(next=="c_head") 
        parse_directive_head(p, next);
    else if(next=="c_noborrow") 
        noborrow = true;
    else if(next=="c_noassign") 
        noassign = true;
    else if(next=="c_nozero") 
        nozero = true;
    else if(next=="c_noleftover") 
        noleftover = true;
    else if(next=="invalid") 
        imp->error(p-1, "Not found correct path: "+imp->at(p));
    else if(next=="unique") {
        next = imp->at(p++);
        if(next.size()<2 || next[0]!='"' || next[next.size()-1]!='"')
            imp->error(--p, "A cstr is required to indicate a resource family id");
        Variable next_query = next;
        if(singletons.find(next_query)!=singletons.end())
            imp->error(--p, "This resource family "
                +next
                +" has been claimed by a previous @unique (e.g., in a call)"
            );
        singletons.insert(next_query);
    }
    else if(next=="acquire") {
        next = imp->at(p++);
        if(next.size()<2 || next[0]!='"' || next[next.size()-1]!='"')
            imp->error(--p, "A cstr is required to indicate a resource family id");
        Variable next_query = next;
        if(acquired.find(next_query)!=acquired.end())
            imp->error(--p, "This resource family "
                +next
                +" has @acquire in a previous call"
            );
        acquired.insert(next_query);
    }
    else if(next=="c_noshare") {
        static const Variable token_transient_end = Variable(")\n");
        next = imp->at(p++);
        this->finals[next] += Code(
            TRANSIENT_VAR,
            Variable(next),
            token_transient_end
        );
    }
    else if(next=="c_link") 
        parse_directive_link(p, next);
    else if(next=="c_buffer") {
        if(!imp->allow_unsafe) 
            imp->error(--p, "@c_buffer is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
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
    else if(next=="c_finally") 
        parse_directive_finally(p, next, types);
    else if(next=="c_fail") 
        parse_directive_fail(p, next, types);
    else if(next=="release") 
        parse_directive_release(p, next, types);
    else if(next=="on") 
        parse_on(p, types, EMPTY_VAR, p);
    else
        imp->error(--p, "Invalid symbol after @ (it is not a directive)");
}
