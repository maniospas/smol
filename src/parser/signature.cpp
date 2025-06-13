#include "../def.h"

string Def::signature_like(Types& types, vector<string> args) {
    string ret("");
    for(size_t i=0;i<args.size();++i) {
        if(ret.size()) ret += ",";
        /*if(alignments[args[i]] && types.reverse_alignment_labels[alignments[args[i]]]!=this && types.reverse_alignment_labels[alignments[args[i]]]->packs.size()>=1) {
            ret += pretty_runtype(types.reverse_alignment_labels[alignments[args[i]]]->name)+""+"["+to_string(types.reverse_alignment_labels[alignments[args[i]]]->packs.size())+"]";
            i += types.reverse_alignment_labels[alignments[args[i]]]->packs.size()-1;
        }
        else*/ ret += ""+pretty_runtype(internalTypes.vars[args[i]]->name);
    }
    return "("+ret+")";
}

string Def::signature(Types& types) {
    if(_is_primitive) return pretty_runtype(name);
    string ret("");
    for(size_t i=0;i<args.size();++i) {
        if(ret.size()) ret += ",";
        if(alignments[args[i].name] && !types.reverse_alignment_labels[alignments[args[i].name]]) ERROR("Internal error: variable type does not exist with id "+to_string(alignments[args[i].name])+" in type of "+pretty_var(name+"__"+args[i].name));
        if(alignments[args[i].name] && types.reverse_alignment_labels[alignments[args[i].name]]!=this && types.reverse_alignment_labels[alignments[args[i].name]]->packs.size()>=1) {
            ret += pretty_runtype(types.reverse_alignment_labels[alignments[args[i].name]]->name)+""+(args[i].mut?"\033[31m&\033[0m":"")+"["+to_string(types.reverse_alignment_labels[alignments[args[i].name]]->packs.size())+"]";
            i += types.reverse_alignment_labels[alignments[args[i].name]]->packs.size()-1;
        }
        else if(args[i].type->name=="nom" && types.reverse_alignment_labels[alignments[args[i].name]]!=this && args[i].type->packs.size()>=1) {
            ret += pretty_runtype(args[i].type->name)+""+(args[i].mut?"\033[31m&\033[0m":"")+"["+to_string(args[i].type->packs.size())+"]";
            i += args[i].type->packs.size()-1;
        }
        else ret += ""+pretty_runtype(args[i].type->name)+""+(args[i].mut?"\033[31m&\033[0m":"");
    }
    if(lazy_compile) return "\033[32m:"+name+"\033[0m("+ret+")->\033[31munresolved (overload or union)\033[0m";
    return "\033[32m:"+name+"\033[0m("+ret+")->"+pretty_runtype(name)+signature_like(types, packs)+"";
}


string Def::canonic_name() {
    string ret = name;
    for(const auto& arg : args) ret += "__"+arg.type->canonic_name();
    return ret;
}

string Def::raw_signature() {
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