#include "def.h"
#include "parser/recommendations.cpp"
#include "parser/gather_tuple.cpp"
#include "parser/next_var.cpp"
#include "parser/assign_variable.cpp"
#include "parser/parse_signature.cpp"
#include "parser/parse_directive.cpp"
#include "parser/parse_expression.cpp"
#include "parser/signature.cpp"
#include "parser/rebase.cpp"
#include "parser/parse.cpp"
#include "parser/parse_return.cpp"

// g++ src/smolang.cpp -o smol -O2 -std=c++23 -Wall
// g++ src/smolang.cpp -o smol -std=c++23 -Wall -fsanitize=address -fsanitize=undefined -D_FORTIFY_SOURCE=3 -fstack-protector-strong -pie -fPIE -g -fsanitize=leak
// g++ __smolambda__temp__main.cpp -o tests/main -std=c++23 -fsanitize=address -fsanitize=undefined -D_FORTIFY_SOURCE=3 -fstack-protector-strong -pie -fPIE -g -fsanitize=leak

enum class Task {
    Assemble,
    Compile,
    Verify,
    Run
};
Task parse_task(const string& arg) {
    if (arg == "compile") return Task::Compile;
    if (arg == "verify") return Task::Verify;
    if (arg == "lsp") {Def::markdown_errors=true; return Task::Verify;}
    if (arg == "run") return Task::Run;
    if (arg == "assemble") return Task::Assemble;
    throw invalid_argument("Unknown task: " + arg);
}

