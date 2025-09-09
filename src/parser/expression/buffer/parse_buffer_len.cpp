#include "../../../def.h"


Variable Def::parse_buffer_len(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos) {
    curry = curry+Variable("dynamic");
    vars[Variable("__buffer_size")] = types.vars[Variable("u64")];
    implementation += Code(
        Variable("__buffer_size"), 
        ASSIGN_VAR, 
        curry,
        Variable("?"),
        Variable("((u64*)"), 
        curry, 
        Variable(")[1]:0"), 
        SEMICOLON_VAR
    );
    return next_var(imp, p, Variable("__buffer_size"), types);
}