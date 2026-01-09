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


Variable Def::parse_buffer_create(size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos, Type type) {
    auto surface = curry;
    if(imp->at(p)!="]") {
        if(surface.exists())
            imp->error(first_token_pos, "Cannot declare a buffer context through both curry and [context]: "+pretty_var(first_token.to_string())+"\nEither use [] or remove the curry");
        auto next = imp->at(p);
        p++;
        surface = parse_expression(p, next, types, EMPTY_VAR);
        if(!contains(surface) || !vars[surface]->buffer_ptr.exists())
            imp->error(first_token_pos, "Given that "
                +pretty_var(first_token.to_string())
                +" is a function (not a local variable), [] is expected to declare a buffer of its defined type here"
                +" or a @c_buffer type must be returned to serve as the buffer's allocation"
            );
        if(!can_mutate(surface, p) && !imp->allow_unsafe)
            imp->error(--p, "Buffer surface is not mutable: "+pretty_var(surface.to_string())+"\nIt might have been used elsewhere. Mark this file as @unsafe to allow a union view.");
        
        if(has_been_service_arg[surface]) 
            imp->error(--p, "Cannot set a buffer surface that has been previously passed as an `@own` argument: "
                +pretty_var(surface.to_string())
            );
        if(vars[surface]->not_primitive()) 
            for(const auto& pack : vars[surface]->packs)
                if(has_been_service_arg[surface+pack]) 
                    imp->error(--p, "Cannot set a buffer surface that has been previously passed as an `@own` argument: "
                        +pretty_var((surface+pack).to_string())
                    );
    }
    p++;
    if(type->options.size()==0) 
        imp->error(--p, "No options to determine buffer elements "
            +type->name.to_string()
            +"\nAdding `new` as first argument in the type's function definition"
            +" and returning that (e.g., with @args) may fix this issue; this would"
            +" enforce a specific selection among variations overloaded with the same name/union."
            +" This annoation directly interleaves the type in the definition"
            +" nand removes its lexical scoping."
        );
    double option_power = -1;
    int conflicts = 0;
    auto original_type = type;
    for(const auto& it : type->options) {
        if(it->choice_power>option_power) {// && it->name==argType->name) {
            option_power = it->choice_power;
            type = it;
            conflicts = 0;
        }
        else if(it->choice_power==option_power) 
            conflicts++;
    }
    if(option_power<0) 
        imp->error(--p, "No resolution options for determining buffer elements: "
            +original_type->name.to_string()
        );
    if(conflicts) 
        imp->error(--p, "There was no criterion for resolving buffer element to one option: "
            +original_type->name.to_string()
            +"\nMultiple options are available"
        );

    auto var = Variable{create_temp()};
    mutables.insert(var);
    auto dynamic_var = var+Variable("dynamic");
    auto surface_var = var+Variable("surface");
    buffer_types[dynamic_var] = type;
    vars[var] = types.vars[BUFFER_VAR];
    vars[dynamic_var] = types.vars[PTR_VAR];
    //vars[var+Variable("surface")] = types.vars[PTR_VAR];
    auto raw_var = var;
    var = dynamic_var;
    implementation += Code(
        var,
        ASSIGN_VAR,
        Variable("__runtime_calloc(3*sizeof(u64))"),
        SEMICOLON_VAR
    ); // ZERO OUT MEMORY, SIZE, CAPACITY (MSB of capacity holds whether the buffer is statically initialized)
    if(surface.exists()) {
        assert_compatible(surface+vars[surface]->buffer_ptr, type, p);
        size_t count_packs = 0;
        for(const auto& pack : type->packs)
            if(type->contains(pack) && type->vars[pack]->name!=NOM_VAR && pack!=ERR_VAR)
                count_packs++;
        if(type->_is_primitive) 
            count_packs++;
        implementation += Code(
            Variable("((u64*)"),var,Variable(")[0]"), 
            ASSIGN_VAR, Variable("(u64)(u64*)"), 
            surface+vars[surface]->buffer_ptr, 
            SEMICOLON_VAR
        );
        current_renaming[var] = surface+vars[surface]->buffer_ptr;
        current_renaming[surface+vars[surface]->buffer_ptr] = var;
        implementation += Code(
            Variable("((u64*)"),
            var,
            Variable(")[2]"), 
            ASSIGN_VAR, 
            LPAR_VAR,
            surface+vars[surface]->buffer_size, 
            Variable("/(sizeof(u64)*"+to_string(count_packs)+")) | (1ULL <<63)"), 
            SEMICOLON_VAR
        );
        //coalesce_finals(var);
        finals[var] += Code(
            token_if, var, RPAR_VAR,
            Variable("__runtime_free("),var,RPAR_VAR,SEMICOLON_VAR,
            var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR
        );
        assign_variable(
            types.vars[PTR_VAR], 
            surface_var, 
            surface+vars[surface]->buffer_release, 
            p
        );

        // returning simplifications may split the memory pointers into two independent sets of finals that reference the same memory - gather in one place
        // coalesce_finals(surface+vars[surface]->buffer_ptr);
        // finals[surface_var] += rename_var(finals[surface+vars[surface]->buffer_ptr], surface+vars[surface]->buffer_ptr, surface_var);
        // finals[surface+vars[surface]->buffer_ptr] = Code();
        // do this in two stages, in case buffer_ptr is buffer_release
        coalesce_finals(surface+vars[surface]->buffer_release);
        finals[surface_var] += rename_var(finals[surface+vars[surface]->buffer_release], surface+vars[surface]->buffer_release, surface_var);
        finals[surface+vars[surface]->buffer_release] = Code();
    }
    else {
        assign_variable(
            types.vars[PTR_VAR], 
            surface_var,
            ZERO_VAR, 
            p
        );
        finals[var] += Code(
            token_if, var, Variable("){if((u64*)((u64*)"),var,Variable(")[2])"), // deallocate only if we have allocated any capacity
            Variable("__runtime_free((u64*)((u64*)"),var,Variable(")[0])"),SEMICOLON_VAR,
            Variable("__runtime_free("),var,RPAR_VAR,SEMICOLON_VAR,
            var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR,
            Variable("}"));
    }
    return next_var(p, raw_var, types);
}