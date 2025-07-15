#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

inline void ERROR(const string& message) {
    size_t newline_pos = message.find('\n');
    string first_line = (newline_pos == string::npos) ? message : message.substr(0, newline_pos);
    string rest = (newline_pos == string::npos) ? "" : message.substr(newline_pos + 1);
    string formatted_message = "\033[33m" + first_line + "\033[0m";
    if (!rest.empty()) formatted_message += "\n" + rest;
    throw runtime_error(formatted_message);
}


string pretty_var(const string& name) {
    if(name.size()>=2 && name[0]=='_' && name[1]=='_') return "";
    string result;
    size_t i = 0;
    while (i < name.size()) {
        if(i && name[i]=='_' && i+1<name.size() && name[i+1]=='_' && name[i - 1] != '_') {result += '.';i += 2;}
        else if(i && name[i]=='_' && i+1<name.size() && name[i+1]=='_') {result += "";i+=2;while(i<name.size() && name[i]=='_')i++;while(i<name.size() && name[i]!='_')i++;}
        else result += name[i++];
    }
    if(result.size()>=4 && result.substr(result.size()-4)=="type") result = result.substr(0, result.size()-4);
    while(result.size() && result[result.size()-1]=='.') result = result.substr(0, result.size()-1);
    return result;
}

string pretty_runtype(const string& name) {
    if(name=="i64" || name=="f64" || name=="ptr" || name=="bool" || name=="nom" || name=="char" || name=="u64" || name=="cstr")return "\033[35m" + name + "\033[0m";
    return "\033[36m" + name + "\033[0m";
}

int min2(int a, int b) {return (a < b) ? a : b;}
int min3(int a, int b, int c) {return min2(min2(a, b), c);}

int sellersMinimumEditDistance(const string& pattern, const string& text) {
    int m = pattern.size();
    int n = text.size();
    vector<vector<int>> E(m + 1, vector<int>(n + 1));
    for (int j = 0; j <= n; ++j) E[0][j] = 0;
    for (int i = 1; i <= m; ++i) E[i][0] = i;
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
        int cost = (pattern[i - 1] == text[j - 1]) ? 0 : 1;
        E[i][j] = min3(E[i - 1][j] + 1, E[i][j - 1] + 1, E[i - 1][j - 1] + cost);
    }
    int minDist = numeric_limits<int>::max();
    for (int j = 0; j <= n; ++j) minDist = min2(minDist, E[m][j]);
    return minDist;
}

bool is_primitive(const string& name) {
    if (name == "true" || name == "false") return true;
    const char* str = name.c_str();
    char* end;
    while (isspace(*str)) ++str;
    if (*str == '\0') return false;
    std::strtol(str, &end, 10);
    if (end != str && *end == '\0') return true;
    std::strtod(str, &end);
    if (end != str && *end == '\0') return true;
    if (name.size() >= 2 && name.front() == '"' && name.back() == '"') return true;
    return false;
}

string type_primitive(const string& name) {
    if (name == "true" || name == "false") return "bool";
    const char* str = name.c_str();
    char* end;
    while (isspace(*str)) ++str;
    if (*str == '\0') return "CANNOT DETECT TYPE";
    std::strtol(str, &end, 10);
    if (end != str && *end == '\0') return "u64";
    std::strtod(str, &end);
    if (end != str && *end == '\0') return "f64";
    if (name.size() >= 2 && name.front() == '"' && name.back() == '"') return "cstr";
    return "CANNOT DETECT TYPE";
}

bool accepted_var_name(const string& name) {return !(name=="(" || name==")" || name=="{" || name=="}" || name == "|" ||  name == ":" || name=="&" || name=="=" || name=="-" || name=="," || name=="." || name=="smo" || name=="@");}
bool is_symbol(const std::string& s) {return s.size() == 1 && std::ispunct(static_cast<unsigned char>(s[0])) && s != "_";}

#endif // COMMON_H
