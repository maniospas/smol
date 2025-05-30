vector<string> Def::gather_tuple(const shared_ptr<Import>& imp, size_t& p, Memory& types, string& inherit_buffer, const string& curry) {
    vector<string> ret;
    if(curry.size()) {
        string var = curry;
        if(!internalTypes.contains(var)) imp->error(p, "Missing symbol: "+pretty_var(var)+recommend_variable(types, var));
        const auto& type = internalTypes.vars.find(var)->second;
        if(type->name=="buffer") inherit_buffer = var;
        else {
            if(!type->not_primitive()) ret.push_back(var);
            else if(type->is_service) {
                string fail_var = create_temp();
                implementation += "if("+var+"__err) goto "+fail_var+";\n";
                errors += fail_var+":\nprintf(\"Runtime error from "+type->name+" "+pretty_var(var)+"\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n";
                add_preample("#include <stdio.h>");
                for(size_t i=1;i<type->packs.size();++i) ret.push_back(var+"__"+type->packs[i]);
            }
            else for(const string& pack : type->packs) ret.push_back(var+"__"+pack);
        }
        string next = imp->at(p);
        if(next==")") return ret;
        if(inherit_buffer.size()) imp->error(--p, "Buffer can only be the last argument to unpack");
    }
    while(true) {
        int expression_start = p;
        string next = imp->at(p++);
        if(next==")") {--p;break;}
        string var = parse_expression(imp, p, next, types);
        if(!internalTypes.contains(var)) imp->error(expression_start, "Failed to parse expression");
        const auto& type = internalTypes.vars[var];
        if(type->name=="buffer") inherit_buffer = var;
        else {
            if(!type->not_primitive()) ret.push_back(var);
            else if(type->is_service) {
                string fail_var = create_temp();
                implementation += "if("+var+"__err) goto "+fail_var+";\n";
                errors += fail_var+":\nprintf(\"Runtime error from "+type->name+" "+pretty_var(var)+"\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n";
                add_preample("#include <stdio.h>");
                for(size_t i=1;i<type->packs.size();++i) ret.push_back(var+"__"+type->packs[i]);
            }
            else for(const string& pack : type->packs) ret.push_back(var+"__"+pack);
        }
        next = imp->at(p++);
        if(next==")") {--p;break;}
        if(inherit_buffer.size()) imp->error(--p, "Buffer can only be the last argument to unpack");
        if(next!=",") imp->error(--p, "Missing comma");
    }
    return ret;
}
