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

void Def::parse_directive_fail(size_t& p, string next, Types& types) {
    if(!imp->allow_unsafe) 
        imp->error(--p, "@fail is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
    Variable fail_label = create_temp();
    vars[fail_label] = types.vars[LABEL_VAR];
    Code directive_errors = Code(fail_label, COLON_VAR);
    next = imp->at(p++);
    if(next!="{") 
        imp->error(--p, "Expected brackets");
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
        if(p<imp->size()-2 && imp->at(p+1)=="=" 
            && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") 
            && !is_symbol(next) 
            && !is_symbol(nextnext)
        ) {
            string argname = nextnext;
            string argtype = next;
            if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->not_primitive()) 
                vars[argname] = types.vars.find(argtype)->second;
            else 
                imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
        }
        else {
            if(is_symbol_or_digit(next)) 
                while(is_symbol_or_digit(nextnext) 
                    && nextnext!="{"
                    && nextnext!="}" 
                    && p<imp->size()-1) 
                {
                    next += nextnext;
                    ++p;
                    nextnext = imp->at(p);
                }
            directive_errors += Code(Variable(next));
        }
    }
    static const Variable token_error = Variable("\n__result__errocode=__USER__ERROR;\ngoto __failsafe;\n");
    static const Variable token_goto = Variable("goto");
    directive_errors += Code(token_error);
    implementation += Code(token_goto, fail_label, SEMICOLON_VAR, UNREACHABLE_VAR);
    errors.insert(directive_errors);
}