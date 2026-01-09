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


Variable Def::parse_buffer_put(size_t& p, Types& types, Variable curry, size_t first_token_pos) {
    Variable raw_var = curry;
    if(imp->at(p++)!="(") 
        imp->error(first_token_pos, "Expected opening parenthesis");
    if(mutables.find(curry)==mutables.end()) 
        imp->error(first_token_pos, "Cannot put into a non-mutable buffer");

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


    curry = curry+Variable("dynamic");
    if(!can_mutate(curry, p))
        imp->error(--p, "Cannot push onto a non-mutable buffer");
    if(buffer_types.find(curry)==buffer_types.end()) 
        imp->error(--p, "Internal error: buffer has not been properly transferred to scope: "+curry.to_string());
    size_t prev_p = p;
    string next_tok = imp->at(p++);
    Variable idx = parse_expression(p, next_tok, types, EMPTY_VAR);
    if(!idx.exists() || !contains(idx) || vars[idx]->name!=U64_VAR)
        imp->error(prev_p, "First argument to put must be u64 but got "
            + (contains(idx)?vars[idx]->name.to_string():"nothing")
        );
    if(imp->at(p++)!=",") 
        imp->error(--p, "Expected comma after buffer index");

    prev_p = p;
    next_tok = imp->at(p++);
    Variable val = parse_expression(p, next_tok, types, EMPTY_VAR);
    if(!val.exists() || !contains(val)) 
        imp->error(prev_p, "Expression does not yield a value within put");
    if(vars[val].get() != buffer_types[curry].get())
        imp->error(prev_p, "Mismatching buffer types.\nTo prevent errors, no structural matching is allowed. Expected "
            +buffer_types[curry]->signature(types)+" but got "
            +vars[val]->signature(types)
        );

    if(imp->at(p++)!=")") 
        imp->error(--p, "Expecting closing parenthesis");

    // locals (namespaced)
    vars[curry+Variable("__buffer_size")]      = types.vars[Variable("u64")];
    vars[curry+Variable("__buffer_alignment")] = types.vars[Variable("u64")];
    vars[curry+Variable("__buffer_contents")]  = types.vars[Variable("ptr")];
    
    Variable fail_var = Variable("__result__buffer_error"); //create_temp();
    implementation += Code(
        token_ifnot, 
        curry, 
        token_goto,
        fail_var, 
        SEMICOLON_VAR
    );

    // compute count_packs (valid packs only)
    size_t count_alignment_bytes = 0;
    for(const auto& pack : buffer_types[curry]->packs)
        count_alignment_bytes += buffer_types[curry]->vars[pack]->storage_size;
    if(buffer_types[curry]->_is_primitive) 
        count_alignment_bytes += buffer_types[curry]->storage_size;

    implementation += Code(curry+Variable("__buffer_size"), ASSIGN_VAR, Variable("((u64*)"), curry, Variable(")[1]"), SEMICOLON_VAR);
    implementation += Code(curry+Variable("__buffer_alignment"), ASSIGN_VAR, Variable(to_string(count_alignment_bytes)), SEMICOLON_VAR);
    implementation += Code(curry+Variable("__buffer_contents"), ASSIGN_VAR, Variable("(ptr)(((u64*)"), curry, Variable(")[0])"), SEMICOLON_VAR);

    // range check
    //vars[fail_var] = types.vars[LABEL_VAR];
    implementation += Code(token_if, idx, Variable(">="), curry+Variable("__buffer_size"),Variable(")goto"), fail_var, SEMICOLON_VAR);
    errors.insert(Code(fail_var, Variable(":\nprintf(\"Buffer error\\n\");\n__result__error_code=__BUFFER__ERROR;\ngoto __failsafe;\n")));

    // write element packs at idx
    size_t count_alignment_bytes_index = 0;
    if(buffer_types[curry]->_is_primitive) {
        implementation += Code(
            Variable("memcpy(&((char*)"), 
            curry+Variable("__buffer_contents"), 
            Variable(")["), 
            idx, 
            MUL_VAR, 
            curry+Variable("__buffer_alignment"),
            Variable("], &"),
            val,
            COMMA_VAR,
            Variable(to_string(count_alignment_bytes)),
            RPAR_VAR, 
            SEMICOLON_VAR
        );
    }
    else 
        for(const auto& pack : buffer_types[curry]->packs) {
            size_t storage = buffer_types[curry]->vars[pack]->storage_size;
            if(storage){
                implementation += Code(
                    Variable("memcpy(&((char*)"), 
                    curry+Variable("__buffer_contents"), 
                    Variable(")["), 
                    idx, 
                    MUL_VAR, 
                    curry+Variable("__buffer_alignment"), 
                    Variable("+"+to_string(count_alignment_bytes_index)+"], &"),
                    val+Variable(pack),
                    COMMA_VAR,
                    Variable(to_string(storage)),
                    RPAR_VAR,
                    SEMICOLON_VAR
                );
                count_alignment_bytes_index += storage;
            }
        }

    return next_var(p, raw_var, types);
}