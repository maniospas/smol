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

extern unordered_set<string> status_requested;
extern unordered_set<string> status_done;
extern unordered_set<string> status_progress;
extern queue<string> g_imports;
extern mutex g_importMutex;

void handle_def_or_service(
    const shared_ptr<Import>& imp,
    size_t& p,
    Types& types
);
void handle_include(
    map<string, shared_ptr<Types>>& files, 
    string file,
    const shared_ptr<Import>& imp, 
    size_t& p,
    Types& types,
    string& halted
);
void handle_install(
    map<string, shared_ptr<Types>>& files, 
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
    map<string, shared_ptr<Types>>& files,
    string file,
    const Memory& builtins,
    Task selected_task,
    string& task_report,
    string& halted,
    bool& errors
);

bool is_import_done(const string &path);
bool request_import(const string &from, const string &path); // true if it was requested or already there, false if the file does not exist
void request_import_if_needed(const string &from, const string &path);
void mark_import_done(const string &path);
void worker_loop();

bool codegen_all(
    map<string, shared_ptr<Types>>& files,
    string first_file,
    const Memory& builtins,
    Task selected_task,
    string& task_report
);
shared_ptr<Types> get_file(map<string, shared_ptr<Types>>& files, string file);


#endif // CODEGEN_H
