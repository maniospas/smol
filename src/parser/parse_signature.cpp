// Copyright 2025 Emmanouil Krasanakis (maniospas@hotmail.com)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "../def.h"

int Def::log_depth = 0;
void Def::parse_signature(size_t& p, Types& types) {
    auto is_as = false;
    if(p>=imp->size()) 
        ERROR("Internal error: parsing "+name.to_string()+" has misjudged end of file");
    if(imp->at(p)=="as") 
        is_as = true;
    else if(imp->at(p)=="service") 
        is_service = true;
    else if(imp->at(p)!="def") 
        imp->error(--p, "Missing `service` or `def` to declare runtype");
    p++;
    if(!is_as) 
        name = imp->at(p++); 
    else 
        name = create_temp();
    /*if(types.contains(name)) {
        if(is_service && types.vars[name]->is_service) imp->error(--p, "A service cannot overload a runtype with the same name");
        if(!is_service && types.vars[name]->is_service) imp->error(--p, "A runtype cannot overload a service with the same name");
    }*/
    if(imp->at(p++)!="(") 
        imp->error(--p, "Missing left parenthesis");
    while(true) {
        auto autoconstruct = false;
        auto mut = false;
        auto can_access_mutables = false;
        auto next = imp->at(p++);
        if(next==")") 
            break;
        if(args.size()) {
            if(next!=",")
                imp->error(--p, "Missing comma between arguments");
            next = imp->at(p++);
        }
        if(next==",") 
            next = imp->at(p++);//spaghetios
        if(next=="@") {
            next = imp->at(p++);
            if(next!="access" && next!="mut")
                imp->error(p, "Only a `@mut` or `@access` directive is allowed here");
            if(next=="access")
                can_access_mutables = true;
            else 
                mut = true;
            next = imp->at(p++);
        }
        if(next=="@") {
            next = imp->at(p++);
            if(next=="access")
                imp->error(--p, "`@access` should be placed before `@mut`");
            if(mut)
                imp->error(--p, "Already declared `@mut`");
            mut = true;
            if(next!="mut")
                imp->error(--p, "Only a `@mut` directive is allowed here");
            next = imp->at(p++);
        }
        if(!accepted_var_name(next)) 
            imp->error(--p, "Not a valid name: "+next);
        if(types.vars.find(next)==types.vars.end()) 
            imp->error(--p, "Missing runtype: "+next);

        Variable arg_name = imp->at(p++);
        bool arg_is_buffer = false;
        if(arg_name=="[") {
            arg_is_buffer = true;
            if(imp->at(p++)!="]") 
                imp->error(--p, "Expecting [] here to indicate buffer argument");
            arg_name = imp->at(p++);
        }
        if(mut && is_service) 
            imp->error(p-2, "Services do not accept values by reference"
                "\nThis ensures failsafe-compliant extensibility."
                "\nDid you mean to declare a runtype instead?"
            );
        
        if(!types.contains(next)) 
            imp->error(--p, "Missing runtype: "+next);
        if(next==NOM_VAR && args.size()) 
            imp->error(--p, "Misplaced align\nCan only be the first argument of a runtype"
                "\nor the argument of dependent runtypes"
            );
        if(next==NOM_VAR && mut) 
            imp->error(p-2, "Cannot have a @mut nominal argument");
        Type argType = types.vars[next];
        if(arg_name=="," || arg_name==")") {
            arg_name = create_temp();
            --p;
        }
        if(!accepted_var_name(arg_name.to_string()))
            imp->error(--p, "Not a valid name");
        if(types.vars.find(arg_name)!=types.vars.end()) 
            imp->error(--p, "Invalid variable name\nIt is a previous runtype or union");
        if(can_access_mutables)
            can_access_mutable_fields.insert(arg_name);
        if(argType->lazy_compile) {
            if(argType->options.size()==0) imp->error(--p, "Internal error: No options for type: "
                +argType->name.to_string()
            );
            double option_power = -1;
            int conflicts = 0;
            Type prev_argType = argType;
            for(const auto& it : argType->options) {
                if(it->choice_power>option_power) {// && it->name==argType->name) {
                    option_power = it->choice_power;
                    argType = it;
                    conflicts = 0;
                }
                else if(it->choice_power==option_power) 
                    conflicts++;
            }
            if(conflicts) 
                argType = prev_argType;
        }
        if(argType->lazy_compile) {
            args.emplace_back(arg_name, argType, mut);
            mutables.insert(arg_name);
            vars[arg_name] = argType;
            parametric_types[argType->name] = argType;
            //for(const auto& it : argType->parametric_types) parametric_types[it.first] = it.second;
            this->lazy_compile = true; // indicate that we want to compile lazily with a second pass across all
        }
        else if(arg_is_buffer) {
            if(argType->options.size()==0) 
                imp->error(--p, "No options to determine buffer elements "
                    +argType->name.to_string()
                    +"\nAdding before the argument's type may resolve this issue"
                    +"\nby forcing usage of the a runtype with ->in its return"
                    +"\namong those overloaded with the same name/union."
                    +"\nThis annoation directly interleaves the type in the definition"
                    +"\nand removes its lexical scoping."
                );
            double option_power = -1;
            int conflicts = 0;
            auto original_type = argType;
            for(const auto& it : argType->options) {
                if(it->choice_power>option_power) {
                    option_power = it->choice_power;
                    argType = it;
                    conflicts = 0;
                }
                else if(it->choice_power==option_power) 
                    conflicts++;
            }
            if(option_power<0) 
                imp->error(--p, "No resolution options for determining buffer elements: "
                    +original_type->name.to_string()
                );
            if(conflicts) 
                imp->error(--p, "There was no criterion for resolving buffer element to one option: "
                    +original_type->name.to_string()
                    +"\nMultiple options are available"
                );
            
            vars[arg_name] = types.vars[BUFFER_VAR];
            vars[arg_name+Variable("surface")] = types.vars[PTR_VAR];
            vars[arg_name+Variable("dynamic")] = types.vars[PTR_VAR];
            buffer_types[arg_name+Variable("dynamic")] = argType;
            if(mut) 
                mutables.insert(arg_name);
            args.emplace_back(arg_name+Variable("dynamic"), types.vars[PTR_VAR], mut); // order matters
            args.emplace_back(arg_name+Variable("surface"), types.vars[PTR_VAR], mut);
        }
        else if(argType->not_primitive()) {
            retrievable_parameters[argType->name] = argType;
            vars[arg_name] = argType;
            if(autoconstruct) for(const auto& it : argType->args) {
                args.emplace_back(arg_name+it.name, it.type, mut || it.mut);
                vars[arg_name+it.name] = it.type;
                implementation += it.type->rebase(it.type->implementation, arg_name);
                for(const string& pre : it.type->preample) 
                    add_preample(pre);
                for(const string& pre : it.type->linker) 
                    add_linker(pre);
                for(const auto& it : it.type->buffer_types)
                    buffer_types[arg_name+it.first] = it.second;
                for(const auto& final : it.type->finals) 
                    finals[arg_name+final.first] = finals[arg_name+final.first] + it.type->rebase(final.second, arg_name); 
                for(const auto& it : it.type->current_renaming) 
                    current_renaming[arg_name+it.first] = arg_name+it.second;
                for(const auto& it : it.type->alignments) 
                    if(it.second) 
                        alignments[arg_name+it.first] = it.second;
                for(const auto& it : it.type->active_calls) 
                    if(it.second.exists()) 
                        active_calls[arg_name+it.first] = it.second;
                for(const auto& error : it.type->errors)
                    errors.insert(it.type->rebase(error, arg_name));
                for(const auto& it2 : it.type->vars) 
                    vars[arg_name+it2.first] = it2.second;
            }
            else {
                vars[arg_name] = argType;
                if(mut) 
                    mutables.insert(arg_name);
                if(!mut && argType->noborrow) 
                    imp->error(--p, "Argument's "
                        +arg_name.to_string()
                        +" runtype has been set as @noborrow\nThis means that arguments and variables of it can only be mutable"
                        +"\nand therefore it becomes impossible to share it with service\n(mutables cannot be assinged anywhere)."
                        +"\nAdd & before the argument name to make it mutable"
                    );
                if(mut) for(const Variable& mut : argType->mutables) 
                    mutables.insert(arg_name+mut);
                for(const auto& itarg : argType->packs) {
                    //cout << name << " " <<itarg << " " << mut << " "<<(argType->mutables.find(itarg)!=argType->mutables.end())<<"\n";
                    args.emplace_back(
                        arg_name+itarg, 
                        argType->vars[itarg], 
                        (mut || (argType->mutables.find(itarg)!=argType->mutables.end()))
                    );
                    vars[arg_name+itarg] = argType->vars[itarg];
                    for(const auto& it : argType->alignments) if(it.second) 
                        alignments[arg_name+it.first] = it.second;
                    //if(is_service && argType->mutables.find(itarg)!=argType->mutables.end()) imp->error(p-2, "Services do not accept values by reference (even implicit ones): "+pretty_var((arg_name+itarg).to_string())+"\nImplicit services could cause services to race on a shared state and are prevented.\nThis ensures failsafe-compliant extensibility.\nDid you mean to declare a runtype instead?");
                }
                for(const auto& itarg : argType->vars) {
                    // TODO: this may be too expensive - consider tracking only packs parents
                    vars[arg_name+itarg.first] = itarg.second;
                }
                for(const auto& it : argType->buffer_types)
                    buffer_types[arg_name+it.first] = it.second;
            }
        }
        else {
            if(mut) 
                mutables.insert(arg_name);
            retrievable_parameters[argType->name] = argType;
            args.emplace_back(arg_name, argType, mut);
            vars[arg_name] = argType;
            if(argType->name==NOM_VAR) {
                choice_power += 1;
                alignments[arg_name] = types.alignment_labels[this];
                if(!types.alignment_labels[this]) 
                    imp->error(--p, "Internal error: Failed to assign `this` as an alignment label");
            }
        }
        
        if(p>=imp->size()) 
            imp->error(pos+2, "Missing matching right parenthesis");
    }
}

