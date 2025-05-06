string signature() {
    //if(!args.size()) return name;
    string ret("");
    for(const auto& arg : args) {
        if(ret.size()) ret += ", ";
        ret += ""+arg.type->name+" "+(arg.mut?"&":"")+pretty_var(arg.name);
    }
    return name+"("+ret+")";
}

string canonic_name() {
    string ret = name;
    for(const auto& arg : args) ret += "__"+arg.type->canonic_name();
    return ret;
}

string raw_signature() {
    //if(!args.size()) return name;
    string ret("");
    if(is_service) for(size_t i=1;i<packs.size();++i) {
        if(i>=2) ret += ", ";
        ret += ""+internalTypes.vars[packs[i]]->name+" &"+packs[i];
    }
    for(const auto& arg : args) {
        if(ret.size()) ret += ", ";
        ret += ""+arg.type->name+" "+(arg.mut?"&":"")+arg.name;
    }
    return name+"("+ret+")";
}