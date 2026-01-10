#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include "importer.h"

typedef size_t Token;
typedef size_t VariableId;
extern std::unordered_map<Token, std::string> id2token;
extern std::unordered_map<std::string, Token> token2id;

static inline Token get_token_id(const std::string& name) {
    const auto it = token2id.find(name);
    if(it!=token2id.end()) 
        return it->second;
    Token next_id = id2token.size();
    id2token[next_id] = name;
    token2id[name] = next_id;
    return next_id;
}

class Function;
class Arg {
public:
    Token name;
    Function* type;
    bool is_own;
    bool is_mut;
    bool is_access;
    bool is_buffer;
    Arg(Token name, Function* type, bool is_own, bool is_mut, bool is_access, bool is_buffer)
        : name(name), type(type), is_own(is_own), is_mut(is_mut), is_access(is_access), is_buffer(is_buffer) {}
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
    std::vector<VariableId> outputs;
    bool is_nominal;
};

class Module;
class Function {
public:
    std::vector<bool> is_var;
    std::vector<size_t> id;   // refers to VariableId or Token
    std::vector<Variable> variables;
    std::vector<Token> header;
    std::vector<Token> linker;
    bool is_service;
    Signature info;
    Function(Token name) {
        info.name = name; 
        info.custom_name = name;
    }
    std::vector<Function*> import(Importer& importer, bool is_service);
    std::string to_string() const {
        auto ret = std::string{""};
        for(size_t i=0;i<id.size();++i) {
            if(i) ret += " ";
            if(is_var[i]) ret += variables[id[i]].to_string();
            else ret += id2token[id[i]];
        }
        return ret;
    }
    Function& token(Token t) {
        is_var.emplace_back(false);
        id.emplace_back(t);
        return *this;
    }
    Function& var(const Variable& t) {
        is_var.emplace_back(true);
        size_t next_id = variables.size();
        for(size_t i=0;i<next_id;++i)
            if(variables[i].matches(t)) {
                id.emplace_back(i);
                return *this;
            }
        id.emplace_back(next_id);
        variables.emplace_back(t);
        return *this;
    }
};