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
        int distance = sellersMinimumEditDistance(
            candidate.to_string(), 
            it.first.to_string())+sellersMinimumEditDistance(it.first.to_string(), 
            candidate.to_string()
        );
        if(distance<min_distance) {
            min_distance = distance;
            recommendation = it.first.to_string();
        }
    }
    if(!recommendation.size()) 
        return recommendation;
    if(recommendation.size()>=2 
        && recommendation[0]=='_' 
        && recommendation[1]=='_') 
        return "";
    return "\nDid you mean "+recommendation+"?";
}

string Def::recommend_variable(const Types& types, const Variable& candidate) {
    int min_distance = numeric_limits<int>::max();
    string recommendation = "";
    for(const auto& it : internalTypes.vars) if(!released[it.first]) {
        int distance = sellersMinimumEditDistance(
            candidate.to_string(), 
            it.first.to_string())+sellersMinimumEditDistance(it.first.to_string(), 
            candidate.to_string()
        );
        if(distance<min_distance) {
            min_distance = distance;
            recommendation = it.first.to_string();
        }
    }
    if(!recommendation.size()) 
        return recommendation;
    if(recommendation.size()>=2 && recommendation[0]=='_' && recommendation[1]=='_') 
        return "";
    return "\nDid you mean "+pretty_var(recommendation)+"?";
}
