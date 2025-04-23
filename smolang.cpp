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
#include "tokenize.h"
#include "common.h"
#include <cctype>
#include <cstdlib>

// g++ smolang.cpp -o smolang -O2 -std=c++23

using namespace std;

struct Def;
typedef shared_ptr<Def> Type;

bool is_primitive(const string& name) {
    if(name=="true" || name=="false") return true;
    const char* str = name.c_str();
    char* end;
    while (isspace(*str)) ++str;
    if (*str == '\0') return false;
    long l = std::strtol(str, &end, 10);
    if (end != str && *end == '\0') return true;
    double d = std::strtod(str, &end);
    if (end != str && *end == '\0') return true;
    return false;
}

bool accepted_var_name(const string& name) {
    if(name=="(" || name==")" || name=="{" || name=="}" || name == "|" || name=="&" || name=="=" || name=="," || name=="." || name=="smo" || name=="@")
        return false;
    return true;
}

bool is_symbol(const std::string& s) {
    return s.size() == 1 &&
    std::ispunct(static_cast<unsigned char>(s[0])) &&
    s != "_";
}

class Memory {
    public:unordered_map<string, Type> vars;
};
class Arg {
public:
    string name;
    Type type;
    Arg(const string& n, const Type& t) : name(n), type(t) {}
};
class Def {
    static int temp;
    static string create_temp() {
        return "__v"+to_string(++temp);
    }
public:
    string canonic_name() {
        string ret = name;
        for(const auto& arg : args) ret += "__"+arg.type->canonic_name();
        return ret;
    }
    string name;
    vector<Arg> args;
    shared_ptr<Import> imp;
    Memory internalTypes;
    vector<string> packs;
    int pos;
    int start;
    int end;
    string vardecl;
    string implementation;
    string preample;
    string errors;
    string finals;

    string rebase(string& impl, const string& var) {
        stringstream input(impl);
        string line, output;
        while (getline(input, line)) {
            int i = 0; bool in_str = false;
            while (i < line.size()) {
                if (line[i] == '"' && (i == 0 || line[i - 1] != '\\')) { output += line[i++]; in_str = !in_str; continue; }
                if (in_str) { output += line[i++]; continue; }
                while (i < line.size() && isspace(line[i])) output += line[i++];
                if (i >= line.size()) break;
                if (is_symbol(line[i])) { output += line[i++]; continue; }
                int start = i;
                while (i < line.size() && !isspace(line[i]) && !is_symbol(line[i])) i++;
                string token = line.substr(start, i - start);
                if (i > 7 && token.substr(0, 7) == "__scope") token = token.substr(7);
                output += internalTypes.vars.count(token) ? var + "__" + token : token;
            }
            output += '\n';
        }
        return output;
    }

