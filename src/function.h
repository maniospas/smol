#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include "importer.h"

typedef size_t Token;
typedef size_t VariableId;
extern std::unordered_map<Token, std::string> id2token;
extern std::unordered_map<std::string, Token> token2id;
extern std::unordered_map<std::string, Token> failure2code;
extern std::unordered_map<Token, std::string> code2failure;
Token get_token_id(const std::string& name);

class Function;
class Arg {
public:
    Token name;
    Function* type;
    bool is_own;
    bool is_mut;
    bool is_access;
    bool is_buffer;
    bool is_new;
    Arg(Token name, Function* type, bool is_own, bool is_mut, bool is_access, bool is_buffer, bool is_new)
        : name(name), type(type), is_own(is_own), is_mut(is_mut), is_access(is_access), is_buffer(is_buffer), is_new(is_new) {}
};

class Variable {
    std::vector<Token> segments;
    bool mut;
public:
    Variable(const Variable& variable) : mut(variable.mut) {
        segments.reserve(variable.segments.size());
        for(size_t i=0;i<segments.size();++i)
            segments.push_back(i);
    }
    Variable(const std::string& name, bool mut): mut(mut) {
        add(name);
    }
    Variable& add(const std::string& name) {
        segments.push_back(get_token_id(name));
        return *this;
    }
    std::string to_string() const {
        auto ret = std::string{""};
        for(size_t i=0;i<segments.size();++i) {
            if(i) ret += "__";
            ret += id2token[segments[i]];
        }
        return ret;
    }
    bool matches(const Variable& other) {
        if(segments.size()!=other.segments.size())
            return false;
        for(size_t i=0;i<segments.size();++i)
            if(segments[i]!=other.segments[i])
                return false;
        return true;
    }
};

struct Signature {
    Token name;
    Token custom_name;
    std::vector<Arg> args;
    std::vector<Arg> returns;
    std::vector<VariableId> outputs;
    bool is_nominal;
    bool is_primitive;
    bool is_service;
    std::string to_string() const;
};


class Module;
class Function {
public:
    std::vector<Token> body;
    std::vector<Token> header;
    std::vector<Token> linker;
    std::unordered_map<Token, std::vector<Token>> releases;
    std::unordered_map<Token, Function*> vars;
    std::unordered_set<Token> used_failure_codes;
    Signature info;
    Function(Token name) {
        info.name = name; 
        info.custom_name = name;
        info.is_nominal = false;
        info.is_primitive = false;
        info.is_service = false;
    }
    std::vector<Function*> import(Importer& importer, bool is_service);
    std::string export_inits(const std::string& prefix) const {
        auto ret = std::string{""};
        for(const auto& [token, function] : vars) {
            if(function->info.is_primitive) ret += function->export_body()+" "+prefix+id2token[token]+"=0;\n";
            else ret += function->export_inits(id2token[token]+"__");
        }
        return ret;
    }
    std::string export_fail() const {
        auto ret = std::string{""};
        for(auto release_label : used_failure_codes) {
            const auto& message = code2failure[release_label];
            ret += id2token[release_label]+": printf(\"Error: "+message.substr(1, message.size()-2)+"\\n\"); goto __failsafe;\n";
        }
        return ret;
    }
    std::string export_release() const {
        auto ret = std::string{"__failsafe:\n"}; 
        // TODO: add returned releases
        ret += std::string{"__return:\n"};
        // TODO: add all the rest of release
        return ret;
    }
    std::string export_body() const {
        auto ret = std::string{""};
        bool is_prev_symbol = true;
        for(size_t i=0;i<body.size();++i) {
            auto next = id2token[body[i]];
            auto is_symbol = next.size()==1 && is_delim(next[0]);
            if(!is_symbol && !is_prev_symbol) ret += " ";
            is_prev_symbol = is_symbol;
            ret += next;
        }
        return ret;
    }
    inline Function& token(const std::string& t) {
        return token(get_token_id(t));
    }
    inline Function& token(Token t) {
        body.emplace_back(t);
        return *this;
    }
    inline void direct_inline(Function* f) {
        body.insert(body.end(), f->body.begin(), f->body.end());
    }
    Token call_failure(const std::string& message) {
        auto it = failure2code.find(message);
        token("goto");
        if(it!=failure2code.end()) {
            token(it->second);
            token(";");
            token("\n");
            used_failure_codes.insert(it->second);
            return it->second;
        }
        auto new_id = get_token_id("__fail"+std::to_string(failure2code.size()+1));
        failure2code[message] = new_id;
        code2failure[new_id] = message;
        token(new_id);
        token(";");
        token("\n");
        used_failure_codes.insert(new_id);
        return new_id;
    }
    inline void var(const Importer& importer, Token name, Function* f) {
        auto& prev_f = vars[name];
        if(prev_f==f) return;
        if(prev_f) importer.type_error("Variable already has a type");
        prev_f = f;
    }
};