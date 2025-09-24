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
#include "def.h"
#include "utils/compiler.h"
#include "utils/tasks.h"

using namespace std;
extern vector<string> installation_permissions;

void handle_def_or_service(
    std::map<std::string, Types>& files,
    const std::string& file,
    const Memory& builtins,
    Task selected_task,
    std::string& task_report,
    const shared_ptr<Import>& imp,
    size_t& p,
    Types& types,
    bool& errors);
bool handle_include(
    map<string, Types>& files, string file,
    const Memory& builtins, Task selected_task,
    string& task_report, const shared_ptr<Import>& imp, size_t& p,
    Types& types
);
bool handle_install(map<string, Types>& files, string file,
    const Memory& builtins, Task selected_task,
    string& task_report, const shared_ptr<Import>& imp, size_t& p);
void handle_union(const shared_ptr<Import>& imp, size_t& p, Types& types);
bool codegen(map<string, Types>& files, string file, const Memory& builtins, Task selected_task, string& task_report);

#endif // CODEGEN_H
