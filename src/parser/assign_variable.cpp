void assign_variable(const Type& type, const string& from, const string& to, const shared_ptr<Import>& i, size_t& p, bool error_on_non_primitives=false) {
    if(type && type->not_primitive()) {
        if(error_on_non_primitives) imp->error(p, "Failed to resolve "+type->name+" "+pretty_var(to)+" to a primitive");
        if(type->packs.size()==0) return;
        if(internalTypes.contains(from)) {
            if(!internalTypes.contains(to)) imp->error(p, "Failed to re-assign "+internalTypes.vars[from]->name+" "+pretty_var(from)+" from no-type"+pretty_var(to));
            if(internalTypes.vars[from]!=internalTypes.vars[to]) imp->error(p-1, "Failed to re-assign "+internalTypes.vars[from]->name+" "+pretty_var(from)+" from different type "+internalTypes.vars[to]->name+" "+pretty_var(to));
            
            /*if(internalTypes.vars[from]->packs.size()!=internalTypes.vars[to]->packs.size()) imp->error(p-2, "Failed to assign to "+internalTypes.vars[from]->name+" "+pretty_var(from)+" from "+internalTypes.vars[to]->name+" "+pretty_var(to)+": different number of fields");
            for(const string& var : internalTypes.vars[from]->packs) {
                if(!internalTypes.contains()) 
                if(internalTypes.vars[from+"__"+var]!=internalTypes.vars[to+"__"+var])
                    imp->error(p-1, "Failed to assign to "+internalTypes.vars[from+"__"+var]->name+" "+pretty_var(from)+"."+pretty_var(var)+" from "+internalTypes.vars[to+"__"+var]->name+" "+pretty_var(from)+"."+pretty_var(var));
            }*/
        }
        internalTypes.vars[from] = type;
        for(const string& var : type->packs) {
            const auto& it = type->internalTypes.vars.find(var);
            assign_variable(it==type->internalTypes.vars.end()?nullptr:it->second, from+"__"+var, to+"__"+var, i, p, true);
        }
        return;
    }
    const auto& it = internalTypes.vars.find(from);
    if(!type) {if(it==internalTypes.vars.end() || !it->second)imp->error(p, "No runtype for either "+pretty_var(from)+" or "+pretty_var(to));}
    else if(it==internalTypes.vars.end()) internalTypes.vars[from] = type;
    else if(it->second!=type) imp->error(--p, "Cannot assign to "+it->second->name+" "+pretty_var(from)+" from "+type->name+" "+pretty_var(to));
    
    if(type->name=="nom" && to!="0") {
        //if(!alignments[from]) imp->error(--p, "Cannot assign to align "+pretty_var(from)+" because it does not already have a valid alignment to check for validity");
        //if(!alignments[to]) imp->error(--p, "Cannot assign to align from "+pretty_var(to)+" because it does not have a valid alignment");
        if(alignments[from] && alignments[from]!=alignments[to]) imp->error(--p, "Cannot assign to align "+pretty_var(from)+" from a different runtype's alignment "+pretty_var(to));
        if(alignments[to]) alignments[from] = alignments[to];
    }
    implementation += from+" = "+to+";\n";
    current_renaming[from] = to;
}
