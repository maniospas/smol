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
#include "../../def.h"

Variable Def::parse_expression(size_t& p, const Variable& first_token, Types& types, const Variable& curry) {
    auto first_token_pos = p-1;
    if(first_token=="(") {
        Variable ret = parse_expression(p, imp->at(p++), types, curry);
        if(imp->at(p++)!=")") 
            imp->error(first_token_pos, "Expecting closing parenthesis");
        return next_var(p, ret, types);
    }
    return parse_expression_no_par(p, first_token, types, curry);
}

Variable Def::parse_expression_no_par(size_t& p, const Variable& first_token, Types& types, Variable curry) {
    auto first_token_pos = p-1;
    if(first_token=="@") {
        auto next = imp->at(p++);
        if(next=="mut") {
            next = imp->at(p++);
            auto ret = parse_expression_no_par(p, next, types, curry);
            if(!ret.exists() || !contains(ret))
                imp->error(first_token_pos+2, "`@mut` must refer to an existing type");
            mutables.insert(ret);
            return ret;
        }
        if(next!="dynamic")
            imp->error(--p, "Unexpected symbol\nCannot have a preprocessor directive other than `@dynamic` in the middle of an expression.");
        auto options = vector<Variable>{};
        if(imp->at(p++)!="(")
            imp->error(--p, "Expected opening parenthesis after `@dynamic` to determine options");
        if(curry.exists())
            imp->error(--p, "Cannot curry into `@dynamic`");
        next = imp->at(p++);
        while(next!=")") {
            if(!types.contains(next))
                imp->error(--p, "Function name is still unknown at this point");
            options.push_back(next);
            next = imp->at(p++);
            if(next!=")" && next!=",")
                imp->error(--p, "Expected closing parenthesis or comma");
            if(next==",")
                next = imp->at(p++);
        }   
        if(!options.size())
            imp->error(--p, "There are no options in `@dynamic()`\nAdd comma-separated function names of allowed alternatives in the parenthesis");
        
        next = imp->at(p++);
        auto caller = next_var(p, next, types);
        if(!contains(caller))
            imp->error(--p, "Missing variable: "+pretty_var(caller.to_string()));
        bool has_tag = false;
        if(vars[caller]->name==Variable("tag"))
            has_tag = true;
        if(vars[caller]->packs.size() && vars[caller]->vars[vars[caller]->packs[0]]->name==Variable("tag"))
            has_tag = true;
        if(!has_tag)
            imp->error(--p, "`@dynamic` can only be applied to a `tag` variable, but found: "+pretty_runtype(vars[caller]->name.to_string()));

        auto return_var = EMPTY_VAR;
        auto end_var = Variable(create_temp());
        vars[end_var] = types.vars[LABEL_VAR];
        if(imp->at(p++)!="(")
            imp->error(--p, "Expecting opening parenthesis");
        auto unpacks = gather_tuple(p, types, EMPTY_VAR);
        if(imp->at(p++)!=")")
            imp->error(--p, "Expecting closing parenthesis");

        for(size_t pos=1;pos<vars[caller]->packs.size();++pos) 
            unpacks.insert(unpacks.begin()+(pos-1), caller+vars[caller]->packs[1]);
        if(vars[caller]->packs.size())
            caller = caller+vars[caller]->packs[0];

        for(const auto& option : options) {
            auto skip_var = Variable(create_temp());
            vars[skip_var] = types.vars[LABEL_VAR];
            implementation += Code(token_if, caller, Variable("!="), Variable(to_string(Def::get_symbol(option))), token_goto, skip_var, SEMICOLON_VAR);
            auto outcome = call_type(p, types.vars[option], unpacks, first_token_pos, option, types);
            if(outcome.exists() && contains(outcome)) {
                if(!return_var.exists()) {
                    return_var = Variable{create_temp()};
                    mutables.insert(return_var);
                }
                assign_variable(types.vars[option], return_var, outcome, p);
            }
            implementation += Code(Variable("goto"), end_var, SEMICOLON_VAR);
            implementation += Code(skip_var, COLON_VAR);
        }
        implementation += Code(Variable("printf(\"An unforeseen dynamic option was encountered\\n\");\n__result__error_code=__DYNAMIC__ERROR;\ngoto __failsafe;\n"));
        implementation += Code(end_var, COLON_VAR);
        
        return return_var;
    }

    if(first_token==DOT_VAR 
        || first_token==LBRACKET_VAR 
        || first_token==RBRACKET_VAR 
        || first_token==ASSIGN_VAR
        || first_token=="{" 
        || first_token=="}" 
        || first_token==";"
        || first_token=="and"
        || first_token=="or"
        //|| first_token=="@"
        || first_token=="union"
        || first_token=="def"
        || first_token=="service"
    ) 
        imp->error(p-1, "Unexpected symbol\nThe previous expression already ended.");
    if(first_token=="if") 
        return parse_if(p, types, curry, first_token_pos);
    if(first_token=="while") 
        return parse_while(p, types, curry, first_token_pos);
    if(first_token=="case") 
        return parse_with(p, types, curry, first_token_pos);
    if(first_token=="algorithm") {
        if(curry.exists())
            imp->error(--p, "Cannot curry into `algorithm`");
        auto temp = Variable{create_temp()};
        auto finally_var = temp;
        vars[finally_var] = types.vars[LABEL_VAR];
        uplifting.emplace_back(finally_var, uplifting.size(), true, uplifting.size() && uplifting.back().is_loop);
        if(uplifting.size()>=2)
            uplifting[uplifting.size()-1].context = uplifting[uplifting.size()-2].context;
        parse_implementation(p, false);
        p++; // offset p-- after parse_return above
        implementation += Code(finally_var,COLON_VAR);
        uplifting.pop_back();
        if(!contains(finally_var+Variable("r")))
            return EMPTY_VAR;
        return finally_var+Variable("r");
    }
    if(curry.exists() 
        && contains(curry) 
        && vars[curry]->name==BUFFER_VAR
    ) {
        if(first_token=="len")
            return parse_buffer_len(p, types, curry);
        if(first_token=="put")
            return parse_buffer_put(p, types, curry, first_token_pos);
        if(first_token=="push")
            return parse_buffer_push(p, types, curry, first_token_pos);
        if(first_token=="pop")
            return parse_buffer_pop(p, types, curry, first_token_pos);
        if(first_token=="expect")
            return parse_buffer_expect(p, types, curry, first_token_pos);
    }

    if(is_primitive(first_token.to_string())) 
        return parse_primitive(p, first_token, types, curry, first_token_pos);

    if(first_token==Variable(":")) {
        // if(imp->at(p++)!=".")
        //     imp->error(--p, "Expecting syntax tag.name in function bodies");
        auto symbol = imp->at(p++);
        auto var = Variable{create_temp()};
        vars[var] = types.vars[Variable("tag")];
        // vardecl += vartype+" "+var+" = "+defval+";\n"; // always set vars to zero because they may reside in if blocks
        implementation += Code(var,ASSIGN_VAR,to_string(get_symbol(symbol)),SEMICOLON_VAR);
        return next_var(p, var, types);
    }

    if(contains(first_token)) {
        if(curry.exists()) 
            imp->error(p, "Expecting runtype but got variable: "
                +first_token.to_string()
            );
        return next_var(p, first_token, types); //ASSIGNMENT TO ALREADY EXISTING VARIABLE
    }
    if(first_token=="@" && p<imp->size() && imp->at(p)=="mut") {
        p++;
        if(p >= imp->size()) 
            imp->error(--p, "Expecting runtype after @mut");
        Variable runtype = imp->at(p++); 
        if(!types.contains(runtype))
            imp->error(--p, "Unknown runtype after @mut: " + runtype.to_string());
        Variable var = parse_expression(p, runtype, types, EMPTY_VAR);
        mutables.insert(var);
        type_trackers.insert(var);
        return  var;
    }
    if(types.contains(first_token) || first_token==name) 
        return parse_runtype(p, first_token, types, curry, first_token_pos);

    // parse symbol calls
    // if(p<imp->size() && imp->at(p)=="(" 
    //     && curry.exists()
    //     && first_token.exists() 
    //     && contains(curry+first_token) 
    //     && vars[curry+first_token]->name=="tag"
    // ) {
    //     imp->error(--p, "Not implemented yet");
    // }

    // parse normal variables
    // if(curry.exists() && (p<imp->size() && (imp->at(p)=="(" || imp->at(p)=="__consume"))) 
    //     imp->error(--p, "Missing runtype: "
    //         +first_token.to_string()
    //         +recommend_runtype(types, first_token)
    //     );
    if(curry.exists())
        return next_var(p, curry+first_token, types);
    return next_var(p, first_token, types);
}
