#include "../../../def.h"


Variable Def::parse_buffer_create(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos, Type type) {
    Variable surface = EMPTY_VAR;
    if(imp->at(p)!="]") {
        string next = imp->at(p);
        p++;
        surface = parse_expression(imp, p, next, types, EMPTY_VAR);
        if(!contains(surface) || !vars[surface]->buffer_ptr.exists())
            imp->error(--p, "Given that "
                +first_token.to_string()
                +" is a runtype (not a local variable), [] is expected to declare a buffer here"
                +" or a @buffer runtype must be returned to serve as the buffer's allocation"
            );
        if(!can_mutate(surface, p) && !imp->allow_unsafe)
            imp->error(--p, "Buffer surface is not mutable: "+pretty_var(surface.to_string())+"\nIt might have been used elsewhere. Mark this file as @unsafe to allow a union view.");
    }
    p++;
    if(type->options.size()==0) 
        imp->error(--p, "No options to determine buffer elements "
            +type->name.to_string()
            +"\nAdding before the argument's type may resolve this issue"
            +"\nby forcing usage of the a runtype with ->in its return"
            +"\namong those overloaded with the same name/union."
            +"\nThis annoation directly interleaves the type in the definition"
            +"\nand removes its lexical scoping."
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

    Variable var = create_temp();
    mutables.insert(var);
    Variable dynamic_var = var+Variable("dynamic");
    Variable surface_var = var+Variable("surface");
    buffer_types[dynamic_var] = type;
    vars[var] = types.vars[BUFFER_VAR];
    vars[dynamic_var] = types.vars[PTR_VAR];
    //vars[var+Variable("surface")] = types.vars[PTR_VAR];
    Variable raw_var = var;
    var = dynamic_var;
    implementation += Code(
        var,
        ASSIGN_VAR,
        Variable("__runtime_calloc(3*sizeof(u64))"),
        SEMICOLON_VAR
    ); // ZERO OUT MEMORY, SIZE, CAPACITY (MSB of capacity holds whether the buffer is statically initialized)
    if(surface.exists()) {
        size_t count_packs = 0;
        for(const auto& pack : type->packs)
            if(type->contains(pack) && type->vars[pack]->name!=NOM_VAR)
                count_packs++;
        if(type->_is_primitive) 
            count_packs++;
        implementation += Code(
            Variable("((u64*)"),var,Variable(")[0]"), 
            ASSIGN_VAR, Variable("(u64)(u64*)"), 
            surface+vars[surface]->buffer_ptr, 
            SEMICOLON_VAR
        );
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
        finals[var] += Code(
            token_if, var, RPAR_VAR,
            Variable("__runtime_free("),var,RPAR_VAR,SEMICOLON_VAR,
            var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR
        );
        assign_variable(
            types.vars[PTR_VAR], 
            surface_var, 
            surface+vars[surface]->buffer_release, 
            imp, 
            p
        );

        // returning simplifcations may split the memory poiters into two independent sets of finals that reference the same memory - gather in one place
        coallesce_finals(surface+vars[surface]->buffer_ptr);
        coallesce_finals(surface+vars[surface]->buffer_release);
        finals[surface_var] = 
                rename_var(finals[surface+vars[surface]->buffer_ptr], surface+vars[surface]->buffer_ptr, surface_var)
                +rename_var(finals[surface+vars[surface]->buffer_release], surface+vars[surface]->buffer_release, surface_var);
        finals[surface+vars[surface]->buffer_ptr] = Code();
        finals[surface+vars[surface]->buffer_release] = Code();
    }
    else {
        assign_variable(
            types.vars[PTR_VAR], 
            surface_var,
            ZERO_VAR, 
            imp, 
            p
        );
        finals[var] += Code(
            token_if, var, Variable("){if((u64*)((u64*)"),var,Variable(")[2])"), // deallocate only if we have allocated any capacity
            Variable("__runtime_free((u64*)((u64*)"),var,Variable(")[0])"),SEMICOLON_VAR,
            Variable("__runtime_free("),var,RPAR_VAR,SEMICOLON_VAR,
            var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR,
            Variable("}"));
    }
    return next_var(imp, p, raw_var, types);
}