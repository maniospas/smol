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
#include "../def.h"

void Def::end_block(size_t& p) {
    auto depth = size_t{0};
    while(p<imp->size()) {
        auto next = imp->at(p++);
        if(next=="if" || next=="while" || next=="algorithm")
            depth++;
        else if(next=="then" || next=="return") {
            imp->error(--p, "Cannot end a `case` on `then` or `return` but only on qed");
            depth--;
        }
        if(next=="def" || next=="service" || next=="union") 
            imp->error(--p, "Unexpected end of `case`");
        if(depth==0&&(next=="qed" || next=="case")) {
            p--;
            break;
        }
    }
}

void Def::parse(const shared_ptr<Import>& _imp, size_t& p, Types& types, bool with_signature) {
    if(!imp) 
        imp = _imp;
    if(!imp) 
        ERROR("Internal error: tried to parse a runtype without a file "+name.to_string());
    if(with_signature) {
        pos = p;
        parse_signature(p, types);
    }
    if(!uplifting.size()) 
        uplifting.emplace_back(Variable("__end"), 0, true, false);
    saved_types = types;
    start = p;
    parse_implementation(p, with_signature);
}

void Def::parse_no_implementation(size_t& p, Types& types, bool with_signature) {
    if(!imp) 
        ERROR("Internal error: tried to parse a runtype without a file "+name.to_string());
    if(with_signature) {
        pos = p;
        parse_signature(p, types);
    }
    if(!uplifting.size()) 
        uplifting.emplace_back(Variable("__end"), 0, false, false);

    saved_types.vars.reserve(types.vars.size());
    saved_types.alignment_labels.reserve(types.alignment_labels.size());
    saved_types.reverse_alignment_labels.reserve(types.reverse_alignment_labels.size());
    for(const auto& it : types.vars) 
        saved_types.vars[it.first] = it.second;
    for(const auto& it : types.alignment_labels) 
        saved_types.alignment_labels[it.first] = it.second;
    for(const auto& it : types.reverse_alignment_labels) 
        saved_types.reverse_alignment_labels[it.first] = it.second;
    start = p;
}

