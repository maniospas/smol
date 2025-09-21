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
#include "def.h"
#include "utils/common.h"
#include "utils/compiler.h"
#include <regex>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <filesystem>

vector<string> installation_permissions;

string to_ctypes(const Type t) {
    if (t->name == "f64") 
        return "ctypes.c_double";
    if (t->name == "i64") 
        return "ctypes.c_long";
    if (t->name == "u64") 
        return "ctypes.c_uint64";
    if (t->name == "cstr") 
        return "ctypes.c_char_p";
    if (t->name == "ptr")   
        return "ctypes.c_void_p";
    return "ctypes.c_void_p";
}

string to_python_type(const Type t) {
    if (t->name == "f64") 
        return "(float, int)";
    if (t->name == "i64") 
        return "int";
    if (t->name == "u64") 
        return "int";
    if (t->name == "cstr") 
        return "(bytes, str)";
    return "object";
}

#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <stdexcept>

enum class Task {
    Assemble,
    Transpile,
    Compile,
    Verify,
    Run,
    Library
};

Task parse_task(const string& arg) {
    if(arg == "compile") 
        return Task::Compile;
    if(arg == "verify") 
        return Task::Verify;
    if(arg == "doc") {
        Def::export_docs=true; 
        return Task::Verify;
    }
    if(arg == "lsp") {
        Def::markdown_errors=true; 
        return Task::Verify;
    }
    if(arg == "run") 
        return Task::Run;
    if(arg == "assemble") 
        return Task::Assemble;
    if(arg == "transpile") 
        return Task::Transpile;
    if(arg == "lib") 
        return Task::Library;
    throw invalid_argument("Unknown task: " + arg+" is not one of --run, --assemble, --transpile, --lib, --lsp, --verify, --doc");
}

