#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <memory>
#include <unordered_map>
#include <cctype>
#include "parser/tokenize.h"
#include "parser/common.h"
#include <cctype>
#include <cstdlib>
#include <unordered_set>

// g++ smolang.cpp -o smol -O2 -std=c++23 -Wall
// g++ smolang.cpp -o smol -std=c++23 -Wall -fsanitize=address -fsanitize=undefined -D_FORTIFY_SOURCE=3 -fstack-protector-strong -pie -fPIE -g -fsanitize=leak

using namespace std;

struct Def;
typedef shared_ptr<Def> Type;

class Memory {
public:
    unordered_map<string, Type> vars;
    inline bool contains(const string& var) const {return vars.find(var)!=vars.end();}
    Memory() = default;
};

class Arg {
public:
    string name;
    Type type;
    bool mut;
    Arg(const string& n, const Type& t, bool m):name(n),type(t),mut(m){}
};

class Def {
    static int temp;
    static string create_temp() {return "__v"+to_string(++temp);}
    #include "parser/recommendations.cpp"
    #include "parser/assign_variable.cpp"
    #include "parser/parse_directive.cpp"
    #include "parser/parse_expression.cpp"
    #include "parser/parse_return.cpp"
    #include "parser/parse_signature.cpp"
public:
    bool is_service;
    bool _is_primitive;
    bool lazy_compile;
    static bool debug;
    vector<Type> options;
    vector<Arg> args;
    shared_ptr<Import> imp;
    Memory internalTypes;
    vector<string> packs;
    size_t pos, start, end;
    string name, preample, vardecl, implementation, errors, finals;
    unordered_map<string, Type> parametric_types;

    Def(const string& builtin): is_service(false), _is_primitive(true), lazy_compile(false), name(builtin), preample(""), vardecl(""), implementation(""), errors(""), finals("") {}
    Def(): is_service(false), _is_primitive(false), lazy_compile(false), name(""), preample(""), vardecl(""), implementation(""), errors(""), finals("") {}
    vector<string> gather_tuple(const shared_ptr<Import>& imp, size_t& p, Memory& types, string& inherit_buffer, const string& curry);
    inline bool not_primitive() const {return !_is_primitive;}
    string next_var(const shared_ptr<Import>& i, size_t& p, const string& first_token, Memory& types, bool test=true);
    #include "parser/signature.cpp"
    #include "parser/rebase.cpp"
    #include "parser/parse.cpp"
};
#include "parser/gather_tuple.cpp"
#include "parser/next_var.cpp"
int Def::temp = 0;
bool Def::debug = false;

enum class Task {
    Compile,
    Verify,
    Run
};
Task parse_task(const string& arg) {
    if (arg == "compile") return Task::Compile;
    if (arg == "verify") return Task::Verify;
    if (arg == "run") return Task::Run;
    throw invalid_argument("Unknown task: " + arg);
}

