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
#include <cmath>

#include <string>
#include <cmath>

string progress_bar(size_t done, size_t total, int width) {
    if (total == 0) 
        return string(width, ' ');
    double frac = static_cast<double>(done) / (double)total;
    int full_cells = static_cast<int>(std::floor(frac * width));
    double remainder = frac * width - full_cells;
    static const char* partials[] = {"", "▏", "▎", "▍", "▌", "▋", "▊", "▉"};
    int eighths = static_cast<int>(std::floor(remainder * 8+0.0025)); // 0.0025 to just help with rounding errors
    string bar;
    bar.reserve(width * 3);
    int cells = 0;
    for (int i = 0; i < full_cells; ++i) {
        bar += "█";
        ++cells;
    }
    if (full_cells < width && eighths > 0) {
        bar += partials[eighths];
        ++cells;
    }
    while (cells < width) {
        bar += ' ';
        ++cells;
    }
    return bar;
}

bool codegen_all(
    map<string, shared_ptr<Types>>& files,
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

    unsigned num_workers = max(1u, thread::hardware_concurrency());
    if(!worker_limit)
        num_workers = 1;
    if (worker_limit && worker_limit < num_workers)
        num_workers = worker_limit;

    atomic<bool> global_errors{false};
    auto worker = [&global_errors, &files, &builtins, &selected_task, &task_report, num_workers, t_start]() {
        for (;;) {
            auto path = string{""};
            auto halted = string{""};
            auto errors = false;
            {
                unique_lock<mutex> lock(g_importMutex);
                if(status_requested.empty() && status_progress.empty()) 
                    break;
                if (g_imports.empty()) {
                    lock.unlock(); 
                    this_thread::sleep_for(chrono::milliseconds(1));
                    continue;
                }
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
                // update progress only once we actually do something
                auto done = status_done.size();
                auto pending = status_requested.size() + status_progress.size();
                auto total = done + pending;
                cout << "\r\033[35mcodegen\033[0m --workers "+to_string(num_workers)
                        +" \033[36m"+progress_bar(done, total, 10)
                        +"\033[0m "+to_string(done)+"/"+to_string(total)
                        +" files  "+to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t_start).count()) + "ms"
                    << std::flush;
            }
        }
    };
    
    cout << "\r\033[35mcodegen\033[0m --workers " << num_workers << " "<<std::flush;
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
    cout << "\n";
    return global_errors.load();
}
