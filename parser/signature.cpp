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