void Def::parse_implementation(size_t& p, bool with_signature) {
    if(_is_primitive) 
        return;
    if(!imp) 
        ERROR("Internal error: tried to parse a runtype implementation without a file "+name.to_string());
    if(lazy_compile && with_signature) 
        return;
    auto& types = saved_types;
    auto next_assignments = unordered_set<Variable>{};
    auto imp_size = imp->size()+1;
    while(p<imp->size()) {
        if(uplifting.size() && uplifting[uplifting.size()-1].has_exited) {
            if(uplifting[uplifting.size()-1].has_returned && contains(uplifting[uplifting.size()-1].target+Variable("var")))
                imp->error(p, "Ending a code block that is expecting a return value");
            uplifting[uplifting.size()-1].has_returned = true;
            break;
        }
        if(p>=imp_size) {
            --p;
            break;
        }
        if(imp->at(p)=="then") {
            if(!uplifting.size() || uplifting[uplifting.size()-1].proving)
                return;
            p++;
            imp_size = p;
        }

        bool is_next_assignment = false;
        bool is_access_assignment = false;
        bool is_mutable_assignment = false;
        string next = imp->at(p++);

        if(next=="def" || next=="service" || next=="union") {
            --p;
            //imp->error(p-1, "Missing end or return\nThe previous function needs to end before this declaration");
            if(uplifting[uplifting.size()-1].has_returned && contains(uplifting[uplifting.size()-1].target+Variable("var")))
                imp->error(p, "Here ends a code block that is expecting a returned value");
            --p;
            break;
        }

        if(next=="@") {
            if(p<imp->size() && imp->at(p)=="next"){
                is_next_assignment=true;
                p++;
                next = imp->at(p++);
            }
            else if(p<imp->size() && imp->at(p)=="mut"){
                is_mutable_assignment=true;
                p++;
                next = imp->at(p++);
                if(next=="@" && imp->at(p)=="access") 
                    imp->error(--p, "`@access` should be placed before `@mut`");
            }
            else if(p<imp->size() && imp->at(p)=="access"){
                is_access_assignment=true;
                p++;
                next = imp->at(p++);
                if(next=="@" && imp->at(p)=="mut") {
                    is_mutable_assignment=true;
                    p++;
                    next = imp->at(p++);
                }
            }
            else {
                parse_directive(p, next, types);
                continue;
            }
        }
        if(uplifting.size() && uplifting[uplifting.size()-1].proving && (next=="case" || next=="qed")) {
            --p;
            return; // abrupt return - we will re-enter from parse_with
        }
        if(next=="qed")
            imp->error(--p, "Cannot have `qed` inside a block without an internal `case` statement");
        if(next=="return" || (next=="else"&&uplifting.size()>1)) {
            parse_return(p, next, types);
            if(uplifting.size()) 
                uplifting[uplifting.size()-1].has_exited = true;
            if(next=="else")
                end = (p-=2);
            else
                end = --p;
            continue;
        }
        // if(next=="else") {
        //     --p;
        //     end = p--; 
        //     break;
        // }
        Variable var = imp->at(p);
        if(var=="=" && p<imp->size()-1 && imp->at(p+1)=="=") 
            var = EMPTY_VAR;
        if(var=="." || var=="=") {
            if(types.contains(next) && var=="=")
                imp->error(--p, "Variable cannot shadow a function name: "+pretty_var(next));
            var = next_var(p, next, types, false);
            if(is_mutable_assignment) {
                if(contains(var)) 
                    imp->error(--p, "Cannot set as mutable an existing variable: "
                        +var.to_string()
                        +"\nMutability is declared by `@mut` in the first declaration"
                    ); 
                mutables.insert(var);
            }
            if(is_access_assignment)
                can_access_mutable_fields.insert(var);
            size_t assignment_start = p-1;
            if(imp->at(p++)!="=") {
                --p;
                continue;
            }//imp->error(--p, "Missing assignment");
            next = imp->at(p++);
            Variable expression_outcome = parse_expression(p, next, types);
            if(!expression_outcome.exists()) 
                imp->error(assignment_start, "The right-hand-side expression computes to no value");
            const auto& it = vars.find(expression_outcome);
            if(it==vars.end()) 
                imp->error(assignment_start, "Failed to parse expression");
            if(it->second->noassign && !imp->allow_unsafe)
                imp->error(assignment_start, "Cannot assign a result marked as @noassign to a non-temporary variable: "
                        +it->second->name.to_string()+" "+pretty_var(var.to_string())
                        +"\nThis is considered unsafe behavior and can only be enabled with @unsafe"
                );
            if(is_next_assignment) {
                next_assignments.insert(var);
                var = NEXT_VAR+var;
            }
            if(is_mutable_assignment && mutables.find(expression_outcome)==mutables.end()) {
                for(const auto& pack : vars[expression_outcome]->packs) {
                    if((vars[expression_outcome]->vars[pack]->name==PTR_VAR 
                            || vars[expression_outcome]->vars[pack]->name==BUFFER_VAR)
                        && mutables.find(var+pack)==mutables.end()
                    ) 
                        imp->error(assignment_start, "Cannot transfer an immutable ptr packed in an immutable variable to a mutable ptr: "
                            + pretty_var((var+pack).to_string())
                            + "\nThis error occurs because, by convention, the contents (but not addresses) "
                            + "\nof mutable pointers may be freely modified when runtypes gain a hold of them."
                        );
                }
            } 
            // else {
            //     for(const auto& pack : vars[expression_outcome]->packs) {
            //         if((vars[expression_outcome]->vars[pack]->name==PTR_VAR 
            //                 || vars[expression_outcome]->vars[pack]->name==BUFFER_VAR)
            //             && !can_mutate(var+pack, p)
            //         ) 
            //             imp->error(assignment_start, "Cannot transfer a mutable ptr packed in a mutable variable to an immutable ptr: "
            //                 + pretty_var((var+pack).to_string())
            //                 + "\nThis error occurs because, by convention, the contents (but not addresses) "
            //                 + "\nof mutable pointers may be freely modified when runtypes gain a hold of them."
            //             );
            //     }
            // }
            if(!accepted_var_name(var.to_string())) 
                imp->error(assignment_start, "Not a valid name");
            if(types.vars.find(var)!=types.vars.end()) 
                imp->error(assignment_start, "Invalid variable name\nIt is a previous runtype or union");
            assign_variable(it->second, var, expression_outcome, p);
        }
        else if(is_next_assignment) 
            imp->error(p, "Expecting assignment to variable after @next");
        else if(is_mutable_assignment) 
            imp->error(p, "Expecting assignment to variable after `@mut`");
        else {
            if(next=="(")
                imp->error(p-1, "Opening parenthesis not allowed here\nYou are not allowed to start a function body expression with a parenthesis; this is often an errorneous attempt to call a function after the previous expression has ended.");
            parse_expression(p, next, types);
        }
    }
    for(const Variable& var : next_assignments) 
        assign_variable(vars[NEXT_VAR+var], var, NEXT_VAR+var.to_string(), p);
    if(with_signature) {
        static const Variable endvar = Variable("__end");
        vars[endvar] = types.vars[LABEL_VAR];
        implementation += Code(endvar, COLON_VAR);
        simplify();
        if(p<imp->size()-1 && imp->at(p+1)!="@" && imp->at(p+1)!="def" && imp->at(p+1)!="service" && imp->at(p+1)!="union")
            imp->error(p+1, "Unparsed code\nThe function has already ended, so it can only be followed by def, service, union, or @ directives");
    }
}
