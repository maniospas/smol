#include "../codegen.h"

using namespace std;

vector<string> installation_permissions;

// bool codegen(map<string, Types>& files, string file, const Memory& builtins, Task selected_task, string& task_report) {
//     auto& types = files[file];
//     if(types.vars.size()) 
//         return false;
//     auto imp = tokenize(file);
//     types.imp = imp;
//     for(const auto& it : builtins.vars) 
//         types.vars[it.first] = it.second;
//     auto imported = unordered_set<string>{};
//     auto p = size_t{0};
//     auto warnings = size_t{0};
//     auto errors = false;
//     if(imp->tokens.size()) while(p<imp->tokens.size()-1) {
//         try {
//             if (imp->at(p) == "@" && imp->at(p + 1) == "unsafe") {
//                 imp->allow_unsafe = true;
//                 p++;
//             }
//             else if (imp->at(p) == "@" && imp->at(p + 1) == "about") {
//                 p += 2;
//                 auto next = imp->at(p);
//                 if(next[0]=='"') imp->about = next;
//                 else {
//                     p++;
//                     auto desc = imp->at(p);
//                     if(desc[0]!='"') imp->error(p-2, "Wrong `@about` syntax\nEither `@about \"description\"` or @about name \"description\" are expected");
//                     imp->docs[next] = desc;
//                 }
//             }
//             else if (imp->at(p) == "@" && imp->at(p + 1) == "install") {
//                 p += 2;
//                 auto found = string{""};
//                 auto path = imp->at(p);
//                 auto test_path = path;
//                 while(p<imp->size()-1 && imp->at(p+1)==".") {
//                     p += 2;
//                     path += "/"+imp->at(p);
//                     test_path += "."+imp->at(p);
//                 }
//                 path += ".s"; 
//                 if(selected_task==Task::Compile || selected_task==Task::Run || selected_task==Task::Transpile) {
//                     for (const auto& it : installation_permissions) 
//                         if (test_path.rfind(it, 0) == 0) { 
//                             found = it;
//                             break;
//                         }
//                     if(found.empty())
//                         imp->error(p, "Missing permissions to @install "+test_path+
//                             "\nFor example, allow std scipts with: --safe std"
//                             "\nIn this case, add this to the compiler: --safe "+test_path);
                    
//                     cout << "\033[30;43m INSTALL \033[0m " << test_path << "\n";
//                     int run_status = system((EXEC_PREFIX+("smol "+path+" --runtime eager")).c_str());
//                     if(run_status) 
//                         imp->error(p, "Failed to run installer: "+test_path);
//                 } 
//                 else if(!filesystem::exists(path))
//                     imp->error(p, "Missing installer: "+test_path);
//                 else
//                     errors = codegen(files, path, builtins, selected_task, task_report) || errors;
//             }
//             else if (imp->at(p) == "@" && imp->at(p + 1) == "include") {
//                 p += 2;
//                 string path = imp->at(p);
//                 while(p<imp->size()-1 && imp->at(p+1)==".") {p += 2;path += "/"+imp->at(p);}
//                 path += ".s";
//                 if(path==file) imp->error(p, "Circular include");
//                 {
//                     ifstream file(path);
//                     if (!file) 
//                         imp->error(p, "Could not open file: " + path);
//                 }
//                 errors = codegen(files, path, builtins, selected_task, task_report) || errors;
//                 unordered_set<Variable> filter;
//                 if(p<imp->size()-1 && imp->at(p+1)=="-") {
//                     p += 2;
//                     if(imp->at(p++)!=">") imp->error(--p, "Expecting -> to import specific symbols");
//                     while(p<imp->size()-1) {
//                         if(files[path].vars.find(imp->at(p))==files[path].vars.end()) imp->error(p, "Could not import "+imp->at(p)+" from "+path);
//                         filter.insert(imp->at(p++));
//                         if(imp->at(p)!=",") {--p;break;}
//                         p++;
//                     }
//                 }
//                 // add unions
//                 for(const auto& it : files[path].vars) 
//                     if(filter.find(it.first)!=filter.end())
//                         for(const auto& option : it.second->options) 
//                             filter.insert(option->name);

