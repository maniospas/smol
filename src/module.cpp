#include "module.h"
#include <charconv>
#include <string>
#include <system_error>

std::unordered_map<Token, Module*> source2module;
std::vector<Function*> all_functions;
std::unordered_map<std::string, Token> failure2code;
std::unordered_map<Token, std::string> code2failure;
std::unordered_map<std::string, Token> constant2code;
std::unordered_map<Token, std::string> code2constant;
std::unordered_set<Token> temporaries;
int temp_vars = 0;

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

bool is_unsigned_long_long(const std::string& s, unsigned long long& value) {
    if (s.empty()) return false;
    if (s[0]=='+' || s[0]=='-') return false;
    auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), value);
    return ec == std::errc{} && ptr == s.data() + s.size();
}

bool is_double(const std::string& s, double& value)
{
    if (s.empty()) return false;
    if (s[0] == '+' || s[0] == '-') return false;
    auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), value, std::chars_format::general);
    return ec == std::errc{} && ptr == s.data() + s.size();
}

Token create_temp() {
    std::string ret = "__tmp"+std::to_string(temp_vars);
    temp_vars++;
    auto ret_id = get_token_id(ret);
    temporaries.insert(ret_id);
    return ret_id;
}

Function* SpecializedFunction::get_type(const Importer& importer, Token name, bool allow_failure) const {
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
            if(next=="mut") 
                is_mut = true;
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
        auto longer_life_next = std::string{""};
        if(next=="new") {
            is_nominal = true;
            // unique new type
            longer_life_next = "__new"+name+id2token[create_temp()];
            next = std::string_view{longer_life_next};
            auto type_id = get_token_id(std::string{next});
            auto it = unions.find(type_id);
            if(it!=unions.end()) 
                importer.internal_error("Temporary union that would be create for a new nominal type already exists");
            unions[type_id] = (new Union(type_id))->add(NOMINAL_FUNCTION);
        }
        if(is_nominal && args.size()) 
            importer.format_error("The new nominal type indicator can only be the first argument");
        if(is_nominal)
            set_as_nominal = true;

        // actually find type
        auto type_id = get_token_id(std::string{next});
        auto type_it = unions.find(type_id);
        if(type_it==unions.end()) 
            importer.type_error("This type does not exist or is not visible here");
        next = importer.next();

        // buffer types
        if(next=="[") {
            if(is_nominal) 
                importer.type_error("Cannot annotate the new nominal type indicator as a buffer");
            if(importer.next()!="]") 
                importer.syntax_error("Buffer arguments must be annotated by [] after their type without contents");
            is_buffer = true;
            next = importer.next();
        }

        // handle name or be nameless with a comma (in this case create a temporary variable)
        Token arg_name;
        if(next==",") 
            arg_name = create_temp();
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


void Module::parse_expression(Importer& importer, std::vector<SpecializedFunction>& variations, std::string_view next) {
    // handle redundant parentheses
    if(next=="(") {
        parse_expression(importer, variations, importer.next());
        if(importer.next()!=")") importer.syntax_error("Needed to close the expression's opening parenthesis here");
        return;
    }
    // handle inline directives
    if(next=="@") {
        next = importer.next();
        if(next=="args") {
            // copy all arguments here
            for(auto& variation : variations) {
                variation.returned.clear();
                for(auto arg : variation.function->info.args) 
                    variation.returned.emplace_back(arg);
            }
        }
        else importer.syntax_error("Within expression you are only allowed to use the @dynamic, @mut, and @args directives");
    }
    // handle return statements
    if(next=="return") {
        for(auto& variation : variations) 
            variation.counter = 0;
        while(true) {
            parse_expression(importer, variations, importer.next());
            for(auto& variation : variations) {
                auto f = variation.function;
                for(auto var : variation.returned) {
                    auto it = f->vars.find(var);
                    if(it==f->vars.end() || !it->first) 
                        importer.internal_error(("Failed to find type for returned variable "+id2token[var]).c_str());
                    //variation.function->var(importer, var, it->second.type, it->second.is_mut, it->second.is_buffer);
                    if(!f->has_returned) 
                        f->info.returns.emplace_back(var);
                    else {
                        if(variation.counter>=f->info.returns.size()) 
                            importer.type_error("Returned different type than the first one");
                        auto prev = f->info.returns[variation.counter];
                        auto temp_var = temporaries.contains(var);
                        auto temp_prev = temporaries.contains(prev);
                        if(f->info.returns[variation.counter]!=var 
                            && !temp_var
                            && !temp_prev)
                            importer.type_error(("Returned different name than the first time. Expected: "+id2token[prev]).c_str());
                        if(temp_var) {
                            auto it1 = f->vars.find(var);
                            auto it2 = f->vars.find(prev);
                            if(it1==f->vars.end() || it2==f->vars.end() 
                                || it1->second.type!=it2->second.type
                                || it1->second.is_buffer!=it2->second.is_buffer) 
                                importer.type_error("This mismatches a previous return");
                            f->token(prev);
                            f->token("=");
                            f->token(var);
                            f->token(";");
                            f->token("\n");
                        }
                        if(temp_prev)
                            importer.format_error("Cannot return an explicit name when the first time you returned an anonymous object here");
                    }
                    ++variation.counter;
                }
            }
            if(importer.next()!=",") break;
        }
        for(auto& variation : variations)
            variation.function->has_returned = true;
        importer.rollback_token(); // rollback our attempt to get the last comma
        return;
    }

    // parse numbers
    auto next_as_string = std::string{next};
    auto next_id = get_token_id(next_as_string);
    unsigned long long parsed_unsigned;
    double parsed_double;
    if(is_unsigned_long_long(next_as_string, parsed_unsigned)) {
        for(auto& variation : variations) {
            auto type = variation.get_type(importer, get_token_id("u64"));
            auto f = variation.function;
            auto temp = f->get_constant(next_as_string);
            if(!f->vars.contains(temp)) f->var(importer, temp, type, false, false);
            variation.returned.clear();
            variation.returned.emplace_back(temp);
        }
        return;
    }
    if(is_double(next_as_string, parsed_double)) {
        for(auto& variation : variations) {
            auto type = variation.get_type(importer, get_token_id("f64"));
            auto f = variation.function;
            auto temp = f->get_constant(next_as_string);
            if(!f->vars.contains(temp)) f->var(importer, temp, type, false, false);
            variation.returned.clear();
            variation.returned.emplace_back(temp);
        }
        return;
    }

    // parse calls
    auto count_is_call = size_t{0};
    for(auto& variation : variations) {
        variation.candidates.clear();
        auto it = variation.poly.find(next_id);
        bool is_call = false;
        if(it!=variation.poly.end()) {
            variation.candidates.insert(it->second);
            is_call = true;
        }
        // base_module is `this` but leaving it this way in case we move the code
        else {
            auto ut = variation.base_module->unions.find(next_id);
            if(ut!=variation.base_module->unions.end()) {
                for(auto func : ut->second->functions)
                    if(func) variation.candidates.insert(func);
                is_call = true;
            }
        }
        if(is_call) ++count_is_call;
    }
    if(count_is_call && count_is_call!=variations.size()) 
        importer.internal_error("This type is missing in at least one variation");
    // now that we know that we have a valid type, actually parse the call
    if(count_is_call) {
        next = importer.next();
        if(next=="[") importer.internal_error("Buffers not implemented yet");
        else if(next==".") importer.internal_error("Dot notation on types not implemented yet");
        else if(next=="(") {
            // we will accumulate arguments returned by comma-separated expressions
            for(auto& variation : variations)  
                variation.arguments.clear();
            next = importer.next();
            while(next!=")") {
                auto saved_arguments = std::vector<std::vector<Token>>{};
                auto saved_candidates = std::vector<std::vector<Function*>>{};
                for(size_t i=0;i<variations.size();++i) {
                    auto& variation = variations[i];
                    variation.returned.clear();
                    saved_arguments.emplace_back();
                    saved_candidates.emplace_back();
                    saved_arguments[i].reserve(variation.arguments.size());
                    saved_candidates[i].reserve(variation.candidates.size());
                    for(auto arg : variation.arguments)
                        saved_arguments[i].emplace_back(arg);
                    for(auto func : variation.candidates)
                        saved_candidates[i].emplace_back(func);
                    variation.arguments.clear();
                    variation.candidates.clear();
                }
                parse_expression(importer, variations, next);
                for(size_t i=0;i<variations.size();++i) {
                    auto& variation = variations[i];
                    variation.arguments.clear();
                    variation.candidates.clear();
                    for(auto arg : saved_arguments[i])
                        variation.arguments.emplace_back(arg);
                    for(auto func : saved_candidates[i])
                        variation.candidates.insert(func);
                }
                // add all new arguments to the variation, but also remove incompatible candidates immediately
                for(auto& variation : variations) 
                    for(auto& arg : variation.returned) {
                        auto f = variation.function;
                        auto new_candidates = std::vector<Function*>{};
                        new_candidates.reserve(variation.candidates.size());
                        auto pos = variation.arguments.size();
                        // check compatibility only for new candidates
                        for(auto candidate : variation.candidates) {
                            if(pos>=candidate->info.args.size()) {
                                //std::cout << "Wrong number of arguments\n";
                                continue;
                            }
                            auto it1 = candidate->vars.find(candidate->info.args[pos]);
                            auto it2 = f->vars.find(arg);
                            if(it1==candidate->vars.end()) continue;
                            if(it2==f->vars.end()) {
                                //std::cout << "no type for var "+id2token[arg] << "\n";
                                continue; 
                            }
                            if(it1->second.type!=it2->second.type
                                || it1->second.is_buffer!=it2->second.is_buffer) {
                                // std::cout << "Incompatible types (function vs given argument):\n";
                                // std::cout << it1->second.type->export_signature() << "\n";
                                // std::cout << it2->second.type->export_signature() << "\n";
                                continue;
                            }
                            new_candidates.emplace_back(candidate);
                        }
                        // move new candidates to the candidate list
                        if(new_candidates.empty()) 
                            importer.type_error("Failed to resolve to any viable function call.");
                        variation.candidates.clear();
                        for(auto candidate : new_candidates) 
                            variation.candidates.insert(candidate);
                        variation.arguments.emplace_back(arg);
                    }
                // continue with the comma and then the token after the comma
                next = importer.next();
                if(next!=",") break;
                next = importer.next();
            }
            if(next!=")") importer.syntax_error("Missing closing parenthesis after function call - maybe an argument expression ended prematurely");
        }
        for(auto& variation : variations) {
            Function* selected = nullptr;
            // select exactly complete argument lists
            for(auto candidate : variation.candidates) {
                if(candidate->info.args.size()==variation.arguments.size()) {
                    if(selected) 
                        importer.type_error("More than one candidates");
                    selected = candidate;
                }
            }
            if(!selected) 
                importer.type_error("Failed to resolve to any viable function call.");
            auto temp = create_temp();
            auto f = variation.function;
            for(size_t i=0; i<variation.arguments.size();++i) {
                f->token(id2token[temp]+"__"+id2token[selected->info.args[i]]);
                f->token("=");
                f->token(variation.arguments[i]);
                f->token(";");
                f->token("\n");
            }
            f->bring_in(importer, selected, temp); // also handles collections and injects all vars
            variation.returned.clear();
            for(auto ret : selected->info.returns)
                variation.returned.emplace_back(get_token_id(id2token[temp]+"__"+id2token[ret]));
        }
        return;
    }


    // check if the current expression is just a variable
    auto count_is_variable = size_t{0};
    for(auto& variation : variations) {
        auto f = variation.function;
        auto it_collection = f->collections.find(next_id);
        variation.returned.clear();
        if(it_collection!=f->collections.end()) {
            for(auto token : it_collection->second)
                variation.returned.emplace_back(token);
        }
        else {
            auto it = f->vars.find(next_id);
            if(it==f->vars.end()) continue;
            variation.returned.emplace_back(next_id);
        }
        ++count_is_variable;
    }
    if(count_is_variable && count_is_variable!=variations.size()) importer.internal_error("This variable is missing in at least one variation");
    // if(count_is_variable) {
    //     next = importer.next();
    //     if(next==".") {}
    //     else if(next=="<") {}
    //     else if(next==">") {}
    //     else if(next=="<=") {}
    //     else if(next==">=") {}
    //     else if(next=="+") {}
    //     else if(next=="-") {}
    //     else if(next=="*") {}
    //     else if(next=="/") {}
    //     else if(next=="==") {}
    //     else if(next=="!=") {}
    //     else {
    //         importer.rollback_token();
    //     }
    //     return;
    // }
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
                variation.function->info.args.emplace_back(arg.name);
                variation.function->vars[arg.name] = Arg(arg.name, found_existing->second, arg.is_own, arg.is_mut, arg.is_access, arg.is_buffer, arg.is_nominal);
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
                    variation.function->info.args.emplace_back(arg.name);
                    variation.function->vars[arg.name] = Arg(arg.name, type, arg.is_own, arg.is_mut, arg.is_access, arg.is_buffer, arg.is_nominal);
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
                    auto var = variation.function->info.args[i];
                    function->info.args.emplace_back(var);
                    const auto& a = function->vars[var]; 
                    function->vars[a.name] = Arg(a.name, a.type, a.is_own, a.is_mut, a.is_access, a.is_buffer, a.is_new); 
                }
                // add the new argument
                function->info.args.emplace_back(arg.name);
                function->vars[arg.name] = Arg(arg.name, type, arg.is_own, arg.is_mut, arg.is_access, arg.is_buffer, arg.is_nominal);
                all_functions.push_back(function);
                variations.emplace_back(function, variation, arg.uni->name, type);
            }
        }
    }

    // replace temporary nominal functions with references to the actual function
    if(set_as_nominal)
        for(auto& variation : variations) {
            auto f = variation.function;
            if(f->info.args.size()){
                auto& var = f->vars[f->info.args[0]];
                if(var.type==NOMINAL_FUNCTION)
                    var.type = variation.function;
            }
        }
        
    // actual parsing from hereon
    auto next = importer.next();
    auto nesting = std::vector<size_t>{};
    auto current_nesting = importer.get_token_start();
    if(!importer.has_changed_line() && current_nesting) 
        importer.syntax_error("Much start a new line after argument declaration ends");
    nesting.emplace_back(current_nesting);
    while(!next.empty() && current_nesting) {
        if(next=="def" || next=="service" || next=="union") break;
            //importer.syntax_error("Cannot nest this definition within another function");
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
                                variation.function->var(importer, next_id, variation.helper_function, false, false);
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
        else parse_expression(importer, variations, next);
        
        next = importer.next();
        if(importer.has_changed_line()) {
            auto new_nesting = importer.get_token_start();
            current_nesting = new_nesting;
        }
    }
    importer.rollback_token();

    // add all variations to the target union
    for(const auto& variation : variations) {
        std::cout << variation.function->export_signature()<<"\n";
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
    if(!importer.is_open()) {
        importer.invalidate_state_for_file_errors();
        importer.error("Build error", "This file does not exist");
    }
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
                    function->info.returns.emplace_back(get_token_id("z"));
                    function->var(importer, get_token_id("z"), function, true, false); // correct return
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
                    auto import_it = source2module.find(path_token);
                    auto imported = import_it==source2module.end()?nullptr:import_it->second;
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