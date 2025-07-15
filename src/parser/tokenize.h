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
    size_t pair;
    bool allow_unsafe;
    string about;
    unordered_map<string, string> docs;
    Import(const string& p): path(p), allow_unsafe(false) {}
    vector<Token> tokens;
    string& at(size_t pos);
    void error(size_t pos, const string& message);
    size_t size() {return tokens.size();}
};
bool is_symbol(char c) {return ispunct(c) && c != '_';}

#include <sstream>

class Token {
public:
    string name;
    size_t line;
    size_t character;
    shared_ptr<Import> imp;
    Token() {}
    Token(const string& n, size_t l, size_t c, const shared_ptr<Import>& i) : name(n), line(l), character(c), imp(i) {}
    string show() const {
        if (!imp || imp->path.empty()) return "[no file]";
        ifstream file(imp->path);
        if (!file) return imp->path;
        string current;
        size_t current_line = 1;
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
        size_t display_col = 0;
        for (size_t i = 0, col = 1; i < current.size() && col < character; ++i) {
            if (current[i] == '\t') {
                display_col += 4;
                col++;
            } else {
                display_col += 1;
                col++;
            }
        }
        string red_marker = "\033[31m" + string(display_col, ' ') +"^" + string(name.size()-1, '^') + "\033[0m";
        return "at \033[90m "+imp->path+" line "+to_string(line)+" col "+to_string(character)+"\033[0m\n"+expanded_line + "\n" + red_marker;
    }
};

string& Import::at(size_t pos) {
    if(pos<0) ERROR("Tried to read before the beginning of file: "+path);
    if(pos>=tokens.size()) ERROR("Premature end of file: "+path+"\n"+tokens[pos-1].show());
    return tokens[pos].name;
}
void Import::error(size_t pos, const string& message) {
    if(pos<0) ERROR("Tried to read before the beginning of file: "+path);
    if(pos>=tokens.size()) ERROR("Premature end of file: "+path+"\n"+tokens[pos-1].show());
    ERROR(message+"\n"+tokens[pos].show());
}auto tokenize(const string& path) {
    ifstream file(path);
    if (!file) ERROR("Could not open file: " + path);
    string line;
    size_t line_num = 0;
    auto main_file = make_shared<Import>(path);
    vector<Token>& tokens = main_file->tokens;
    size_t in_brackets = 0;
    while(getline(file, line)) {
        line_num++;
        size_t i = 0;
        size_t col = 1;
        while(i < line.size()) {
            while (i < line.size() && isspace(line[i])) {if (line[i] == '\t') col += 4; else col++;i++;}
            if(i >= line.size()) break;
            if(line[i] == '/' && i + 1 < line.size() && line[i + 1] == '/') break;
            size_t start = i;
            size_t start_col = col;
            string prefix("");
            if (line[i] == '"') {
                i++;
                col++;
                // Parse string literal, allowing escaped quotes
                while (i < line.size()) {
                    if (line[i] == '"') {
                        // Count number of backslashes before this quote
                        size_t backslashes = 0;
                        size_t j = i;
                        while (j > start && line[j-1] == '\\') { backslashes++; j--; }
                        if (backslashes % 2 == 0) {
                            // even: not escaped, string ends
                            break;
                        }
                    }
                    if (line[i] == '\t') col += 4;
                    else col++;
                    i++;
                }
                if(i >= line.size()) ERROR("String segments can only span one line\n"+tokens[tokens.size()-1].show());
                i++; // skip closing quote
                col++;
                string current_str_token = (prefix + line.substr(start, i - start));
                // Merge with previous string token if possible
                if (!tokens.empty() && 
                    !tokens.back().name.empty() && 
                    tokens.back().name.front() == '"' && 
                    tokens.back().name.back() == '"' &&
                    !current_str_token.empty() && 
                    current_str_token.front() == '"' && 
                    current_str_token.back() == '"') 
                {
                    // Merge: remove the ending quote from previous and starting quote from current, then join
                    tokens.back().name = 
                        tokens.back().name.substr(0, tokens.back().name.size() - 1) + 
                        current_str_token.substr(1);
                } else {
                    tokens.emplace_back(current_str_token, line_num, start_col, main_file);
                }
            }
            else if(!in_brackets && line[i]=='+') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("add", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++;
                col++;
                continue;
            }
            else if(!in_brackets && line[i]=='-' && i && line[i-1]!='-' && i<line.size()-1 && line[i+1]!='-' && line[i+1]!='>') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("sub", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; col++;
                continue;
            }
            else if(!in_brackets && line[i]=='*') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("mul", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; col++;
                continue;
            }
            else if(!in_brackets && line[i]=='/') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("div", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; col++;
                continue;
            }
            else if(!in_brackets && line[i]=='%') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("mod", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; col++;
                continue;
            }
            else if(!in_brackets && line[i]=='>' && i<line.size()-1 && line[i+1]=='=') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("geq", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i+=2; col+=2;
                continue;
            }
            else if(!in_brackets && line[i]=='<' && i<line.size()-1 && line[i+1]=='=') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("leq", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i+=2; col+=2;
                continue;
            }
            else if(!in_brackets && line[i]=='<') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("lt", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; col++;
                continue;
            }
            else if(!in_brackets && line[i]=='>' && i && line[i-1]!='-' && line[i-1]!='>') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("gt", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; col++;
                continue;
            }
            else if(!in_brackets && line[i]=='=' && i<line.size()-1 && line[i+1]=='=') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("eq", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i+=2; col+=2;
                continue;
            }
            else if(!in_brackets && line[i]=='!' && i<line.size()-1 && line[i+1]=='=') {
                tokens.emplace_back(":", line_num, col, main_file);
                tokens.emplace_back("neq", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i+=2; col+=2;
                continue;
            }
            else if(is_symbol(line[i])) {
                if(line[i]=='{') in_brackets++;
                else if(line[i]=='}' && in_brackets) in_brackets--;
                tokens.emplace_back(string(1, line[i]), line_num, col, main_file);
                i++; col++;
                continue;
            }
            else if(isdigit(line[i]) || (line[i] == '.' && i + 1 < line.size() && isdigit(line[i + 1]))) {
                bool has_dot = false;
                if(line[i] == '.') has_dot = true;
                while(i < line.size() && (isdigit(line[i]) || (line[i] == '.' && !has_dot))) {
                    if(line[i] == '.') has_dot = true;
                    i++; col++;
                }
                tokens.emplace_back(line.substr(start, i - start), line_num, start_col, main_file);
            }
            else {
                while(i < line.size() && !isspace(line[i]) && !is_symbol(line[i])) {i++; col++;}
                if(start < i) {
                    string substr = line.substr(start, i - start);
                    if(substr=="elif") {
                        tokens.emplace_back("else", line_num, start_col, main_file);
                        tokens.emplace_back("-", line_num, start_col, main_file);
                        tokens.emplace_back(">", line_num, start_col, main_file);
                        tokens.emplace_back("if", line_num, start_col, main_file);
                    }
                    else tokens.emplace_back(substr, line_num, start_col, main_file);
                }
            }
        }
    }
    return main_file;
}




#endif // TOKENIZE_H