void codegen(unordered_map<string, Types>& files, string file, const Memory& builtins) {
    Types& types = files[file];
    if(types.vars.size()) return;
    auto imp = tokenize(file);
    for(const auto& it : builtins.vars) types.vars[it.first] = it.second;

    stack<pair<string, int>> brackets;
    for(size_t p=0;p<imp->size();++p) {
        string next = imp->at(p);
        if(next=="(" || next=="{" || next=="[") brackets.push(make_pair(next, p));
        if(next==")") {if(!brackets.size()) imp->error(p, "Never opened parenthesis"); if(brackets.top().first!="(") imp->error(brackets.top().second, "Never closed parenthesis");brackets.pop();continue;}
        if(next=="}") {if(!brackets.size()) imp->error(p, "Never opened bracket "); if(brackets.top().first!="{") imp->error(brackets.top().second, "Never closed bracket");brackets.pop();continue;}
        if(next=="]") {if(!brackets.size()) imp->error(p, "Never opened square bracket"); if(brackets.top().first!="[") imp->error(brackets.top().second, "Never closed square bracket");brackets.pop();continue;}
    }
    if(brackets.size() && brackets.top().first=="(") imp->error(brackets.top().second, "Never closed parenthesis");
    if(brackets.size() && brackets.top().first=="{") imp->error(brackets.top().second, "Never closed bracket");
    if(brackets.size() && brackets.top().first=="[") imp->error(brackets.top().second, "Never closed square bracket");
    if(brackets.size()) imp->error(brackets.top().second, "Never closed");

    unordered_set<string> imported;
    size_t p = 0;
    while(p<imp->tokens.size()-1) {
        try {
            if (imp->at(p) == "@" && imp->at(p + 1) == "include") {
                p += 2;
                string path = imp->at(p);
                while(p<imp->size()-1 && imp->at(p+1)==".") {p += 2;path += "/"+imp->at(p);}
                path += ".s";
                if(path==file) imp->error(p, "Circular include");
                {
                    ifstream file(path);
                    if (!file) imp->error(p, "Could not open file: " + path);
                }

                codegen(files, path, builtins);

                unordered_set<string> filter;
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

                for(const auto& it : files[path].vars) {
                    const string& name = it.first;
                    if(filter.size() && filter.find(name)==filter.end()) continue;
                    Type impl = it.second;
                    if(impl->_is_primitive) continue;
                    if(!types.contains(name)) types.vars[name] = impl;
                    else if(types.vars[name]==impl) {}
                    else {
                        auto def = make_shared<Def>(types);
                        for(const auto& option : types.vars[name]->options) def->options.insert(option);
                        for(const auto& option : impl->options) def->options.insert(option);
                        all_types.push_back(def);
                        def->imp = imp;
                        def->lazy_compile = true;  // TODO: Check if this needs to be true
                        def->name = name;
                        types.vars[name]  = def;
                    }
                }
                for(const auto& it : files[path].alignment_labels) types.alignment_labels[it.first] = it.second;
                for(const auto& it : files[path].reverse_alignment_labels) types.reverse_alignment_labels[it.first] = it.second;
                if(files[path].all_errors.size()) if(Def::markdown_errors) imp->error(p, "Errors in included file: "+path);
                p++;
                continue;
            }
            else if(imp->at(p)=="smo" || imp->at(p)=="service") {
                auto def = make_shared<Def>(types);
                all_types.push_back(def);
                def->imp = imp;
                def->parse(imp, p, types);
                vector<Type> lazy_options;
                if(def->lazy_compile) lazy_options = def->get_lazy_options(types);
                if(!types.contains(def->name)) types.vars[def->name] = def;
                else if(!types.vars[def->name]->lazy_compile) {
                    // if it was a normal implementation move to a union
                    auto prev = types.vars[def->name];
                    types.vars[def->name] = make_shared<Def>(types);
                    all_types.push_back(types.vars[def->name]);
                    types.vars[def->name]->imp = imp;
                    types.vars[def->name]->lazy_compile = true;
                    types.vars[def->name]->name = prev->name;
                    for(const auto& d : prev->options) types.vars[def->name]->options.insert(d);
                }

                if(def->lazy_compile) {
                    Def::log_depth = 0;
                    for(const auto& d : lazy_options) {
                        if(d->lazy_compile) imp->error(--p, "Internal error: failed to compile "+d->signature(types));
                        types.vars[def->name]->options.insert(d);
                    }
                    p--;
                    while(p<imp->size()-1) {
                        p++;
                        if(imp->at(p)=="smo" || imp->at(p)=="union" || imp->at(p)=="service") break;
                        if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include") break;
                    }
                    --p;
                }
                else types.vars[def->name]->options.insert(def);
            }
            else if(imp->at(p)=="union") {
                string name = imp->at(++p);
                if(types.contains(name)) imp->error(--p, "Already defined: "+name);
                auto def = make_shared<Def>(types);
                all_types.push_back(def);
                def->imp = imp;
                def->lazy_compile = true;
                def->name = name;
                p++;
                if(imp->at(p++)!="(") imp->error(--p, "Expecting opening parenthesis");
                while(true) {
                    string next = imp->at(p++);
                    const auto& found_type = types.vars.find(next);
                    if(found_type==types.vars.end()) imp->error(--p, "Undefined runtype");
                    for(const Type& option : found_type->second->options) {
                        if(option->lazy_compile) imp->error(--p, "Internal error: failed to compile runtype "+option->signature(types));
                        def->options.insert(option);
                    }
                    next = imp->at(p++);
                    if(next==")") break;
                    if(next!=",") imp->error(--p, "Missing comma");
                }
                --p;
                types.vars[name] = def;
            }
            else imp->error(p, "Unexpected token\nOnly `service`, `smo`, `union` or `@include` allowed");
            p++;
        }
        catch (const std::runtime_error& e) {
            string message = e.what();
            if(types.all_errors.find(message)==types.all_errors.end()) {
                types.all_errors.insert(message);
                cerr << message << "\n";
            }
            while(p<imp->size()-1) {
                p++;
                if(imp->at(p)=="smo" || imp->at(p)=="union" || imp->at(p)=="service") break;
                if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include") break;
            }
            if(p>=imp->size()-1) break;
        }
    }

    //imp->tokens.clear();  // DO NOT CLEAR HERE BECAUSE IT PREVENTS LAZY DEFS FROM PARSING
}

