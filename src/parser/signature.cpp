#include "../def.h"

string Def::signature_like(Types& types, vector<Variable> args) {
    string ret("");
    for(size_t i=0;i<args.size();++i) {
        size_t prev_i = i;
        if(ret.size()) ret += ",";
        if(alignments[args[i]] && types.reverse_alignment_labels[alignments[args[i]]] && types.reverse_alignment_labels[alignments[args[i]]]!=this && types.reverse_alignment_labels[alignments[args[i]]]->packs.size()>=1) {
            ret += pretty_runtype(types.reverse_alignment_labels[alignments[args[i]]]->name.to_string())+""+"["+to_string(types.reverse_alignment_labels[alignments[args[i]]]->packs.size())+"]";
            i += types.reverse_alignment_labels[alignments[args[i]]]->packs.size()-1;
        }
        else ret += ""+pretty_runtype(internalTypes.vars[args[i]]->name.to_string());
        string arg_name = pretty_var(args[prev_i].to_string());
        if(arg_name.size()) ret += " \033[38m"+arg_name;
        ret += "\033[32m";
    }
    return "\033[32m("+ret+")\033[0m";
}

string Def::signature(Types& types) {
    if(_is_primitive) return pretty_runtype(name.to_string());
    string ret("");
    for(size_t i=0;i<args.size();++i) {
        size_t prev_i = i;
        if(ret.size()) ret += ",";
        if(alignments[args[i].name] && !types.reverse_alignment_labels[alignments[args[i].name]]) ERROR("Internal error: variable type does not exist with id "+to_string(alignments[args[i].name])+" in type of "+pretty_var(name.to_string()+"__"+args[i].name.to_string()));
        if(alignments[args[i].name] && types.reverse_alignment_labels[alignments[args[i].name]]!=this && types.reverse_alignment_labels[alignments[args[i].name]]->packs.size()>=1) {
            ret += pretty_runtype(types.reverse_alignment_labels[alignments[args[i].name]]->name.to_string())+""+(args[i].mut?"\033[31m&\033[0m":"")+"["+to_string(types.reverse_alignment_labels[alignments[args[i].name]]->packs.size())+"]";
            i += types.reverse_alignment_labels[alignments[args[i].name]]->packs.size()-1;
        }
        else if(args[i].type->name=="nom" && types.reverse_alignment_labels[alignments[args[i].name]]!=this && args[i].type->packs.size()>=1) {
            ret += pretty_runtype(args[i].type->name.to_string())+""+(args[i].mut?"\033[31m&\033[0m":"")+"["+to_string(args[i].type->packs.size())+"]";
            i += args[i].type->packs.size()-1;
        }
        else ret += ""+pretty_runtype(args[i].type->name.to_string())+""+(args[i].mut?"\033[31m&\033[0m":"");
        string arg_name = pretty_var(args[prev_i].name.to_string());
        if(arg_name.size()) ret += " \033[38m"+arg_name;
        ret += "\033[32m";
    }
    if(lazy_compile) return "\033[32m:"+name.to_string()+"(\033[0m"+ret+") \033[31munresolved\033[0m with "+to_string(options.size())+" options";
    return "\033[32m"+name.to_string()+"(\033[0m"+ret+")\033[0m";
    //if(lazy_compile) return "\033[32m:"+name+"\033[0m("+ret+")->\033[31munresolved (overload or union)\033[0m";
    //return "\033[32m:"+name+"\033[0m("+ret+")->"+pretty_runtype(name)+signature_like(types, packs)+"";
}


string Def::canonic_name() {
    string ret = name.to_string();
    for(const auto& arg : args) ret += "__"+arg.type->canonic_name();
    return ret;
}

string Def::raw_signature() {
    /*string ret("");
    if(is_service) for(size_t i=1;i<packs.size();++i) {
        if(i>=2) ret += ", ";
        ret += ""+internalTypes.vars[packs[i]]->name.to_string()+" *__ref__"+packs[i].to_string();
    }
    for(const auto& arg : args) {
        if(ret.size()) ret += ", ";
        ret += ""+arg.type->name.to_string()+" "+(arg.mut?"*__ref__":"")+arg.name.to_string();
    }*/
    string ret = "void *__void__state";
    string name = this->name.to_string();
    if(is_service) name += "__"+to_string(identifier);
    return name+"("+ret+")";
}
string Def::raw_signature_state() {
    string ret("");
    ret += "errcode err;";
    for(size_t i=1;i<packs.size();++i) {
        ret += ""+internalTypes.vars[packs[i]]->name.to_string()+" *"+packs[i].to_string()+";";
    }
    for(const auto& arg : args) {
        ret += ""+arg.type->name.to_string()+" "+(arg.mut?"*":"")+arg.name.to_string()+";";
    }
    string name = raw_signature_state_name();
    return "struct "+name+"{"+ret+"};";
}
string Def::raw_signature_state_name() const {return this->name.to_string()+"__"+to_string(identifier)+"__state";}