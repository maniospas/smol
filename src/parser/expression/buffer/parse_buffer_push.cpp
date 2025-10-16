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


Variable Def::parse_buffer_push(size_t& p, Types& types, Variable curry, size_t first_token_pos) {
    if(imp->at(p++)!="(") 
        imp->error(--p, "Expected opening parenthesis");
    if(mutables.find(curry)==mutables.end()) 
        imp->error(--p, "Cannot push onto a non-mutable buffer");
    Variable raw_var = curry;
    curry = curry+Variable("dynamic");
    if(!can_mutate(curry, p))
        imp->error(--p, "Cannot push onto a non-mutable buffer");
    if(buffer_types.find(curry)==buffer_types.end())
        imp->error(first_token_pos, "Internal error: buffer has not been properly transferred to scope");
    auto prev_p = p;
    string next = imp->at(p++);
    Variable var = parse_expression(p, next, types, EMPTY_VAR);
    if(!var.exists() || !vars[var]) 
        imp->error(prev_p, "Expression does not yield a value within push");
    if(vars[var].get() != buffer_types[curry].get())
        imp->error(prev_p, "Not found type on buffer\nTo prevent errors, no structural matching of the types is allowed.\nExpected " 
            + buffer_types[curry]->signature(types) 
            + " but got " 
            + vars[var]->signature(types)
        );
    if(imp->at(p++)!=")") 
        imp->error(--p, "Expecting closing parenthesis");

    vars[curry+Variable("__buffer_size")]          = types.vars[Variable("u64")];
    vars[curry+Variable("__buffer_capacity")]      = types.vars[Variable("u64")];
    vars[curry+Variable("__buffer_prev_capacity")] = types.vars[Variable("u64")];
    vars[curry+Variable("__buffer_alignment")]     = types.vars[Variable("u64")];
    vars[curry+Variable("__buffer_contents")]      = types.vars[Variable("ptr")];

    Variable fail_var = Variable("__result__buffer_error"); //create_temp();
    implementation += Code(
        token_ifnot, 
        curry, 
        token_goto,
        fail_var, 
        SEMICOLON_VAR
    );

    // compute count_packs (valid packs only)
    size_t count_packs = 0;
    for(const auto& pack : buffer_types[curry]->packs)
        if(buffer_types[curry]->contains(pack) && buffer_types[curry]->vars[pack]->name!=NOM_VAR && pack!=ERR_VAR)
            count_packs++;
    if(buffer_types[curry]->_is_primitive) count_packs++;

    implementation += Code(curry+Variable("__buffer_alignment"), ASSIGN_VAR, Variable(to_string(count_packs)), SEMICOLON_VAR);
    implementation += Code(curry+Variable("__buffer_size"), ASSIGN_VAR, Variable("((u64*)"), curry, Variable(")[1]"), SEMICOLON_VAR);
    implementation += Code(curry+Variable("__buffer_capacity"), ASSIGN_VAR, Variable("((u64*)"), curry, Variable(")[2] & ~(1ULL << 63)"), SEMICOLON_VAR);

    static const Variable token_print = Variable(":\nprintf(\"Buffer error\\n\");\n__result__error_code=__BUFFER__ERROR;\ngoto __failsafe;\n");

    implementation += Code(token_if, curry+Variable("__buffer_size"),
        Variable(">="), curry+Variable("__buffer_capacity"), Variable("){"));

    implementation += Code(token_if,
        Variable("((u64*)"), curry, Variable(")[2] & (1ULL << 63)"),
        token_goto, fail_var, SEMICOLON_VAR);

    implementation += Code(curry+Variable("__buffer_prev_capacity"), ASSIGN_VAR,
        curry+Variable("__buffer_capacity"), SEMICOLON_VAR);

    implementation += Code(curry+Variable("__buffer_capacity"), ASSIGN_VAR,
        curry+Variable("__buffer_capacity"),
        Variable("+("), curry+Variable("__buffer_capacity"), Variable(">>2)+1;")); // +25%+1 capacity

    // realloc path
    implementation += Code(token_if, curry+Variable("__buffer_size"),
        Variable(") ((void**)"), curry,
        Variable(")[0] = __runtime_realloc((u64*)((void**)"), curry,
        Variable(")[0], "),
        curry+Variable("__buffer_capacity"), MUL_VAR, curry+Variable("__buffer_alignment"),
        Variable("*sizeof(u64), "),
        curry+Variable("__buffer_prev_capacity"), MUL_VAR, curry+Variable("__buffer_alignment"),
        Variable("*sizeof(u64));"));

    // alloc path
    implementation += Code(Variable("else ((void**)"), curry,
        Variable(")[0] = __runtime_alloc("),
        curry+Variable("__buffer_capacity"), Variable("*"),
        curry+Variable("__buffer_alignment"), Variable("*sizeof(u64));"));

    // update capacity
    implementation += Code(Variable("((u64*)"), curry, Variable(")[2]"),
        ASSIGN_VAR, curry+Variable("__buffer_capacity"), SEMICOLON_VAR);

    // set buffer_contents
    implementation += Code(curry+Variable("__buffer_contents"), ASSIGN_VAR,
        Variable("(ptr)((void**)"), curry, Variable(")[0]"), SEMICOLON_VAR);


    //vars[fail_var] = types.vars[LABEL_VAR];
    implementation += Code(token_ifnot, curry+Variable("__buffer_contents"), token_goto, fail_var, SEMICOLON_VAR);
    errors.insert(Code(fail_var, token_print));

    implementation += Code(Variable("} else "));
    implementation += Code(curry+Variable("__buffer_contents"), ASSIGN_VAR, Variable("(ptr)(((u64*)"), curry, Variable(")[0])"), SEMICOLON_VAR);
    implementation += Code(Variable("((u64*)"), curry, Variable(")[1]"), ASSIGN_VAR, curry+Variable("__buffer_size"), Variable("+1"), SEMICOLON_VAR);

    // final loop: move only valid packs
    size_t pack_index = 0;
    if(buffer_types[curry]->_is_primitive) {
        implementation += Code(
            Variable("memcpy(&((u64*)"), curry+Variable("__buffer_contents"), Variable(")["), curry+Variable("__buffer_size"), MUL_VAR, curry+Variable("__buffer_alignment"), Variable("], &"),
            var,
            Variable(", sizeof(u64));")
        );
    }
    else for(const auto& pack : buffer_types[curry]->packs) {
        if(buffer_types[curry]->contains(pack) 
            && buffer_types[curry]->vars[pack]->name!=NOM_VAR
            && pack!=ERR_VAR
        ) {
            implementation += Code(
                Variable("memcpy(&((u64*)"), curry+Variable("__buffer_contents"), Variable(")["), curry+Variable("__buffer_size"), MUL_VAR, curry+Variable("__buffer_alignment"), Variable("+"+to_string(pack_index)+"], &"),
                var+Variable(pack),
                Variable(", sizeof("+buffer_types[curry]->vars[pack]->name.to_string()+"));")
            );
            pack_index++;
        }
    }
    return next_var(p, raw_var, types);
}