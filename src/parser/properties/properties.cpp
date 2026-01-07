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
#include "../../def.h"

void Def::add_preamble(const string& pre) {
    if(preamble.find(pre)==preamble.end()) 
        preamble.insert(pre);
}
void Def::add_linker(const string& pre) {
    if(linker.find(pre)==linker.end()) 
        linker.insert(pre);
}
void Def::assert_options_validity(size_t& p) {
    bool is_service = false;
    bool is_not_service = false;
    size_t count_nom = 0;
    size_t count_nonnom = 0;
    for(const auto& it : options) {
        if(it->is_service)
            is_service = true;
        else
            is_not_service = true;
        if(it->choice_power) 
            count_nom++;
        else
            count_nonnom++;
    }
    if(count_nom>1 && count_nonnom)
        imp->error(p, "More than one new declarations for: "+name.to_string());
    if(is_service && is_not_service)
        imp->error(p, "Cannot have both service and non-service declarations for: "+name.to_string());
}
void Def::coalesce_finals(const Variable& original) {
    unordered_set<Variable> visited;
    queue<Variable> q;
    unordered_set<Variable> group;
    q.push(original);
    visited.insert(original);
    while(!q.empty()) {
        Variable var = q.front();
        q.pop();
        group.insert(var);
        if(current_renaming.count(var)) {
            Variable next = current_renaming[var];
            if(visited.insert(next).second) 
                q.push(next);
        }
        for(const auto& [k, v] : current_renaming) 
            if(v == var && visited.insert(k).second) 
                q.push(k);
    }
    // Coalesce all finals into the original
    for(const Variable& name : group) 
        if(name != original && finals.count(name)) {
            finals[original] += rename_var(finals[name], name, original);
            finals[name] = Code();
        }
}
void Def::notify_release(const Variable& original) {
    unordered_set<Variable> visited;
    queue<Variable> q;
    unordered_set<Variable> group;
    q.push(original);
    visited.insert(original);
    while(!q.empty()) {
        Variable var = q.front();
        q.pop();
        group.insert(var);
        if(current_renaming.count(var)) {
            Variable next = current_renaming[var];
            if(visited.insert(next).second) 
                q.push(next);
        }
        for(const auto& [k, v] : current_renaming) 
            if(v == var && visited.insert(k).second) 
                q.push(k);
    }
    for(const Variable& name : group) 
        released[name] = true;
}

Type Def::extract_buffer_type(const Variable& original, size_t p) {
    unordered_set<Variable> visited;
    queue<Variable> q;
    unordered_set<Variable> group;
    q.push(original);
    visited.insert(original);
    while(!q.empty()) {
        auto var = q.front();
        q.pop();
        group.insert(var);
        if(current_renaming.count(var)) {
            Variable next = current_renaming[var];
            if(visited.insert(next).second) 
                q.push(next);
        }
        for(const auto& [k, v] : current_renaming) 
            if(v == var && visited.insert(k).second) 
                q.push(k);
    }
    auto found = Type{nullptr};
    for (const Variable& name : group) {
        auto it = buffer_types.find(name);
        if (it != buffer_types.end()) {
            if (!found.get())
                found = it->second;
            else if (found.get() != it->second.get())
                imp->error(p - 1, "Mismatching buffer types.\nThe same memory has been accessed as a different kind of buffer before.");
        }
    }
    return found;
}



void Def::assert_compatible(const Variable& original, const Type& type, size_t p) {
    if(imp->allow_unsafe)
        return;
    unordered_set<Variable> visited;
    queue<Variable> q;
    unordered_set<Variable> group;
    q.push(original);
    visited.insert(original);
    while(!q.empty()) {
        auto var = q.front();
        q.pop();
        group.insert(var);
        if(current_renaming.count(var)) {
            Variable next = current_renaming[var];
            if(visited.insert(next).second) 
                q.push(next);
        }
        for(const auto& [k, v] : current_renaming) 
            if(v == var && visited.insert(k).second) 
                q.push(k);
    }
    //for(const Variable& name : group) 
    //    mutables.erase(name);
    for(const Variable& name : group) {
        if(buffer_types.find(name)!=buffer_types.end()) {
            if(buffer_types[name].get()!=type.get())
                imp->error(p-1, "Mismatching buffer types.\n"
                    "The same memory has been accessed as a different kind of buffer before."
                );
        }
    }
}

bool Def::can_mutate_any_assigned(const Variable& original, size_t p) {
    unordered_set<Variable> visited;
    queue<Variable> q;
    unordered_set<Variable> group;
    q.push(original);
    visited.insert(original);
    while(!q.empty()) {
        auto var = q.front();
        q.pop();
        group.insert(var);
        if(current_renaming.count(var)) {
            Variable next = current_renaming[var];
            if(visited.insert(next).second) 
                q.push(next);
        }
        for(const auto& [k, v] : current_renaming) 
            if(v == var && visited.insert(k).second) 
                q.push(k);
    }
    for(const Variable& name : group) 
        if(!can_mutate(name, p))
            return false;
    return true;
}

void Def::notify_service_arg(const Variable& original) {
    unordered_set<Variable> visited;
    queue<Variable> q;
    unordered_set<Variable> group;
    q.push(original);
    visited.insert(original);
    while(!q.empty()) {
        Variable var = q.front();
        q.pop();
        group.insert(var);
        if(current_renaming.count(var)) {
            Variable next = current_renaming[var];
            if(visited.insert(next).second) 
                q.push(next);
        }
        for(const auto& [k, v] : current_renaming) 
            if(v == var && visited.insert(k).second) 
                q.push(k);
    }
    //for(const Variable& name : group) 
    //    mutables.erase(name);
    for(const Variable& name : group) 
        //if(can_mutate_any_part(name))
            has_been_service_arg[name] = true;
    for(const auto& arg : args)
        if(!arg.owned && group.contains(arg.name))
            imp->error(--p, "Cannot `@own` argument: "+pretty_var(original.to_string())
                + "\nThat is transferred from this function's argument that has not been declared as `@own` itself. A quick fix could be to set `@own` to the argument: "+pretty_var(arg.name.to_string()));
}

bool Def::can_mutate_any_part(const Variable& var) {
    if(has_been_service_arg[var]) 
        return false;
    if(has_been_retrieved_as_immutable[var])
        return false;
    Variable prefix = var;
    for(size_t i =var.size; i>=1; --i) {
        prefix.size = i;
        if(mutables.find(prefix) != mutables.end()) {
            prefix.size = var.size; // correct deallocation
            return true;
        }
    }
    prefix.size = var.size; // correct deallocation
    return false;
}

bool Def::can_mutate(const Variable& var, size_t p) {
    // if(has_been_service_arg[var]) 
    //     imp->error(p-1, "Cannot use mutable variable that has been passed to a service: "
    //         +pretty_var(var.to_string())
    //         +"\nStore it into an immutable intermediate if you want to use it"
    //     );
    if(has_been_retrieved_as_immutable[var])
        return false;
    Variable prefix = var;
    for(size_t i =var.size; i>=1; --i) {
        prefix.size = i;
        if(mutables.find(prefix) != mutables.end()) {
            // if(has_been_service_arg[prefix]) 
            //     imp->error(p-1, "Cannot use mutable variable that has been passed to a service: "
            //         +pretty_var(prefix.to_string())
            //         +"\nStore it into an immutable intermediate if you want to use it"
            //     ); 
            prefix.size = var.size; // correct deallocation
            return true;
        }
    }
    prefix.size = var.size; // correct deallocation
    return false;
}