#include "../def.h"

void Def::end_block(const shared_ptr<Import>& i, size_t& p) {
    size_t depth = 0;
    while(p<imp->size()) {
        string next = imp->at(p);
        if(next=="if" || next=="else" || next=="while" || next=="with") ++depth;
        if(next=="smo" || next=="service") imp->error(p, "Unexpected end of definition");
        if(next=="-" && p<imp->size()-1) {
            ++p; next = imp->at(p);
            if(next=="-") {if(depth==0){++p;break;} --depth;}
            if(next==">") imp->error(p, "Currently unimplemented nesting that ends in symbol other than `--` or `else`");
        }
        ++p;
    }
}

void Def::parse(const shared_ptr<Import>& _imp, size_t& p, Types& types, bool with_signature) {
    if(!imp) imp = _imp;
    if(!imp) ERROR("Internal error: tried to parse a runtype without a file "+name);
    if(with_signature) {pos = p;parse_signature(imp, p, types);}
    if(!uplifting_targets.size()) uplifting_targets.push_back("__end");
    start = p;
    if(lazy_compile && with_signature) return;
    unordered_set<string> next_assignments;
    while(p<imp->size()) {
        bool is_next_assignment = false;
        bool is_mutable_assignment = false;
        string next = imp->at(p++);
        if(next=="@") {
            if(p<imp->size() && imp->at(p)=="next"){is_next_assignment=true;p++;next = imp->at(p++);}
            else {parse_directive(imp, p, next, types);continue;}
        }
        if(next=="&") {next = imp->at(p++);is_mutable_assignment=true;}
        if(next=="|") {parse_return(imp, p, next, types);end = p--; break;}
        if(next=="-") {parse_return(imp, p, next, types);end = p--; break;}
        if(next=="else") {--p;end = p--; break;}
        string var = imp->at(p);
        if(var=="=" && p<imp->size()-1 && imp->at(p+1)=="=") var = "";
        if(var=="." || var=="=") {
            var = next_var(imp, p, next, types, false);
            if(is_mutable_assignment) {if(internalTypes.contains(var)) imp->error(--p, "Cannot set as mutable an existing variable: "+var+"\nMutability is declared by prepending & to the first occurence"); mutables.insert(var);}
            int assignment_start = p;
            if(imp->at(p++)!="=") {--p;continue;}//imp->error(--p, "Missing assignment");
            next = imp->at(p++);
            string expression_outcome = parse_expression(imp, p, next, types);
            if(!expression_outcome.size()) imp->error(assignment_start, "The right-hand-side expression computes to no value");
            const auto& it = internalTypes.vars.find(expression_outcome);
            if(it==internalTypes.vars.end()) imp->error(assignment_start, "Failed to parse expression");
            if(is_next_assignment) {next_assignments.insert(var);var = "__next__"+var;}
            if(it->second && it->second->name=="buffer") buffer_primitive_associations[var] = buffer_primitive_associations[expression_outcome];
            assign_variable(it->second, var, expression_outcome, imp, p);
        }
        else if(is_next_assignment) imp->error(p, "Expecting assignment to variable after @next");
        else if(is_mutable_assignment) imp->error(p, "Expecting assignment to variable after &");
        else parse_expression(imp, p, next, types);
    }
    for(const string& var : next_assignments) assign_variable(internalTypes.vars["__next__"+var], var, "__next__"+var, imp, p);
    if(with_signature) {
        internalTypes.vars["__end"] = types.vars["__label"];implementation += "__end:\n";
        for(const auto& it : invalidators) if(it.second.size()) finals[it.first] = it.second;
        invalidators.clear();
        simplify();
    }
}
