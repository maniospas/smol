void parse(const shared_ptr<Import>& i, size_t& p, Memory& types, bool with_signature=true) {
    imp = i;
    if(with_signature) {pos = p;parse_signature(imp, p, types);}
    start = p;
    if(lazy_compile && with_signature && !debug) return;
    while(p<imp->size()) {
        string next = imp->at(p++);
        if(next=="@") {parse_directive(imp, p, next, types);continue;}
        if(next=="-") {parse_return(imp, p, next, types);end = p--; break;}
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
