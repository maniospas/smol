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

#endif // FASTSTRING_H
