#include "../def.h"

Variable Def::next_var(const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test) {
    if(first_token.is_empty()) return Variable("");
    size_t n = i->size();
    if(p>=n) return first_token;
    Variable next = first_token;
    static const Variable token_if = Variable("if(");
    static const Variable token_ifnot = Variable("if(!");
    static const Variable token_goto = Variable(")goto");
    static const Variable token_plus_one = Variable("+1");
    while(true) {
        if(released[next]) imp->error(--p, "Cannot use already released value: "+pretty_var(next.to_string()));
        if(p>=n) break;
        if(imp->at(p)==":") {
            ++p;
            next = parse_expression(i, p, imp->at(p++), types, next);
        }
        else if(imp->at(p)=="and") {
            if(!internalTypes.contains(next)) imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
            if(internalTypes.vars[next]!=types.vars[BOOL_VAR]) imp->error(--p, "Left hand side of `and` expected bool but got "+internalTypes.vars[next]->name.to_string()+" "+pretty_var(next.to_string()));
            ++p;
            Variable prev = next;
            Variable tmp = create_temp();
            internalTypes.vars[tmp] = types.vars[LABEL_VAR];
            implementation +=Code(token_ifnot, next, token_goto, tmp, SEMICOLON_VAR);
            next = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(next)) imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
            if(internalTypes.vars[next]!=types.vars[BOOL_VAR]) imp->error(--p, "Right hand side of `and` expected bool but got "+internalTypes.vars[next]->name.to_string()+" "+pretty_var(next.to_string()));
            implementation +=Code(prev,ASSIGN_VAR,next,SEMICOLON_VAR,tmp,COLON_VAR);
            next = prev;
        }
        else if(imp->at(p)=="or") {
            if(!internalTypes.contains(next)) imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
            if(internalTypes.vars[next]!=types.vars[BOOL_VAR]) imp->error(--p, "Left hand side of `or` expected bool but got "+internalTypes.vars[next]->name.to_string()+" "+pretty_var(next.to_string()));
            ++p;
            Variable prev = next;
            Variable tmp = create_temp();
            internalTypes.vars[tmp] = types.vars[LABEL_VAR];
            implementation +=Code(token_if, next, token_goto, tmp, SEMICOLON_VAR);
            next = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(next)) imp->error(--p, "Unknown symbol "+pretty_var(next.to_string()));
            if(internalTypes.vars[next]!=types.vars[BOOL_VAR]) imp->error(--p, "Right hand side of `or` expected bool but got "+internalTypes.vars[next]->name.to_string()+" "+pretty_var(next.to_string()));
            implementation +=Code(prev, ASSIGN_VAR, next, SEMICOLON_VAR, tmp, COLON_VAR);
            next = prev;
        }
        else if(imp->at(p)==".") {
            ++p;
            const string& next_token = imp->at(p++);
            if(next.exists() && internalTypes.contains(next) && internalTypes.vars[next]->retrievable_parameters.find(next_token)!=internalTypes.vars[next]->retrievable_parameters.end()) {
                Type prevType = internalTypes.vars[next];
                if(prevType->options.size()==1) prevType = *prevType->options.begin();
                if(prevType->lazy_compile) {
                    if(parametric_types.find(next)==parametric_types.end()) imp->error(--p, "Internal error: has no compiled lazy type "+prevType->signature(types));
                    prevType = parametric_types[next];
                }
                Type type = prevType->retrievable_parameters[next_token];
                if(type->name=="ptr" && !imp->allow_unsafe) imp->error(--p, "Direct access of `ptr` fields is unsafe.\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
                next = create_temp();
                if(type->not_primitive()) {
                    for(size_t i=0;i<type->args.size();++i) {
                        assign_variable(type->args[i].type, next+type->args[i].name, ZERO_VAR, imp, p, true);
                        if(type->args[i].type->name==NOM_VAR) alignments[next+type->args[i].name] = types.alignment_labels[type.get()];
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
                if(type_trackers.find(next)!=type_trackers.end())imp->error(--p, "Not found "+next_token+" in "+internalTypes.vars[next]->signature(types));
                //if(!internalTypes.contains(next)) imp->error(--p, "Symbol not declared: "+pretty_var(next)); // declare all up to this point
                next = next+next_token;
                if(p>=n) return first_token;
                if(next.exists() && test && !internalTypes.contains(next)) imp->error(--p, "Not found: "+pretty_var(next.to_string())+recommend_variable(types, next));
                if(internalTypes.contains(next) && internalTypes.vars[next]->name=="ptr"&& !imp->allow_unsafe) imp->error(--p, "Direct access of `ptr` fields is unsafe.\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
            }
        }
        else if(imp->at(p)=="[") {
            if(!internalTypes.contains(next)) imp->error(--p, "Not found: "+pretty_var(next.to_string())+recommend_variable(types, next));
            if(internalTypes.vars[next]->name!=BUFFER_VAR) {
                ++p;
                Variable arg = parse_expression(i, p, imp->at(p++), types);
                if(!internalTypes.contains(arg)) imp->error(--p, "Not found: "+pretty_var(arg.to_string())+recommend_variable(types, next));
                //if(internalTypes.vars[arg]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(arg)->second->name+" "+pretty_var(arg));
                string end("");
                string method("at");
                if(imp->at(p)=="to") {
                    p++;
                    method = "slice";
                    end = parse_expression(i, p, imp->at(p++), types).to_string();
                    if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                    //if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
                }
                else if(imp->at(p)=="upto") {
                    if(internalTypes.vars[arg]->name!=U64_VAR) imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(arg)->second->name.to_string()+" "+pretty_var(arg.to_string())+"\nYou can only use element access [pos] or non-inclusive `to` ranges [pos to end] for non-u64 pos.");
                    p++;
                    end = parse_expression(i, p, imp->at(p++), types).to_string();
                    if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                    if(internalTypes.vars[end]->name!=U64_VAR) imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name.to_string()+" "+pretty_var(end)+"\nYou can only use `upto` with u64. Move to `to` bounds for other end index runtypes.");
                    method = "slice";
                    string tmp = create_temp();
                    assign_variable(internalTypes.vars[end], tmp, end, imp, p);
                    implementation +=Code(tmp,ASSIGN_VAR,tmp,token_plus_one,SEMICOLON_VAR);
                    end = tmp;
                }
                else if(imp->at(p)=="lento") {
                    if(internalTypes.vars[arg]->name!=U64_VAR) imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(arg)->second->name.to_string()+" "+pretty_var(arg.to_string())+"\nYou can only use element access [pos] or non-inclusive `to` ranges [pos to end] for non-u64 pos.");
                    p++;
                    end = parse_expression(i, p, imp->at(p++), types).to_string();
                    if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                    if(internalTypes.vars[end]->name!=U64_VAR) imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name.to_string()+" "+pretty_var(end)+"\nYou can only use `lento` with u64. Move to `to` bounds for other end index runtypes.");
                    method = "slice";
                    Variable tmp = create_temp();
                    assign_variable(internalTypes.vars[end], tmp, end, imp, p);
                    implementation +=Code(tmp,ASSIGN_VAR,tmp,PLUS_VAR,arg,SEMICOLON_VAR);
                    end = tmp.to_string();
                }
                if(!types.contains(method)) imp->error(--p, "No implementation for "+method);
                Type type = types.vars[method];
                vector<Variable> unpacks;
                if(internalTypes.vars[next]->is_service) imp->error(--p, "Slice overloads cannot be a service");
                if(internalTypes.vars[next]->not_primitive()) for(const Variable& pack : internalTypes.vars[next]->packs) unpacks.push_back(next+pack);
                else unpacks.push_back(next);
                unpacks.push_back(arg);
                if(end.size()) unpacks.push_back(end);
                string inherit_buffer = "";
                next = call_type(i, p, type, unpacks, p-1, method, inherit_buffer, types);
                if(imp->at(p++)!="]") imp->error(--p, "Expecting : or closing square bracket");
                continue;
            }
            //if(internalTypes.vars[next]->name!="buffer") imp->error(--p, "Expected buffer but found: "+internalTypes.vars.find(next)->second->name+" "+pretty_var(next));
            ++p;
            Variable arg = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(arg)) imp->error(--p, "Not found: "+pretty_var(arg.to_string())+recommend_variable(types, next));
            if(internalTypes.vars[arg]->name!=U64_VAR) imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(arg)->second->name.to_string()+" "+pretty_var(arg.to_string())+"\nYou can only use u64 for buffer indexes");
            string end("");
            if(imp->at(p)=="to") {
                p++;
                end = parse_expression(i, p, imp->at(p++), types).to_string();
                if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                //if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
            }
            else if(imp->at(p)=="upto") {
                p++;
                end = parse_expression(i, p, imp->at(p++), types).to_string();
                if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                if(internalTypes.vars[end]->name!=U64_VAR) imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name.to_string()+" "+pretty_var(end)+"\nYou can only use u64 for buffer indexes");
                end += " + 1";
            }
            else if(imp->at(p)=="lento") {
                p++;
                end = parse_expression(i, p, imp->at(p++), types).to_string();
                if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                if(internalTypes.vars[end]->name!=U64_VAR) imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name.to_string()+" "+pretty_var(end)+"\nYou can only use u64 for buffer indexes");
                end += " - "+next.to_string()+"____offset";
            }
            if(imp->at(p++)!="]") imp->error(--p, "Expecting : or closing square bracket");
            Variable prev = next;
            next = create_temp();
            internalTypes.vars[next] = types.vars[BUFFER_VAR]; // field runtypes should not be set here because they are automated and would mess with assign_variable
            Variable actual_size = next+Variable("hidden_size");
            buffer_primitive_associations[next] = buffer_primitive_associations[prev];

            // new size
            if(end.size()) {
                // prepare error position
                string fail_var = create_temp();
                static const Variable token_err = Variable(":\nprintf(\"Runtime error: buffer does not have enough remaining elements\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n");
                errors = errors+Code(fail_var, token_err);
                add_preample("#include <stdio.h>");
                assign_variable(types.vars[U64_VAR], next+Variable("__size"), prev+Variable("__offset + "+end), imp, p, false); // TODO: this is a hack but semantically wrong and may cause issues
                // copy the actual size from the first position of the pointer
                //// vardecl += "u64 "+actual_size+";\n";
                //implementation += "std::memcpy(&" + actual_size + ", (unsigned char*)" + prev + "____contents, sizeof(u64));\n";
                // check if we do not get over actual size (size is the end basically, so practical size is size-start)
                implementation +=Code(token_if, next+Variable("__size"),GT_VAR,prev+Variable("__size"), token_goto, fail_var, SEMICOLON_VAR);
            }
            else assign_variable(types.vars[U64_VAR], next+Variable("__size"), prev+Variable("__size"), imp, p, false);
            assign_variable(types.vars[U64_VAR], next+Variable("__offset"), prev+Variable("__offset + "+arg.to_string()), imp, p, false); // no need for bounds checking here because we are going to later check if non-empty anyway when we pop elements in parse_expression
            assign_variable(types.vars[PTR_VAR], next+Variable("__contents"), prev+Variable("__contents"), imp, p, false);
            assign_variable(types.vars[PTR_VAR], next+Variable("__typetag"), prev+Variable("__typetag"), imp, p, false);

        }
        else break;
    }
    if(next.exists() && test && !internalTypes.contains(next)) imp->error(--p, "Not found: "+pretty_var(next.to_string())+recommend_variable(types, next));
    if(released[next]) imp->error(--p, "Cannot use already released value: "+pretty_var(next.to_string()));
    return next;
}
