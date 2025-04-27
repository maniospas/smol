vector<string> Def::gather_tuple(const shared_ptr<Import>& imp, size_t& p, Memory& types) {
    vector<string> ret;
    while(true) {
        int expression_start = p;
        string next = imp->at(p++);
        if(next==")") {--p;break;}
        string var = parse_expression(imp, p, next, types);
        if(!internalTypes.contains(var)) imp->error(expression_start, "Failed to parse expression");
        if(!internalTypes.vars.find(var)->second->not_primitive()) ret.push_back(var);
        for(const string& pack : internalTypes.vars.find(var)->second->packs) ret.push_back(var+"__"+pack);
        next = imp->at(p++);
        if(next==")") {--p;break;}
        if(next!=",") imp->error(--p, "Missing comma");
    }


    return ret;
}
