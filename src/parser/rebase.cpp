#include "../def.h"

Code Def::rebase(const Code& impl, const Variable& var) {
    if(impl.is_empty()) 
        return impl;
    vector<SegmentedString> segments;
    segments.reserve(impl.size());
    for(size_t i=0; i<impl.size(); ++i) 
        segments.push_back(internalTypes.contains(impl[i])?var+impl[i]:impl[i]);
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