bool codegen(map<string, Types>& files, string file, const Memory& builtins, Task selected_task, string& task_report) {
    auto& types = files[file];
    if(types.vars.size()) 
        return false;
    auto imp = tokenize(file);
    types.imp = imp;
    for(const auto& it : builtins.vars) 
        types.vars[it.first] = it.second;
    auto imported = unordered_set<string>{};
    auto p = size_t{0};
    auto warnings = size_t{0};
    auto errors = false;
    if(imp->tokens.size()) while(p<imp->tokens.size()-1) {
        try {
            if (imp->at(p) == "@" && imp->at(p + 1) == "unsafe") {
                imp->allow_unsafe = true;
                p++;
            }
            else if (imp->at(p) == "@" && imp->at(p + 1) == "about") {
                p += 2;
                string next = imp->at(p);
                if(next[0]=='"') imp->about = next;
                else {
                    p++;
                    string desc = imp->at(p);
                    if(desc[0]!='"') imp->error(p-2, "Wrong `@about` syntax\nEither `@about \"description\"` or @about name \"description\" are expected");
                    imp->docs[next] = desc;
                }
            }
            else if (imp->at(p) == "@" && imp->at(p + 1) == "install") {
                p += 2;
                string found = "";
                string path = imp->at(p);
                string test_path = path;
                while(p<imp->size()-1 && imp->at(p+1)==".") {
                    p += 2;
                    path += "/"+imp->at(p);
                    test_path += "."+imp->at(p);
                }
                path += ".s"; 
                if(selected_task==Task::Compile || selected_task==Task::Run || selected_task==Task::Transpile) {
                    for (const auto& it : installation_permissions) 
                        if (test_path.rfind(it, 0) == 0) { 
                            found = it;
                            break;
                        }
                    if(found.empty())
                        imp->error(p, "Missing permissions to @install "+test_path+
                            "\nFor example, allow std scipts with: --safe std"
                            "\nIn this case, add this to the compiler: --safe "+test_path);
                    
                    cout << "\033[30;43m INSTALL \033[0m " << test_path << "\n";
                    int run_status = system((EXEC_PREFIX+("smol "+path+" --runtime eager")).c_str());
                    if(run_status) 
                        imp->error(p, "Failed to run installer: "+test_path);
                } 
                else if(!filesystem::exists(path))
                    imp->error(p, "Missing installer: "+test_path);
                else
                    errors = codegen(files, path, builtins, selected_task, task_report) || errors;
            }
            else if (imp->at(p) == "@" && imp->at(p + 1) == "include") {
                p += 2;
                string path = imp->at(p);
                while(p<imp->size()-1 && imp->at(p+1)==".") {p += 2;path += "/"+imp->at(p);}
                path += ".s";
                if(path==file) imp->error(p, "Circular include");
                {
                    ifstream file(path);
                    if (!file) 
                        imp->error(p, "Could not open file: " + path);
                }
                errors = codegen(files, path, builtins, selected_task, task_report) || errors;
                unordered_set<Variable> filter;
                if(p<imp->size()-1 && imp->at(p+1)=="-") {
                    p += 2;
                    if(imp->at(p++)!=">") imp->error(--p, "Expecting -> to import specific symbols");
                    while(p<imp->size()-1) {
                        if(files[path].vars.find(imp->at(p))==files[path].vars.end()) imp->error(p, "Could not import "+imp->at(p)+" from "+path);
                        filter.insert(imp->at(p++));
                        if(imp->at(p)!=",") {--p;break;}
                        p++;
                    }
                }
                // add unions
                for(const auto& it : files[path].vars) 
                    if(filter.find(it.first)!=filter.end())
                        for(const auto& option : it.second->options) 
                            filter.insert(option->name);

                // add @access
                for(const auto& it : files[path].vars) {
                    for(const auto& access : it.second->can_access_mutable_fields) 
                        if(it.second->contains(access) && filter.find(it.second->vars[access]->name)!=filter.end())
                            filter.insert(it.second->name);
                    for(const auto& option : it.second->options) 
                        for(const auto& access : option->can_access_mutable_fields) 
                            if(option->contains(access) && filter.find(option->vars[access]->name)!=filter.end()) {
                               filter.insert(option->name);
                               break;
                            }
                }
                for(const auto& it : files[path].vars) {
                    const Variable& name = it.first;
                    if(filter.size() && filter.find(name)==filter.end()) 
                        continue;
                    Type impl = it.second;
                    //cout<<file<<" imports "<<path<<" "<<impl->signature(types) << "\n";
                    if(impl->_is_primitive) 
                        continue;
                    if(!types.contains(name)) 
                        types.vars[name] = impl;
                    else if(types.vars[name]==impl) {
                    }
                    else {
                        auto def = std::make_shared<Def>(types);
                        auto add_unique = [&](const auto& options) {
                            for (const auto& option : options) {
                                if (!std::ranges::contains(def->options, option)) 
                                    def->options.push_back(option);
                            }
                        };
                        add_unique(types.vars[name]->options);
                        add_unique(impl->options);
                        all_types.push_back(def);
                        def->imp = imp;
                        def->lazy_compile = true;//treat as union
                        def->name = name;
                        types.vars[def->name]->pos = p;
                        types.vars[name] = def;
                        def->assert_options_validity(imp, p);
                    }
                }
                for(auto& it : files[path].alignment_labels) 
                    types.alignment_labels[it.first] = it.second;
                for(auto& it : files[path].reverse_alignment_labels) 
                    types.reverse_alignment_labels[it.first] = it.second;
                if(files[path].all_errors.size()) 
                    if(Def::markdown_errors) 
                        imp->error(p, "Errors in included file: "+path);
                p++;
                continue;
            }
            else if(imp->at(p)=="def" || imp->at(p)=="service") {
                auto start_p = p;
                auto brackets = stack<pair<string, int>> {};
                for(;p<imp->size();++p) {
                    string next = imp->at(p);
                    if(next=="(" || next=="{" || next=="[") 
                        brackets.push(make_pair(next, p));
                    if(next==")") {
                        if(!brackets.size()) 
                            imp->error(p, "Never opened parenthesis"); 
                        if(brackets.top().first!="(") 
                            imp->error(brackets.top().second, "Never closed parenthesis");
                        brackets.pop();
                        continue;
                    }
                    if(next=="}") {
                        if(!brackets.size()) 
                            imp->error(p, "Never opened bracket "); 
                        if(brackets.top().first!="{") 
                            imp->error(brackets.top().second, "Never closed bracket");
                        brackets.pop();
                        continue;
                    }
                    if(next=="]") {
                        if(!brackets.size()) 
                            imp->error(p, "Never opened square bracket"); 
                        if(brackets.top().first!="[") 
                            imp->error(brackets.top().second, "Never closed square bracket");
                        brackets.pop();
                        continue;
                    }
                    if(next=="def" || next=="service") 
                        break;
                }
                if(brackets.size() && brackets.top().first=="(") 
                    imp->error(brackets.top().second, "Never closed parenthesis");
                if(brackets.size() && brackets.top().first=="{") 
                    imp->error(brackets.top().second, "Never closed bracket");
                if(brackets.size() && brackets.top().first=="[") 
                    imp->error(brackets.top().second, "Never closed square bracket");
                if(brackets.size()) 
                    imp->error(brackets.top().second, "Never closed");
                p = start_p;

                auto def = make_shared<Def>(types);
                all_types.push_back(def);
                def->imp = imp;
                def->parse(imp, p, types);
                vector<Type> lazy_options;
                if(def->lazy_compile) lazy_options = def->get_lazy_options(types);
                if(!types.contains(def->name)) 
                    types.vars[def->name] = def;
                else if(!types.vars[def->name]->lazy_compile) {
                    // if the previous was a normal implementation move that to a union
                    auto prev = types.vars[def->name];
                    types.vars[def->name] = make_shared<Def>(types);
                    all_types.push_back(types.vars[def->name]);
                    types.vars[def->name]->imp = imp;
                    types.vars[def->name]->pos = p;
                    types.vars[def->name]->lazy_compile = true;
                    types.vars[def->name]->name = prev->name;
                    for (const auto& d : prev->options) 
                        if (!ranges::contains(types.vars[def->name]->options, d)) 
                            types.vars[def->name]->options.push_back(d);
                }
                if(def->lazy_compile) {
                    Def::log_depth = 0;
                    for(const auto& d : lazy_options) {
                        if(d->lazy_compile) 
                            imp->error(--p, "Internal error: failed to compile "+d->signature(types));
                        if (!ranges::contains(types.vars[def->name]->options, d))
                            types.vars[def->name]->options.push_back(d);
                    }
                    p--;
                    while(p<imp->size()-1) {
                        p++;
                        if(
                            imp->at(p)=="def" 
                            || imp->at(p)=="union" 
                            || imp->at(p)=="service"
                            || (imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include")
                            || (imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="install") 
                            || (imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="unsafe") 
                            || (imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="about") 
                        )
                            break;
                    }
                    --p;
                }
                else 
                    types.vars[def->name]->options.push_back(def);
                def->assert_options_validity(imp, p);
            }
            else if(imp->at(p)=="union") {
                string name = imp->at(++p);
                if(types.contains(name)) imp->error(--p, "Already defined: "+name);
                auto def = make_shared<Def>(types);
                all_types.push_back(def);
                def->imp = imp;
                def->pos = p;
                def->lazy_compile = true;
                def->name = name;
                types.vars[name] = def;
                p++;
                while(true) {
                    string next = imp->at(p++);
                    // if(next=="def" || next=="union" || next=="service"){
                    //     --p;
                    //     break;
                    // }
                    if(next=="-" && imp->at(p++)=="-") 
                        break;
                    const auto& found_type = types.vars.find(next);
                    if(found_type==types.vars.end()) 
                        imp->error(--p, "Undefined runtype: "+next);
                    bool added = false;
                    for(const Type& option : found_type->second->options) {
                        if(!option->choice_power)
                            continue;
                        if(option->lazy_compile) 
                            imp->error(--p, "Internal error: failed to compile runtype "+option->signature(types));
                        if(!ranges::contains(def->options, option)) {
                            def->options.push_back(option);
                            added = true;
                        }
                    }
                    if(!added)
                        imp->error(--p, "Missing nominal variation"
                            "\nCannot create a runtype union that includes non-nominal types (those would be ignored)");
                }
                --p;
                def->assert_options_validity(imp, p);
            }
            else 
                imp->error(p, "Unexpected token\nOnly `service`, `smo`, `union`, `@include`, `@install`, `@about`, or `@unsafe` allowed");
            p++;
        }
        catch(const std::runtime_error& e) {
            warnings++;
            string message = e.what();
            string preample = message;
            if(!Def::markdown_errors) // if not in lsp don't show everything
                preample = message.substr(0, message.find('\n'));
            if(types.all_errors.find(preample)==types.all_errors.end()) {
                types.all_errors[preample] += message.substr(message.find('\n'));
                //cerr << message << "\n";
            }
            else 
                types.suppressed[preample] += 1;
            while(p<imp->size()-1) {
                p++;
                if(imp->at(p)=="def" || imp->at(p)=="union" || imp->at(p)=="service") break;
                if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include") break;
                if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="install") break;
                if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="unsafe") break;
                if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="about") break;
            }
            if(p>=imp->size()-1) break;
        }
    }
    
    for(const auto& err : types.all_errors) {
        cerr << err.first;
        if(types.suppressed.find(err.first)!=types.suppressed.end()) 
            cerr << "\033[33m -- "<<types.suppressed[err.first]<<" similar errors in this file\033[0m";
        if(!Def::markdown_errors) 
            cerr << err.second;
        cerr << "\n";
        errors = true;
    }

    if(!Def::markdown_errors) {
        if(imp->allow_unsafe && imp->about.size()==0) 
            imp->about = "\"Unsafe code without description at "+imp->path+"\"";
        else if(imp->about.size()==0) 
            imp->about = "\""+imp->path+"\"";
        if(selected_task==Task::Verify && warnings) 
            task_report += "\033[30;41m "
                +string(warnings<10?" ":"")
                +to_string(warnings)
                +" ERRORS \033[0m " 
                + file 
                + "\n"; 
        else if(selected_task==Task::Verify) 
            task_report += "\033[30;42m OK \033[0m " + file + "\n"; 
    }
    return errors;

    //imp->tokens.clear();  // DO NOT CLEAR HERE BECAUSE IT PREVENTS LAZY DEFS FROM PARSING
}

