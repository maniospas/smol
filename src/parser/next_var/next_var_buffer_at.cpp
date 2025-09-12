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

Variable Def::next_var_buffer_at(Variable next, const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test) {
    Variable buffer_var = next;
    next = next+Variable("dynamic");
    if(buffer_types.find(next)==buffer_types.end())
        imp->error(--p, "Internal error: cannot determine the buffer storage data for "
            +next.to_string()
        );
    ++p;
    Variable idx = parse_expression(i, p, imp->at(p++), types);
    if(!contains(idx) || vars[idx]->name!=U64_VAR)
        imp->error(--p, "Buffer index must be u64 but got "
            +(contains(idx)?vars[idx]->name.to_string():"nothing")
        );
    if(imp->at(p++)!="]") 
        imp->error(--p, "Expecting closing square bracket");
    vars[next+Variable("__buffer_size")]          = types.vars[Variable("u64")];
    vars[next+Variable("__buffer_alignment")]     = types.vars[Variable("u64")];

    size_t count_packs = 0;
    for (const auto& pack : buffer_types[next]->packs)
        if (buffer_types[next]->contains(pack) && buffer_types[next]->vars[pack]->name != NOM_VAR)
            count_packs++;
    if(buffer_types[next]->_is_primitive) 
        count_packs++;
    Variable fail_var = create_temp();
    
    implementation += Code(
        token_ifnot, 
        next, 
        token_goto,
        fail_var, 
        SEMICOLON_VAR
    );

    implementation += Code(
        next+Variable("__buffer_alignment"), 
        ASSIGN_VAR, 
        Variable(to_string(count_packs)), 
        SEMICOLON_VAR
    );
    implementation += Code(
        next+Variable("__buffer_size"), 
        ASSIGN_VAR, 
        Variable("((u64*)"), 
        next, 
        Variable(")[1]"), 
        SEMICOLON_VAR
    );

    vars[fail_var] = types.vars[LABEL_VAR];
    implementation += Code(
        token_if, 
        idx, 
        Variable(">="), 
        next+Variable("__buffer_size"),
        token_goto, 
        fail_var, 
        SEMICOLON_VAR
    );
    errors += Code(
        fail_var, 
        Variable(":\nprintf(\"Buffer index out of range\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n")
    );
    Variable elem = create_temp();
    Variable packname = EMPTY_VAR;
    // TODO: the following has only issue with buffers stored into buffers
    //if(p<i->size()-1 && i->at(p) == ".") 
    //    packname = i->at(p+1); 

    size_t pack_index = 0;
    if(buffer_types[next]->_is_primitive) {
        Variable tmp = create_temp();
        vars[tmp] = buffer_types[next];
        implementation += Code(
            Variable("memcpy(&"), 
            tmp, 
            Variable(", &((u64*)((u64*)"), 
            next, 
            Variable(")[0])["),
            idx, 
            MUL_VAR, 
            next+Variable("__buffer_alignment"), 
            Variable("+"+ to_string(pack_index)+"], sizeof("), 
            buffer_types[next]->name, 
            Variable("))"), 
            SEMICOLON_VAR
        );
        assign_variable(
            buffer_types[next],
            elem,
            tmp,
            i, 
            p
        );
    }
    else {
        vars[elem] = buffer_types[next];
        if(mutables.find(next)!=mutables.end()) 
            mutables.insert(elem);
        for (const auto& pack : buffer_types[next]->packs) {
            if(!buffer_types[next]->contains(pack)) 
                imp->error(--p, "Internal error: failed to unpack value stored on buffer due to unknown type: "
                    +pack.to_string()
                );
            else if(buffer_types[next]->vars[pack]->name == NOM_VAR) {
                Variable tmp = create_temp();
                vars[tmp] = buffer_types[next]->vars[pack];
                if(packname.is_empty()) {
                    assign_variable(
                        buffer_types[next]->vars[pack],
                        elem+pack,
                        tmp,
                        i, 
                        p
                    );
                }
            }
            else {
               if(packname.is_empty() || packname==pack) 
               {
                    Variable tmp = create_temp();
                    if(mutables.find(next)!=mutables.end() 
                        && buffer_types[next]->mutables.find(pack)
                            !=buffer_types[next]->mutables.end()
                    ) 
                        mutables.insert(tmp);
                    vars[tmp] = buffer_types[next]->vars[pack];
                    if(buffer_types[next]->buffer_types.find(pack)!=buffer_types[next]->buffer_types.end())
                        buffer_types[tmp] = buffer_types[next]->buffer_types[pack];
                    implementation += Code(
                        Variable("memcpy(&"), 
                        tmp, 
                        Variable(", &((u64*)((void**)"),
                        next, 
                        Variable(")[0])["),
                        idx, 
                        MUL_VAR, 
                        next + Variable("__buffer_alignment"), 
                        Variable("+" + to_string(pack_index) + "], sizeof("), 
                        buffer_types[next]->vars[pack]->name, 
                        Variable("))"), 
                        SEMICOLON_VAR
                    );
                    assign_variable(
                        buffer_types[next]->vars[pack],
                        elem+pack,
                        tmp,
                        i, 
                        p
                    );
                }
                pack_index++;
            }
        }
    }
    // do this after the loop to not mess with assign_variable
    if(packname.is_empty()) 
        for(const auto& it : buffer_types[next]->vars) 
            vars[elem+it.first] = it.second;
    for(const auto& it : buffer_types[next]->buffer_types)
        buffer_types[elem+it.first] = it.second;

    // parse buff[element]::call(args)
    if(p<imp->size()-2 && imp->at(p)==":" && imp->at(p+1)==":") {
        p += 2;
        if(mutables.find(buffer_var)==mutables.end())
            imp->error(p, "Buffer is immutable: "
                +pretty_var(buffer_var.to_string())
                +"\nCannot apply :: to create a modifiable curry for an element of an immutable buffer."
            );
        mutables.insert(elem);
        for(const auto& it : buffer_types[next]->packs) 
            mutables.insert(elem+it);
        Variable first_element = imp->at(p++);
        Variable ret = parse_expression(imp, p, first_element, types, elem);
        pack_index = 0;
        for(const auto& pack : buffer_types[next]->packs) {
            if(!buffer_types[next]->contains(pack)) 
                imp->error(--p, "Internal error: failed to unpack value stored on buffer due to unknown type: "
                    +pack.to_string()
                );
            else if(buffer_types[next]->vars[pack]->name != NOM_VAR) {
                implementation += Code(
                    Variable("memcpy(&((u64*)((u64*)"), 
                    next, 
                    Variable(")[0])["),
                    idx, 
                    MUL_VAR, 
                    next+Variable("__buffer_alignment"), 
                    Variable("+"+ to_string(pack_index)+"], &"),
                    elem+pack,
                    Variable(", sizeof("), 
                    elem+pack, 
                    Variable("))"), 
                    SEMICOLON_VAR
                );
            }
            pack_index++;
        }
        return ret;
    }

    next = elem;
    return next;
}