//                 // add @access
//                 for(const auto& it : files[path].vars) {
//                     for(const auto& access : it.second->can_access_mutable_fields) 
//                         if(it.second->contains(access) && filter.find(it.second->vars[access]->name)!=filter.end())
//                             filter.insert(it.second->name);
//                     for(const auto& option : it.second->options) 
//                         for(const auto& access : option->can_access_mutable_fields) 
//                             if(option->contains(access) && filter.find(option->vars[access]->name)!=filter.end()) {
//                                filter.insert(option->name);
//                                break;
//                             }
//                 }
//                 for(const auto& it : files[path].vars) {
//                     const Variable& name = it.first;
//                     if(filter.size() && filter.find(name)==filter.end()) 
//                         continue;
//                     Type impl = it.second;
//                     //cout<<file<<" imports "<<path<<" "<<impl->signature(types) << "\n";
//                     if(impl->_is_primitive) 
//                         continue;
//                     if(!types.contains(name)) 
//                         types.vars[name] = impl;
//                     else if(types.vars[name]==impl) {
//                     }
//                     else {
//                         auto def = std::make_shared<Def>(types);
//                         auto add_unique = [&](const auto& options) {
//                             for (const auto& option : options) {
//                                 if (!std::ranges::contains(def->options, option)) 
//                                     def->options.push_back(option);
//                             }
//                         };
//                         add_unique(types.vars[name]->options);
//                         add_unique(impl->options);
//                         all_types.push_back(def);
//                         def->imp = imp;
//                         def->lazy_compile = true;//treat as union
//                         def->name = name;
//                         types.vars[def->name]->pos = p;
//                         types.vars[name] = def;
//                         def->assert_options_validity(imp, p);
//                     }
//                 }
//                 for(auto& it : files[path].alignment_labels) 
//                     types.alignment_labels[it.first] = it.second;
//                 for(auto& it : files[path].reverse_alignment_labels) 
//                     types.reverse_alignment_labels[it.first] = it.second;
//                 if(files[path].all_errors.size()) 
//                     if(Def::markdown_errors) 
//                         imp->error(p, "Errors in included file: "+path);
//                 p++;
//                 continue;
//             }
//             else if(imp->at(p)=="def" || imp->at(p)=="service") {
//                 auto start_p = p;
//                 auto brackets = stack<pair<string, int>> {};
//                 for(;p<imp->size();++p) {
//                     string next = imp->at(p);
//                     if(next=="(" || next=="{" || next=="[") 
//                         brackets.push(make_pair(next, p));
//                     if(next==")") {
//                         if(!brackets.size()) 
//                             imp->error(p, "Never opened parenthesis"); 
//                         if(brackets.top().first!="(") 
//                             imp->error(brackets.top().second, "Never closed parenthesis");
//                         brackets.pop();
//                         continue;
//                     }
//                     if(next=="}") {
//                         if(!brackets.size()) 
//                             imp->error(p, "Never opened bracket "); 
//                         if(brackets.top().first!="{") 
//                             imp->error(brackets.top().second, "Never closed bracket");
//                         brackets.pop();
//                         continue;
//                     }
//                     if(next=="]") {
//                         if(!brackets.size()) 
//                             imp->error(p, "Never opened square bracket"); 
//                         if(brackets.top().first!="[") 
//                             imp->error(brackets.top().second, "Never closed square bracket");
//                         brackets.pop();
//                         continue;
//                     }
//                     if(next=="def" || next=="service") 
//                         break;
//                 }
//                 if(brackets.size() && brackets.top().first=="(") 
//                     imp->error(brackets.top().second, "Never closed parenthesis");
//                 if(brackets.size() && brackets.top().first=="{") 
//                     imp->error(brackets.top().second, "Never closed bracket");
//                 if(brackets.size() && brackets.top().first=="[") 
//                     imp->error(brackets.top().second, "Never closed square bracket");
//                 if(brackets.size()) 
//                     imp->error(brackets.top().second, "Never closed");
//                 p = start_p;