int main(int argc, char* argv[]) {
    Task selected_task = Task::Run;
    vector<string> files;
    map<string, Types> included;
    Types builtins;
    bool errors = false;

    builtins.vars[U64_VAR] = make_shared<Def>("u64");
    builtins.vars[Variable("i64")] = make_shared<Def>("i64");
    builtins.vars[Variable("f64")] = make_shared<Def>("f64");
    builtins.vars[PTR_VAR] = make_shared<Def>("ptr");
    builtins.vars[ERRCODE_VAR] = make_shared<Def>("errcode");
    builtins.vars[Variable("cstr")] = make_shared<Def>("cstr");
    builtins.vars[BOOL_VAR] = make_shared<Def>("bool");
    builtins.vars[Variable("char")] = make_shared<Def>("char");
    builtins.vars[NOM_VAR] = make_shared<Def>("nominal");
    builtins.vars[LABEL_VAR] = make_shared<Def>("__label");
    
    builtins.vars[BUFFER_VAR] = make_shared<Def>("__buffer");
    builtins.vars[BUFFER_VAR]->packs.push_back(Variable("dynamic"));// order matters
    builtins.vars[BUFFER_VAR]->packs.push_back(Variable("surface"));
    builtins.vars[BUFFER_VAR]->vars[Variable("dynamic")] = builtins.vars[PTR_VAR]; 
    builtins.vars[BUFFER_VAR]->vars[Variable("surface")] = builtins.vars[PTR_VAR];
    builtins.vars[BUFFER_VAR]->_is_primitive = false;

    for(const auto& it : builtins.vars) 
        it.second->options.push_back(it.second);
    for(const auto& it : builtins.vars) 
        all_types.push_back(it.second);


    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--log") log_type_resolution = true;
        else if (arg == "--runtime") {
            if(i + 1 >= argc) {
                cerr << "Error: --runtime requires an argument. Provide an unknown name, like 'none', to see available runtimes" << endl;
                return 1;
            }
            runtime = argv[++i];
            if(runtime.size()<2 || runtime.substr(runtime.size()-2)!=".h") 
                runtime = "std/runtime/"+runtime+".h";
        }
        else if (arg == "--task") {
            if(i + 1 >= argc) {
                cerr << "\033[30;41m ERROR \033[0m --task requires an argument (compile, verify, run, lsp)" << endl;
                return 1;
            }
            try {
                selected_task = parse_task(argv[++i]); 
            } 
            catch (const invalid_argument& e) {
                cerr << "\033[30;41m ERROR \033[0m " << e.what() << endl; 
                return 1;
            }
        } 
        else if (arg == "--stackargs") {
            Def::calls_on_heap = false;
        }
        else if (arg == "--safe") {
            if(i + 1 >= argc) {
                cerr << "\033[30;41m ERROR \033[0m --safe requires a string" << endl;
                return 1;
            }
            installation_permissions.emplace_back(argv[++i]);
        } 
        else if (arg == "--back") {
            if(i + 1 >= argc) {
                cerr << "\033[30;41m ERROR \033[0m --back requires an argument (e.g., gcc, tcc, g++)" << endl;
                return 1;
            }
            compiler = argv[++i];
        } 
        else if(arg.rfind("--", 0) == 0) {
            cerr << "Unknown option: " << arg << endl; 
            return 1;
        }
        else 
            files.push_back(arg);
    }
    if(!filesystem::exists(runtime)) {
        cerr << "\033[30;41m ERROR \033[0m Runtime not found at: " << runtime << endl;
        cerr << "Provide either a valid path or a [name] matching std/runtime/[name].h:" << endl;
        try {
            for(const auto& entry : filesystem::directory_iterator("std/runtime")) 
                if(entry.is_regular_file() && entry.path().extension() == ".h") 
                    cerr << "  --runtime " << entry.path().stem().filename().string() << endl;
        } 
        catch (const filesystem::filesystem_error& e) {
            cerr << "Nothin - did not find std/runtime/: " << e.what() << endl;
        }
        return 1;
    }
    if(files.size()==0) 
        files.push_back("main.s");
    string task_report;
    for(const string& file : files) {
        if(file.size()<2 || file.substr(file.size()-2) != ".s") {
            cerr << "\033[30;41m ERROR \033[0m expecting '.s' extension but got file: " << file << endl; 
            return 1;
        }
        try {
            errors = codegen(included, file, builtins, selected_task, task_report);
            size_t number = 1;
            if (Def::export_docs) {
                std::string docs = "";
                std::string toc = "<h1 id=\"toc\">Contents</h1>\n";
                for (auto& include : included) {
                    string display_name = include.first;
                    if (display_name.size() >= 2 && display_name.substr(display_name.size() - 2) == ".s")  
                        display_name = display_name.substr(0, display_name.size() - 2);
                    display_name = std::regex_replace(display_name, std::regex("[\\\\/]"), ".");
                    string unsafe_html = "";
                    if (include.second.imp->allow_unsafe) 
                        unsafe_html = " <span class=\"unsafe-badge\">unsafe</span>";
                    string file_anchor = "file_" + display_name;
                    toc += "<br><b><a href=\"#" + file_anchor + "\">" + display_name + "</a></b><div style=\"color:gray\">";
                    docs += "<h1 id=\"file_" + display_name + "\"><span style=\"color:black\"> " 
                        + display_name 
                        + unsafe_html 
                        + "</span><a href=\"#toc\">&nbsp;🔝</a></h1>\n"
                        + include.second.imp->about.substr(1, include.second.imp->about.size() - 2) 
                        + "</p>\n";
                    number++;
                    if(unsafe_html.size()) 
                        docs += "<p class=\"notice\"><i>This file is marked with the unsafe keyword. This means that its "
                            "internal implementation (<i>only</i>) could be subject to bugs that the language's design otherwise "
                            "eliminates. By using this file as a direct or indirect dependency you are trusting its implementation. "
                            "Given this trust, consider other non-unsafe files using it as safe.</i></p>";
                    string overload_docs("");
                    std::vector<pair<Variable, Type>> keys;
                    for (const auto& type : include.second.vars) keys.push_back(pair<Variable,Type>(type.first, type.second));
                    std::sort(keys.begin(), keys.end(), [](pair<Variable, Type>& lhs, pair<Variable, Type>& rhs) {
                        return lhs.second->pos < rhs.second->pos;
                    });
                    bool has_prev = false;
                    for (const auto& type : keys) {
                        string type_docs("");
                        for (const auto& subtype : type.second->options)
                            if (/*include.second.imp->docs.find(subtype->name)!=include.second.imp->docs.end() &&*/ include.second.imp.get()==subtype->imp.get()) {
                                try {
                                    string sig = ansi_to_html(subtype->signature(include.second))+"&nbsp;→&nbsp;";
                                    if(subtype->alias_for.exists() && subtype->vars[subtype->alias_for]->name==subtype->name) 
                                        sig = sig+ansi_to_html(subtype->vars[subtype->alias_for]->signature(include.second));
                                    else if(subtype->alias_for.exists()) 
                                        sig = sig+ansi_to_html(pretty_runtype(subtype->vars[subtype->alias_for]->name.to_string())/*+"["+to_string(subtype->vars[subtype->alias_for]->args.size())+"]"*/);//ansi_to_html(subtype->vars[subtype->alias_for]->signature(include.second));
                                    else if(subtype->packs.size()==1) 
                                        sig += ansi_to_html(pretty_runtype(subtype->vars[subtype->packs[0]]->name.to_string()));
                                    else if(subtype->packs.size()==0) 
                                        sig += "()";
                                    else 
                                        sig += ""+ansi_to_html(ansi_to_html(subtype->signature_like(include.second, subtype->packs)));
                                    sig +=  "<br>\n";
                                    //for(const auto& param : subtype->parametric_types) {
                                    //    sig += "&nbsp;&nbsp;&nbsp;&nbsp;"+param.first + " = " + ansi_to_html(param.second->signature(include.second))+"<br>\n";
                                    //}
                                    sig = "<span class=\"sig\">"+sig+"</span>";
                                    type_docs += sig;
                                } catch (const runtime_error&) {}
                            }
                        if (type_docs.size()) {
                            string desc = include.second.imp->docs[type.second->name.to_string()];
                            desc = unescape_string(desc);
                            if(desc.size()>=2) {
                                replaceAll(desc, "<pre>", "<pre class=\"language-smolambda\"><code class=\"language-smolambda\">");
                                replaceAll(desc, "</pre>", "</code></pre>");
                                desc = "<p>"+(desc.substr(1,desc.size()-2))+"</p>";
                            }
                            string type_anchor = file_anchor + "_" + type.first.to_string();
                            if(has_prev)
                                toc += "<br>";
                            toc += "<a style=\"color:gray\" href=\"#" + type_anchor + "\">" + type.first.to_string() + "</a>";
                            has_prev = true;
                            
                            if (type.second->options.size() != 1) 
                                overload_docs += "<h2 id=\"" + type_anchor + "\">" 
                                    + type.first.to_string() +"<a href=\"#toc\">&nbsp;🔝</a></h2>\n" 
                                    + desc + type_docs;
                            else 
                                docs += "<h2 id=\"" + type_anchor + "\">" 
                                    + type.first.to_string() + "<a href=\"#toc\">&nbsp;🔝</a></h2>\n" 
                                    + desc + type_docs;
                        }
                    }
                    docs += overload_docs;
                    toc += "</div>";
                }
                std::ofstream out(file.substr(0, file.size()-2)+".html");
                out << "<!DOCTYPE html>\n<html>\n<head>\n"
                "<meta charset=\"UTF-8\">\n"
                "<title>Documentation</title>\n"
                "<link href=\"https://cdn.jsdelivr.net/npm/prismjs@1.29.0/themes/prism.min.css\" rel=\"stylesheet\" />\n"
                "<script src=\"https://cdn.jsdelivr.net/npm/prismjs@1.29.0/prism.min.js\"></script>\n"
                "<script src=\"https://cdn.jsdelivr.net/npm/prismjs@1.29.0/components/prism-clike.min.js\"></script>\n"
                "<style>\n"
                "a { text-decoration: none; display: inline-block; transition: transform 0.2s ease;  }"
                "a:hover { transform: scale(1.2); }"
                "body { font-family: sans-serif; max-width: 960px; margin: auto; padding: 2em; background: #fafaff; }\n"
                "h1 { border-bottom: 2px solid #ddd; padding-bottom: 0.2em;}\n"
                ".sig { font-size:1.3em; font-family: monospace; }\n"
                ".notice { color: #888; margin-left:3em; margin-right:3em; }\n"
                ".unsafe-badge { font-size: 0.65em; height:1em; color: #fff; background: #d72a2a; border-radius: 4px; padding: 0.1em 0.6em; margin-left: 0.5em; vertical-align: middle; letter-spacing: 1px; }\n"
                ".overload-badge { font-size: 0.65em; height:1em; color: #fff; background:rgb(126, 123, 149); border-radius: 4px; padding: 0.1em 0.6em; margin-left: 0.5em; vertical-align: middle; letter-spacing: 1px; }\n"
                "</style>\n"
                "<script>\n"
                "Prism.languages.smolambda = {\n"
                "  'comment': /\\/\\/.*/,\n"
                "  'directive': { pattern: /@\\w+/, alias: 'important' },\n"
                "  'keyword': [\n"
                "    { pattern: /\\b(?:smo|service|if|else|elif|with|include|do|while|on|union|to|upto|lento|len|and|or)\\b/, greedy: true },\n"
                "    { pattern: /(?:\\|\\|\\|->|\\|\\|->|\\|\\|--|\\|->|\\|--|->|--|:|=)/, greedy: true }\n"
                "  ],\n"
                "  'builtin': /\\b(?:i64|u64|f64|ptr|str|buffer|main|copy|bool|not|cos|sin|tan|acos|asin|atan|pi|exp|log|pow|sqrt|add|mul|sub|div|nominal)\\b/,\n"
                "  'punctuation': /[{}();,\\[\\]]/,\n"
                "  'number': /\\b\\d+\\b/,\n"
                "  'string': { pattern: /\"(?:\\\\.|[^\"\\\\])*\"/, greedy: true }\n"
                "};\n"
                "Prism.highlightAll();\n"
                "</script>\n"
                "</head>\n<body>\n"
                <<toc
                <<docs
                <<"</body>\n</html>\n";
                included.clear();
                continue;
            }
            if(selected_task==Task::Verify) {
                cout << task_report;
                included.clear();
                continue;
            }
            Type main = included[file].vars[Variable("main")];
            if(!main) 
                ERROR("Missing main service at: "+file);
            if(!main->is_service) 
                ERROR("Main was not a service at: "+file);
            if(included[file].all_errors.size()) 
                ERROR("Aborted due to the above errors\n");

            //define services
            size_t count_services = 0;
            unordered_set<string> preample;
            for(const auto& it : included[file].vars) 
                if(it.second->is_service) 
                    for(const auto& service : it.second->options) {
                        for(const string& pre : service->preample) 
                            preample.insert(pre);
                        for (const string& pre : service->linker) 
                            linker += " " + pre;
                        count_services++;
                    }
                    
            // globals
            std::stringstream out("");
            out << 
                "#define SMOLAMBDA_SERVICES "<<(selected_task==Task::Library?1:count_services)<<"\n" // libraries do not run on their own scheduler
                "#ifdef __cplusplus\n"
                "#define __externc extern \"C\"\n"
                "#else\n"
                "#define __externc\n"
                "#endif\n"
                //"#undef _FORTIFY_SOURCE"
                "#include <string.h>\n"
                "#include \""+runtime+"\"\n"
                "#define __IS_i64 1\n"
                "#define __IS_f64 2\n"
                "#define __IS_u64 3\n"
                "#define __IS_ptr 4\n"
                "#define __IS_char 5\n"
                "#define __IS_errcode 6\n"
                "#define __IS_cstr 7\n"
                "#define __IS_bool 8\n"
                "#define __IS_nominal 9\n"
                "#ifdef __cplusplus\n"
                "#define __NULL nullptr\n"
                "#else\n"
                "#include <stddef.h>\n"
                "#define __NULL NULL\n"
                "#endif\n"
                "#define __USER__ERROR 1\n"
                "#define __BUFFER__ERROR 2\n"
                "#define __UNHANDLED__ERROR 3\n"
                "#define __TRANSIENT(message)\n" // empty
                "#define __builtin_assume(cond) do { if (!(cond)) __builtin_unreachable(); } while (0)\n"
                "#ifdef __cplusplus\n"
                "#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L\n"
                "#include <stdbool.h>\n"
                "#else\n"
                "#ifndef bool\n"
                "typedef int bool;\n"
                "#define true 1\n"
                "#define false 0\n"
                "#endif\n"
                "#endif\n"
                "#ifndef __GNUC__\n"
                "#ifndef __builtin_unreachable\n"
                "#define __builtin_unreachable();\n"
                "#endif\n"
                "#endif\n"
                "#include <stdint.h>\n"
                "typedef void* ptr;\n"
                "typedef int errcode;\n"
                "typedef const char* cstr;\n"
                "typedef uint64_t u64;\n"
                "typedef long i64;\n"
                "typedef uint64_t nominal;\n"
                "typedef double f64;\n\n";

            for(const string& pre : preample) 
                out << pre << "\n";
            unordered_set<Type> added_services; // we track added services because somtimes services add themselves to themselves
            for(const auto& it : included[file].vars) 
                if(it.second->is_service) 
                    for(const auto& service : it.second->options)
                        if(!ranges::contains(added_services, it.second) && !service->lazy_compile) {
                            out << service->raw_signature_state()<<"\n";
                            out << "__externc void "+service->raw_signature()+";\n";
                            added_services.insert(service);
                        }
            Type main_service;
            // implement services
            for(const auto& service : added_services) {
                service->simplify();
                if(service->name=="main") 
                    main_service = service;
                out << "\n";
                out << "void "<<service->raw_signature()+"{\nerrcode __result__errocode=0;\n";
                if(service->active_calls.size()) {
                    out << "__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;\n";
                    out << "__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;\n";
                }
                out << "struct "<<service->raw_signature_state_name()<<" *__state=(struct "<<service->raw_signature_state_name()<<"*)__void__state;\n";
                out << service->vardecl.to_string();
                //out << service->vardecl;
                string finals_on_error = "";
                string enref_at_end = "";
                unordered_map<Variable, Type> prev_vars;
                prev_vars.reserve(service->vars.size());
                for(const auto& it : service->vars)
                    prev_vars[it.first] = it.second;
                for(const auto& arg : service->args) {
                    if(arg.type->name==NOM_VAR)     
                        continue;
                    if(arg.mut) {
                        service->coallesce_finals(arg.name); // coallesce finals so that we can hard-remove finals attached to them in the next line (these are transferred on call instead)
                        if(service->finals[arg.name].exists()) {
                            finals_on_error += service->finals[arg.name].to_string();
                            finals_on_error += arg.name.to_string()+"=0;\n";
                            service->finals[arg.name] = Code();
                        }
                        out << arg.type->name.to_string()<<" "<<arg.name.to_string() << "= *__state->" << arg.name.to_string() << ";\n";
                        enref_at_end += "*__state->"+arg.name.to_string()+"="+arg.name.to_string()+";\n";
                    }
                    else
                        out << arg.type->name.to_string()<<" "<<arg.name.to_string() << "= __state->" << arg.name.to_string() << ";\n";
                    service->vars[arg.name] = nullptr; // hack to prevent redeclaration of arguments when iterating through `vars` next
                }
                for(size_t i=1;i<service->packs.size();++i) {
                    Variable var = service->packs[i];
                    service->coallesce_finals(var); // so that we can hard-remove finals in the next line (these are transferred on call instead)
                    if(service->finals[var].exists()) {
                        finals_on_error += service->finals[var].to_string();
                        finals_on_error += var.to_string()+"=0;\n";
                        service->finals[var] = Code();
                    }
                    if(!service->contains(var)) {
                        // this means that it was an input too
                        enref_at_end += "*__state->"+(var+RET_VAR).to_string()+"="+var.to_string()+";\n";
                        continue;
                    }
                        //service->imp->error(service->pos+1, "Unknown runype for internal variable: "+(var.to_string()));
                    if(var!=ERR_VAR && service->vars[var]->name!=NOM_VAR) {
                        //out << "printf(\""<<var+RET_VAR<<"\\n\");\n";
                        out << service->vars[var]->name.to_string()<<" "<<var.to_string() << " = 0;\n";// << "= *__state->" << (var+RET_VAR).to_string() << ";\n";
                        enref_at_end += "*__state->"+(var+RET_VAR).to_string()+"="+var.to_string()+";\n";
                        //out << "printf(\""<<var+RET_VAR<<"\\n\");\n";
                    }
                    service->vars[var] = nullptr ;// hack to prevent redeclaration of arguments when iterating through `vars` next
                }
                for(const auto& var : service->vars) 
                    if(var.second && var.second->_is_primitive && var.second->name!=LABEL_VAR) 
                        out << var.second->name << " " << var.first << "=0;\n";

                out << "\n// IMPLEMENTATION\n";
                out << service->implementation;
                out << "goto __return;\n"; // skip error handling block that resides at the end of the service
                if(service->errors.size()) {
                    out << "\n// ERROR HANDLING\n";
                    for(const auto& error : service->errors)
                        out << error;
                }
                out << "\n// DEALLOCATE RESOURCES BY ERRORS\n";
                out << "__failsafe:\n";
                if(service->active_calls.size())
                    out << "__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_wait, 0);\n";
                out << finals_on_error;
                if(service->active_calls.size()) {
                    out << "__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_destroy, 1);\n";
                    out << "__smolambda_all_tasks = 0;\n"; // prevent the hotpath from doubly freeing
                }
                out << "\n// HOTPATH SKIPS TO HERE\n";
                out << "__return:\n"; // resource deallocation
                if(service->active_calls.size()) {
                    out << "__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_wait, 0);\n";
                    out << "__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_destroy, 1);\n";
                }
                for(const auto& final : service->finals) 
                    if(final.second.exists()) 
                        out << final.second;
                out << enref_at_end;
                if(Def::calls_on_heap && service->active_calls.size()) 
                    out << "__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);\n"; // do this after running all finalization code
                out << "__state->err =  __result__errocode;\n";
                out << "}\n\n";

                // restore variable types to be potentially used by further transpilation
                for(const auto& it : prev_vars) 
                    service->vars[it.first] = it.second;
            }
            out << "\n\nint main() {\n";
            out << "struct "<<main_service->raw_signature_state_name()<<" __main_args={0};\n";
            out << "__smolambda_initialize_service_tasks("<<"main__"<<to_string(main_service->identifier)<<", &__main_args);\n";
            out << "return __main_args.err;\n";
            out << "}\n\n";
            //cout << out.str() << "\n";
            
            // for(const auto& it : included[file].vars) { // CREATES PROBLEM IN LIBRARY, ALL MEMORY WILL BE RELEASED AT THE END BY THE OS ANYWAY
            //     for(const auto& opt : it.second->options) 
            //         opt->vars.clear();
            //     it.second->vars.clear();
            //     it.second->options.clear();
            // }

            if(selected_task == Task::Run) {
                int run_status = compile_from_stringstream_with_flags(out, file.substr(0, file.size()-2), "");
                if(run_status != 0) 
                    return run_status;
                //cout << (EXEC_PREFIX + file.substr(0, file.size()-2)+EXEC_EXT).c_str() << "\n";
                run_status = system((EXEC_PREFIX + file.substr(0, file.size()-2)+EXEC_EXT).c_str());
                if (run_status) 
                    return run_status;
            } 
            else if(selected_task == Task::Library) {
                int run_status = compile_from_stringstream_with_flags(out, file.substr(0, file.size()-2), "-shared -fPIC");
                if(run_status) 
                    return run_status;
                string py_filename = file.substr(0, file.size()-2) + ".py";
                ofstream py_out(py_filename);
                py_out << "import ctypes\n\n";
                py_out << "_lib = ctypes.CDLL(\"" << file.substr(0, file.size()-2) << "\")\n";
                py_out << "if _lib is None:\n";
                py_out << "    raise RuntimeError('Library not loaded.')\n\n";

                // Emit service wrappers + struct definitions
                for (const auto& service : added_services) {
                    string clsname = service->raw_signature_state_name();
                    string symbol  = service->name.to_string()+"__"+to_string(service->identifier);
                    py_out << "class " << clsname << "State(ctypes.Structure):\n";
                    py_out << "    _fields_ = [\n";
                    py_out << "        ('err', ctypes.c_int),\n";
                    for (size_t i = 1; i < service->packs.size(); ++i) 
                        py_out << "        ('" << service->packs[i]+RET_VAR << "', ctypes.POINTER(" << to_ctypes(service->vars[service->packs[i]]) << ")),\n";
                    for (const auto& arg : service->args) {
                        string aname = arg.name.to_string();
                        string tname = arg.type->name.to_string();
                        if (arg.mut) 
                            py_out << "        ('" << aname << "', ctypes.POINTER(" << to_ctypes(arg.type) << ")),\n";
                        else
                            py_out << "        ('" << aname << "', " << to_ctypes(arg.type) << "),\n";
                    }
                    py_out << "    ]\n\n";
                    py_out << "class " << clsname << ":\n";
                    py_out << "    def __init__(self):\n";
                    py_out << "        self._fn = _lib." << symbol << "\n";
                    py_out << "        self._fn.restype = None\n";
                    py_out << "        self._fn.argtypes = [ctypes.POINTER(" << service->raw_signature_state_name() << "State)]\n\n";
                    py_out << "    def __call__(self";
                    for (size_t i = 0; i < service->args.size(); i++) {
                        py_out << ", " << service->args[i].name;
                    }
                    py_out << "):\n";
                    py_out << "        state = " << service->raw_signature_state_name() << "State()\n";
                    for (size_t i = 1; i < service->packs.size(); i++) {
                        py_out << "        " << service->packs[i]+RET_VAR << " = " << to_ctypes(service->vars[service->packs[i]])  << "(0)\n";
                        py_out << "        state." << service->packs[i]+RET_VAR << " = ctypes.pointer(" << service->packs[i]+RET_VAR << ")\n";
                    }
                    for (size_t i = 0; i < service->args.size(); i++) {
                        const auto& arg = service->args[i];
                        string aname = arg.name.to_string();
                        string tname = arg.type->name.to_string();
                        if(tname == "cstr") {
                            py_out << "        if isinstance(" << aname << ", str):\n";
                            py_out << "            " << aname << " = " << aname << ".encode('utf-8')\n";
                            py_out << "        assert isinstance(" << aname << ", (bytes, str)), \"" 
                                << aname << " must be cstr (str or bytes)\"\n";
                        } 
                        else if(arg.mut) 
                            py_out << "        assert isinstance(" << aname 
                                << ", ctypes.POINTER(" << to_ctypes(arg.type) << ")), \"" 
                                << aname << " must be a pointer to " << tname << "\"\n";
                        else 
                            py_out << "        assert isinstance(" << aname << ", " 
                                << to_python_type(arg.type) << "), \"" 
                                << aname << " must be " << tname << "\"\n";
                        py_out << "        state." << aname << " = " << aname << "\n";
                    }
                    py_out << "        self._fn(ctypes.byref(state))\n";
                    py_out << "        if state.err:\n";
                    py_out << "             raise Exception('Failed service execution')\n";
                    py_out << "        return (";
                    for (size_t i = 1; i < service->packs.size(); i++) {
                        if (i > 1) py_out << ", ";
                        py_out << "state." << service->packs[i]+RET_VAR<< ".contents.value";
                    }
                    py_out << ")\n\n";
                }

                // Emit top-level instances
                for (const auto& service : added_services) {
                    py_out << service->name << " = " << service->raw_signature_state_name() << "()\n";
                }

            } 
            else if(selected_task == Task::Assemble) {
                int run_status = compile_from_stringstream_with_flags(out, file.substr(0, file.size()-2), "-S -masm=intel");
                if(run_status) 
                    return run_status;
            } 
            else if(selected_task == Task::Transpile) {
                // Save to .c file
                string c_filename = file.substr(0, file.size()-2) + ".c";
                ofstream c_out(c_filename);
                if (!c_out) {
                    std::cerr << "Failed to open " << c_filename << " for writing\n";
                    return 1;
                }
                c_out << out.str();
                return 0;
            } 
            else {
                int run_status = compile_from_stringstream_with_flags(out, file.substr(0, file.size()-2), "-nodefaultlibs -lc");
                if(run_status) 
                    return run_status;
                cout << "\033[30;42m ./ \033[0m " + file.substr(0, file.size()-2) + "\n";
            }

        }
        catch(const std::runtime_error& e) {
            if(selected_task!=Task::Run) 
                cout << "\033[30;41m ERROR \033[0m " << file << "\n";
            cerr << e.what() << std::endl;
        }
        
        included.clear();
    }
    if(selected_task==Task::Verify && !Def::markdown_errors) 
        for(const auto& def : all_types) 
            if(def 
                && def->imp 
                && def->imp->allow_unsafe 
                && def->imp->about.size()
            ) {
                //cout << "[ "<< def->imp->path << "] ";
                cout << "\033[30;43m UNSAFE \033[0m ";
                cout << def->imp->about.substr(1, def->imp->about.size()-2) << "\n";
                def->imp->about = "";
            }

    for(const auto& def : all_types) 
        if(def && def->imp) 
            def->imp->tokens.clear();
    all_types.clear();
    if(errors)
        return 1;
    return 0;
}
