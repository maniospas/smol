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
#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "utils/common.h"

// Utility for suffix parsing
size_t parse_integer_suffix(const string& line, size_t i);
using namespace std;

class Token;  // forward

class Import {
public:
    string path;
    size_t pair;
    size_t parse_progress;
    size_t forward_p;//this is used to mark the point up to which imports are concluded
    string about;
    unordered_map<string, string> docs;
    bool allow_unsafe;
    Import(const string& p);
    vector<Token> tokens;
    string& at(size_t pos);
    void error(size_t pos, const string& message);
    size_t size();
    ~Import() = default;
};

class Token {
public:
    string name;
    size_t line;
    size_t character;
    shared_ptr<Import> imp;
    Token();
    Token(const string& n, size_t l, size_t c, const shared_ptr<Import>& i);
    string show() const;
    ~Token() = default;
};

shared_ptr<Import> tokenize(const string& path);

#endif // TOKENIZE_H
