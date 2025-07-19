#ifndef SEGMENTS_H
#define SEGMENTS_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <mutex>
#include <iostream>
#include <algorithm>
#include <functional> // for std::hash

class SegmentMap {
public:
    int get_id(const std::string& seg) {
        //std::lock_guard<std::mutex> lock(mutex_);
        auto it = seg_to_id.find(seg);
        if (it != seg_to_id.end()) return it->second;
        unsigned int id = id_to_seg.size();
        seg_to_id[seg] = id;
        id_to_seg.push_back(seg);
        return id;
    }
    const std::string& get_segment(unsigned int id) const {return id_to_seg.at(id);}
    static SegmentMap& instance() {
        static SegmentMap inst;
        return inst;
    }
private:
    std::unordered_map<std::string, unsigned int> seg_to_id;
    std::vector<std::string> id_to_seg;
    //mutable std::mutex mutex_;
};

class SegmentedString {
public:
    unsigned int size;
    unsigned int first_segment;
    unsigned int* segments;

    SegmentedString() : size(0), first_segment(0), segments(nullptr) {}
    SegmentedString(const std::string& input) : size(0), first_segment(0), segments(nullptr) {
        if (input.empty()) return;
        // Count segments
        size_t pos = 0, next;
        while ((next = input.find("__", pos)) != std::string::npos) {
            ++size;
            pos = next + 2;
        }
        if (pos < input.size()) ++size;
        if (size == 0) return;
        // Parse segments
        pos = 0;
        next = input.find("__", pos);
        std::string first_seg_str = (next == std::string::npos) ? input : input.substr(pos, next-pos);
        first_segment = SegmentMap::instance().get_id(first_seg_str);

        if (size > 1) {
            segments = (unsigned int*)malloc(sizeof(unsigned int) * (size - 1));
            size_t found = 0;
            if (next != std::string::npos) {
                pos = next + 2;
                // Fill in the rest segments[1..size-1]
                while ((next = input.find("__", pos)) != std::string::npos) {
                    segments[found++] = SegmentMap::instance().get_id(input.substr(pos, next-pos));
                    pos = next + 2;
                }
                if (pos < input.size())
                    segments[found] = SegmentMap::instance().get_id(input.substr(pos));
            }
        }
    }

    SegmentedString(const SegmentedString& other)
        : size(other.size), first_segment(other.first_segment), segments(nullptr)
    {
        if (size > 1) {
            segments = (unsigned int*)malloc(sizeof(unsigned int) * (size - 1));
            std::copy(other.segments, other.segments + (size - 1), segments);
        }
    }

    SegmentedString(SegmentedString&& other) noexcept: size(other.size), first_segment(other.first_segment), segments(other.segments)
    {
        other.segments = nullptr;
        other.size = 0;
    }

    SegmentedString& operator=(const SegmentedString& other) {
        if (this != &other) {
            if (size > 1) free(segments);
            size = other.size;
            first_segment = other.first_segment;
            if (size > 1) {
                segments = (unsigned int*)malloc(sizeof(unsigned int) * (size - 1));
                std::copy(other.segments, other.segments + (size - 1), segments);
            }
        }
        return *this;
    }

    SegmentedString& operator=(SegmentedString&& other) noexcept {
        if (this != &other) {
            if (size>1) free(segments);
            size = other.size;
            first_segment = other.first_segment;
            segments = other.segments;
            other.size = 0;
        }
        return *this;
    }

    ~SegmentedString() {if (size>1) free(segments);}
    explicit SegmentedString(unsigned int* segments, unsigned int size, unsigned int first_segment): size(size), first_segment(first_segment), segments(segments) {}
    bool is_empty() const { return size == 0; }
    bool exists() const { return size != 0; }
    bool is_private() const { return size && SegmentMap::instance().get_segment(first_segment).size(); }
    std::string to_string() const {
        std::ostringstream oss;
        if (size == 0) return "";
        oss << SegmentMap::instance().get_segment(first_segment);
        for (size_t i = 1; i < size; ++i) oss << "__" << SegmentMap::instance().get_segment(segments[i - 1]);
        return oss.str();
    }

    SegmentedString operator+(const SegmentedString& other) const {
        if (size == 0) return other;
        if (other.size == 0) return *this;
        size_t new_size = size + other.size;
        unsigned int* new_segments = (unsigned int*)malloc(sizeof(unsigned int) * (new_size - 1));
        if (size > 1) memcpy(new_segments, segments, sizeof(unsigned int) * (size - 1));
        new_segments[size - 1] = other.first_segment;
        if (other.size > 1) memcpy(new_segments + size, other.segments, sizeof(unsigned int) * (other.size - 1));
        return SegmentedString(new_segments, new_size, first_segment);
    }

    bool operator==(const SegmentedString& other) const {
        if (size != other.size) return false;
        if (size && first_segment != other.first_segment) return false;
        if (size > 1 && memcmp(segments, other.segments, sizeof(unsigned int) * (size - 1)) != 0) return false;
        return true;
    }
    bool operator!=(const SegmentedString& other) const { return !(*this == other); }

    friend std::ostream& operator<<(std::ostream& os, const SegmentedString& ss) {
        if (ss.size == 0) return os;
        os << SegmentMap::instance().get_segment(ss.first_segment);
        for (size_t i = 1; i < ss.size; ++i) os << "__" << SegmentMap::instance().get_segment(ss.segments[i - 1]);
        return os;
    }

    bool operator==(const std::string& s) const {
        size_t pos = 0;
        // Compare first segment
        const std::string& seg0 = SegmentMap::instance().get_segment(first_segment);
        if (s.compare(pos, seg0.size(), seg0) != 0) return false;
        pos += seg0.size();
        for (size_t i = 1; i < size; ++i) {
            if (s.compare(pos, 2, "__") != 0) return false;
            pos += 2;
            const std::string& seg = SegmentMap::instance().get_segment(segments[i - 1]);
            if (s.compare(pos, seg.size(), seg) != 0) return false;
            pos += seg.size();
        }
        return pos == s.size();
    }
};

// std::hash specialization for SegmentedString
namespace std {
    template <>
    struct hash<SegmentedString> {
        std::size_t operator()(const SegmentedString& s) const noexcept {
            std::size_t h = 0;
            {
                unsigned int id = s.first_segment;
                h ^= std::hash<int>()(id) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            // FNV-1a or similar combination, but simple XOR+hash is enough for most
            for (size_t i = 1; i < s.size; ++i) {
                unsigned int id = s.segments[i-1];
                h ^= std::hash<int>()(id) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };
}

inline bool operator==(const std::string& lhs, const SegmentedString& rhs) {return rhs == lhs;}
inline bool operator!=(const std::string& lhs, const SegmentedString& rhs) {return !(rhs == lhs);}

#endif // SEGMENTS_H
