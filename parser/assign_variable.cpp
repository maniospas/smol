void assignVariable(const Type& type, const string& from, const string& to, const shared_ptr<Import>& i, size_t& p) {
    const auto& it = internalTypes.vars.find(from);
    if(it==internalTypes.vars.end()) {
        internalTypes.vars[from] = type;
        vardecl += type->name+" "+from+";\n";
    }
    else if(it->second!=type) imp->error(p, "Cannot assign to "+it->second->name+" "+pretty_var(from)+" from "+type->name+" "+pretty_var(to));
    implementation += from+" = "+to+";\n";
}
