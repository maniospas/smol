#include "../def.h"

void Def::assign_variable(const Type& type, const string& from, const string& to, const shared_ptr<Import>& i, size_t& p, bool error_on_non_primitives, bool check_mutables) {
    current_renaming[from] = to;
    current_renaming[to] = from;
    if(check_mutables && internalTypes.contains(from) && mutables.find(from)==mutables.end()) imp->error(--p, "Cannot reassign to non-mutable: "+pretty_var(from)+"\nMutables are prepended by & in their first declaration");
    if(to.size()>=2 && (to[0]!='_' || to[1]!='_') && internalTypes.contains(to) && internalTypes.vars[to]->noborrow && mutables.find(to)!=mutables.end()) imp->error(--p, "Cannot reassign from @noborrow: "+pretty_var(to)+"\nArguments and variables of its runtype can only be mutable\nand therefore it becomes impossible to share it\n(mutable variables cannot be assinged anywhere).\nAdd & before the variable name to make it mutable");
    
    
    //if(invalidators.find(from)!=invalidators.end() && invalidators[from].size()) {implementation += invalidators[from]; invalidators[from] = "";}
    if(type_trackers.find(to)!=type_trackers.end()) type_trackers.insert(from);
    //else if(type_trackers.find(from)!=type_trackers.end()) i->error(p-2, "Cannot assign a value on internal variable referencing a runtype: "+pretty_var(to));
    if(type && type->not_primitive()) {
        if(error_on_non_primitives) imp->error(p, "Failed to resolve "+type->name+" "+pretty_var(to)+" to a primitive");
        if(type->packs.size()==0) return;
        if(internalTypes.contains(from)) {
            if(!internalTypes.contains(to)) imp->error(p, "Not found\nFailed to re-assign "+internalTypes.vars[from]->name+" "+pretty_var(from)+" from no-type"+pretty_var(to));
            if(internalTypes.vars[from]->canonic_type()!=internalTypes.vars[to]->canonic_type()) imp->error(p-1, "Not found\nFailed to re-assign "+internalTypes.vars[from]->canonic_type()->name+" "+pretty_var(from)+" from different type "+internalTypes.vars[to]->canonic_type()->name+" "+pretty_var(to));
        }
        internalTypes.vars[from] = type;
        for(const string& var : type->packs) {
            const auto& it = type->internalTypes.vars.find(var);
            assign_variable(it==type->internalTypes.vars.end()?nullptr:it->second, from+"__"+var, to+"__"+var, i, p, true, false);
        }
        for(const string& mut : type->mutables) mutables.insert(from+"__"+mut);
        for(const auto& it : type->internalTypes.vars) {
            const string& var = it.first;
            // TODO: this brings everything - restrict only on what is actually returned (we need to keep track of complex runtypes)
            internalTypes.vars[from+"__"+var] = internalTypes.vars[to+"__"+var];
        }
        return;
    }
    const auto& it = internalTypes.vars.find(from);
    if(!type) {if(it==internalTypes.vars.end() || !it->second)imp->error(p, "Not found runtype for either "+pretty_var(from)+" or "+pretty_var(to));}
    else if(it==internalTypes.vars.end()) internalTypes.vars[from] = type;
    else if(it->second!=type) imp->error(--p, "Cannot assign to "+it->second->name+" "+pretty_var(from)+" from "+type->name+" "+pretty_var(to));
    if(type->name=="nom" && to!="0") {
        if(!alignments[to]) alignments[to] = alignments[from];
        if(alignments[from] && alignments[from]!=alignments[to]) imp->error(--p, "Cannot assign to align "+pretty_var(from)+" with id "+to_string(alignments[from])+" from a different runtype's alignment "+pretty_var(to)+" with id "+to_string(alignments[to]));
        if(alignments[to]) alignments[from] = alignments[to];
    }
    implementation += from+" = "+to+";\n";
}