void Def::print_depth() {
    for(int i=0;i<log_depth;++i) 
        cout<<"| "; 
}

vector<Type>& Def::get_options() {
    return options;
}

void Def::signature_until_position(vector<unordered_map<Variable, Type>>& results, const vector<Variable>& parametric_names, size_t i, const unordered_map<Variable, Type>& current, const Types& types) {
    unordered_map<Variable, Type> next(current);
    if(i>=parametric_names.size()) {
        results.push_back(next);
        return;
    }
    Variable parametric_name = parametric_names[i];
    if(current.find(parametric_name)!=current.end()) 
        return signature_until_position(results, parametric_names, i+1, current, types);
    auto& arg_options = types.vars.find(parametric_name)->second->get_options();
    bool progressed = false;
    for(const Type& option : arg_options) {
        if(option->alias_for.exists()
            && option->alias_for.exists() 
            && ranges::find(arg_options, option->vars[option->alias_for]) != arg_options.end()
        ) 
            continue;
        next[parametric_name] = option;
        signature_until_position(results, parametric_names, i+1, next, types);
        progressed = true;
    }
    if(!progressed) 
        signature_until_position(results, parametric_names, i+1, next, types);
}


bool Def::start_option_resolution(const Types& _types) {
    has_tried_to_resolve_before = false;
    unresolved_options = true;
    Types types;
    types.vars.reserve(_types.vars.size());
    types.alignment_labels.reserve(_types.alignment_labels.size());
    types.reverse_alignment_labels.reserve(_types.reverse_alignment_labels.size());
    for(const auto& it : _types.vars) 
        types.vars[it.first] = it.second;
    for(const auto& it : _types.alignment_labels) 
        types.alignment_labels[it.first] = it.second;
    for(const auto& it : _types.reverse_alignment_labels) 
        types.reverse_alignment_labels[it.first] = it.second;

    for(const auto& it : this->retrievable_parameters) {
        if(!_types.contains(it.first)) 
            imp->error(pos, "Internal error: global typesystem is unaware of runtype "+it.first.to_string());
        if(!it.second) 
            imp->error(pos, "Internal error: null runtype for "+it.first.to_string());
        if(it.second->lazy_compile) 
            imp->error(pos, "Failed to previously compile type: "
                +types.vars[it.first]->signature(types)
            );
        if(!types.vars[it.first]->lazy_compile && types.vars[it.first]!=it.second)
            break;
        types.vars[it.first] = it.second;
    }

    log_depth += 1;
    size_t p = pos;
    try {
        parse_signature(p, types);
    }
    catch(const runtime_error& e) {
        string what = e.what();
        log_depth -= 1;
        const string expected = "\033[33m`with` with no `else`";
        if(what.compare(0, expected.size(), expected) != 0) 
            throw e;
        return false;
    }
    log_depth -= 1;
    if(lazy_compile) 
        imp->error(pos, "Failed to resolve all dependent types");
    if(log_type_resolution) {
        print_depth();
        cout << signature(types) <<"\n";
        for(const auto& it : retrievable_parameters) {
            print_depth();
            cout<<"- "
                <<pretty_runtype(it.first.to_string())
                <<" is "<<it.second->signature(types)
                <<"\n";
        }
    }
    unresolved_options = false;
    return true;
}

