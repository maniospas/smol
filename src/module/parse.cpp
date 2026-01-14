#include "../module.h"
#include <charconv>
#include <string>
#include <system_error>

std::unordered_map<Token, Module*> source2module;
std::vector<Function*> all_functions;
std::unordered_map<std::string, Token> failure2code;
std::unordered_map<Token, std::string> code2failure;
std::unordered_map<std::string, Token> constant2code;
std::unordered_map<Token, std::string> code2constant;
int temp_vars = 0;

bool is_temp(Token token) {
    const std::string& name = id2token[token];
    if(name.size()<5) return false;
    return name[0]=='_' && name[1]=='_' && name[2]=='t' && name[3]=='m' && name[4]=='p';
}

bool is_unsigned_long_long(const std::string& s, unsigned long long& value) {
    if(s.empty()) return false;
    if(s[0]=='+' || s[0]=='-') return false;
    auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), value);
    return ec == std::errc{} && ptr == s.data() + s.size();
}

bool is_double(const std::string& s, double& value) {
    if(s.empty()) return false;
    if(s[0] == '+' || s[0] == '-') return false;
    auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), value, std::chars_format::general);
    return ec == std::errc{} && ptr == s.data() + s.size();
}

Token create_temp() {
    std::string ret = "__tmp"+std::to_string(temp_vars);
    temp_vars++;
    auto ret_id = get_token_id(ret);
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

    auto keep_only_nominal_variations = false;
    for(auto type : ut->second->functions) 
        if(type)
            if(type->info.is_nominal || type->info.is_primitive) {
                keep_only_nominal_variations = true;
                break; // definitely add this, because nominal types, if any, are likely to be first
            }

    Function* selected = nullptr;
    for(auto type : ut->second->functions) {// >1 element
        if(!type) continue;
        if(keep_only_nominal_variations && !type->info.is_nominal && ! type->info.is_primitive)
            continue;
        if(selected)
            importer.type_error("This type has multiple possible resolutions - pass as (named or nameless) argument to be able to specialize this function on a version you like"); 
        selected = type;    
    }
    if(!selected) importer.internal_error("The compiler thinks that this type does not exist or is not visible here, but it should be available");
    return selected;
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



void Module::parse_expression_for_arguments(Importer& importer, std::vector<SpecializedFunction>& variations, std::string_view next) {
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
}

void Module::parse_code_block(Importer& importer, std::vector<SpecializedFunction>& variations, std::string_view next) {
    auto indentation = importer.get_token_start();
    while(!next.empty()) {
        if(!importer.has_changed_line())
            importer.format_error("This expression is unrelated to the previous one. It should start in a new line.");
        else {
            // keep this otherwise useless else statement in case we want to skip the previous format error
            auto line_indentation = importer.get_token_start();
            if(line_indentation>indentation)
                importer.format_error("This expression should not be further indented than the previous one in the same code block.");
            if(line_indentation<indentation) {
                importer.rollback_token();
                return;
            }
        }
        parse_expression(importer, variations, next);
        next = importer.next();
    }
}

void Module::parse_expression(Importer& importer, std::vector<SpecializedFunction>& variations, std::string_view next) {
    // handle redundant parentheses
    if(next=="(") {
        parse_expression(importer, variations, importer.next());
        if(importer.next()!=")") importer.syntax_error("Needed to close an opened parenthesis here.");
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
        else importer.syntax_error("Within expression you are only allowed to use the @dynamic, @mut, and @args directives.");
        return;
    }
    if(next=="if") {
        if(!importer.has_changed_line())
            importer.syntax_error("If statements should start at the beginning of each line.");
        auto indentation = importer.get_token_start();
        parse_expression(importer, variations, importer.next());
        for(auto& variation : variations) {
            auto f = variation.function;
            if(variation.returned.size()!=1)
                importer.syntax_error("This condition is not a bool primitive.");
            auto it = f->vars.find(variation.returned[0]);
            if(it==f->vars.end())
                importer.internal_error("This condition does not evaluate to a variable.");
            if(!it->second.type 
                || !it->second.type->info.is_primitive 
                || it->second.type->info.custom_name!=get_token_id("bool"))
                importer.syntax_error("This condition is not a bool primitive.");
            f->token("if");
            f->token("(");
            f->token(variation.returned[0]);
            f->token(")");
            f->token("{");
            f->token("\n");
        }
        next = importer.next();
        if(!importer.has_changed_line())// && next!="return" && next!="fail")
            importer.syntax_error("The body of if statements should start in a new line, unless it contains only return or fail.");
        auto block_indentation = importer.get_token_start();
        if(block_indentation<=indentation)
            importer.syntax_error("The body of if statements should be indented further in.");
        parse_code_block(importer, variations, next);
        for(auto& variation : variations) {
            variation.function->token("}");
            variation.function->token("\n");
            variation.returned.clear();
        }
        return;
    }
    // handle return statements
    if(next=="fail") {
        next = importer.next();
        if(!is_string(next)) importer.type_error("Expecting a string literal for failure");
        for(auto& variation : variations) {
            auto message = std::string{next};
            variation.function->call_failure(message.c_str());
        }
        return;
    }
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
                            importer.type_error("Returned different type than the first one.");
                        auto prev = f->info.returns[variation.counter];
                        auto temp_var = is_temp(var);
                        auto temp_prev = is_temp(prev);
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
                                importer.type_error("This mismatches a previous return.");
                            f->token(prev);
                            f->token("=");
                            f->token(var);
                            f->token(";");
                            f->token("\n");
                        }
                        if(temp_prev)
                            importer.format_error("Cannot return an explicit name when the first time you returned an anonymous object here.");
                    }
                    ++variation.counter;
                }
            }
            if(importer.next()!=",") break;
        }
        for(auto& variation : variations) {
            variation.function->has_returned = true;
            variation.returned.clear();
        }
        importer.rollback_token(); // rollback our attempt to get the last comma
        return;
    }

    // parse numbers
    const auto next_as_string = std::string{next};
    if(next_as_string.size() && is_delim(next_as_string[0]))
        return; //  TODO: find why this works but the error does not
        //importer.syntax_error("Unexpected symbol at the expression starting here. The previous expression has already ended.");
    const auto next_id = get_token_id(next_as_string);
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
        //auto it = variation.poly.find(next_id);
        bool is_call = false;
        // if(it!=variation.poly.end()) {
        //     variation.candidates.insert(it->second);
        //     is_call = true;
        // }
        // // base_module is `this` but leaving it this way in case we move the code
        //else 
        {
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
                parse_expression_for_arguments(importer, variations, next);
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
            if(next!=")") importer.syntax_error("Missing closing parenthesis of function call. Perhaps an argument's expression ended prematurely.");
        }
        for(auto& variation : variations) {
            Function* selected = nullptr;
            // select exactly complete argument lists
            for(auto candidate : variation.candidates) {
                if(candidate->info.args.size()==variation.arguments.size()) {
                    if(selected) 
                        importer.type_error("More than one candidates.");
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

    // handle assignment (peek at next symbol and rollback)
    next = importer.next();
    if(next=="=") {
        for(auto& variation : variations)  
            variation.arguments.clear();
        next = importer.next();
        // gather arguments
        while(true) {
            parse_expression_for_arguments(importer, variations, next);
            for(auto& variation : variations) {
                if(variation.returned.empty())
                    importer.type_error("The right side of the assignment evaluates to an empty type.");
                for(auto ret : variation.returned)
                    variation.arguments.emplace_back(ret);
            }
            next = importer.next();
            if(next!=",") 
                break;
            next = importer.next();
        }
        importer.rollback_token();
        // gather
        for(auto& variation : variations) {
            auto f = variation.function;
            auto it_collection = f->collections.find(next_id);
            if(it_collection!=f->collections.end()) {
                if(it_collection->second.size()!=variation.arguments.size())
                    importer.type_error("Cannot assign to incompatible variable.");
                // type checking in implemented in the next `for` for clarity
            } 
            for(size_t i=0;i<variation.arguments.size();++i) {
                auto& ret = variation.arguments[i];
                auto new_name = next_as_string+"__"+id2token[ret];
                auto new_name_id = get_token_id(new_name);
                if(it_collection==f->collections.end()) 
                    f->collections[next_id].emplace_back(new_name_id);
                else
                    new_name_id = f->collections[next_id][i];
                auto rhs = f->vars.find(ret);
                if(rhs==f->vars.end())
                    importer.internal_error("Right side of the assignment contains a value that does not exist.");
                auto& a = rhs->second;
                auto it = f->vars.find(new_name_id);
                if(it==f->vars.end())
                    f->var(importer, new_name_id, a.type, a.is_mut, a.is_buffer);
                f->token(new_name_id);
                f->token("=");
                f->token(a.name);
                f->token(";");
                f->token("\n");
            }
        }
        return;
    }


    importer.rollback_token(); // because we tried to peek at next symbol (e.g. to check for assignment with "=")
    // check if the current expression is just a variable and return that
    // in this case we need every variation to have the variable
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
    if(count_is_variable && count_is_variable!=variations.size()) 
        importer.syntax_error("This variable is missing.");
    if(!count_is_variable) 
        importer.syntax_error("This variable is missing.");
}

void SpecializedFunction::print_debug() const {
    std::cout << function->export_signature()<<"\n";
    std::cout << function->export_inits("");
    std::cout << function->export_body();
    std::cout << function->export_fail();
    std::cout << function->export_release();
}
