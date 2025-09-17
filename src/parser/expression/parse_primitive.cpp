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


Variable Def::parse_primitive(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos) {
    if(curry.exists())
        imp->error(p-1, "Primitive is not callable.");
    string vartype = type_primitive(first_token.to_string());
    string defval = "0";
    if(p<imp->size() && imp->at(p)=="@" && imp->at(p+1)=="else") {
        defval = imp->at(p+2);
        p += 3;
        if(type_primitive(defval)!=vartype) 
            imp->error(p-1, "Required "+vartype+" primitive");
    }
    string var = create_temp();
    if(!types.contains(vartype)) 
        return first_token;// fallback
    vars[var] = types.vars[vartype];
    // vardecl += vartype+" "+var+" = "+defval+";\n"; // always set vars to zero because they may reside in if blocks
    implementation += Code(var,ASSIGN_VAR,first_token.to_string(),SEMICOLON_VAR);
    //mutables.insert(var);
    return next_var(imp, p, var, types);
}