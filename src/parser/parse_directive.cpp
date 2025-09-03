#include "../def.h"

void Def::parse_directive(const shared_ptr<Import>& imp, size_t& p, string next, Types& types) {
    next = imp->at(p++);
    if(next=="noborrow") {
        noborrow=true;
        return;
    }
    if(next=="head") {
        if(!imp->allow_unsafe) 
            imp->error(--p, "@head is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        next = imp->at(p++);
        if(next!="{") 
            imp->error(--p, "Expected brackets");
        int depth = 1;
        string preample("");
        while(true) {
            next = imp->at(p++);
            if(next=="{") 
                depth++;
            if(next=="}") {
                depth--;
                if(depth==0) 
                    break;
            }
            if(next=="#" && preample.size()) {
                preample += "\n#"; 
                continue;
            }
            string nextnext = imp->at(p);
            preample += next;
            if(!is_symbol(next) && !is_symbol(nextnext)) 
                preample += " ";
        }
        preample += "\n";
        add_preample(preample);
    }
    else if(next=="link") {
        if(!imp->allow_unsafe) 
            imp->error(--p, "@link is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        next = imp->at(p++);
        if(next!="{") 
            imp->error(--p, "Expected brackets");
        int depth = 1;
        string preample("");
        while(true) {
            next = imp->at(p++);
            if(next=="{") 
                depth++;
            if(next=="}") {
                depth--;
                if(depth==0) 
                    break;
            }
            if(next=="#" && preample.size()) {
                preample += "\n#"; 
                continue;
            }
            string nextnext = imp->at(p);
            preample += next;
        }
        add_linker(preample);
    }
    else if(next=="body") {
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
    else if(next=="noshare") {
        static const Variable token_transient_end = Variable(")\n");
        next = imp->at(p++);
        this->finals[next] += Code(TRANSIENT_VAR,move(Variable(next)),move(token_transient_end));
    }
    else if(next=="finally") {
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
                if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->not_primitive()) {
                    internalTypes.vars[argname] = types.vars.find(argtype)->second;
                    // vardecl += argtype+" "+argname+" = 0;\n";
                }
                else imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
            }
            else {
                if(is_symbol_or_digit(next)) while(is_symbol_or_digit(nextnext) && nextnext!="{" && nextnext!="}" && p<imp->size()-1) {
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
    else if(next=="fail") {
        if(!imp->allow_unsafe) 
            imp->error(--p, "@fail is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        Variable fail_label = create_temp();
        internalTypes.vars[fail_label] = types.vars[LABEL_VAR];
        errors = errors+Code(fail_label, COLON_VAR);
        next = imp->at(p++);
        if(next!="{") 
            imp->error(--p, "Expected brackets");
        int depth = 1;
        while(true) {
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
                    imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
            }
            else {
                if(is_symbol_or_digit(next)) 
                    while(is_symbol_or_digit(nextnext) && nextnext!="{" && nextnext!="}" && p<imp->size()-1) {
                        next += nextnext;
                        ++p;
                        nextnext = imp->at(p);
                    }
                errors += Code(move(Variable(next)));
            }
        }
        static const Variable token_error = Variable("\n__result__errocode=__USER__ERROR;\ngoto __failsafe;\n");
        static const Variable token_goto = Variable("goto");
        errors = errors+Code(token_error);
        implementation += Code(token_goto, fail_label, SEMICOLON_VAR, UNREACHABLE_VAR);
    }
    else if(next=="release") {
        next = imp->at(p++);
        Variable next_var = Variable(next);//parse_expression(imp, p, Variable(next), types, Variable(""));
        bool resolved_call = false;
        if(active_calls[next_var].exists() && active_calls[active_calls[next_var]].exists()) {
            const Variable& call_var = active_calls[next_var];
            static const Variable token_if = Variable("if(");
            static const Variable token_goto = Variable(")goto");
            static const Variable token_print = Variable(":\nprintf(\"Runtime error from");
            static const Variable token_failsafe = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
            implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
            implementation += Code(call_var+ERR_VAR, ASSIGN_VAR, call_var+STATE_VAR, DOT_VAR, ERR_VAR, SEMICOLON_VAR);
            Variable fail_var = create_temp();
            internalTypes.vars[fail_var] = types.vars[LABEL_VAR];
            implementation += Code(token_if,call_var+ERR_VAR,token_goto,fail_var, SEMICOLON_VAR);
            errors += Code(fail_var, token_print, internalTypes.vars[call_var]->name, call_var, token_failsafe);
            add_preample("#include <stdio.h>");
            active_calls[call_var] = EMPTY_VAR;
            next_var = call_var;
        }
        //bool found = false;
        Variable& released_var = next_var;
        if(!internalTypes.contains(released_var)) {
            if(resolved_call) 
                return;
            imp->error(--p, "Unknown variable: "
                +pretty_var(released_var.to_string())
            );
        }
        if(has_been_service_arg[released_var]) imp->error(--p, "Cannot release a variable that has been previously passed to a service: "+pretty_var(released_var.to_string()));
        //for(const auto& arg : args) if(arg.name==next) imp->error(--p, "Cannot @release an argument");
        for(const auto& arg : args) if(arg.name==released_var) imp->error(--p, "Cannot @release an argument: "+pretty_var(arg.name.to_string()));
        for(const auto& it : internalTypes.vars[next]->internalTypes.vars) {
            Variable var = released_var+it.first;
            if(has_been_service_arg[var]) 
                imp->error(--p, "Cannot release a variable that has been previously passed to a service: "+pretty_var(var.to_string()));
            coallesce_finals(var);
            if(finals[var].exists()) {
                implementation += finals[var];
                finals[var] = Code();
                //found = true;
            }
            for(const auto& arg : args) 
                if(arg.name==var) 
                    imp->error(--p, "Cannot @release an argument: "
                        +pretty_var(arg.name.to_string())
                    );
            //size_t fp = p-1;
            //assign_variable(internalTypes.vars[var], it.first, ZERO_VAR, imp, fp, false, false);
            //if(internalTypes.vars[var]->_is_primitive && internalTypes.vars[var]->name!=LABEL_VAR) implementation += Code(var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR);
            notify_release(var);
            //internalTypes.vars[it.first] = types.vars[RELEASED_VAR];
        }
        coallesce_finals(next);
        if(finals[next].exists()) {
            implementation += finals[next];
            finals[next] = Code();
            //found = true;
        }
        notify_release(next);
        //if(!found) imp->error(--p, "There is no @finally to @release for the data of variable: "+pretty_var(next));
        //internalTypes.vars[next] = types.vars[RELEASED_VAR];
        //if(!imp->allow_unsafe) imp->error(--p, "@release is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
    }
    else
        imp->error(--p, "Invalid symbol after @\nOnly @head, @body, @fail, @finally, @noshare, @release, @noborrow are allowed here.");
}
