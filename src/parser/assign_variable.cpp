// Copyright 2025 Emmanouil Krasanakis (maniospas@hotmail.com)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "../def.h"

void Def::assign_variable(
    const Type& type, 
    const Variable& from, 
    const Variable& to, 
    const shared_ptr<Import>& i, 
    size_t& p, 
    bool error_on_non_primitives, 
    bool check_mutables
) {
    if(buffer_types.find(to)!=buffer_types.end()) {
        if(buffer_types.find(from)==buffer_types.end()) 
            buffer_types[from] = buffer_types[to];
        else if(buffer_types[from].get()!=buffer_types[to].get()) 
            imp->error(--p, "Mismatched buffer assignment.\nExpected:"
                +buffer_types[from]->name.to_string()
                +" but got "+buffer_types[to]->name.to_string()
            );
    }
    current_renaming[from] = to;
    current_renaming[to] = from;
    released[from] = released[to];
    if(active_calls.size())
        active_calls[from] = active_calls[to];
    if(check_mutables 
        && internalTypes.contains(from) 
        && mutables.find(from)==mutables.end()
    ) 
        imp->error(--p, "Cannot reassign to non-mutable: "
            +pretty_var(from.to_string())
            +"\nMutables are prepended by & in their first declaration AND must be fields"
            +"\nof free variables or fields of mutable variables"
        );
    if(to.is_private() 
        && internalTypes.contains(to) 
        && internalTypes.vars[to]->noborrow 
        && mutables.find(to)!=mutables.end()
    ) 
        imp->error(--p, "Cannot reassign from @noborrow: "
            +pretty_var(to.to_string())+"\nArguments and variables of its runtype can only be mutable"
            +"\nand therefore it becomes impossible to share it with services"
            +"\n(mutable variables cannot be assinged anywhere).\nAdd & before the variable name to make it mutable"
        );
    if(type_trackers.find(to)!=type_trackers.end()) 
        type_trackers.insert(from);
    if(type && type->not_primitive()) {
        if(error_on_non_primitives) 
            imp->error(p, "Failed to resolve "
                +type->name.to_string()
                +" "+pretty_var(to.to_string())
                +" to a primitive"
            );
        if(type->packs.size()==0) 
            return;
        if(internalTypes.contains(from)) {
            if(!internalTypes.contains(to)) 
                imp->error(p, "Not found\nFailed to re-assign "
                    +internalTypes.vars[from]->name.to_string()
                    +" "+pretty_var(from.to_string())
                    +" from no-type"
                    +pretty_var(to.to_string())
                );
            if(internalTypes.vars[from]->canonic_type()!=internalTypes.vars[to]->canonic_type()) 
                imp->error(p-1, "Not found\nFailed to re-assign "
                    +internalTypes.vars[from]->canonic_type()->name.to_string()
                    +" "+pretty_var(from.to_string())
                    +" from different type "
                    +internalTypes.vars[to]->canonic_type()->name.to_string()
                    +" "+pretty_var(to.to_string())
                );
        }
        internalTypes.vars[from] = type;
        for(const Variable& var : type->packs) {
            const auto& it = type->internalTypes.vars.find(var);
            assign_variable(
                it==type->internalTypes.vars.end()?nullptr:it->second, 
                from+var, 
                to+var, 
                i, p, true, false);
        }
        if(mutables.find(to)!=mutables.end()) 
            for(const Variable& mut : type->mutables) 
                mutables.insert(from+mut);
        for(const auto& it : type->internalTypes.vars) {
            const Variable& var = it.first;
            // TODO: this brings everything - restrict only on what is actually returned (we need to keep track of complex runtypes)
            internalTypes.vars[from+var] = internalTypes.vars[to+var];
        }
        return;
    }
    const auto& it = internalTypes.vars.find(from);
    if(!type) {
        if(it==internalTypes.vars.end() || !it->second)
            imp->error(p, "Not found runtype for either "
                +pretty_var(from.to_string())
                +" or "+pretty_var(to.to_string())
            );
    } 
    else if(it==internalTypes.vars.end()) 
        internalTypes.vars[from] = type;
    else if(it->second!=type) 
        imp->error(--p, "Cannot assign to "+it->second->name.to_string()+" "+pretty_var(from.to_string())+" from "+type->name.to_string()+" "+pretty_var(to.to_string()));
    if(type->name==NOM_VAR && to!=ZERO_VAR) {
        if(!alignments[to]) 
            alignments[to] = alignments[from];
        if(alignments[from] && alignments[from]!=alignments[to]) 
            imp->error(--p, "Cannot assign to align "
                +pretty_var(from.to_string())
                +" with id "+to_string(alignments[from])
                +" from a different runtype's alignment "
                +pretty_var(to.to_string())
                +" with id "+to_string(alignments[to])
            );
        if(alignments[to]) 
            alignments[from] = alignments[to];
    }
    if(type->name!=NOM_VAR)
        implementation += Code(from,ASSIGN_VAR,to,SEMICOLON_VAR);
}
