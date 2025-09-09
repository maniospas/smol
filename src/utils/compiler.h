#ifndef SMOL_COMPILER_H
#define SMOL_COMPILER_H

#include <regex>
#include <map>
#include <sstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <filesystem>

using namespace std;

#if defined(_WIN32) || defined(_WIN64)
#define SMOL_POPEN _popen
#define SMOL_PCLOSE _pclose
#else
#define SMOL_POPEN popen
#define SMOL_PCLOSE pclose
#endif

string compiler = "g++";
string linker = "";
string runtime = "std/runtime/auto.h";

// Returns 0 on success, or nonzero (compiler exit code or error).
int compile_from_stringstream_with_flags(
    std::stringstream& out,
    const std::string& output_file,
    const std::string& extra_flags 
) {
    std::string cmd =
        compiler+" -O3 -s -ffunction-sections -fno-exceptions -fno-rtti -fdata-sections -std=c++11 -m64 -fpermissive " +
        extra_flags + " -o \"" + output_file + "\" -x c++ -"+linker;
    FILE* pipe = SMOL_POPEN(cmd.c_str(), "w");
    if (!pipe) 
        return -1; // popen failed
    std::string code = out.str();
    size_t written = fwrite(code.data(), 1, code.size(), pipe);
    int ret = SMOL_PCLOSE(pipe);
    if (written != code.size()) 
        return -2; // fwrite failed

#if defined(_WIN32) || defined(_WIN64)
    // On Windows, ret is the return value of the process (already shifted)
    return ret;
#else
    // On UNIX, WEXITSTATUS gives the compiler's exit code
    if (WIFEXITED(ret))
        return WEXITSTATUS(ret);
    else
        return -3; // Abnormal termination
#endif
}

#ifdef _WIN32
    #define EXEC_EXT ".exe"
    #define EXEC_PREFIX ".\\"
#else
    #define EXEC_EXT ""
    #define EXEC_PREFIX "./"
#endif

#endif // SMOL_COMPILER_H