string next_var(const shared_ptr<Import>& i, size_t& p, const string& first_token, bool test=true) {
    size_t n = i->size();
    if(p>=n) return first_token;
    string next = first_token;
    while(imp->at(p)==".") {
        //if(!internalTypes.contains(next)) imp->error(--p, "Symbol not declared: "+pretty_var(next)); // declare all up to this point
        next += "__";
        ++p;
        next += imp->at(p++);
        if(p>=n) return first_token;
    }
    if(test && !internalTypes.contains(next)) imp->error(--p, "Symbol not declared: "+pretty_var(next));
    return next;
}

string parse_expression(const shared_ptr<Import>& imp, size_t& p, const string& first_token, Memory& types) {
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
        vardecl += vartype+" "+var+" = "+defval+";\n"; // always set vars to zero because they may reside in if blocks
        implementation += var+" = "+first_token+";\n";
        return var;
    }

    if(internalTypes.contains(first_token)) return next_var(imp, p, first_token);
    if(first_token=="buffer") {
        string var = create_temp();
        preample += "#include<cstdlib>\n";
        if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
        string inherit_buffer("");
        vector<string> unpacks = gather_tuple(imp, p, types, inherit_buffer);
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        vardecl += "u64 "+var+"__size = 0;\n";
        vardecl += "u64 "+var+"__offset = 0;\n";
        vardecl += "ptr "+var+"__contents;\n";
        implementation += var+"__size = "+to_string(unpacks.size())+(inherit_buffer.size()?(" + "+inherit_buffer+"__size"):"")+";\n";
        implementation += var+"__offset = 0;\n";
        implementation += "if("+var+"__size-"+var+"__offset) free("+var+"__contents);\n";
        implementation += var + "__contents = malloc(sizeof(i64)*" + var + "__size);\n";
        for(size_t i = 0; i < unpacks.size(); ++i) implementation += "std::memcpy((unsigned char*)" + var + "__contents + sizeof(i64) * " + to_string(i) + ", &" + unpacks[i] + ", sizeof(i64));\n";
        internalTypes.vars[var] = types.vars.find(first_token)->second;
        internalTypes.vars[var+"__size"] = types.vars["u64"];
        internalTypes.vars[var+"__contents"] = types.vars["ptr"];
        finals += var+"__size = 0;\nfree(" + var + "__contents);\n";
        return next_var(imp, p, var);
    }
    if(types.contains(first_token)) {
        auto type = types.vars.find(first_token)->second;
        if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
        string inherit_buffer("");
        vector<string> unpacks = gather_tuple(imp, p, types, inherit_buffer);
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");

        string overloading_errors = "";
        string var = create_temp();
        while(type) {
            try {
                if(inherit_buffer.size()) {
                    if(unpacks.size()>type->args.size()) throw runtime_error(type->signature()+": Requires "+to_string(type->args.size())+" but found > "+to_string(unpacks.size())+" arguments (buffers unpack at least one value)");
                }
                else if(unpacks.size()!=type->args.size()) throw runtime_error(type->signature()+": Requires "+to_string(type->args.size())+" but found "+to_string(unpacks.size())+" arguments");
                for(size_t i=0;i<unpacks.size();++i) {
                    if(type->args[i].type->not_primitive()) throw runtime_error(type->signature()+": Failed to create builtin for " + type->args[i].type->name + " of "+type->args[i].name);
                    if(!internalTypes.vars.contains(unpacks[i])) throw runtime_error(type->signature()+": No runtype for "+pretty_var(unpacks[i]));
                    if(type->args[i].type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i]))
                        throw std::runtime_error(type->signature()+": Needs " + pretty_var(type->args[i].type->name) + " "+pretty_var(type->name)+"."+ pretty_var(type->args[i].name)+" but found "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
                }
                break;
            }
            catch (const std::runtime_error& e) {
                overloading_errors += "\n";
                overloading_errors += e.what();
                type = type->next_overload_to_try;
            }
        }
        if(!type) imp->error(p-1, "Implementation not found"+overloading_errors);
        internalTypes.vars[var] = type;
        if(inherit_buffer.size()) { // unpack buffer
            string arg = inherit_buffer;
            int remaining = (int)(type->args.size()-unpacks.size());
            string fail_var = create_temp();
            implementation += "if("+arg+"__size-"+arg+"__offset<"+to_string(remaining)+") goto "+fail_var+";\n";
            errors += fail_var+":\nprintf(\"Runtime error: buffer `"+arg+"` does not have enough remaining elements\\n\");\ngoto __return;\n";
            preample += "#include <stdio.h>\n";
            for(int i=0;i<remaining;++i) {
                string cast = type->args[unpacks.size()].type->name; // don't add i because we push back the element
                string element = "__"+arg+"__"+to_string(i);
                if(internalTypes.vars.find(element)==internalTypes.vars.end()) vardecl += cast+" "+element+";\n";
                implementation += "std::memcpy(&" + element + ", (unsigned char*)" + arg + "__contents+sizeof(u64)*("+ to_string(i)+"+"+arg+"__offset), sizeof("+element+"));\n";
                internalTypes.vars[element] = types.vars[cast];
                unpacks.push_back(element);
            }
            implementation += arg+"__offset += "+to_string(remaining)+";\n";
        }
        for(size_t i=0;i<unpacks.size();++i) assign_variable(type->args[i].type, var+"__"+type->args[i].name, unpacks[i], imp, p);


        vardecl += type->rebase(type->vardecl, var, internalTypes, false);
        implementation += type->rebase(type->implementation, var, internalTypes);
        preample += type->rebase(type->preample, var, internalTypes);
        finals = type->rebase(type->finals, var, internalTypes)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
        errors = errors+type->rebase(type->errors, var, internalTypes);

        string finally = "";
        if(type->packs.size()==1 && type->packs[0]=="@scope") {
            auto def = make_shared<Def>();
            def->name = "parsed expression";
            def->internalTypes.vars["__finally"] = types.vars["__label"];
            //def->internalTypes.vars["start"] = types.vars["__label"];
            for(const auto& it : internalTypes.vars) def->internalTypes.vars[it.first] = it.second;
            def->parse(imp, p, types, false); // this consumes until return
            p++;

            vardecl += def->rebase(def->vardecl, var, internalTypes, false);
            implementation += def->rebase(def->implementation, var, internalTypes);
            preample += def->rebase(def->preample, var, internalTypes);
            finals = def->rebase(def->finals, var, internalTypes)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
            errors = errors+def->rebase(def->errors, var, internalTypes);
            for(const auto& it : def->internalTypes.vars) internalTypes.vars[var+"__"+it.first] = it.second;
            internalTypes.vars[var+"____finally"] = types.vars.find("__label")->second;
            //internalTypes.vars[var+"__start"] = types.vars["__label"];
            implementation = var+"__start:\n"+implementation+var+"____finally:\n";

            // we can now discard implementations for efficiency because we will never use them again
            def->implementation = "";
            def->preample = "";
            def->finals = "";
            def->errors = "";
            def ->vardecl = "";
            internalTypes.vars[var] = def;
        }

        for(const auto& it : type->internalTypes.vars) internalTypes.vars[var+"__"+it.first] = it.second;
        if(type->packs.size()==1) {
            if(type->packs[0]=="@scope") {
                //return ""; // TODO: improve to allow return from ifs
                type = internalTypes.vars[var]; // guaranteed to exist
                if(type->packs.size()==1) return var+"__"+type->packs[0];
                //for(const string& pack : type->packs) assign_variable(type->internalTypes.vars[pack], var+"__"+pack, pack, imp, p);
                return next_var(imp, p, var);
            }
            return next_var(imp, p, var+"__"+type->packs[0]);
        }
        return next_var(imp, p, var);
    }

    string var = next_var(imp, p, first_token);
    //if(types.vars.find(var)!=types.end() && (p>=imp->size()-1 || imp->at(p+1)=="(")
    if(internalTypes.contains(var)) return var;
    return next_var(imp, p, var);
}
