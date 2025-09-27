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

void handle_include(
    map<string, shared_ptr<Types>>& files, 
    string file,
    const Memory& builtins, 
    Task selected_task,
    string& task_report, 
    const shared_ptr<Import>& imp, 
    size_t& p,
    Types& types,
    string& halted,
    bool& errors
) {
    auto prev_progress = p;
    auto path = imp->at(p+=2);
    while(p<imp->size()-1 && imp->at(p+1) == ".") 
        path += "/" + imp->at(p+=2);
    path += ".s";
    // if(!is_import_exists(path)) {
    //     codegen(files, path, builtins, selected_task, task_report, halted, errors);
    //     if(halted.size()) {
    //         return;
    //     }
    // }
    try {
        if(!is_import_done(path)) {
            if(imp->forward_p<=p) {
                imp->forward_p = p+1; // don't repeat this code block while is_import done polls to false, but do repeat it whenever we progress
                auto forward_p = p+1;
                // forwrd look for more imports and add them to the queue if needed
                while(forward_p<imp->size()-2 && imp->at(forward_p)=="@" && imp->at(forward_p+1)=="include") {
                    auto forward_path = imp->at(forward_p+=2);
                    while(forward_p<imp->size()-1 && imp->at(forward_p+1) == ".") 
                        forward_path += "/" + imp->at(forward_p+=2);
                    forward_path += ".s";
                    request_import_if_needed(file, forward_path); // these are batched without calling g_importCv.notify_all(); 
                    forward_p++;
                }
            }
            if(request_import(file, path)) {
                p = prev_progress; // go back to the import statement
                halted = path; // who is blocking
                return;
            }
            else {
                imp->error(p, "Could not open file: " + path);
                return;
            }
        }
    }
    catch(runtime_error& e) {
        imp->error(p, e.what());
        return;
    }

    auto included_file = get_file(files, path);
    auto filter = unordered_set<Variable>{};
    if(p < imp->size() - 1 && imp->at(p + 1) == "-") {
        p += 2;
        if(imp->at(p++) != ">")
            imp->error(--p, "Expecting -> to import specific symbols");
        while(p < imp->size() - 1) {
            if(included_file->vars.find(imp->at(p)) == included_file->vars.end())
                imp->error(p, "Could not import " + imp->at(p) + " from " + path);
            filter.insert(imp->at(p++));
            if(imp->at(p) != ",") {
                --p;
                break;
            }
            p++;
        }
    }

    // unions and @access propagation
    for(const auto& it : included_file->vars)
        if(filter.find(it.first) != filter.end())
            for(const auto& option : it.second->options)
                filter.insert(option->name);
    for(const auto& it : included_file->vars) {
        for(const auto& access : it.second->can_access_mutable_fields)
            if(it.second->contains(access) && filter.find(it.second->vars[access]->name) != filter.end())
                filter.insert(it.second->name);
        for(const auto& option : it.second->options)
            for(const auto& access : option->can_access_mutable_fields)
                if(option->contains(access) && filter.find(option->vars[access]->name) != filter.end()) {
                    filter.insert(option->name);
                    break;
                }
    }

    for(const auto& it : included_file->vars) {
        const Variable& name = it.first;
        if(filter.size() && filter.find(name) == filter.end())
            continue;
        Type impl = it.second;
        if(impl->_is_primitive)
            continue;
        if(!types.contains(name))
            types.vars[name] = impl;
        else if(types.vars[name] != impl) {
            auto def = std::make_shared<Def>(types);
            auto add_unique = [&](const auto& options) {
                for(const auto& option : options)
                    if(!ranges::contains(def->options, option))
                        def->options.push_back(option);
            };
            add_unique(types.vars[name]->options);
            add_unique(impl->options);
            all_types.push_back(def);
            def->imp = imp;
            def->lazy_compile = true;
            def->name = name;
            types.vars[def->name]->pos = p;
            types.vars[name] = def;
            def->assert_options_validity(imp, p);
        }
    }

    for(auto& it : included_file->alignment_labels)
        types.alignment_labels[it.first] = it.second;
    for(auto& it : included_file->reverse_alignment_labels)
        types.reverse_alignment_labels[it.first] = it.second;

    //cout << path+" -- include finished\n";

    if(included_file->all_errors.size() && Def::lsp)
        imp->error(p, "Errors in included file: " + path);
}