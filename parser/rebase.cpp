string rebase(string& impl, const string& var) {
    stringstream input(impl);
    string line, output;
    while (getline(input, line)) {
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
            output += internalTypes.vars.find(prev_token)!=internalTypes.vars.end() ? var + "__" + token : token;
        }
        output += '\n';
    }
    return output;
}

string rebase(string& impl, const string& var, const Memory& keep_parent, bool noskip=true) {
    stringstream input(impl);
    string line, output;
    while (getline(input, line)) {
        size_t i = 0;
        bool in_str = false;
        while (i < line.size()) {
            if (line[i] == '"' && (i == 0 || line[i - 1] != '\\')) { output += line[i++]; in_str = !in_str; continue; }
            if (in_str) { output += line[i++]; continue; }
            while (i < line.size() && isspace(line[i])) output += line[i++];
            if (i >= line.size()) break;
            if (is_symbol(line[i])) { output += line[i++]; continue; }
            size_t start = i;
            while (i < line.size() && !isspace(line[i]) && !is_symbol(line[i])) i++;
            string token = line.substr(start, i - start);
            string prev_token = token;
            if(keep_parent.vars.find(prev_token)!=keep_parent.vars.end() && token!="__finally"
                && (
                    internalTypes.vars.find(prev_token)==internalTypes.vars.end()
                    || keep_parent.vars.find(prev_token)->second==internalTypes.vars.find(prev_token)->second
                )) {if(noskip) output += token; else output += "__unused__"+token;}
                else output += internalTypes.vars.find(prev_token)!=internalTypes.vars.end() ? var + "__" + token : token;
        }
        output += '\n';
    }
    return output;
}
