
string recommend_runtypes(const Memory& types, const string& candidate) {
    int min_distance = numeric_limits<int>::max();
    string recommendation = "";
    for(const auto& it : types.vars) {
        double distance = sellersMinimumEditDistance(candidate, it.first);
        if(distance<min_distance) {
            min_distance = distance;
            recommendation = it.first;
        }
    }
    if(!recommendation.size()) return recommendation;
    return "\nDid you mean "+recommendation+"?";
}

string recommend_variable(const Memory& types, const string& candidate) {
    int min_distance = numeric_limits<int>::max();
    string recommendation = "";
    for(const auto& it : internalTypes.vars) {
        double distance = sellersMinimumEditDistance(candidate, it.first);
        if(distance<min_distance) {
            min_distance = distance;
            recommendation = it.first;
        }
    }
    if(!recommendation.size()) return recommendation;
    return "\nDid you mean "+pretty_var(recommendation)+"?";
}