//                 auto def = make_shared<Def>(types);
//                 all_types.push_back(def);
//                 def->imp = imp;
//                 def->parse(imp, p, types);
//                 vector<Type> lazy_options;
//                 if(def->lazy_compile) lazy_options = def->get_lazy_options(types);
//                 if(!types.contains(def->name)) 
//                     types.vars[def->name] = def;
//                 else if(!types.vars[def->name]->lazy_compile) {
//                     // if the previous was a normal implementation move that to a union
//                     auto prev = types.vars[def->name];
//                     types.vars[def->name] = make_shared<Def>(types);
//                     all_types.push_back(types.vars[def->name]);
//                     types.vars[def->name]->imp = imp;
//                     types.vars[def->name]->pos = p;
//                     types.vars[def->name]->lazy_compile = true;
//                     types.vars[def->name]->name = prev->name;
//                     for (const auto& d : prev->options) 
//                         if (!ranges::contains(types.vars[def->name]->options, d)) 
//                             types.vars[def->name]->options.push_back(d);
//                 }
//                 if(def->lazy_compile) {
//                     Def::log_depth = 0;
//                     for(const auto& d : lazy_options) {
//                         if(d->lazy_compile) 
//                             imp->error(--p, "Internal error: failed to compile "+d->signature(types));
//                         if (!ranges::contains(types.vars[def->name]->options, d))
//                             types.vars[def->name]->options.push_back(d);
//                     }
//                     p--;
//                     while(p<imp->size()-1) {
//                         p++;
//                         if(
//                             imp->at(p)=="def" 
//                             || imp->at(p)=="union" 
//                             || imp->at(p)=="service"
//                             || (imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include")
//                             || (imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="install") 
//                             || (imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="unsafe") 
//                             || (imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="about") 
//                         )
//                             break;
//                     }
//                     --p;
//                 }
//                 else 
//                     types.vars[def->name]->options.push_back(def);
//                 def->assert_options_validity(imp, p);
//             }
//             else if(imp->at(p)=="union") {
//                 string name = imp->at(++p);
//                 if(types.contains(name)) imp->error(--p, "Already defined: "+name);
//                 auto def = make_shared<Def>(types);
//                 all_types.push_back(def);
//                 def->imp = imp;
//                 def->pos = p;
//                 def->lazy_compile = true;
//                 def->name = name;
//                 types.vars[name] = def;
//                 p++;
//                 while(true) {
//                     string next = imp->at(p++);
//                     // if(next=="def" || next=="union" || next=="service"){
//                     //     --p;
//                     //     break;
//                     // }
//                     if(next=="-" && imp->at(p++)=="-") 
//                         break;
//                     const auto& found_type = types.vars.find(next);
//                     if(found_type==types.vars.end()) 
//                         imp->error(--p, "Undefined runtype: "+next);
//                     bool added = false;
//                     for(const Type& option : found_type->second->options) {
//                         if(!option->choice_power)
//                             continue;
//                         if(option->lazy_compile) 
//                             imp->error(--p, "Internal error: failed to compile runtype "+option->signature(types));
//                         if(!ranges::contains(def->options, option)) {
//                             def->options.push_back(option);
//                             added = true;
//                         }
//                     }
//                     if(!added)
//                         imp->error(--p, "Missing nominal variation"
//                             "\nCannot create a runtype union that includes non-nominal types (those would be ignored)");
//                 }
//                 --p;
//                 def->assert_options_validity(imp, p);
//             }
//             else 
//                 imp->error(p, "Unexpected token\nOnly `service`, `smo`, `union`, `@include`, `@install`, `@about`, or `@unsafe` allowed");
//             p++;
//         }
//         catch(const std::runtime_error& e) {
//             warnings++;
//             string message = e.what();
//             string preample = message;
//             if(!Def::markdown_errors) // if not in lsp don't show everything
//                 preample = message.substr(0, message.find('\n'));
//             if(types.all_errors.find(preample)==types.all_errors.end()) {
//                 types.all_errors[preample] += message.substr(message.find('\n'));
//                 //cerr << message << "\n";
//             }
//             else 
//                 types.suppressed[preample] += 1;
//             while(p<imp->size()-1) {
//                 p++;
//                 if(imp->at(p)=="def" || imp->at(p)=="union" || imp->at(p)=="service") break;
//                 if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include") break;
//                 if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="install") break;
//                 if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="unsafe") break;
//                 if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="about") break;
//             }
//             if(p>=imp->size()-1) break;
//         }
//     }
    
//     for(const auto& err : types.all_errors) {
//         cerr << err.first;
//         if(types.suppressed.find(err.first)!=types.suppressed.end()) 
//             cerr << "\033[33m -- "<<types.suppressed[err.first]<<" similar errors in this file\033[0m";
//         if(!Def::markdown_errors) 
//             cerr << err.second;
//         cerr << "\n";
//         errors = true;
//     }

//     if(!Def::markdown_errors) {
//         if(imp->allow_unsafe && imp->about.size()==0) 
//             imp->about = "\"Unsafe code without description at "+imp->path+"\"";
//         else if(imp->about.size()==0) 
//             imp->about = "\""+imp->path+"\"";
//         if(selected_task==Task::Verify && warnings) 
//             task_report += "\033[30;41m "
//                 +string(warnings<10?" ":"")
//                 +to_string(warnings)
//                 +" ERRORS \033[0m " 
//                 + file 
//                 + "\n"; 
//         else if(selected_task==Task::Verify) 
//             task_report += "\033[30;42m OK \033[0m " + file + "\n"; 
//     }
//     return errors;

