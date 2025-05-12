void parse(const shared_ptr<Import>& i, size_t& p, Memory& types, bool with_signature=true) {
    imp = i;
    if(with_signature) {pos = p;parse_signature(imp, p, types);}
    if(!uplifting_targets.size()) uplifting_targets.push_back("__end");
    start = p;
    if(lazy_compile && with_signature && !debug) return;
    unordered_set<string> next_assignments;
    while(p<imp->size()) {
        bool is_next_assignment = false;
        string next = imp->at(p++);
        if(next=="@") {
            if(p<i->size() && i->at(p)=="next"){is_next_assignment=true;p++;next = imp->at(p++);}
            else {parse_directive(imp, p, next, types);continue;}
        }
        if(next=="-") {parse_return(imp, p, next, types);end = p--; break;}
        if(next=="if") {
            string temp = create_temp();
            string finally_var = temp+"__if";
            uplifting_targets.push_back(finally_var);
            internalTypes.vars[finally_var] = types.vars["__label"];
            next = imp->at(p++);
            string var = parse_expression(imp, p, next, types);
            if(!internalTypes.contains(var)) imp->error(--p, "Expression did not evaluate to anything");
            if(internalTypes.vars.find(var)->second!=types.vars["bool"]) imp->error(--p, "If expects bool condition but got "+internalTypes.vars.find(var)->second->name+" "+pretty_var(var));
            implementation += "if(!"+var+") goto "+finally_var+";\n";
            parse(i, p, types, false);
            p++; // offset p-- after parse_return above
            if(p<i->size()-1 && i->at(p)=="else") {
                p++;
                string else_var = temp+"__else";
                internalTypes.vars[else_var] = types.vars["__label"];
                uplifting_targets.pop_back();
                uplifting_targets.push_back(else_var);
                implementation += "goto "+else_var+";\n";
                implementation += finally_var+":\n";
                parse(i, p, types, false);
                p++; // offset p-- after parse_return above
                implementation += else_var+":\n";
            }
            else implementation += finally_var+":\n";
            uplifting_targets.pop_back();
            continue;
        }
        if(next=="while") {
            string temp = create_temp();
            string finally_var = temp+"__while";
            uplifting_targets.push_back(finally_var);
            string start_var = temp+"__loop";
            internalTypes.vars[start_var] = types.vars["__label"];
            internalTypes.vars[finally_var] = types.vars["__label"];
            implementation += start_var+":\n";
            next = imp->at(p++);
            string var = parse_expression(imp, p, next, types);
            if(!internalTypes.contains(var)) imp->error(--p, "Expression did not evaluate to anything");
            if(internalTypes.vars.find(var)->second!=types.vars["bool"]) imp->error(--p, "If expects bool condition but got "+internalTypes.vars.find(var)->second->name+" "+pretty_var(var));
            implementation += "if(!"+var+") goto "+finally_var+";\n";
            parse(i, p, types, false);
            p++; // offset p-- after parse_return above
            implementation += "goto "+start_var+";\n";
            implementation += finally_var+":\n";
            uplifting_targets.pop_back();
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
            if(is_next_assignment) {
                next_assignments.insert(var);
                var = "__next__"+var;
            }
            assign_variable(it->second, var, expression_outcome, i, p);
        }
        else {
            if(is_next_assignment) imp->error(p, "Expecting assignment to variable after @next");
            parse_expression(imp, p, next, types);
        }
    }
    for(const string& var : next_assignments) assign_variable(internalTypes.vars["__next__"+var], var, "__next__"+var, i, p);
    if(with_signature) {
        internalTypes.vars["__end"] = types.vars["__label"];
        implementation += "__end:\n";
    }
}