    Def(const string& builtin): name(builtin) {}
    Def(): implementation(""), preample(""), errors(""), finals(""), vardecl("") {}
    void parse(const shared_ptr<Import>& i, int& p, Memory& types, bool with_signature=true) {
        pos = p;
        imp = i;
        if(with_signature) {
            if(imp->at(p++)!="smo") imp->error(--p, "Missing `smo`");
            name = imp->at(p++);
            if(imp->at(p++)!="(") imp->error(--p, "Missing left parenthesis");
            while(true) {
                string next = imp->at(p++);
                if(next==")") break;
                if(args.size()) {
                    if(next!=",")imp->error(--p, "Expecting comma between arguments");
                    next = imp->at(p++);
                }
                if(!accepted_var_name(next)) imp->error(--p, "Expecting type declaration but this is not a valid type name");
                if(types.vars.find(next)==types.vars.end()) imp->error(--p, "Type name not visible");
                string arg_name = imp->at(p++);
                if(!accepted_var_name(arg_name)) imp->error(--p, "Expecting variable name");
                Type argType = types.vars.find(next)->second;

                if(argType->args.size()) {
                    internalTypes.vars[arg_name] = argType;
                    for(const auto& it : argType->args) {
                        args.emplace_back(arg_name+"__"+it.name, it.type);
                        internalTypes.vars[arg_name+"__"+it.name] = it.type;
                        vardecl += it.type->rebase(it.type->vardecl, arg_name);
                        implementation += it.type->rebase(it.type->implementation, arg_name);
                        preample += it.type->rebase(it.type->preample, arg_name);
                        finals = it.type->rebase(it.type->finals, arg_name)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
                        errors = errors+it.type->rebase(it.type->errors, arg_name);
                        for(const auto& it : it.type->internalTypes.vars) internalTypes.vars[arg_name+"__"+it.first] = it.second;
                    }
                }
                else {
                    args.emplace_back(arg_name, argType);
                    internalTypes.vars[arg_name] = argType;
                }
                if(p>=imp->size()) imp->error(pos+2, "Missing matching right parenthesis");
            }
        }

        start = p;
        while(p<imp->size()) {
            string next = imp->at(p++);
            // custom behavior
            if(next=="@") {
                next = imp->at(p++);
                if(next=="head") {
                    next = imp->at(p++);
                    if(next!="{") imp->error(--p, "Expected brackets");
                    int depth = 1;
                    while(true) {
                        next = imp->at(p++);
                        if(next=="{") depth++;
                        if(next=="}") {depth--;if(depth==0) break;}
                        string nextnext = imp->at(p);
                        preample += next;
                        if(!is_symbol(next) && !is_symbol(nextnext)) preample += " ";
                    }
                    preample += "\n";
                    continue;
                }
                else if(next=="body") {
                    next = imp->at(p++);
                    if(next!="{") imp->error(--p, "Expected brackets");
                    int depth = 1;
                    while(true) {
                        next = imp->at(p++);
                        if(next=="{") depth++;
                        if(next=="}") {depth--;if(depth==0) break;}
                        string nextnext = imp->at(p);
                        if(p<imp->size()-1 && imp->at(p+1)=="=" && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") && !is_symbol(next) && !is_symbol(nextnext)) {
                            string argname = nextnext;
                            string argtype = next;
                            if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->args.size()) {
                                internalTypes.vars[argname] = types.vars.find(argtype)->second;
                                vardecl += argtype+" "+argname+";\n";
                            }
                            else imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
                        }
                        else {
                            implementation += next;
                            if(!is_symbol(next) && !is_symbol(nextnext)) implementation += " ";
                        }
                    }
                    implementation += "\n";
                    continue;
                }
                else if(next=="fail") {
                    string fail_label = create_temp();
                    errors += fail_label+":\n";
                    next = imp->at(p++);
                    if(next!="{") imp->error(--p, "Expected brackets");
                    int depth = 1;
                    while(true) {
                        next = imp->at(p++);
                        if(next=="{") depth++;
                        if(next=="}") {depth--;if(depth==0) break;}
                        string nextnext = imp->at(p);
                        if(p<imp->size()-1 && imp->at(p+1)=="=" && (!is_symbol(imp->at(p+2)) || imp->at(p+2)=="(") && !is_symbol(next) && !is_symbol(nextnext)) {
                            string argname = nextnext;
                            string argtype = next;
                            if(types.vars.find(argtype)!=types.vars.end() && !types.vars.find(argtype)->second->args.size()) {
                                internalTypes.vars[argname] = types.vars.find(argtype)->second;
                                vardecl += argtype+" "+argname+";\n";
                            }
                            else imp->error(--p, "Unexpected type (can only use builtin types in C++ code, cast to the void* ptr type if need be)");
                        }
                        else {
                            errors += next;
                            if(!is_symbol(next) && !is_symbol(nextnext)) errors += " ";
                        }
                    }
                    errors += "\ngoto __return;\n";
                    implementation += "goto "+fail_label+";\n";
                    continue;
                }
                imp->error(--p, "Invalid symbol after @");
            }
            // return statement
            if(next=="=") {
                if(imp->at(p++)!=">") imp->error(--p, "Expecting `=>` to return for expressions starting with `=`");
                next = imp->at(p++);
                if(next=="@") {
                    next = imp->at(p++);
                    if(next == "scope") {
                        packs.push_back("@scope");
                    }
                    else {
                        if(next!="new") imp->error(--p, "Only allowed special command here is`=>@new` or `=>@scope`");
                        for(const auto& arg : args) packs.push_back(arg.name);
                    }
                }
                else if(next!="(") {
                    while(imp->at(p)==".") {
                        //if(internalTypes.vars.find(next)==internalTypes.vars.end() && !is_primitive(next)) imp->error(--p, "Symbol not declared"); // declare all up to this point
                        next += "__";++p;next += imp->at(p++);
                    }
                    if(internalTypes.vars.find(next)==internalTypes.vars.end() && !is_primitive(next)) imp->error(--p, "Symbol not declared (error during return)");
                    if(!is_primitive(next) && internalTypes.vars[next]->args.size()) {
                        if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared (error during return)");
                        auto oneType = internalTypes.vars[next];
                        if(oneType->packs.size()!=1) imp->error(--p, "Can only convert a primitive result to a primitive");
                        next = next+"__"+oneType->packs[0];
                    }
                    packs.push_back(next);
                }
                else { // we are starting parenthesis
                    while(true) {
                        next = imp->at(p++);
                        while(imp->at(p)==".") {
                            //if(internalTypes.vars.find(next)==internalTypes.vars.end() && !is_primitive(next)) imp->error(--p, "Symbol not declared"); // declare all up to this point
                            next += "__";++p;next += imp->at(p++);
                        }
                        if(internalTypes.vars.find(next)==internalTypes.vars.end() && !is_primitive(next)) imp->error(--p, "Symbol not declared (error during return)");
                        if(!is_primitive(next) && internalTypes.vars[next]->args.size()) {
                            if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared (error during return)");
                            auto oneType = internalTypes.vars[next];
                            if(oneType->packs.size()!=1) imp->error(--p, "Can only convert a primitive result to a primitive");
                            next = next+"__"+oneType->packs[0];
                        }
                        packs.push_back(next);
                        next = imp->at(p++);
                        if(next==")") break;
                        if(next!=",") imp->error(--p, "Comma expected (not implemented expression in return statements yet)");
                    }
                }
                --p;
                end = p;
                break;
            }

            if(types.vars.find(next)==types.vars.end()) imp->error(--p, "Symbol not declared (cannot find `smo` definition)");
            Type type = types.vars.find(next)->second;
            string var = imp->at(p++);
            if(var=="(") var = create_temp();
            else {
                while(imp->at(p)==".") {
                    //if(internalTypes.vars.find(var)==internalTypes.vars.end() && !is_primitive(var)) imp->error(--p, "Symbol not declared"); // declare all up to this point
                    var += "__";++p;var += imp->at(p++);
                }
                if(imp->at(p++)!="(") imp->error(p, "Expecting opening parenthesis");
            }
            internalTypes.vars[var] = type;
            preample += type->preample;

            if(type->name=="buffer") {
                preample += "#include<cstdlib>\n";
                vector<string> unpacks;
                while(true) {
                    string arg = imp->at(p++);
                    if(arg==")") break;
                    while(imp->at(p)==".") {arg += "__";++p;arg += imp->at(p++);}
                    if(internalTypes.vars.find(arg)==internalTypes.vars.end() && !is_primitive(arg)) imp->error(--p, "Symbol not declared");
                    if(!is_primitive(arg)) {
                        Type internalType = internalTypes.vars[arg];
                        if(!internalType->packs.size()) unpacks.push_back(arg);
                        else for(const string& pack : internalType->packs) unpacks.push_back(arg+"__"+pack);
                    }
                    else unpacks.push_back(arg);
                    arg = imp->at(p++);
                    if(arg==")") break;
                    if(arg!=",") imp->error(--p, "Comma expected (not implemented expressions other than field access in calls yet)");
                }

                implementation += "u64 "+var+"__size = "+to_string(unpacks.size())+";\n";
                implementation += "ptr "+var+"__contents = malloc(sizeof(i64)*"+var+"__size);\n";
                for(int i=0;i<unpacks.size();++i) implementation += "((i64*)"+var+"__contents)["+to_string(i)+"] = "+unpacks[i]+";\n";
                internalTypes.vars[var] = type;
                internalTypes.vars[var+"__size"] = types.vars["u64"];
                internalTypes.vars[var+"__contents"] = types.vars["ptr"];
                continue;
            }

            if(!type->args.size()) {
                string value = imp->at(p++);
                while(imp->at(p)==".") {value += "__";++p;value += imp->at(p++);}
                if(internalTypes.vars.find(value)==internalTypes.vars.end() && !is_primitive(value)) imp->error(--p, "Symbol not declared (error during argument parsing)");
                if(imp->at(p++)!=")") imp->error(--p, "Expecting closing parenthesis because builtin `smo "+next+"` can only have one argument");

                if(!is_primitive(value)) {
                    if(internalTypes.vars.find(value)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared (error during unpacking)");
                    auto oneType = internalTypes.vars[value];
                    if(oneType->packs.size()!=1) imp->error(--p, "Can only convert a primitive result to a primitive");
                    value = value+"__"+oneType->packs[0];
                }

                implementation += var + " = " + value + ";\n";
                vardecl += next + " " + var+";\n";
                internalTypes.vars[var] = type;
                continue;
            }

            vector<string> unpacks;
            while(true) {
                string arg = imp->at(p++);
                while(imp->at(p)==".") {arg += "__";++p;arg += imp->at(p++);}
                if(internalTypes.vars.find(arg)==internalTypes.vars.end() && !is_primitive(arg)) imp->error(--p, "Symbol not declared (error during unpacking)");
                if(!is_primitive(arg)) {
                    Type internalType = internalTypes.vars[arg];
                    if(!internalType->packs.size()) unpacks.push_back(arg);
                    else for(const string& pack : internalType->packs) unpacks.push_back(arg+"__"+pack);
                }
                else unpacks.push_back(arg);
                arg = imp->at(p++);
                if(arg==")") break;
                if(arg!=",") imp->error(--p, "Comma expected (not implemented expressions other than field access in calls yet)");
            }
            if(unpacks.size()!=type->args.size()) imp->error(--p, "Unexpected closed parenthesis: smol "+next+" requires "+to_string(type->args.size())+" arguments");
            for(int i=0;i<unpacks.size();++i) {
                if(type->args[i].type->args.size()) imp->error(--p, "Internal errors failed to resolve the type " + type->args[i].type->name + " of "+type->args[i].name);
                if(type->args[i].type!=internalTypes.vars[unpacks[i]] && !is_primitive(unpacks[i])) imp->error(--p, "Different types between " + type->args[i].type->name + " "+ type->args[i].name+" and "+unpacks[i]);
                string target = var+"__"+type->args[i].name;
                implementation += target + " = " + unpacks[i]+";\n";
                vardecl += type->args[i].type->name+" "+ target+";\n";
                internalTypes.vars[target] = type->args[i].type;
            }


            vardecl += type->rebase(type->vardecl, var);
            implementation += type->rebase(type->implementation, var);
            preample += type->rebase(type->preample, var);
            finals = type->rebase(type->finals, var)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
            errors = errors+type->rebase(type->errors, var);
            for(const auto& it : type->internalTypes.vars) internalTypes.vars[var+"__"+it.first] = it.second;

            if(type->packs.size()==1 && type->packs[0]=="@scope") {
                Def def;
                for(const auto& it : internalTypes.vars) def.internalTypes.vars[it.first] = it.second;
                def.parse(imp, p, types, false); // this consumes until return
                p++;

                vardecl += def.rebase(def.vardecl, var);
                implementation += def.rebase(def.implementation, var);
                preample += def.rebase(def.preample, var);
                finals = def.rebase(def.finals, var)+finals; // inverse order for finals to ensure that any inner memory is released first (future-proofing)
                errors = errors+def.rebase(def.errors, var);
                for(const auto& it : def.internalTypes.vars) internalTypes.vars[var+"__"+it.first] = it.second;
                internalTypes.vars["__finally"] = types.vars["__label"];
                implementation += "__finally:\n";
                continue;
            }


        }
        if(with_signature) {
            internalTypes.vars["__end"] = types.vars["__label"];
            implementation += "__end:\n";
        }
    }
};
int Def::temp = 0;


