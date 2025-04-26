void parse(const shared_ptr<Import>& i, size_t& p, Memory& types, bool with_signature=true) {
    pos = p;
    imp = i;
    if(with_signature) {
        if(imp->at(p++)!="smo") imp->error(--p, "Missing `smo`");
        name = imp->at(p++);
        if(imp->at(p++)!="(") imp->error(--p, "Missing left parenthesis");
        while(true) {
            string next = imp->at(p++);
            if(next==")") break;
            if(args.size()) {
                if(next!=",")imp->error(--p, "Expecting comma between arguments");
                next = imp->at(p++);
            }
            if(!accepted_var_name(next)) imp->error(--p, "Expecting type declaration but this is not a valid type name");
            if(types.vars.find(next)==types.vars.end()) imp->error(--p, "Type name not visible");
            string arg_name = imp->at(p++);
            if(!accepted_var_name(arg_name)) imp->error(--p, "Expecting variable name");
            Type argType = types.vars.find(next)->second;
            if(argType->next_overload_to_try) imp->error(p-2, "Overloaded names are ambiguous arguments");

            if(argType->args.size()) {
                internalTypes.vars[arg_name] = argType;
                for(const auto& it : argType->args) {
                    args.emplace_back(arg_name+"__"+it.name, it.type);
                    internalTypes.vars[arg_name+"__"+it.name] = it.type;
                    vardecl += it.type->rebase(it.type->vardecl, arg_name);
                    implementation += it.type->rebase(it.type->implementation, arg_name);
                    preample += it.type->rebase(it.type->preample, arg_name);
                    finals = it.type->rebase(it.type->finals, arg_name)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
                    errors = errors+it.type->rebase(it.type->errors, arg_name);
                    for(const auto& it : it.type->internalTypes.vars) internalTypes.vars[arg_name+"__"+it.first] = it.second;
                }
            }
            else {
                args.emplace_back(arg_name, argType);
                internalTypes.vars[arg_name] = argType;
            }
            if(p>=imp->size()) imp->error(pos+2, "Missing matching right parenthesis");
        }
    }
    start = p;
    while(p<imp->size()) {
        string next = imp->at(p++);
        // custom behavior
        if(next=="@") {
            parse_directive(imp, p, next, types);
            continue;
        }
        // return statement
        if(next=="-") {
            if(imp->at(p)=="-") {
                end = p;
                break;
            }
            if(imp->at(p++)!=">") imp->error(p-2, "Expecting `->` to return a value or `--` to return without a value for expressions starting with `-`");
            next = imp->at(p++);
            if(next=="@") {
                next = imp->at(p++);
                if(next == "scope") {
                    packs.push_back("@scope");
                }
                else {
                    if(next!="new") imp->error(--p, "Only allowed special command here is`->@new` or `->@scope`");
                    for(const auto& arg : args) packs.push_back(arg.name);
                }
            }
            else if(next!="(") {
                next = parse_expression(imp, p, next, types);
                if(!is_primitive(next) && internalTypes.vars[next]->args.size()) {
                    if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared (error during return)");
                    auto oneType = internalTypes.vars[next];
                    if(oneType->packs.size()!=1) imp->error(--p, "Can only convert a primitive result to a primitive");
                    next = next+"__"+oneType->packs[0];
                }
                packs.push_back(next);
            }
            else { // we are starting parenthesis
                while(true) {
                    next = parse_expression(imp, p, imp->at(p++), types);
                    if(!is_primitive(next) && internalTypes.vars[next]->args.size()) {
                        if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared (error during return)");
                        auto oneType = internalTypes.vars[next];
                        if(oneType->packs.size()!=1) imp->error(--p, "Can only convert a primitive result to a primitive");
                        next = next+"__"+oneType->packs[0];
                    }
                    packs.push_back(next);
                    next = imp->at(p++);
                    if(next==")") break;
                    if(next!=",") imp->error(--p, "Comma expected (not implemented expression in return statements yet)");
                }
            }
            --p;
            end = p;
            break;
        }

        string assignTo("");
        Type assignType(nullptr);

        string var = imp->at(p++);
        Type type;
        if(var=="." || var=="=") {
            p--;
            var = next_var(imp, p, next, false);
            if(internalTypes.vars.find(var)!=internalTypes.vars.end()) assignType = internalTypes.vars.find(var)->second;
            next = imp->at(p++);
            if(next!="=") imp->error(--p, "Assign to this variable per: `"+var+" = ...`");
            assignTo = var;
            next = imp->at(p++);
            if(is_primitive(next)) {
                // direct assignment of primitive to value
                assignTo = var;
                var = next;
                next = type_primitive(next);
                if(types.vars.find(next)==types.vars.end()) imp->error(--p, "Internal error: implicit type is not a `smo` definition");
                type = types.vars.find(next)->second;
                if(type->args.size()) imp->error(--p, "Type not declared");
                if(assignType){
                    if(assignType->args.size()==0 && assignType!=type) imp->error(p-2, "You are trying to overwrite "+assignType->name+" "+assignTo+" with an incompatible `smo` type");
                    if(assignType->packs.size()>1) imp->error(p-2, "Cannot unpack to a builting a type with more than one values");
                    if(assignType->packs.size()) {
                        var += "__"+assignType->packs[0];
                        if(internalTypes.vars.find(var)==internalTypes.vars.end()) imp->error(p-2, "Symbol not declared (error during unpacking)");
                        assignType = internalTypes.vars.find(var)->second;
                    }
                }
                else internalTypes.vars[assignTo] = type;
                implementation += assignTo +" = "+var+";\n";
                vardecl += type->name+" "+assignTo+";\n";
                continue;
            }
            var = imp->at(p++);
        }
        if(types.vars.find(next)==types.vars.end()) imp->error(p-2, "Type not declared");
        type = types.vars.find(next)->second;
        if(assignTo.size() && assignType && type!=assignType) {
            if(type->args.size()==0 && assignType->args.size()==0) {}
            else if(type->args.size()==0 && assignType->packs.size()==1) {}
            else if(type->packs.size()==1 && assignType->args.size()==0) {}
            else if(type->packs.size()==assignType->packs.size()) {}
            else imp->error(p-2, "You are trying to overwrite "+assignType->name+" "+assignTo+" with an incompatible type");
        }

        if(var=="(") {
            if(types.vars.find(next)==types.vars.end()) imp->error(p-2, "Type not declared");
            type = types.vars.find(next)->second;
            var = create_temp();
        }
        else {
            if(assignTo.size()) imp->error(--p, "Expecting opening parenthesis when you call a `smo` anonymously with an assignment (you tried to assign a second name)");
            while(imp->at(p)==".") {
                //if(internalTypes.vars.find(var)==internalTypes.vars.end() && !is_primitive(var)) imp->error(--p, "Symbol not declared"); // declare all up to this point
                var += "__";++p;var += imp->at(p++);
            }
            if(internalTypes.vars.find(var)!=internalTypes.vars.end()) imp->error(--p, "Cannot reconstruct data - use assignment instead");
            if(imp->at(p++)!="(") imp->error(p, "Expecting opening parenthesis");
        }
        internalTypes.vars[var] = type;
        preample += type->preample;

        if(type->name=="buffer") {
            preample += "#include<cstdlib>\n";
            vector<string> unpacks;
            while(true) {
                string arg = imp->at(p++);
                if(arg==")") break;
                arg = parse_expression(imp, p, arg, types);
                Type internalType = internalTypes.vars[arg];
                if(!internalType->packs.size()) unpacks.push_back(arg);
                else for(const string& pack : internalType->packs) unpacks.push_back(arg+"__"+pack);
                arg = imp->at(p++);
                if(arg==")") break;
                if(arg!=",") imp->error(--p, "Comma expected (not implemented expressions other than field access in calls yet)");
            }

            vardecl += "u64 "+var+"__size = 0;\n";
            vardecl += "u64 "+var+"__offset = 0;\n";
            vardecl += "ptr "+var+"__contents;\n";
            implementation += var+"__size = "+to_string(unpacks.size())+";\n";
            implementation += var+"__offset = 0;\n";
            implementation += "if("+var+"__size-"+var+"__offset) free("+var+"__contents);\n";
            implementation += var + "__contents = malloc(sizeof(i64)*" + var + "__size);\n";
            for(size_t i = 0; i < unpacks.size(); ++i) implementation += "std::memcpy((unsigned char*)" + var + "__contents + sizeof(i64) * " + to_string(i) + ", &" + unpacks[i] + ", sizeof(i64));\n";
            internalTypes.vars[var] = type;
            internalTypes.vars[var+"__size"] = types.vars["u64"];
            internalTypes.vars[var+"__contents"] = types.vars["ptr"];
            finals += var+"__size = 0;\nfree(" + var + "__contents);\n";

            if(assignTo.size()) {
                imp->error(--p, "Cannot assign a buffer");
                // assign type is automatically inferred
                /*internalTypes.vars[assignTo] = type;
                 *               for(const auto& it : type->internalTypes.vars) {
                 *                   if(!assignType) {
                 *                       internalTypes.vars[assignTo+"__"+it.first] = it.second;
                 *                       vardecl += it.second->name+" "+assignTo+"__"+it.first+";\n";
            }
            implementation += assignTo+"__"+it.first +" = "+var+"__"+it.first+";\n";
            }*/
            }
            continue;
        }

        if(!type->args.size()) {
            string value = imp->at(p++);
            value = parse_expression(imp, p, value, types);
            if(internalTypes.vars.find(value)==internalTypes.vars.end() && !is_primitive(value)) imp->error(--p, "Symbol not declared (error during argument parsing)");
            if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis because builtin `smo "+next+"` can only have one argument");

            if(internalTypes.vars.find(value)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared (error during unpacking)");
            auto oneType = internalTypes.vars[value];
            if(oneType->packs.size()>1) imp->error(--p, "Can only convert a primitive result to a primitive");
            if(oneType->packs.size())value = value+"__"+oneType->packs[0];

            implementation += var + " = " + value + ";\n";
            vardecl += next + " " + var+";\n";
            internalTypes.vars[var] = type;

            if(assignTo.size()) {
                // assign type is automatically inferred
                if(!assignType) {
                    vardecl += type->name+" "+assignTo+";\n";
                    internalTypes.vars[assignTo] = type;
                }
                else {
                    if(assignType->args.size()==0 && assignType!=type) imp->error(p-2, "You are trying to overwrite "+assignType->name+" "+assignTo+" with an incompatible `smo` type");
                    if(assignType->packs.size()>1) imp->error(p-2, "Cannot unpack to a builting a type with more than one values");
                    if(assignType->packs.size()) {
                        var += "__"+assignType->packs[0];
                        if(internalTypes.vars.find(var)==internalTypes.vars.end()) imp->error(p-2, "Symbol not declared (error during unpacking)");
                        assignType = internalTypes.vars.find(var)->second;
                    }
                    // if(assignType!=type) imp->error(p-2, "Mismatched types");
                }
                implementation += assignTo +" = "+var+";\n";
            }
            continue;
        }

        vector<string> unpacks;
        bool has_buffer = 0;
        while(true) {
            string arg = imp->at(p++);
            arg = parse_expression(imp, p, arg, types);
            if(internalTypes.vars.find(arg)==internalTypes.vars.end() && !is_primitive(arg)) imp->error(--p, "Symbol not declared (error during unpacking)");
            if(!is_primitive(arg)) {
                Type internalType = internalTypes.vars[arg];
                if(internalType->name=="buffer") {
                    has_buffer = p;
                    if(imp->at(p)!=")") imp->error(p, "Argument of builtin type `buffer` can only be last (it unpacks as many elements as possible)");
                    int remaining = (int)(type->args.size()-unpacks.size());
                    if(remaining>0) {
                        string fail_var = create_temp();
                        implementation += "if("+arg+"__size-"+arg+"__offset<"+to_string(remaining)+") goto "+fail_var+";\n";
                        errors += fail_var+":\nprintf(\"Runtime error: `"+arg+"` does not have enough remaining elements\\n\");\ngoto __return;\n";
                        preample += "#include <stdio.h>\n";
                    }
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
                else {
                    if(!internalType->packs.size()) unpacks.push_back(arg);
                    else for(const string& pack : internalType->packs) unpacks.push_back(arg+"__"+pack);
                }
            }
            else unpacks.push_back(arg);
            arg = imp->at(p++);
            if(arg==")") break;
            if(arg!=",") imp->error(--p, "Comma expected (not implemented expressions other than field access in calls yet)");
        }
        if(has_buffer && type->next_overload_to_try) imp->error(has_buffer-1, "Ambiguous syntax\n> Cannot pass a buffer to overloaded "+type->name);


        bool found_overload = false;
        string overloading_errors = "";
        while(!found_overload && type) {
            try {
                if(unpacks.size()!=type->args.size()) throw std::runtime_error(type->signature()+": Requires "+to_string(type->args.size())+" but found "+to_string(unpacks.size())+" arguments");
                for(size_t i=0;i<unpacks.size();++i) {
                    if(type->args[i].type->args.size()) throw std::runtime_error(type->signature()+": Internal errors failed to resolve the type " + type->args[i].type->name + " of "+type->args[i].name);
                    if(internalTypes.vars.find(unpacks[i])==internalTypes.vars.end()) throw std::runtime_error(type->signature()+": Failed to find type for "+unpacks[i]);
                    if(type->args[i].type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i]))
                        throw std::runtime_error(type->signature()+": Needs " + pretty_var(type->args[i].type->name) + " "+pretty_var(type->name)+"."+ pretty_var(type->args[i].name)+" but found "+internalTypes.vars[unpacks[i]]->name+" "+pretty_var(unpacks[i]));
                }
                found_overload = true;
                for(size_t i=0;i<unpacks.size();++i) {
                    string target = var+"__"+type->args[i].name;
                    implementation += target + " = " + unpacks[i]+";\n";
                    vardecl += type->args[i].type->name+" "+ target+";\n";
                    internalTypes.vars[target] = type->args[i].type;
                }
            }
            catch (const std::runtime_error& e) {
                overloading_errors += "\n";
                overloading_errors += e.what();
                type = type->next_overload_to_try;
            }
        }
        if(!type) imp->error(p-1, "Implementation not found"+overloading_errors);

        internalTypes.vars[var] = type; // important to overload correctly
        vardecl += type->rebase(type->vardecl, var);
        implementation += type->rebase(type->implementation, var);
        preample += type->rebase(type->preample, var);
        finals = type->rebase(type->finals, var)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
        errors = errors+type->rebase(type->errors, var);
        for(const auto& it : type->internalTypes.vars) internalTypes.vars[var+"__"+it.first] = it.second;

        if(type->packs.size()==1 && type->packs[0]=="@scope") {
            Def def;
            def.internalTypes.vars["__finally"] = types.vars["__label"];
            //def.internalTypes.vars["start"] = types.vars["__label"];
            for(const auto& it : internalTypes.vars) def.internalTypes.vars[it.first] = it.second;
            def.parse(imp, p, types, false); // this consumes until return
            p++;

            vardecl += def.rebase(def.vardecl, var, internalTypes, false);
            implementation += def.rebase(def.implementation, var, internalTypes);
            preample += def.rebase(def.preample, var, internalTypes);
            finals = def.rebase(def.finals, var, internalTypes)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
            errors = errors+def.rebase(def.errors, var, internalTypes);
            for(const auto& it : def.internalTypes.vars) internalTypes.vars[var+"__"+it.first] = it.second;
            internalTypes.vars[var+"____finally"] = types.vars["__label"];
            //internalTypes.vars[var+"__start"] = types.vars["__label"];
            implementation = var+"__start:\n"+implementation+var+"____finally:\n";
        }
        if(assignTo.size()) {
            if(assignType && assignType->args.size()==0) {
                //cout << type->args.size()<<"\n";
                if(type->packs.size()!=1) imp->error(p-2, "You are trying to overwrite "+assignType->name+" "+assignTo+" with an incompatible `smo` type");
                if(type->packs[0]!="@scope") implementation += assignTo+" = "+var+"__"+type->packs[0]+";\n";
            }
            else {
                internalTypes.vars[assignTo] = type;
                //rejectFields.insert(assignTo); // prevent subsequent element access
                for(const auto& it : type->internalTypes.vars) {
                    if(it.second->name=="@scope") continue;
                    if(it.second->name=="__label" || it.second->args.size()) {
                        if(!assignType) internalTypes.vars[assignTo+"__"+it.first] = it.second;
                        continue;
                    }
                    if(internalTypes.vars.find(var+"__"+it.first)==internalTypes.vars.end()) continue;
                    if(internalTypes.vars.find(assignTo+"__"+it.first)==internalTypes.vars.end()) vardecl += it.second->name+" "+assignTo+"__"+it.first+";\n";
                    if(!assignType) internalTypes.vars[assignTo+"__"+it.first] = it.second;
                    implementation += assignTo+"__"+it.first +" = "+var+"__"+it.first+";\n";
                }
            }
        }

    }
    if(with_signature) {
        internalTypes.vars["__end"] = types.vars["__label"];
        implementation += "__end:\n";
    }
}
