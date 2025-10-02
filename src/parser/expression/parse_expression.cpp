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
    if(first_token=="(") {
        Variable ret = parse_expression(p, imp->at(p++), types, curry);
        if(imp->at(p++)!=")") 
            imp->error(--p, "Expecting closing parenthesis");
        return next_var(p, ret, types);
    }
    return parse_expression_no_par(p, first_token, types, curry);
}

Variable Def::parse_expression_no_par(size_t& p, const Variable& first_token, Types& types, Variable curry) {
    size_t first_token_pos = p-1;
    if(first_token==DOT_VAR 
        || first_token==CURRY_VAR
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
    if(first_token=="on") 
        return parse_on(p, types, curry, first_token_pos);
    if(first_token=="with") 
        return parse_with(p, types, curry, first_token_pos);
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
        if(first_token=="expect")
            return parse_buffer_expect(p, types, curry, first_token_pos);
    }

    if(is_primitive(first_token.to_string())) 
        return parse_primitive(p, first_token, types, curry, first_token_pos);

    if(first_token==Variable("symbol")) {
        if(imp->at(p++)!=".")
            imp->error(--p, "Expecting syntax symbol.name in function bodies");
        auto symbol = imp->at(p++);
        auto var = Variable{create_temp()};
        vars[var] = types.vars[Variable("symbol")];
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
    //     && vars[curry+first_token]->name=="symbol"
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
