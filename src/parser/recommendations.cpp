
string recommend_runtype(const Memory& types, const string& candidate) {
    int min_distance = numeric_limits<int>::max();
    string recommendation = "";
    for(const auto& it : types.vars) {
        int distance = sellersMinimumEditDistance(candidate, it.first)+sellersMinimumEditDistance(it.first, candidate);
        if(distance<min_distance) {
            min_distance = distance;
            recommendation = it.first;
        }
    }
    if(!recommendation.size()) return recommendation;
    if(recommendation.size()>=2 && recommendation[0]=='_' && recommendation[1]=='_') return "";
    return "\nDid you mean "+recommendation+"?";
}

string recommend_variable(const Memory& types, const string& candidate) {
    int min_distance = numeric_limits<int>::max();
    string recommendation = "";
    for(const auto& it : internalTypes.vars) {
        int distance = sellersMinimumEditDistance(candidate, it.first)+sellersMinimumEditDistance(it.first, candidate);
        if(distance<min_distance) {
            min_distance = distance;
            recommendation = it.first;
        }
    }
    if(!recommendation.size()) return recommendation;
    if(recommendation.size()>=2 && recommendation[0]=='_' && recommendation[1]=='_') return "";
    return "\nDid you mean "+pretty_var(recommendation)+"?";
}
