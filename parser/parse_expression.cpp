string next_var(const shared_ptr<Import>& i, size_t& p, const string& first_token, bool test=true) {
    string next = first_token;
    while(imp->at(p)==".") {
        //if(internalTypes.vars.find(next)==internalTypes.vars.end() && !is_primitive(next)) imp->error(--p, "Symbol not declared"); // declare all up to this point
        next += "__";++p;next += imp->at(p++);
    }
    if(test && internalTypes.vars.find(next)==internalTypes.vars.end() && !is_primitive(next)) imp->error(--p, "Symbol not declared");
    return next;
}

string parse_expression(const shared_ptr<Import>& imp, size_t& p, const string& first_token, const Memory& types) {
    if(is_primitive(first_token)) {
        string var = create_temp();
        string vartype = type_primitive(first_token);
        if(types.vars.find(vartype)==types.vars.end()) return first_token;// fallback
        internalTypes.vars[var] = types.vars.find(vartype)->second;
        vardecl += vartype+" "+var+" = "+first_token+";\n";
        return var;
    }
    string var = next_var(imp, p, first_token);
    //if(types.vars.find(var)!=types.end() && (p>=imp->size()-1 || imp->at(p+1)=="(")
    if(internalTypes.vars.find(var)!=internalTypes.vars.find(var)) return var;
    return var;
}
