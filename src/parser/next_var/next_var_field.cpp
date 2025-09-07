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

Variable Def::next_var_field(Variable next, const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test, bool& skip) {
    ++p;
    const string& next_token = imp->at(p++);
    Variable var = Variable(next);
    if(active_calls.find(var)!=active_calls.end() && active_calls[var].exists()) {
        if(active_calls[active_calls[var]].exists()) {
            static const Variable token_print = Variable(":\nprintf(\"Runtime error from");
            static const Variable token_failsafe = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
            const Variable& call_var = active_calls[var];
            implementation += Code(
                Variable("__smolambda_task_wait"),
                LPAR_VAR,
                call_var+TASK_VAR,
                RPAR_VAR,
                SEMICOLON_VAR
            );
            internalTypes.vars[var+ERR_VAR] = types.vars[ERRCODE_VAR];
            implementation += Code(
                call_var+ERR_VAR, 
                ASSIGN_VAR, 
                call_var+STATE_VAR, 
                ARROW_VAR, 
                ERR_VAR, 
                SEMICOLON_VAR
            );
            implementation += Code(
                var+ERR_VAR, 
                ASSIGN_VAR, 
                call_var+ERR_VAR,
                SEMICOLON_VAR
            );
            Variable fail_var = create_temp();
            internalTypes.vars[fail_var] = types.vars[LABEL_VAR];
            if(next_token!=ERR_VAR)
                implementation += Code(
                    token_if, 
                    call_var+ERR_VAR, 
                    token_goto, 
                    fail_var, 
                    SEMICOLON_VAR
                );
            errors += Code(
                fail_var, 
                token_print, 
                internalTypes.contains(var)?internalTypes.vars[var]->name:EMPTY_VAR, 
                call_var, 
                token_failsafe
            );
            add_preample("#include <stdio.h>");
        }
        next = active_calls[var]+next_token;
        if(active_calls.find(var)!=active_calls.end() 
            && active_calls[var].exists() 
            && active_calls[active_calls[var]].exists()
        ) 
            active_calls[active_calls[var]] = EMPTY_VAR;
        if(!imp->allow_unsafe 
            && internalTypes.contains(next) 
            && internalTypes.vars[next]->name==NOM_VAR
        )
            imp->error(--p, "Direct access of `nominal` fields is unsafe.\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        skip = true;
        return next;
    }
    skip = false;

    if(next.exists() 
        && internalTypes.contains(next) 
        && internalTypes.vars[next]->retrievable_parameters.find(next_token)
            !=internalTypes.vars[next]->retrievable_parameters.end()
    ) {
        Type prevType = internalTypes.vars[next];
        if(prevType->options.size()==1) 
            prevType = *prevType->options.begin();
        if(prevType->lazy_compile) {
            if(parametric_types.find(next)==parametric_types.end()) 
                imp->error(--p, "Internal error: has no compiled lazy type "+prevType->signature(types));
            prevType = parametric_types[next];
        }
        Type type = prevType->retrievable_parameters[next_token];
        if(type->name=="ptr" && !imp->allow_unsafe) 
            imp->error(--p, "Direct access of `ptr` fields is unsafe.\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
        next = create_temp();
        if(type->not_primitive()) {
            for(size_t i=0;i<type->args.size();++i) {
                assign_variable(type->args[i].type, next+type->args[i].name, ZERO_VAR, imp, p, true);
                if(type->args[i].type->name==NOM_VAR) 
                    alignments[next+type->args[i].name] = types.alignment_labels[type.get()];
            }
            internalTypes.vars[next] = type;
        }
        else assign_variable(type, next, ZERO_VAR, imp, p, true);
        type_trackers.insert(next);
        if(!imp->allow_unsafe && internalTypes.contains(next) && internalTypes.vars[next]->name==NOM_VAR)
            imp->error(--p, "Direct access of `nominal` fields is unsafe.\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
    }
    else {
        if(type_trackers.find(next)!=type_trackers.end())
            imp->error(--p, "Not found "+next_token+" in "+internalTypes.vars[next]->signature(types));
        //if(!internalTypes.contains(next)) imp->error(--p, "Symbol not declared: "+pretty_var(next)); // declare all up to this point
        next = next+next_token;
        if(p>=imp->size()) 
            return first_token;
        if(next.exists() && test && !internalTypes.contains(next)) 
            imp->error(--p, "Not found: "
                +pretty_var(next.to_string())
                +recommend_variable(types, next)
            );
        if(internalTypes.contains(next) && internalTypes.vars[next]->name==PTR_VAR && !imp->allow_unsafe) 
            imp->error(--p, "Direct access of `ptr` fields is unsafe."
                "\nDeclare the file as @unsafe by placing this at the top level (typically after imports)"
            );
        if(!imp->allow_unsafe && internalTypes.contains(next) && internalTypes.vars[next]->name==NOM_VAR)
            imp->error(--p, "Direct access of `nominal` fields is unsafe.\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
    }
    return next;
}