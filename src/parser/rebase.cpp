#include "../def.h"

/*static bool is_unescaped_quote(const string& line, size_t pos) {
    if(line[pos] != '"') return false;
    int backslash_count = 0;
    for(int i = (int)pos - 1; i >= 0 && line[i] == '\\'; --i) backslash_count++;
    return backslash_count % 2 == 0;
}*/

Code Def::rebase(const Code& impl, const Variable& var) {
    if (impl.is_empty()) return impl;
    std::vector<SegmentedString> segments;
    segments.reserve(impl.size()); // pre-allocate
    for (size_t i = 0; i < impl.size(); ++i) {
        if (internalTypes.contains(impl[i])) segments.push_back(var + impl[i]);
        else segments.push_back(impl[i]);
    }
    return Code(segments);
}

Code Def::rename_var(const Code& impl, const Variable& from, const Variable& to) {
    if (impl.is_empty()) return impl;
    std::vector<SegmentedString> segments;
    segments.reserve(impl.size());
    for (size_t i = 0; i < impl.size(); ++i) {
        if (impl[i] == from) segments.push_back(to);
        else segments.push_back(impl[i]);
    }
    return Code(segments);
}
