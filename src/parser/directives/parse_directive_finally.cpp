#include "../../def.h"

void Def::parse_directive_finally(const shared_ptr<Import>& imp, size_t& p, string next, Types& types) {
    if(!imp->allow_unsafe) 
        imp->error(--p, "@finally is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
    Code finals;
    string conditioned("");
    next = imp->at(p++);
    if(next!="{") {
        conditioned = next; 
        next = imp->at(p++);
    }
    if(conditioned.size() && !internalTypes.contains(conditioned)) 
        imp->error(p-2, "Expected brackets or conditioning variable but this has not been declared: "
            +pretty_var(conditioned)
        );
    if(conditioned.size() && internalTypes.vars[conditioned]->not_primitive()) 
        imp->error(p-2, "finally can only be conditioned on a primitive but got "
            +internalTypes.vars[conditioned]->name.to_string()
            +" "+pretty_var(conditioned)
        );
    if(next!="{") 
        imp->error(p-1, "Expected opening bracket");
    int depth = 1;
    while(true) {
        next = imp->at(p++);
        if(next=="{") 
            depth++;
        if(next=="}") {
            depth--;
            if(depth==0) 
                break;
        }
        string nextnext = imp->at(p);
        if(p<imp->size()-2 && imp->at(p+1)=="=" && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") && !is_symbol(next) && !is_symbol(nextnext)) {
            string argname = nextnext;
            string argtype = next;
            if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->not_primitive()) 
                internalTypes.vars[argname] = types.vars.find(argtype)->second;
            else imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
        }
        else {
            if(is_symbol_or_digit(next)) 
                while(is_symbol_or_digit(nextnext) 
                    && nextnext!="{" 
                    && nextnext!="}" 
                    && p<imp->size()-1
                ) {
                    next += nextnext;
                    ++p;
                    nextnext = imp->at(p);
                }
            if(next=="goto") 
                internalTypes.vars[nextnext] = types.vars[LABEL_VAR];
            finals += Code(move(Variable(next)));
        }
    }
    finals += Code(ENDL_VAR);
    this->finals[conditioned] += finals;
}