void parse(const shared_ptr<Import>& i, size_t& p, Memory& types, bool with_signature=true) {
    imp = i;
    if(with_signature) {pos = p;parse_signature(imp, p, types);}
    start = p;
    if(lazy_compile && with_signature && !debug) return;
    while(p<imp->size()) {
        string next = imp->at(p++);
        if(next=="@") {parse_directive(imp, p, next, types);continue;}
        if(next=="-") {parse_return(imp, p, next, types);end = p--; break;}
        if(next=="if") {
            string temp = create_temp();
            string finally_var = temp+"__if";
            internalTypes.vars[finally_var] = types.vars["__label"];
            if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
            next = imp->at(p++);
            string var = parse_expression(imp, p, next, types);
            if(!internalTypes.contains(var)) imp->error(--p, "Expression did not evaluate to anything");
            if(internalTypes.vars.find(var)->second!=types.vars["bool"]) imp->error(--p, "If expects bool condition but got "+internalTypes.vars.find(var)->second->name+" "+pretty_var(var));
            if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
            implementation += "if(!"+var+") goto "+finally_var+";\n";
            parse(i, p, types, false);
            p++; // offset p-- after parse_return above
            if(p<i->size()-1 && i->at(p)=="else") {
                p++;
                string else_var = temp+"__else";
                internalTypes.vars[else_var] = types.vars["__label"];
                implementation += "goto "+else_var+";\n";
                implementation += finally_var+":\n";
                parse(i, p, types, false);
                p++; // offset p-- after parse_return above
                implementation += else_var+":\n";
            }
            else implementation += finally_var+":\n";
            continue;
        }
        if(next=="while") {
            string temp = create_temp();
            string finally_var = temp+"__while";
            string start_var = temp+"__loop";
            internalTypes.vars[start_var] = types.vars["__label"];
            internalTypes.vars[finally_var] = types.vars["__label"];
            implementation += start_var+":\n";
            if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
            next = imp->at(p++);
            string var = parse_expression(imp, p, next, types);
            if(!internalTypes.contains(var)) imp->error(--p, "Expression did not evaluate to anything");
            if(internalTypes.vars.find(var)->second!=types.vars["bool"]) imp->error(--p, "If expects bool condition but got "+internalTypes.vars.find(var)->second->name+" "+pretty_var(var));
            if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
            implementation += "if(!"+var+") goto "+finally_var+";\n";
            parse(i, p, types, false);
            p++; // offset p-- after parse_return above
            implementation += "goto "+start_var+";\n";
            implementation += finally_var+":\n";
            continue;
        }
        string var = imp->at(p);
        if(var=="." || var=="=") {
            var = next_var(imp, p, next, types, false);
            int assignment_start = p;
            if(imp->at(p++)!="=") imp->error(p, "Missing assignment");
            next = imp->at(p++);
            string expression_outcome = parse_expression(imp, p, next, types);
            if(!expression_outcome.size()) imp->error(assignment_start, "Expression returns no value");
            const auto& it = internalTypes.vars.find(expression_outcome);
            if(it==internalTypes.vars.end()) imp->error(assignment_start, "Failed to parse expression");
            assign_variable(it->second, var, expression_outcome, i, p);
        }
        else parse_expression(imp, p, next, types);
    }
    if(with_signature) {
        internalTypes.vars["__end"] = types.vars["__label"];
        implementation += "__end:\n";
    }
}
