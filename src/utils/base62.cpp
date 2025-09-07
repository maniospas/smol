#include "base62.h"
#include <bit>   // for std::popcount (C++20)
#include <string>

using namespace std;

static const char* base62_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789";

string numberToVar(std::size_t num) {
    int count = popcount(num);
    string result;
    result.reserve(count);
    while (num) {
        result += base62_chars[num % 62];
        num /= 62;
    }
    return result;
}
