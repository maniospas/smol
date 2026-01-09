#include "compiler.h"
#include <iostream>

string compiler = "gcc";
string linker = "";
string runtime = "std/runtime/auto.h";

// Returns 0 on success, or nonzero (compiler exit code or error).
int compile_from_stringstream_with_flags(
    stringstream& out,
    const string& output_file,
    const string& extra_flags 
) {
    string cmd = compiler+string(" -O3 ")
        +" -std=c++11 -m64 -fpermissive"
        +" -fno-stack-protector -fno-exceptions -fno-rtti -ffunction-sections -s -fdata-sections -std=c++11 -Wl,--gc-sections "
        + extra_flags + " -o \"" + output_file + "\" -x c++ -"+linker+" -lm";

    //cout << cmd << "\n";
    FILE* pipe = SMOL_POPEN(cmd.c_str(), "w");
    if(!pipe) 
        return -1; // popen failed
    string code = out.str();
    size_t written = fwrite(code.data(), 1, code.size(), pipe);
    int ret = SMOL_PCLOSE(pipe);
    if(written != code.size()) 
        return -2; // fwrite failed

#if defined(_WIN32) || defined(_WIN64)
    // On Windows, ret is the return value of the process (already shifted)
    return ret;
#else
    // On UNIX, WEXITSTATUS gives the compiler's exit code
    if(WIFEXITED(ret))
        return WEXITSTATUS(ret);
    else
        return -3; // Abnormal termination
#endif
}
