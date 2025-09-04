#include "../def.h"

void Def::end_block(const shared_ptr<Import>& i, size_t& p) {
    size_t depth = 0;
    while(p<imp->size()) {
        string next = imp->at(p);
        if(next=="if" || next=="else" || next=="while" || next=="with") 
            ++depth;
        if(next=="smo" || next=="service") 
            imp->error(p, "Unexpected end of definition");
        if(next=="-" && p<imp->size()-1) {
            ++p; next = imp->at(p);
            //if(next=="-" && imp->at(p-2)=="|") {}
            if(next=="-") {if(depth==0){++p;break;} --depth;}
            //else if(next==">" && imp->at(p-2)=="|") {}
            else if(next==">") imp->error(p, "Currently unimplemented nesting that ends in symbol other than `--`");
        }
        ++p;
    }
}

void Def::parse(const shared_ptr<Import>& _imp, size_t& p, Types& types, bool with_signature) {
    if(!imp) 
        imp = _imp;
    if(!imp) 
        ERROR("Internal error: tried to parse a runtype without a file "+name.to_string());
    if(with_signature) {
        pos = p;
        parse_signature(imp, p, types);
    }
    if(!uplifting_targets.size()) 
        uplifting_targets.push_back(Variable("__end"));
    saved_types = types;
    start = p;
    parse_implementation(p, with_signature);
}

void Def::parse_no_implementation(const shared_ptr<Import>& _imp, size_t& p, Types& types, bool with_signature) {
    if(!imp) 
        imp = _imp;
    if(!imp) 
        ERROR("Internal error: tried to parse a runtype without a file "+name.to_string());
    if(with_signature) {
        pos = p;
        parse_signature(imp, p, types);
    }
    if(!uplifting_targets.size()) 
        uplifting_targets.push_back(Variable("__end"));

    saved_types.vars.reserve(types.vars.size());
    saved_types.alignment_labels.reserve(types.alignment_labels.size());
    saved_types.reverse_alignment_labels.reserve(types.reverse_alignment_labels.size());
    for(const auto& it : types.vars) 
        saved_types.vars[it.first] = it.second;
    for(const auto& it : types.alignment_labels) 
        saved_types.alignment_labels[it.first] = it.second;
    for(const auto& it : types.reverse_alignment_labels) 
        saved_types.reverse_alignment_labels[it.first] = it.second;
    start = p;
}

void Def::parse_implementation(size_t& p, bool with_signature) {
    if(_is_primitive) 
        return;
    if(!imp) 
        ERROR("Internal error: tried to parse a runtype implementation without a file "+name.to_string());
    if(lazy_compile && with_signature) 
        return;
    Types& types = saved_types;
    unordered_set<Variable> next_assignments;
    while(p<imp->size()) {
        bool is_next_assignment = false;
        bool is_mutable_assignment = false;
        string next = imp->at(p++);
        if(next=="@") {
            if(p<imp->size() && imp->at(p)=="next"){
                is_next_assignment=true;
                p++;
                next = imp->at(p++);
            }
            else {
                parse_directive(imp, p, next, types);
                continue;
            }
        }
        if(next=="&") {
            next = imp->at(p++);
            is_mutable_assignment=true;
        }
        if(next=="|") {
            parse_return(imp, p, next, types);
            end = p--;
            break;
        }
        if(next=="-") {
            parse_return(imp, p, next, types);
            end = p--;
            break;
        }
        if(next=="else") {
            --p;
            end = p--; 
            break;
        }
        Variable var = imp->at(p);
        if(var=="=" && p<imp->size()-1 && imp->at(p+1)=="=") var = EMPTY_VAR;
        if(var=="." || var=="=") {
            var = next_var(imp, p, next, types, false);
            if(is_mutable_assignment) {
                if(internalTypes.contains(var)) imp->error(--p, "Cannot set as mutable an existing variable: "+var.to_string()+"\nMutability is declared by prepending & to the first occurence"); 
                mutables.insert(var);
            }
            int assignment_start = p;
            if(imp->at(p++)!="=") {
                --p;
                continue;
            }//imp->error(--p, "Missing assignment");
            next = imp->at(p++);
            Variable expression_outcome = parse_expression(imp, p, next, types);
            if(!expression_outcome.exists()) 
                imp->error(assignment_start, "The right-hand-side expression computes to no value");
            const auto& it = internalTypes.vars.find(expression_outcome);
            if(it==internalTypes.vars.end()) 
                imp->error(assignment_start, "Failed to parse expression");
            if(is_next_assignment) {
                next_assignments.insert(var);
                var = NEXT_VAR+var;
            }
            if(is_mutable_assignment && mutables.find(expression_outcome)==mutables.end()) for(const auto& pack : internalTypes.vars[expression_outcome]->packs) {
                if((internalTypes.vars[expression_outcome]->internalTypes.vars[pack]->name==PTR_VAR 
                        || internalTypes.vars[expression_outcome]->internalTypes.vars[pack]->name==BUFFER_VAR)
                    && mutables.find(var+pack)==mutables.end()
                ) 
                    imp->error(assignment_start, "Cannot transfer an immutable ptr packed in an immutable variable to a mutable ptr: "
                        + pretty_var((var+pack).to_string())
                        + "\nThis error occurs because, by convention, the contents (but not addresses) "
                        + "\nof mutable pointers may be freely modified when runtypes gain a hold of them."
                    );
            }
            assign_variable(it->second, var, expression_outcome, imp, p);
        }
        else if(is_next_assignment) 
            imp->error(p, "Expecting assignment to variable after @next");
        else if(is_mutable_assignment) 
            imp->error(p, "Expecting assignment to variable after &");
        else 
            parse_expression(imp, p, next, types);
    }
    for(const Variable& var : next_assignments) 
        assign_variable(internalTypes.vars[NEXT_VAR+var], var, NEXT_VAR+var.to_string(), imp, p);
    if(with_signature) {
        static const Variable endvar = Variable("__end");
        internalTypes.vars[endvar] = types.vars[LABEL_VAR];
        implementation +=Code(endvar, COLON_VAR);
        simplify();
    }
}
