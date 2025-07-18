#ifndef SEGMENTS_H
#define SEGMENTS_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
#include <mutex>
#include <iostream>
#include <algorithm>
#include <functional> // for std::hash

class SegmentMap {
public:
    int get_id(const std::string& seg) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = seg_to_id.find(seg);
        if (it != seg_to_id.end()) return it->second;
        int id = id_to_seg.size();
        seg_to_id[seg] = id;
        id_to_seg.push_back(seg);
        return id;
    }

    const std::string& get_segment(int id) const {
        return id_to_seg.at(id);
    }

    static SegmentMap& instance() {
        static SegmentMap inst;
        return inst;
    }
private:
    std::unordered_map<std::string, int> seg_to_id;
    std::vector<std::string> id_to_seg;
    mutable std::mutex mutex_;
};


class SegmentedString {
public:
    std::vector<int> segments;

    SegmentedString() = default;
    SegmentedString(const std::string& input) {
        if(!input.size()) return;
        size_t pos = 0, next;
        while ((next = input.find("__", pos)) != std::string::npos) {
            std::string seg = input.substr(pos, next-pos);
            segments.push_back(SegmentMap::instance().get_id(seg));
            pos = next + 2;
        }
        std::string last = input.substr(pos);
        if (!last.empty() || segments.empty())
            segments.push_back(SegmentMap::instance().get_id(last));
    }
    SegmentedString(const std::vector<int>& ids) : segments(ids) {}

    bool is_empty() const {return !segments.size();}
    bool exists() const {return segments.size();}
    bool is_private() const {return segments.size() && SegmentMap::instance().get_segment(segments[0]).size();}

    std::string to_string() const {
        std::ostringstream oss;
        for (size_t i = 0; i < segments.size(); ++i) {
            if (i > 0) oss << "__";
            oss << SegmentMap::instance().get_segment(segments[i]);
        }
        return oss.str();
    }

    SegmentedString operator+(const SegmentedString& other) const {
        std::vector<int> result = segments;
        result.insert(result.end(), other.segments.begin(), other.segments.end());
        return SegmentedString(result);
    }

    bool operator==(const SegmentedString& other) const { return segments == other.segments; }
    bool operator!=(const SegmentedString& other) const { return segments != other.segments; }
    bool operator<(const SegmentedString& other) const { return segments < other.segments; }

    friend std::ostream& operator<<(std::ostream& os, const SegmentedString& ss) {
        os << ss.to_string();
        return os;
    }

    bool operator==(const std::string& s) const {
        size_t pos = 0;
        for (size_t i = 0; i < segments.size(); ++i) {
            const std::string& seg = SegmentMap::instance().get_segment(segments[i]);
            size_t seg_len = seg.length();
            if (s.compare(pos, seg_len, seg) != 0) return false;
            pos += seg_len;
            if (i + 1 < segments.size()) {
                if (s.compare(pos, 2, "__") != 0) return false;
                pos += 2;
            }
        }
        return pos == s.length();
    }
};

// std::hash specialization for SegmentedString
namespace std {
    template <>
    struct hash<SegmentedString> {
        std::size_t operator()(const SegmentedString& s) const noexcept {
            std::size_t h = 0;
            // FNV-1a or similar combination, but simple XOR+hash is enough for most
            for (auto id : s.segments) h ^= std::hash<int>()(id) + 0x9e3779b9 + (h << 6) + (h >> 2);
            return h;
        }
    };
}

inline bool operator==(const std::string& lhs, const SegmentedString& rhs) {return rhs == lhs;}
inline bool operator!=(const std::string& lhs, const SegmentedString& rhs) {return !(rhs == lhs);}

#endif // SEGMENTS_H
