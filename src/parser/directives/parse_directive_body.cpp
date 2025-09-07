#include "../../def.h"

void Def::parse_directive_body(const shared_ptr<Import>& imp, size_t& p, string next, Types& types) {
    if(!imp->allow_unsafe) 
        imp->error(--p, "@body is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
    next = imp->at(p++);
    if(next!="{") 
        imp->error(--p, "Expected brackets");
    int depth = 1;
    while(true) {
        size_t pos = p;
        next = imp->at(p++);
        if(next=="{") depth++;
        if(next=="}") {
            depth--;
            if(depth==0) 
                break;
        }
        string nextnext = imp->at(p);
        if(p<imp->size()-2 && imp->at(p+1)=="=" 
            && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") 
            && !is_symbol(next) && !is_symbol(nextnext)
        ) {
            string argname = nextnext;
            string argtype = next;
            if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->not_primitive()) {
                internalTypes.vars[argname] = types.vars.find(argtype)->second;
                // vardecl += argtype+" "+argname+" = 0;\n";
            }
            else 
                imp->error(pos, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
        }
        else {
            string prev_nextnext = next;
            if(is_symbol_or_digit(next)) 
                while(is_symbol_or_digit(nextnext) && nextnext!="{" && nextnext!="}" && p<imp->size()-1) {
                    next += nextnext;
                    ++p;
                    nextnext = imp->at(p);
                }
            if(next=="goto") 
                internalTypes.vars[nextnext] = types.vars[LABEL_VAR];
            implementation += move(Variable(next));
        }
    }
    implementation += move(Variable(ENDL_VAR));
}