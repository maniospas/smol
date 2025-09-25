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

namespace fs = std::filesystem;

vector<string> installation_permissions;
mutex g_importMutex;
condition_variable g_importCv;
vector<ImportItem> g_imports;

bool is_import_done(const string &path) {
    lock_guard<mutex> lock(g_importMutex);
    for (auto &item : g_imports)
        if(item.path==path)
            return item.status==ImportStatus::Done;
    return false;
}

bool request_import(const string &path) {
    lock_guard<mutex> lock(g_importMutex);
    auto it = find_if(g_imports.begin(), g_imports.end(), [&](const ImportItem &i){ return i.path==path; });
    if(it==g_imports.end()) {
        if (!fs::is_regular_file(path))
            return false;
        g_imports.push_back({path, ImportStatus::Requested, nullptr});
        g_importCv.notify_all(); // wake up any worker polling
    }
    return true;
}

void mark_import_done(const string &path, shared_ptr<Import> imp) {
    lock_guard<mutex> lock(g_importMutex);
    for (auto &item : g_imports) {
        if(item.path==path) {
            item.status = ImportStatus::Done;
            item.imp = imp;
            g_importCv.notify_all();
            return;
        }
    }
}
