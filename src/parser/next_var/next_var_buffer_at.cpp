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

Variable Def::next_var_buffer_at(Variable next, size_t& p, Types& types) {

    if(active_calls[next].exists() && active_calls[active_calls[next]].exists()) {
        static const Variable token_print = Variable(":\n__result__error_code=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
        const Variable& call_var = active_calls[next];
        implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
        vars[next+ERR_VAR] = types.vars[ERRCODE_VAR];
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
        vars[fail_var] = types.vars[LABEL_VAR];
        implementation += Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
        errors.insert(Code(fail_var, token_print));
        add_preamble("#include <stdio.h>");
        if(active_calls[next].exists() && active_calls[active_calls[next]].exists()) 
            active_calls[active_calls[next]] = EMPTY_VAR;
    }

    Variable buffer_var = next;
    next = next+Variable("dynamic");
    if(buffer_types.find(next)==buffer_types.end())
        imp->error(--p, "Internal error: cannot determine the buffer storage data for "
            +next.to_string()
        );
    ++p;
    Variable idx = parse_expression(p, imp->at(p++), types);
    if(!contains(idx) || vars[idx]->name!=U64_VAR)
        imp->error(--p, "Buffer index must be u64 but got "
            +(contains(idx)?vars[idx]->name.to_string():"nothing")
        );
    if(imp->at(p++)!="]") 
        imp->error(--p, "Expecting closing square bracket");
    vars[next+Variable("__buffer_size")]          = types.vars[Variable("u64")];
    vars[next+Variable("__buffer_alignment")]     = types.vars[Variable("u64")];

    
    // compute alignment_size (valid packs only)
    size_t count_alignment_bytes = 0;
    for(const auto& pack : buffer_types[next]->packs)
        count_alignment_bytes += buffer_types[next]->vars[pack]->storage_size;
    if(buffer_types[next]->_is_primitive) 
        count_alignment_bytes += buffer_types[next]->storage_size;
    Variable fail_var = Variable("__result__buffer_error"); //create_temp();
    
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
        Variable(to_string(count_alignment_bytes)), 
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

    //vars[fail_var] = types.vars[LABEL_VAR];
    implementation += Code(
        token_if, 
        idx, 
        Variable(">="), 
        next+Variable("__buffer_size"),
        token_goto, 
        fail_var, 
        SEMICOLON_VAR
    );
    errors.insert(Code(
        fail_var, 
        Variable(":\nprintf(\"Buffer error\\n\");\n__result__error_code=__BUFFER__ERROR;\ngoto __failsafe;\n")
    ));
    Variable elem = create_temp();
    Variable packname = EMPTY_VAR;
    // TODO: the following has only issue with buffers stored into buffers
    //if(p<i->size()-1 && i->at(p) == ".") 
    //    packname = i->at(p+1); 

    if(buffer_types[next]->_is_primitive) {
        Variable tmp = create_temp();
        vars[tmp] = buffer_types[next];
        implementation += Code(
            Variable("memcpy(&"), 
            tmp, 
            Variable(", &((char*)((void**)"), 
            next, 
            Variable(")[0])["),
            idx, 
            MUL_VAR, 
            next+Variable("__buffer_alignment"), 
            Variable("], sizeof("), 
            buffer_types[next]->name, 
            Variable("))"), 
            SEMICOLON_VAR
        );
        assign_variable(
            buffer_types[next],
            elem,
            tmp,
            p
        );
    }
    else {
        size_t count_alignment_bytes = 0;
        // parse non-primitive
        vars[elem] = buffer_types[next];
        if(mutables.find(next)!=mutables.end()) 
            mutables.insert(elem);
        for(const auto& pack : buffer_types[next]->packs) {
            if(!buffer_types[next]->contains(pack)) 
                imp->error(--p, "Internal error: failed to unpack value stored on buffer due to unknown type: "
                    +pack.to_string()
                );
            else if(buffer_types[next]->vars[pack]->name == NOM_VAR) {
                Variable tmp = create_temp();
                vars[tmp] = buffer_types[next]->vars[pack];
                alignments[tmp] = buffer_types[next]->alignments[pack];
                if(packname.is_empty()) {
                    assign_variable(
                        buffer_types[next]->vars[pack],
                        elem+pack,
                        tmp,
                        p
                    );
                }
            }
            else {
               if(packname.is_empty() || packname==pack) 
               {
                    auto tmp = Variable{create_temp()};
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
                        Variable(", &((char*)((void**)"),
                        next, 
                        Variable(")[0])["),
                        idx, 
                        MUL_VAR, 
                        next + Variable("__buffer_alignment"), 
                        Variable("+" + to_string(count_alignment_bytes) + "], sizeof("), 
                        buffer_types[next]->vars[pack]->name, 
                        Variable("))"), 
                        SEMICOLON_VAR
                    );
                    assign_variable(
                        buffer_types[next]->vars[pack],
                        elem+pack,
                        tmp,
                        p
                    );
                }
                count_alignment_bytes += buffer_types[next]->vars[pack]->storage_size;
            }
        }
    }
    // do this after the loop to not mess with assign_variable
    if(packname.is_empty()) 
        for(const auto& it : buffer_types[next]->vars) 
            vars[elem+it.first] = it.second;
    for(const auto& it : buffer_types[next]->buffer_types)
        buffer_types[elem+it.first] = it.second;

    // parse buff[element] = .call(args)
    if(p<imp->size()-2 && imp->at(p+1)=="." && imp->at(p)=="=") {
        p += 2;
        if(mutables.find(buffer_var)==mutables.end())
            imp->error(p, "Buffer is immutable: "
                +pretty_var(buffer_var.to_string())
                +"\nCannot apply /= to create a modifiable curry for an element of an immutable buffer."
            );
        mutables.insert(elem);
        for(const auto& it : buffer_types[next]->packs) 
            mutables.insert(elem+it);
        Variable first_element = imp->at(p++);
        Variable ret = parse_expression(p, first_element, types, elem);
        if(ret.is_empty() || !vars.contains(ret) || vars[ret]->packs.size()==0)
            imp->error(--p, "Cannot modify a buffer value with an expression that does not return a value (use . instead of =. )");
        if(vars[ret]->alias_for.exists()) {
            if(vars[ret]->vars[vars[ret]->alias_for]!=buffer_types[next]) 
                imp->error(--p, "Cannot modify a buffer value with an expression of different return type"
                    "\nExpected "+buffer_types[next]->name.to_string()+" but got "+vars[ret]->vars[vars[ret]->alias_for]->name.to_string());
        }
        else if(vars[ret]!=buffer_types[next]) 
            imp->error(--p, "Cannot modify a buffer value with an expression of different return type"
                "\nExpected "+buffer_types[next]->name.to_string()+" but got "+vars[ret]->name.to_string());
        size_t count_alignment_bytes_offset = 0;
        for(const auto& pack : buffer_types[next]->packs) {
            if(!buffer_types[next]->contains(pack)) 
                imp->error(--p, "Internal error: failed to unpack value stored on buffer due to unknown type: "
                    +pack.to_string()
                );
            else if(buffer_types[next]->vars[pack]->name != NOM_VAR) {
                implementation += Code(
                    Variable("memcpy("), 
                    Variable("&((char*)"),
                    next+Variable("__buffer_contents"), 
                    Variable(")["), 
                    idx, 
                    MUL_VAR, 
                    next+Variable("__buffer_alignment"),
                    PLUS_VAR,
                    Variable(to_string(count_alignment_bytes_offset)),
                    Variable("]"),
                    COMMA_VAR,
                    REF_VAR,
                    ret+pack,
                    COMMA_VAR,
                    Variable(to_string(buffer_types[next]->vars[pack]->storage_size)),
                    RPAR_VAR, 
                    SEMICOLON_VAR
                );
            }
            else 
                alignments[next+pack] = buffer_types[next]->alignments[pack];
            count_alignment_bytes_offset += buffer_types[next]->vars[pack]->storage_size;
        }
        return ret;
    }

    if (p < imp->size() - 2 && imp->at(p) == "=") {
        // handle: buffer[index] = value
        p += 1;
        if (mutables.find(buffer_var) == mutables.end())
            imp->error(p, "Buffer is immutable: "
                + pretty_var(buffer_var.to_string())
                + "\nCannot assign into an element of an immutable buffer."
            );

        // parse value to assign
        size_t prev_p = p;
        string next_tok = imp->at(p++);
        Variable val = parse_expression(p, next_tok, types, EMPTY_VAR);
        if (!val.exists() || !contains(val))
            imp->error(prev_p, "Expression does not yield a value for buffer assignment");
        if (vars[val].get() != buffer_types[next].get())
            imp->error(prev_p, "Mismatching buffer types.\nTo prevent errors, no structural matching is allowed. Expected "
                + buffer_types[next]->signature(types) + " but got "
                + vars[val]->signature(types)
            );

        // locals (namespaced)
        vars[next + Variable("__buffer_size")]      = types.vars[Variable("u64")];
        vars[next + Variable("__buffer_alignment")] = types.vars[Variable("u64")];
        vars[next + Variable("__buffer_contents")]  = types.vars[Variable("ptr")];

        Variable fail_var = Variable("__result__buffer_error");
        implementation += Code(token_ifnot, next, token_goto, fail_var, SEMICOLON_VAR);

        // compute alignment size
        size_t alignment_bytes = 0;
        for (const auto& pack : buffer_types[next]->packs)
            alignment_bytes += buffer_types[next]->vars[pack]->storage_size;
        if (buffer_types[next]->_is_primitive)
            alignment_bytes += buffer_types[next]->storage_size;

        // assign metadata
        implementation += Code(
            next + Variable("__buffer_size"),
            ASSIGN_VAR,
            Variable("((u64*)"), next, Variable(")[1]"),
            SEMICOLON_VAR
        );

        implementation += Code(
            next + Variable("__buffer_alignment"),
            ASSIGN_VAR,
            Variable(to_string(alignment_bytes)),
            SEMICOLON_VAR
        );

        implementation += Code(
            next + Variable("__buffer_contents"),
            ASSIGN_VAR,
            Variable("(ptr)(((u64*)"), next, Variable(")[0])"),
            SEMICOLON_VAR
        );

        // range check
        implementation += Code(
            token_if,
            idx, Variable(">="),
            next + Variable("__buffer_size"),
            token_goto,
            fail_var,
            SEMICOLON_VAR
        );

        errors.insert(Code(
            fail_var,
            Variable(":\nprintf(\"Buffer error\\n\");\n__result__error_code=__BUFFER__ERROR;\ngoto __failsafe;\n")
        ));

        // write element packs at idx
        if (buffer_types[next]->_is_primitive) {
            implementation += Code(
                Variable("memcpy(&((char*)"),
                next + Variable("__buffer_contents"),
                Variable(")["),
                idx,
                MUL_VAR,
                next + Variable("__buffer_alignment"),
                Variable("], &"),
                val,
                Variable(", sizeof("),
                buffer_types[next]->name,
                Variable("))"),
                SEMICOLON_VAR
            );
        }
        else {
            size_t offset = 0;
            for (const auto& pack : buffer_types[next]->packs) {
                if (buffer_types[next]->contains(pack)
                    && buffer_types[next]->vars[pack]->name != NOM_VAR
                    && pack != ERR_VAR)
                {
                    implementation += Code(
                        Variable("memcpy(&((char*)"),
                        next + Variable("__buffer_contents"),
                        Variable(")["),
                        idx,
                        MUL_VAR,
                        next + Variable("__buffer_alignment"),
                        Variable("+" + to_string(offset) + "], &"),
                        val + pack,
                        Variable(", sizeof("),
                        buffer_types[next]->vars[pack]->name,
                        Variable("))"),
                        SEMICOLON_VAR
                    );
                    offset += buffer_types[next]->vars[pack]->storage_size;
                }
            }
        }

        // after assignment, return the buffer itself
        return EMPTY_VAR;
    }



    next = elem;
    return next;
}