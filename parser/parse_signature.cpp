void parse_signature(const shared_ptr<Import>& imp, size_t& p, Memory& types) {
    if(imp->at(p++)!="smo") imp->error(--p, "Missing `smo` to declare runtype");
    name = imp->at(p++);
    if(imp->at(p++)!="(") imp->error(--p, "Missing left parenthesis");
    while(true) {
        bool mut = false;
        string next = imp->at(p++);
        if(next==")") break;
        if(args.size()) {
            if(next!=",")imp->error(--p, "Missing comma between arguments");
            next = imp->at(p++);
        }
        if(!accepted_var_name(next)) imp->error(--p, "Not a valid name");
        if(types.vars.find(next)==types.vars.end()) imp->error(--p, "Missing runtype");
        string arg_name = imp->at(p++);
        if(arg_name=="," || arg_name==")") {
            arg_name = create_temp();
            --p;
        }
        if(arg_name=="&") {mut = true;arg_name = imp->at(p++);}
        if(!accepted_var_name(arg_name)) imp->error(--p, "Not a valid name");
        if(types.vars.find(arg_name)!=types.vars.end()) imp->error(--p, "Invalid variable name\nConflicts with a runtype or union");
        Type argType = types.vars.find(next)->second;
        if(argType->lazy_compile) {
            args.emplace_back(arg_name, argType, mut);
            internalTypes.vars[arg_name] = argType;
            this->lazy_compile = true; // indicate that we want to compile lazily later again
        }
        else if(argType->not_primitive()) {
            internalTypes.vars[arg_name] = argType;
            for(const auto& it : argType->args) {
                args.emplace_back(arg_name+"__"+it.name, it.type, mut);
                internalTypes.vars[arg_name+"__"+it.name] = it.type;
                vardecl += it.type->rebase(it.type->vardecl, arg_name);
                implementation += it.type->rebase(it.type->implementation, arg_name);
                preample += it.type->rebase(it.type->preample, arg_name);
                finals = it.type->rebase(it.type->finals, arg_name)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
                errors = errors+it.type->rebase(it.type->errors, arg_name);
                for(const auto& it : it.type->internalTypes.vars) {
                    string arg = arg_name+"__"+it.first;
                    internalTypes.vars[arg] = it.second;
                }
            }
        }
        else {
            args.emplace_back(arg_name, argType, mut);
            internalTypes.vars[arg_name] = argType;
        }
        if(p>=imp->size()) imp->error(pos+2, "Missing matching right parenthesis");
    }
}
