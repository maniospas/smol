#include "../codegen.h"

bool handle_install(map<string, Types>& files, string file,
                           const Memory& builtins, Task selected_task,
                           string& task_report, const shared_ptr<Import>& imp, size_t& p) {
    p += 2;
    string found;
    string path = imp->at(p);
    string test_path = path;
    while(p < imp->size() - 1 && imp->at(p + 1) == ".") {
        p += 2;
        path += "/" + imp->at(p);
        test_path += "." + imp->at(p);
    }
    path += ".s";
    if(selected_task == Task::Compile || selected_task == Task::Run || selected_task == Task::Transpile) {
        for (const auto& it : installation_permissions)
            if (test_path.rfind(it, 0) == 0) {
                found = it;
                break;
            }
        if (found.empty())
            imp->error(p, "Missing permissions to @install " + test_path +
                          "\nFor example, allow std scipts with: --safe std"
                          "\nIn this case, add this to the compiler: --safe " + test_path);
        cout << "\033[30;43m INSTALL \033[0m " << test_path << "\n";
        int run_status = system((EXEC_PREFIX + ("smol " + path + " --runtime eager")).c_str());
        if (run_status)
            imp->error(p, "Failed to run installer: " + test_path);
    } 
    else if (!filesystem::exists(path))
        imp->error(p, "Missing installer: " + test_path);
    else
        return codegen(files, path, builtins, selected_task, task_report);

    return false;
}

