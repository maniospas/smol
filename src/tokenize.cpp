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
#include <iostream>

// ---------- parse_integer_suffix ----------
size_t parse_integer_suffix(const string& line, size_t i) {
    bool found_u = false;
    int l_count = 0;

    for(int n = 0; n < 3 && i < line.size(); ++n) {
        char c = line[i];
        if((c == 'u' || c == 'U') && !found_u) {
            found_u = true;
            ++i;
        } else if((c == 'l' || c == 'L') && l_count < 2) {
            l_count++;
            ++i;
        } else {
            break;
        }
    }
    return i;
}

// ---------- Import ----------
Import::Import(const string& p)
    : path(p), pair(0), parse_progress(0), forward_p(0), allow_unsafe(false) {}


auto premature_end = string{"Premature end of file\n"};
const string& Import::at(size_t pos) {
    if(pos >= tokens.size()) 
        return premature_end;//path;
        //return "Premature end of file: " + path;  
    //ERROR("Premature end of file: " + path + "\n" + tokens[pos - 1].show());
    return tokens[pos].name;
}

void Import::error(size_t pos, const string& message) {
    if(pos >= tokens.size()) 
        pos = tokens.size()-1;
        //ERROR("Premature end of file: " + path + "\n" + tokens[pos - 1].show());
    ERROR(message + "\n" + tokens[pos].show());
}

size_t Import::size() {
    return tokens.size();
}

// ---------- Token ----------
Token::Token() 
    : line(0), character(0) {}

Token::Token(const string& n, size_t l, size_t c, const shared_ptr<Import>& i)
    : name(n), line(l), character(c), imp(i) {}