int main(int argc, char* argv[]) {
    Task selected_task = Task::Run;
    vector<string> files;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--task") {
            if (i + 1 >= argc) {cerr << "Error: --task requires an argument (compile, verify, run)" << endl;return 1;}
            try {selected_task = parse_task(argv[++i]);
            } catch (const invalid_argument& e) {cerr << "Error: " << e.what() << endl; return 1;}
        } 
        else if (arg.rfind("--", 0) == 0) {cerr << "Unknown option: " << arg << endl; return 1;}
        else files.push_back(arg);
    }
    if(files.size()==0) files.push_back("main.s");

    for(string file : files) {
        if(file.size()<2 || file.substr(file.size()-2) != ".s") {cerr << "Error: expecting '.s' extension for file: " << file << endl; return 1;}
        try {
            auto imp = tokenize(file);
            Memory types;
            types.vars["u64"] = make_shared<Def>("u64");
            types.vars["i64"] = make_shared<Def>("i64");
            types.vars["f64"] = make_shared<Def>("f64");
            types.vars["ptr"] = make_shared<Def>("ptr");
            types.vars["errcode"] = make_shared<Def>("errcode");
            types.vars["cstr"] = make_shared<Def>("cstr");
            types.vars["bool"] = make_shared<Def>("bool");
            types.vars["char"] = make_shared<Def>("char");
            types.vars["__label"] = make_shared<Def>("__label");


            types.vars["buffer"] = make_shared<Def>("buffer");
            types.vars["buffer"]->packs.push_back("contents");
            types.vars["buffer"]->packs.push_back("size");
            types.vars["buffer"]->packs.push_back("offset");
            types.vars["buffer"]->internalTypes.vars["contents"] = types.vars["ptr"];
            types.vars["buffer"]->internalTypes.vars["size"] = types.vars["u64"];
            types.vars["buffer"]->internalTypes.vars["offset"] = types.vars["u64"];
            types.vars["buffer"]->_is_primitive = false;

            for(const auto& it : types.vars) it.second->options.push_back(it.second);

            stack<pair<string, int>> brackets;
            for(size_t p=0;p<imp->size();++p) {
                string next = imp->at(p);
                if(next=="(" || next=="{" || next=="[") brackets.push(make_pair(next, p));
                if(next==")") {if(!brackets.size() || brackets.top().first!="(") imp->error(brackets.top().second, "Never closed parenthesis");brackets.pop();continue;}
                if(next=="}") {if(!brackets.size() || brackets.top().first!="{") imp->error(brackets.top().second, "Never closed bracket");brackets.pop();continue;}
                if(next=="]") {if(!brackets.size() || brackets.top().first!="[") imp->error(brackets.top().second, "Never closed square bracket");brackets.pop();continue;}
            }
            if(brackets.size() && brackets.top().first=="(") imp->error(brackets.top().second, "Never closed parenthesis");
            if(brackets.size() && brackets.top().first=="{") imp->error(brackets.top().second, "Never closed bracket");
            if(brackets.size() && brackets.top().first=="[") imp->error(brackets.top().second, "Never closed square bracket");
            if(brackets.size()) imp->error(brackets.top().second, "Never closed");

            unordered_set<string> imported;
            size_t count_errors = 0;
            size_t p = 0;
            unordered_set<string> all_errors;
            while(p<imp->tokens.size()) {
                try {
                    if (imp->at(p) == "@" && imp->at(p + 1) == "include") {
                        p += 2;
                        string path = imp->at(p);
                        while(imp->at(p+1)==".") {p += 2;path += "/"+imp->at(p);}
                        path += ".s";
                        if(imported.find(path)!=imported.end()) imp->error(p, "Already included");
                        imported.insert(path);
                        auto new_tokens = tokenize(path);
                        p += 1;
                        imp->tokens.reserve(imp->tokens.size() + new_tokens->tokens.size());
                        imp->tokens.insert(imp->tokens.begin() + p,new_tokens->tokens.size(),Token());
                        std::move(new_tokens->tokens.begin(), new_tokens->tokens.end(),imp->tokens.begin() + p);
                        new_tokens->tokens.clear();
                        continue;
                    }
                    else if(imp->at(p)=="smo" || imp->at(p)=="service") {
                        auto def = make_shared<Def>();
                        def->parse(imp, p, types);
                        if(!types.contains(def->name)) types.vars[def->name] = def;
                        types.vars[def->name]->options.push_back(def);
                        /*if(types.vars.find(def->name)!=types.vars.end()) {
                            auto prev_def = types.vars.find(def->name)->second;
                            def->next_overload_to_try = prev_def;
                            string new_name = def->canonic_name();
                            string new_path = def->imp->path; // TODO: fix because currently we inserted includes to tokens (need to recursively parse instead maybe)
                            while(prev_def) {
                                if(new_path!=prev_def->imp->path) imp->error(def->pos+1, "Defined in two different files\n"+new_path+"\n"+prev_def->imp->path);
                                if(prev_def->canonic_name()==new_name) imp->error(def->pos+1, "Already defined");
                                prev_def = prev_def->next_overload_to_try;
                            }
                        }
                        else types.vars[def->name] = def;*/
                        if(def->lazy_compile) {
                            p--;
                            while(p<imp->size()-1) {
                                p++;
                                if(imp->at(p)=="smo" || imp->at(p)=="union" || imp->at(p)=="service") break;
                                if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include") break;
                            }
                            --p;
                        }
                    }
                    else if(imp->at(p)=="union") {
                        auto def = make_shared<Def>();
                        def->lazy_compile = true;
                        ++p;
                        def->name = imp->at(p++);
                        if(types.contains(def->name)) imp->error(--p, "Union is already defined as a runtype or union");
                        p++;
                        while(true) {
                            string next = imp->at(p++);
                            const auto& found_type = types.vars.find(next);
                            if(found_type!=types.vars.end()) for(const Type& option : found_type->second->options) def->options.push_back(option);
                            else imp->error(--p, "Undefined runtype");
                            next = imp->at(p++);
                            if(next==")") {break;}
                            if(next!=",") imp->error(--p, "Missing comma");
                        }
                        types.vars[def->name] = def;
                        if(def->lazy_compile) {
                            --p;
                            while(p<imp->size()-1) {
                                p++;
                                if(imp->at(p)=="smo" || imp->at(p)=="union" || imp->at(p)=="service") break;
                                if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include") break;
                            }
                            --p;
                        }
                    }
                    else imp->error(p, "Unexpected token\nOnly `service`, `smo`, `union` or `@include` allowed");
                    p++;
                }
                catch (const std::runtime_error& e) {
                    string message = e.what();
                    if(all_errors.find(message)==all_errors.end()) {
                        all_errors.insert(message);
                        cerr << message << "\n";
                    }
                    count_errors++;
                    while(p<imp->size()-1) {
                        p++;
                        if(imp->at(p)=="smo" || imp->at(p)=="union" || imp->at(p)=="service") break;
                        if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include") break;
                    }
                    if(p>=imp->size()-1) break;
                }
            }

            imp->tokens.clear();
            if(count_errors) ERROR("Aborted due to the above "+to_string(count_errors)+" errors\n");
            

            string globals = 
                "#include <cstring>\n"
                "#define __USER__ERROR 1\n"
                "#define __BUFFER__ERROR 2\n"
                "#define __UNHANDLED__ERROR 2\n"
                "#define ptr void*\n"
                "#define errcode int\n"
                "#define cstr const char*\n"
                "#define u64 unsigned long\n"
                "#define i64 long\n"
                "#define f64 double\n\n";
            string impl = "";


            for(const auto& it : types.vars) if(it.second->is_service) {
                const auto& service = it.second;
                globals += service->preample;
                globals += "errcode "+service->raw_signature()+";\n";
                impl += "\n";
                impl += "errcode ";
                impl += service->raw_signature()+"{\nerrcode __result__errocode = 0;\n";
                impl += service->vardecl;
                impl += service->implementation;
                impl += "goto __return;\n"; // skip error handling block that resides at the end of the service
                impl +="__error:\n"; // error handling (each of those runs goto ____finally)
                impl += service->errors;
                impl += "__return:\n"; // resource deallocation
                impl += service->finals;
                impl += "return __result__errocode;\n";
                impl += "}\n\n";
            }

            if(selected_task==Task::Verify) {
                cout << "\033[30;42m OK \033[0m " + file + "\n";
                continue;
            }
            std::ofstream out(file.substr(0, file.size()-2)+".cpp");
            out << globals;
            out << impl;
            out.close();
            if(selected_task==Task::Run) {
                int run_status = system("g++ -O3 -s -ffunction-sections -fno-exceptions -fno-rtti -flto -fdata-sections main.cpp -o main && ./main");
                if (run_status != 0) return run_status;
            }
            else {
                int run_status = system("g++ -O3 -s -ffunction-sections -fno-exceptions -fno-rtti -flto -fdata-sections main.cpp -o main");
                if (run_status != 0) return run_status;
                cout << "\033[30;42m ./ \033[0m " + file.substr(0, file.size()-2) + "\n";
            }
        }
        catch (const std::runtime_error& e) {
            if(selected_task!=Task::Run) cout << "\033[30;41m ERROR \033[0m " << file << "\n";
            cerr << e.what() << std::endl;
        }
    }
    return 0;
}