int main() {
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
    types.vars["buffer"]->internalTypes.vars["contents"] = types.vars["ptr"];
    types.vars["buffer"]->internalTypes.vars["size"] = types.vars["u64"];

    stack<pair<string, int>> brackets;
    for(int p=0;p<imp->size();++p) {
        string next = imp->at(p);
        if(next=="(" || next=="{" || next=="[") brackets.push(make_pair(next, p));
        if(next==")") {if(!brackets.size() || brackets.top().first!="(") imp->error(brackets.top().second, "Never closed");brackets.pop();continue;}
        if(next=="}") {if(!brackets.size() || brackets.top().first!="{") imp->error(brackets.top().second, "Never closed");brackets.pop();continue;}
        if(next=="]") {if(!brackets.size() || brackets.top().first!="[") imp->error(brackets.top().second, "Never closed");brackets.pop();continue;}
    }
    if(brackets.size()) imp->error(brackets.top().second, "Never closed");


    int p = 0;
    while(p<imp->tokens.size()) {
        if(imp->at(p)=="smo") {
            auto def = make_shared<Def>();
            def->parse(imp, p, types);
            types.vars[def->name] = def;
        }
        else imp->error(p, "Unexpected token: only smo allowed here");
        p++;
    }

    string vardecl = types.vars["main"]->vardecl;
    string implementation = types.vars["main"]->implementation;
    string preample = types.vars["main"]->preample;
    string finals = types.vars["main"]->finals;
    string errors = types.vars["main"]->errors;
    implementation =
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
    "__error:\n" +// error handling (each of those runs goto __finally)
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
    return 0;
}