string Token::show() const {
    if(!imp || imp->path.empty()) 
        return "[no file]";

    ifstream file(imp->path);
    if(!file) 
        return imp->path;

    string current;
    size_t current_line = 1;
    while(getline(file, current)) {
        if(current_line == line) break;
        current_line++;
    }
    if(current_line != line)
        return imp->path;

    string expanded_line;
    for(char c : current) {
        if(c == '\t') expanded_line += "    ";
        else expanded_line += c;
    }

    size_t display_col = 0;
    for(size_t i = 0, col = 1; i < current.size() && col < character; ++i) {
        if(current[i] == '\t') {
            display_col += 4;
            col++;
            continue;
        }
        display_col++;
        col++;
    }

    string red_marker =
        "\033[31m" +
        string(display_col, ' ') +
        "^" +
        string(name.size() - 1, '^') +
        "\033[0m";

    return "at \033[90m " + imp->path +
           " line " + to_string(line) +
           " col " + to_string(character) +
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
    auto in_brackets = size_t{0};
    auto in_parentheses = size_t{0};
    auto parentheses_indent = size_t{0};
    auto& tokens = main_file->tokens;
    main_file->indentation_mode = true;
    size_t last_nonempty_indent = 0;
    string last_nonempty_content;
    size_t prev_indent = 0;

    auto is_blank = [](const string& s) {
        for(char c : s)
            if(!isspace(static_cast<unsigned char>(c))) return false;
        return true;
    };

    while(getline(file, line)) {
        line_num++;
        if(is_blank(line))
            continue;
        string trimmed_line = line;
        trimmed_line.erase(0, trimmed_line.find_first_not_of(" \t"));
        if(trimmed_line.rfind("//", 0) == 0)
            continue;
        if(line.starts_with("@serial")) {
            if(line_num!=1) {
                tokens.emplace_back("@serial", line_num, 1, main_file);
                main_file->error(
                    tokens.size() ? tokens.size()-1 : 0,
                    "`@serial` can only be the first statement of a file. "
                    + to_string(line_num)
                );
            }
            if(line!="@serial" && line!="@serial ") {
                tokens.emplace_back("@serial", line_num, 1, main_file);
                main_file->error(
                    tokens.size() ? tokens.size()-1 : 0,
                    "`@serial` can only be a single statement in a separate line. "
                    + to_string(line_num)
                );
            }
            main_file->indentation_mode = false;
            continue;
        }
        size_t indent = 0;
        for(char c : line) {
            if(c == ' ') indent++;
            else if(c == '\t') indent += 4;
            else break;
        }
        if (main_file->indentation_mode && indent%4) {
            tokens.emplace_back(line, line_num, 1, main_file);
            main_file->error(
                tokens.size() ? tokens.size()-1 : 0,
                "Indentation expects tabs or multiples of 4 spaces (switch to `@serial` mode to allow this syntax)"
            );
        }
        if (main_file->indentation_mode && indent>prev_indent+4) {
            tokens.emplace_back(line, line_num, 1, main_file);
            main_file->error(
                tokens.size() ? tokens.size()-1 : 0,
                "Cannot indent more than 4 spaces or a tab deeper than the previous line"
            );
        }
        if(main_file->indentation_mode && !in_parentheses && indent <= last_nonempty_indent) {
            string trimmed_prev = last_nonempty_content;
            trimmed_prev.erase(0, trimmed_prev.find_first_not_of(" \t"));
            if(trimmed_prev.starts_with("if ") 
                || trimmed_prev.starts_with("else ") 
                || trimmed_prev.starts_with("elif ")
                || trimmed_prev.starts_with("while ")
                || trimmed_prev.starts_with(".while ")
                || trimmed_prev.starts_with(".if ")
            ) {
                tokens.emplace_back("then", line_num-1, 1, main_file);
                tokens.emplace_back("ok", line_num-1, 1, main_file);
            }
        }
        if(main_file->indentation_mode && !in_parentheses && indent < last_nonempty_indent && !in_brackets && last_nonempty_content.size()>=indent+4) {
            string trimmed_prev = last_nonempty_content;
            trimmed_prev.erase(0, 4+indent);
            if(!trimmed_prev.starts_with("then ") 
                && !trimmed_prev.starts_with("return ")
                && !trimmed_line.starts_with("elif ")
                && !trimmed_line.starts_with("else ")
            ) {
                tokens.emplace_back("then", line_num-1, 1, main_file);
                tokens.emplace_back("ok", line_num-1, 1, main_file);
            }
        }
        last_nonempty_indent = indent;
        last_nonempty_content = line;
        prev_indent = indent;

        auto i = size_t{0};
        auto col = size_t{1};

        while(i < line.size()) {
            while(i < line.size() && isspace(line[i])) {
                if(line[i] == '\t') 
                    col += 4; 
                else 
                    col++;
                i++;
            }
            if(i >= line.size()) 
                break;
            if(line[i] == '/' && i + 1 < line.size() && line[i + 1] == '/') 
                break;
            auto start = i;
            auto start_col = col;
            auto prefix = string{""};
            if(line[i] == '"') {
                i++;
                col++;
                // Parse string literal, allowing escaped quotes
                while(i < line.size()) {
                    if(line[i] == '"') {
                        // Count number of backslashes before this quote
                        size_t backslashes = 0;
                        size_t j = i;
                        while(j > start && line[j-1] == '\\') { backslashes++; j--; }
                        if(backslashes % 2 == 0) {
                            // even: not escaped, string ends
                            break;
                        }
                    }
                    if(line[i] == '\t') col += 4;
                    else col++;
                    i++;
                }
                //if(i >= line.size()) ERROR("String segments can only span one line\n"+tokens[tokens.size()-1].show());
                if(i >= line.size()) 
                    tokens.emplace_back("String segments can only span one line", line_num, start_col, main_file);
                i++; // skip closing quote
                col++;
                string current_str_token = (prefix + line.substr(start, i - start));
                // Merge with previous string token if possible
                if(!tokens.empty() 
                    && !tokens.back().name.empty()
                    && tokens.back().name.front() == '"' 
                    && tokens.back().name.back() == '"' 
                    && !current_str_token.empty()
                    && current_str_token.front() == '"' 
                    && current_str_token.back() == '"'
                ) {
                    // Merge: remove the ending quote from previous and starting quote from current, then join
                    tokens.back().name = 
                        tokens.back().name.substr(0, tokens.back().name.size() - 1) 
                        + current_str_token.substr(1);
                } 
                else 
                    tokens.emplace_back(current_str_token, line_num, start_col, main_file);
            }
            else if(!in_brackets && line[i]=='+') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("add", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++;
                col++;
                continue;
            }
            else if(!in_brackets && line[i]=='-' && i && line[i-1]!='-' && i<line.size()-1 && line[i+1]!='-' && line[i+1]!='>') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("sub", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; 
                col++;
                continue;
            }
            else if(!in_brackets && line[i]=='*') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("mul", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; 
                col++;
                continue;
            }
            else if(!in_brackets && line[i]=='/') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("div", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; 
                col++;
                continue;
            }
            else if(!in_brackets && line[i]=='%') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("mod", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++;
                col++;
                continue;
            }
            else if(!in_brackets && line[i]=='>' && i<line.size()-1 && line[i+1]=='=') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("geq", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i += 2; 
                col += 2;
                continue;
            }
            else if(!in_brackets && line[i]=='<' && i<line.size()-1 && line[i+1]=='=') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("leq", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i += 2; 
                col += 2;
                continue;
            }
            else if(!in_brackets && line[i]=='<') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("lt", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; 
                col++;
                continue;
            }
            else if(!in_brackets && line[i]=='>' && i && line[i-1]!='-' && line[i-1]!='>') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("gt", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i++; 
                col++;
                continue;
            }
            else if(!in_brackets && line[i]=='=' && i<line.size()-1 && line[i+1]=='=') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("eq", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i += 2; 
                col += 2;
                continue;
            }
            else if(!in_brackets && line[i]=='!' && i<line.size()-1 && line[i+1]=='=') {
                tokens.emplace_back(".", line_num, col, main_file);
                tokens.emplace_back("neq", line_num, col, main_file);
                tokens.emplace_back("__consume", line_num, col, main_file);
                i += 2; 
                col += 2;
                continue;
            }
            else if(is_symbol(line[i])) {
                if(line[i]=='{') in_brackets++;
                else if(line[i]=='}' && in_brackets) in_brackets--;
                if(line[i]=='(') {
                    if(!in_parentheses) parentheses_indent=indent; 
                    in_parentheses++;
                }
                else if(line[i]==')' && in_parentheses) {
                    in_parentheses--;
                    if(!in_parentheses && parentheses_indent!=indent && main_file->indentation_mode) {
                        tokens.emplace_back(string(1, line[i]), line_num, col, main_file);
                        main_file->error(tokens.size() - 1, "Top-level parenthesis cannot close in a line with a different indent than its start");
                    }
                }
                tokens.emplace_back(string(1, line[i]), line_num, col, main_file);
                i++; 
                col++;
                continue;
            }
            else if(isdigit(line[i]) || (line[i] == '.' && i + 1 < line.size() && isdigit(line[i + 1]))) {
                auto number_start = i;
                auto number_col = col;
                // Handle hex, octal, binary literals
                if(line[i] == '0' && i + 1 < line.size()) {
                    if(line[i + 1] == 'x' || line[i + 1] == 'X') {
                        i += 2; 
                        col += 2;
                        auto hex_start = i;
                        while(i < line.size() && isxdigit(line[i])) { i++; col++; }
                        if(hex_start == i)
                            tokens.emplace_back("Invalid hexadecimal number", line_num, number_col, main_file);
                            //ERROR("Invalid hexadecimal number\n" + Token(line.substr(number_start, i-number_start), line_num, number_col, main_file).show());
                        auto suffix_end = parse_integer_suffix(line, i);
                        col += (suffix_end - i);
                        i = suffix_end;
                        tokens.emplace_back(line.substr(number_start, i - number_start), line_num, number_col, main_file);
                        continue;
                    } else if(line[i + 1] == 'b' || line[i + 1] == 'B') {
                        i += 2; 
                        col += 2;
                        auto bin_start = i;
                        while(i < line.size() && (line[i] == '0' || line[i] == '1')) { 
                            i++;
                            col++;
                        }
                        if(bin_start == i)
                            tokens.emplace_back("Invalid binary number", line_num, number_col, main_file);
                            //ERROR("Invalid binary number\n" + Token(line.substr(number_start, i-number_start), line_num, number_col, main_file).show());
                        auto suffix_end = parse_integer_suffix(line, i);
                        col += (suffix_end - i);
                        i = suffix_end;
                        tokens.emplace_back(line.substr(number_start, i - number_start), line_num, number_col, main_file);
                        continue;
                    } else if(line[i + 1] == 'o' || line[i + 1] == 'O') {
                        i += 2; 
                        col += 2;
                        auto oct_start = i;
                        while(i < line.size() && (line[i] >= '0' && line[i] <= '7')) {
                            i++;
                            col++;
                        }
                        if(oct_start == i)
                            tokens.emplace_back("Invalid octal number", line_num, number_col, main_file);
                            //ERROR("Invalid octal number\n" + Token(line.substr(number_start, i-number_start), line_num, number_col, main_file).show());
                        auto suffix_end = parse_integer_suffix(line, i);
                        col += (suffix_end - i);
                        i = suffix_end;
                        tokens.emplace_back(line.substr(number_start, i - number_start), line_num, number_col, main_file);
                        continue;
                    }
                }
                // Decimal/floating point
                auto has_dot = line[i] == '.';
                while(i < line.size() && (isdigit(line[i]) || (line[i] == '.' && !has_dot))) {
                    if(line[i] == '.') 
                        has_dot = true;
                    i++; 
                    col++;
                }
                // Accept integer suffixes (not for floats, but safe to include for now)
                auto suffix_end = parse_integer_suffix(line, i);
                col += (suffix_end - i);
                i = suffix_end;
                tokens.emplace_back(line.substr(number_start, i - number_start), line_num, number_col, main_file);
            }

            else {
                while(i < line.size() && !isspace(line[i]) && !is_symbol(line[i])) {
                    i++; 
                    col++;
                }
                if(start < i) {
                    auto substr = line.substr(start, i - start);

                    if(substr=="elif") {
                        tokens.emplace_back("else", line_num, start_col, main_file);
                        tokens.emplace_back("then", line_num, start_col, main_file);
                        tokens.emplace_back("if", line_num, start_col, main_file);
                    }
                    else tokens.emplace_back(substr, line_num, start_col, main_file);
                    if(main_file->indentation_mode && substr=="then")
                            main_file->error(tokens.size() - 1, "`then` is available only in `@serial` mode");
                    if (main_file->indentation_mode && (substr == "if" || substr == "while") && !in_brackets) {
                        bool valid =
                            (start_col == indent + 1) || 
                            (!tokens.empty() &&
                            tokens.size() >= 2 &&
                            tokens[tokens.size()-2].line == line_num &&
                            (tokens[tokens.size()-2].name == ".") &&
                            tokens[tokens.size()-2].character == indent + 1);
                        if (!valid) 
                            main_file->error(
                                tokens.size() - 1,
                                "`" + substr + "` must start either immediately after the indentation "
                                "or after a '.' immediately after the indentation (switch to `@serial` mode to allow this syntax)"
                            );
                    }
                    else if (main_file->indentation_mode && (substr == "else" || substr == "elif" || substr == "return") && !in_brackets) {
                        if (start_col != indent + 1) 
                            main_file->error(
                                tokens.size() - 1,
                                "`" + substr + "` must start immediately after the indentation (switch to `@serial` mode to allow this syntax)"
                            );
                    }
                }
            }
        }
    }
    return main_file;
}
