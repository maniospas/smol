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
#include "../def.h"

Code Def::rebase(const Code& impl, const Variable& var) {
    if(impl.is_empty()) 
        return impl;
    vector<SegmentedString> segments;
    segments.reserve(impl.size());
    for(size_t i=0; i<impl.size(); ++i) 
        segments.push_back(contains(impl[i])?var+impl[i]:impl[i]);
    return Code(move(segments));
}

Code Def::rename_var(const Code& impl, const Variable& from, const Variable& to) {
    if(impl.is_empty()) 
        return impl;
    vector<SegmentedString> segments;
    segments.reserve(impl.size());
    for(size_t i=0; i<impl.size(); ++i) 
        segments.push_back(impl[i] == from?to:impl[i]);
    return Code(move(segments));
}

Code Def::rename_var(const Code& impl, const Variable& from, const Code& to) {
    if(impl.is_empty()) 
        return impl;
    vector<SegmentedString> segments;
    segments.reserve(impl.size());
    for(size_t i=0; i<impl.size(); ++i) {
        if(impl[i] == from) 
            for(const auto& it : to.segments)
                segments.push_back(it);
        else 
            segments.push_back(impl[i]);
    }
    return Code(move(segments));
}
