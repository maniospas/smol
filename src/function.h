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
    Arg(): name(0), type(nullptr), is_own(false), is_mut(false), is_access(false), is_buffer(false), is_new(false) {}
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
    std::vector<Token> args;
    std::vector<Token> returns;
    std::vector<VariableId> outputs;
    bool is_nominal;
    bool is_primitive;
    bool is_service;
};


class Module;
class Function {
public:
    std::vector<Token> body;
    std::vector<Token> header;
    std::vector<Token> linker;
    std::unordered_map<Token, std::vector<Token>> releases;
    std::unordered_map<Token, Arg> vars;
    std::unordered_set<Token> used_failure_codes;
    std::unordered_map<Token, std::vector<Token>> collections;
    Signature info;
    bool has_returned;
    Function(Token name) : has_returned(false) {
        info.name = name; 
        info.custom_name = name;
        info.is_nominal = false;
        info.is_primitive = false;
        info.is_service = false;
    }
    std::vector<Function*> import(Importer& importer, bool is_service);
    std::string export_inits(const std::string& prefix) const;
    std::string export_fail() const;
    std::string export_release() const;
    std::string export_body() const;
    std::string export_signature() const;
    inline Function& token(const std::string& t) { return token(get_token_id(t)); }
    inline Function& token(Token t) {
        body.emplace_back(t);
        return *this;
    }
    inline void direct_inline(Function* f) { body.insert(body.end(), f->body.begin(), f->body.end()); }
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
    inline void var(const Importer& importer, Token name, Function* f, bool is_mut, bool is_buffer) {
        auto& prev_f = vars[name];
        if(prev_f.type) importer.type_error("Variable already has a type");
        prev_f.name = name;
        prev_f.type = f;
        prev_f.is_mut = is_mut;
        prev_f.is_buffer = is_buffer;
    }
};