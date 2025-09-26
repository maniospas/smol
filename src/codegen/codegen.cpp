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

static bool handle_about(Import* imp, size_t& p) {
    auto next = imp->at(p+=2);
    if(next[0]=='"') 
        imp->about = next;
    else {
        ++p;
        auto desc = imp->at(p);
        if(desc[0] != '"')
            imp->error(p-2, "Wrong `@about` syntax\nEither `@about \"description\"` or @about name \"description\" are expected");
        imp->docs[next] = desc;
    }
    return false;
}

unsigned worker_limit = 0;

shared_ptr<Types> get_file(map<string, shared_ptr<Types>>& files, string file) {
    unique_lock<mutex> lock(g_importMutex);
    auto ret = files[file];
    if(!ret) {
        ret = make_shared<Types>();
        files[file] = ret;
    }
    return ret;
}

void codegen(
    map<string, shared_ptr<Types>>& files, 
    string file,
    const Memory& builtins, 
    Task selected_task,
    string& task_report,
    string& halted,
    bool& errors
) { 
    auto types_ref = get_file(files, file);
    auto& types = *types_ref;
    auto already_tokenized = (bool)types.imp;
    auto imp = already_tokenized?types.imp:tokenize(file);
    if(!already_tokenized) {
        types.imp = imp;
        for(const auto& it : builtins.vars)
            types.vars[it.first] = it.second;
    }

    auto& p = imp->parse_progress;
    if(p>=imp->size()-1) {
        //cout << file+" -- ALREADY PARSED\n";
        return;
    }
    // if(p)
    //     cout << file+" -- continuing from "+imp->at(imp->parse_progress)+imp->at(imp->parse_progress+1)+"\n";
    // else
    //     cout << file+" -- tokenized and parsing\n";

    auto warnings = size_t{0};
    if(imp->tokens.size())
        while(p < imp->tokens.size() - 1) {
            try {
                if(imp->at(p)=="@" && imp->at(p + 1)=="unsafe") {
                    imp->allow_unsafe = true;
                    ++p;
                }
                else if(imp->at(p)=="@" && imp->at(p+1)=="about")
                    errors |= handle_about(imp.get(), p);
                else if(imp->at(p)=="@" && imp->at(p+1)=="install")
                    handle_install(files, file, builtins, selected_task, task_report, imp, p, errors);
                else if(imp->at(p)=="@" && imp->at(p+1)=="include") {
                    handle_include(files, file, builtins, selected_task, task_report, imp, p, types, halted, errors);
                    if(halted.size()) 
                        return;
                }
                else if(imp->at(p)=="def" || imp->at(p)=="service")
                    handle_def_or_service(files, file, builtins, selected_task, task_report, imp, p, types, errors);
                else if(imp->at(p)=="union")
                    handle_union(imp, p, types);
                else
                    imp->error(p, "Unexpected token\nOnly `service`, `smo`, `union`, `@include`, `@install`, `@about`, or `@unsafe` allowed");
                p++;
            }
            catch (const runtime_error& e) {
                warnings++;
                string message = e.what();
                string preample = message;
                if(!Def::lsp)
                    preample = message.substr(0, message.find('\n'));
                if(types.all_errors.find(preample)==types.all_errors.end())
                    types.all_errors[preample] += message.substr(message.find('\n'));
                else
                    types.suppressed[preample] += 1;
                while(p < imp->size() - 1) {
                    p++;
                    if(imp->at(p)=="def" || imp->at(p)=="union" || imp->at(p)=="service") break;
                    if(imp->at(p)=="@" && p < imp->size() - 1 && imp->at(p + 1)=="include") break;
                    if(imp->at(p)=="@" && p < imp->size() - 1 && imp->at(p + 1)=="install") break;
                    if(imp->at(p)=="@" && p < imp->size() - 1 && imp->at(p + 1)=="unsafe") break;
                    if(imp->at(p)=="@" && p < imp->size() - 1 && imp->at(p + 1)=="about") break;
                }
                if(p >= imp->size() - 1) break;
            }
        }

    for(const auto& err : types.all_errors) {
        cerr << err.first;
        if(types.suppressed.find(err.first) != types.suppressed.end())
            cerr << "\033[33m -- " << types.suppressed[err.first] << " similar errors in this file\033[0m";
        if(!Def::lsp)
            cerr << err.second;
        cerr << "\n";
        errors = true;
    }

    if(!Def::lsp) {
        if(imp->allow_unsafe && imp->about.empty())
            imp->about = "\"Unsafe code without description at " + imp->path + "\"";
        else if(imp->about.empty())
            imp->about = "\"" + imp->path + "\"";
        if(selected_task==Task::Verify && warnings)
            task_report += "\033[30;41m " + string(warnings < 10 ? " " : "") + to_string(warnings) + " ERRORS \033[0m " + file + "\n";
        else if(selected_task==Task::Verify)
            task_report += "\033[30;42m OK \033[0m " + file + "\n";
    }
}

