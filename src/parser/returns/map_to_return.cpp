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
#include <ranges>

vector<Variable> Def::map_to_return(size_t& p, Types& types, bool is_zero_level) {
    vector<Variable> packs;
    Variable next = imp->at(p++);
    bool hasComma = false;
    if(is_service && is_zero_level && !ranges::contains(packs, ERR_VAR)) {
        packs.push_back(ERR_VAR);
        vars[ERR_VAR] = types.vars[ERRCODE_VAR];
    }
    if(next==AT_VAR) {
        next = imp->at(p++);
        if(next!=ARGS_VAR) 
            imp->error(--p, "Use `return @args`");
        //choice_power += 4; 
        if(is_service 
            && !uplifting.size() 
            && !ranges::contains(packs, ERR_VAR)
        ){
            packs.push_back(ERR_VAR);
            vars[ERR_VAR] = types.vars[ERRCODE_VAR];
        }
        for (const auto& arg : args) {
            Variable next = arg.name;
            if(vars[next]->nozero)
                nozero = true;
            if(vars[next]->_is_primitive) 
                packs.push_back(next);
            else for(const Variable& pack : vars[next]->packs) {
                packs.push_back(next+pack);
                if(contains(next+pack) && vars[next+pack]->name==NOM_VAR && !alignments[next+pack]) 
                    imp->error(--p, "Returned an unset nominal value "
                        +pretty_var(next.to_string()+"__"+pack.to_string())
                        +"\nAdd a nominal variable as the first argument to the signature and return that instead."
                    );
            }
        }
        p++;
        if(p>=imp->size()) {
            p = imp->size();
            return packs;
        }
        if(imp->at(p-1)!=",") {
            --p;
            return packs;
        }
        hasComma = true;
        p++;
    }

    --p;
    // we are starting parenthesis
    while(true) {
        next = parse_expression(p, imp->at(p++), types);
        if(!contains(next)) 
            break;
        if(released[next]) 
            imp->error(--p, "Returned a released resource: "
                +pretty_var((next).to_string())
                +"\nA previous @release has already ran any attached finalization and invalidataed the variable."
            );
        if(is_service && finals.find(next)!=finals.end() && finals[next].find(TRANSIENT_VAR) != std::string::npos) 
            imp->error(--p, "You are returning @noshare data from a service: "
                +pretty_var(next.to_string())
                +"\nThose use service-local resources, such as its stack memory. Create these data externally and pass them as arguments."
            );
        if(vars[next]->nozero)
            nozero = true;
        if(!vars[next]->not_primitive()) {
            if(contains(next) && vars[next]->name==NOM_VAR && !alignments[next]) 
                imp->error(--p, "You are returning @noshare data from a service: "
                    +pretty_var(next.to_string())
                    +"\nAdd an align first variable to the signature and return that instead"
                );
            if(is_service && !uplifting.size()) {
                implementation += Code(VALUE_VAR,ASSIGN_VAR,next,SEMICOLON_VAR);
                if(contains(VALUE_VAR) && vars[VALUE_VAR]!=vars[next]) 
                    imp->error(--p, "Returning single value of multiple types "
                        +vars[VALUE_VAR]->name.to_string()
                        +" and "+vars[next]->name.to_string()
                    );
                vars[VALUE_VAR] = vars[next];
                packs.push_back(VALUE_VAR);
            }
            else 
                packs.push_back(next);
        }
        else {
            // not primitives here
            if(vars.find(next)==vars.end()) 
                imp->error(--p, "Not found: "
                    +pretty_var(next.to_string())
                    +recommend_variable(types, next)
                );
            if(!hasComma && p<imp->size() && imp->at(p)!=",") {
                alias_for = next;
                noborrow = vars[alias_for]->noborrow;
                noassign = vars[alias_for]->noassign;
                if(noborrow && !imp->allow_unsafe) 
                    imp->error(--p, "Rerurned a @noborrow variable "
                        +pretty_var(alias_for.to_string())
                        +"\nThis is unsafe behavior. Declare the file as @unsafe by placing this at the top level (typically right after imports)."
                    );
                if(vars[alias_for]->alias_for.exists()) 
                    alias_for = next+vars[alias_for]->alias_for;
                
                for(const Variable& pack : vars[next]->packs) {
                    if(released[next+pack]) 
                        imp->error(--p, "Returned a releaased resource: "
                            +pretty_var((next+pack).to_string())
                            +"\nA previous @release has already ran any attached finalization and invalidataed the variable."
                        );
                    if(contains(pack) && vars[pack]!=vars[next]->vars[pack]) 
                        imp->error(--p, "Mismatched types for: "
                            +pretty_var(pack.to_string())
                            +"\nThe current declaration wraps a base type that declares the same internal variable name with a different type."
                        );
                    assign_variable(
                        vars[next]->vars[pack], 
                        pack, 
                        next+pack, 
                        p,
                        false, 
                        false
                    );
                    if(is_service) {
                        coallesce_finals(next+pack);
                        if(finals.find(next+pack)!=finals.end() && finals[next+pack].find(TRANSIENT_VAR) != std::string::npos) 
                            imp->error(--p, 
                                "Returned @noshare data from a service: "
                                +pretty_var(next.to_string()+"__"+pack.to_string())
                                +"\nThose use service-local resources, such as its stack memory. Create these data externally and pass them as arguments."
                            );
                    }
                    packs.push_back(pack);
                    if(vars[next]->buffer_types.find(pack)!=vars[next]->buffer_types.end())
                        vars[pack] = vars[next]->buffer_types[pack];
                    if(contains(pack) && vars[pack]->name==NOM_VAR && !alignments[pack]) 
                        imp->error(--p, "You are returning an unset align "
                            +pretty_var(pack.to_string())
                            +"\nAdd an align first variable to the signature and return that instead."
                        );
                }
                mutables.clear();
                for(const Variable& mut : vars[next]->mutables) 
                    mutables.insert(mut);
                for(const auto& it : vars[next]->finals) 
                    finals[it.first] = finals[it.first]+it.second;
            }
            else {
                for(const Variable& pack : vars[next]->packs) {
                    Variable next_pack = next+pack;
                    if(released[next_pack]) 
                        imp->error(--p, "Returned a releaased resource: "
                            +pretty_var((next_pack).to_string())
                            +"\nA previous @release has already ran any attached finalization and invalidataed the variable."
                        );
                    if(contains(next_pack) && vars[next_pack]->noborrow) 
                        imp->error(--p, "Rerurned a @noborrow variable "
                            +pretty_var(next.to_string()+"__"+pack.to_string())
                            +"\nThis is unsafe behavior. Declare the file as @unsafe by placing this at the top level (typically right after imports)."
                        );
                    packs.push_back(next_pack);
                    if(is_service) {
                        coallesce_finals(next_pack);
                        if(finals.find(next_pack)!=finals.end() && finals[next_pack].find(TRANSIENT_VAR) != std::string::npos) 
                            imp->error(--p, "Returned @noshare data from a service: "
                                +pretty_var((next+pack).to_string())
                                +"\nThose use service-local resources, such as its stack memory. Create these data externally and pass them as arguments."
                            );
                    }
                    if(contains(next_pack) && vars[next_pack]->name==NOM_VAR && !alignments[next_pack]) 
                        imp->error(--p, "Returned an unset nominal value "
                            +pretty_var(next.to_string()+"__"+pack.to_string())
                            +"\nAdd a nominal variable as the first argument to the signature and return that instead."
                        );
                }
            }
        }
        if(p>=imp->size()) {
            p=imp->size();
            break;
        }
        next = imp->at(p++);
        //if(next==")") break;
        if(next!=COMMA_VAR) {
            --p;
            break;
            //imp->error(--p, "Missing comma (not implemented expression in return statements yet)");
        }
        hasComma = true;
    }
    return packs;
}
