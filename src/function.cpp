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

std::string Signature::to_string() const {
    auto ars = std::string{""};
    for(size_t i=0;i<args.size();++i) {
        const auto& arg = args[i];
        if(ars.size()) ars += ansi::cyan+std::string{", "};
        if(arg.is_own) ars += ansi::purple+std::string{"@own "};
        if(arg.is_access) ars += ansi::purple+std::string{"@access "};
        if(arg.is_mut) ars += ansi::purple+std::string{"@mut "};
        ars += ansi::green+(arg.type?id2token[arg.type->info.custom_name]:"unknown");
        if(arg.is_buffer) ars += ansi::cyan+std::string{"[]"};
        ars += ansi::reset;
        ars += " "+id2token[arg.name];
        // skip nominal dependent type contents
        if(arg.is_new && arg.type && arg.type->info.returns.size() && (i || !is_nominal)) 
            i += arg.type->info.returns.size()-1;
    }
    auto ret = std::string{""};
    for(size_t i=0;i<returns.size();++i) {
        const auto& arg = returns[i];
        if(ret.size()) ret += ansi::cyan+std::string{", "};
        if(arg.is_own) ret += ansi::purple+std::string{"@own "};
        if(arg.is_access) ret += ansi::purple+std::string{"@access "};
        if(arg.is_mut) ret += ansi::purple+std::string{"@mut "};
        ret += ansi::green+(arg.type?id2token[arg.type->info.custom_name]:"unknown");
        if(arg.is_buffer) ars += ansi::cyan+std::string{"[]"};
        ret += ansi::reset;
        ret += " "+id2token[arg.name];
        // skip nominal dependent type contents
        if(arg.is_new && arg.type && arg.type->info.returns.size() && (i || !is_nominal)) 
            i += arg.type->info.returns.size()-1;
    }

    return ansi::green+id2token[custom_name]+ansi::cyan+"("+ars+ansi::cyan+") -> ("+ret+ansi::cyan+")"+ansi::reset;
}