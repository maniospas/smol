#ifndef COMMON_H
#define COMMON_H
#include <string>

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
    if(name.size()>=2 && name[0]=='_' && name[1]=='_') return "...";
    string result;
    size_t i = 0;
    while (i < name.size()) {
        if(i && name[i]=='_' && i+1<name.size() && name[i+1]=='_' && name[i - 1] != '_') {result += '.';i += 2;}
        else result += name[i++];
    }
    return result;
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
    if (end != str && *end == '\0') return "i64";
    std::strtod(str, &end);
    if (end != str && *end == '\0') return "f64";
    if (name.size() >= 2 && name.front() == '"' && name.back() == '"') return "cstr";
    return "CANNOT DETECT TYPE";
}

bool accepted_var_name(const string& name) {return !(name=="(" || name==")" || name=="{" || name=="}" || name == "|" || name=="&" || name=="=" || name=="-" || name=="," || name=="." || name=="smo" || name=="@" || name=="|");}
bool is_symbol(const std::string& s) {return s.size() == 1 && std::ispunct(static_cast<unsigned char>(s[0])) && s != "_";}

#endif // COMMON_H
