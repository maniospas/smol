#include "../../../def.h"


Variable Def::parse_while(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos) {
    Variable temp = create_temp();
    Variable finally_var = temp+WHILE_VAR;
    uplifting_targets.push_back(finally_var);
    uplifiting_is_loop.push_back(true);
    Variable start_var = temp+LOOP_VAR;
    vars[start_var] = types.vars[LABEL_VAR];
    vars[finally_var] = types.vars[LABEL_VAR];
    implementation +=Code(start_var,COLON_VAR);
    Variable next = imp->at(p++);
    Variable var = parse_expression(imp, p, next, types, curry);
    if(!contains(var)) 
        imp->error(--p, "Expression did not evaluate to anything");
    if(vars.find(var)->second!=types.vars[BOOL_VAR]) 
        imp->error(--p, "If expects bool condition but got "
            +vars.find(var)->second->name.to_string()
            +" "+pretty_var(var.to_string())
        );
    implementation += Code(token_ifnot,var,token_goto,finally_var,SEMICOLON_VAR);
    parse(imp, p, types, false);
    p++; // offset p-- after parse_return above
    implementation += Code(Variable("goto"),start_var,SEMICOLON_VAR,finally_var,COLON_VAR);
    uplifting_targets.pop_back();
    uplifiting_is_loop.pop_back();
    return EMPTY_VAR;
}