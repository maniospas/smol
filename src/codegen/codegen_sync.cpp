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
#include <filesystem>
#include <unordered_set>

namespace fs = std::filesystem;

vector<string> installation_permissions;
mutex g_importMutex;
queue<string> g_imports;

// NEW global sets replacing the old status enum
unordered_set<string> status_requested;
unordered_set<string> status_progress;
unordered_set<string> status_done;

bool is_import_done(const string &path) {
    lock_guard<mutex> lock(g_importMutex);
    return status_done.find(path)!=status_done.end();
}

bool request_import(const string &path) {
    lock_guard<mutex> lock(g_importMutex);
    if(status_done.find(path)!=status_done.end()) return true;
    if(status_requested.find(path)!=status_requested.end()) return true;
    if(status_progress.find(path)!=status_progress.end()) return true;
    if (!fs::is_regular_file(path))
        return false;
    g_imports.push(path);
    status_requested.insert(path);
    return true;
}

void request_import_if_needed(const string &path) {
    lock_guard<mutex> lock(g_importMutex);
    if(status_done.find(path)!=status_done.end()) return;
    if(status_requested.find(path)!=status_requested.end()) return;
    if(status_progress.find(path)!=status_progress.end()) return;
    g_imports.push(path);
    status_requested.insert(path);
}

void mark_import_done(const string &path) {
    lock_guard<mutex> lock(g_importMutex);
    status_progress.erase(path);
    status_requested.erase(path);
    status_done.insert(path);
}
