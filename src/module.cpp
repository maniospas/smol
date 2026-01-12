#include "module.h"

std::unordered_map<Token, Module*> source2module;
std::vector<Function*> all_functions;
std::unordered_map<std::string, Token> failure2code;
std::unordered_map<Token, std::string> code2failure;

Function* NOMINAL_FUNCTION = new Function(0);

void cleanup_modules() {
    delete NOMINAL_FUNCTION;
    for(auto const [source, mod] : source2module)
        delete mod;
    source2module.clear();
    for(auto function : all_functions)
        delete function;
    all_functions.clear();
}

class SpecializedFunction {
public:
    Function* function;
    Module* base_module;
    std::unordered_map<Token, Function*> poly;

    Function* helper_function; // used by the parser when a different type needs to be stored per variation

    SpecializedFunction(Function* function, Module* base_module) : function(function), base_module(base_module), helper_function(nullptr) {}
    SpecializedFunction(Function* function, 
        const SpecializedFunction& prototype, Token specialize_name, Function* specialize_function
    ) : function(function), base_module(prototype.base_module), helper_function(nullptr) {
        for(auto [name, fun] : prototype.poly)
            poly[name] = fun;
        if(specialize_function) poly[specialize_name] = specialize_function;
    }

    Function* get_type(const Importer& importer, Token name, bool allow_failure=false) const {
        auto it = poly.find(name);
        if(it!=poly.end()) 
            return it->second;
        auto ut = base_module->unions.find(name);
        if(ut==base_module->unions.end()) {
            if(allow_failure) return nullptr;
            importer.type_error("This type does not exist or is not visible here");
        }
        if(ut->second->functions.size()>1) importer.type_error("This type has multiple possible resolutions - pass as (named or nameless) argument to be able to specialize this function on a version you like"); 
        for(auto func : ut->second->functions) // return the one unique function (unless that is null, in which case go to the next error)
            if(func) return func;
        importer.internal_error("The compiler thinks that this type does not exist or is not visible here, but it should be available");
        return nullptr;
     }
};

int temp_vars = 0;
std::string create_temp() {
    std::string ret = "__tmp"+std::to_string(temp_vars);
    temp_vars++;
    return ret;
}

