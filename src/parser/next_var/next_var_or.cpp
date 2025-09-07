#include "../../def.h"

Variable Def::next_var_or(Variable next, const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test) {
    if(!internalTypes.contains(next)) 
        imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
    if(internalTypes.vars[next]!=types.vars[BOOL_VAR]) 
        imp->error(--p, "Left hand side of `or` expected bool but got "
            +internalTypes.vars[next]->name.to_string()
            +" "+pretty_var(next.to_string())
        );
    ++p;
    Variable prev = next;
    Variable tmp = create_temp();
    internalTypes.vars[tmp] = types.vars[LABEL_VAR];
    implementation += Code(
        token_if, 
        next, 
        token_goto, 
        tmp, 
        SEMICOLON_VAR
    );
    next = parse_expression(i, p, imp->at(p++), types);
    if(!internalTypes.contains(next)) 
        imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
    if(internalTypes.vars[next]!=types.vars[BOOL_VAR])
        imp->error(--p, "Right hand side of `or` expected bool but got "
            +internalTypes.vars[next]->name.to_string()
            +" "+pretty_var(next.to_string())
        );
    implementation += Code(
        prev, 
        ASSIGN_VAR, 
        next, 
        SEMICOLON_VAR, 
        tmp, 
        COLON_VAR
    );
    next = prev;
    return next;
}