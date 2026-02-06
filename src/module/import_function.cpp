#include "../module.h"

Function* NOMINAL_FUNCTION = new Function(get_token_id("new"));//get_token_id("[nominal type/constructor]"));

void cleanup_modules() {
    delete NOMINAL_FUNCTION;
    for(auto const [source, mod] : source2module)
        delete mod;
    source2module.clear();
    for(auto function : all_functions)
        delete function;
    all_functions.clear();
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
    auto variations = std::vector<SpecializedFunction>{};
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
        bool keep_only_nominal_variations = false; //
        for(auto type : arg.uni->functions) 
            if(/*type->info.is_nominal ||*/ type->info.is_primitive) {
                keep_only_nominal_variations = true;
                break; // definitely add this break, because nominal types, if any, are likely to be first
            }
        auto already_added = std::unordered_set<Function*>{};
        for(auto type : arg.uni->functions) {// >1 element
            if(keep_only_nominal_variations /*&& !type->info.is_nominal*/ && ! type->info.is_primitive)
                continue;
            if(type->info.returns.size()) {
                auto& var = type->vars[type->info.returns[0]];
                if(var.type!=type 
                    && var.type->info.returns.size()==type->info.returns.size()
                    && var.type->info.is_nominal) // if we are a proxy for a nominal type use that instead
                    type = var.type;
            }
            if(already_added.contains(type))
                continue;
            already_added.insert(type); // this effectively means that proxy constructors with the same name only create one variation
            // TODO: in addition to the preliminary check in already_added, in the end reduce variations to unique alternatives
            // to be completely minimal - but this already covers most std overhead
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
        if(is_first_type) importer.internal_error("Failed to select any argument variation.");;
    }

    // replace temporary nominal functions with references to the actual function
    if(set_as_nominal)
        for(auto& variation : variations) {
            auto f = variation.function;
            if(f->info.args.size()){
                auto& var = f->vars[f->info.args[0]];
                if(var.type==NOMINAL_FUNCTION) 
                    var.type = variation.function;
                else importer.internal_error("Failed to resolve to nominal type.");
            } 
            else importer.internal_error("Failed to resolve to nominal type.");
        }

    // unpack arguments to tuples
    for(auto& variation : variations) {
        auto f = variation.function;
        auto args = std::move(f->info.args);
        f->info.args.clear();
        for(auto arg : args) {
            if(!f->vars[arg].type)
                continue;
            if(f->vars[arg].type->info.is_primitive || f->vars[arg].type==f) {
                f->info.args.emplace_back(arg);
                continue;
            }
            auto argument_type = f->vars[arg].type;
            for(auto ret : argument_type->info.returns) {
                auto type = argument_type->vars[ret];
                if(!type.type) {
                    auto message = "Argument type not found: "+id2token[arg]+"."+id2token[ret];
                    importer.internal_error(message.c_str());
                }
                auto field_name = id2token[arg]+"__"+id2token[ret];
                auto field_name_id = get_token_id(field_name);
                f->collections[arg].emplace_back(field_name_id);
                f->var(importer, field_name_id, type.type, type.is_mut, type.is_buffer);
                auto it = type.type->collections.find(ret);
                if(it==type.type->collections.end()) {
                    f->info.args.emplace_back(field_name_id);
                    //auto message = "Argument type not found: "+id2token[arg]+"."+id2token[ret];
                    //importer.internal_error(message.c_str());
                }
                for(const auto& [name, values] : type.type->collections) {
                    auto new_type = argument_type->vars[name];
                    auto new_name = get_token_id(id2token[arg]+"__"+id2token[name]);
                    f->info.args.emplace_back(new_name);
                    f->var(importer, new_name, new_type.type, new_type.is_mut, new_type.is_buffer);
                    f->collections[new_name].reserve(values.size());
                    for(auto value : values) 
                        f->collections[new_name].emplace_back(get_token_id(id2token[arg]+"__"+id2token[value]));
                }
            }
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
            else 
                importer.syntax_error("This kind of directive is not valid within function definitions");
        }
        else parse_expression(importer, variations, next, 0);
        
        next = importer.next();
        if(importer.has_changed_line()) {
            auto new_nesting = importer.get_token_start();
            current_nesting = new_nesting;
        }
    }
    importer.rollback_token();
    // add all variations to the target union
    for(const auto& variation : variations) {
        //variation.print_debug();
        //std::cout << variation.function->export_signature( ) << "\n";
        auto it = unions.find(variation.function->info.name);
        if(it!=unions.end()) it->second->add(variation.function);
        else unions[variation.function->info.name] = (new Union(variation.function->info.name))->add(variation.function);
    }
}
