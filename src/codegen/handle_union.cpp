#include "../codegen.h"

void handle_union(const shared_ptr<Import>& imp, size_t& p, Types& types) {
    auto name = imp->at(++p);
    if(types.contains(name))
        imp->error(--p, "Already defined: " + name);

    auto def = std::make_shared<Def>(types);
    all_types.push_back(def);
    def->imp = imp;
    def->pos = p;
    def->lazy_compile = true;
    def->name = name;
    types.vars[name] = def;
    p++;

    while(true) {
        auto next = imp->at(p++);
        if(next == "-" && imp->at(p++) == "-")
            break;
            
        const auto& found_type = types.vars.find(next);
        if(found_type == types.vars.end())
            imp->error(--p, "Undefined runtype: " + next);

        auto added = false;
        for(const Type& option : found_type->second->options) {
            if(!option->choice_power)
                continue;
            if(option->lazy_compile)
                imp->error(--p, "Internal error: failed to compile runtype " + option->signature(types));
            if(!std::ranges::contains(def->options, option)) {
                def->options.push_back(option);
                added = true;
            }
        }
        if(!added)
            imp->error(--p, "Missing nominal variation"
                "\nCannot create a runtype union that includes non-nominal types (those would be ignored)"
            );
    }
    
    def->assert_options_validity(imp, --p);
}
