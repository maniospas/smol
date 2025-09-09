// Copyright 2025 Emmanouil Krasanakis (maniospas@hotmail.com)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "../def.h"

Variable Def::parse_expression(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, const Variable& curry) {
    if(first_token=="(") {
        Variable ret = parse_expression(imp, p, imp->at(p++), types, curry);
        if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis");
        return next_var(imp, p, ret, types);
    }
    return parse_expression_no_par(imp, p, first_token, types, curry);
}

Variable Def::parse_expression_no_par(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry) {
    size_t first_token_pos = p-1;
    if(first_token==DOT_VAR 
        || first_token==CURRY_VAR
        || first_token==LBRACKET_VAR 
        || first_token==RBRACKET_VAR 
        || first_token=="{" 
        || first_token=="}" 
        || first_token==";"
        || first_token=="&"
    ) 
        imp->error(p-1, "Unexpected symbol\nThe previous expression already ended.");

    if(first_token==IF_VAR) {
        Variable temp = create_temp();
        Variable finally_var = temp+IF_VAR;
        Variable closeif_var = temp+FI_VAR;
        uplifting_targets.push_back(finally_var);
        if(uplifiting_is_loop.size()) 
            uplifiting_is_loop.push_back(uplifiting_is_loop.back());
        else 
            uplifiting_is_loop.push_back(false);
        vars[finally_var] = types.vars[LABEL_VAR];
        vars[closeif_var] = types.vars[LABEL_VAR];
        string next = imp->at(p++);
        Variable var = parse_expression(imp, p, next, types, curry);
        if(!contains(var)) 
            imp->error(--p, "Expression did not evaluate to anything");
        if(vars.find(var)->second!=types.vars[BOOL_VAR]) 
            imp->error(--p, "If expects bool condition but got "
                +vars.find(var)->second->name.to_string()
                +" "+pretty_var(var.to_string())
            );
        implementation += Code(token_ifnot,var,token_goto,closeif_var,SEMICOLON_VAR);
        parse(imp, p, types, false);
        p++; // offset p-- after parse_return above
        Variable else_var = EMPTY_VAR;
        Variable rfinally_var = finally_var+Variable("r");
        if(p<imp->size()-1 && imp->at(p)=="else") {
            p++;
            else_var = temp+LE_VAR;
            Variable relse_var = else_var+Variable("r");
            vars[else_var] = types.vars[LABEL_VAR];
            Variable else_skip = temp+EL_VAR;
            vars[else_skip] = types.vars[LABEL_VAR];
            uplifting_targets.pop_back();
            uplifting_targets.push_back(else_var);
            implementation += Code(finally_var,COLON_VAR,Variable("goto"), else_skip, SEMICOLON_VAR, closeif_var, COLON_VAR);
            parse(imp, p, types, false);
            implementation += Code(else_var,COLON_VAR);
            p++; // offset p-- after parse_return above
            if(contains(relse_var) && !contains(rfinally_var)) 
                imp->error(first_token_pos, "There was a non-empty return "
                    +vars[relse_var]->name.to_string()
                    +" `else` but no such value from `if`"
                );
            if(!contains(relse_var) && contains(rfinally_var)) 
                imp->error(first_token_pos, "There was a non-empty return "
                    +vars[rfinally_var]->name.to_string()
                    +" `if` but no such value from `else` "
                );
            if(contains(relse_var) && contains(rfinally_var)) {
                if(vars[rfinally_var]!=vars[relse_var]) 
                    imp->error(first_token_pos, "There were mismatching return "
                        +vars[rfinally_var]->name.to_string()
                        +" `if` and "+vars[relse_var]->name.to_string()+" `else`"
                    );
                assign_variable(
                    vars[rfinally_var], 
                    rfinally_var, 
                    relse_var, 
                    imp, 
                    first_token_pos, 
                    false, 
                    false
                );
            }
            implementation += Code(else_skip,COLON_VAR);
        }
        else 
            implementation += Code(finally_var,COLON_VAR,closeif_var,COLON_VAR);
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        if(contains(rfinally_var)) {
            if(else_var.exists()==0) 
                imp->error(first_token_pos, "There was a non-empty return "
                    +vars[rfinally_var]->name.to_string()
                    +" `if` but no `else` statement for the alternative"
                ); 
            return rfinally_var;
        }
        return EMPTY_VAR;
    }
    if(first_token==WHILE_VAR) {
        Variable temp = create_temp();
        Variable finally_var = temp+WHILE_VAR;
        uplifting_targets.push_back(finally_var);
        uplifiting_is_loop.push_back(true);
        Variable start_var = temp+LOOP_VAR;
        vars[start_var] = types.vars[LABEL_VAR];
        vars[finally_var] = types.vars[LABEL_VAR];
        implementation +=Code(start_var,COLON_VAR);
        Variable next = imp->at(p++);
        Variable var = parse_expression(imp, p, next, types, curry);
        if(!contains(var)) 
            imp->error(--p, "Expression did not evaluate to anything");
        if(vars.find(var)->second!=types.vars[BOOL_VAR]) 
            imp->error(--p, "If expects bool condition but got "
                +vars.find(var)->second->name.to_string()
                +" "+pretty_var(var.to_string())
            );
        implementation += Code(token_ifnot,var,token_goto,finally_var,SEMICOLON_VAR);
        parse(imp, p, types, false);
        p++; // offset p-- after parse_return above
        implementation += Code(Variable("goto"),start_var,SEMICOLON_VAR,finally_var,COLON_VAR);
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        return EMPTY_VAR;
    }

    if(first_token=="len" && curry.exists() && contains(curry) && vars[curry]->name==BUFFER_VAR)  {
        curry = curry+Variable("dynamic");
        vars[Variable("__buffer_size")] = types.vars[Variable("u64")];
        implementation += Code(
            Variable("__buffer_size"), 
            ASSIGN_VAR, 
            curry,
            Variable("?"),
            Variable("((u64*)"), 
            curry, 
            Variable(")[1]:0"), 
            SEMICOLON_VAR
        );
        return next_var(imp, p, Variable("__buffer_size"), types);
    }
    if(first_token=="put" && curry.exists() && contains(curry) && vars[curry]->name==BUFFER_VAR)  {
        Variable raw_var = curry;
        if(imp->at(p++)!="(") 
            imp->error(--p, "Expected opening parenthesis");
        if(mutables.find(curry)==mutables.end()) 
            imp->error(--p, "Cannot put into a non-mutable buffer");
        curry = curry+Variable("dynamic");
        if(buffer_types.find(curry)==buffer_types.end()) 
            imp->error(--p, "Internal error: buffer has not been properly transferred to scope: "+curry.to_string());
        size_t prev_p = p;
        string next_tok = imp->at(p++);
        Variable idx = parse_expression(imp, p, next_tok, types, EMPTY_VAR);
        if(!idx.exists() || !contains(idx) || vars[idx]->name!=U64_VAR)
            imp->error(prev_p, "First argument to put must be u64 but got "
                + (contains(idx)?vars[idx]->name.to_string():"nothing")
            );
        if(imp->at(p++)!=",") 
            imp->error(--p, "Expected comma after buffer index");

        prev_p = p;
        next_tok = imp->at(p++);
        Variable val = parse_expression(imp, p, next_tok, types, EMPTY_VAR);
        if(!val.exists() || !contains(val)) 
            imp->error(prev_p, "Expression does not yield a value within put");
        if(vars[val].get() != buffer_types[curry].get())
            imp->error(prev_p, "Mismatching buffer types.\nTo prevent errors, no structural matching is allowed.\nExpected "
                +buffer_types[curry]->signature(types)+" but got "
                +vars[val]->signature(types)
            );

        if(imp->at(p++)!=")") 
            imp->error(--p, "Expecting closing parenthesis");

        // locals (namespaced)
        vars[curry+Variable("__buffer_size")]      = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_alignment")] = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_contents")]  = types.vars[Variable("ptr")];
        
        Variable fail_var = create_temp();
        implementation += Code(
            token_ifnot, 
            curry, 
            token_goto,
            fail_var, 
            SEMICOLON_VAR
        );

        // compute count_packs (valid packs only)
        size_t count_packs = 0;
        for(const auto& pack : buffer_types[curry]->packs)
            if(buffer_types[curry]->contains(pack) && buffer_types[curry]->vars[pack]->name!=NOM_VAR)
                count_packs++;

        implementation += Code(curry+Variable("__buffer_size"), ASSIGN_VAR, Variable("((u64*)"), curry, Variable(")[1]"), SEMICOLON_VAR);
        implementation += Code(curry+Variable("__buffer_alignment"), ASSIGN_VAR, Variable(to_string(count_packs)), SEMICOLON_VAR);
        implementation += Code(curry+Variable("__buffer_contents"), ASSIGN_VAR, Variable("(ptr)(((u64*)"), curry, Variable(")[0])"), SEMICOLON_VAR);

        // range check
        vars[fail_var] = types.vars[LABEL_VAR];
        implementation += Code(token_if, idx, Variable(">="), curry+Variable("__buffer_size"),Variable(")goto"), fail_var, SEMICOLON_VAR);
        errors += Code(fail_var, Variable(":\nprintf(\"Buffer index out of range\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n"));

        // write element packs at idx
        size_t pack_index = 0;
        for(const auto& pack : buffer_types[curry]->packs) {
            if(buffer_types[curry]->contains(pack) && buffer_types[curry]->vars[pack]->name!=NOM_VAR) {
                implementation += Code(
                    Variable("memcpy(&((u64*)"), curry+Variable("__buffer_contents"), Variable(")["), idx, MUL_VAR, curry+Variable("__buffer_alignment"), Variable("+"+to_string(pack_index)+"], &"),
                    val+Variable(pack),
                    Variable(", sizeof("+buffer_types[curry]->vars[pack]->name.to_string()+"));")
                );
                pack_index++;
            }
        }

        return next_var(imp, p, raw_var, types);
    }


    if(first_token=="push" 
        && curry.exists() 
        && contains(curry) 
        && vars[curry]->name==BUFFER_VAR
    ) {
        if(imp->at(p++)!="(") 
            imp->error(--p, "Expected opening parenthesis");
        if(mutables.find(curry)==mutables.end()) 
            imp->error(--p, "Cannot push onto a non-mutable buffer");
        Variable raw_var = curry;
        curry = curry+Variable("dynamic");
        if(buffer_types.find(curry)==buffer_types.end())
            imp->error(--p, "Internal error: buffer has not been properly transferred to scope");
        auto prev_p = p;
        string next = imp->at(p++);
        Variable var = parse_expression(imp, p, next, types, EMPTY_VAR);
        if(!var.exists() || !vars[var]) 
            imp->error(prev_p, "Expression does not yield a value within push");
        if(vars[var].get() != buffer_types[curry].get())
            imp->error(prev_p, "Mismatching buffer types.\nTo prevent errors, no structural matching of the types is allowed.\nExpected " 
                + buffer_types[curry]->signature(types) 
                + " but got " 
                + vars[var]->signature(types)
            );
        if(imp->at(p++)!=")") 
            imp->error(--p, "Expecting closing parenthesis");

        vars[curry+Variable("__buffer_size")]          = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_capacity")]      = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_prev_capacity")] = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_alignment")]     = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_contents")]      = types.vars[Variable("ptr")];

        Variable fail_var = create_temp();
        implementation += Code(
            token_ifnot, 
            curry, 
            token_goto,
            fail_var, 
            SEMICOLON_VAR
        );

        // compute count_packs (valid packs only)
        size_t count_packs = 0;
        for(const auto& pack : buffer_types[curry]->packs)
            if(buffer_types[curry]->contains(pack) && buffer_types[curry]->vars[pack]->name!=NOM_VAR)
                count_packs++;
        if(buffer_types[curry]->_is_primitive) count_packs++;

        implementation += Code(curry+Variable("__buffer_alignment"), ASSIGN_VAR, Variable(to_string(count_packs)), SEMICOLON_VAR);
        implementation += Code(curry+Variable("__buffer_size"), ASSIGN_VAR, Variable("((u64*)"), curry, Variable(")[1]"), SEMICOLON_VAR);
        implementation += Code(curry+Variable("__buffer_capacity"), ASSIGN_VAR, Variable("((u64*)"), curry, Variable(")[2] & ~(1ULL << 63)"), SEMICOLON_VAR);

        static const Variable token_print = Variable(":\nprintf(\"Buffer error");
        static const Variable token_failsafe = Variable("\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n");

        implementation += Code(token_if, curry+Variable("__buffer_size"),
            Variable(">="), curry+Variable("__buffer_capacity"), Variable("){"));

        implementation += Code(token_if,
            Variable("((u64*)"), curry, Variable(")[2] & (1ULL << 63)"),
            token_goto, fail_var, SEMICOLON_VAR);

        implementation += Code(curry+Variable("__buffer_prev_capacity"), ASSIGN_VAR,
            curry+Variable("__buffer_capacity"), SEMICOLON_VAR);

        implementation += Code(curry+Variable("__buffer_capacity"), ASSIGN_VAR,
            curry+Variable("__buffer_capacity"),
            Variable("+("), curry+Variable("__buffer_capacity"), Variable(">>2)+1;")); // +25%+1 capacity

        // realloc path
        implementation += Code(token_if, curry+Variable("__buffer_size"),
            Variable(") ((void**)"), curry,
            Variable(")[0] = __runtime_realloc((u64*)((void**)"), curry,
            Variable(")[0], "),
            curry+Variable("__buffer_capacity"), MUL_VAR, curry+Variable("__buffer_alignment"),
            Variable("*sizeof(u64), "),
            curry+Variable("__buffer_prev_capacity"), MUL_VAR, curry+Variable("__buffer_alignment"),
            Variable("*sizeof(u64));"));

        // alloc path
        implementation += Code(Variable("else ((void**)"), curry,
            Variable(")[0] = __runtime_alloc("),
            curry+Variable("__buffer_capacity"), Variable("*"),
            curry+Variable("__buffer_alignment"), Variable("*sizeof(u64));"));

        // update capacity
        implementation += Code(Variable("((u64*)"), curry, Variable(")[2]"),
            ASSIGN_VAR, curry+Variable("__buffer_capacity"), SEMICOLON_VAR);

        // set buffer_contents
        implementation += Code(curry+Variable("__buffer_contents"), ASSIGN_VAR,
            Variable("(ptr)((void**)"), curry, Variable(")[0]"), SEMICOLON_VAR);


        vars[fail_var] = types.vars[LABEL_VAR];
        implementation += Code(token_if, Variable("!"), curry+Variable("__buffer_contents"), token_goto, fail_var, SEMICOLON_VAR);
        errors += Code(fail_var, token_print, token_failsafe);

        implementation += Code(Variable("} else "));
        implementation += Code(curry+Variable("__buffer_contents"), ASSIGN_VAR, Variable("(ptr)(((u64*)"), curry, Variable(")[0])"), SEMICOLON_VAR);
        implementation += Code(Variable("((u64*)"), curry, Variable(")[1]"), ASSIGN_VAR, curry+Variable("__buffer_size"), Variable("+1"), SEMICOLON_VAR);

        // final loop: move only valid packs
        size_t pack_index = 0;
        if(buffer_types[curry]->_is_primitive) {
            implementation += Code(
                Variable("memcpy(&((u64*)"), curry+Variable("__buffer_contents"), Variable(")["), curry+Variable("__buffer_size"), MUL_VAR, curry+Variable("__buffer_alignment"), Variable("], &"),
                var,
                Variable(", sizeof(u64));")
            );
        }
        else for(const auto& pack : buffer_types[curry]->packs) {
            if(buffer_types[curry]->contains(pack) 
                && buffer_types[curry]->vars[pack]->name!=NOM_VAR
            ) {
                implementation += Code(
                    Variable("memcpy(&((u64*)"), curry+Variable("__buffer_contents"), Variable(")["), curry+Variable("__buffer_size"), MUL_VAR, curry+Variable("__buffer_alignment"), Variable("+"+to_string(pack_index)+"], &"),
                    var+Variable(pack),
                    Variable(", sizeof("+buffer_types[curry]->vars[pack]->name.to_string()+"));")
                );
                pack_index++;
            }
        }
        return next_var(imp, p, raw_var, types);
    }

    if(first_token=="expect" 
        && curry.exists() 
        && contains(curry) 
        && vars[curry]->name==BUFFER_VAR
    ) {
        Variable raw_var = curry;
        if(imp->at(p++)!="(") 
            imp->error(--p, "Expected opening parenthesis");
        if(mutables.find(curry)==mutables.end()) 
            imp->error(--p, "Cannot grow a non-mutable buffer");
        curry = curry+Variable("dynamic");
        if(buffer_types.find(curry)==buffer_types.end())
            imp->error(--p, "Internal error: buffer has not been properly transferred to scope");
        auto prev_p = p;
        string next = imp->at(p++);
        Variable amount = parse_expression(imp, p, next, types, EMPTY_VAR);
        if(!amount.exists() || !vars[amount]) 
            imp->error(prev_p, "Expression does not yield a value within grow");
        if(vars[amount]->name != Variable("u64"))
            imp->error(prev_p, "Grow amount must be of type u64");
        if(imp->at(p++)!=")") 
            imp->error(--p, "Expecting closing parenthesis");

        vars[curry+Variable("__buffer_size")]          = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_capacity")]      = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_prev_capacity")] = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_alignment")]     = types.vars[Variable("u64")];
        vars[curry+Variable("__buffer_contents")]      = types.vars[Variable("ptr")];

        Variable fail_var = create_temp();
        implementation += Code(
            token_ifnot, 
            curry, 
            token_goto,
            fail_var, 
            SEMICOLON_VAR
        );

        // compute count_packs (valid packs only)
        size_t count_packs = 0;
        for(const auto& pack : buffer_types[curry]->packs)
            if(buffer_types[curry]->contains(pack) && buffer_types[curry]->vars[pack]->name!=NOM_VAR)
                count_packs++;
        if(buffer_types[curry]->_is_primitive) count_packs++;

        implementation += Code(curry+Variable("__buffer_alignment"), ASSIGN_VAR, Variable(to_string(count_packs)), SEMICOLON_VAR);
        implementation += Code(curry+Variable("__buffer_size"), ASSIGN_VAR, Variable("((u64*)"), curry, Variable(")[1]"), SEMICOLON_VAR);
        implementation += Code(curry+Variable("__buffer_capacity"), ASSIGN_VAR, Variable("((u64*)"), curry, Variable(")[2] & ~(1ULL << 63)"), SEMICOLON_VAR);

        static const Variable token_print = Variable(":\nprintf(\"Buffer error");
        static const Variable token_failsafe = Variable("\\n\");\n__result__errocode=__BUFFER__ERROR;\ngoto __failsafe;\n");

        // check if resize needed
        implementation += Code(token_if, amount, Variable("&&"), curry+Variable("__buffer_size"), PLUS_VAR, amount, Variable(">"), curry+Variable("__buffer_capacity"), Variable("){"));
        implementation += Code(token_if, Variable("((u64*)"), curry, Variable(")[2] & (1ULL << 63)"), token_goto, fail_var, SEMICOLON_VAR);
        implementation += Code(curry+Variable("__buffer_prev_capacity"), ASSIGN_VAR, curry+Variable("__buffer_capacity"), SEMICOLON_VAR); 
        implementation += Code(curry+Variable("__buffer_capacity"), ASSIGN_VAR, curry+Variable("__buffer_size"), PLUS_VAR, amount, token_plus_one, SEMICOLON_VAR); // capacity to the new size
        implementation += Code(
            token_if,
            curry + Variable("__buffer_size"),
            Variable(") { ((u64*)"),
            curry,
            Variable(")[0]=(u64)(u64*)__runtime_realloc((u64*)((u64*)"),
            curry,
            Variable(")[0], "),
            curry + Variable("__buffer_capacity"),
            MUL_VAR,
            curry + Variable("__buffer_alignment"),
            Variable("*sizeof(u64), "),
            curry + Variable("__buffer_prev_capacity"),
            MUL_VAR,
            curry + Variable("__buffer_alignment"),
            Variable("*sizeof(u64));"),
            // zero-initialization for the newly allocated part
            Variable("memset((u64*)((u64*)((u64*)"),
            curry,
            Variable(")[0]) + ("),
            curry + Variable("__buffer_prev_capacity"),
            MUL_VAR,
            curry + Variable("__buffer_alignment"),
            Variable("), 0, (("),
            curry + Variable("__buffer_capacity"),
            Variable(" - "),
            curry + Variable("__buffer_prev_capacity"),
            Variable(") * "),
            curry + Variable("__buffer_alignment"),
            Variable(" * sizeof(u64)));")
        );
        implementation += Code(
            Variable("} else ((u64*)"), 
            curry, Variable(")[0]=(u64)(u64*)__runtime_calloc("), 
            curry+Variable("__buffer_capacity"), 
            Variable("*"), 
            curry+Variable("__buffer_alignment"), 
            Variable("*sizeof(u64))"), 
            COMMA_VAR, 
            ZERO_VAR, 
            SEMICOLON_VAR
        );
        implementation += Code(Variable("((u64*)"), curry, Variable(")[2]"), ASSIGN_VAR, curry+Variable("__buffer_capacity"), SEMICOLON_VAR);
        implementation += Code(curry+Variable("__buffer_contents"), ASSIGN_VAR, Variable("(ptr)(((u64*)"), curry, Variable(")[0])"), SEMICOLON_VAR);

        vars[fail_var] = types.vars[LABEL_VAR];
        implementation += Code(token_if, Variable("!"), curry+Variable("__buffer_contents"), token_goto, fail_var, SEMICOLON_VAR);
        errors += Code(fail_var, token_print, token_failsafe);

        implementation += Code(Variable("} else "));
        implementation += Code(curry+Variable("__buffer_contents"), ASSIGN_VAR, Variable("(ptr)(((u64*)"), curry, Variable(")[0])"), SEMICOLON_VAR);

        // finally, update size
        implementation += Code(Variable("((u64*)"), curry, Variable(")[1]"), ASSIGN_VAR, curry+Variable("__buffer_size"), PLUS_VAR, amount, SEMICOLON_VAR);

        return next_var(imp, p, raw_var, types);
    }


    if(first_token=="on") {
        if(curry.exists()) 
            imp->error(p, "Cannot curry onto `on`");
        if(active_context.exists()) 
            imp->error(p, "There is already an active context in this implementation\nEnd its code block to enter a new context with `on`.");
        string next = imp->at(p++);
        active_context = parse_expression(imp,p,next,types,curry);
        if(!active_context.exists() || !contains(active_context)) 
            imp->error(--p, "Expression does not evaluate to a variable to use as `on` context");
        if(vars[active_context]->noassign && !imp->allow_unsafe)
            imp->error(--p, "Cannot use as en `on` context a variable marked as @noassign\nThis is considered unsafe behavior and can only be enabled with @unsafe");
        Variable temp = create_temp();
        Variable finally_var = temp+Variable("on");
        vars[finally_var] = types.vars[LABEL_VAR];
        //int on_start = p-1;
        uplifting_targets.push_back(finally_var);
        if(uplifiting_is_loop.size()) 
            uplifiting_is_loop.push_back(uplifiting_is_loop.back());
        else 
            uplifiting_is_loop.push_back(false);
        parse(imp, p, types, false);
        uplifting_targets.pop_back();
        uplifiting_is_loop.pop_back();
        p++;
        Variable var = finally_var+Variable("r");
        if(!contains(var)) 
            var = EMPTY_VAR;
        implementation +=Code(finally_var,COLON_VAR);
        active_context = EMPTY_VAR;
        return var;
    }
    if(first_token=="with") { // TODO: this implementation does not account for nesting
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

    if(is_primitive(first_token.to_string())) {
        string vartype = type_primitive(first_token.to_string());
        string defval = "0";
        if(p<imp->size() && imp->at(p)=="@" && imp->at(p+1)=="else") {
            defval = imp->at(p+2);
            p += 3;
            if(type_primitive(defval)!=vartype) 
                imp->error(p-1, "Required "+vartype+" primitive");
        }
        string var = create_temp();
        if(!types.contains(vartype)) return first_token;// fallback
        vars[var] = types.vars[vartype];
        // vardecl += vartype+" "+var+" = "+defval+";\n"; // always set vars to zero because they may reside in if blocks
        implementation += Code(var,ASSIGN_VAR,first_token.to_string(),SEMICOLON_VAR);
        //mutables.insert(var);
        return next_var(imp, p, var, types);
    }
    if(contains(first_token)) {
        if(curry.exists()) 
            imp->error(p, "Expecting runtype but got variable: "
                +first_token.to_string()
            );
        return next_var(imp, p, first_token, types); //ASSIGNMENT TO ALREADY EXISTING VARIABLE
    }
    if(types.contains(first_token)) {
        auto type = types.vars.find(first_token)->second;
        Variable surface = EMPTY_VAR;
        if(p<imp->size()-1 && imp->at(p)=="[") {
            p++;
            if(imp->at(p)!="]") {
                string next = imp->at(p);
                p++;
                surface = parse_expression(imp, p, next, types, EMPTY_VAR);
                if(!contains(surface) || !vars[surface]->buffer_ptr.exists())
                    imp->error(--p, "Given that "
                        +first_token.to_string()
                        +" is a runtype (not a local variable), [] is expected to declare a buffer here"
                        +" or a @buffer runtype must be returned to serve as the buffer's allocation"
                    );
                if(!can_mutate(surface) && !imp->allow_unsafe)
                    imp->error(--p, "Buffer surface is not mutable: "+pretty_var(surface.to_string())+"\nIt might have been used elsewhere. Mark this file as @unsafe to allow a union view.");
            }
            p++;
            if(type->options.size()==0) 
                imp->error(--p, "No options to determine buffer elements "
                    +type->name.to_string()
                    +"\nAdding before the argument's type may resolve this issue"
                    +"\nby forcing usage of the a runtype with ->in its return"
                    +"\namong those overloaded with the same name/union."
                    +"\nThis annoation directly interleaves the type in the definition"
                    +"\nand removes its lexical scoping."
                );
            double option_power = -1;
            int conflicts = 0;
            auto original_type = type;
            for(const auto& it : type->options) {
                if(it->choice_power>option_power) {// && it->name==argType->name) {
                    option_power = it->choice_power;
                    type = it;
                    conflicts = 0;
                }
                else if(it->choice_power==option_power) 
                    conflicts++;
            }
            if(option_power<0) 
                imp->error(--p, "No resolution options for determining buffer elements: "
                    +original_type->name.to_string()
                );
            if(conflicts) 
                imp->error(--p, "There was no criterion for resolving buffer element to one option: "
                    +original_type->name.to_string()
                    +"\nMultiple options are available"
                );
        
            Variable var = create_temp();
            mutables.insert(var);
            Variable dynamic_var = var+Variable("dynamic");
            Variable surface_var = var+Variable("surface");
            buffer_types[dynamic_var] = type;
            vars[var] = types.vars[BUFFER_VAR];
            vars[dynamic_var] = types.vars[PTR_VAR];
            //vars[var+Variable("surface")] = types.vars[PTR_VAR];
            Variable raw_var = var;
            var = dynamic_var;
            implementation += Code(
                var,
                ASSIGN_VAR,
                Variable("__runtime_calloc(3*sizeof(u64))"),
                SEMICOLON_VAR
            ); // ZERO OUT MEMORY, SIZE, CAPACITY (MSB of capacity holds whether the buffer is statically initialized)
            if(surface.exists()) {
                size_t count_packs = 0;
                for(const auto& pack : type->packs)
                    if(type->contains(pack) && type->vars[pack]->name!=NOM_VAR)
                        count_packs++;
                if(type->_is_primitive) 
                    count_packs++;
                implementation += Code(
                    Variable("((u64*)"),var,Variable(")[0]"), 
                    ASSIGN_VAR, Variable("(u64)(u64*)"), 
                    surface+vars[surface]->buffer_ptr, 
                    SEMICOLON_VAR
                );
                implementation += Code(
                    Variable("((u64*)"),
                    var,
                    Variable(")[2]"), 
                    ASSIGN_VAR, 
                    LPAR_VAR,
                    surface+vars[surface]->buffer_size, 
                    Variable("/(sizeof(u64)*"+to_string(count_packs)+")) | (1ULL <<63)"), 
                    SEMICOLON_VAR
                );
                finals[var] += Code(
                    token_if, var, RPAR_VAR,
                    Variable("__runtime_free("),var,RPAR_VAR,SEMICOLON_VAR,
                    var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR
                );
                assign_variable(
                    types.vars[PTR_VAR], 
                    surface_var, 
                    surface+vars[surface]->buffer_release, 
                    imp, 
                    p
                );

                // returning simplifcations may split the memory poiters into two independent sets of finals that reference the same memory - gather in one place
                coallesce_finals(surface+vars[surface]->buffer_ptr);
                coallesce_finals(surface+vars[surface]->buffer_release);
                finals[surface_var] = 
                        rename_var(finals[surface+vars[surface]->buffer_ptr], surface+vars[surface]->buffer_ptr, surface_var)
                        +rename_var(finals[surface+vars[surface]->buffer_release], surface+vars[surface]->buffer_release, surface_var);
                finals[surface+vars[surface]->buffer_ptr] = Code();
                finals[surface+vars[surface]->buffer_release] = Code();
            }
            else {
                assign_variable(
                    types.vars[PTR_VAR], 
                    surface_var,
                    ZERO_VAR, 
                    imp, 
                    p
                );
                finals[var] += Code(
                    token_if, var, Variable("){if((u64*)((u64*)"),var,Variable(")[2])"), // deallocate only if we have allocated any capacity
                    Variable("__runtime_free((u64*)((u64*)"),var,Variable(")[0])"),SEMICOLON_VAR,
                    Variable("__runtime_free("),var,RPAR_VAR,SEMICOLON_VAR,
                    var,ASSIGN_VAR,ZERO_VAR,SEMICOLON_VAR,
                    Variable("}"));
            }
            return next_var(imp, p, raw_var, types);
        }
        vector<Variable> unpacks;
        if(p>=imp->size()-1) {
            if(curry.exists()) {
                if(!contains(curry)) 
                    imp->error(first_token_pos-2, "Not found: "+pretty_var(curry.to_string())+recommend_runtype(types, curry));
                else if(vars.find(curry)->second->not_primitive()) {
                    for(const Variable& pack : vars.find(curry)->second->packs) unpacks.push_back(curry.to_string()+"__"+pack.to_string());
                }
                else 
                    unpacks.push_back(curry);
            }
        }
        else if(imp->at(p)=="__consume") {
            if(!curry.exists()) imp->error(p-2, "Unexpected usage of operator\nThere is no left-hand-side");
            if(!contains(curry)) imp->error(first_token_pos-2, "Not found: "+pretty_var(curry.to_string())+recommend_runtype(types, curry));
            else if(vars.find(curry)->second->not_primitive()) {
                for(const Variable& pack : vars.find(curry)->second->packs) 
                    unpacks.push_back(curry+pack);
            }
            else 
                unpacks.push_back(curry);
            p++;
            string next = imp->at(p++);
            Variable rhs = parse_expression(imp, p, next, types);
            if(!contains(rhs)) 
                imp->error(--p, "Failed to parse the right-hand-side of "+first_token.to_string());
            const auto& rhsType = vars.find(rhs)->second;
            if(rhsType->_is_primitive) 
                unpacks.push_back(rhs);
            else if(type->is_service) {
                Variable fail_var = create_temp();
                if(active_calls[rhs].exists() && active_calls[active_calls[rhs]].exists()) {
                    const Variable& call_var = active_calls[rhs];
                    implementation += Code(Variable("__smolambda_task_wait"),LPAR_VAR,call_var+TASK_VAR,RPAR_VAR,SEMICOLON_VAR);
                    vars[rhs+ERR_VAR] = types.vars[ERRCODE_VAR];
                    implementation += Code(
                        call_var+ERR_VAR, 
                        ASSIGN_VAR, 
                        call_var+STATE_VAR, 
                        ARROW_VAR, 
                        ERR_VAR, 
                        SEMICOLON_VAR
                    );
                    implementation += Code(
                        rhs+ERR_VAR, 
                        ASSIGN_VAR, 
                        call_var+ERR_VAR,
                        SEMICOLON_VAR
                    );
                    static const Variable token_err1 = Variable(":\nprintf(\"Runtime error from ");
                    static const Variable token_err2 = Variable("\\n\");\n__result__errocode=__UNHANDLED__ERROR;\ngoto __failsafe;\n");
                    implementation += Code(token_if, call_var+ERR_VAR, token_goto, fail_var, SEMICOLON_VAR);
                    errors += Code(fail_var, token_err1, rhsType->name, call_var, token_err2);
                    add_preample("#include <stdio.h>");
                }
                for(size_t i=1;i<rhsType->packs.size();++i)
                    unpacks.push_back(active_calls[rhs]+rhsType->packs[i]);
                for(const auto& it : rhsType->buffer_types)
                    buffer_types[active_calls[rhs]+it.first] = it.second;
                if(active_calls[rhs].exists() && active_calls[active_calls[rhs]].exists())
                    active_calls[active_calls[rhs]] = EMPTY_VAR;
            }
            else 
                for(const Variable& pack : rhsType->packs)
                    unpacks.push_back(rhs+pack);
        }
        else if(imp->at(p)!="(" && curry.exists()) {
            if(!contains(curry)) 
                imp->error(first_token_pos-2, "Not found: "
                    +pretty_var(curry.to_string())
                    +recommend_runtype(types, curry)
                );
            else if(vars.find(curry)->second->not_primitive()) {
                for(const Variable& pack : vars.find(curry)->second->packs) 
                    unpacks.push_back(curry.to_string()+"__"+pack.to_string());
            }
            else unpacks.push_back(curry);
        }
        else if(imp->at(p)==")" || imp->at(p)=="]" || imp->at(p)=="," || imp->at(p)==":"){// || imp->at(p)=="and" || imp->at(p)=="or" 
            //|| types.vars.find(imp->at(p))!=types.vars.end() || (imp->at(p)=="-" && p<imp->size()-1 && (imp->at(p+1)=="-" || imp->at(p+1)==">"))) {
            int num_choices = 0;
            int highest_choice_power = 0;
            if(parametric_types.find(type->name)!=parametric_types.end()) 
                type = parametric_types[type->name];
            string candidates("");
            for(const auto& option : type->get_options(types)) {
                if(option->choice_power>highest_choice_power) {
                    highest_choice_power = option->choice_power;
                    num_choices = 0;
                    candidates = "";
                }
                if(option->choice_power<highest_choice_power) 
                    continue;
                num_choices ++;
                type = option;
                candidates += "\n"+option->signature(types);
            }

            if(num_choices==0) 
                imp->error(--p, "Overloaded or union runtype has no alternative");
            if(num_choices!=1) {
                if(!highest_choice_power) 
                    imp->error(--p, "Overloaded or union runtype names are ambiguous."
                        "\nConsider defining exactly one of them as nominal (with nom first argument)"
                        "\nto break the priority stalemate."
                        "\nCandidates:"+candidates
                    );
                else 
                    imp->error(--p, "Overloaded or union runtype names are ambiguous."
                        "\nYou have already defined several of those as nominal (with nom first argument)."
                        "\nCandidates:"+candidates
                    );
            }
            
            if(type->not_primitive()) for(size_t i=0;i<type->args.size();++i) {
                Variable var = create_temp();
                if(p<imp->size()-1 && imp->at(p+1)=="&") 
                    mutables.insert(var);
                assign_variable(type->args[i].type, var+type->args[i].name, ZERO_VAR, imp, first_token_pos, true);
                type_trackers.insert(var);
                unpacks.push_back(var+type->args[i].name);
            }
            else {
                string var = create_temp();
                if(p<imp->size()-1 && imp->at(p+1)=="&") 
                    mutables.insert(var);
                assign_variable(type, var, ZERO_VAR, imp, first_token_pos, true);
                type_trackers.insert(var);
                unpacks.push_back(var);
            }
        }
        else if(((p<imp->size()-1 && imp->at(p)!="(" && (imp->at(p+1)==")" || imp->at(p+1)==",")) || (p<imp->size()-2 && imp->at(p)=="&" && imp->at(p+1)!="(" && (imp->at(p+2)==")" || imp->at(p+2)==",")))){
            Variable var = imp->at(p++);
            if(var==REF_VAR) {
                var = imp->at(p++);
                mutables.insert(var);
            }
            if(contains(var)) 
                imp->error(--p, "Cannot redeclare local variable "+vars[var]->name.to_string()+" "+pretty_var(var.to_string()));
            if(parametric_types.find(type->name)!=parametric_types.end()) 
                type = parametric_types[type->name];
            int num_choices = 0;
            int highest_choice_power = 0;
            string candidates("");
            for(const auto& option : type->get_options(types)) {
                if(option->choice_power>highest_choice_power) {
                    highest_choice_power = option->choice_power;
                    num_choices = 0;
                    candidates = "";
                }
                if(option->choice_power<highest_choice_power) continue;
                num_choices ++;
                type = option;
                candidates += "\n"+option->signature(types);
            }
            if(num_choices==0) 
                imp->error(--p, "Overloaded or union runtype has no alternative");
            if(num_choices!=1) {
                if(!highest_choice_power) 
                    imp->error(--p, "Overloaded or union runtype names are ambiguous."
                        "\nConsider defining exactly one of them as nominal (with nom first argument)"
                        "\nto break the priority stalemate."
                        "\nCandidates:"+candidates
                    );
                else 
                    imp->error(--p, "Overloaded or union runtype names are ambiguous."
                        "\nYou have already defined several of those as nominal (with nom first argument)."
                        "\nCandidates:"+candidates
                    );
            } 
            if(type->not_primitive()) 
                for(size_t i=0;i<type->args.size();++i) {
                    vars[var+type->args[i].name] = type->args[i].type;
                    unpacks.push_back(var+type->args[i].name);
                }
            else 
                unpacks.push_back(var);
            if(type->args.size() && type->args[0].type->name==NOM_VAR) 
                alignments[var+type->args[0].name] = types.alignment_labels[type.get()];
            vars[var] = type;
            return var;
        }
        else if(imp->at(p)!="(") {
            Variable var = create_temp();
            vars[var] = type;
            type_trackers.insert(var);
            if(p<imp->size()-1 && imp->at(p+1)=="&") 
                mutables.insert(var);
            for(const Variable& pack : type->packs) 
                assign_variable(type->vars[pack], var+pack, ZERO_VAR, imp, first_token_pos);
            if(type->args.size() && type->args[0].type->name==NOM_VAR) 
                alignments[var+type->args[0].name] = types.alignment_labels[type.get()];
            return next_var(imp, p, var, types);
        }
        else {
            if(imp->at(p++)!="(") 
                imp->error(--p, "Expecting opening parenthesis");
            unpacks = gather_tuple(imp, p, types, curry);
            if(imp->at(p++)!=")") 
                imp->error(--p, "Expecting closing parenthesis");
        }
        return call_type(imp, p, type, unpacks, first_token_pos, first_token, types);
    }
    if(curry.exists() || (p<imp->size() && (imp->at(p)=="(" || imp->at(p)=="__consume"))) 
        imp->error(--p, "Missing runtype: "
            +first_token.to_string()
            +recommend_runtype(types, first_token)
        );
    return next_var(imp, p, first_token, types);
}
