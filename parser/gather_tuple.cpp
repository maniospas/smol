vector<string> Def::gather_tuple(const shared_ptr<Import>& imp, size_t& p, Memory& types, string& inherit_buffer, const string& curry) {
    vector<string> ret;
    if(curry.size()) {
        string var = curry;
        if(!internalTypes.contains(var)) imp->error(p, "Failed to parse expression");
        if(internalTypes.vars.find(var)->second->name=="buffer") inherit_buffer = var;
        else {
            if(!internalTypes.vars.find(var)->second->not_primitive()) ret.push_back(var);
            for(const string& pack : internalTypes.vars.find(var)->second->packs) ret.push_back(var+"__"+pack);
        }
        string next = imp->at(p++);
        if(next==")") {--p;return ret;}
        if(inherit_buffer.size()) imp->error(--p, "Buffer can only be the last argument to unpack");
        if(next!=",") imp->error(--p, "Missing comma");
    }
    while(true) {
        int expression_start = p;
        string next = imp->at(p++);
        if(next==")") {--p;break;}
        string var = parse_expression(imp, p, next, types);
        if(!internalTypes.contains(var)) imp->error(expression_start, "Failed to parse expression");
        if(internalTypes.vars.find(var)->second->name=="buffer") inherit_buffer = var;
        else {
            if(!internalTypes.vars.find(var)->second->not_primitive()) ret.push_back(var);
            for(const string& pack : internalTypes.vars.find(var)->second->packs) ret.push_back(var+"__"+pack);
        }
        next = imp->at(p++);
        if(next==")") {--p;break;}
        if(inherit_buffer.size()) imp->error(--p, "Buffer can only be the last argument to unpack");
        if(next!=",") imp->error(--p, "Missing comma");
    }


    return ret;
}