//     //imp->tokens.clear();  // DO NOT CLEAR HERE BECAUSE IT PREVENTS LAZY DEFS FROM PARSING
// }


static bool handle_unsafe(Import* imp, size_t& p) {
    imp->allow_unsafe = true;
    ++p;
    return false;
}

static bool handle_about(Import* imp, size_t& p) {
    p += 2;
    auto next = imp->at(p);
    if (next[0] == '"') {
        imp->about = next;
    } else {
        ++p;
        auto desc = imp->at(p);
        if (desc[0] != '"')
            imp->error(p - 2, "Wrong `@about` syntax\nEither `@about \"description\"` or @about name \"description\" are expected");
        imp->docs[next] = desc;
    }
    return false;
}

bool codegen(map<string, Types>& files, string file,
             const Memory& builtins, Task selected_task,
             string& task_report) {

    auto& types = files[file];
    if (types.vars.size())
        return false;

    auto imp = tokenize(file);
    types.imp = imp;

    for (const auto& it : builtins.vars)
        types.vars[it.first] = it.second;

    size_t p = 0;
    size_t warnings = 0;
    bool errors = false;

    if (imp->tokens.size())
        while (p < imp->tokens.size() - 1) {
            try {
                if (imp->at(p) == "@" && imp->at(p + 1) == "unsafe")
                    errors |= handle_unsafe(imp.get(), p);
                else if (imp->at(p) == "@" && imp->at(p + 1) == "about")
                    errors |= handle_about(imp.get(), p);
                else if (imp->at(p) == "@" && imp->at(p + 1) == "install")
                    errors |= handle_install(files, file, builtins, selected_task, task_report, imp, p);
                else if (imp->at(p) == "@" && imp->at(p + 1) == "include")
                    errors |= handle_include(files, file, builtins, selected_task, task_report, imp, p, types);
                else if (imp->at(p) == "def" || imp->at(p) == "service")
                    handle_def_or_service(files, file, builtins, selected_task, task_report, imp, p, types, errors);
                else if (imp->at(p) == "union")
                    handle_union(imp, p, types);
                else
                    imp->error(p, "Unexpected token\nOnly `service`, `smo`, `union`, `@include`, `@install`, `@about`, or `@unsafe` allowed");
                p++;
            }
            catch (const std::runtime_error& e) {
                warnings++;
                string message = e.what();
                string preample = message;
                if (!Def::markdown_errors)
                    preample = message.substr(0, message.find('\n'));
                if (types.all_errors.find(preample) == types.all_errors.end())
                    types.all_errors[preample] += message.substr(message.find('\n'));
                else
                    types.suppressed[preample] += 1;
                while (p < imp->size() - 1) {
                    p++;
                    if (imp->at(p) == "def" || imp->at(p) == "union" || imp->at(p) == "service") break;
                    if (imp->at(p) == "@" && p < imp->size() - 1 && imp->at(p + 1) == "include") break;
                    if (imp->at(p) == "@" && p < imp->size() - 1 && imp->at(p + 1) == "install") break;
                    if (imp->at(p) == "@" && p < imp->size() - 1 && imp->at(p + 1) == "unsafe") break;
                    if (imp->at(p) == "@" && p < imp->size() - 1 && imp->at(p + 1) == "about") break;
                }
                if (p >= imp->size() - 1) break;
            }
        }

    for (const auto& err : types.all_errors) {
        cerr << err.first;
        if (types.suppressed.find(err.first) != types.suppressed.end())
            cerr << "\033[33m -- " << types.suppressed[err.first] << " similar errors in this file\033[0m";
        if (!Def::markdown_errors)
            cerr << err.second;
        cerr << "\n";
        errors = true;
    }

    if (!Def::markdown_errors) {
        if (imp->allow_unsafe && imp->about.empty())
            imp->about = "\"Unsafe code without description at " + imp->path + "\"";
        else if (imp->about.empty())
            imp->about = "\"" + imp->path + "\"";
        if (selected_task == Task::Verify && warnings)
            task_report += "\033[30;41m " + string(warnings < 10 ? " " : "") + to_string(warnings) + " ERRORS \033[0m " + file + "\n";
        else if (selected_task == Task::Verify)
            task_report += "\033[30;42m OK \033[0m " + file + "\n";
    }
    return errors;
}
