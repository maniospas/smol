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
#include <chrono>  

bool codegen_all(
    map<string, Types>& files,
    string first_file,
    const Memory& builtins,
    Task selected_task,
    string& task_report
) {
    auto t_start = chrono::steady_clock::now();
    {
        lock_guard<mutex> lock(g_importMutex);
        g_imports.push(first_file);
        status_requested.insert(first_file);
    }

    atomic<bool> global_errors{false};

    auto worker = [&]() {
        for (;;) {
            auto path = string{""};
            auto halted = string{""};
            auto errors = false;
            {
                unique_lock<mutex> lock(g_importMutex);
                if(status_requested.empty() && status_progress.empty()) 
                    break;
                if(!g_imports.size())
                    continue;
                path = g_imports.front();
                g_imports.pop();
            }
            codegen(files, path, builtins, selected_task, task_report, halted, errors);
            if (errors) 
                global_errors = true;

            {
                unique_lock<mutex> lock(g_importMutex);
                status_progress.erase(path);
                if (!halted.empty()) {
                    status_requested.insert(path);
                    g_imports.push(path);
                    continue;
                }
                status_requested.erase(path);
                status_progress.erase(path);
                status_done.insert(path);
            }
        }
    };

    unsigned num_workers = max(1u, thread::hardware_concurrency());
    if(!worker_limit)
        num_workers = 1;
    if (worker_limit && worker_limit < num_workers)
        num_workers = worker_limit;

    cout << "Compiling on --workers " + to_string(num_workers) + "\n";
    if (num_workers == 1) 
        worker();
    else {
        vector<thread> workers;
        for (unsigned i = 0; i < num_workers - 1; ++i)
            workers.emplace_back(worker);
        worker(); // also use the current thread
        for (auto &t : workers)
            t.join();
    }
    cout << "Finished in " +
        to_string(chrono::duration_cast<chrono::milliseconds>(
            chrono::steady_clock::now() - t_start).count()) + " ms\n";
    return global_errors.load();
}
