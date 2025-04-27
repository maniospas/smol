void assign_variable(const Type& type, const string& from, const string& to, const shared_ptr<Import>& i, size_t& p, bool error_on_non_primitives=false) {
    if(type && type->not_primitive()) {
        internalTypes.vars[from] = type;
        if(error_on_non_primitives) imp->error(p, "Failed to resolve "+type->name+" "+pretty_var(to)+" to a primitive");
        for(const string& var : type->packs) {
            const auto& it = type->internalTypes.vars.find(var);
            assign_variable(it==type->internalTypes.vars.end()?nullptr:it->second, from+"__"+var, to+"__"+var, i, p, true);
        }
        return;
    }
    const auto& it = internalTypes.vars.find(from);
    if(!type) {if(it==internalTypes.vars.end() || !it->second)imp->error(p, "No runtype for either "+pretty_var(from)+" or "+pretty_var(to));}
    else if(it==internalTypes.vars.end()) {
        internalTypes.vars[from] = type;
        vardecl += type->name+" "+from+";\n";
    }
    else if(it->second!=type) imp->error(p, "Cannot assign to "+it->second->name+" "+pretty_var(from)+" from "+type->name+" "+pretty_var(to));
    implementation += from+" = "+to+";\n";
}
