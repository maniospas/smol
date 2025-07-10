#include "../def.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <regex>
#include <memory>

void Def::simplify() {
    /*static const std::regex gotoLabel(R"(^\s*goto\s+([A-Za-z_][A-Za-z0-9_]*)\s*;\s*$)");
    static const std::regex label(R"(^\s*([A-Za-z_][A-Za-z0-9_]*)\s*:\s*$)");
    static const std::regex varName(R"([A-Za-z_][A-Za-z0-9_]*)");

    std::vector<std::string> rawLines;
    std::stringstream in(implementation);
    std::string line;
    while (std::getline(in, line)) rawLines.push_back(line);
    for (size_t i = 0; i < rawLines.size(); ++i) {
        std::smatch m1, m2;
        if (i + 1 < rawLines.size() &&
            std::regex_match(rawLines[i], m1, gotoLabel) &&
            std::regex_match(rawLines[i + 1], m2, label) &&
            m1[1].str() == m2[1].str()) {
            ++i;
            continue;
        }
    }
    std::unordered_map<std::string, std::string> varRename;
    auto rename_in_string = [&](std::string& text) {
        std::string result;
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), varName);
        auto words_end = std::sregex_iterator();
        size_t lastPos = 0;

        for (auto it = words_begin; it != words_end; ++it) {
            std::string match = it->str();
            size_t pos = it->position();

            result += text.substr(lastPos, pos - lastPos);

            if (match.rfind("__", 0) == 0) {
                if (!varRename.count(match)) varRename[match] = create_temp();
                result += varRename[match];
            } else {
                result += match;
            }
            lastPos = pos + match.size();
        }
        result += text.substr(lastPos);
        text = result;
    };

    rename_in_string(vardecl);
    rename_in_string(errors);
    rename_in_string(implementation);


    std::unordered_map<std::string, std::string> new_finals;
    for (auto& kv : finals) {
        rename_in_string(kv.second);
        std::string newKey = kv.first;
        if (newKey.rfind("__", 0) == 0 && varRename.count(newKey)) newKey = varRename[newKey];
        new_finals[newKey] = kv.second;
    }
    std::unordered_map<std::string, std::string> new_invalidators;
    for (auto& kv : invalidators) {
        rename_in_string(kv.second);
        std::string newKey = kv.first;
        if (newKey.rfind("__", 0) == 0 && varRename.count(newKey)) newKey = varRename[newKey];
        new_invalidators[newKey] = kv.second;
    }
    std::unordered_map<std::string, Type> new_types;
    for (auto& kv : internalTypes.vars) {
        std::string newKey = kv.first;
        if (newKey.rfind("__", 0) == 0 && varRename.count(newKey)) newKey = varRename[newKey];
        new_types[newKey] = kv.second;
    }
    std::unordered_map<std::string, Type> new_buffer_primitive_associations;
    for (auto& kv : buffer_primitive_associations) {
        std::string newKey = kv.first;
        if (newKey.rfind("__", 0) == 0 && varRename.count(newKey)) newKey = varRename[newKey];
        new_buffer_primitive_associations[newKey] = kv.second;
    }
    std::unordered_map<std::string, unsigned long> new_alignments;
    for (auto& kv : alignments) {
        std::string newKey = kv.first;
        new_alignments[newKey] = kv.second;
        if (newKey.rfind("__", 0) == 0 && varRename.count(newKey)) newKey = varRename[newKey];
        new_alignments[newKey] = kv.second;
    }
    std::unordered_set<std::string> new_mutables;
    for (const auto& name : mutables) {
        if (name.rfind("__", 0) == 0 && varRename.count(name)) new_mutables.insert(varRename[name]);
        else new_mutables.insert(name);
    }
    for(auto& arg : args) if (arg.name.rfind("__", 0) == 0 && varRename.count(arg.name)) arg.name = varRename[arg.name];
    for(auto& pack : packs) if (pack.rfind("__", 0) == 0 && varRename.count(pack)) pack = varRename[pack];

    finals.swap(new_finals);
    mutables.swap(new_mutables);
    invalidators.swap(new_invalidators);
    buffer_primitive_associations.swap(new_buffer_primitive_associations);
    alignments.swap(new_alignments);
    internalTypes.vars.swap(new_types);*/
}


/*
void Def::simplify() {
    static const std::regex assign(R"(^\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*([A-Za-z_][A-Za-z0-9_]*)\s*;\s*$)");
    std::unordered_map<std::string, std::string> next;
    std::vector<std::string> rawLines;
    std::stringstream in(implementation);
    std::string line;
    while (std::getline(in, line)) {
        std::smatch m;
        if (std::regex_match(line, m, assign)) {
            if((mutables.find(m[1].str())==mutables.end())==(mutables.find(m[2].str())==mutables.end()))
            next[m[1].str()] = m[2].str();
        }
        rawLines.push_back(line);
    }
    std::unordered_map<std::string, std::string> repCache;
    auto findRep = [&](const std::string& v) -> const std::string& {
        auto it = repCache.find(v);
        if (it != repCache.end()) return it->second;

        std::string cur = v;
        std::unordered_set<std::string> visited;
        while (true) {
            auto it2 = next.find(cur);
            if (it2 == next.end() || !visited.insert(cur).second) {
                break; // Reached a sink or detected a cycle.
            }
            cur = it2->second; // Follow the chain.
        }
        for (const std::string& n : visited) repCache[n] = cur;
        return repCache.emplace(v, cur).first->second;
    };

    std::vector<std::string> newLines;
    for (const std::string& ln : rawLines) {
        std::smatch m;
        if (!std::regex_match(ln, m, assign)) {
            newLines.push_back(ln); // Keep unmatched segments too.
            continue;
        }
        const std::string& lhsRep = findRep(m[1].str());
        const std::string& rhsRep = findRep(m[2].str());
        if (lhsRep == rhsRep) continue;
        newLines.emplace_back(lhsRep + " = " + rhsRep + ";");
    }
    std::ostringstream out;
    for (size_t i = 0; i < newLines.size(); ++i) {
        out << newLines[i];
        if (i + 1 < newLines.size()) out << '\n';
    }
    cout << name << implementation.size() << " -> ";
    implementation = out.str();
    cout <<out.str().size()<<"\n";
    for (std::string& p : packs) p = findRep(p);
    unordered_map<string, string> new_finals;
    unordered_map<string, string> new_invalidators;
    unordered_map<string, Type> new_buffer_primitive_associations;
    unordered_map<string, unsigned long> new_alignments; 
    unordered_set<string> new_mutables;
    for (auto& kv : finals) new_finals[findRep(kv.first)] += kv.second;
    for (auto& kv : invalidators) new_invalidators[findRep(kv.first)] += kv.second;
    for (auto& kv : buffer_primitive_associations) new_buffer_primitive_associations[findRep(kv.first)] = kv.second;
    for (auto& kv : alignments) alignments[findRep(kv.first)] = kv.second;
    for (auto& kv : mutables) new_mutables.insert(findRep(kv));
    for (auto& arg : args) arg.name = findRep(arg.name);


    finals.swap(new_finals);
    mutables.swap(new_mutables);
    invalidators.swap(new_invalidators);
    new_buffer_primitive_associations.swap(new_buffer_primitive_associations);
}
*/