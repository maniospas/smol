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
    ReusableString(const string& name);
    ReusableString(const ReusableString& other) = default;
    ReusableString(ReusableString&& other) noexcept = default;
    ReusableString& operator=(const ReusableString& other) = default;
    ReusableString& operator=(ReusableString&& other) noexcept = default;

    bool operator==(const ReusableString& other) const { return id==other.id; }
    bool operator!=(const ReusableString& other) const { return id!=other.id; }
    size_t get_id() const { return id; }
    const string& name() const { return id2name.at(id); }
};

namespace std {
    template<> struct hash<ReusableString> {
        size_t operator()(const ReusableString& rs) const {
            return hash<size_t>()(rs.get_id());
        }
    };
}

class ReusableText {
public:
    vector<ReusableString> contents;
    ReusableText() = default;
    void parse(const string& text);
    string text();
};

#endif // FASTSTRING_H
