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

void handle_install(
    map<string, shared_ptr<Types>>& files, 
    string file,
    const Memory& builtins, 
    Task selected_task,
    string& task_report, 
    const shared_ptr<Import>& imp, 
    size_t& p,
    bool& errors
) {
    auto path = imp->at(p+=2);
    auto test_path = path;
    while(p<imp->size()-1 && imp->at(p+1) == ".") {
        path += "/" + imp->at(p+=2);
        test_path += "." + imp->at(p);
    }
    path += ".s";

    if(selected_task==Task::Compile || selected_task==Task::Run || selected_task==Task::Transpile) {
        if(ranges::none_of(installation_permissions, [&](const string& perm){ return test_path.starts_with(perm); }))
            imp->error(p, "Missing permissions to @install " + test_path +
                          "\nFor example, add this to the compiler: --safe " + test_path);
        cout << "\033[30;43m INSTALL \033[0m " << test_path << "\n";
        int run_status = system((EXEC_PREFIX + ("smol " + path + " --runtime eager")).c_str());
        if(run_status)
            imp->error(p, "Failed to run installer: " + test_path+"\nRequired by: "+file);
    } 
    else if(!filesystem::exists(path))
        imp->error(p, "Missing installer: " + test_path+"\nRequired by: "+file);
    else
        errors |= codegen_all(files, path, builtins, selected_task, task_report);
}

