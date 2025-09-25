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
#include "common.h"
#include <iostream>
#include <limits>
#include <regex>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <sstream>

using namespace std;

// Convert ANSI escape codes to HTML
string ansi_to_html(const string& input) {
    string output = input;
    output = regex_replace(output, regex("\033\\[31m"), "</span><span style=\"color:#c0392b\">");
    output = regex_replace(output, regex("\033\\[32m"), "</span><span style=\"color:#2E7D32\">");
    output = regex_replace(output, regex("\033\\[33m"), "</span><span style=\"color:#f39c12\">");
    output = regex_replace(output, regex("\033\\[34m"), "</span><span style=\"color:#2980b9\">");
    output = regex_replace(output, regex("\033\\[36m"), "</span><span style=\"color:#1976D2\">");
    output = regex_replace(output, regex("\033\\[35m"), "</span><span style=\"color:#7B1FA2\">");
    output = regex_replace(output, regex("\033\\[38m"), "</span><span style=\"color:black\">");
    output = regex_replace(output, regex("\033\\[0m"), "</span><span>");
    return "<span>" + output + "</span>";
}

string pretty_var(const string& name) {
    if(name.size() >= 2 && name[0] == '_' && name[1] == '_') return "";
    string result;
    size_t i = 0;
    while(i < name.size()) {
        if(i && name[i] == '_' && i+1 < name.size() && name[i+1] == '_' && name[i-1] != '_') {
            result += '.';
            i += 2;
        }
        else if(i && name[i] == '_' && i+1 < name.size() && name[i+1] == '_') {
            i += 2;
            while(i < name.size() && name[i] == '_') i++;
            while(i < name.size() && name[i] != '_') i++;
        }
        else result += name[i++];
    }
    if(result.size() >= 4 && result.substr(result.size()-4) == "type") 
        result = result.substr(0, result.size()-4);
    while(!result.empty() && result.back() == '.') 
        result.pop_back();
    return result;
}

string pretty_runtype(const string& name) {
    if(name=="i64" || name=="f64" || name=="ptr" || name=="bool" ||
       name=="nominal" || name=="char" || name=="u64" || name=="cstr") 
        return "\033[35m" + name + "\033[0m";
    return "\033[36m" + name + "\033[0m";
}

int min2(int a, int b) {
    return (a < b) ? a : b;
}
int min3(int a, int b, int c) {
    return min2(min2(a, b), c);
}

int sellersMinimumEditDistance(const string& pattern, const string& text) {
    int m = pattern.size();
    int n = text.size();
    vector<vector<int>> E(m + 1, vector<int>(n + 1));
    for(int j = 0; j <= n; ++j) 
        E[0][j] = 0;
    for(int i = 1; i <= m; ++i) 
        E[i][0] = i;
    for(int i = 1; i <= m; ++i) 
        for(int j = 1; j <= n; ++j) {
            int cost = (pattern[i - 1] == text[j - 1]) ? 0 : 1;
            E[i][j] = min3(
                E[i - 1][j] + 1, 
                E[i][j - 1] + 1, 
                E[i - 1][j - 1] + cost
            );
        }
    int minDist = numeric_limits<int>::max();
    for(int j = 0; j <= n; ++j) minDist = min2(minDist, E[m][j]);
    return minDist;
}

bool is_primitive(const string& name) {
    if(name=="true"||name=="false") return true;
    const char* s=name.c_str(); while(isspace(*s)) ++s; if(*s=='\0') return false;
    char* e;
    if(s[0]=='0'&&(s[1]=='x'||s[1]=='X')){ strtol(s,&e,16); if(e!=s+2&&*e=='\0') return true; }
    else if(s[0]=='0'&&(s[1]=='b'||s[1]=='B')){ const char* p=s+2; if(*p){ while(*p=='0'||*p=='1') ++p; if(*p=='\0') return true; } }
    else if(s[0]=='0'&&(s[1]=='o'||s[1]=='O')){ const char* p=s+2; if(*p){ while(*p>='0'&&*p<='7') ++p; if(*p=='\0') return true; } }
    strtol(s,&e,10); if(e!=s&&*e=='\0') return true;
    strtod(s,&e);    if(e!=s&&*e=='\0') return true;
    if(name.size()>=2&&name.front()=='"'&&name.back()=='"') return true;
    return false;
}

