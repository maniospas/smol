string signature() {
    string ret("");
    for(const auto& arg : args) {
        if(ret.size()) ret += ", ";
        ret += ""+arg.type->canonic_name()+" "+arg.name;
    }
    return name+"("+ret+")";
}

string canonic_name() {
    string ret = name;
    for(const auto& arg : args) ret += "__"+arg.type->canonic_name();
    return ret;
}
