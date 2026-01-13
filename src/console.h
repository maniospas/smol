#pragma once
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

namespace ansi {
    extern const char* red;
    extern const char* purple;
    extern const char* cyan;
    extern const char* green;
    extern const char* yellow;
    extern const char* gray;
    extern const char* reset;
}

class Importer;
int compile_from_string(Importer& importer, const std::string& transpiled, const std::string& flags, const std::string& out_extension);
int run_executable(const std::string& path);

class Options {
public:
    std::string source;
    std::string back;
    std::string runtime;
    std::string linker;
    std::string task;
    Options() = default;
};

extern Options compiler_options;