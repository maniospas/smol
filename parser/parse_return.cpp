void parse_return(const shared_ptr<Import>& imp, size_t& p, string next, Memory& types) {
    if(imp->at(p)=="-") {++p;return;}
    if(imp->at(p++)!=">") imp->error(p-2, "Use `->` to return a value or `--` to return without a value for expressions starting with `-`");
    next = imp->at(p++);
    if(next=="@") {
        next = imp->at(p++);
        if(next == "scope") packs.push_back("@scope");
        else {if(next!="new") imp->error(--p, "Use `->@new` or `->@scope`"); for(const auto& arg : args) packs.push_back(arg.name);}
    }
    else if(next!="(") {
        next = parse_expression(imp, p, next, types);
        if(!is_primitive(next) && internalTypes.vars[next]->args.size()) {
            if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared (error during return)");
            auto oneType = internalTypes.vars[next];
            if(oneType->packs.size()!=1) imp->error(--p, "Can only convert a primitive result to a primitive");
            next = next+"__"+oneType->packs[0];
        }
        packs.push_back(next);
    }
    else {
        // we are starting parenthesis
        while(true) {
            next = parse_expression(imp, p, imp->at(p++), types);
            if(!is_primitive(next) && internalTypes.vars[next]->args.size()) {
                if(internalTypes.vars.find(next)==internalTypes.vars.end()) imp->error(--p, "Symbol not declared (error during return)");
                auto oneType = internalTypes.vars[next];
                if(oneType->packs.size()!=1) imp->error(--p, "Can only convert a primitive result to a primitive");
                next = next+"__"+oneType->packs[0];
            }
            packs.push_back(next);
            next = imp->at(p++);
            if(next==")") break;
            if(next!=",") imp->error(--p, "Missing comma (not implemented expression in return statements yet)");
        }
    }
}
