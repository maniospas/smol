#include "function.h"
#include "console.h"

std::unordered_map<Token, std::string> id2token;
std::unordered_map<std::string, Token> token2id;

Token get_token_id(const std::string& name) {
    const auto it = token2id.find(name);
    if(it!=token2id.end()) 
        return it->second;
    Token next_id = id2token.size();
    id2token[next_id] = name;
    token2id[name] = next_id;
    return next_id;
}

void Function::bring_in(const Importer& importer, Function * other, Token prefix) {
    // update collections, variable types, and (TODO) releases
    auto collection = collections.find(prefix);
    if(collection!=collections.end()) {
        if(collection->second.size()!=other->info.returns.size())
            importer.type_error("This has a different type than previous variable with the same name");
        for(size_t i=0;i<collection->second.size();++i) {
            auto it1 = vars.find(collection->second[i]);
            auto it2 = other->vars.find(other->info.returns[i]);
            if(it1==vars.end() || it2==other->vars.end() 
                || it1->second.type!=it2->second.type 
                || it1->second.is_buffer!=it2->second.is_buffer)
                importer.type_error("This has a different type than previous variable with the same name");
            auto newname = id2token[prefix]+"__"+id2token[it2->first];
            auto newname_id = get_token_id(newname);
            if(newname_id!=it1->first)
                importer.type_error("This has a different type than previous variable with the same name");
        }
    }
    else {
        collections[prefix].clear();
        for(const auto& ret : other->info.returns) {
            auto newname = id2token[prefix]+"__"+id2token[ret];
            collections[prefix].emplace_back(get_token_id(newname));
            auto it = other->vars.find(ret);
            if(it==other->vars.end())
                importer.internal_error(("Failed to find variable: "+id2token[ret]).c_str());
        }
        for(const auto& [name, a] : other->vars) {
            auto newname = id2token[prefix]+"__"+id2token[a.name];
            auto newname_id = get_token_id(newname);
            if(other->used_constants.contains(a.name)) {
                token(newname_id);
                token("=");
                token(a.name);
                token(";");
                token("\n");
                if(!used_constants.contains(a.name))
                    var(importer, a.name, a.type, a.is_mut, a.is_buffer);
            }
            var(importer, newname_id, a.type, a.is_mut, a.is_buffer);
        }
    }

    // bring in headers
    header.reserve(header.size()+other->header.size());
    for(const auto& token : other->header)
        header.emplace_back(token);

    // merge constants and failure codes
    for(auto token : other->used_failure_codes)
        used_failure_codes.insert(token);
    for(auto token : other->used_constants)
        used_constants.insert(token);

    // bring in body while renaming
    body.reserve(body.size()+other->body.size());
    for(const auto& token : other->body) {
        auto it = other->vars.find(token);
        if(it==other->vars.end()) body.emplace_back(token);
        else body.emplace_back(get_token_id(id2token[prefix]+"__"+id2token[token]));
    }
}

std::string Function::export_signature() const {
    auto ars = std::string{""};
    for(size_t i=0;i<info.args.size();++i) {
        if(ars.size()) ars += ansi::cyan+std::string{", "};
        auto it = vars.find(info.args[i]);
        if(it==vars.end() || !it->second.type) {
            ars += ansi::green;
            ars += "unknown";
            ars += ansi::reset;
            ars += " "+id2token[info.args[i]];
            continue;
        }
        const auto& arg = it->second;
        if(arg.is_own) ars += ansi::purple+std::string{"@own "};
        if(arg.is_access) ars += ansi::purple+std::string{"@access "};
        if(arg.is_mut) ars += ansi::purple+std::string{"@mut "};
        ars += ansi::green+(arg.type?id2token[arg.type->info.custom_name]:"unknown");
        if(arg.is_buffer) ars += ansi::cyan+std::string{"[]"};
        ars += ansi::reset;
        ars += " "+id2token[arg.name];
        // skip nominal dependent type contents
        if(arg.is_new && arg.type && arg.type->info.returns.size() && (i || !info.is_nominal)) 
            i += arg.type->info.returns.size()-1;
    }
    auto ret = std::string{""};
    for(size_t i=0;i<info.returns.size();++i) {
        auto it = vars.find(info.returns[i]);
        if(it==vars.end() || !it->second.type) {
            ars += ansi::green;
            ars += "unknown";
            ars += ansi::reset;
            ars += " "+id2token[info.returns[i]];
            continue;
        }
        const auto& arg = it->second;
        if(ret.size()) ret += ansi::cyan+std::string{", "};
        if(arg.is_own) ret += ansi::purple+std::string{"@own "};
        if(arg.is_access) ret += ansi::purple+std::string{"@access "};
        if(arg.is_mut) ret += ansi::purple+std::string{"@mut "};
        ret += ansi::green+(arg.type?id2token[arg.type->info.custom_name]:"unknown");
        if(arg.is_buffer) ars += ansi::cyan+std::string{"[]"};
        ret += ansi::reset;
        ret += " "+id2token[arg.name];
        // skip nominal dependent type contents
        if(arg.is_new && arg.type && arg.type->info.returns.size() && (i || !info.is_nominal)) 
            i += arg.type->info.returns.size()-1;
    }

    return ansi::green+id2token[info.custom_name]+ansi::cyan+"("+ars+ansi::cyan+") -> ("+ret+ansi::cyan+")"+ansi::reset;
}

std::string Function::export_inits(const std::string& prefix) const {
    auto ret = std::string{""};
    auto vars = this->vars;
    for(auto arg : info.args) {
        auto it = vars.find(arg);
        if(it!=vars.end()) it->second.name = 0;
    }
    for(const auto& constant : used_constants) {
        auto it = vars.find(constant);
        if(it==vars.end()) continue;
        if(!it->second.type->info.is_primitive) continue;
        ret += it->second.type->export_body()+" "+id2token[constant]+"="+code2constant[constant]+";\n";
        it->second.name = 0;
    }
    for(const auto& [token, var] : vars) {
        if(!var.name) continue;
        if(var.type->info.is_primitive) ret += var.type->export_body()+" "+prefix+id2token[token]+"=0;\n";
        else ret += var.type->export_inits(id2token[token]+"__");
    }
    return ret;
}
std::string Function::export_fail() const {
    auto ret = std::string{""};
    for(auto release_label : used_failure_codes) {
        const auto& message = code2failure[release_label];
        ret += id2token[release_label]+": printf(\"Error: "+message.substr(1, message.size()-2)+"\\n\");";
        ret += "__error_code="+std::to_string(release_label);
        ret += "goto __failsafe;\n";
    }
    return ret;
}
std::string Function::export_release() const {
    return "";
}
std::string Function::export_body() const {
    auto ret = std::string{""};
    bool is_prev_symbol = true;
    for(size_t i=0;i<body.size();++i) {
        auto next = id2token[body[i]];
        auto is_symbol = next.size()==1 && is_delim(next[0]);
        if(!is_symbol && !is_prev_symbol) ret += " ";
        is_prev_symbol = is_symbol;
        ret += next;
    }
    return ret;
}

std::string Function::export_service() const {
    auto ret = std::string{""};
    for(auto h : header)
        ret += id2token[h]+"\n";
    ret += "int "+id2token[info.name]+"(){\n";
    ret += "int __error_code = 0;\n";
    ret += export_inits("");
    ret += export_body();
    ret += export_fail();
    ret += export_release();

    ret += "__failsafe:\n"; 
    // TODO: add returned releases
    ret += "__return:\n";
    // TODO: add all the rest of release
    ret += "return __error_code;\n";
    ret += "}";
    return ret;
}