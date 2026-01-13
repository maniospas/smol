#include "../module.h"

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
        bool keep_only_nominal_variations = false;
        for(auto type : arg.uni->functions) 
            if(type->info.is_nominal || type->info.is_primitive) {
                keep_only_nominal_variations = true;
                break; // definitely add this, because nominal types, if any, are likely to be first
            }
        for(auto type : arg.uni->functions) {// >1 element
            if(keep_only_nominal_variations && !type->info.is_nominal && ! type->info.is_primitive)
                continue;
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
        if(is_first_type) importer.internal_error("Failed to select any argument variation");;
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
        //variation.print_debug();
        auto it = unions.find(variation.function->info.name);
        if(it!=unions.end()) it->second->add(variation.function);
        else unions[variation.function->info.name] = (new Union(variation.function->info.name))->add(variation.function);
    }
}
