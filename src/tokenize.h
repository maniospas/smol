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
size_t parse_integer_suffix(const std::string& line, size_t i);

class Token;  // forward

class Import {
public:
    std::string path;
    size_t pair;
    bool allow_unsafe;
    std::string about;
    std::unordered_map<std::string, std::string> docs;
    Import(const std::string& p);
    std::vector<Token> tokens;
    std::string& at(size_t pos);
    void error(size_t pos, const std::string& message);
    size_t size();
};

class Token {
public:
    std::string name;
    size_t line;
    size_t character;
    std::shared_ptr<Import> imp;
    Token();
    Token(const std::string& n, size_t l, size_t c, const std::shared_ptr<Import>& i);
    std::string show() const;
};

std::shared_ptr<Import> tokenize(const std::string& path);

#endif // TOKENIZE_H
