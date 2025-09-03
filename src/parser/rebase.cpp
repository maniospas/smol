#include "../def.h"

Code Def::rebase(const Code& impl, const Variable& var) {
    if(impl.is_empty()) 
        return impl;
    std::vector<SegmentedString> segments;
    segments.reserve(impl.size());
    for (size_t i = 0; i < impl.size(); ++i) {
        if(internalTypes.contains(impl[i])) 
            segments.push_back(var + impl[i]);
        else 
            segments.push_back(impl[i]);
    }
    return Code(segments);
}

Code Def::rename_var(const Code& impl, const Variable& from, const Variable& to) {
    if(impl.is_empty()) 
        return impl;
    std::vector<SegmentedString> segments;
    segments.reserve(impl.size());
    for (size_t i = 0; i < impl.size(); ++i) {
        if (impl[i] == from) 
            segments.push_back(to);
        else 
            segments.push_back(impl[i]);
    }
    return Code(segments);
}
