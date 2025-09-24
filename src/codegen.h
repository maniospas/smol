#ifndef CODEGEN_H
#define CODEGEN_H

#include <string>
#include <vector>
#include <map>
#include <stack>
#include <ranges>
#include <fstream>
#include <filesystem>
#include <unordered_set>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>

#include <queue>
#include "def.h"
#include "utils/compiler.h"
#include "utils/tasks.h"

using namespace std;
extern vector<string> installation_permissions;
extern unsigned worker_limit;

enum class ImportStatus { Requested, Done, InProgress };

struct ImportItem {
    string path;
    ImportStatus status;
    shared_ptr<Import> imp;
};

extern mutex g_importMutex;
extern condition_variable g_importCv;
extern vector<ImportItem> g_imports;

void handle_def_or_service(
    map<string, Types>& files,
    const string& file,
    const Memory& builtins,
    Task selected_task,
    string& task_report,
    const shared_ptr<Import>& imp,
    size_t& p,
    Types& types,
    bool& errors
);
void handle_include(
    map<string, Types>& files, string file,
    const Memory& builtins, Task selected_task,
    string& task_report, const shared_ptr<Import>& imp, size_t& p,
    Types& types,
    string& halted,
    bool& errors
);
void handle_install(
    map<string, Types>& files, 
    string file,
    const Memory& builtins, 
    Task selected_task,
    string& task_report, 
    const shared_ptr<Import>& imp, 
    size_t& p,
    bool& errors
);
void handle_union(
    const shared_ptr<Import>& imp, 
    size_t& p, 
    Types& types
);
void codegen(
    std::map<std::string, Types>& files,
    std::string file,
    const Memory& builtins,
    Task selected_task,
    std::string& task_report,
    string& halted,
    bool& errors
);

bool is_import_done(const string &path);
void request_import(const string &path);
void mark_import_done(const string &path, shared_ptr<Import> imp);
void worker_loop();

bool codegen_all(
    std::map<std::string, Types>& files,
    std::string first_file,
    const Memory& builtins,
    Task selected_task,
    std::string& task_report
);


#endif // CODEGEN_H
