#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include "importer.h"
#include "function.h"
#include <unordered_set>


class Module;
extern std::unordered_map<Token, Module*> source2module;
extern std::vector<Function*> all_functions;

static inline bool is_string(const std::string& token) {
    return token.size()>=2 && token[0]=='"' && token[token.size()-1]=='"';
}

class Union {
public:
    Token name;
    std::unordered_set<Function*> functions;
    Union(Token name) : name(name) {}
    ~Union() {functions.clear();}
    Union* add(Function* function) {
        functions.insert(function);
        return this;
    }
    Union* add_all(Union* u) {
        functions.reserve(functions.size()+u->functions.size());
        for(auto function : u->functions)
            functions.insert(function);
        return this;
    }
};

class Module {
    Token source;
    std::string description;
    std::unordered_map<Token, std::string> function_descriptions;
    bool unsafe;
    int count_errors;
public:
    std::unordered_map<Token, Union*> unions;
    Module(Token source) : source(source), unsafe(false), count_errors(0) {
        source2module[source] = this;
    }
    ~Module() {
        for(auto [name, u] : unions)
            delete u;
        unions.clear();
    }
    int get_error_count() const { return count_errors; }
    void import();
    void import_function(Importer& importer, bool is_service);
};

void cleanup_modules();