string type_primitive(const string& name) {
    if(name=="true"||name=="false") return "bool";
    const char* s=name.c_str(); while(isspace(*s)) ++s; if(*s=='\0') return "CANNOT DETECT TYPE";
    char* e;
    if(s[0]=='0'&&(s[1]=='x'||s[1]=='X')){ strtol(s,&e,16); if(e!=s+2&&*e=='\0') return "u64"; }
    else if(s[0]=='0'&&(s[1]=='b'||s[1]=='B')){ const char* p=s+2; if(*p){ while(*p=='0'||*p=='1') ++p; if(*p=='\0') return "u64"; } }
    else if(s[0]=='0'&&(s[1]=='o'||s[1]=='O')){ const char* p=s+2; if(*p){ while(*p>='0'&&*p<='7') ++p; if(*p=='\0') return "u64"; } }
    strtol(s,&e,10); if(e!=s&&*e=='\0') return "u64";
    strtod(s,&e);    if(e!=s&&*e=='\0') return "f64";
    if(name.size()>=2&&name.front()=='"'&&name.back()=='"') return "cstr";
    return "";
}


bool accepted_var_name(const string& name) {
    return !(name=="(" || name==")" || name=="{" || name=="}" ||
             name=="[" || name=="]" ||
             name=="|" || name==":" || name=="&" || name=="=" ||
             name=="-" || name=="," || name=="." ||
             name=="def" || name=="service" || name=="union" ||
             name=="if" || name=="while" || name=="elif" || name=="err" ||
             name=="with" || name=="else" || name=="@");
}

bool is_symbol(const string& s) {
    return s.size() == 1 &&
           ispunct(static_cast<unsigned char>(s[0])) &&
           s != "_";
}

bool is_symbol(char c) {
    return ispunct(static_cast<unsigned char>(c)) && c != '_';
}

bool is_symbol_or_digit(const string& s) {
    return s.size() == 1 &&
           (ispunct(static_cast<unsigned char>(s[0])) ||
            isdigit(static_cast<unsigned char>(s[0])));
}

bool is_digits(const string& s) {
    for(char ch : s) 
        if(!isdigit(static_cast<unsigned char>(ch))) 
            return false;
    return !s.empty();
}

bool is_digits_part(const string& s) {
    for(char ch : s) 
        if(!isdigit(static_cast<unsigned char>(ch)) &&
            ch!='X' && ch!='x' && ch!='U' && ch!='u' &&
            ch!='L' && ch!='l' && ch!='e' && ch!='E')
            return false;
    return !s.empty();
}



string unescape_string(const string& input) {
    ostringstream out;
    // Start at 1 to skip opening quote, end at size()-1 to skip closing quote
    for(size_t i = 1; i + 1 < input.size(); ++i) {
        if(input[i] == '\\' && i + 1 < input.size() - 1) {
            char next = input[i + 1];
            switch (next) {
                case 'n': out << '\n'; break;
                case 't': out << '\t'; break;
                case 'r': out << '\r'; break;
                case '"': out << '"'; break;
                case '\\': out << '\\'; break;
                default: out << next; break; // unknown escape, emit as-is
            }
            ++i; // skip the next character, it's part of escape
        } else {
            out << input[i];
        }
    }
    // Wrap with quotes to match how you output string tokens
    return '"' + out.str() + '"';
}

void replaceAll(string& str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Move past the replacement
    }
}

string html_escape(const string& code) {
    string out;
    for(char c : code) {
        switch (c) {
            case '&': out += "&amp;"; break;
            case '<': out += "&lt;"; break;
            case '>': out += "&gt;"; break;
            case '"': out += "&quot;"; break;
            default: out += c;
        }
    }
    return out;
}
