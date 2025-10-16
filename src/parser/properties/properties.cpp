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
    size_t count_nom = 0;
    size_t count_nonnom = 0;
    for(const auto& it : options) {
        if(it->choice_power) 
            count_nom++;
        else
            count_nonnom++;
    }
    if(count_nom>1 && count_nonnom)
        imp->error(p, "More than one nominal declarations for: "+name.to_string());
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
        if(can_mutate_any_part(name))
            has_been_service_arg[name] = true;
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
    if(has_been_service_arg[var]) 
        imp->error(p-1, "Cannot use mutable variable that has been passed to a service: "
            +pretty_var(var.to_string())
            +"\nStore it into an immutable intermediate if you want to use it"
        );
    if(has_been_retrieved_as_immutable[var])
        return false;
    Variable prefix = var;
    for(size_t i =var.size; i>=1; --i) {
        prefix.size = i;
        if(mutables.find(prefix) != mutables.end()) {
            if(has_been_service_arg[prefix]) 
                    imp->error(p-1, "Cannot use mutable variable that has been passed to a service: "
                        +pretty_var(prefix.to_string())
                        +"\nStore it into an immutable intermediate if you want to use it"
                    ); 
            prefix.size = var.size; // correct deallocation
            return true;
        }
    }
    prefix.size = var.size; // correct deallocation
    return false;
}