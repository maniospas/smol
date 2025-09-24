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
#include "../codegen.h"

void handle_union(const shared_ptr<Import>& imp, size_t& p, Types& types) {
    auto name = imp->at(++p);
    if(types.contains(name))
        imp->error(--p, "Already defined: " + name);

    auto def = make_shared<Def>(types);
    all_types.push_back(def);
    def->imp = imp;
    def->pos = p;
    def->lazy_compile = true;
    def->name = name;
    types.vars[name] = def;
    p++;

    while(true) {
        auto next = imp->at(p++);
        if(next == "-" && imp->at(p++) == "-")
            break;
            
        const auto& found_type = types.vars.find(next);
        if(found_type == types.vars.end())
            imp->error(--p, "Undefined runtype: " + next);

        auto added = false;
        for(const Type& option : found_type->second->options) {
            if(!option->choice_power)
                continue;
            if(option->lazy_compile)
                imp->error(--p, "Internal error: failed to compile runtype " + option->signature(types));
            if(!ranges::contains(def->options, option)) {
                def->options.push_back(option);
                added = true;
            }
        }
        if(!added)
            imp->error(--p, "Missing nominal variation"
                "\nCannot create a runtype union that includes non-nominal types (those would be ignored)"
            );
    }

    def->assert_options_validity(imp, --p);
}
