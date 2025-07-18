#ifndef SEGMENTS_H
#define SEGMENTS_H

#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <mutex>
#include <iostream>
#include <algorithm>

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
    std::vector<int> segments;
public:
    SegmentedString(const std::string& input) {
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
    friend std::ostream& operator<<(std::ostream& os, const SegmentedString& ss) {
        os << ss.to_string();
        return os;
    }
    bool operator==(const std::string& s) const {
        size_t pos = 0;
        for (size_t i = 0; i < segments.size(); ++i) {
            const std::string& seg = SegmentMap::instance().get_segment(segments[i]);
            size_t seg_len = seg.length();
            // Check if next part matches segment
            if (s.compare(pos, seg_len, seg) != 0)
                return false;
            pos += seg_len;
            // After each segment except last, expect "__"
            if (i + 1 < segments.size()) {
                if (s.compare(pos, 2, "__") != 0)
                    return false;
                pos += 2;
            }
        }
        // If anything left in s, not equal
        return pos == s.length();
    }
};


#endif // SEGMENTS_H