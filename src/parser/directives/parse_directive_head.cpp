#include "../../def.h"

void Def::parse_directive_head(const shared_ptr<Import>& imp, size_t& p, string next, Types& types) {
    if(!imp->allow_unsafe) 
        imp->error(--p, "@head is unsafe\nDeclare the file as @unsafe by placing this at the top level (typically after imports)");
    next = imp->at(p++);
    if(next!="{") 
        imp->error(--p, "Expected brackets");
    int depth = 1;
    string preample("");
    while(true) {
        next = imp->at(p++);
        if(next=="{") 
            depth++;
        if(next=="}") {
            depth--;
            if(depth==0) 
                break;
        }
        if(next=="#" && preample.size()) {
            preample += "\n#"; 
            continue;
        }
        string nextnext = imp->at(p);
        preample += next;
        if(!is_symbol(next) && !is_symbol(nextnext)) 
            preample += " ";
    }
    preample += "\n";
    add_preample(preample);
}