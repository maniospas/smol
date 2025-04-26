void parse_directive(const shared_ptr<Import>& imp, size_t& p, string next, Memory& types) {
    next = imp->at(p++);
    if(next=="head") {
        next = imp->at(p++);
        if(next!="{") imp->error(--p, "Expected brackets");
        int depth = 1;
        while(true) {
            next = imp->at(p++);
            if(next=="{") depth++;
            if(next=="}") {depth--;if(depth==0) break;}
            string nextnext = imp->at(p);
            preample += next;
            if(!is_symbol(next) && !is_symbol(nextnext)) preample += " ";
        }
        preample += "\n";
    }
    else if(next=="body") {
        next = imp->at(p++);
        if(next!="{") imp->error(--p, "Expected brackets");
        int depth = 1;
        while(true) {
            next = imp->at(p++);
            if(next=="{") depth++;
            if(next=="}") {depth--;if(depth==0) break;}
            string nextnext = imp->at(p);
            if(p<imp->size()-1 && imp->at(p+1)=="=" && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") && !is_symbol(next) && !is_symbol(nextnext)) {
                string argname = nextnext;
                string argtype = next;
                if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->args.size()) {
                    internalTypes.vars[argname] = types.vars.find(argtype)->second;
                    vardecl += argtype+" "+argname+";\n";
                }
                else imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
            }
            else {
                if(next=="goto") internalTypes.vars[nextnext] = types.vars["__label"];
                implementation += next;
                if(!is_symbol(next) && !is_symbol(nextnext)) implementation += " ";
            }
        }
        implementation += "\n";
    }
    else if(next=="fail") {
        string fail_label = create_temp();
        errors += fail_label+":\n";
        next = imp->at(p++);
        if(next!="{") imp->error(--p, "Expected brackets");
        int depth = 1;
        while(true) {
            next = imp->at(p++);
            if(next=="{") depth++;
            if(next=="}") {depth--;if(depth==0) break;}
            string nextnext = imp->at(p);
            if(p<imp->size()-1 && imp->at(p+1)=="=" && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") && !is_symbol(next) && !is_symbol(nextnext)) {
                string argname = nextnext;
                string argtype = next;
                if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->args.size()) {
                    internalTypes.vars[argname] = types.vars.find(argtype)->second;
                    vardecl += argtype+" "+argname+";\n";
                }
                else imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
            }
            else {
                errors += next;
                if(!is_symbol(next) && !is_symbol(nextnext)) errors += " ";
            }
        }
        errors += "\ngoto __return;\n";
        implementation += "goto "+fail_label+";\n";
    }
    else imp->error(--p, "Invalid symbol after @");
}
