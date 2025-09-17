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
#include "../../../def.h"


Variable Def::parse_buffer_len(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos) {
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