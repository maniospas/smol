void parse_return(const shared_ptr<Import>& imp, size_t& p, string next, Memory& types) {
    if(imp->at(p)=="-") {++p;return;}
    if(imp->at(p++)!=">") imp->error(p-2, "Use `->` to return a value or `--` to return without a value for expressions starting with `-`");
    next = imp->at(p++);
    if(next=="@") {
        next = imp->at(p++);
        if(next == "scope") packs.push_back("@scope");
        else {
            if(next!="new") imp->error(--p, "Use `->@new` or `->@scope`");
            for (const auto& arg : args) packs.push_back(arg.name);
            //unordered_set<string> packSet(packs.begin(), packs.end());
            //for (const auto& arg : internalTypes.vars) if (packSet.insert(arg.first).second) packs.push_back(arg.first);
        }
    }
    else {
        --p;
        // we are starting parenthesis
        while(true) {
            next = parse_expression(imp, p, imp->at(p++), types);

            if(!internalTypes.vars[next]->not_primitive()) {
                packs.push_back(next);
            }
            else {
                if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared");
                for(const string& pack : internalTypes.vars.find(next)->second->packs) packs.push_back(next+"__"+pack);
            }
            next = imp->at(p++);
            //if(next==")") break;
            if(next!=",") {--p;break;}//imp->error(--p, "Missing comma (not implemented expression in return statements yet)");
        }
    }
}
