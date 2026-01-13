#include "importer.h"
#include "function.h"
#include "module.h"
#include "console.h"

#define argument_error(message) {std::cout << message << "\n"; return 1;}

#include <cstdio>
#include <string>
#include <stdexcept>

int main(int argc, char* argv[]) {
    get_token_id(""); // this will always be our 0 token to allow it to be invalid everywhere
    for(int i = 1; i < argc; ++i) {
        auto arg = std::string{argv[i]};
        if(arg=="--task") {
            if(i>=argc-1)  argument_error("Missing --task value");
            compiler_options.task = argv[++i];
        }
        else if(arg=="--link") {
            if(i>=argc-1)  argument_error("Missing --link value");
            compiler_options.linker = argv[++i];
        }
        else if(arg=="--back") {
            if(i>=argc-1)  argument_error("Missing --back value");
            compiler_options.back = argv[++i];
        }
        else if(arg=="--runtime") {
            if(i>=argc-1)  argument_error("Missing --runtime value");
            compiler_options.runtime = argv[++i];
        }
        else {
            if(!arg.ends_with(".s")) argument_error("Compiled files can only end in .s but given: "+arg);
            if(compiler_options.source.size()) argument_error("Can only compile one source");
            compiler_options.source = arg;
        }
    }

    if(compiler_options.back.empty()) 
        compiler_options.back = "gcc";
    if(compiler_options.runtime.empty()) 
        compiler_options.runtime = "auto";
    if(compiler_options.task.empty()) 
        compiler_options.task = "run";

    int return_code = 0;
    auto error_handler = Importer(compiler_options.source);
    error_handler.invalidate_state_for_file_errors();
    try {
        Module* main_module = new Module(get_token_id(compiler_options.source));
        main_module->import();
        auto it = main_module->unions.find(get_token_id("main"));
        if(it==main_module->unions.end()) 
            error_handler.error("Build error", "No main function");

        // for(auto func : it->second->functions)
        //     std::cout << func->export_service();
        auto transpiled = std::ostringstream{};
        for(auto func : it->second->functions)
            transpiled << func->export_service();

        if(compiler_options.task=="compile")
            return_code = compile_from_string(error_handler, transpiled.str(), "-O2", "");
        else if(compiler_options.task=="run") {
            return_code = compile_from_string(error_handler, transpiled.str(), "-O2", "");
            if(!return_code) return_code = run_executable(compiler_options.source.substr(0, compiler_options.source.size()-2));
        }
        else if(compiler_options.task=="transpile") {
            auto out_name = compiler_options.source.substr(0, compiler_options.source.size() - 2) + ".c";
            auto out = std::ofstream{out_name};
            if(!out) error_handler.error("Build error", ("Failed to open: " + out_name).c_str());
            out << transpiled.str();
            out.close();
            std::cout << "Created: " << out_name << "\n";
            return_code = 0;
        }
    }
    catch(std::runtime_error&) {
        return_code = 1;
    }
    cleanup_modules();
    return return_code;
}