#include "console.h"
#include "importer.h"

Options compiler_options;

namespace ansi {
    const char* red = "\033[31m";
    const char* yellow = "\033[33m";
    const char* cyan = "\033[36m";
    const char* green = "\033[32m";
    const char* purple = "\033[35m";
    const char* gray = "\033[90m";
    const char* reset = "\033[0m";
}

int compile_from_string(Importer& importer, const std::string& transpiled, const std::string& flags, const std::string& out_extension) {
    const auto cmd = 
        compiler_options.back 
        + " -x c -  -o " + compiler_options.source.substr(0,compiler_options.source.size()-2)
        + out_extension+ " " 
        + flags + " " 
        + compiler_options.linker;
    auto pipe = popen(cmd.c_str(), "w");
    if(!pipe)
        importer.error("Build error", "Failed to start compiler backend");
    auto written = fwrite(transpiled.data(), 1, transpiled.size(), pipe);
    if(written != transpiled.size()) {
        pclose(pipe);
        importer.error("Build error", "Failed to pass C source to the backend");
    }
    return pclose(pipe);
}

int run_executable(const std::string& path) {
#ifdef _WIN32
    std::string cmd = path;
#else
    std::string cmd = "./" + path;
#endif
    return std::system(cmd.c_str());
}