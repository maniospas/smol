void end_block(const shared_ptr<Import>& i, size_t& p) {
    size_t depth = 0;
    while(p<i->size()) {
        string next = i->at(p);
        if(next=="if" || next=="else" || next=="while" || next=="with") ++depth;
        if(next=="smo" || next=="service") i->error(p, "Unexpected end of definition");
        if(next=="-" && p<i->size()-1) {
            ++p;
            next = i->at(p);
            if(next=="-") {if(depth==0){++p;break;} --depth;}
            if(next==">") i->error(p, "Currently unimplemented nesting that ends in symbol other than -");
        }
        ++p;
    }
} 

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
        if(next=="with") { // TODO: this implementation does not account for nesting
            string temp = create_temp();
            string finally_var = temp+"__with";
            size_t numberOfCandidates = 0;
            string overloading_errors = "";
            int with_start = p-1;
            uplifting_targets.push_back(finally_var);
            internalTypes.vars[finally_var] = types.vars["__label"];
            
            try {
                parse(imp, p, types, false);
                p++;
                next = imp->at(p++);
                numberOfCandidates++;
            }
            catch (const std::runtime_error& e) {
                string what = e.what();
                if(what.substr(0, string("\033[33mRuntype not found").size())!="\033[33mRuntype not found") throw e;
                overloading_errors += "\n- ";
                overloading_errors += what;
                end_block(imp, p);
                next = imp->at(p++);
            }
            if(next!="else") imp->error(with_start, "Missing matching else statement");
            if(numberOfCandidates==0) {
                try {
                    parse(imp, p, types, false);
                    numberOfCandidates++;
                    ++p;
                }
                catch (const std::runtime_error& e) {
                    string what = e.what();
                    if(what.substr(0, string("\033[33mRuntype not found").size())!="\033[33mRuntype not found") throw e;
                    overloading_errors += "\n- ";
                    overloading_errors += what;
                    end_block(imp, p);
                }
            }
            else end_block(imp, p);
            if(numberOfCandidates>1) imp->error(with_start, "With is not mutually exclusive to else");
            if(numberOfCandidates==0) imp->error(with_start, "No valid branch of with:"+overloading_errors);

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
            if(it->second->name=="buffer") buffer_primitive_associations[var] = buffer_primitive_associations[expression_outcome];
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
