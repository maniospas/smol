#include "faststring.h"

unordered_map<string, size_t> ReusableString::name2id;
unordered_map<size_t, string> ReusableString::id2name;

ReusableString::ReusableString(const string& name) {
    if(name2id.find(name)==name2id.end()) {
        id = name2id.size();
        if(id==(size_t)-1) 
            ERROR("Too many unique tokens in source code (should normally be impossible)");
        name2id[name] = id;
        id2name[id] = name;
    } 
    else 
        id = name2id[name];
}
