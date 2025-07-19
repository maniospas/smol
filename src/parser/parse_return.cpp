#include "../def.h"


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
        if(next!=NEW_VAR) imp->error(--p, "Use `->@new`");
        choice_power++; 
        if(is_service && !uplifting_targets.size())  {
            bool found = false;
            for(const Variable& pack : packs) if(pack==ERR_VAR) {found=true;break;}
            if(!found) {
                packs.push_back(ERR_VAR);
                internalTypes.vars[ERR_VAR] = types.vars[ERRCODE_VAR];
            }
        }
        for (const auto& arg : args) {
            Variable next = arg.name;
            if(internalTypes.vars[next]->_is_primitive) packs.push_back(next);
            else for(const Variable& pack : internalTypes.vars[next]->packs) {
                packs.push_back(next+pack);
                if(internalTypes.contains(next+pack) && internalTypes.vars[next+pack]->name=="nom" && !alignments[next+pack]) imp->error(--p, "You are returning an unset align "+pretty_var(next.to_string()+"__"+pack.to_string())+"\nAdd an align first variable to the signature and return that instead");
            }
        }
        p++;
        if(p>=imp->size()) {p=imp->size();return packs;}
        if(imp->at(p-1)!=",") {--p;return packs;}
        hasComma = true;
        p++;
    }

    --p;
    // we are starting parenthesis
    while(true) {
        next = parse_expression(imp, p, imp->at(p++), types);
        if(!internalTypes.contains(next)) break;
        if(is_service && finals.find(next)!=finals.end() && finals[next].find(TRANSIENT_VAR) != std::string::npos) imp->error(--p, "You are returning @noshare data from a"+pretty_var(next.to_string())+"\nThose can only be returned from smo runtypes");
        if(!internalTypes.vars[next]->not_primitive()) {
            if(internalTypes.contains(next) && internalTypes.vars[next]->name=="nom" && !alignments[next]) imp->error(--p, "You are returning @noshare data from a service: "+pretty_var(next.to_string())+"\nAdd an align first variable to the signature and return that instead");
            if(is_service && !uplifting_targets.size()) {
                implementation +=Code(VALUE_VAR,ASSIGN_VAR,next,SEMICOLON_VAR);
                if(internalTypes.contains(VALUE_VAR) && internalTypes.vars[VALUE_VAR]!=internalTypes.vars[next]) imp->error(--p, "Returning single value of multiple types "+internalTypes.vars[VALUE_VAR]->name.to_string()+" and "+internalTypes.vars[next]->name.to_string());
                internalTypes.vars[VALUE_VAR] = internalTypes.vars[next];
                packs.push_back(VALUE_VAR);
            }
            else packs.push_back(next);
        }
        else {
            // not primitives here
            if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Not found: "+pretty_var(next.to_string())+recommend_variable(types, next));
            if(!hasComma && p<imp->size() && imp->at(p)!=",") {
                alias_for = next;
                noborrow = internalTypes.vars[alias_for]->noborrow;
                if(noborrow && !imp->allow_unsafe) imp->error(--p, "Rerurning a @noborrow type for variable "+pretty_var(alias_for.to_string())+" is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
                if(internalTypes.vars[alias_for]->alias_for.exists()) alias_for = next+internalTypes.vars[alias_for]->alias_for;
                for(const Variable& pack : internalTypes.vars[next]->packs) {
                    if(internalTypes.contains(pack)) {
                        if(internalTypes.vars[pack]!=internalTypes.vars[next]->internalTypes.vars[pack]) imp->error(--p, "Mismatching types for: "+pretty_var(pack.to_string())+"\nYou are wrapping a base runtype that declares the same internal variable name under a different type");
                    }
                    assign_variable(internalTypes.vars[next]->internalTypes.vars[pack], pack, next+pack, imp, p, false, false);
                    if(is_service) {
                        coallesce_finals(next+pack);
                        if(finals.find(next+pack)!=finals.end() && finals[next+pack].find(TRANSIENT_VAR) != std::string::npos) imp->error(--p, "You are returning @noshare data from a service: "+pretty_var(next.to_string()+"__"+pack.to_string())+"\nThose can only be returned from smo runtypes");
                    }
                    packs.push_back(pack);
                    if(internalTypes.contains(pack) && internalTypes.vars[pack]->name=="nom" && !alignments[pack]) imp->error(--p, "You are returning an unset align "+pretty_var(pack.to_string())+"\nAdd an align first variable to the signature and return that instead");
                }
                mutables.clear();
                for(const Variable& mut : internalTypes.vars[next]->mutables) mutables.insert(mut);
                for(const auto& it : internalTypes.vars[next]->finals) finals[it.first] = finals[it.first]+it.second;
            }
            else {
                if(internalTypes.vars[next]->name==BUFFER_VAR) imp->error(--p, "Cannot return a buffer alongside other values");
                for(const Variable& pack : internalTypes.vars[next]->packs) {
                    Variable next_pack = next+pack;
                    if(internalTypes.contains(next_pack) && internalTypes.vars[next_pack]->noborrow) imp->error(--p, "Rerurning a @noborrow type for variable "+pretty_var(next.to_string()+"__"+pack.to_string())+" is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
                    packs.push_back(next_pack);
                    if(is_service) {
                        coallesce_finals(next_pack);
                        if(finals.find(next_pack)!=finals.end() && finals[next_pack].find(TRANSIENT_VAR) != std::string::npos) imp->error(--p, "You are returning @noshare data from a service: "+pretty_var(next.to_string()+"__"+pack.to_string())+"\nThose can only be returned from smo runtypes");
                    }
                    if(internalTypes.contains(next_pack) && internalTypes.vars[next_pack]->name=="nom" && !alignments[next_pack]) imp->error(--p, "You are returning an unset align "+pretty_var(next.to_string()+"__"+pack.to_string())+"\nAdd an align first variable to the signature and return that instead");
                }
            }
        }
        if(p>=imp->size()){p=imp->size();break;}
        next = imp->at(p++);
        //if(next==")") break;
        if(next!=COMMA_VAR) {--p;break;}//imp->error(--p, "Missing comma (not implemented expression in return statements yet)");
        hasComma = true;
    }
    return packs;
}


void Def::parse_return(const shared_ptr<Import>& imp, size_t& p, Variable next, Types& types) {
    size_t uplifting = 0;
    static const Variable token_goto = Variable("goto");
    if(next=="|") {
        --p;
        while(p+uplifting<imp->size() && imp->at(p+uplifting)=="|") ++uplifting;
        p += uplifting;
        if(imp->at(p++)!="-") imp->error(--p, "Expecting `--` or `->` after uplifting operator `|`");
    }
    if(imp->at(p)=="-") {
        ++p;
        if(uplifting) implementation +=Code(token_goto,uplifting_targets[0],SEMICOLON_VAR);
        return;
    }
    if(imp->at(p++)!=">") imp->error(p-2, "Expecting return.\nUse `->` to return a value or `--` (or end of file) to return without a value for expressions starting with `-`");
    if(uplifting>=uplifting_targets.size()) imp->error(p-3, "Too many levels of uplifting.\nYou are currently on "+to_string(uplifting_targets.size()-1)+" nested blocks in.");
    if(p<imp->size() && imp->at(p)=="-") {
        p++;
        implementation +=Code(token_goto,uplifting_targets[uplifting_targets.size()-uplifting-1],SEMICOLON_VAR);
        if(has_returned && uplifting_targets.size()-uplifting==1 && packs.size()) imp->error(p-1, "Cannot mix a no-return and a return");
        if(uplifting_targets.size()==1+uplifting) has_returned = true;
        return;
    }
    if(uplifting_targets.size()>1+uplifting) {
        if(uplifting>=uplifting_targets.size()) imp->error(p-3, "Too many levels of uplifting.\nYou are currently on "+to_string(uplifting_targets.size()-1)+" nested blocks in.");
        next = imp->at(p++);
        next = parse_expression(imp, p, next, types);
        if(internalTypes.contains(next)) assign_variable(internalTypes.vars[next], uplifting_targets[uplifting_targets.size()-uplifting-1]+Variable("r"), next, imp, p);
        implementation +=Code(token_goto,uplifting_targets[uplifting_targets.size()-uplifting-1],SEMICOLON_VAR);
        return;
    }

    vector<Variable> tentative = map_to_return(imp, p, types, true);
    if(!has_returned) packs = tentative;
    else if(packs.size()!=tentative.size()) imp->error(--p, "Incompatible returns\nprevious "+signature_like(types, packs)+" vs last "+signature_like(types, tentative));
    else {
        for(size_t i=0;i<packs.size();++i) {
            if(internalTypes.vars[packs[i]]!=internalTypes.vars[tentative[i]]) imp->error(--p, "Incompatible returns\nprevious "+signature_like(types, packs)+" vs last "+signature_like(types, tentative));
            assign_variable(internalTypes.vars[packs[i]], tentative[i], packs[i], imp, p, false, false);
        }
    }
    implementation +=Code(token_goto,uplifting_targets[0],SEMICOLON_VAR);
    has_returned = true;
}
