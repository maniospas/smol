void parse_return(const shared_ptr<Import>& imp, size_t& p, string next, Memory& types) {
    if(imp->at(p)=="-") {++p;return;}
    if(imp->at(p++)!=">") imp->error(p-2, "Use `->` to return a value or `--` to return without a value for expressions starting with `-`");
    next = imp->at(p++);
    if(next=="@") {
        next = imp->at(p++);
        /*if(next == "scope") packs.push_back("@scope");
        else*/ {
            if(next!="new") imp->error(--p, "Use `->@new`");
            if(is_service)  packs.push_back("err");
            internalTypes.vars["err"] = types.vars["errcode"];
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
                if(is_service) {
                    packs.push_back("err");
                    internalTypes.vars["err"] = types.vars["errcode"];
                    implementation += "__value = "+next+";\n";
                    if(internalTypes.contains("__value") && internalTypes.vars["__value"]!=internalTypes.vars[next]) imp->error(--p, "Returning single value of multple types "+internalTypes.vars["__value"]->name+" and "+internalTypes.vars[next]->name);
                    internalTypes.vars["__value"] = internalTypes.vars[next];
                    packs.push_back("__value");
                }
                else packs.push_back(next);
            }
            else {
                if(is_service) {
                    packs.push_back("__err");
                    internalTypes.vars["err"] = types.vars["errcode"];
                    imp->error(--p, "Service multivalue returns not implemented yet");
                }
                if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared: "+pretty_var(next)+recommend_variable(types, next));
                if(p && imp->at(p-1)==")") {
                    // if we are directly returning a proxy, unpack that proxy here
                    for(const string& pack : internalTypes.vars[next]->packs) {
                        assign_variable(internalTypes.vars[next]->internalTypes.vars[pack], pack, next+"__"+pack, imp, p);
                        packs.push_back(pack);
                    }
                }
                else for(const string& pack : internalTypes.vars.find(next)->second->packs) packs.push_back(next+"__"+pack);
            }
            if(p>=imp->size()){break;}
            next = imp->at(p++);
            //if(next==")") break;
            if(next!=",") {--p;break;}//imp->error(--p, "Missing comma (not implemented expression in return statements yet)");
        }
    }
}
