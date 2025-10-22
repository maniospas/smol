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
#include "codegen.h"
#include "utils/tasks.h"
#include "utils/topython.h"
#include "utils/common.h"
#include "utils/compiler.h"
#include <regex>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;


int main(int argc, char* argv[]) {
    auto selected_task = Task::Run;
    auto errors = false;
    map<string, shared_ptr<Types>> included;
    vector<string> files;
    Types builtins;

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
    builtins.vars[Variable("tag")] = make_shared<Def>("tag");
    
    builtins.vars[BUFFER_VAR] = make_shared<Def>("__buffer");
    builtins.vars[BUFFER_VAR]->packs.push_back(Variable("dynamic"));// order matters
    builtins.vars[BUFFER_VAR]->packs.push_back(Variable("surface"));
    builtins.vars[BUFFER_VAR]->mutables.insert(Variable("dynamic"));
    builtins.vars[BUFFER_VAR]->mutables.insert(Variable("surface"));
    builtins.vars[BUFFER_VAR]->vars[Variable("dynamic")] = builtins.vars[PTR_VAR]; 
    builtins.vars[BUFFER_VAR]->vars[Variable("surface")] = builtins.vars[PTR_VAR];
    builtins.vars[BUFFER_VAR]->_is_primitive = false;

    for(const auto& it : builtins.vars) 
        it.second->options.push_back(it.second);
    for(const auto& it : builtins.vars) 
        all_types.push_back(it.second);


    for(int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if(arg == "--log") log_type_resolution = true;
        else if(arg == "--workers") {
            if (i + 1 >= argc) {
                cerr << "\033[31mERROR\033[0m --workers requires a number or zero" << endl;
                return 1;
            }
            try {
                worker_limit = stoi(argv[++i]);
            } catch (const invalid_argument&) {
                cerr << "\033[31mERROR\033[0m --workers argument must be an integer" << endl;
                return 1;
            } catch (const out_of_range&) {
                cerr << "\033[31mERROR\033[0m --workers value out of range" << endl;
                return 1;
            }
        }
        else if(arg == "--runtime") {
            if(i + 1 >= argc) {
                cerr << "\033[31mERROR\033[0m --runtime requires an argument. Provide an unknown name, like 'none', to see available runtimes" << endl;
                return 1;
            }
            runtime = argv[++i];
            if(runtime.size()<2 || runtime.substr(runtime.size()-2)!=".h") 
                runtime = "std/runtime/"+runtime+".h";
        }
        else if(arg == "--task") {
            if(i + 1 >= argc) {
                cerr << "\033[31mERROR\033[0m --task requires an argument (compile, verify, run, lsp)" << endl;
                return 1;
            }
            try {
                selected_task = parse_task(argv[++i]); 
            } 
            catch (const invalid_argument& e) {
                cerr << "\033[31mERROR\033[0m " << e.what() << endl; 
                return 1;
            }
        } 
        else if(arg == "--stackargs") {
            Def::calls_on_heap = false;
        }
        else if(arg == "--safe") {
            if(i + 1 >= argc) {
                cerr << "\033[31mERROR\033[0m --safe requires a string" << endl;
                return 1;
            }
            installation_permissions.emplace_back(argv[++i]);
        } 
        else if(arg == "--back") {
            if(i + 1 >= argc) {
                cerr << "\033[31mERROR\033[0m --back requires an argument (e.g., gcc, tcc, g++)" << endl;
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
        cerr << "\033[31mERROR\033[0m Runtime not found at: " << runtime << endl;
        cerr << "Provide either a valid path or a [name] matching std/runtime/[name].h:" << endl;
        try {
            for(const auto& entry : filesystem::directory_iterator("std/runtime")) 
                if(entry.is_regular_file() && entry.path().extension() == ".h") 
                    cerr << "  --runtime " << entry.path().stem().filename().string() << endl;
        } 
        catch (const filesystem::filesystem_error& e) {
            cerr << "Nothing - did not find std/runtime/: " << e.what() << endl;
        }
        return 1;
    }
    if(files.size()==0)
        files.push_back("main.s");
    string task_report;
    for(const string& file : files) {
        if(file.size()<2 || file.substr(file.size()-2) != ".s") {
            cerr << "\033[31mERROR\033[0m expecting '.s' extension but got file: " << file << endl; 
            goto return_errors;
        }
        try {
            if(!fs::is_regular_file(file)) {
                cerr << "\033[31mERROR\033[0m could not find file: " << file << endl; 
                goto return_errors;
            }
            errors = codegen_all(included, file, builtins, selected_task, task_report);
            size_t number = 1;
            if(Def::export_docs) {
                string docs = "";
                string toc = "<h1 id=\"toc\">Contents</h1>\n";
                for(auto& include : included) {
                    string display_name = include.first;
                    if(display_name.size() >= 2 && display_name.substr(display_name.size() - 2) == ".s")  
                        display_name = display_name.substr(0, display_name.size() - 2);
                    display_name = regex_replace(display_name, regex("[\\\\/]"), ".");
                    string unsafe_html = "";
                    if(include.second->imp->allow_unsafe) 
                        unsafe_html = " <span class=\"unsafe-badge\">unsafe</span>";
                    string file_anchor = "file_" + display_name;
                    toc += "<br><b><a href=\"#" + file_anchor + "\">" + display_name + "</a></b><div style=\"color:gray\">";
                    docs += "<h1 id=\"file_" + display_name + "\"><span style=\"color:black\"> " 
                        + display_name 
                        + unsafe_html 
                        + "</span><a href=\"#toc\">&nbsp;🔝</a></h1>\n"
                        + include.second->imp->about.substr(1, include.second->imp->about.size() - 2) 
                        + "</p>\n";
                    number++;
                    if(unsafe_html.size()) 
                        docs += "<p class=\"notice\"><i>This file is marked with the unsafe keyword. This means that its "
                            "internal implementation (<i>only</i>) could be subject to bugs that the language's design otherwise "
                            "eliminates. By using this file as a direct or indirect dependency you are trusting its implementation. "
                            "Given this trust, consider other non-unsafe files using it as safe.</i></p>";
                    string overload_docs("");
                    vector<pair<Variable, Type>> keys;
                    for(const auto& type : include.second->vars) keys.push_back(pair<Variable,Type>(type.first, type.second));
                    sort(keys.begin(), keys.end(), [](pair<Variable, Type>& lhs, pair<Variable, Type>& rhs) {
                        return lhs.second->pos < rhs.second->pos;
                    });
                    bool has_prev = false;
                    for(const auto& type : keys) {
                        string type_docs("");
                        for(const auto& subtype : type.second->options)
                            if(/*include.second.imp->docs.find(subtype->name)!=include.second.imp->docs.end() &&*/ include.second->imp.get()==subtype->imp.get()) {
                                try {
                                    string sig = ansi_to_html(subtype->signature(*include.second.get()))+"&nbsp;→&nbsp;";
                                    if(subtype->alias_for.exists() && subtype->vars[subtype->alias_for]->name==subtype->name) 
                                        sig = sig+ansi_to_html(subtype->vars[subtype->alias_for]->signature(*include.second.get()));
                                    else if(subtype->alias_for.exists()) 
                                        sig = sig+ansi_to_html(pretty_runtype(subtype->vars[subtype->alias_for]->name.to_string())/*+"["+to_string(subtype->vars[subtype->alias_for]->args.size())+"]"*/);//ansi_to_html(subtype->vars[subtype->alias_for]->signature(include.second));
                                    else if(subtype->packs.size()==1) 
                                        sig += ansi_to_html(pretty_runtype(subtype->vars[subtype->packs[0]]->name.to_string()));
                                    else if(subtype->packs.size()==0) 
                                        sig += "()";
                                    else 
                                        sig += ""+ansi_to_html(ansi_to_html(subtype->signature_like(*include.second.get(), subtype->packs)));
                                    sig +=  "<br>\n";
                                    //for(const auto& param : subtype->parametric_types) {
                                    //    sig += "&nbsp;&nbsp;&nbsp;&nbsp;"+param.first + " = " + ansi_to_html(param.second->signature(include.second))+"<br>\n";
                                    //}
                                    sig = "<span class=\"sig\">"+sig+"</span>";
                                    type_docs += sig;
                                } catch (const runtime_error&) {}
                            }
                        if(type_docs.size()) {
                            string desc = include.second->imp->docs[type.second->name.to_string()];
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
                            
                            if(type.second->options.size() != 1) 
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
                ofstream out(file.substr(0, file.size()-2)+".html");
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
                "    { pattern: /\\b(?:smo|service|if|else|elif|with|case|qed|include|while|on|union|to|upto|lento|len|and|or|then|return)\\b/, greedy: true },\n"
                "  ],\n"
                "  'builtin': /\\b(?:i64|u64|f64|symbol|ptr|str|buffer|main|copy|bool|not|cos|sin|tan|acos|asin|atan|pi|exp|log|pow|sqrt|add|mul|sub|div|nominal)\\b/,\n"
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
            Type main = included[file]->vars[Variable("main")];
            if(!main) 
                ERROR("Missing main service at: "+file);
            if(!main->is_service) 
                ERROR("Main was not a service at: "+file);
            if(included[file]->all_errors.size()) 
                ERROR("Aborted due to the above errors\n");

            //define services
            auto count_services = size_t{0};
            unordered_set<string> preamble;
            for(const auto& it : included[file]->vars) 
                if(it.second->is_service) 
                    for(const auto& service : it.second->options) {
                        for(const string& pre : service->preamble) 
                            preamble.insert(pre);
                        for(const string& pre : service->linker) 
                            linker += " " + pre;
                        count_services++;
                    }
                    
            // globals
            auto out = stringstream{""};
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
                "#define __IS_symbol 10\n"
                "#ifdef __cplusplus\n"
                "#define __NULL nullptr\n"
                "#else\n"
                "#include <stddef.h>\n"
                "#define __NULL NULL\n"
                "#endif\n"
                "#define __USER__ERROR 1\n"
                "#define __BUFFER__ERROR 2\n"
                "#define __UNHANDLED__ERROR 3\n"
                "#define __STACK__ERROR 4\n"
                "#define __DYokMIC__ERROR 5\n"
                "#define __TRANSIENT(message)\n" // empty
                "#define __builtin_assume(cond) do { if(!(cond)) __builtin_unreachable(); } while(0)\n"
                "#ifdef __cplusplus\n"
                "#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L\n"
                "#include <stdbool.h>\n"
                "#else\n"
                "#ifndef bool\n"
                "typedef char bool;\n"
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
                "typedef uint64_t tag;\n"
                "typedef uint64_t u64;\n"
                "typedef long i64;\n"
                "typedef uint64_t nominal;\n"
                "typedef double f64;\n\n";

            for(const string& pre : preamble) 
                out << pre << "\n";
            unordered_set<Type> added_services; // we track added services because somtimes services add themselves to themselves
            for(const auto& it : included[file]->vars) 
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
                out << "void "<<service->raw_signature()+"{\nerrcode __result__error_code=0;\n";
                out << "char* __service_stack_floor = (char*)__runtime_stack_bottom();\n";
                out << "u64 __service_stack_size = "<<service->estimate_stack_deallocation_size()<<";\n"; 
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
                        service->coalesce_finals(arg.name); // coalesce finals so that we can hard-remove finals attached to them in the next line (these are transferred on call instead)
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
                    service->coalesce_finals(var); // so that we can hard-remove finals in the next line (these are transferred on call instead)
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
                out << "__state->err =  __result__error_code;\n";
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
            auto t_start = chrono::steady_clock::now();
            if(selected_task == Task::Run) {
                cout << "\033[35mcompile\033[0m --back "+compiler+"  --runtime "+runtime+"  "<<std::flush;
                int run_status = compile_from_stringstream_with_flags(out, file.substr(0, file.size()-2), "");
                cout << to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t_start).count()) + "ms\n";
                if(run_status != 0) 
                    return run_status;
                //cout << (EXEC_PREFIX + file.substr(0, file.size()-2)+EXEC_EXT).c_str() << "\n";
                cout << "\033[32mrunning\033[0m " + file.substr(0, file.size()-2) + "\n\n";
                run_status = system((EXEC_PREFIX + file.substr(0, file.size()-2)+EXEC_EXT).c_str());
                if(run_status) 
                    return run_status;
            } 
            else if(selected_task == Task::Library) {
                cout << "\033[35mcompile\033[0m --back "+compiler+"  --runtime "+runtime+"  "<<std::flush;
                int run_status = compile_from_stringstream_with_flags(out, file.substr(0, file.size()-2), "-shared -fPIC");
                cout << to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t_start).count()) + "ms\n";
                if(run_status) 
                    return run_status;
                string py_filename = file.substr(0, file.size()-2) + ".py";
                ofstream py_out(py_filename);
                py_out << "import ctypes\n\n";
                py_out << "_lib = ctypes.CDLL(\"" << file.substr(0, file.size()-2) << "\")\n";
                py_out << "if _lib is None:\n";
                py_out << "    raise RuntimeError('Library not loaded.')\n\n";

                // Emit service wrappers + struct definitions
                for(const auto& service : added_services) {
                    string clsname = service->raw_signature_state_name();
                    string symbol  = service->name.to_string()+"__"+to_string(service->identifier);
                    py_out << "class " << clsname << "State(ctypes.Structure):\n";
                    py_out << "    _fields_ = [\n";
                    py_out << "        ('err', ctypes.c_int),\n";
                    for(size_t i = 1; i < service->packs.size(); ++i) 
                        py_out << "        ('" << service->packs[i]+RET_VAR << "', ctypes.POINTER(" << to_ctypes(service->vars[service->packs[i]]) << ")),\n";
                    for(const auto& arg : service->args) {
                        string aname = arg.name.to_string();
                        string tname = arg.type->name.to_string();
                        if(arg.mut) 
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
                    for(size_t i = 0; i < service->args.size(); i++) {
                        py_out << ", " << service->args[i].name;
                    }
                    py_out << "):\n";
                    py_out << "        state = " << service->raw_signature_state_name() << "State()\n";
                    for(size_t i = 1; i < service->packs.size(); i++) {
                        py_out << "        " << service->packs[i]+RET_VAR << " = " << to_ctypes(service->vars[service->packs[i]])  << "(0)\n";
                        py_out << "        state." << service->packs[i]+RET_VAR << " = ctypes.pointer(" << service->packs[i]+RET_VAR << ")\n";
                    }
                    for(size_t i = 0; i < service->args.size(); i++) {
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
                    for(size_t i = 1; i < service->packs.size(); i++) {
                        if(i > 1) py_out << ", ";
                        py_out << "state." << service->packs[i]+RET_VAR<< ".contents.value";
                    }
                    py_out << ")\n\n";
                }

                // Emit top-level instances
                for(const auto& service : added_services) {
                    py_out << service->name << " = " << service->raw_signature_state_name() << "()\n";
                }
                cout << "\033[32mcreated\033[0m " + file.substr(0, file.size()-2) + ".py\n";
            } 
            else if(selected_task == Task::Assemble) {
                cout << "\033[35massemble\033[0m --back "+compiler+"  --runtime "+runtime+"  "<<std::flush;
                int run_status = compile_from_stringstream_with_flags(out, file.substr(0, file.size()-2), "-S -masm=intel");
                cout << to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t_start).count()) + "ms\n";
                if(run_status) 
                    return run_status;
                cout << "\033[32mcreated\033[0m " + file.substr(0, file.size()-2) + "\n";
            } 
            else if(selected_task == Task::Transpile) {
                // Save to .c file
                string c_filename = file.substr(0, file.size()-2) + ".c";
                ofstream c_out(c_filename);
                if(!c_out) {
                    cerr << "Failed to open " << c_filename << " for writing\n";
                    goto return_errors;
                }
                c_out << out.str();
                cout << "\033[37;42mcreated\033[0m " + file.substr(0, file.size()-2) + ".c\n";
                return 0;
            } 
            else {
                // Task::Compile
                cout << "\033[35mcompile\033[0m --back "+compiler+"  --runtime "+runtime+"  "<<std::flush;
                int run_status = compile_from_stringstream_with_flags(out, file.substr(0, file.size()-2), "-lc");
                cout << to_string(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t_start).count()) + "ms\n";
                if(run_status) 
                    return run_status;
                cout << "\033[32mcreated\033[0m " + file.substr(0, file.size()-2) + "\n";
            }

        }
        catch(const runtime_error& e) {
            if(selected_task!=Task::Run) 
                cout << "\033[31mERROR\033[0m " << file << "\n";
            cerr << e.what() << endl;
        }
        
        included.clear();
    }
    if(selected_task==Task::Verify && !Def::lsp) 
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
    if(errors)
        goto return_errors;
    
    for(const auto& it : included) {
        it.second->imp->tokens.clear();
        it.second->imp = nullptr;
    }
    for(const auto& def : all_types) {
        if(def) {
            def->clear();
        }
    }
    included.clear();
    all_types.clear();
    builtins.vars.clear(); 
    SegmentMap::instance().clear();
    return 0;
    

    return_errors:
    for(const auto& it : included) {
        it.second->imp->tokens.clear();
        it.second->imp = nullptr;
    }
    for(const auto& def : all_types) 
        if(def) {
            def->clear();
        }
    included.clear();
    all_types.clear();
    builtins.vars.clear(); 
    SegmentMap::instance().clear();
    return 1;
}
