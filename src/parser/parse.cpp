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
        if(next=="-") {
            parse_return(imp, p, next, types);end = p--; break;
        }
        
        string var = imp->at(p);
        if(var=="." || var=="=") {
            var = next_var(imp, p, next, types, false);
            int assignment_start = p;
            if(imp->at(p++)!="=") imp->error(p, "Missing assignment");
            next = imp->at(p++);
            string expression_outcome = parse_expression(imp, p, next, types);
            if(!expression_outcome.size()) imp->error(assignment_start, "The right-hand-side expression computes to no value");
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
