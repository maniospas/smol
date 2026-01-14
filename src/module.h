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
extern Function* NOMINAL_FUNCTION;

static inline bool is_string(const std::string_view& token) {
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

class UnresolvedArg {
public:
    Token name;
    Union* uni;
    bool is_own;
    bool is_mut;
    bool is_access;
    bool is_buffer;
    bool is_nominal;
    UnresolvedArg(Token name, Union* uni, bool is_own, bool is_mut, bool is_access, bool is_buffer, bool is_nominal)
        : name(name), uni(uni), is_own(is_own), is_mut(is_mut), is_access(is_access), is_buffer(is_buffer), is_nominal(is_nominal) {}
};

class SpecializedFunction {
public:
    Function* function;
    Module* base_module;
    std::unordered_map<Token, Function*> poly;

    Function* helper_function; // used by the parser when a different type needs to be stored per variation
    std::vector<Token> returned; // used when needing to return tuples
    size_t counter; // used by various temporary counters
    std::unordered_set<Function*> candidates; // used during polymorphic type resolution
    std::vector<Token> arguments; // used when accumulating `returned` as arguments in polymorphic type resolution

    SpecializedFunction(Function* function, Module* base_module) 
        : function(function), base_module(base_module), helper_function(nullptr), counter(0) {}
    SpecializedFunction(Function* function, 
        const SpecializedFunction& prototype, Token specialize_name, Function* specialize_function
    ) : function(function), base_module(prototype.base_module), helper_function(nullptr), counter(0) {
        for(auto [name, fun] : prototype.poly)
            poly[name] = fun;
        if(specialize_function) poly[specialize_name] = specialize_function;
    }
    Function* get_type(const Importer& importer, Token name, bool allow_failure=false) const;
    void print_debug() const;
};

class Module {
    Token source;
    std::string description;
    std::unordered_map<Token, std::string> function_descriptions;
    bool unsafe;
    int count_errors;
    std::vector<UnresolvedArg> _gather_arguments(Importer& importer, const std::string& name, bool& set_as_nominal);
    // returned value inside variations, next is not const to use as temporary storage inside
    void parse_code_block(Importer& importer, std::vector<SpecializedFunction>& variations, std::string_view next);
    void parse_expression(Importer& importer, std::vector<SpecializedFunction>& variations, std::string_view next); 
    void parse_expression_for_arguments(Importer& importer, std::vector<SpecializedFunction>& variations, std::string_view next);
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