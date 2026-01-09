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
static std::unordered_map<Token, std::string> id2token;
static std::unordered_map<std::string, Token> token2id;

class Arg {
    Token name;
    bool is_mut;
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
        const auto it = token2id.find(name);
        if(it!=token2id.end()) 
            segments.push_back(it->second);
        else {
            Token next_id = id2token.size();
            id2token[next_id] = name;
            token2id[name] = next_id;
            segments.push_back(next_id);
        }
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
    std::vector<Arg> args;
    std::vector<VariableId> outputs;
};


class Function {
    Signature info;
    std::vector<bool> is_var;
    std::vector<size_t> id;   // refers to VariableId or Token
    std::vector<Variable> variables;
    bool is_service;
public:
    Function(const std::string& name) {
        const auto it = token2id.find(name);
        if(it!=token2id.end()) 
            info.name = it->second;
        else {
            Token next_id = id2token.size();
            id2token[next_id] = name;
            token2id[name] = next_id;
            info.name = next_id;
        }
    }
    Function(Importer& importer, bool is_service) : is_service(is_service) {
        // parse name
        auto name = std::string{importer.next_token_autoline()};
        if(name.empty())
            importer.error("Syntax error", "Failed to find function name");
        const auto it = token2id.find(name);
        if(it!=token2id.end()) 
            info.name = it->second;
        else {
            Token next_id = id2token.size();
            id2token[next_id] = name;
            token2id[name] = next_id;
            info.name = next_id;
        }
    }
    std::string to_string() const {
        auto ret = std::string{""};
        for(size_t i=0;i<id.size();++i) {
            if(i) ret += " ";
            if(is_var[i]) ret += variables[id[i]].to_string();
            else ret += id2token[id[i]];
        }
        return ret;
    }
    Function& token(const std::string& t) {
        const auto it = token2id.find(t);
        is_var.emplace_back(false);
        if(it!=token2id.end()) 
            id.emplace_back(it->second);
        else {
            Token next_id = id2token.size();
            id2token[next_id] = t;
            token2id[t] = next_id;
            id.emplace_back(next_id);
        }
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