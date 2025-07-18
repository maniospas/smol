#include "../def.h"

void Def::parse_directive(const shared_ptr<Import>& imp, size_t& p, string next, Types& types) {
    next = imp->at(p++);
    if(next=="noborrow") {noborrow=true;return;}
    if(next=="head") {
        if(!imp->allow_unsafe) imp->error(--p, "@head is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        next = imp->at(p++);
        if(next!="{") imp->error(--p, "Expected brackets");
        int depth = 1;
        string preample("");
        while(true) {
            next = imp->at(p++);
            if(next=="{") depth++;
            if(next=="}") {depth--;if(depth==0) break;}
            if(next=="#" && preample.size()) {preample += "\n#"; continue;}
            string nextnext = imp->at(p);
            preample += next;
            if(!is_symbol(next) && !is_symbol(nextnext)) preample += " ";
        }
        preample += "\n";
        add_preample(preample);
    }
    else if(next=="body") {
        if(!imp->allow_unsafe) imp->error(--p, "@body is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        next = imp->at(p++);
        if(next!="{") imp->error(--p, "Expected brackets");
        int depth = 1;
        while(true) {
            next = imp->at(p++);
            if(next=="{") depth++;
            if(next=="}") {depth--;if(depth==0) break;}
            string nextnext = imp->at(p);
            if(p<imp->size()-1 && imp->at(p+1)=="=" && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") && !is_symbol(next) && !is_symbol(nextnext)) {
                string argname = nextnext;
                string argtype = next;
                if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->not_primitive()) {
                    internalTypes.vars[argname] = types.vars.find(argtype)->second;
                    // vardecl += argtype+" "+argname+" = 0;\n";
                }
                else imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
            }
            else {
                if(next=="goto") internalTypes.vars[nextnext] = types.vars[LABEL_VAR];
                implementation += next;
                if(!is_symbol(next) && !is_symbol(nextnext)) implementation += " ";
            }
        }
        implementation += "\n";
    }
    else if(next=="noshare") {
        next = imp->at(p++);
        this->finals[next] += "__TRANSIENT("+next+")\n";
    }
    else if(next=="finally") {
        if(!imp->allow_unsafe) imp->error(--p, "@finally is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        string finals("");
        string conditioned("");
        next = imp->at(p++);
        if(next!="{") {conditioned = next; next = imp->at(p++);}
        if(conditioned.size() && !internalTypes.contains(conditioned)) imp->error(p-2, "Expected brackets or conditioning variable but this has not been declared: "+pretty_var(conditioned));
        if(conditioned.size() && internalTypes.vars[conditioned]->not_primitive()) imp->error(p-2, "finally can only be conditioned on a primitive but got "+internalTypes.vars[conditioned]->name.to_string()+" "+pretty_var(conditioned));
        if(next!="{") imp->error(p-1, "Expected brackets");
        int depth = 1;
        while(true) {
            next = imp->at(p++);
            if(next=="{") depth++;
            if(next=="}") {depth--;if(depth==0) break;}
            string nextnext = imp->at(p);
            if(p<imp->size()-1 && imp->at(p+1)=="=" && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") && !is_symbol(next) && !is_symbol(nextnext)) {
                string argname = nextnext;
                string argtype = next;
                if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->not_primitive()) {
                    internalTypes.vars[argname] = types.vars.find(argtype)->second;
                    // vardecl += argtype+" "+argname+" = 0;\n";
                }
                else imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
            }
            else {
                if(next=="goto") internalTypes.vars[nextnext] = types.vars[LABEL_VAR];
                finals += next;
                if(!is_symbol(next) && !is_symbol(nextnext)) finals += " ";
            }
        }
        finals += "\n";
        this->finals[conditioned] += finals;
    }
    else if(next=="fail") {
        if(!imp->allow_unsafe) imp->error(--p, "@fail is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        string fail_label = create_temp();
        internalTypes.vars[fail_label] = types.vars[LABEL_VAR];
        errors += fail_label+":\n";
        next = imp->at(p++);
        if(next!="{") imp->error(--p, "Expected brackets");
        int depth = 1;
        while(true) {
            next = imp->at(p++);
            if(next=="{") depth++;
            if(next=="}") {depth--;if(depth==0) break;}
            string nextnext = imp->at(p);
            if(p<imp->size()-1 && imp->at(p+1)=="=" && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") && !is_symbol(next) && !is_symbol(nextnext)) {
                string argname = nextnext;
                string argtype = next;
                if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->not_primitive()) {
                    internalTypes.vars[argname] = types.vars.find(argtype)->second;
                    // vardecl += argtype+" "+argname+" = 0;\n";
                }
                else imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
            }
            else {
                errors += next;
                if(!is_symbol(next) && !is_symbol(nextnext)) errors += " ";
            }
        }
        errors += "\n__result__errocode=__USER__ERROR;\ngoto __failsafe;\n";
        implementation += "goto "+fail_label+";\n";
        implementation += "__builtin_unreachable();\n";
    }
    else imp->error(--p, "Invalid symbol after @\nOnly @head, @body, @fail, @finally, @noshare are allowed here for injecting C++ code.");
}
