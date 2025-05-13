string parse_expression(const shared_ptr<Import>& imp, size_t& p, const string& first_token, Memory& types, string curry="") {
    if(first_token=="(") {
        string ret = parse_expression(imp, p, imp->at(p++), types, curry);
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        return ret;
    }
    return parse_expression_no_par(imp, p, first_token, types, curry);
}

string parse_expression_no_par(const shared_ptr<Import>& imp, size_t& p, const string& first_token, Memory& types, string curry="") {
    size_t first_token_pos = p-1;
    if(first_token=="." || first_token==":" || first_token=="[" || first_token=="]" || first_token=="{" || first_token=="}" || first_token==";"|| first_token=="&") imp->error(p-1, "Unexpected symbol\nThe previous expression already ended.");
    if(is_primitive(first_token)) {
        string vartype = type_primitive(first_token);
        string defval = "0";
        if(p<imp->size() && imp->at(p)=="@" && imp->at(p+1)=="else") {
            defval = imp->at(p+2);
            p += 3;
            if(type_primitive(defval)!=vartype) imp->error(p-1, "Required "+vartype+" primitive");
        }
        string var = create_temp();
        if(types.vars.find(vartype)==types.vars.end()) return first_token;// fallback
        internalTypes.vars[var] = types.vars.find(vartype)->second;
        // vardecl += vartype+" "+var+" = "+defval+";\n"; // always set vars to zero because they may reside in if blocks
        implementation += var+" = "+first_token+";\n";
        return next_var(imp, p, var, types);
    }
    if(first_token == "len" && curry.size() && internalTypes.contains(curry) && internalTypes.vars[curry]->name=="buffer") {
        string var = create_temp();
        implementation += var + " = " + curry+"____size-"+curry+"____offset;\n"; 
        internalTypes.vars[var] = types.vars["u64"];
        return next_var(imp, p, var, types);
    }
    if(first_token == "put" && curry.size() && internalTypes.contains(curry) && internalTypes.vars[curry]->name=="buffer") {
        string arg = curry;
        if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
        string inherit_buffer("");
        vector<string> unpacks = gather_tuple(imp, p, types, inherit_buffer, "");
        if(inherit_buffer.size()) imp->error(--p, "Cannot unpack from a buffer to put elements in a buffer");
        int remaining = unpacks.size();
        if(!remaining) imp->error(--p, "Need to set at least one element to the buffer");
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        string fail_var = create_temp();
        string fail_var_type = create_temp();
        if(remaining==1) implementation += "if("+arg+"____size<="+arg+"____offset) goto "+fail_var+";\n";
        else implementation += "if("+arg+"____size<"+arg+"____offset+"+to_string(remaining)+") goto "+fail_var+";\n";
        errors += fail_var+":\nprintf(\"Runtime error: buffer is empty\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
        errors += fail_var_type+":\nprintf(\"Runtime error: buffer element would replace a different type\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
        preample += "#include <stdio.h>\n";
        string tmp = create_temp();
        for(int i=0;i<remaining;++i) {
            Type desiredType = internalTypes.vars[unpacks[i]];
            bool typecheck = !buffer_primitive_associations[arg];
            if(!typecheck && desiredType!=buffer_primitive_associations[arg]) imp->error(p-2, "Buffer contains only "+buffer_primitive_associations[arg]->name+" primitives but tried to replace one with "+desiredType->name);
            string element = "__"+tmp+"__"+to_string(i);
            if(typecheck) {
                internalTypes.vars[element+"t"] = types.vars["u64"];
                implementation += element+"t = ((u64*)"+arg+"____typetag)[("+ to_string(i)+"+"+arg+"____offset)/16];\n";
                string pos = "((("+ to_string(i)+"+"+arg+"____offset)%16)*4)";
                implementation += "if((("+element+"t>>"+pos+")& 0xF)!=__IS_"+desiredType->name+") goto "+fail_var_type+";\n";
            }
            //if(desiredType->name=="i64" || desiredType->name=="f64" || desiredType->name=="ptr" || desiredType->name=="cstr") implementation += "((u64*)" + arg + "____contents)["+ to_string(i)+"+"+arg+"____offset] = std::bit_cast<u64>("+unpacks[i]+");\n";
            implementation += "std::memcpy((unsigned char*)" + arg + "____contents+sizeof(u64)*("+ to_string(i)+"+"+arg+"____offset), &"+unpacks[i]+", sizeof("+unpacks[i]+"));\n";
        }
        implementation += arg+"____offset += "+to_string(remaining)+";\n";
        return arg;
    }
    if(internalTypes.contains(first_token)) {
        if(curry.size()) imp->error(p, "Expecting runtype (not variable): "+first_token);
        return next_var(imp, p, first_token, types); //ASSIGNMENT TO ALREADY EXISTING VARIABLE
    }
    if(first_token=="buffer") {
        string var = create_temp();
        preample += "#include<cstdlib>\n";
        if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
        string inherit_buffer("");
        vector<string> unpacks = gather_tuple(imp, p, types, inherit_buffer, curry);
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        // vardecl += "u64 "+var+"____size = 0;\n";
        // vardecl += "u64 "+var+"____offset = 0;\n";
        // vardecl += "ptr "+var+"____contents;\n";
        implementation += "if("+var+"____size-"+var+"____offset) free("+var+"____contents);\n";
        implementation += var+"____size = "+to_string(unpacks.size())+(inherit_buffer.size()?(" + "+inherit_buffer+"____size"):"")+";\n";
        implementation += var+"____offset = 0;\n";
        implementation += var + "____contents = malloc(sizeof(i64)*" + var + "____size);\n";
        implementation += var + "____typetag = calloc(" + var + "____size/16+1, sizeof(u64));\n";
        //implementation += "std::memcpy((unsigned char*)" + var + "____contents, &" + var + "____size, sizeof(u64));\n";
        if(unpacks.size()) buffer_primitive_associations[var] = internalTypes.vars[unpacks[0]];
        for(size_t i = 0; i < unpacks.size(); ++i) {
            if(buffer_primitive_associations[var]!=internalTypes.vars[unpacks[i]]) buffer_primitive_associations[var] = nullptr;
            //if(buffer_primitive_associations[var]) 
            // for now it's mandatory to set the type because we might lose the primitive association in the future - the optimizer may just remove if if unused though
            implementation += "((u64*)" + var + "____typetag)["+to_string(i/16)+"] |= ((u64)__IS_"+internalTypes.vars[unpacks[i]]->name+")<<"+to_string((i%16)*4)+";\n";
            implementation += "std::memcpy((unsigned char*)" + var + "____contents + sizeof(u64) * " + to_string(i) + ", &" + unpacks[i] + ", sizeof("+unpacks[i]+"));\n";
        }
        internalTypes.vars[var] = types.vars.find(first_token)->second;
        internalTypes.vars[var+"____size"] = types.vars["u64"];
        internalTypes.vars[var+"____offset"] = types.vars["u64"];
        internalTypes.vars[var+"____contents"] = types.vars["ptr"];
        internalTypes.vars[var+"____typetag"] = types.vars["ptr"];
        finals[var+"____contents"] += "if("+var+"____contents) free(" + var + "____contents);\n"+var+"____contents = 0;\n";
        finals[var+"____typetag"] += "if("+var+"____typetag) free(" + var + "____typetag);\n"+var+"____typetag = 0;\n";
        return next_var(imp, p, var, types);
    }
    if(types.contains(first_token)) {
        auto type = types.vars.find(first_token)->second;
        string inherit_buffer("");
        vector<string> unpacks;
        if(imp->at(p)=="__consume") {
            if(!curry.size()) imp->error(p-2, "Unexpected usage of operator\nThere is no left-hand-side");
            if(internalTypes.contains(curry) && internalTypes.vars.find(curry)->second==types.vars["buffer"]) imp->error(p-2, "Operator does not accept buffer as the first input");
            else {
                if(internalTypes.contains(curry) && internalTypes.vars.find(curry)->second->not_primitive()) {
                    for(const string& pack : internalTypes.vars.find(curry)->second->packs)  unpacks.push_back(curry+"__"+pack);
                }
                else unpacks.push_back(curry);
            }
            p++;
            string next = imp->at(p++);
            string rhs = parse_expression(imp, p, next, types);
            if(!internalTypes.contains(rhs)) imp->error(--p, "Failed to parse the right-hand-side of "+first_token);
            const auto& rhsType = internalTypes.vars.find(rhs)->second;
            if(rhsType->name=="buffer") imp->error(--p, "Cannot involve a buffer in operation "+first_token);
            if(rhsType->_is_primitive) unpacks.push_back(rhs);
            else if(type->is_service) {
                string fail_var = create_temp();
                implementation += "if("+rhs+"__err) goto "+fail_var+";\n";
                errors += fail_var+":\nprintf(\"Runtime error from "+rhsType->name+" "+pretty_var(rhs)+"\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n";
                preample += "#include <stdio.h>\n";
                for(size_t i=1;i<rhsType->packs.size();++i) unpacks.push_back(rhs+"__"+rhsType->packs[i]);
            }
            else for(const string& pack : rhsType->packs) unpacks.push_back(rhs+"__"+pack);
        }
        else if(imp->at(p)!="(" && curry.size()) {
            if(internalTypes.contains(curry) && internalTypes.vars.find(curry)->second==types.vars["buffer"]) inherit_buffer = curry;
            else if(internalTypes.contains(curry) && internalTypes.vars.find(curry)->second->not_primitive()) {
                for(const string& pack : internalTypes.vars.find(curry)->second->packs) unpacks.push_back(curry+"__"+pack);
            }
            else unpacks.push_back(curry);
        }
        else if(imp->at(p)==")" || imp->at(p)=="]" || imp->at(p)=="," || imp->at(p)==":") {
            int num_choices = 0;
            int highest_choice_power = 0;
            string candidates("");
            if(type->options.size()==1) {type = type->options[0];num_choices=1;}
            else for(const auto& option : type->options) {
                if(option->choice_power>highest_choice_power) {
                    highest_choice_power = option->choice_power;
                    num_choices = 0;
                    candidates = "";
                }
                if(option->choice_power<highest_choice_power) continue;
                num_choices ++;
                type = option;
                candidates += "\n"+option->signature();
            }
            if(num_choices!=1) imp->error(--p, "Overloaded or union runtype names are ambiguous.\nConsider defining exactly one of them with ->@new return\nto break the priority stalemate.\nCandidates:"+candidates);
            if(type->not_primitive()) for(size_t i=0;i<type->args.size();++i) {
                string var = create_temp();
                assign_variable(type->args[i].type, var, "0", imp, p, true);
                unpacks.push_back(var);
            }
            else {
                string var = create_temp();
                assign_variable(type, var, "0", imp, p, true);
                unpacks.push_back(var);
            }
        }
        else {
            if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
            unpacks = gather_tuple(imp, p, types, inherit_buffer, curry);
            if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        }

        string overloading_errors("");
        string var = create_temp();
        Type successfullType = nullptr;
        string multipleFound("");
        int numberOfFound = 0;
        int numberOfErrors = 0;
        Type previousType = type;
        int highest_choice_power = 0;
        for(size_t i=0;i<unpacks.size();++i) 
            if(!internalTypes.vars.contains(unpacks[i])) 
                imp->error(p-3, "Missing symbol: "+pretty_var(unpacks[i])+recommend_variable(types, unpacks[i]));

        for(const Type& type : previousType->get_options(imp, types)) { // options encompases all overloads, in case of unions it may not have the base overload
            try {
                //if(type->lazy_compile) throw runtime_error("Failed to resolve parametric type: "+type->signature());//+"\nParameters need to be determined by arguments");
                size_t type_args = type->not_primitive()?type->args.size():1;
                if(inherit_buffer.size()) {
                    if(unpacks.size()>type_args) throw runtime_error(type->signature()+": Requires "+to_string(type_args)+" but got > "+to_string(unpacks.size())+" arguments (buffers unpack at least one value)");
                }
                else if(unpacks.size()!=type_args) throw runtime_error(type->signature()+": Requires "+to_string(type_args)+" but got "+to_string(unpacks.size())+" arguments");
                for(size_t i=0;i<unpacks.size();++i) {
                    auto arg_type = type->_is_primitive?type:type->args[i].type;
                    if(type->not_primitive() && arg_type->not_primitive()) throw runtime_error(type->signature()+": Cannot unpack abstract " + arg_type->signature() + " "+type->args[i].name);
                    if(!internalTypes.vars.contains(unpacks[i])) throw runtime_error(type->signature()+": No runtype for "+pretty_var(unpacks[i]));
                    if(type->not_primitive() && arg_type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i]))
                        throw std::runtime_error(type->signature()+": Expecting " + arg_type->name + " "+pretty_var(type->name)+"."+ pretty_var(type->args[i].name)+" but got "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
                }
                if(type->choice_power>highest_choice_power) {
                    highest_choice_power = type->choice_power;
                    numberOfFound = 0;
                    multipleFound = "";
                }
                if(type->choice_power<highest_choice_power) continue;
                successfullType = type;
                multipleFound += "\n- "+type->signature();
                numberOfFound++;
            }
            catch (const std::runtime_error& e) {
                overloading_errors += "\n- ";
                overloading_errors += e.what();
                numberOfErrors++;
            }
        }
        type = successfullType;
        if(!type && numberOfErrors) imp->error(first_token_pos, "Runtype not found among "+to_string(numberOfErrors)+" candidates"+overloading_errors);
        if(!type) imp->error(first_token_pos, "Runtype not found: "+first_token+recommend_runtype(types, first_token));
        if(numberOfFound>1) imp->error(first_token_pos, "Ambiguous use of "+to_string(numberOfFound)+" acceptable runtypes"+multipleFound);
        if(inherit_buffer.size()) { // unpack buffer
            string arg = inherit_buffer;
            int remaining = (int)(type->args.size()-unpacks.size());
            if(type->_is_primitive) remaining++;
            string fail_var = create_temp();
            string fail_var_type = create_temp();
            if(remaining==1) implementation += "if("+arg+"____size<="+arg+"____offset) goto "+fail_var+";\n";
            else implementation += "if("+arg+"____size<"+arg+"____offset+"+to_string(remaining)+") goto "+fail_var+";\n";
            errors += fail_var+":\nprintf(\"Runtime error: buffer is empty\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
            errors += fail_var_type+":\nprintf(\"Runtime error: buffer element has the wrong type\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n";
            preample += "#include <stdio.h>\n";
            string tmp = create_temp();
            for(int i=0;i<remaining;++i) {
                Type desiredType = type->_is_primitive?type:type->args[unpacks.size()].type;// don't add i because we push back the element
                bool typecheck = !buffer_primitive_associations[inherit_buffer];//desiredType!=buffer_primitive_associations[inherit_buffer];
                if(!typecheck && desiredType!=buffer_primitive_associations[inherit_buffer]) imp->error(--p, "Buffer contains only "+buffer_primitive_associations[inherit_buffer]->name+" primitives but tried to extract "+desiredType->name);
                string element = "__"+tmp+"__"+to_string(i);
                if(typecheck) {
                    internalTypes.vars[element+"t"] = types.vars["u64"];
                    implementation += element+"t = ((u64*)"+arg+"____typetag)[("+ to_string(i)+"+"+arg+"____offset)/16];\n";
                    string pos = "((("+ to_string(i)+"+"+arg+"____offset)%16)*4)";
                    implementation += "if((("+element+"t>>"+pos+")& 0xF)!=__IS_"+desiredType->name+") goto "+fail_var_type+";\n";
                }
                implementation += "std::memcpy(&" + element + ", (unsigned char*)" + arg + "____contents+sizeof(u64)*("+ to_string(i)+"+"+arg+"____offset), sizeof("+element+"));\n";
                internalTypes.vars[element] = desiredType;
                unpacks.push_back(element);
            }
            implementation += arg+"____offset += "+to_string(remaining)+";\n";
        }
        if(type->is_service) {
            var = create_temp();
            // vardecl += "errcode "+var+"__err = 0;\n";
            string impl = var+"__err = "+type->name+"(";
            internalTypes.vars[var+"__err"] = types.vars["errcode"];
            internalTypes.vars[var] = type;
            bool toadd = false;
            for(size_t i=1;i<type->packs.size();++i) { // first service output is the error code, which we return instead of parsing by reference
                const string& ret = type->packs[i];
                assign_variable(type->internalTypes.vars[ret], var+"__"+ret, "0", imp, p);
                if(toadd) impl += ",";
                impl += var+"__"+ret;
                toadd = true;
                type->coallesce_finals(ret);
                finals[var+"__"+ret] += type->rebase(type->finals[ret], var);
                if(type->internalTypes.vars[ret]->name=="buffer") buffer_primitive_associations[var+"__"+ret] = type->buffer_primitive_associations[ret];
            }
            for(size_t i=0;i<unpacks.size();++i) {
                if(toadd) impl += ",";
                impl += unpacks[i];
                toadd = true;
                if(type->args[i].mut) {
                    string ret = unpacks[i];
                    type->coallesce_finals(type->args[i].name);
                    finals[unpacks[i]] += type->rename_var(type->finals[type->args[i].name], type->args[i].name, unpacks[i]);
                    if(type->internalTypes.vars[ret]->name=="buffer") buffer_primitive_associations[unpacks[i]] = type->buffer_primitive_associations[type->args[i].name];
                }
            }
            impl += ");\n";
            implementation += impl;
            finals[var] = type->rebase(type->finals_when_used, var);
            internalTypes.vars[var] = type->alias_for.size()?type->internalTypes.vars[type->alias_for]:type;
            if(internalTypes.vars[var]->name=="buffer") buffer_primitive_associations[var] = type->buffer_primitive_associations[type->alias_for];
            return next_var(imp, p, var, types);
        }
        if(type->_is_primitive) {
            if(unpacks.size()!=1) imp->error(--p, "Primitive types only accept one argument");
            assign_variable(type, var, unpacks[0], imp, p);
            return next_var(imp, p, var, types);
        }
        string immediate_finals("");
        for(size_t i=0;i<unpacks.size();++i) {
            assign_variable(type->args[i].type, var+"__"+type->args[i].name, unpacks[i], imp, p);
            if(type->args[i].mut) {
                immediate_finals += unpacks[i]+ " = "+var+"__"+type->args[i].name+";\n";
                current_renaming[unpacks[i]] = var+"__"+type->args[i].name;
                buffer_primitive_associations[unpacks[i]] = type->buffer_primitive_associations[var+"__"+type->args[i].name];
            }
        }
        internalTypes.vars[var] = type->alias_for.size()?type->internalTypes.vars[type->alias_for]:type;
        implementation += type->rebase(type->implementation, var);
        preample += type->rebase(type->preample, var);
        for(const auto& final : type->finals) finals[var+"__"+final.first] += type->rebase(final.second, var); 
        //finals = type->rebase(type->finals, var)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
        errors = errors+type->rebase(type->errors, var);
        for(const auto& it : type->current_renaming) current_renaming[var+"__"+it.first] = var+"__"+it.second; 
        for(const auto& it : type->internalTypes.vars) {
            internalTypes.vars[var+"__"+it.first] = it.second;
            if(it.second->name=="buffer") buffer_primitive_associations[var+"__"+it.first] = type->buffer_primitive_associations[it.first];
        }
        finals[""] += immediate_finals; // TODO maybe it's a good idea to have some deallocations at the end of runtype implementations
        finals[var] = type->rebase(type->finals_when_used, var);
        if(internalTypes.vars[var]->name=="buffer") buffer_primitive_associations[var] = type->buffer_primitive_associations[type->alias_for];
        if(type->packs.size()==1) return next_var(imp, p, var+"__"+type->packs[0], types);
        return next_var(imp, p, var, types);
    }
    if(curry.size() || (p<imp->size() && (imp->at(p)=="(" || imp->at(p)=="__consume"))) imp->error(--p, "Missing runtype: "+first_token+recommend_runtype(types, first_token));
    return next_var(imp, p, first_token, types);
}