bool Def::complete_option_resolution(const Types& _types) {
    if(has_tried_to_resolve_before) 
        return !unresolved_options;
        
    has_tried_to_resolve_before = true;
    unresolved_options = true;
    Types types;
    types.vars.reserve(_types.vars.size());
    types.alignment_labels.reserve(_types.alignment_labels.size());
    types.reverse_alignment_labels.reserve(_types.reverse_alignment_labels.size());
    for(const auto& it : _types.vars) 
        types.vars[it.first] = it.second;
    for(const auto& it : _types.alignment_labels) 
        types.alignment_labels[it.first] = it.second;
    for(const auto& it : _types.reverse_alignment_labels) 
        types.reverse_alignment_labels[it.first] = it.second;

    for(const auto& it : this->retrievable_parameters) {
        if(!_types.contains(it.first)) 
            imp->error(pos, "Internal error: global typesystem is unaware of runtype "
                +it.first.to_string()
            );
        if(!it.second) 
            imp->error(pos, "Internal error: null runtype for "
                +it.first.to_string()
            );
        if(it.second->lazy_compile) 
            imp->error(pos, "Failed to previously compile type: "
                +types.vars[it.first]->signature(types)
            );
        if(!types.vars[it.first]->lazy_compile && types.vars[it.first]!=it.second) 
            break;
        types.vars[it.first] = it.second;
    }

    log_depth += 1;
    size_t p = pos;
    try {
        parse(imp, p, types);
    }
    catch(const runtime_error& e) {
        string what = e.what();
        log_depth -= 1;
        const string expected = "\033[33m`with` with no `else`";
        if(what.compare(0, expected.size(), expected) != 0) 
            throw e;
        return false;
    }
    log_depth -= 1;
    if(lazy_compile) 
        imp->error(pos, "Failed to resolve all dependent types");

    if(log_type_resolution) {
        print_depth();cout << signature(types) <<"\n";
        for(const auto& it : retrievable_parameters) {
            print_depth();
            cout<<"- "
                <<pretty_runtype(it.first.to_string())
                <<" is "<<it.second->signature(types)
                <<"\n";
        }
    }

    unresolved_options = false;
    return true;
}

vector<Type> Def::get_lazy_options(Types& _types) {
    vector<Variable> parametric_names;
    for(const auto& it : parametric_types) 
        parametric_names.push_back(it.first);

    vector<unordered_map<Variable, Type>> argoptions;
    signature_until_position(
        argoptions, 
        parametric_names, 
        0, 
        unordered_map<Variable, Type>(), 
        _types
    );

    for(const unordered_map<Variable, Type>& argoption : argoptions) {
        auto def = make_shared<Def>(_types);
        def->retrievable_parameters = argoption;
        def->pos = pos;
        def->imp = imp;
        def->name = name;
        def->has_tried_to_resolve_before = false;
        if(!def->complete_option_resolution(_types)) 
            continue;
        options.push_back(def);
        all_types.push_back(def);
    }
    if(options.size()==0) 
        imp->error(pos, "Failed to resolve to any valid version"
            "\nCheck your `with` statements that have no `else`"
            "\nor if you have runtypes that serve as constructors of"
            "\nothers with the same name or in the same union"
        );
    return options;
}
