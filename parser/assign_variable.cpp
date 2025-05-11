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

        // the following ensures that we safely update pointers when reallocating them
        /*if(type->name!="ptr") // vardecl += type->name+" "+from+";\n";
        else {
            if(to=="0") // vardecl += type->name+" "+from+" = nullptr;\n";
            else // vardecl += type->name+" "+from+" = "+to+";\n";
        }*/
        // replace the above line to make the language impure
        //if(internalTypes.vars.find(to)==internalTypes.vars.end()) // vardecl += type->name+" "+from+";\n";
        //else // vardecl += type->name+" &"+from+" = "+to+";\n";
    }
    else if(it->second!=type) imp->error(--p, "Cannot assign to "+it->second->name+" "+pretty_var(from)+" from "+type->name+" "+pretty_var(to));
    implementation += from+" = "+to+";\n";
}
