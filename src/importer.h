#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include "console.h"

bool is_delim(char c);

class Importer {
    std::ifstream file;
    size_t line;
    size_t column;
    std::string current_line;
    std::string path;
    bool _has_changed_line;
    size_t start, end; // track these for errors
    const std::string_view _next_token();
    bool next_line() {
        if(!line && !column && !file.is_open()) {
            error("Build error", "This file does not exist");
            return false;
        }
        if(!std::getline(file, current_line)) 
            return false;
        ++line;
        column = 0;
        while(column < current_line.size() && current_line[column]==' ')
            ++column;
        return true;
    }
public:
    inline bool is_open() const {return file.is_open();}
    Importer(const std::string& path): file(path), line(0), column(0), current_line(""), path(path), _has_changed_line(false), start(0), end(0) {}
    ~Importer() = default;
    inline size_t get_token_start() const {
        return start;
    }
    inline bool has_changed_line() const {return _has_changed_line;}
    void rollback_token();
    void invalidate_state_for_file_errors();
    const std::string_view next();
    inline void error(const char* message, const char* description) const {error(message, description, ansi::yellow);}
    inline void format_error(const char* description) const {error("Format error", description, ansi::green);}
    inline void syntax_error(const char* description) const {error("Syntax error", description, ansi::yellow);}
    inline void type_error(const char* description) const {error("Type error", description, ansi::purple);}
    inline void internal_error(const char* description) const {error("Internal error (compiler bug)", description, ansi::red);}
    void error(const char* message, const char* description, const char* color) const;
};