string rebase(const string& impl, const string& var) {
    stringstream input(impl);
    string line, output;
    while(getline(input, line)) {
        size_t i = 0; bool in_str = false;
        while (i < line.size()) {
            if (line[i] == '"' && (i == 0 || line[i - 1] != '\\')) { output += line[i++]; in_str = !in_str; continue; }
            if (in_str) { output += line[i++]; continue; }
            while (i < line.size() && isspace(line[i])) output += line[i++];
            if (i >= line.size()) break;
            if (is_symbol(line[i])) { output += line[i++]; continue; }
            int start = i;
            while (i < line.size() && !isspace(line[i]) && !is_symbol(line[i])) i++;
            string token = line.substr(start, i - start);
            string prev_token = token;
            bool found = internalTypes.contains(prev_token);
            output += found ? var + "__" + token : token;
        }
        output += '\n';
    }
    return output;
}

string rename_var(const string& impl, const string& from, const string& to) {
    stringstream input(impl);
    string line, output;
    while(getline(input, line)) {
        size_t i = 0; bool in_str = false;
        while (i < line.size()) {
            if (line[i] == '"' && (i == 0 || line[i - 1] != '\\')) { output += line[i++]; in_str = !in_str; continue; }
            if (in_str) { output += line[i++]; continue; }
            while (i < line.size() && isspace(line[i])) output += line[i++];
            if (i >= line.size()) break;
            if (is_symbol(line[i])) { output += line[i++]; continue; }
            int start = i;
            while (i < line.size() && !isspace(line[i]) && !is_symbol(line[i])) i++;
            string token = line.substr(start, i - start);
            string prev_token = token;
            output += token==from ? to : token;
        }
        output += '\n';
    }
    return output;
}