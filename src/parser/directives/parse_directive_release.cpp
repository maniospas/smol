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

void Def::parse_directive_release(const shared_ptr<Import>& imp, size_t& p, string next, Types& types) {
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
        vars[fail_var] = types.vars[LABEL_VAR];
        implementation += Code(token_if,call_var+ERR_VAR,token_goto,fail_var, SEMICOLON_VAR);
        errors += Code(fail_var, token_print, vars[call_var]->name, call_var, token_failsafe);
        add_preample("#include <stdio.h>");
        active_calls[call_var] = EMPTY_VAR;
        next_var = call_var;
    }
    //bool found = false;
    Variable& released_var = next_var;
    if(!contains(released_var)) {
        if(resolved_call) 
            return;
        imp->error(--p, "Unknown variable: "
            +pretty_var(released_var.to_string())
        );
    }
    if(has_been_service_arg[released_var]) imp->error(--p, "Cannot release a variable that has been previously passed to a service: "+pretty_var(released_var.to_string()));
    //for(const auto& arg : args) if(arg.name==next) imp->error(--p, "Cannot @release an argument");
    for(const auto& arg : args) if(arg.name==released_var) imp->error(--p, "Cannot @release an argument: "+pretty_var(arg.name.to_string()));
    for(const auto& it : vars[next]->vars) {
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
        //assign_variable(vars[var], it.first, ZERO_VAR, imp, fp, false, false);
        //if(vars[var]->_is_primitive && vars[var]->name!=LABEL_VAR) implementation += Code(var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR);
        notify_release(var);
        //vars[it.first] = types.vars[RELEASED_VAR];
    }
    coallesce_finals(next);
    if(finals[next].exists()) {
        implementation += finals[next];
        finals[next] = Code();
        //found = true;
    }
    notify_release(next);
    //if(!found) imp->error(--p, "There is no @finally to @release for the data of variable: "+pretty_var(next));
    //vars[next] = types.vars[RELEASED_VAR];
    //if(!imp->allow_unsafe) imp->error(--p, "@release is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
}