// Copyright 2025 Emmanouil Krasanakis (maniospas@hotmail.com)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "tokenize.h"
#include <fstream>
#include <sstream>
#include <cctype>

// ---------- parse_integer_suffix ----------
size_t parse_integer_suffix(const std::string& line, size_t i) {
    bool found_u = false;
    int l_count = 0;

    for (int n = 0; n < 3 && i < line.size(); ++n) {
        char c = line[i];
        if ((c == 'u' || c == 'U') && !found_u) {
            found_u = true;
            ++i;
        } else if ((c == 'l' || c == 'L') && l_count < 2) {
            l_count++;
            ++i;
        } else {
            break;
        }
    }
    return i;
}

// ---------- Import ----------
Import::Import(const std::string& p)
    : path(p), pair(0), allow_unsafe(false) {}

std::string& Import::at(size_t pos) {
    if (pos < 0) 
        ERROR("Tried to read before the beginning of file: " + path);
    if (pos >= tokens.size()) 
        ERROR("Premature end of file: " + path + "\n" + tokens[pos - 1].show());
    return tokens[pos].name;
}

void Import::error(size_t pos, const std::string& message) {
    if (pos < 0) 
        ERROR("Tried to read before the beginning of file: " + path);
    if (pos >= tokens.size()) 
        ERROR("Premature end of file: " + path + "\n" + tokens[pos - 1].show());
    ERROR(message + "\n" + tokens[pos].show());
}

size_t Import::size() {
    return tokens.size();
}

// ---------- Token ----------
Token::Token() : line(0), character(0) {}

Token::Token(const std::string& n, size_t l, size_t c, const std::shared_ptr<Import>& i)
    : name(n), line(l), character(c), imp(i) {}

std::string Token::show() const {
    if (!imp || imp->path.empty()) 
        return "[no file]";

    std::ifstream file(imp->path);
    if (!file) 
        return imp->path;

    std::string current;
    size_t current_line = 1;
    while (getline(file, current)) {
        if (current_line == line) break;
        current_line++;
    }
    if (current_line != line)
        return imp->path;

    std::string expanded_line;
    for (char c : current) {
        if (c == '\t') expanded_line += "    ";
        else expanded_line += c;
    }

    size_t display_col = 0;
    for (size_t i = 0, col = 1; i < current.size() && col < character; ++i) {
        if (current[i] == '\t') {
            display_col += 4;
            col++;
            continue;
        }
        display_col++;
        col++;
    }

    std::string red_marker =
        "\033[31m" +
        std::string(display_col, ' ') +
        "^" +
        std::string(name.size() - 1, '^') +
        "\033[0m";

    return "at \033[90m " + imp->path +
           " line " + std::to_string(line) +
           " col " + std::to_string(character) +
           "\033[0m\n" +
           expanded_line + "\n" + red_marker;
}

// ---------- tokenize ----------
shared_ptr<Import> tokenize(const string& path) {
    auto file = ifstream{path};
    if(!file) 
        ERROR("Could not open file: " + path);
    auto line = string{""};
    auto line_num = size_t{0};
    auto main_file = make_shared<Import>(path);
    auto& tokens = main_file->tokens;
    auto in_brackets = size_t{0};
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
            else if (isdigit(line[i]) || (line[i] == '.' && i + 1 < line.size() && isdigit(line[i + 1]))) {
                size_t number_start = i;
                size_t number_col = col;
                // Handle hex, octal, binary literals
                if (line[i] == '0' && i + 1 < line.size()) {
                    if (line[i + 1] == 'x' || line[i + 1] == 'X') {
                        i += 2; col += 2;
                        size_t hex_start = i;
                        while (i < line.size() && isxdigit(line[i])) { i++; col++; }
                        if (hex_start == i)
                            ERROR("Invalid hexadecimal number\n" + Token(line.substr(number_start, i-number_start), line_num, number_col, main_file).show());
                        // <<<<<< ADD THIS >>>>>
                        size_t suffix_end = parse_integer_suffix(line, i);
                        col += (suffix_end - i);
                        i = suffix_end;
                        tokens.emplace_back(line.substr(number_start, i - number_start), line_num, number_col, main_file);
                        continue;
                    } else if (line[i + 1] == 'b' || line[i + 1] == 'B') {
                        i += 2; col += 2;
                        size_t bin_start = i;
                        while (i < line.size() && (line[i] == '0' || line[i] == '1')) { i++; col++; }
                        if (bin_start == i)
                            ERROR("Invalid binary number\n" + Token(line.substr(number_start, i-number_start), line_num, number_col, main_file).show());
                        size_t suffix_end = parse_integer_suffix(line, i);
                        col += (suffix_end - i);
                        i = suffix_end;
                        tokens.emplace_back(line.substr(number_start, i - number_start), line_num, number_col, main_file);
                        continue;
                    } else if (line[i + 1] == 'o' || line[i + 1] == 'O') {
                        i += 2; col += 2;
                        size_t oct_start = i;
                        while (i < line.size() && (line[i] >= '0' && line[i] <= '7')) { i++; col++; }
                        if (oct_start == i)
                            ERROR("Invalid octal number\n" + Token(line.substr(number_start, i-number_start), line_num, number_col, main_file).show());
                        size_t suffix_end = parse_integer_suffix(line, i);
                        col += (suffix_end - i);
                        i = suffix_end;
                        tokens.emplace_back(line.substr(number_start, i - number_start), line_num, number_col, main_file);
                        continue;
                    }
                }
                // Decimal/floating point
                bool has_dot = false;
                if(line[i] == '.') has_dot = true;
                while(i < line.size() && (isdigit(line[i]) || (line[i] == '.' && !has_dot))) {
                    if(line[i] == '.') has_dot = true;
                    i++; col++;
                }
                // Accept integer suffixes (not for floats, but safe to include for now)
                size_t suffix_end = parse_integer_suffix(line, i);
                col += (suffix_end - i);
                i = suffix_end;
                tokens.emplace_back(line.substr(number_start, i - number_start), line_num, number_col, main_file);
            }

            else {
                while(i < line.size() && !isspace(line[i]) && !is_symbol(line[i])) {i++; col++;}
                if(start < i) {
                    string substr = line.substr(start, i - start);
                    /*if (substr=="end") {
                        tokens.emplace_back("-", line_num, col, main_file);
                        tokens.emplace_back("-", line_num, col + 1, main_file);
                    }
                    else*/ if (substr=="return") {
                        tokens.emplace_back("-", line_num, col, main_file);
                        tokens.emplace_back(">", line_num, col + 1, main_file);
                    }
                    else if(substr=="elif") {
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
