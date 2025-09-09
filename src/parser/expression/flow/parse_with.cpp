#include "../../../def.h"


Variable Def::parse_with(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos) {
    // TODO: this implementation does not account for nesting
    Variable temp = create_temp();
    Variable finally_var = temp+Variable("with");
    size_t numberOfCandidates = 0;
    string overloading_errors = "";
    string competing = "";
    int with_start = p-1;
    uplifting_targets.push_back(finally_var);
    if(uplifiting_is_loop.size()) 
        uplifiting_is_loop.push_back(uplifiting_is_loop.back());
    else 
        uplifiting_is_loop.push_back(false);
    vars[finally_var] = types.vars[LABEL_VAR];
    string next;
    try {
        if(curry.exists()) 
            imp->error(--p, "Cannot have a curry onto `with`.");
        parse(imp, p, types, false);
        p++;
        next = imp->at(p++);
        numberOfCandidates++;
        implementation += Code(Variable("goto"),finally_var,SEMICOLON_VAR);
        if(numberOfCandidates) 
            competing = "\n"+imp->tokens[with_start].show();
    }
    catch (const runtime_error& e) {
        string what = e.what();
        if(what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found" 
            && (what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found")
        ) 
            throw e;
        if(Def::markdown_errors) 
            overloading_errors += "\n";
        else overloading_errors += "\n- ";
        overloading_errors += what;
        end_block(imp, p);
        next = imp->at(p++);
        if(next!="else") 
            imp->error(with_start, "`with` with no `else`\nCan guard parametric types but is a code smell otherwise\nHere it is redundant as enclosed code always succeeds");
    }
    while(next=="else") {
        if(!numberOfCandidates) {
            try {
                size_t else_start = p-1;
                parse(imp, p, types, false);
                numberOfCandidates++;
                implementation += Code(Variable("goto"), finally_var, SEMICOLON_VAR);
                ++p;
                if(numberOfCandidates) 
                    competing = "\n"+imp->tokens[else_start].show();
            }
            catch (const std::runtime_error& e) {
                string what = e.what();
                if(what.substr(0, string("\033[33mNot found").size())!="\033[33mNot found") 
                    throw e;
                if(Def::markdown_errors) 
                    overloading_errors += "\n";
                else 
                    overloading_errors += "\n- ";
                overloading_errors += what;
                end_block(imp, p);
            }
        }
        else 
            end_block(imp, p);
        next = p<imp->size()?imp->at(p):"";
        p++;
    }
    p--;
    if(numberOfCandidates>1) 
        ERROR("Competes with previous branch of `with`"+competing);
    if(numberOfCandidates==0) 
        imp->error(with_start, "No valid branch of `with`"+string(Def::markdown_errors?"\n```rust":"")+overloading_errors+(Def::markdown_errors?"\n```\n":""));

    implementation += Code(finally_var,COLON_VAR);
    uplifting_targets.pop_back();
    uplifiting_is_loop.pop_back();
    return EMPTY_VAR;

}