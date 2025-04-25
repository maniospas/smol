#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <cctype>
#include "common.h"
using namespace std;

class Token;
class Import {
public:
    string path;
    int pair;
    Import(const string& p): path(p) {}
    vector<Token> tokens;
    string& at(int pos);
    void error(int pos, const string& message);
    int size() {return tokens.size();}
};
bool is_symbol(char c) {return ispunct(c) && c != '_';}

class Token {
public:
    string name;
    shared_ptr<Import> imp;
    int line;
    int character;
    Token(const string& n, int l, int c, const shared_ptr<Import>& i) : name(n), line(l), character(c), imp(i) {}
    string show() const {
        if (!imp || imp->path.empty()) return "[no file]";
        ifstream file(imp->path);
        if (!file) return imp->path;
        string current;
        int current_line = 1;
        while (getline(file, current)) {
            if (current_line == line) break;
            current_line++;
        }
        if (current_line != line) return imp->path;
        string expanded_line;
        for (char c : current) {
            if (c == '\t') expanded_line += "    ";
            else expanded_line += c;
        }
        int display_col = 0;
        for (int i = 0, col = 1; i < current.size() && col < character; ++i) {
            if (current[i] == '\t') {
                display_col += 4;
                col++;
            } else {
                display_col += 1;
                col++;
            }
        }
        string red_marker = "\033[31m" + string(display_col, ' ') +"^" + string(name.size()-1, '^') + "\033[0m";
        return "at \033[90m "+imp->path+" line "+to_string(line)+"\033[0m\n"+expanded_line + "\n" + red_marker;
    }
};

string& Import::at(int pos) {
    if(pos<0) ERROR("Tried to read before the beginning of file: "+path);
    if(pos>=tokens.size()) ERROR("Premature end of file: "+path);
    return tokens[pos].name;
}
void Import::error(int pos, const string& message) {
    if(pos<0) ERROR("Tried to read before the beginning of file: "+path);
    if(pos>=tokens.size()) ERROR("Premature end of file: "+path);
    ERROR(message+"\n"+tokens[pos].show());
}
auto tokenize(const string& path) {
    ifstream file(path);
    if (!file) ERROR("Could not open file: " + path);
    string line;
    int line_num = 0;
    auto main_file = make_shared<Import>(path);
    vector<Token>& tokens = main_file->tokens;
    while (getline(file, line)) {
        line_num++;
        int i = 0;
        int col = 1;
        while (i < line.size()) {
            while (i < line.size() && isspace(line[i])) {if (line[i] == '\t') col += 4; else col++;i++;}
            if (i >= line.size()) break;
            if (line[i] == '\\' && i + 1 < line.size() && line[i + 1] == '\\') break;
            int start = i;
            int start_col = col;
            if (line[i] == '"') {
                // String literal
                i++;
                col++;
                while (i < line.size() && line[i] != '"') {
                    if (line[i] == '\t') col += 4;
                    else col++;
                    i++;
                }
                if (i < line.size() && line[i] == '"' && line[i-1]!='\\') {
                    i++;
                    col++;
                }
                tokens.emplace_back(line.substr(start, i - start), line_num, start_col, main_file);
            }
            else if (is_symbol(line[i])) {
                tokens.emplace_back(string(1, line[i]), line_num, col, main_file);
                i++;
                col++;
                continue;
            }
            else if (isdigit(line[i]) || (line[i] == '.' && i + 1 < line.size() && isdigit(line[i + 1]))) {
                bool has_dot = false;
                if (line[i] == '.') has_dot = true;
                while (i < line.size() && (isdigit(line[i]) || (line[i] == '.' && !has_dot))) {
                    if (line[i] == '.') has_dot = true;
                    i++;
                    col++;
                }
                tokens.emplace_back(line.substr(start, i - start), line_num, start_col, main_file);
            }
            else {
                while (i < line.size() && !isspace(line[i]) && !is_symbol(line[i])) {
                    i++;
                    col++;
                }
                if (start < i) tokens.emplace_back(line.substr(start, i - start), line_num, start_col, main_file);
            }
        }
    }
    return main_file;
}


#endif // TOKENIZE_H
