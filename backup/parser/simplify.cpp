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
    //return;
    // TODO: mutables should not be optimized for equality anywhere
    // TODO: BUG loop variables that are modified (replicate: in Split.next make @mut prev immutable, comment its mutable reassignment, and run tests/qualitative/banana.s)
    if(implementation.is_empty()) 
        return;
    unordered_map<Variable, size_t> usage;
    unordered_map<Variable, size_t> sets;
    for(const Variable& pack : packs) {
        usage[pack] = 100000; // always consider it used
        sets[pack] = 100000;
    }
    for(const auto& it : finals) {
        usage[it.first] = 100000; // always consider it used
        sets[it.first] = 100000;
    }
    for(const auto& it : args) {
        usage[it.name] = 100000; // always consider it used
        sets[it.name] = 100000;
    }
        
    size_t n = implementation.segments.size();
    for(size_t i=0;i<n;++i) {
        const Variable& var = implementation.segments[i];
        if(contains(var)) 
            usage[var] += 1;
        if(i<n-3 
            && (i==0 || implementation.segments[i-1]==SEMICOLON_VAR || implementation.segments[i-1]==COLON_VAR )
            && contains(var)
            && implementation.segments[i+1]==ASSIGN_VAR 
            && implementation.segments[i+3]==SEMICOLON_VAR 
            && contains(implementation.segments[i+2])
        ) {
            sets[var] += 1;
        }
    }

    for(auto& it : finals) 
        for(size_t i=0;i<it.second.segments.size();++i) {
            const Variable& var = it.second.segments[i];
            if(contains(var)) 
                usage[var] += 1;
        }
    for(auto& error : errors) 
        for(size_t i=0;i<error.segments.size();++i) {
            const Variable& var = error.segments[i];
            if(contains(var)) 
                usage[var] += 1;
        }
    

    auto renaming = unordered_map<Variable, Variable>{};
    auto code = Code{};
    code.segments.reserve(implementation.segments.size()/8);
    for(size_t i=0;i<n;++i) {
        Variable var = implementation.segments[i];
        if(renaming.find(var)!=renaming.end() && implementation.segments[i-1]!=ARROW_VAR) 
            var = renaming[var];
        // rename assignments to variables that have been assigned to once, or which are private
        if(i<n-3 
            && (i==0 || implementation.segments[i-1]==SEMICOLON_VAR || implementation.segments[i-1]==COLON_VAR ) 
            && implementation.segments[i+1]==ASSIGN_VAR 
            && implementation.segments[i+3]==SEMICOLON_VAR 
            && (sets[var]==1 || var==implementation.segments[i+2])// || sets[var]<100000) // once used later and once assigned here
            && contains(var)
            && contains(implementation.segments[i+2])
            && vars[var]==vars[implementation.segments[i+2]] // do not make a renaming for value casting
        ) {
            if(renaming.find(implementation.segments[i+2])!=renaming.end())
                renaming[var] = renaming[implementation.segments[i+2]];
            else
                renaming[var] = implementation.segments[i+2];
            i += 3;
            continue;
        }
        // skip goto label;label:
        if(var=="goto" && i<n-4 
            && implementation.segments[i+2]==SEMICOLON_VAR 
            && implementation.segments[i+3]==implementation.segments[i+1]
            && implementation.segments[i+4]==COLON_VAR) {
            i+=2; // skip only the goto, not the label setting
            continue;
        }
        //skip empty labels
        if(i<n-2
            && (i==0 || implementation.segments[i-1]==SEMICOLON_VAR || implementation.segments[i-1]==COLON_VAR || implementation.segments[i-1]==UNREACHABLE_VAR ) 
            && implementation.segments[i+1]==COLON_VAR
            && usage[var] <=1
        ) {
            i += 1;
            continue;
        }
        // scip unused ops 
        if(i<n-3 
            && implementation.segments[i+1]==ASSIGN_VAR
            && (i==0 || implementation.segments[i-1]==SEMICOLON_VAR || implementation.segments[i-1]==COLON_VAR )
            && contains(var)
            && usage[var]<=1  
            && contains(implementation.segments[i+2]) && implementation.segments[i+3]==SEMICOLON_VAR//TODO: added this line because it does not work properly with "path":is_dir
        ) {
            while(i<n && var!=SEMICOLON_VAR && var!=";") {
                i++;
                var = implementation.segments[i];
            }
            continue;
        }
        // remove renaming in case of some unknown assignment
        if(i<n-3 
            && (i==0 || implementation.segments[i-1]==SEMICOLON_VAR || implementation.segments[i-1]==COLON_VAR ) 
            && implementation.segments[i+1]==ASSIGN_VAR
            && contains(var)
        ) {
            renaming.erase(var);
        }
        code.segments.push_back(var);
    }
    implementation = code;

    // update errors and finals
    unordered_set<Code> new_errors;
    for(const auto& error : errors) {
        auto new_error = Code{};
        new_error.segments.reserve(error.segments.size()/8);
        for(size_t i=0;i<error.segments.size();++i) {
            Variable var = error.segments[i];
            if(renaming.find(var)!=renaming.end() && error.segments[i-1]!=ARROW_VAR) 
                var = renaming[var];
            new_error.segments.push_back(var);
        }
        new_errors.insert(new_error);
    }
    errors = std::move(new_errors);

    // update finals
    for(auto& it : finals) {
        auto new_finals = Code{};
        new_finals.segments.reserve(it.second.segments.size()/8);
        for(size_t i=0;i<it.second.segments.size();++i) {
            Variable& var = it.second.segments[i];
            if(renaming.find(var)!=renaming.end() && it.second.segments[i-1]!=ARROW_VAR) 
                var = renaming[var];
            new_finals.segments.push_back(var);
        }
        it.second = std::move(new_finals);
    }

    // now remove vars that previously existed but don't anymore
    unordered_map<Variable, Type> existing_vars;
    for(const auto& it : vars) {
        if(it.second && !it.second->_is_primitive) // keep meta-vars because it's complicated to find which to keep
            existing_vars[it.first] = it.second;
    }
    // do not remove certain stuff
    for(const Variable& pack : packs) 
        existing_vars[pack] = vars[pack];
    for(const auto& it : finals) 
        existing_vars[it.first] = vars[it.first];
    for(const auto& it : args) 
        existing_vars[it.name] = vars[it.name];
    // keep types only for stuff that exists
    for(size_t i=0;i<implementation.segments.size();++i) {
        const Variable& var = implementation.segments[i];
        if(contains(var))
            existing_vars[var] = vars[var];
    }
    for(size_t i=0;i<vardecl.segments.size();++i) {
        const Variable& var = vardecl.segments[i];
        if(contains(var))
            existing_vars[var] = vars[var];
    }
    for(const auto& error : errors) 
        for(size_t i=0;i<error.segments.size();++i) {
            const Variable& var = error.segments[i];
            if(contains(var))
                existing_vars[var] = vars[var];
        }
    for(const auto& it : finals) 
        for(size_t i=0;i<it.second.segments.size();++i) {
            const Variable& var = it.second.segments[i];
            if(contains(var))
                existing_vars[var] = vars[var];
        }
    vars=(existing_vars);

    prune();
}

