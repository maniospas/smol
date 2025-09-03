#ifndef FASTSTRING_H
#define FASTSTRING_H

#include <string>
#include <unordered_map>
#include <sstream>
#include "common.h"

using namespace std;

class ReusableString {
    size_t id;
    static unordered_map<string, size_t> name2id;
    static unordered_map<size_t, string> id2name;
    ReusableString() : id((size_t)-1) {}
public:
    ReusableString(const string& name) {
        if(name2id.find(name)==name2id.end()) {
            id = name2id.size();
            if(id==(size_t)-1) ERROR("Too many unique tokens in source code (should normally be impossible)");
            name2id[name] = id;
            id2name[id] = name;
        } 
        else 
            id = name2id[name];
    }
    ReusableString(const ReusableString& other) = default;
    ReusableString(ReusableString&& other) noexcept = default;
    ReusableString& operator=(const ReusableString& other) = default;
    ReusableString& operator=(ReusableString&& other) noexcept = default;
    bool operator==(const ReusableString& other) const {
        return id==other.id;
    }
    bool operator!=(const ReusableString& other) const {
        return id!=other.id;
    }
    size_t get_id() const {
        return id;
    }
    const string& name() const {
        return id2name.at(id); 
    }
};
unordered_map<string, size_t> ReusableString::name2id;
unordered_map<size_t, string> ReusableString::id2name;
namespace std {template<> struct hash<ReusableString> {
    size_t operator()(const ReusableString& rs) const {
        return hash<size_t>()(rs.get_id());}
    };
}

class ReusableText {
public:
    vector<ReusableString> contents;
    ReusableText() = default;
    void parse(const string& text) {
        stringstream input(text);
        string line;
        while (getline(input, line)) {
            size_t i = 0;
            bool in_str = false;
            string output;
            while (i < line.size()) {
                if(line[i] == '"' && (i == 0 || line[i - 1] != '\\')) {
                    output += line[i++];
                    in_str = !in_str;
                    continue;
                }
                if(in_str) {
                    output += line[i++];
                    continue;
                }
                while(i < line.size() && isspace(line[i])) {
                    output += line[i++];
                }
                if(i >= line.size()) 
                    break;
                if (is_symbol(string(1, line[i]))) {
                    contents.emplace_back(string(1, line[i++]));
                    continue;
                }
                int start = i;
                while(i < line.size() && !isspace(line[i]) && !is_symbol(line[i])) 
                    i++;
                string token = line.substr(start, i - start);
                contents.emplace_back(token);
            }
        }
    }
    string text() {
        string ret;
        for(ReusableString token : contents) 
            ret += token.name()+" ";
        return ret;
    }
};



#endif // FASTSTRING_H