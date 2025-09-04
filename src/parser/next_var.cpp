#include "../def.h"

Variable Def::next_var(const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test) {
    if(first_token.is_empty()) 
        return Variable("");
    size_t n = i->size();
    if(released[first_token]) 
        imp->error(p-2, "Cannot use already released value: "
            +pretty_var(first_token.to_string())
        );
    if(p>=n) 
        return first_token;
    Variable next = first_token;
    static const Variable token_if = Variable("if(");
    static const Variable token_ifnot = Variable("if(!");
    static const Variable token_goto = Variable(")goto");
    static const Variable token_plus_one = Variable("+1");
    while(true) {
        if(released[next]) 
            imp->error(--p, "Cannot use already released value: "
                +pretty_var(next.to_string())
            );
        if(p>=n) 
            break;
        if(imp->at(p)==":") {
            ++p;
            next = parse_expression(i, p, imp->at(p++), types, next);
        }
        else if(imp->at(p)=="and") {
            if(!internalTypes.contains(next)) 
                imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
            if(internalTypes.vars[next]!=types.vars[BOOL_VAR]) 
                imp->error(--p, "Left hand side of `and` expected bool but got "
                    +internalTypes.vars[next]->name.to_string()
                    +" "+pretty_var(next.to_string())
                );
            ++p;
            Variable prev = next;
            Variable tmp = create_temp();
            internalTypes.vars[tmp] = types.vars[LABEL_VAR];
            implementation +=Code(token_ifnot, next, token_goto, tmp, SEMICOLON_VAR);
            next = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(next)) 
                imp->error(--p, "Unknown symbol "
                    +pretty_var(next.to_string())
                );
            if(internalTypes.vars[next]!=types.vars[BOOL_VAR]) 
                imp->error(--p, "Right hand side of `and` expected bool but got "
                    +internalTypes.vars[next]->name.to_string()
                    +" "+pretty_var(next.to_string())
                );
            implementation += Code(prev,ASSIGN_VAR,next,SEMICOLON_VAR,tmp,COLON_VAR);
            next = prev;
        }
        else if(imp->at(p)=="or") {
            if(!internalTypes.contains(next)) 
                imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
            if(internalTypes.vars[next]!=types.vars[BOOL_VAR]) 
                imp->error(--p, "Left hand side of `or` expected bool but got "
                    +internalTypes.vars[next]->name.to_string()
                    +" "+pretty_var(next.to_string())
                );
            ++p;
            Variable prev = next;
            Variable tmp = create_temp();
            internalTypes.vars[tmp] = types.vars[LABEL_VAR];
            implementation +=Code(token_if, next, token_goto, tmp, SEMICOLON_VAR);
            next = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(next)) 
                imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
            if(internalTypes.vars[next]!=types.vars[BOOL_VAR])
                imp->error(--p, "Right hand side of `or` expected bool but got "
                    +internalTypes.vars[next]->name.to_string()
                    +" "+pretty_var(next.to_string())
                );
            implementation += Code(prev, ASSIGN_VAR, next, SEMICOLON_VAR, tmp, COLON_VAR);
            next = prev;
        }
        else if(imp->at(p)==".") {
            ++p;
            const string& next_token = imp->at(p++);
            Variable var = Variable(next);
            if(active_calls[var].exists()) {
                if(active_calls[active_calls[var]].exists()) {
                    static const Variable token_print = Variable(":\nprintf(\"Runtime error from");
                    static const Variable token_failsafe = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
                    const Variable& call_var = active_calls[var];
                    implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
                    implementation += Code(var+ERR_VAR, ASSIGN_VAR, call_var+STATE_VAR, ARROW_VAR, ERR_VAR, SEMICOLON_VAR);
                    Variable fail_var = create_temp();
                    internalTypes.vars[fail_var] = types.vars[LABEL_VAR];
                    implementation +=Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
                    errors = errors+Code(fail_var, token_print, internalTypes.vars[var]->name, call_var, token_failsafe);
                    add_preample("#include <stdio.h>");
                }
                next = active_calls[var]+next_token;
                if(active_calls[var].exists() && active_calls[active_calls[var]].exists()) 
                    active_calls[active_calls[var]] = EMPTY_VAR;
                continue;
            }

            if(next.exists() && internalTypes.contains(next) && internalTypes.vars[next]->retrievable_parameters.find(next_token)!=internalTypes.vars[next]->retrievable_parameters.end()) {
                Type prevType = internalTypes.vars[next];
                if(prevType->options.size()==1) prevType = *prevType->options.begin();
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
            }
            /*else if(type_trackers.find(next)!=type_trackers.end() && internalTypes.contains(next)) {
                Type prevType = internalTypes.vars[next];
                if(prevType->options.size()==1) prevType = *prevType->options.begin();
                if(prevType->lazy_compile) {
                    if(parametric_types.find(next)==parametric_types.end()) imp->error(--p, "Internal error: has no compiled lazy type "+prevType->signature(types));
                    prevType = parametric_types[next];
                }
                Type type(nullptr);
                for(const auto& arg : prevType->args) 
                    if(arg.type->name==next_token) {type=arg.type;break;} 
                    else if(arg.type->name=="nom" && alignments[arg.name] && types.reverse_alignment_labels[alignments[arg.name]]->name==next_token)
                        {type=types.reverse_alignment_labels[alignments[arg.name]];break;}
                if(!type) imp->error(--p, "Cannot find type "+pretty_var(next_token)+" as any of the arguments of "+prevType->signature(types));
                if(type->options.size()!=1) imp->error(--p, "Ambiguous type "+pretty_var(next_token)+" in the arguments of "+prevType->signature(types));
                type = *type->options.begin();
                next = create_temp();
                if(type->not_primitive()) {
                    for(size_t i=0;i<type->args.size();++i) {
                        assign_variable(type->args[i].type, next+"__"+type->args[i].name, "0", imp, p, true);
                        if(type->args[i].type->name=="nom") alignments[next+"__"+type->args[i].name] = types.alignment_labels[type.get()];
                    }
                    internalTypes.vars[next] = type;
                }
                else assign_variable(type, next, "0", imp, p, true);
                type_trackers.insert(next);
            }*/
            else {
                if(type_trackers.find(next)!=type_trackers.end())
                    imp->error(--p, "Not found "+next_token+" in "+internalTypes.vars[next]->signature(types));
                //if(!internalTypes.contains(next)) imp->error(--p, "Symbol not declared: "+pretty_var(next)); // declare all up to this point
                next = next+next_token;
                if(p>=n) 
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
            }
        }
        else if(imp->at(p)=="[" && internalTypes.contains(next) && internalTypes.vars[next]->name==BUFFER_VAR) {
            if(buffer_types.find(next)==buffer_types.end())
                imp->error(--p, "Internal error: cannot determine the buffer storage data for "
                    +next.to_string()
                );
            ++p;
            Variable idx = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(idx) || internalTypes.vars[idx]->name!=U64_VAR)
                imp->error(--p, "Buffer index must be u64 but got "
                    +(internalTypes.contains(idx)?internalTypes.vars[idx]->name.to_string():"nothing")
                );
            if(imp->at(p++)!="]") 
                imp->error(--p, "Expecting closing square bracket");

            
            internalTypes.vars[next+Variable("__buffer_size")]          = types.vars[Variable("u64")];
            internalTypes.vars[next+Variable("__buffer_alignment")]     = types.vars[Variable("u64")];

            size_t count_packs = 0;
            for (const auto& pack : buffer_types[next]->packs)
                if (buffer_types[next]->internalTypes.contains(pack) && buffer_types[next]->internalTypes.vars[pack]->name != NOM_VAR)
                    count_packs++;
            if(buffer_types[next]->_is_primitive) 
                count_packs++;

            implementation += Code(next+Variable("__buffer_alignment"), ASSIGN_VAR, Variable(to_string(count_packs)), SEMICOLON_VAR);
            implementation += Code(next+Variable("__buffer_size"), ASSIGN_VAR, Variable("((u64*)"), next, Variable(")[1]"), SEMICOLON_VAR);

            Variable fail_var = create_temp();
            internalTypes.vars[fail_var] = types.vars[LABEL_VAR];
            implementation += Code(Variable("if("), idx, Variable(">="), next+Variable("__buffer_size"),
                                Variable(")goto"), fail_var, SEMICOLON_VAR);
            errors = errors + Code(fail_var, Variable(":\nprintf(\"Buffer index out of range\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n"));

            Variable elem = create_temp();

            Variable packname = EMPTY_VAR;
            if(p < i->size()-1 && i->at(p) == ".") 
                packname = i->at(p+1); 

            size_t pack_index = 0;
            if(buffer_types[next]->_is_primitive) {
                Variable tmp = create_temp();
                internalTypes.vars[tmp] = buffer_types[next];
                implementation += Code(
                    Variable("memcpy(&"), tmp, Variable(", &((u64*)((u64*)"), next, Variable(")[0])["),
                    idx, MUL_VAR, next+Variable("__buffer_alignment"), Variable("+"+ to_string(pack_index)+"], sizeof("), 
                    buffer_types[next]->name, Variable("))"), SEMICOLON_VAR
                );
                assign_variable(
                    buffer_types[next],
                    elem,
                    tmp,
                    i, 
                    p
                );
            }
            else {
                internalTypes.vars[elem] = buffer_types[next];
                if(mutables.find(next)!=mutables.end()) 
                    mutables.insert(elem);
                for (const auto& pack : buffer_types[next]->packs) {
                    if(!buffer_types[next]->internalTypes.contains(pack)) 
                        imp->error(--p, "Internal error: failed to unpack value stored on buffer due to unknown type: "
                            +pack.to_string()
                        );
                    else if(buffer_types[next]->internalTypes.vars[pack]->name == NOM_VAR) {
                        Variable tmp = create_temp();
                        internalTypes.vars[tmp] = buffer_types[next]->internalTypes.vars[pack];
                        if(packname.is_empty()) {
                            assign_variable(
                                buffer_types[next]->internalTypes.vars[pack],
                                elem+pack,
                                tmp,
                                i, 
                                p
                            );
                        }
                    }
                    else {
                        if(packname.is_empty() || packname==pack) {
                            Variable tmp = create_temp();
                            if(mutables.find(next)!=mutables.end() && buffer_types[next]->mutables.find(pack)!=buffer_types[next]->mutables.end()) 
                                mutables.insert(tmp);
                            internalTypes.vars[tmp] = buffer_types[next]->internalTypes.vars[pack];
                            implementation += Code(
                                Variable("memcpy(&"), tmp, Variable(", &((u64*)((u64*)"), next, Variable(")[0])["),
                                idx, MUL_VAR, next+Variable("__buffer_alignment"), Variable("+"+ to_string(pack_index)+"], sizeof("), 
                                buffer_types[next]->internalTypes.vars[pack]->name, Variable("))"), SEMICOLON_VAR
                            );
                            assign_variable(
                                buffer_types[next]->internalTypes.vars[pack],
                                elem+pack,
                                tmp,
                                i, 
                                p
                            );
                        }
                        pack_index++;
                    }
                }
            }
            // do this after the loop to not mess with assign_variable
            if(packname.is_empty()) 
                for(const auto& it : buffer_types[next]->internalTypes.vars) 
                    internalTypes.vars[elem+it.first] = it.second;
            for(const auto& it : buffer_types[next]->buffer_types)
                buffer_types[elem+it.first] = it.second;
            next = elem;
        }

        else if(imp->at(p)=="[") {
            if(!internalTypes.contains(next)) 
                imp->error(--p, "Not found: "+pretty_var(next.to_string())+recommend_variable(types, next));
            ++p;
            Variable arg = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(arg)) 
                imp->error(--p, "Not found: "+pretty_var(arg.to_string())+recommend_variable(types, next));
            //if(internalTypes.vars[arg]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(arg)->second->name+" "+pretty_var(arg));
            string end("");
            string method("at");
            if(imp->at(p)=="to") {
                p++;
                method = "slice";
                end = parse_expression(i, p, imp->at(p++), types).to_string();
                if(!internalTypes.contains(end)) 
                    imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                //if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
            }
            else if(imp->at(p)=="upto") {
                if(internalTypes.vars[arg]->name!=U64_VAR) 
                    imp->error(--p, "Expected u64 but found: "
                        +internalTypes.vars.find(arg)->second->name.to_string()
                        +" "+pretty_var(arg.to_string())
                        +"\nYou can only use element access [pos] or non-inclusive `to` ranges [pos to end] for non-u64 pos."
                    );
                p++;
                end = parse_expression(i, p, imp->at(p++), types).to_string();
                if(!internalTypes.contains(end)) 
                    imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                if(internalTypes.vars[end]->name!=U64_VAR) 
                    imp->error(--p, "Expected u64 but found: "
                        +internalTypes.vars.find(end)->second->name.to_string()
                        +" "+pretty_var(end)
                        +"\nYou can only use `upto` with u64. Move to `to` bounds for other end index runtypes."
                    );
                method = "slice";
                string tmp = create_temp();
                assign_variable(internalTypes.vars[end], tmp, end, imp, p);
                implementation += Code(tmp,ASSIGN_VAR,tmp,token_plus_one,SEMICOLON_VAR);
                end = tmp;
            }
            else if(imp->at(p)=="lento") {
                if(internalTypes.vars[arg]->name!=U64_VAR) 
                    imp->error(--p, "Expected u64 but found: "
                        +internalTypes.vars.find(arg)->second->name.to_string()
                        +" "+pretty_var(arg.to_string())
                        +"\nYou can only use element access [pos] or non-inclusive `to` ranges [pos to end] for non-u64 pos."
                    );
                p++;
                end = parse_expression(i, p, imp->at(p++), types).to_string();
                if(!internalTypes.contains(end)) 
                    imp->error(--p, "Not found: "
                        +pretty_var(end)
                        +recommend_variable(types, next)
                    );
                if(internalTypes.vars[end]->name!=U64_VAR) 
                    imp->error(--p, "Expected u64 but found: "
                        +internalTypes.vars.find(end)->second->name.to_string()+" "+pretty_var(end)
                        +"\nYou can only use `lento` with u64. Move to `to` bounds for other end index runtypes."
                    );
                method = "slice";
                Variable tmp = create_temp();
                assign_variable(internalTypes.vars[end], tmp, end, imp, p);
                implementation += Code(tmp,ASSIGN_VAR,tmp,PLUS_VAR,arg,SEMICOLON_VAR);
                end = tmp.to_string();
            }
            if(!types.contains(method)) 
                imp->error(--p, "No implementation for "+method);
            Type type = types.vars[method];
            vector<Variable> unpacks;
            if(internalTypes.vars[next]->is_service) 
                imp->error(--p, "Slice overloads cannot be a service");
            if(internalTypes.vars[next]->not_primitive()) 
                for(const Variable& pack : internalTypes.vars[next]->packs) 
                    unpacks.push_back(next+pack);
            else 
                unpacks.push_back(next);
            unpacks.push_back(arg);
            if(end.size()) 
                unpacks.push_back(end);
            string inherit_buffer = "";
            next = call_type(i, p, type, unpacks, p-1, method, types);
            if(imp->at(p++)!="]") 
                imp->error(--p, "Expecting : or closing square bracket");
        }
        else 
            break;
    }
    if(next.exists() && test && !internalTypes.contains(next)) 
        imp->error(--p, "Not found: "
            +pretty_var(next.to_string())
            +recommend_variable(types, next)
        );
    if(released[next]) 
        imp->error(--p, "Cannot use already released value: "
            +pretty_var(next.to_string())
        );
    return next;
}
