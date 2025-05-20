string Def::next_var(const shared_ptr<Import>& i, size_t& p, const string& first_token, Memory& types, bool test) {
    size_t n = i->size();
    if(p>=n) return first_token;
    string next = first_token;
    while(true) {
        if(p>=n) break;
        if(imp->at(p)==":") {
            ++p;
            next = parse_expression(i, p, imp->at(p++), types, next);
        }
        else if(imp->at(p)==".") {
            //if(!internalTypes.contains(next)) imp->error(--p, "Symbol not declared: "+pretty_var(next)); // declare all up to this point
            next += "__";
            ++p;
            next += imp->at(p++);
            if(p>=n) return first_token;
        }
        else if(imp->at(p)=="[") {
            if(!internalTypes.contains(next)) imp->error(--p, "Missing symbol: "+pretty_var(next)+recommend_variable(types, next));
            if(internalTypes.vars.find(next)->second->name!="buffer") imp->error(--p, "Expected buffer but found: "+internalTypes.vars.find(next)->second->name+" "+pretty_var(next));
            ++p;
            string arg = parse_expression(i, p, imp->at(p++), types);
            if(!internalTypes.contains(arg)) imp->error(--p, "Missing symbol: "+pretty_var(arg)+recommend_variable(types, next));
            if(internalTypes.vars[arg]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(arg)->second->name+" "+pretty_var(arg));
            string end("");
            if(imp->at(p)=="to") {
                p++;
                end = parse_expression(i, p, imp->at(p++), types);
                if(!internalTypes.contains(end)) imp->error(--p, "Missing symbol: "+pretty_var(end)+recommend_variable(types, next));
                if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
            }
            else if(imp->at(p)=="upto") {
                p++;
                end = parse_expression(i, p, imp->at(p++), types);
                if(!internalTypes.contains(end)) imp->error(--p, "Missing symbol: "+pretty_var(end)+recommend_variable(types, next));
                if(internalTypes.vars[end]->name!="u64") imp->error(--p, "Expected u64 but found: "+internalTypes.vars.find(end)->second->name+" "+pretty_var(end));
                end += " + 1";
            }
            else if(imp->at(p)=="lento") {
                p++;
                end = parse_expression(i, p, imp->at(p++), types);
                if(!internalTypes.contains(end)) imp->error(--p, "Missing symbol: "+pretty_var(end)+recommend_variable(types, next));
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
                errors += fail_var+":\nprintf(\"Runtime error: buffer `"+arg+"` does not have enough remaining elements\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
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
    if(test && !internalTypes.contains(next)) imp->error(--p, "Symbol not declared: "+pretty_var(next)+recommend_variable(types, next));
    return next;
}
