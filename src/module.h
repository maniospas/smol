#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include "importer.h"
#include "function.h"


class Module;
static std::unordered_map<std::string, Module*> source2module;

class Module {
    std::string source;
public:
    std::vector<Function*> functions;
    Module(const std::string& source) : source(source) {
        source2module[source] = this;
    }
    ~Module() {
        for(auto function : functions)
            delete function;
        functions.clear();
    }
    void import() {
        std::cout << "Importing: " << source << "\n";
        auto importer = Importer{source};
        while(importer.next_line()) {
            size_t nesting = importer.get_column();
            while(true) {
                auto token = importer.next_token();
                if(!token.size())
                    break;
                if(token=="@") {
                    auto instruction = importer.next_token();
                    if(instruction=="include") {
                        auto path = std::string{importer.next_token()};
                        if(path.empty()) importer.error("Syntax error", "@include must be followed by a dot-separated path in the same line");
                        auto part = importer.next_token();
                        while(!part.empty()) {
                            if(part!=".") importer.error("Syntax error", "@include paths must be dot-separated");
                            part = importer.next_token();
                            if(part.empty()) importer.error("Syntax error", "@include path is incomplete");
                            path += "/";
                            path += part;
                            part = importer.next_token();
                        }
                        path += ".s";
                        if(!source2module.contains(path)) 
                            (new Module(path))->import();
                    }
                }
                else if(token=="def") 
                    functions.push_back(new Function(importer, false));
                else if(token=="service") 
                    functions.push_back(new Function(importer, true));
            }
        }
    }
};

void cleanup_modules() {
    for(auto const& [source, mod] : source2module)
        delete mod;
    source2module.clear();
}