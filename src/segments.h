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
    SegmentedString() {size=0;}
    SegmentedString(const std::string& input) {
        size = 0;
        if(!input.size()) return;
        size_t pos = 0, next;
        while ((next = input.find("__", pos)) != std::string::npos) {
            size++;
            pos = next + 2;
        }
        if(pos<input.size()) size++;
        size_t found = 0;
        pos = 0;
        segments = (unsigned int*)malloc(sizeof(int)*(size));
        while ((next = input.find("__", pos)) != std::string::npos) {
            segments[found] = SegmentMap::instance().get_id(input.substr(pos, next-pos));
            found++;
            pos = next + 2;
        }
        if(pos<input.size()) segments[found] = SegmentMap::instance().get_id(input.substr(pos));
        first_segment = segments[0];
    }
    SegmentedString(const SegmentedString& other) : size(other.size), first_segment(other.first_segment) {
        if (size) {
            segments = (unsigned int*)malloc(sizeof(int) * size);
            std::copy(other.segments, other.segments + size, segments);
        }
    }
    SegmentedString(SegmentedString&& other) noexcept: size(other.size), first_segment(other.first_segment), segments(other.segments) {
        other.size = 0;
    }
    SegmentedString& operator=(const SegmentedString& other) {
        if (this != &other) {
            first_segment = other.first_segment;
            if (size) free(segments);
            size = other.size;
            if (size) {
                segments = (unsigned int*)malloc(sizeof(int) * size);
                std::copy(other.segments, other.segments + size, segments);
            }
        }
        return *this;
    }
    SegmentedString& operator=(SegmentedString&& other) noexcept {
        if (this != &other) {
            first_segment = other.first_segment;
            if (size) free(segments);
            segments = other.segments;
            size = other.size;
            other.segments = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~SegmentedString() {if(size)free(segments);}
    explicit SegmentedString(unsigned int* segments, unsigned int size, unsigned int first_segment): size(size), first_segment(first_segment), segments(segments) {}
    bool is_empty() const {return !size;}
    bool exists() const {return size;}
    bool is_private() const {return size && SegmentMap::instance().get_segment(segments[0]).size();}
    std::string to_string() const {
        std::ostringstream oss;
        for (size_t i = 0; i < size; ++i) {
            if (i) oss << "__";
            oss << SegmentMap::instance().get_segment(segments[i]);
        }
        return oss.str();
    }
    SegmentedString operator+(const SegmentedString& other) const {
        size_t new_size = this->size + other.size;
        unsigned int* result = (unsigned int*)malloc(new_size * sizeof(int));
        if (this->size) memcpy(result, this->segments, this->size * sizeof(int));
        if (other.size) memcpy(result + this->size, other.segments, other.size * sizeof(int));
        return SegmentedString(result, new_size, first_segment);
    }

    bool operator==(const SegmentedString& other) const { 
        if(size!=other.size) return false;
        if(size && first_segment!=other.first_segment) return false;
        for (size_t i = 0; i < size; ++i) if(segments[i]!=other.segments[i]) return false;
        return true;
     }
    bool operator!=(const SegmentedString& other) const {
        if(size!=other.size) return true;
        if(size && first_segment!=other.first_segment) return true;
        for (size_t i = 0; i < size; ++i) if(segments[i]!=other.segments[i]) return true;
        return false;
    }
    friend std::ostream& operator<<(std::ostream& os, const SegmentedString& ss) {
        if(!ss.size) return os;
        os << SegmentMap::instance().get_segment(ss.first_segment);
        for (size_t i = 1; i < ss.size; ++i) os << "__" << SegmentMap::instance().get_segment(ss.segments[i]);
        return os;
    }
    bool operator==(const std::string& s) const {
        size_t pos = 0;
        for (size_t i = 0; i < size; ++i) {
            const std::string& seg = SegmentMap::instance().get_segment(segments[i]);
            size_t seg_len = seg.length();
            if (s.compare(pos, seg_len, seg) != 0) return false;
            pos += seg_len;
            if (i + 1 < size) {
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
            for (size_t i = 0; i < s.size; ++i) {
                unsigned int id = s.segments[i];
                h ^= std::hash<int>()(id) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };
}

inline bool operator==(const std::string& lhs, const SegmentedString& rhs) {return rhs == lhs;}
inline bool operator!=(const std::string& lhs, const SegmentedString& rhs) {return !(rhs == lhs);}

#endif // SEGMENTS_H
