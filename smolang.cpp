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
    #include "parser/assign_variable.cpp"
    #include "parser/parse_directive.cpp"
    #include "parser/parse_expression.cpp"
    #include "parser/parse_return.cpp"
    #include "parser/parse_signature.cpp"
public:
    bool _is_primitive;
    Type next_overload_to_try;
    vector<Arg> args;
    shared_ptr<Import> imp;
    Memory internalTypes;
    vector<string> packs;
    size_t pos, start, end;
    string name, preample, vardecl, implementation, errors, finals;
    unordered_set<string> muts;

    Def(const string& builtin): _is_primitive(true), name(builtin), preample(""), vardecl(""), implementation(""), errors(""), finals("") {}
    Def(): _is_primitive(false), name(""), preample(""), vardecl(""), implementation(""), errors(""), finals("") {}
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


int main() {
    try {
        auto imp = tokenize("main.s");
        Memory types;
        types.vars["u64"] = make_shared<Def>("u64");
        types.vars["i64"] = make_shared<Def>("i64");
        types.vars["f64"] = make_shared<Def>("f64");
        types.vars["ptr"] = make_shared<Def>("ptr");
        types.vars["bool"] = make_shared<Def>("bool");
        types.vars["__label"] = make_shared<Def>("__label");


        types.vars["buffer"] = make_shared<Def>("buffer");
        types.vars["buffer"]->packs.push_back("contents");
        types.vars["buffer"]->packs.push_back("size");
        types.vars["buffer"]->packs.push_back("offset");
        types.vars["buffer"]->internalTypes.vars["contents"] = types.vars["ptr"];
        types.vars["buffer"]->internalTypes.vars["size"] = types.vars["u64"];
        types.vars["buffer"]->internalTypes.vars["offset"] = types.vars["u64"];
        types.vars["buffer"]->_is_primitive = false;

        stack<pair<string, int>> brackets;
        for(size_t p=0;p<imp->size();++p) {
            string next = imp->at(p);
            if(next=="(" || next=="{" || next=="[") brackets.push(make_pair(next, p));
            if(next==")") {if(!brackets.size() || brackets.top().first!="(") imp->error(brackets.top().second, "Never closed");brackets.pop();continue;}
            if(next=="}") {if(!brackets.size() || brackets.top().first!="{") imp->error(brackets.top().second, "Never closed");brackets.pop();continue;}
            if(next=="]") {if(!brackets.size() || brackets.top().first!="[") imp->error(brackets.top().second, "Never closed");brackets.pop();continue;}
        }
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
                else if(imp->at(p)=="smo") {
                    auto def = make_shared<Def>();
                    def->parse(imp, p, types);
                    if(types.vars.find(def->name)!=types.vars.end()) {
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
                    types.vars[def->name] = def;
                }
                else imp->error(p, "Unexpected token\nOnly `smo` or `@include` allowed");
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
                    if(imp->at(p)=="smo") break;
                    if(imp->at(p)=="@" && p<imp->size()-1 && imp->at(p+1)=="include") break;
                }
                if(p>=imp->size()-1) break;
            }
        }

        imp->tokens.clear();
        if(count_errors) ERROR("Aborted due to the above "+to_string(count_errors)+" errors\n");

        string vardecl = types.vars["main"]->vardecl;
        string implementation = types.vars["main"]->implementation;
        string preample = types.vars["main"]->preample;
        string finals = types.vars["main"]->finals;
        string errors = types.vars["main"]->errors;
        implementation =
        "#include <cstring>\n"
        "#define ptr void*\n"
        "#define u64 unsigned long\n"
        "#define i64 long\n"
        "#define f64 double\n\n"
        +preample+
        "int main() {\n" +
        vardecl +
        implementation +
        "goto __return;\n" + // skip error handling block that resides at the end of the service
        finals+
        "__error:\n" +// error handling (each of those runs goto ____finally)
        errors +
        "__return:\n" + // resource deallocation
        finals +
        "return 0;\n" // actually return from the service
        "}\n";
        std::ofstream out("main.cpp");
        out << implementation;
        out.close();
        int run_status = system("g++ -O3 -s -ffunction-sections -fno-exceptions -fno-rtti -flto -fdata-sections main.cpp -o main && ./main");
        if (run_status != 0) return run_status;
    }
    catch (const std::runtime_error& e) {
        cerr << e.what() << std::endl;
    }
    return 0;
}
