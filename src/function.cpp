#include "function.h"

std::unordered_map<Token, std::string> id2token;
std::unordered_map<std::string, Token> token2id;

void Function::import(Importer& importer, bool is_service) {
    // parse name
    this->is_service = is_service;
    auto name = std::string{importer.next()};
    if(name.empty() || is_delim(name[0]))
        importer.syntax_error("Invalid function name");
    info.name = get_token_id(name);

    auto next = importer.next();
    while(!next.empty()) {
        if(next=="def" || next=="service" || next=="union") {
            importer.rollback_token();
            break;
        }
        raw_tokens.push_back(get_token_id(std::string{next}));
        next = importer.next();
    }
}