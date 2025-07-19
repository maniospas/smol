#include "../def.h"


vector<Variable> Def::gather_tuple(const shared_ptr<Import>& imp, size_t& p, Types& types, Variable& inherit_buffer, const Variable& curry) {
    static const Variable token_if = Variable("if(");
    static const Variable token_goto = Variable(") goto");
    static const Variable token_print = Variable(":\nprintf(\"Runtime error from");
    static const Variable token_failsafe = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");

    vector<Variable> ret;
    if(curry.exists()) {
        Variable var = curry;
        if(!internalTypes.contains(var)) imp->error(p, "Not found: "+pretty_var(var.to_string())+recommend_variable(types, var));
        const auto& type = internalTypes.vars.find(var)->second;
        if(type->name=="buffer") inherit_buffer = var;
        else {
            if(!type->not_primitive()) ret.push_back(var);
            else if(type->is_service) {
                Variable fail_var = create_temp();
                internalTypes.vars[fail_var] = types.vars[LABEL_VAR];
                implementation +=Code(token_if, var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
                errors = errors+Code(fail_var, token_print,type->name,var, token_failsafe);
                add_preample("#include <stdio.h>");
                for(size_t i=1;i<type->packs.size();++i) ret.push_back(var+type->packs[i]);
            }
            else for(const Variable& pack : type->packs) ret.push_back(var+pack);
        }
        string next = imp->at(p);
        if(next==")") return ret;
        if(inherit_buffer.exists()) imp->error(--p, "Buffer can only be the last argument to unpack");
    }
    while(true) {
        int expression_start = p;
        string next = imp->at(p++);
        if(next==")") {--p;break;}
        Variable var = parse_expression(imp, p, next, types);
        if(!internalTypes.contains(var)) imp->error(expression_start, "Failed to parse expression");
        const auto& type = internalTypes.vars[var];
        if(type->name==BUFFER_VAR) inherit_buffer = var;
        else {
            if(!type->not_primitive()) ret.push_back(var);
            else if(type->is_service) {
                Variable fail_var = create_temp();
                internalTypes.vars[fail_var] = types.vars[LABEL_VAR];
                implementation +=Code(token_if,var+ERR_VAR,token_goto,fail_var, SEMICOLON_VAR);
                errors = errors+Code(fail_var, token_print, type->name, var, token_failsafe);
                add_preample("#include <stdio.h>");
                for(size_t i=1;i<type->packs.size();++i) ret.push_back(var+type->packs[i]);
            }
            else for(const Variable& pack : type->packs) ret.push_back(var+pack);
        }
        next = imp->at(p++);
        if(next==")") {--p;break;}
        if(inherit_buffer.exists()) imp->error(--p, "Buffer can only be the last argument to unpack");
        if(next!=",") imp->error(--p, "Missing comma");
    }
    return ret;
}
