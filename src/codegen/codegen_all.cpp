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
        auto it = find_if(g_imports.begin(), g_imports.end(), [&](const ImportItem &i){ return i.path==first_file; });
        if(it==g_imports.end()) {
            g_imports.push_back({first_file, ImportStatus::Requested, nullptr});
            g_importCv.notify_all();
        }
    }

    // --- 2. Launch workers ---
    atomic<bool> global_errors{false};

    auto worker = [&]() { for (;;) {
        unique_lock<mutex> lock(g_importMutex);
        g_importCv.wait(lock, [] {
            return any_of(g_imports.begin(), g_imports.end(), [](auto &i){ return i.status==ImportStatus::Requested; }) ||
                   all_of(g_imports.begin(), g_imports.end(), [](auto &i){ return i.status==ImportStatus::Done; });
        });

        if(none_of(g_imports.begin(), g_imports.end(),
                 [](auto &i){ return i.status == ImportStatus::Requested ||
                                      i.status == ImportStatus::InProgress; }))
            break;
        auto it = find_if(g_imports.begin(), g_imports.end(), [](auto &i){ return i.status==ImportStatus::Requested; });
        if(it==g_imports.end())
            continue;

        auto path = it->path;
        auto halted = string{""};
        auto errors = false;
        it->status = ImportStatus::InProgress;
        lock.unlock();

        codegen(files, path, builtins, selected_task, task_report, halted, errors);
        if(errors)
            global_errors = true;

        if(!halted.empty()) {
            lock_guard<mutex> relock(g_importMutex);
            //cout << path << " -- has incomplete import (will continue later)\n";
            auto it2 = find_if(g_imports.begin(), g_imports.end(),[&](const ImportItem &i){ return i.path==path; });
            if(it2 != g_imports.end()) {
                it2->status = ImportStatus::Requested;
                rotate(it2, it2 + 1, g_imports.end());
            }
            g_importCv.notify_all();
            continue;
        }
        mark_import_done(path, nullptr);
    }};

    unsigned num_workers = max(1u, thread::hardware_concurrency());
    if(worker_limit && worker_limit<num_workers)
        num_workers = worker_limit;
    if(num_workers==1) {
        cout << "Compiling on --workers "+to_string(num_workers)+"\n";
        worker();
        cout << "finished in "+to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t_start).count())+" ms\n";
    }
    else {
        cout << "Compiling on --workers "+to_string(num_workers)+"\n";
        vector<thread> workers;
        for (unsigned i = 0; i < num_workers-1; ++i)
            workers.emplace_back(worker);
        worker(); // don't neglect the current thread
        for (auto &t : workers) 
            t.join();
        cout << "Finished in "+to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t_start).count())+" ms\n";
    }
    return global_errors.load();
}