int main(int argc, char* argv[]) {
    Task selected_task = Task::Run;
    vector<string> files;
    unordered_map<string, Types> included;
    Types builtins;

    builtins.vars["u64"] = make_shared<Def>("u64");
    builtins.vars["i64"] = make_shared<Def>("i64");
    builtins.vars["f64"] = make_shared<Def>("f64");
    builtins.vars["ptr"] = make_shared<Def>("ptr");
    builtins.vars["errcode"] = make_shared<Def>("errcode");
    builtins.vars["cstr"] = make_shared<Def>("cstr");
    builtins.vars["bool"] = make_shared<Def>("bool");
    builtins.vars["char"] = make_shared<Def>("char");
    builtins.vars["nom"] = make_shared<Def>("nom");

    builtins.vars["__label"] = make_shared<Def>("__label");

    builtins.vars["buffer"] = make_shared<Def>("buffer");
    builtins.vars["buffer"]->packs.push_back("__contents");
    builtins.vars["buffer"]->packs.push_back("__typetag");
    builtins.vars["buffer"]->packs.push_back("__size");
    builtins.vars["buffer"]->packs.push_back("__offset");
    builtins.vars["buffer"]->internalTypes.vars["__contents"] = builtins.vars["ptr"];
    builtins.vars["buffer"]->internalTypes.vars["__typetag"] = builtins.vars["ptr"];
    builtins.vars["buffer"]->internalTypes.vars["__size"] = builtins.vars["u64"];
    builtins.vars["buffer"]->internalTypes.vars["__offset"] = builtins.vars["u64"];
    builtins.vars["buffer"]->_is_primitive = false;
    for(const auto& it : builtins.vars) it.second->options.insert(it.second);
    for(const auto& it : builtins.vars) all_types.push_back(it.second);


    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--log") log_type_resolution = true;
        else if (arg == "--task") {
            if(i + 1 >= argc) {cerr << "Error: --task requires an argument (compile, verify, run, lsp)" << endl;return 1;}
            try {selected_task = parse_task(argv[++i]); } 
            catch (const invalid_argument& e) {cerr << "Error: " << e.what() << endl; return 1;}
        } 
        else if(arg.rfind("--", 0) == 0) {cerr << "Unknown option: " << arg << endl; return 1;}
        else files.push_back(arg);
    }
    if(files.size()==0) files.push_back("main.s");
    for(string file : files) {
        if(file.size()<2 || file.substr(file.size()-2) != ".s") {cerr << "Error: expecting '.s' extension but got file: " << file << endl; return 1;}
        try {
            codegen(included, file, builtins);
            Type main = included[file].vars["main"];
            if(!main) ERROR("Missing main service at: "+file);
            if(!main->is_service) ERROR("Main was not a service at: "+file);
            if(included[file].all_errors.size()) ERROR("Aborted due to the above errors\n");
            if(selected_task==Task::Verify) {cout << "\033[30;42m OK \033[0m " + file + "\n"; continue;}
            string globals = 
                //"#undef _FORTIFY_SOURCE"
                "#include <cstring>\n"
                "#define __IS_i64 1\n"
                "#define __IS_f64 2\n"
                "#define __IS_u64 3\n"
                "#define __IS_ptr 4\n"
                "#define __IS_char 5\n"
                "#define __IS_errcode 6\n"
                "#define __IS_cstr 7\n"
                "#define __IS_bool 8\n"
                "#define __IS_nom 9\n"
                "#define __NULL nullptr\n"
                "#define __USER__ERROR 1\n"
                "#define __BUFFER__ERROR 2\n"
                "#define __UNHANDLED__ERROR 3\n"
                "#define __TRANSIENT(message)\n" // empty
                "#define __builtin_assume(cond) do { if (!(cond)) __builtin_unreachable(); } while (0)\n"
                "using ptr = void*;\n"
                "using errcode = int;\n"
                "using cstr = const char*;\n"
                "using u64 = unsigned long;\n"
                "using i64 = long;\n"
                "using nom = unsigned long;\n"
                "using f64 = double;\n\n";
            std::ofstream out("__smolambda__temp__main.cpp");
            // globals & define services
            out << globals;
            for(const auto& it : included[file].vars) if(it.second->is_service) for(const auto& service : it.second->options) /*if(service->number_of_calls || service->name=="main")*/ {
                for(const string& pre : service->preample) out << pre << "\n";
                out << "errcode "+service->raw_signature()+";\n";
            }
            // implement services
            for(const auto& it : included[file].vars) if(it.second->is_service) for(const auto& service : it.second->options) /*if(service->number_of_calls || service->name=="main")*/ {
                out << "\n";
                out << "errcode ";
                out << service->raw_signature()+"{\nerrcode __result__errocode=0;\n";
                //out << service->vardecl;
                string finals_on_error = "";
                for(const auto& var : service->packs) {
                    service->coallesce_finals(var); // coallesce finals so that we can hard-remove finals attached to them in the next line (these are transferred on call instead)
                    if(service->finals[var].size()) {
                        finals_on_error += service->finals[var];
                        finals_on_error += var+"=0;\n";
                        service->finals[var] = "";
                    }
                    service->internalTypes.vars[var] = nullptr ;// hack to prevent redeclaration of arguments when iterating through internalTypes
                }
                for(const auto& arg : service->args) {
                    if(arg.mut) {
                        service->coallesce_finals(arg.name); // coallesce finals so that we can hard-remove finals attached to them in the next line (these are transferred on call instead)
                        if(service->finals[arg.name].size()) {
                            finals_on_error += service->finals[arg.name];
                            finals_on_error += arg.name+"=0;\n";
                            service->finals[arg.name] = "";
                        }
                    }
                    service->internalTypes.vars[arg.name] = nullptr; // hack to prevent redeclaration of arguments when iterating through internalTypes
                }
                for(const auto& var : service->internalTypes.vars) if(var.second && var.second->_is_primitive && var.second->name!="buffer" && var.second->name!="__label") out << var.second->name << " " << var.first << "=0;\n";
                out << "\n// IMPLEMENTATION\n";
                out << service->implementation;
                out << "goto __return;\n"; // skip error handling block that resides at the end of the service
                if(service->errors.size()) {
                    out << "\n// ERROR HANDLING\n";
                    //out <<"__error:\n"; // error handling (each of those runs goto ____finally)
                    out << service->errors;
                }
                out << "\n// DEALLOCATE RESOURCES BY ERRORS\n";
                out << "__failsafe:\n";
                out << finals_on_error;
                out << "\n// HOTPATH SKIPS TO HERE\n";
                out << "__return:\n"; // resource deallocation
                for(const auto& final : service->finals) if(final.second.size()) out << final.second;
                out << "return __result__errocode;\n";
                out << "}\n\n";
            }
            out.close();
            for(const auto& it : included[file].vars) {
                for(const auto& opt : it.second->options) opt->internalTypes.vars.clear();
                it.second->internalTypes.vars.clear();
                it.second->options.clear();
            }
            if(selected_task==Task::Run) {int run_status = system(("g++ -O3 -s -ffunction-sections -fno-exceptions -fno-rtti -flto -fdata-sections __smolambda__temp__main.cpp -std=c++23 -o "+file.substr(0, file.size()-2)+" && ./"+file.substr(0, file.size()-2)).c_str()); if (run_status != 0) return run_status;}
            else if(selected_task==Task::Assemble) {int run_status = system(("g++ -O3 -ffunction-sections -fno-exceptions -fno-rtti -fdata-sections __smolambda__temp__main.cpp -o "+file.substr(0, file.size()-2)+" -S -masm=intel -fverbose-asm -std=c++23").c_str()); if (run_status != 0) return run_status;}
            else {
                int run_status = system(("g++ -O3 -s -ffunction-sections -fno-exceptions -fno-rtti -flto -fdata-sections __smolambda__temp__main.cpp -o "+file.substr(0, file.size()-2)+" -nodefaultlibs -lc -std=c++23").c_str());
                if (run_status != 0) return run_status;
                cout << "\033[30;42m ./ \033[0m " + file.substr(0, file.size()-2) + "\n";
            }
        }
        catch(const std::runtime_error& e) {
            if(selected_task!=Task::Run) cout << "\033[30;41m ERROR \033[0m " << file << "\n";
            cerr << e.what() << std::endl;
        }
        std::remove("__smolambda__temp__main.cpp");
        included.clear();
    }

    for(const auto& def : all_types) if(def && def->imp) def->imp->tokens.clear();
    all_types.clear();
    return 0;
}
