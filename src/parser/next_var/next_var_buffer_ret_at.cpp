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

Variable Def::next_var_buffer_ret_at(Variable next, const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test) {
    if(active_calls.find(next)!=active_calls.end() && active_calls[next].exists()) {
        if(active_calls[active_calls[next]].exists()) {
            static const Variable token_print = Variable(":\nprintf(\"Runtime error from");
            static const Variable token_failsafe = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
            const Variable& call_var = active_calls[next];
            implementation += Code(
                Variable("__smolambda_task_wait"),
                LPAR_VAR,
                call_var+TASK_VAR,
                RPAR_VAR,
                SEMICOLON_VAR
            );
            internalTypes.vars[next+ERR_VAR] = types.vars[ERRCODE_VAR];
            implementation += Code(
                call_var+ERR_VAR, 
                ASSIGN_VAR, 
                call_var+STATE_VAR, 
                ARROW_VAR, 
                ERR_VAR, 
                SEMICOLON_VAR
            );
            implementation += Code(
                next+ERR_VAR, 
                ASSIGN_VAR, 
                call_var+ERR_VAR,
                SEMICOLON_VAR
            );
            Variable fail_var = create_temp();
            internalTypes.vars[fail_var] = types.vars[LABEL_VAR];
            if(!internalTypes.contains(next+ERR_VAR))
                internalTypes.vars[next+ERR_VAR] = types.vars[ERRCODE_VAR];
            implementation += Code(
                token_if, 
                call_var+ERR_VAR, 
                token_goto, 
                fail_var, 
                SEMICOLON_VAR
            );
            errors += Code(
                fail_var, 
                token_print, 
                internalTypes.contains(next)?internalTypes.vars[next]->name:EMPTY_VAR, 
                call_var, 
                token_failsafe
            );
            add_preample("#include <stdio.h>");
        }
        if(active_calls[next].exists() && active_calls[active_calls[next]].exists()) 
            active_calls[active_calls[next]] = EMPTY_VAR;
    }
    internalTypes.vars[next+internalTypes.vars[next]->packs[1]] = types.vars[BUFFER_VAR];
    buffer_types[next+internalTypes.vars[next]->packs[1]] = internalTypes.vars[next]->buffer_types[internalTypes.vars[next]->packs[1]];
    if(!buffer_types[next+internalTypes.vars[next]->packs[1]])
        imp->error(--p, "Internal error: Failed to transfer a buffer type");
    implementation += Code(
        next+internalTypes.vars[next]->packs[1],
        ASSIGN_VAR,
        MUL_VAR,
        active_calls[next]+STATE_VAR,
        ARROW_VAR,
        internalTypes.vars[next]->packs[1],
        SEMICOLON_VAR
    );
    next = next+internalTypes.vars[next]->packs[1];
    if(buffer_types.find(next)==buffer_types.end())
        imp->error(--p, "Internal error: cannot determine the buffer storage data for "
            +next.to_string()
        );
    ++p;
    Variable idx = parse_expression(i, p, imp->at(p++), types);
    if(!internalTypes.contains(idx) || internalTypes.vars[idx]->name!=U64_VAR)
        imp->error(--p, "Buffer index must be u64 but got "
            +(internalTypes.contains(idx)?internalTypes.vars[idx]->name.to_string():"nothing")
        );
    if(imp->at(p++)!="]") 
        imp->error(--p, "Expecting closing square bracket");

    internalTypes.vars[next+Variable("__buffer_size")]          = types.vars[Variable("u64")];
    internalTypes.vars[next+Variable("__buffer_alignment")]     = types.vars[Variable("u64")];

    size_t count_packs = 0;
    for (const auto& pack : buffer_types[next]->packs)
        if (buffer_types[next]->internalTypes.contains(pack) && buffer_types[next]->internalTypes.vars[pack]->name != NOM_VAR)
            count_packs++;
    if(buffer_types[next]->_is_primitive) 
        count_packs++;

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

    Variable fail_var = create_temp();
    internalTypes.vars[fail_var] = types.vars[LABEL_VAR];
    implementation += Code(
        Variable("if("), 
        idx, 
        Variable(">="), 
        next+Variable("__buffer_size"),
        Variable(")goto"), 
        fail_var, 
        SEMICOLON_VAR
    );
    errors += Code(
        fail_var, 
        Variable(":\nprintf(\"Buffer index out of range\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n")
    );
    Variable elem = create_temp();
    Variable packname = EMPTY_VAR;
    if(p<i->size()-1 && i->at(p) == ".") 
        packname = i->at(p+1); 

    size_t pack_index = 0;
    if(buffer_types[next]->_is_primitive) {
        Variable tmp = create_temp();
        internalTypes.vars[tmp] = buffer_types[next];
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
        internalTypes.vars[elem] = buffer_types[next];
        if(mutables.find(next)!=mutables.end()) 
            mutables.insert(elem);
        for (const auto& pack : buffer_types[next]->packs) {
            if(!buffer_types[next]->internalTypes.contains(pack)) 
                imp->error(--p, "Internal error: failed to unpack value stored on buffer due to unknown type: "
                    +pack.to_string()
                );
            else if(buffer_types[next]->internalTypes.vars[pack]->name == NOM_VAR) {
                Variable tmp = create_temp();
                internalTypes.vars[tmp] = buffer_types[next]->internalTypes.vars[pack];
                if(packname.is_empty()) {
                    assign_variable(
                        buffer_types[next]->internalTypes.vars[pack],
                        elem+pack,
                        tmp,
                        i, 
                        p
                    );
                }
            }
            else {
                if(packname.is_empty() || packname==pack) {
                    Variable tmp = create_temp();
                    if(mutables.find(next)!=mutables.end() 
                        && buffer_types[next]->mutables.find(pack)
                            !=buffer_types[next]->mutables.end()
                    ) 
                        mutables.insert(tmp);
                    internalTypes.vars[tmp] = buffer_types[next]->internalTypes.vars[pack];
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
                        buffer_types[next]->internalTypes.vars[pack]->name, 
                        Variable("))"), 
                        SEMICOLON_VAR
                    );
                    assign_variable(
                        buffer_types[next]->internalTypes.vars[pack],
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
        for(const auto& it : buffer_types[next]->internalTypes.vars) 
            internalTypes.vars[elem+it.first] = it.second;
    for(const auto& it : buffer_types[next]->buffer_types)
        buffer_types[elem+it.first] = it.second;
    next = elem;
    return next;
}