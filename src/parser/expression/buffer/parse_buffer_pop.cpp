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
#include "../../../def.h"

Variable Def::parse_buffer_pop(size_t& p, Types& types, Variable curry, size_t first_token_pos) {
    if(imp->at(p++)!="(")
        imp->error(--p, "Expected opening parenthesis");

    if(mutables.find(curry)==mutables.end())
        imp->error(--p, "Cannot pop from a non-mutable buffer");

    
    if(active_calls[curry].exists() && active_calls[active_calls[curry]].exists()) {
        static const Variable token_print = Variable(":\n__result__error_code=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
        const Variable& call_var = active_calls[curry];
        implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
        vars[curry+ERR_VAR] = types.vars[ERRCODE_VAR];
        implementation += Code(
            call_var+ERR_VAR, 
            ASSIGN_VAR, 
            call_var+STATE_VAR, 
            ARROW_VAR, 
            ERR_VAR, 
            SEMICOLON_VAR
        );
        implementation += Code(
            curry+ERR_VAR, 
            ASSIGN_VAR, 
            call_var+ERR_VAR,
            SEMICOLON_VAR
        );
        Variable fail_var = create_temp();
        vars[fail_var] = types.vars[LABEL_VAR];
        implementation += Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
        errors.insert(Code(fail_var, token_print));
        add_preamble("#include <stdio.h>");
        if(active_calls[curry].exists() && active_calls[active_calls[curry]].exists()) 
            active_calls[active_calls[curry]] = EMPTY_VAR;
    }

    Variable raw_var = curry;
    curry = curry + Variable("dynamic");
    if(!can_mutate(curry, p))
        imp->error(--p, "Cannot pop from a non-mutable buffer");

    if(buffer_types.find(curry)==buffer_types.end())
        imp->error(first_token_pos, "Internal error: buffer has not been properly transferred to scope");

    if(imp->at(p++)!=")")
        imp->error(--p, "Expecting closing parenthesis");

    auto elem_type = buffer_types[curry];
    Variable result_var = Variable(create_temp());
    vars[result_var] = elem_type;
    for (const auto& pack : elem_type->packs)
        vars[result_var + pack] = elem_type->vars[pack];

    Variable fail_var = Variable("__result__buffer_pop_error");

    vars[curry+Variable("__buffer_size")]     = types.vars[Variable("u64")];
    vars[curry+Variable("__buffer_capacity")] = types.vars[Variable("u64")];
    vars[curry+Variable("__buffer_alignment")] = types.vars[Variable("u64")];
    vars[curry+Variable("__buffer_contents")] = types.vars[Variable("ptr")];

    implementation += Code(
        token_ifnot, curry, token_goto, fail_var, SEMICOLON_VAR
    );

    size_t alignment_bytes = 0;
    for(const auto& pack : elem_type->packs)
        alignment_bytes += elem_type->vars[pack]->storage_size;
    if(elem_type->_is_primitive)
        alignment_bytes += elem_type->storage_size;

    implementation += Code(
        curry+Variable("__buffer_alignment"), ASSIGN_VAR,
        Variable(to_string(alignment_bytes)), SEMICOLON_VAR
    );

    implementation += Code(
        curry+Variable("__buffer_size"), ASSIGN_VAR,
        Variable("((u64*)"), curry, Variable(")[1]"),
        SEMICOLON_VAR
    );

    implementation += Code(
        curry+Variable("__buffer_capacity"), ASSIGN_VAR,
        Variable("((u64*)"), curry, Variable(")[2] & ~(1ULL << 63)"),
        SEMICOLON_VAR
    );

    implementation += Code(
        token_ifnot,
        curry+Variable("__buffer_size"),
        token_goto,
        fail_var,
        SEMICOLON_VAR
    );

    implementation += Code(
        curry+Variable("__buffer_contents"), ASSIGN_VAR,
        Variable("(ptr)((void**)"), curry, Variable(")[0]"),
        SEMICOLON_VAR
    );

    implementation += Code(
        token_ifnot,
        curry+Variable("__buffer_contents"),
        token_goto,
        fail_var,
        SEMICOLON_VAR
    );

    Variable idx = create_temp();
    vars[idx] = types.vars[Variable("u64")];
    implementation += Code(
        idx, ASSIGN_VAR,
        curry+Variable("__buffer_size"), Variable("-1"),
        SEMICOLON_VAR
    );

    if(elem_type->_is_primitive) {
        implementation += Code(
            Variable("memcpy("),
                Variable("&"), result_var, COMMA_VAR,
                Variable("&((char*)"), curry+Variable("__buffer_contents"), Variable(")["),
                    idx, MUL_VAR, curry+Variable("__buffer_alignment"),
                Variable("]"),
                COMMA_VAR,
                Variable(to_string(alignment_bytes)),
            RPAR_VAR, SEMICOLON_VAR
        );
    }
    else {
        size_t offset = 0;
        for(const auto& pack : elem_type->packs) {
            size_t storage = elem_type->vars[pack]->storage_size;
            if(!storage) continue;

            implementation += Code(
                Variable("memcpy("),
                    Variable("&"), result_var+pack, COMMA_VAR,
                    Variable("&((char*)"), curry+Variable("__buffer_contents"), Variable(")["),
                        idx, MUL_VAR, curry+Variable("__buffer_alignment"),
                        PLUS_VAR, Variable(to_string(offset)),
                    Variable("]"),
                    COMMA_VAR,
                    Variable(to_string(storage)),
                RPAR_VAR, SEMICOLON_VAR
            );

            offset += storage;
        }
    }


    implementation += Code(
        Variable("((u64*)"), curry, Variable(")[1]"),
        ASSIGN_VAR,
        idx,
        SEMICOLON_VAR
    );

    static const Variable token_print =
        Variable(":\nprintf(\"Buffer error\\n\");\n__result__error_code=__BUFFER__ERROR;\ngoto __failsafe;\n");

    errors.insert(Code(fail_var, token_print));

    return next_var(p, result_var, types);
}
