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
#include "../../def.h"

string Def::recommend_runtype(const Types& types, const Variable& candidate) {
    int min_distance = numeric_limits<int>::max();
    string recommendation = "";
    for(const auto& it : types.vars) {
        if(it.first == candidate) 
            continue; // don't recommend itself
        string it_first = it.first.to_string();
        if(it_first.size()>=2 && it_first[0]=='_' && it_first[1]=='_')
            continue;
        if(it_first.find("____") != std::string::npos)
            continue;
        int distance = 4*sellersMinimumEditDistance(candidate.to_string(), it_first)
                           +sellersMinimumEditDistance(it_first, candidate.to_string());
        if(distance<min_distance) {
            min_distance = distance;
            recommendation = it.first.to_string();
        }
    }
    if(!recommendation.size()) 
        return "";
    return "\nDo you mean `"+recommendation+"`?";
}

string Def::recommend_variable(const Types& types, const Variable& candidate) {
    int min_distance = numeric_limits<int>::max();
    string recommendation = "";
    for(const auto& it : vars) 
        if(!released[it.first] && it.first!=candidate) {
            string it_first = it.first.to_string();
            if(it_first.size()>=2 && it_first[0]=='_' && it_first[1]=='_')
                continue;
            if(it_first.find("____") != std::string::npos)
                continue;
            int distance = 4*sellersMinimumEditDistance(candidate.to_string(), it_first)
                           +sellersMinimumEditDistance(it_first, candidate.to_string()); // it_first can have extra trailing characters at small cost (our current writing may just be incomplete)
            if(distance<min_distance) {
                min_distance = distance;
                recommendation = it_first;
            }
        }
    if(!recommendation.size()) // need at least two characters to gain some sense 
        return "";
    return "\nDo you mean `"+pretty_var(recommendation)+"`?";
}
