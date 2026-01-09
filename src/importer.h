#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>

namespace ansi {
    extern const char* red;
    extern const char* purple;
    extern const char* cyan;
    extern const char* green;
    extern const char* yellow;
    extern const char* gray;
    extern const char* reset;
}

class Importer {
    std::ifstream file;
    size_t line;
    size_t column;
    std::string current_line;
    std::string path;
    size_t start, end; // track these for errors
public:
    Importer(const std::string& path): file(path), line(0), column(0), current_line(""), path(path) {}
    ~Importer() = default;
    size_t get_token_start() const {
        return start;
    }
    bool next_line() {
        if(!line && !column && !file.is_open()) {
            error("Broken import", "The file does not exist");
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
    const std::string_view next() {
        auto ret = _next_token();
        while(ret.empty()) {
            if(!next_line()) return ret;
            ret = _next_token();
        }
        return ret;
    }
    void rollback_token();
    const std::string_view _next_token();
    inline void error(const char* message, const char* description) {error(message, description, ansi::yellow);}
    inline void format_error(const char* description) {error("Format error", description, ansi::green);}
    inline void syntax_error(const char* description) {error("Syntax error", description, ansi::yellow);}
    inline void type_error(const char* description) {error("Type error", description, ansi::purple);}
    void error(const char* message, const char* description, const char* color);
};

bool is_delim(char c);