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
