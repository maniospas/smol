#include "importer.h"
#include "function.h"
#include "module.h"


int main(int argc, char* argv[]) {
    auto source = std::string{""};
    for(int i = 1; i < argc; ++i) {
        auto arg = std::string{argv[i]};
        source = arg;
    }
    get_token_id(""); // this will always be our 0 token to allow it to be invalid everywhere
    try {
        Module* main_module = new Module(get_token_id(source));
        main_module->import();
        auto it = main_module->unions.find(get_token_id("main"));
        if(it==main_module->unions.end()) {
            auto importer = Importer(source);
            importer.invalidate_state_for_file_errors();
            importer.type_error("No main function");
        }
    }
    catch(std::runtime_error&) {}
    //for(auto function : it->second->functions)
    //    std::cout << function->to_string() << "\n";

    cleanup_modules();
}