#include "../../def.h"

#include "next_var_and.cpp" 
#include "next_var_or.cpp" 
#include "next_var_field.cpp" 
#include "next_var_buffer_ret_at.cpp" 
#include "next_var_buffer_at.cpp" 
#include "next_var_at.cpp" 

#define CHECK_RELEASE(next) if(released[next]) imp->error(--p, "Cannot use already released value: "+next.to_string());

Variable Def::next_var(const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test) {
    if(first_token.is_empty()) 
        return EMPTY_VAR;
    size_t n = i->size();
    CHECK_RELEASE(first_token);
    if(p>=n) 
        return first_token;
    Variable next = first_token;
    while(true) {
        CHECK_RELEASE(next);
        if(p>=n) 
            break;
        if(imp->at(p)==":") {
            ++p;
            next = parse_expression(i, p, imp->at(p++), types, next);
        }
        else if(imp->at(p)=="and") 
            next = next_var_and(next, imp, p, first_token, types, test);
        else if(imp->at(p)=="or") 
            next = next_var_or(next, imp, p, first_token, types, test);
        else if(imp->at(p)==".") {
            bool skip = false;
            next = next_var_field(next, imp, p, first_token, types, test, skip);
            if(skip)
                continue;
        }
        else if(imp->at(p)=="[" 
            && internalTypes.contains(next) 
            && internalTypes.vars[next]->is_service
            && internalTypes.vars[next]->packs.size()==2
            && internalTypes.vars[next]->internalTypes.contains(internalTypes.vars[next]->packs[1])
            && internalTypes.vars[next]->internalTypes.vars[internalTypes.vars[next]->packs[1]]->name==BUFFER_VAR
        ) {
            next = next_var_buffer_ret_at(next, imp, p, first_token, types, test);
            continue;
        }
        else if(imp->at(p)=="[" 
            && internalTypes.contains(next) 
            && internalTypes.vars[next]->name==BUFFER_VAR
        ) 
            next = next_var_buffer_at(next, imp, p, first_token, types, test);
        else if(imp->at(p)=="[") 
            next = next_var_at(next, imp, p, first_token, types, test);
        else 
            break;
    }
    if(test && next.exists() && !internalTypes.contains(next)) 
        imp->error(--p, "Not found: "
            +pretty_var(next.to_string())
            +recommend_variable(types, next)
        );
    CHECK_RELEASE(next);
    return next;
}
