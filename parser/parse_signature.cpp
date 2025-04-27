void parse_signature(const shared_ptr<Import>& imp, size_t& p, Memory& types) {
    if(imp->at(p++)!="smo") imp->error(--p, "Missing `smo` to declare runtype");
    name = imp->at(p++);
    if(imp->at(p++)!="(") imp->error(--p, "Missing left parenthesis");
    while(true) {
        string next = imp->at(p++);
        if(next==")") break;
        if(args.size()) {
            if(next!=",")imp->error(--p, "Missing comma between arguments");
            next = imp->at(p++);
        }
        if(!accepted_var_name(next)) imp->error(--p, "Not a valid name");
        if(types.vars.find(next)==types.vars.end()) imp->error(--p, "Missing runtype");
        string arg_name = imp->at(p++);
        if(!accepted_var_name(arg_name)) imp->error(--p, "Not a valid name");
        if(types.vars.find(arg_name)!=types.vars.end()) imp->error(--p, "Invalid variable name\nA runtype already has this name (you could define that later)");
        Type argType = types.vars.find(next)->second;
        if(argType->next_overload_to_try) imp->error(p-2, "Overloaded runtypes are ambiguous");

        if(argType->not_primitive()) {
            internalTypes.vars[arg_name] = argType;
            for(const auto& it : argType->args) {
                args.emplace_back(arg_name+"__"+it.name, it.type);
                internalTypes.vars[arg_name+"__"+it.name] = it.type;
                vardecl += it.type->rebase(it.type->vardecl, arg_name);
                implementation += it.type->rebase(it.type->implementation, arg_name);
                preample += it.type->rebase(it.type->preample, arg_name);
                finals = it.type->rebase(it.type->finals, arg_name)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
                errors = errors+it.type->rebase(it.type->errors, arg_name);
                for(const auto& it : it.type->internalTypes.vars) internalTypes.vars[arg_name+"__"+it.first] = it.second;
            }
        }
        else {
            args.emplace_back(arg_name, argType);
            internalTypes.vars[arg_name] = argType;
        }
        if(p>=imp->size()) imp->error(pos+2, "Missing matching right parenthesis");
    }
}
