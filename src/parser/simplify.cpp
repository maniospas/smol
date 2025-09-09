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
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <regex>
#include <memory>

void Def::simplify() {
    return;
    if(implementation.is_empty()) 
        return;
    unordered_set<Variable> in_packs;
    for(const Variable& pack : packs)
        in_packs.insert(pack);
    if(alias_for.exists() && vars[alias_for]->not_primitive()) {
        in_packs.insert(alias_for);
        for(const Variable& pack : vars[alias_for]->packs) 
            in_packs.insert(alias_for+pack);
    }
    unordered_map<Variable, Variable> renaming;
    unordered_set<Variable> all_tokens;
    unordered_set<Variable> use_before_renamed;
    unordered_map<Variable, unsigned int> total_uses;
    unordered_map<Variable, unsigned int> used;
    Code code;
    code.segments.reserve(implementation.segments.size()/8);
    size_t n = implementation.segments.size();
    for(size_t i=0;i<n;++i) {
        const Variable& var = implementation.segments[i];
        total_uses[var] += 1;
    }
    for(size_t i=0;i<n;++i) {
        const Variable& var = implementation.segments[i];
        if(i<n-1 && implementation.segments[i+1]==SEMICOLON_VAR && contains(var)) 
            used[var] += 1;
        if(i<n-3 
            && implementation.segments[i+1]==ASSIGN_VAR 
            && implementation.segments[i+3]==SEMICOLON_VAR
            && contains(var)
            && vars[var]->name!=NOM_VAR
            && in_packs.find(var)==in_packs.end() // do not rename returned values
            && (contains(implementation.segments[i+2]) 
                /*|| (is_primitive(implementation.segments[i+2].to_string()))*/)
            && (mutables.find(var)==mutables.end())
            && (mutables.find(implementation.segments[i+2])==mutables.end() || total_uses[implementation.segments[i+2]]==2)
        ) {
                if(all_tokens.find(var)!=all_tokens.end()) 
                    use_before_renamed.insert(var);
                const Variable& sub = implementation.segments[i+2];
                if(renaming.find(sub)==renaming.end()) 
                    renaming[var] = sub;
                else 
                    renaming[var] = renaming[sub];
                i += 3;
        }
        else {
            if(renaming.find(var)==renaming.end()) {
                code.segments.push_back(var);
                all_tokens.insert(var);
            }
            else 
                code.segments.push_back(renaming[var]);
        }
    }
    implementation = code;
    n = implementation.segments.size();
    code = Code();
    for(size_t i=0;i<n;++i) {
        //skip gotos that jump to just the next line
        if(i<n-4
            && implementation.segments[i]==Variable("goto") 
            && implementation.segments[i+2]==SEMICOLON_VAR 
            && implementation.segments[i+4]==COLON_VAR
            && implementation.segments[i+3]==implementation.segments[i+1]
            && used[implementation.segments[i+1]]==1) {
                i += 4;
                continue;
            }
        //skip unused gotos
        if(i<n-1 
            && implementation.segments[i+1]==COLON_VAR 
            && used.find(implementation.segments[i])==used.end()
            && contains(implementation.segments[i])
            && vars[implementation.segments[i]]->name==LABEL_VAR) {
                i += 1;
                continue;
            }
        code.segments.push_back(implementation.segments[i]);
    }
    implementation = code;


    unordered_map<Variable, Code> new_finals;
    new_finals.reserve(finals.size());
    for(const auto& it : finals) {
        Code renamed;
        renamed.segments.reserve(it.second.segments.size());
        for(size_t i=0;i<it.second.segments.size();++i) {
            const Variable& var = it.second.segments[i];
            if(renaming.find(var)==renaming.end()) 
                renamed.segments.push_back(var);
            else 
                renamed.segments.push_back(renaming[var]);
        }
        if(renaming.find(it.first)==renaming.end()) 
            new_finals[it.first] = renamed;
        else 
            new_finals[renaming[it.first]] = renamed;
    }
    finals = new_finals;

    for(size_t i=0;i<packs.size();++i) 
        if(renaming.find(packs[i])!=renaming.end()) 
            packs[i] = renaming[packs[i]];

    Code renamed_errors;
    renamed_errors.segments.reserve(errors.segments.size());
    for(size_t i=0;i<errors.size();++i) {
        const Variable& var = errors.segments[i];
        if(renaming.find(var)==renaming.end()) 
            renamed_errors.segments.push_back(var);
        else
            renamed_errors.segments.push_back(renaming[var]);
    }
    errors = renamed_errors;

    unordered_map<Variable, Variable> new_renaming;
    for(const auto& it : current_renaming) {
        Variable new_first = renaming.find(it.first)==renaming.end()?it.first:renaming[it.first];
        Variable new_second = renaming.find(it.second)==renaming.end()?it.second:renaming[it.second];
        new_renaming[new_first] = new_second;
    }
    current_renaming = new_renaming;
}