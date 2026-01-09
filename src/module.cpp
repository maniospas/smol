#include "module.h"

std::unordered_map<Token, Module*> source2module;
std::vector<Function*> all_functions;

void cleanup_modules() {
    for(auto const [source, mod] : source2module)
        delete mod;
    source2module.clear();
    for(auto function : all_functions)
        delete function;
    all_functions.clear();
}

void Module::import() {
    //std::cout << "Importing: " << id2token[source] << "\n";
    auto importer = Importer{id2token[source]};
    bool recovering = false;
    while(true) {
        try {
            const auto token = importer.next();
            if(!token.size())
                break;
            if(importer.get_token_start() && !recovering)
                importer.syntax_error("Top-level instructions or definitions must start at the beginning of a new line");
            if(token=="@") {
                auto instruction = importer.next();
                if(instruction=="unsafe") {
                    recovering = false;
                    unsafe = true;
                }
                else if(instruction=="c_primitive") {
                    recovering = false;
                    auto name = get_token_id(std::string{importer.next()});
                    if(importer.next()!="{")
                        importer.syntax_error("");
                    auto next = importer.next(); 
                    auto depth = int{1};
                    // create the function
                    auto function = new Function(name);
                    all_functions.push_back(function);
                    // parse now
                    while(true) {
                        if(next.empty())
                            importer.syntax_error("Never closed opening brackets");
                        if(next=="{") depth++;
                        if(next=="}") depth--;
                        if(!depth) break;
                        next = importer.next();
                    }
                    // register only now that we can't break with errors
                    auto it = unions.find(function->info.name);
                    if(it!=unions.end()) it->second->add(function);
                    else unions[function->info.name] = (new Union(function->info.name))->add(function);
                }
                else if(instruction=="include") {
                    recovering = false;
                    auto path = std::string{importer.next()};
                    if(path.empty()) importer.syntax_error("Include path was empty - it needs to follow in the same line");
                    auto part = importer.next();
                    while(part==".") {
                        part = importer.next();
                        path += "/";
                        path += part;
                        part = importer.next();
                    }
                    importer.rollback_token();
                    path += ".s";
                    auto path_token = get_token_id(path);
                    if(!source2module.contains(path_token)) 
                        (new Module(path_token))->import();
                }
                else if(instruction=="about") {
                    recovering = false;
                    auto next = std::string{importer.next()};
                    auto name = std::string{""};
                    if(!is_string(next)) {
                        name = next;
                        next = importer.next();
                    }
                    if(!is_string(next))
                        importer.syntax_error("About directives must be followed by a string description");
                    while(is_string(next)) {
                        if(name.empty()) description += std::string_view{next.data()+1, next.size()-2};
                        else function_descriptions[get_token_id(name)] += std::string_view{next.data()+1, next.size()-2};
                        next = importer.next();
                    }
                    importer.rollback_token();
                }
                else if(!recovering) 
                    importer.syntax_error("Unknown directive");
            }
            else if(token=="def" || token=="service") {
                recovering = false;
                auto function = new Function(get_token_id("unnamed"));
                all_functions.push_back(function);
                function->import(importer, token=="service");
                auto it = unions.find(function->info.name);
                if(it!=unions.end()) it->second->add(function);
                else unions[function->info.name] = (new Union(function->info.name))->add(function);
            }
            else if(token=="union") {
                recovering = false;
                auto name = get_token_id(std::string{importer.next()});
                auto it = unions.find(name);
                //if(it!=unions.end()) importer.type_error("This type already exists and cannot be set as a union");
                if(importer.next()!="=") importer.syntax_error("Union names must be followed by = to be assigned a value");
                Union* base_union = (it!=unions.end())?it->second:(unions[name] = new Union(name));
                while(true) {
                    name = get_token_id(std::string{importer.next()});
                    it = unions.find(name);
                    if(it==unions.end()) importer.type_error("This type does not exist or is not visible here");
                    base_union->add_all(it->second);
                    if(importer.next()!="or") {
                        importer.rollback_token();
                        break;
                    }
                }
            }
            else if(!recovering)
                importer.syntax_error("Unknown command or directive");
        }
        catch (const std::runtime_error&) {
            recovering = true;
        }

    }
}