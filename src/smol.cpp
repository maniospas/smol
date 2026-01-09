#include "importer.h"
#include "function.h"
#include "module.h"


int main(int argc, char* argv[]) {
    auto source = std::string{""};
    for(int i = 1; i < argc; ++i) {
        auto arg = std::string{argv[i]};
        source = arg;
    }
    (new Module(get_token_id(source)))->import();
    cleanup_modules();
}