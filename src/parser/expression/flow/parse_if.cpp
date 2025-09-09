#include "../../../def.h"


Variable Def::parse_if(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos) {
    Variable temp = create_temp();
    Variable finally_var = temp+IF_VAR;
    Variable closeif_var = temp+FI_VAR;
    uplifting_targets.push_back(finally_var);
    if(uplifiting_is_loop.size()) 
        uplifiting_is_loop.push_back(uplifiting_is_loop.back());
    else 
        uplifiting_is_loop.push_back(false);
    vars[finally_var] = types.vars[LABEL_VAR];
    vars[closeif_var] = types.vars[LABEL_VAR];
    string next = imp->at(p++);
    Variable var = parse_expression(imp, p, next, types, curry);
    if(!contains(var)) 
        imp->error(--p, "Expression did not evaluate to anything");
    if(vars.find(var)->second!=types.vars[BOOL_VAR]) 
        imp->error(--p, "If expects bool condition but got "
            +vars.find(var)->second->name.to_string()
            +" "+pretty_var(var.to_string())
        );
    implementation += Code(token_ifnot,var,token_goto,closeif_var,SEMICOLON_VAR);
    parse(imp, p, types, false);
    p++; // offset p-- after parse_return above
    Variable else_var = EMPTY_VAR;
    Variable rfinally_var = finally_var+Variable("r");
    if(p<imp->size()-1 && imp->at(p)=="else") {
        p++;
        else_var = temp+LE_VAR;
        Variable relse_var = else_var+Variable("r");
        vars[else_var] = types.vars[LABEL_VAR];
        Variable else_skip = temp+EL_VAR;
        vars[else_skip] = types.vars[LABEL_VAR];
        uplifting_targets.pop_back();
        uplifting_targets.push_back(else_var);
        implementation += Code(finally_var,COLON_VAR,Variable("goto"), else_skip, SEMICOLON_VAR, closeif_var, COLON_VAR);
        parse(imp, p, types, false);
        implementation += Code(else_var,COLON_VAR);
        p++; // offset p-- after parse_return above
        if(contains(relse_var) && !contains(rfinally_var)) 
            imp->error(first_token_pos, "There was a non-empty return "
                +vars[relse_var]->name.to_string()
                +" `else` but no such value from `if`"
            );
        if(!contains(relse_var) && contains(rfinally_var)) 
            imp->error(first_token_pos, "There was a non-empty return "
                +vars[rfinally_var]->name.to_string()
                +" `if` but no such value from `else` "
            );
        if(contains(relse_var) && contains(rfinally_var)) {
            if(vars[rfinally_var]!=vars[relse_var]) 
                imp->error(first_token_pos, "There were mismatching return "
                    +vars[rfinally_var]->name.to_string()
                    +" `if` and "+vars[relse_var]->name.to_string()+" `else`"
                );
            assign_variable(
                vars[rfinally_var], 
                rfinally_var, 
                relse_var, 
                imp, 
                first_token_pos, 
                false, 
                false
            );
        }
        implementation += Code(else_skip,COLON_VAR);
    }
    else 
        implementation += Code(finally_var,COLON_VAR,closeif_var,COLON_VAR);
    uplifting_targets.pop_back();
    uplifiting_is_loop.pop_back();
    if(contains(rfinally_var)) {
        if(else_var.exists()==0) 
            imp->error(first_token_pos, "There was a non-empty return "
                +vars[rfinally_var]->name.to_string()
                +" `if` but no `else` statement for the alternative"
            ); 
        return rfinally_var;
    }
    return EMPTY_VAR;
}