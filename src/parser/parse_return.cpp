#include "../def.h"

void Def::parse_return(const shared_ptr<Import>& imp, size_t& p, string next, Types& types) {
    if(imp->at(p)=="-") {++p;return;}
    if(name=="main" && uplifting_targets.size()<=1) imp->error(p-1, "The main service cannot return a value.\nIt must end at end of file `--`.");
    if(imp->at(p++)!=">") imp->error(p-2, "Expecting return.\nUse `->` to return a value or `--` (or end of file) to return without a value for expressions starting with `-`");
    size_t uplifting = 0;
    while(p+uplifting<imp->size() && imp->at(p+uplifting)==">") ++uplifting;
    p += uplifting;
    if(p<imp->size() && imp->at(p)=="-") {
        p++;
        uplifting++;
        if(uplifting>=uplifting_targets.size()) imp->error(p-1, "Too many levels of uplifting.\nYou are currently on "+to_string(uplifting_targets.size())+" nested blocks in.");
        implementation += "goto "+uplifting_targets[uplifting_targets.size()-uplifting]+";\n";
        return;
    }
    if(uplifting_targets.size()>1){
        uplifting++;
        if(uplifting>=uplifting_targets.size()) imp->error(p-1, "Too many levels of uplifting.\nYou are currently on "+to_string(uplifting_targets.size())+" nested blocks in.");
        next = imp->at(p++);
        next = parse_expression(imp, p, next, types);
        if(internalTypes.contains(next)) assign_variable(internalTypes.vars[next], uplifting_targets[uplifting_targets.size()-uplifting]+"r", next, imp, p);
        implementation += "goto "+uplifting_targets[uplifting_targets.size()-uplifting]+";\n";
        return;
    }
    
    next = imp->at(p++);
    bool hasComma = false;
    if(is_service && uplifting_targets.size()<=1) {
        bool found = false;
        for(const string& pack : packs) if(pack=="err") {found=true;break;}
        if(!found) {
            packs.push_back("err");
            internalTypes.vars["err"] = types.vars["errcode"];
        }
    }
    if(next=="@") {
        next = imp->at(p++);
        if(next!="new") imp->error(--p, "Use `->@new`");
        choice_power++; 
        if(is_service && !uplifting_targets.size())  {
            bool found = false;
            for(const string& pack : packs) if(pack=="err") {found=true;break;}
            if(!found) {
                packs.push_back("err");
                internalTypes.vars["err"] = types.vars["errcode"];
            }
        }
        for (const auto& arg : args) {
            string next = arg.name;
            if(internalTypes.vars[next]->_is_primitive) packs.push_back(next);
            else for(const string& pack : internalTypes.vars[next]->packs) {
                packs.push_back(next+"__"+pack);
                if(internalTypes.contains(next+"__"+pack) && internalTypes.vars[next+"__"+pack]->name=="nom" && !alignments[next+"__"+pack]) imp->error(--p, "You are returning an unset align "+pretty_var(next+"__"+pack)+"\nAdd an align first variable to the signature and return that instead");
            }
        }
        p++;
        if(p>=imp->size()) {p=imp->size();return;}
        if(imp->at(p-1)!=",") {--p;return;}
        hasComma = true;
        p++;
    }

    --p;
    // we are starting parenthesis
    while(true) {
        next = parse_expression(imp, p, imp->at(p++), types);
        if(!internalTypes.contains(next)) break;
        if(is_service && finals.find(next)!=finals.end() && finals[next].find("__TRANSIENT") != std::string::npos) imp->error(--p, "You are returning @noshare data from a"+pretty_var(next)+"\nThose can only be returned from smo runtypes");

        if(!internalTypes.vars[next]->not_primitive()) {
            if(internalTypes.contains(next) && internalTypes.vars[next]->name=="nom" && !alignments[next]) imp->error(--p, "You are returning @noshare data from a service: "+pretty_var(next)+"\nAdd an align first variable to the signature and return that instead");
            if(is_service && !uplifting_targets.size()) {
                implementation += "__value = "+next+";\n";
                if(internalTypes.contains("__value") && internalTypes.vars["__value"]!=internalTypes.vars[next]) imp->error(--p, "Returning single value of multple types "+internalTypes.vars["__value"]->name+" and "+internalTypes.vars[next]->name);
                internalTypes.vars["__value"] = internalTypes.vars[next];
                packs.push_back("__value");
            }
            else packs.push_back(next);
        }
        else {
            // not primitives here
            if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Missing symbol: "+pretty_var(next)+recommend_variable(types, next));
            if(!hasComma && p<imp->size() && imp->at(p)!=",") {
                alias_for = next;
                for(const string& pack : internalTypes.vars[next]->packs) {
                    if(internalTypes.contains(pack)) {
                        if(internalTypes.vars[pack]!=internalTypes.vars[next]->internalTypes.vars[pack]) imp->error(--p, "Mismatching types for: "+pretty_var(next+"__"+pack)+" vs "+pretty_var(pack)+"\nYou are wrapping a base runtype that declares the same name under a different type");
                    }
                    assign_variable(internalTypes.vars[next]->internalTypes.vars[pack], pack, next+"__"+pack, imp, p, false, false);
                    if(is_service) {
                        coallesce_finals(next+"__"+pack);
                        if(finals.find(next+"__"+pack)!=finals.end() && finals[next+"__"+pack].find("__TRANSIENT") != std::string::npos) imp->error(--p, "You are returning @noshare data from a service: "+pretty_var(next+"__"+pack)+"\nThose can only be returned from smo runtypes");
                    }
                    packs.push_back(pack);
                    if(internalTypes.contains(pack) && internalTypes.vars[pack]->name=="nom" && !alignments[pack]) imp->error(--p, "You are returning an unset align "+pretty_var(pack)+"\nAdd an align first variable to the signature and return that instead");
                }
                mutables.clear();
                for(const string& mut : internalTypes.vars[next]->mutables) mutables.insert(mut);
                for(const auto& it : internalTypes.vars[next]->finals) finals[it.first] += it.second;
            }
            else {
                if(internalTypes.vars[next]->name=="buffer") imp->error(--p, "Cannot return a buffer alongside other values");
                for(const string& pack : internalTypes.vars[next]->packs) {
                    packs.push_back(next+"__"+pack);
                    if(is_service) {
                        coallesce_finals(next+"__"+pack);
                        if(finals.find(next+"__"+pack)!=finals.end() && finals[next+"__"+pack].find("__TRANSIENT") != std::string::npos) imp->error(--p, "You are returning @noshare data from a service: "+pretty_var(next+"__"+pack)+"\nThose can only be returned from smo runtypes");
                    }
                    if(internalTypes.contains(next+"__"+pack) && internalTypes.vars[next+"__"+pack]->name=="nom" && !alignments[next+"__"+pack]) imp->error(--p, "You are returning an unset align "+pretty_var(next+"__"+pack)+"\nAdd an align first variable to the signature and return that instead");
                }
            }
        }
        if(p>=imp->size()){p=imp->size();break;}
        next = imp->at(p++);
        //if(next==")") break;
        if(next!=",") {--p;break;}//imp->error(--p, "Missing comma (not implemented expression in return statements yet)");
        hasComma = true;
    }
}