std::vector<UnresolvedArg> Module::_gather_arguments(Importer& importer, const std::string& name, bool& set_as_nominal) {
    // gather unresolved arguments
    auto args = std::vector<UnresolvedArg>{};
    if(importer.next()!="(") {
        importer.syntax_error("Expecting opening parenthesis");
        importer.rollback_token();
    }
    auto next = importer.next();
    while(next!=")" && !next.empty()) {
        bool is_own = false;
        bool is_mut = false;
        bool is_access = false;
        bool is_buffer = false;
        bool is_nominal = false;

        // qualifiers
        while(next=="@") {
            next = importer.next();
            if(next=="mut") {
                is_mut = true;
            }
            else if(next=="own") {
                is_own = true;
                if(is_mut) importer.format_error("@own must be placed before @mut");
            }
            else if(next=="access") {
                is_access = true;
                if(is_mut) importer.format_error("@access must be placed after @mut");
                if(is_own) importer.format_error("@access must be placed after @mut");
            }
            else importer.syntax_error("Only @own @access @mut can be argument directives");
            next = importer.next();
        }

        // new nominal type handling
        if(next=="new") {
            is_nominal = true;
            // unique new type
            next = std::string_view{"__new"+name+create_temp()};
            auto type_id = get_token_id(std::string{next});
            auto it = unions.find(type_id);
            if(it!=unions.end()) importer.internal_error("Temporary union that would be create for a new nominal type already exists");
            unions[type_id] = (new Union(type_id))->add(NOMINAL_FUNCTION);
        }
        if(is_nominal && args.size()) importer.format_error("The new nominal type indicator can only be the first argument");
        if(is_nominal) set_as_nominal = true;

        // actually find type
        auto type_id = get_token_id(std::string{next});
        auto type_it = unions.find(type_id);
        if(type_it==unions.end()) importer.type_error("This type does not exist or is not visible here");
        next = importer.next();

        // buffer types
        if(next=="[") {
            if(is_nominal) importer.type_error("Cannot annotate the new nominal type indicator as a buffer");
            if(importer.next()!="]") importer.syntax_error("Buffer arguments must be annotated by [] after their type without contents");
            is_buffer = true;
            next = importer.next();
        }

        // handle name or be nameless with a comma (in this case create a temporary variable)
        Token arg_name;
        if(next==",") 
            arg_name = get_token_id(create_temp());
        else {
            arg_name = get_token_id(std::string{next});
            next = importer.next();
        }
        args.emplace_back(arg_name, type_it->second, is_own, is_mut, is_access, is_buffer, is_nominal);
        if(next==")") break;
        if(next!=",") importer.syntax_error("Expected comma between function arguments");
        next = importer.next();
    }
    if(next!=")") {
        importer.syntax_error("Expecting closing parenthesis");
        importer.rollback_token();
    }
    return args;
}
void Module::import_function(Importer& importer, bool is_service) {
    // parse name
    auto name = std::string{importer.next()};
    auto name_id = get_token_id(name);
    if(name.empty() || is_delim(name[0]))
        importer.syntax_error("Invalid function name");

    // gather arguments
    auto set_as_nominal = false;
    auto args = _gather_arguments(importer, name, set_as_nominal);

    // construct variations
    std::vector<SpecializedFunction> variations;
    variations.reserve(1);
    {
        Function* function = new Function(name_id);
        function->info.is_service = is_service;
        function->info.is_nominal = set_as_nominal;
        all_functions.push_back(function);
        variations.emplace_back(function, this);
    }
    auto has_been_named = std::unordered_set<Token>{};
    for(size_t arg_pos=0; arg_pos<args.size(); ++arg_pos) {
        const auto& arg = args[arg_pos];
        // if we have resolved the argument type name before, get the previous choice
        if(has_been_named.contains(arg.uni->name)) {
            for(const auto& variation : variations) {
                auto found_existing = variation.poly.find(arg.uni->name);
                if(found_existing==variation.poly.end()) 
                    importer.internal_error(("Failed to find already resolved type "+id2token[arg.uni->name]).c_str());
                variation.function->info.args.emplace_back(arg.name, 
                    found_existing->second, arg.is_own, arg.is_mut, arg.is_access, arg.is_buffer, arg.is_nominal);
                }
            continue;
        }
        has_been_named.insert(arg.uni->name);
        // all combinations of existing variations with new type alternatives (arg union functions)
        if(arg.uni->functions.size()>1) variations.reserve(variations.size()*arg.uni->functions.size());
        auto is_first_type = true;
        auto prev_variation_size = variations.size();
        for(auto type : arg.uni->functions) {// >1 element
            if(is_first_type) {
                // if we have only one type alternative, we remain here and just add an argument
                for(auto& variation : variations) {
                    variation.function->info.args.emplace_back(arg.name, 
                        type, arg.is_own, arg.is_mut, arg.is_access, arg.is_buffer, arg.is_nominal);
                    variation.poly[arg.uni->name] = type;
                }
                is_first_type = false;
                continue;
            }
            // if we have more than one type candidates, expand only previous variations
            for(size_t variation_pos=0; variation_pos<prev_variation_size; ++variation_pos) { 
                const auto& variation = variations[variation_pos];
                Function* function = new Function(name_id);
                function->info.is_nominal = set_as_nominal;
                function->info.is_service = is_service;
                // copy existing args
                for(size_t i=0; i<arg_pos; ++i) {
                    const auto& a = variation.function->info.args[i];
                    function->info.args.emplace_back(a.name, 
                        a.type, a.is_own, a.is_mut, a.is_access, a.is_buffer, a.is_new); 
                }
                // add the new argument
                function->info.args.emplace_back(arg.name, 
                    type, arg.is_own, arg.is_mut, arg.is_access, arg.is_buffer, arg.is_nominal);
                all_functions.push_back(function);
                variations.emplace_back(function, variation, arg.uni->name, type);
            }
        }
    }

    // replace temporary nominal functions with references to the actual function
    if(set_as_nominal)
        for(auto& variation : variations) {
            if(variation.function->info.args.size() 
                && variation.function->info.args[0].type==NOMINAL_FUNCTION)
                variation.function->info.args[0].type = variation.function;
            if(variation.function->info.returns.size() 
                && variation.function->info.returns[0].type==NOMINAL_FUNCTION)
                variation.function->info.returns[0].type = variation.function;
        }
        
    // actual parsing from hereon
    auto next = importer.next();
    auto nesting = std::vector<size_t>{};
    auto current_nesting = importer.get_token_start();
    if(!importer.has_changed_line() && current_nesting) 
        importer.syntax_error("Much start a new line after argument declaration ends");
    nesting.emplace_back(current_nesting);
    while(!next.empty() && current_nesting) {
        if(next=="def" || next=="service" || next=="union") 
            importer.syntax_error("Cannot nest this definition within another function");
        if(next=="@") {
            next = importer.next();
            if(next=="c_head") {
                if(importer.next()!="{") importer.syntax_error("C header contents must start with {");
                auto c_depth = int{1};
                auto built_head = std::string{""};
                auto is_prev_symbol = true;
                while(true) {
                    next = importer.next();
                    if(next.empty()) importer.syntax_error("Failed to close a C header block");
                    else if(next=="}") c_depth--;
                    if(c_depth==0) break;
                    if(next=="{") c_depth++;
                    if(importer.has_changed_line()) {
                        built_head += "\n";
                        is_prev_symbol = true;
                    }
                    auto is_symbol = next.size()==1 && is_delim(next[0]);
                    if(!is_prev_symbol && !is_symbol) built_head += " ";
                    built_head += next;
                    is_prev_symbol = is_symbol;
                }
                for(auto& variation : variations) 
                    variation.function->header.push_back(get_token_id(built_head));
            }
            else if(next=="c_body") {
                if(importer.next()!="{") importer.syntax_error("C header contents must start with {");
                auto c_depth = int{1};
                // auto is_prev_dot = false;
                // auto is_prev_equals = false;
                while(true) {
                    next = importer.next();
                    if(next.empty()) importer.syntax_error("Failed to close a C header block");
                    else if(next=="}") c_depth--;
                    if(c_depth==0) break;
                    if(next=="{") c_depth++;
                    //is_prev_dot = next==".";
                    //is_prev_equals = next=="=";
                    auto next_id = get_token_id(std::string{next});
                    for(auto& variation : variations) {
                        auto existing_type = variation.get_type(importer, next_id, true);
                        if(existing_type) {
                            if(variation.helper_function)
                                importer.syntax_error("Variable names cannot be smoλ type names");
                            if(!existing_type->info.is_primitive) 
                                 importer.syntax_error("Cannot declare smoλ types in C for non c_primitive types - define structures outside c_body and use them inside");
                            // variation.function->direct_inline(existing_type);
                            variation.helper_function = existing_type;
                        }
                        else {
                            if(variation.helper_function) {
                                variation.function->var(importer, next_id, variation.helper_function);
                                variation.helper_function = nullptr;
                            }
                            variation.function->token(next_id);
                        }
                    }
                }
                for(auto& variation : variations) 
                    variation.function->token(get_token_id("\n"));
            }
            else importer.syntax_error("This kind of directive is not valid within function definitions");
        }
        else if(next=="fail") {
            next = importer.next();
            if(!is_string(next)) importer.syntax_error("Fail must be followed by a string message to be printed - directly run commands like custom prints beforehand");
            for(auto& variation : variations) 
                variation.function->call_failure(std::string{next});
        }
        else {
            
        }
        
        next = importer.next();
        if(importer.has_changed_line()) {
            auto new_nesting = importer.get_token_start();
            current_nesting = new_nesting;
        }
    }
    importer.rollback_token();

    // add all variations to the target union
    for(const auto& variation : variations) {
        std::cout << variation.function->info.to_string()<<"\n";
        std::cout << variation.function->export_inits("");
        std::cout << variation.function->export_body();
        std::cout << variation.function->export_fail();
        std::cout << variation.function->export_release();

        auto it = unions.find(variation.function->info.name);
        if(it!=unions.end()) it->second->add(variation.function);
        else unions[variation.function->info.name] = (new Union(variation.function->info.name))->add(variation.function);
    }
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
                importer.format_error("Top-level instructions or definitions must start at the beginning of a new line");
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
                    function->info.is_primitive = true;
                    // parse now
                    while(true) {
                        if(next.empty())
                            importer.syntax_error("Never closed opening brackets");
                        if(next=="{") depth++;
                        if(next=="}") depth--;
                        if(!depth) break;
                        function->token(get_token_id(std::string{next}));
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
                    auto imported = source2module[path_token];
                    if(!imported) 
                        (imported = new Module(path_token))->import();
                    for(auto [name, u] : imported->unions) {
                        auto it = unions.find(name);
                        if(it!=unions.end()) it->second->add_all(u);
                        else unions[name] = (new Union(name))->add_all(u);
                    }
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
                import_function(importer, token=="service");
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
            count_errors++;
        }

    }
}