void Def::prune() {
    // Create a mapping of private vars → renamed temporary vars
    auto renaming = unordered_map<Variable, Variable>();
    for (const auto& [var, type] : vars)
        if (var.is_private() && contains(var) && finals.find(var)==finals.end()) // TODO: investigate we why need the exclusion of finals
            renaming[var] = Variable(create_temp());
    for(const auto& pack : packs) 
        renaming.erase(pack);
    if(is_service)
        for(const auto& arg : args) 
            renaming.erase(arg.name);
    if(renaming.size())
        rename(renaming);
}


void Def::rename(unordered_map<Variable, Variable>& renaming) {
    auto apply_renaming = [&](Code& code) {
        for (size_t i = 0; i < code.segments.size(); ++i) {
            auto& var = code.segments[i];
            if (renaming.find(var) != renaming.end())
                var = renaming[var];
        }
    };
    auto rename_set = [&](unordered_set<Variable>& s) {
        auto new_set = unordered_set<Variable>{};
        new_set.reserve(s.size());
        for(const auto& v : s)
            new_set.insert(renaming.find(v) != renaming.end() ? renaming[v] : v);
        s=std::move(new_set);
    };

    auto rename_map_var_type = [&](unordered_map<Variable, Type>& m) {
        auto new_m = unordered_map<Variable, Type>{};
        new_m.reserve(m.size());
        for(const auto& [k, v] : m)
            new_m[renaming.find(k) != renaming.end() ? renaming[k] : k] = v;
        m=std::move(new_m);
    };

    auto rename_map_var_var = [&](unordered_map<Variable, Variable>& m) {
        auto new_m = unordered_map<Variable, Variable>{};
        new_m.reserve(m.size());
        for(const auto& [k, v] : m) {
            auto nk = renaming.find(k) != renaming.end() ? renaming[k] : k;
            auto nv = renaming.find(v) != renaming.end() ? renaming[v] : v;
            new_m[nk] = nv;
        }
        m=std::move(new_m);
    };
    auto rename_map_var_bool = [&](unordered_map<Variable, bool>& m) {
        auto new_m = unordered_map<Variable, bool>{};
        for (auto& [k, v] : m)
            new_m[renaming.find(k) != renaming.end() ? renaming[k] : k] = v;
        m=std::move(new_m);
    };
    auto rename_var = [&](Variable& v) {
        auto it = renaming.find(v); 
        if(it != renaming.end())
            v = it->second;
    };

    apply_renaming(implementation);
    auto new_errors = unordered_set<Code>();
    new_errors.reserve(errors.size());
    for (auto error : errors) {
        apply_renaming(error);
        new_errors.insert((error));
    }
    errors=std::move(new_errors);
    for (auto& [name, code] : finals) 
        apply_renaming(code);
    apply_renaming(vardecl);
    auto new_vars = unordered_map<Variable, Type>();
    new_vars.reserve(vars.size());
    for (const auto& [var, type] : vars) {
        if (renaming.find(var) != renaming.end())
            new_vars[renaming[var]] = type;
        else
            new_vars[var] = type;
    }
    vars=std::move(new_vars);

    for (auto& pack : packs)
        if (renaming.find(pack) != renaming.end())
            pack = renaming[pack];
    for (auto& arg : args)
        if (renaming.find(arg.name) != renaming.end())
            arg.name = renaming[arg.name];
    for (auto* v : {&buffer_ptr, &buffer_size, &buffer_release}) 
        if (renaming.find(*v) != renaming.end())
            *v = renaming[*v];

    rename_set(acquired);
    rename_set(singletons);
    rename_set(mutables);
    rename_set(type_trackers);
    rename_set(can_access_mutable_fields);
    rename_map_var_type(buffer_types);
    rename_map_var_var(active_calls);
    rename_map_var_var(original_calls);
    rename_map_var_bool(released);
    rename_map_var_bool(has_been_service_arg);
    rename_map_var_bool(has_been_retrieved_as_immutable);
    rename_map_var_type(parametric_types);
    rename_var(alias_for);
    rename_var(buffer_ptr);
    rename_var(buffer_size);
    rename_var(buffer_release);
    if(uplifting.size())
        rename_var(uplifting[uplifting.size()-1].context);
    rename_map_var_type(retrievable_parameters);

    auto new_finals = unordered_map<Variable, Code>{};
    new_finals.reserve(finals.size());
    for (auto& [k, v] : finals) {
        auto nk = renaming.count(k) ? renaming.at(k) : k;
        apply_renaming(v);
        new_finals[nk] = v;
    }
    finals=std::move(new_finals);

    auto rename_map_var_ulong = [&](unordered_map<Variable, unsigned long>& m) {
        auto new_m = unordered_map<Variable, unsigned long>{};
        new_m.reserve(m.size());
        for (const auto& [k, v] : m)
            new_m[renaming.find(k) != renaming.end() ? renaming[k] : k] = v;
        m=std::move(new_m);
    };
    rename_map_var_ulong(alignments);
}