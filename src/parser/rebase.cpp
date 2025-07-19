#include "../def.h"

static bool is_unescaped_quote(const string& line, size_t pos) {
    if(line[pos] != '"') return false;
    int backslash_count = 0;
    for(int i = (int)pos - 1; i >= 0 && line[i] == '\\'; --i) backslash_count++;
    return backslash_count % 2 == 0;
}

string Def::rebase(const string& impl, const Variable& _var) {
    string var = _var.to_string();
    stringstream input(impl);
    string line, output;
    while(getline(input, line)) {
        size_t i = 0; bool in_str = false;
        while(i < line.size()) {
            if(is_unescaped_quote(line, i)) { output += line[i++]; in_str = !in_str; continue; }
            if(in_str) { output += line[i++]; continue; }
            if(isspace(line[i])) { output += line[i++]; continue; }
            if(is_symbol(line[i])) { output += line[i++]; continue; }
            int start = i;
            while(i < line.size() && !isspace(line[i]) && !is_symbol(line[i]) && !(line[i] == '"' && is_unescaped_quote(line, i))) i++;
            string token = line.substr(start, i - start);
            bool found = internalTypes.contains(token);
            output += found ? var + "__" + token : token;
        }
        output += '\n';
    }
    return output;
}

string Def::rename_var(const string& impl, const Variable& _from, const Variable& _to) {
    string from = _from.to_string();
    string to = _to.to_string();
    stringstream input(impl);
    string line, output;
    while(getline(input, line)) {
        size_t i = 0; bool in_str = false;
        while(i < line.size()) {
            if(is_unescaped_quote(line, i)) { output += line[i++]; in_str = !in_str; continue; }
            if(in_str) { output += line[i++]; continue; }

            if(isspace(line[i])) { output += line[i++]; continue; }
            if(is_symbol(line[i])) { output += line[i++]; continue; }

            int start = i;
            while(i < line.size() && !isspace(line[i]) && !is_symbol(line[i]) && !(line[i] == '"' && is_unescaped_quote(line, i))) i++;
            string token = line.substr(start, i - start);
            output += token == from ? to : token;
        }
        output += '\n';
    }
    return output;
}
