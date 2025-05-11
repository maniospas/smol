#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
static const char* base62_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789";

string numberToVar(size_t num) {
    int count = popcount(num); 
    string result;
    result.reserve(count);
    while(num) {
        result += base62_chars[num%62];
        num /= 62;
    }
    return result;
}
