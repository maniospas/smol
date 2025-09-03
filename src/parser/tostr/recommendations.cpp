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
