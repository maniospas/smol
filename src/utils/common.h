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
// Copyright 2025 Emmanouil Krasanakis (maniospas@hotmail.com)
// Licensed under the Apache License, Version 2.0 (the "License");
// ...

#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// ERROR is inline because it throws and should be visible everywhere
inline void ERROR(const string& message) {
    size_t newline_pos = message.find('\n');
    string first_line = (newline_pos == string::npos) ? message : message.substr(0, newline_pos);
    string rest = (newline_pos == string::npos) ? "" : message.substr(newline_pos + 1);
    string formatted_message = "\033[33m" + first_line + "\033[0m";
    if(!rest.empty()) 
        formatted_message += "\n" + rest;
    throw runtime_error(formatted_message);
}

// Function declarations
string ansi_to_html(const string& input);
string pretty_var(const string& name);
string pretty_runtype(const string& name);

size_t min2(size_t a, size_t b);
size_t min3(size_t a, size_t b, size_t c);
size_t sellersMinimumEditDistance(const string& pattern, const string& text);

bool is_primitive(const string& name);
string type_primitive(const string& name);
bool accepted_var_name(const string& name);

bool is_symbol(const string& s);
bool is_symbol(char c);
bool is_symbol_or_digit(const string& s);
bool is_digits(const string& s);
bool is_digits_part(const string& s);

string unescape_string(const string& input);
void replaceAll(string& str, const string& from, const string& to);
string html_escape(const string& code);

#endif // COMMON_H
