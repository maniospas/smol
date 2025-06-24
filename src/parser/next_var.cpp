#include "../def.h"

string Def::next_var(const shared_ptr<Import>& i, size_t& p, const string& first_token, Types& types, bool test) {
    if(first_token.size()==0) return "";
    size_t n = i->size();
    if(p>=n) return first_token;
    string next = first_token;
    while(true) {
        if(p>=n) break;
        if(imp->at(p)==":") {
            ++p;
            next = parse_expression(i, p, imp->at(p++), types, next);
        }
        else if(imp->at(p)=="and") {
            if(!internalTypes.contains(next)) imp->error(--p, "Unknown symbol "+pretty_var(next));
            if(internalTypes.vars[next]!=types.vars["bool"]) imp->error(--p, "Left hand side of `and` expected bool but got "+internalTypes.vars[next]->name+" "+pretty_var(next));
            ++p;
            string prev = next;
            string tmp = create_temp();
            implementation += "if(!"+next+")"+" goto "+tmp+";\n";
            next = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(next)) imp->error(--p, "Unknown symbol "+pretty_var(next));
            if(internalTypes.vars[next]!=types.vars["bool"]) imp->error(--p, "Right hand side of `and` expected bool but got "+internalTypes.vars[next]->name+" "+pretty_var(next));
            implementation += prev+"="+next+";\n";
            implementation += tmp+":\n";
            next = prev;
        }
        else if(imp->at(p)=="or") {
            if(!internalTypes.contains(next)) imp->error(--p, "Unknown symbol "+pretty_var(next));
            if(internalTypes.vars[next]!=types.vars["bool"]) imp->error(--p, "Left hand side of `or` expected bool but got "+internalTypes.vars[next]->name+" "+pretty_var(next));
            ++p;
            string prev = next;
            string tmp = create_temp();
            implementation += "if("+next+")"+" goto "+tmp+";\n";
            next = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(next)) imp->error(--p, "Unknown symbol "+pretty_var(next));
            if(internalTypes.vars[next]!=types.vars["bool"]) imp->error(--p, "Right hand side of `or` expected bool but got "+internalTypes.vars[next]->name+" "+pretty_var(next));
            implementation += prev+"="+next+";\n";
            implementation += tmp+":\n";
            next = prev;
        }
        else if(imp->at(p)==".") {
            ++p;
            const string& next_token = imp->at(p++);
            if(next.size() && internalTypes.contains(next) && internalTypes.vars[next]->retrievable_parameters.find(next_token)!=internalTypes.vars[next]->retrievable_parameters.end()) {
                Type prevType = internalTypes.vars[next];
                if(prevType->options.size()==1) prevType = *prevType->options.begin();
                if(prevType->lazy_compile) {
                    if(parametric_types.find(next)==parametric_types.end()) imp->error(--p, "Internal error: has no compiled lazy type "+prevType->signature(types));
                    prevType = parametric_types[next];
                }
                Type type = prevType->retrievable_parameters[next_token];
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
                next += "__"+next_token;
                if(p>=n) return first_token;
                if(next.size() && test && !internalTypes.contains(next)) imp->error(--p, "Not found: "+pretty_var(next)+recommend_variable(types, next));
            }
        }
        else if(imp->at(p)=="[") {
            if(!internalTypes.contains(next)) imp->error(--p, "Not found: "+pretty_var(next)+recommend_variable(types, next));
            if(internalTypes.vars[next]->name!="buffer") {
                ++p;
                string arg = parse_expression(i, p, imp->at(p++), types);
                if(!internalTypes.contains(arg)) imp->error(--p, "Not found: "+pretty_var(arg)+recommend_variable(types, next));
                if(internalTypes.vars[arg]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(arg)->second->name+" "+pretty_var(arg));
                string end("");
                string method("at");
                if(imp->at(p)=="to") {
                    p++;
                    method = "slice";
                    end = parse_expression(i, p, imp->at(p++), types);
                    if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                    if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
                }
                else if(imp->at(p)=="upto") {
                    p++;
                    end = parse_expression(i, p, imp->at(p++), types);
                    if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                    if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
                    method = "slice";
                    string tmp = create_temp();
                    assign_variable(internalTypes.vars[end], tmp, end, imp, p);
                    implementation += tmp+" = "+tmp+" + 1;\n";
                    end = tmp;
                }
                else if(imp->at(p)=="lento") {
                    p++;
                    end = parse_expression(i, p, imp->at(p++), types);
                    if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                    if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
                    method = "slice";
                    string tmp = create_temp();
                    assign_variable(internalTypes.vars[end], tmp, end, imp, p);
                    implementation += tmp+" = "+tmp+" + "+arg+";\n";
                    end = tmp;
                }
                if(!types.contains(method)) imp->error(--p, "No implementation for "+method);
                Type type = types.vars[method];
                vector<string> unpacks;
                if(internalTypes.vars[next]->is_service) imp->error(--p, "Slicing notation cannot be a service\nIt mus be allowed to be overloaded by various symbols");
                if(internalTypes.vars[next]->not_primitive()) for(const string& pack : internalTypes.vars[next]->packs) unpacks.push_back(next+"__"+pack);
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
            string arg = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(arg)) imp->error(--p, "Not found: "+pretty_var(arg)+recommend_variable(types, next));
            if(internalTypes.vars[arg]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(arg)->second->name+" "+pretty_var(arg));
            string end("");
            if(imp->at(p)=="to") {
                p++;
                end = parse_expression(i, p, imp->at(p++), types);
                if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
            }
            else if(imp->at(p)=="upto") {
                p++;
                end = parse_expression(i, p, imp->at(p++), types);
                if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
                end += " + 1";
            }
            else if(imp->at(p)=="lento") {
                p++;
                end = parse_expression(i, p, imp->at(p++), types);
                if(!internalTypes.contains(end)) imp->error(--p, "Not found: "+pretty_var(end)+recommend_variable(types, next));
                if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
                end += " - "+next+"____offset";
            }
            if(imp->at(p++)!="]") imp->error(--p, "Expecting : or closing square bracket");
            string prev = next;
            next = create_temp();
            internalTypes.vars[next] = types.vars["buffer"]; // field runtypes should not be set here because they are automated and would mess with assign_variable
            string actual_size = next+"__hidden_size";
            buffer_primitive_associations[next] = buffer_primitive_associations[prev];

            // new size
            if(end.size()) {
                // prepare error position
                string fail_var = create_temp();
                errors += fail_var+":\nprintf(\"Runtime error: buffer does not have enough remaining elements\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
                add_preample("#include <stdio.h>");

                assign_variable(types.vars["u64"], next+"____size", prev+"____offset + "+end, imp, p, false);
                // copy the actual size from the first position of the pointer
                //// vardecl += "u64 "+actual_size+";\n";
                //implementation += "std::memcpy(&" + actual_size + ", (unsigned char*)" + prev + "____contents, sizeof(u64));\n";
                // check if we do not get over actual size (size is the end basically, so practical size is size-start)
                implementation += "if("+next+"____size>"+prev+"____size) goto "+fail_var+";\n";
            }
            else assign_variable(types.vars["u64"], next+"____size", prev+"____size", imp, p, false);
            assign_variable(types.vars["u64"], next+"____offset", prev+"____offset + "+arg, imp, p, false); // no need for bounds checking here because we are going to later check if non-empty anyway when we pop elements in parse_expression
            assign_variable(types.vars["ptr"], next+"____contents", prev+"____contents", imp, p, false);
            assign_variable(types.vars["ptr"], next+"____typetag", prev+"____typetag", imp, p, false);

        }
        else break;
    }
    if(next.size() && test && !internalTypes.contains(next)) imp->error(--p, "Not found: "+pretty_var(next)+recommend_variable(types, next));
    return next;
}
