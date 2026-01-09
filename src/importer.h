#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>

namespace ansi {
    static const char* red = "\033[31m";
    static const char* yellow = "\033[33m";
    static const char* gray = "\033[90m";
    static const char* reset = "\033[0m";
}

class Importer {
    std::ifstream file;
    size_t line;
    size_t column;
    std::string current_line;
    std::string path;
    size_t start, end; // track these for errors
    static bool is_delim(char c) {
        return c == '(' || c == ')' || c == '@' || c == ',' || c == '.';
    }
public:
    Importer(const std::string& path): file(path), line(0), column(0), current_line(""), path(path) {}
    ~Importer() = default;
    size_t get_column() {
        return column;
    }
    bool next_line() {
        if(!std::getline(file, current_line)) 
            return false;
        ++line;
        column = 0;
        while(column < current_line.size() && current_line[column]==' ')
            ++column;
        return true;
    }
    const std::string_view next_token_autoline() {
        if(column>=current_line.size())
            next_line();
        return next_token();
    }
    const std::string_view next_token() {
        start = column;
        end = column;
        while(true) {
            if(column>=current_line.size()) {
                end = column;
                break;
            }
            char c = current_line[column];
            if((c==' ' || c=='\t') && column==start) {
                ++column;
                ++start;
                continue;
            }
            if(c==' ') {
                ++column;
                end = column-1;
                break;
            }
            if(is_delim(c)) {
                if(start==column) end = ++column;
                else end = column;
                break;
            }
            ++column;
        }
        return std::string_view(current_line.data()+start, end - start);
    }

    void error(const char* message, const char* description) {
        std::ostringstream caret;
        for (size_t i = 0; i < start; ++i) caret << ' ';
        for (size_t i = start; i < end; ++i) caret << '^';
        const std::string header_text = std::string(" ")+message+" ";
        const std::string description_text = std::string(description);
        const std::string location = "at " + path + " line " + std::to_string(line);
        size_t content_width = std::max({
            header_text.size(),
            description_text.size(),
            location.size(),
            current_line.size(),
            caret.str().size(),
            size_t{60}
        });
        auto repeat = [](const std::string& s, size_t n) {
            std::string out;
            out.reserve(s.size() * n);
            for (size_t i = 0; i < n; ++i) out += s;
            return out;
        };
        size_t left_pad  = 2;
        size_t right_pad = content_width - header_text.size();
        std::cout << ansi::yellow << "╭"
                << repeat("─", left_pad)
                << ansi::yellow << header_text
                << ansi::yellow
                << repeat("─", right_pad)
                << "╮\n";
        auto line_box = [&](const std::string& s, const char* text_color) {
            std::cout << ansi::yellow << "│ "
                    << text_color << s
                    << std::string(content_width - s.size(), ' ')
                    << ansi::yellow << " │\n";
        };
        line_box(location, ansi::gray);
        line_box(current_line, ansi::gray);
        line_box(caret.str(), ansi::red);
        line_box(description_text, ansi::reset);
        std::cout << ansi::yellow << "╰"
                << repeat("─", content_width + 2)
                << "╯" << ansi::reset << "\n";
        throw std::runtime_error(message);
    }

};