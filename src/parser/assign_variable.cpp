#include "../def.h"

void Def::assign_variable(const Type& type, const string& from, const string& to, const shared_ptr<Import>& i, size_t& p, bool error_on_non_primitives, bool check_mutables) {
    if(check_mutables && internalTypes.contains(from) && from!=to && mutables.find(from)==mutables.end()) imp->error(--p, "Cannot reassign to non-mutable variable: "+pretty_var(from)+"\nMutable names are prepended by & in their first declaration");
    //if(invalidators.find(from)!=invalidators.end() && invalidators[from].size()) {implementation += invalidators[from]; invalidators[from] = "";}
    if(type_trackers.find(to)!=type_trackers.end()) type_trackers.insert(from);
    //else if(type_trackers.find(from)!=type_trackers.end()) i->error(p-2, "Cannot assign a value on internal variable referencing a runtype: "+pretty_var(to));
    if(type && type->not_primitive()) {
        if(error_on_non_primitives) imp->error(p, "Failed to resolve "+type->name+" "+pretty_var(to)+" to a primitive");
        if(type->packs.size()==0) return;
        if(internalTypes.contains(from)) {
            if(!internalTypes.contains(to)) imp->error(p, "Not found\nFailed to re-assign "+internalTypes.vars[from]->name+" "+pretty_var(from)+" from no-type"+pretty_var(to));
            if(internalTypes.vars[from]!=internalTypes.vars[to]) imp->error(p-1, "Not found\nFailed to re-assign "+internalTypes.vars[from]->name+" "+pretty_var(from)+" from different type "+internalTypes.vars[to]->name+" "+pretty_var(to));
        }
        internalTypes.vars[from] = type;
        for(const string& var : type->packs) {
            const auto& it = type->internalTypes.vars.find(var);
            assign_variable(it==type->internalTypes.vars.end()?nullptr:it->second, from+"__"+var, to+"__"+var, i, p, true, false);
        }
        if(mutables.find(to)!=mutables.end()) for(const string& mut : type->mutables) mutables.insert(from+"__"+mut);
        for(const auto& it : type->internalTypes.vars) {
            const string& var = it.first;
            // TODO: this brings everything - restrict only on what is actually returned (we need to keep track of complex runtypes)
            internalTypes.vars[from+"__"+var] = internalTypes.vars[to+"__"+var];
        }
        return;
    }
    const auto& it = internalTypes.vars.find(from);
    if(!type) {if(it==internalTypes.vars.end() || !it->second)imp->error(p, "No runtype for either "+pretty_var(from)+" or "+pretty_var(to));}
    else if(it==internalTypes.vars.end()) internalTypes.vars[from] = type;
    else if(it->second!=type) imp->error(--p, "Cannot assign to "+it->second->name+" "+pretty_var(from)+" from "+type->name+" "+pretty_var(to));
    if(type->name=="nom" && to!="0") {
        if(!alignments[to]) alignments[to] = alignments[from];
        if(alignments[from] && alignments[from]!=alignments[to]) imp->error(--p, "Cannot assign to align "+pretty_var(from)+" with id "+to_string(alignments[from])+" from a different runtype's alignment "+pretty_var(to)+" with id "+to_string(alignments[to]));
        if(alignments[to]) alignments[from] = alignments[to];
    }
    implementation += from+" = "+to+";\n";
    current_renaming[from] = to;
}
