#include "../../def.h"
#include <ranges>

vector<Variable> Def::map_to_return(const shared_ptr<Import>& imp, size_t& p, Types& types, bool is_zero_level) {
    vector<Variable> packs;
    Variable next = imp->at(p++);
    bool hasComma = false;
    if(is_service && is_zero_level) {
        packs.push_back(ERR_VAR);
        internalTypes.vars[ERR_VAR] = types.vars[ERRCODE_VAR];
    }
    if(next==AT_VAR) {
        next = imp->at(p++);
        if(next!=ARGS_VAR) 
            imp->error(--p, "Use `->@args`");
        //choice_power += 4; 
        if(is_service 
            && !uplifting_targets.size() 
            && !ranges::any_of(packs, [](const Variable& pack) {return pack == ERR_VAR;})
        ) {
            packs.push_back(ERR_VAR);
            internalTypes.vars[ERR_VAR] = types.vars[ERRCODE_VAR];
        }
        for (const auto& arg : args) {
            Variable next = arg.name;
            if(internalTypes.vars[next]->_is_primitive) 
                packs.push_back(next);
            else for(const Variable& pack : internalTypes.vars[next]->packs) {
                packs.push_back(next+pack);
                if(internalTypes.contains(next+pack) && internalTypes.vars[next+pack]->name==NOM_VAR && !alignments[next+pack]) 
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
        next = parse_expression(imp, p, imp->at(p++), types);
        if(!internalTypes.contains(next)) 
            break;
        if(released[next]) 
            imp->error(--p, "Returned a releaased resource: "
                +pretty_var((next).to_string())
                +"\nA previous @release has already ran any attached finalization and invalidataed the variable."
            );
        if(is_service && finals.find(next)!=finals.end() && finals[next].find(TRANSIENT_VAR) != std::string::npos) 
            imp->error(--p, "You are returning @noshare data from a service: "
                +pretty_var(next.to_string())
                +"\nThose can only be returned from smo runtypes"
            );
        if(!internalTypes.vars[next]->not_primitive()) {
            if(internalTypes.contains(next) && internalTypes.vars[next]->name==NOM_VAR && !alignments[next]) 
                imp->error(--p, "You are returning @noshare data from a service: "
                    +pretty_var(next.to_string())
                    +"\nAdd an align first variable to the signature and return that instead"
                );
            if(is_service && !uplifting_targets.size()) {
                implementation += Code(VALUE_VAR,ASSIGN_VAR,next,SEMICOLON_VAR);
                if(internalTypes.contains(VALUE_VAR) && internalTypes.vars[VALUE_VAR]!=internalTypes.vars[next]) 
                    imp->error(--p, "Returning single value of multiple types "
                        +internalTypes.vars[VALUE_VAR]->name.to_string()
                        +" and "+internalTypes.vars[next]->name.to_string()
                    );
                internalTypes.vars[VALUE_VAR] = internalTypes.vars[next];
                packs.push_back(VALUE_VAR);
            }
            else 
                packs.push_back(next);
        }
        else {
            // not primitives here
            if(internalTypes.vars.find(next)==internalTypes.vars.end()) 
                imp->error(--p, "Not found: "
                    +pretty_var(next.to_string())
                    +recommend_variable(types, next)
                );
            if(!hasComma && p<imp->size() && imp->at(p)!=",") {
                alias_for = next;
                noborrow = internalTypes.vars[alias_for]->noborrow;
                if(noborrow && !imp->allow_unsafe) 
                    imp->error(--p, "Rerurned a @noborrow variable "
                        +pretty_var(alias_for.to_string())
                        +"\nThis is unsafe behavior. Declare the file as @unsafe by placing this at the top level (typically right after imports)."
                    );
                if(internalTypes.vars[alias_for]->alias_for.exists()) 
                    alias_for = next+internalTypes.vars[alias_for]->alias_for;
                for(const Variable& pack : internalTypes.vars[next]->packs) {
                    if(released[next+pack]) 
                        imp->error(--p, "Returned a releaased resource: "
                            +pretty_var((next+pack).to_string())
                            +"\nA previous @release has already ran any attached finalization and invalidataed the variable."
                        );
                    if(internalTypes.contains(pack) && internalTypes.vars[pack]!=internalTypes.vars[next]->internalTypes.vars[pack]) 
                        imp->error(--p, "Mismatched types for: "
                            +pretty_var(pack.to_string())
                            +"\nThe current declaration wraps a base type that declares the same internal variable name with a different type."
                        );
                    assign_variable(
                        internalTypes.vars[next]->internalTypes.vars[pack], 
                        pack, 
                        next+pack, 
                        imp,
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
                                +"\nThose can only be returned from smo runtypes. Create those data in the caller (or in a wrapper runtype) and pass them to the service."
                            );
                    }
                    packs.push_back(pack);
                    if(internalTypes.contains(pack) && internalTypes.vars[pack]->name==NOM_VAR && !alignments[pack]) 
                        imp->error(--p, "You are returning an unset align "
                            +pretty_var(pack.to_string())
                            +"\nAdd an align first variable to the signature and return that instead."
                        );
                }
                mutables.clear();
                for(const Variable& mut : internalTypes.vars[next]->mutables) 
                    mutables.insert(mut);
                for(const auto& it : internalTypes.vars[next]->finals) 
                    finals[it.first] = finals[it.first]+it.second;
            }
            else {
                for(const Variable& pack : internalTypes.vars[next]->packs) {
                    Variable next_pack = next+pack;
                    if(released[next_pack]) 
                        imp->error(--p, "Returned a releaased resource: "
                            +pretty_var((next_pack).to_string())
                            +"\nA previous @release has already ran any attached finalization and invalidataed the variable."
                        );
                    if(internalTypes.contains(next_pack) && internalTypes.vars[next_pack]->noborrow) 
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
                                +"\nThose can only be returned from smo runtypes. Create those data in the caller (or in a wrapper runtype) and pass them to the service."
                            );
                    }
                    if(internalTypes.contains(next_pack) && internalTypes.vars[next_pack]->name==NOM_VAR && !alignments[next_pack]) 
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
