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
#ifndef DEF_H
#define DEF_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <cctype>
#include <cctype>
#include <cstdlib>
#include <unordered_set>
#include <set>
#include <queue>
#include "tokenize.h"
#include "utils/common.h"
#include "utils/faststring.h"
#include "utils/base62.h"
#include "utils/segments.h"
#include <atomic>

using namespace std;

#define CODE_START() string(lsp?"\n```rust\n":"")
#define CODE_END() string(lsp?"```\n":"")

class Def;
using Type = shared_ptr<Def>;
using Variable = SegmentedString;
using Code = SegmentSequence;

const extern Variable BUFFER_VAR;
const extern Variable LABEL_VAR;
const extern Variable NEXT_VAR;
const extern Variable BOOL_VAR;
const extern Variable EMPTY_VAR;
const extern Variable ZERO_VAR;
const extern Variable ASSIGN_VAR;
const extern Variable RET_VAR;
const extern Variable PLUS_VAR;
const extern Variable MUL_VAR;
const extern Variable REF_VAR;
const extern Variable MINUS_VAR;
const extern Variable GT_VAR;
const extern Variable NOM_VAR;
const extern Variable U64_VAR;
const extern Variable RELEASED_VAR;
const extern Variable PTR_VAR;
const extern Variable ERRCODE_VAR;
const extern Variable IF_VAR;
const extern Variable FI_VAR;
const extern Variable LE_VAR;
const extern Variable EL_VAR;
const extern Variable LPAR_VAR;
const extern Variable RPAR_VAR;
const extern Variable COMMA_VAR;
const extern Variable ELSE_VAR;
const extern Variable WHILE_VAR;
const extern Variable LOOP_VAR;
const extern Variable ERR_VAR;
const extern Variable ALL_VAR;
const extern Variable TASK_VAR;
const extern Variable STATE_VAR;
const extern Variable STRUCT_VAR;
const extern Variable ARGS_VAR;
const extern Variable VALUE_VAR;
const extern Variable AT_VAR;
const extern Variable DOT_VAR;
const extern Variable ARROW_VAR;
const extern Variable SEMICOLON_VAR;
const extern Variable COLON_VAR;
const extern Variable ENDL_VAR;
const extern Variable COMP_LE_VAR;
const extern Variable COMP_LT_VAR;
const extern Variable UNREACHABLE_VAR;
const extern Variable TRANSIENT_VAR;
const extern Variable LBRACKET_VAR;
const extern Variable RBRACKET_VAR;

const extern Variable token_if;
const extern Variable token_ifnot;
const extern Variable token_goto;
const extern Variable token_plus_one;


class Memory {
public:
    unordered_map<string, string> all_errors;
    unordered_map<string, size_t> suppressed;
    unordered_map<Variable, Type> vars;
    inline bool contains(const Variable& var) const {
        return vars.find(var)!=vars.end() && vars.find(var)->second;
    }
    Memory() = default;
    ~Memory() = default;
};

class Arg {
public:
    Variable name;
    Type type;
    bool mut;
    Arg(const Variable& n, const Type& t, bool m):name(n),type(t),mut(m){}
    ~Arg() = default;
};

class Types: public Memory {
public:
    static atomic<unsigned long> last_type_id;
    Types() = default;
    ~Types() = default;
    shared_ptr<Import> imp;
    unordered_map<Def*, unsigned long> alignment_labels;
    unordered_map<unsigned long, Def*> reverse_alignment_labels;
};
extern bool log_type_resolution;
extern vector<Type> all_types;

class UpliftingStatus {
public:
    Variable target;
    size_t depth;
    bool mandate_return;
    bool is_loop;
    bool has_returned;
    bool has_exited;
    bool proving;
    Variable context;
    UpliftingStatus(const Variable& target, size_t depth, bool mandate_return, bool is_loop): 
        target(target), depth(depth), mandate_return(mandate_return), is_loop(is_loop), has_returned(false), has_exited(false), proving(false) {}
    ~UpliftingStatus() = default;
};

class Def : public enable_shared_from_this<Def> {
    static atomic<int> temp;
    static string create_temp() {return "__"+numberToVar(++temp);}
    static size_t symbol;
    static unordered_map<Variable, size_t> symbol_values; 
    static mutex symbol_access;
    static size_t get_symbol(const Variable& v);

    unordered_map<Variable, Variable> current_renaming;
    string recommend_runtype(const Types& types, const Variable& candidate);
    string recommend_variable(const Types& types, const Variable& candidate);
    void signature_until_position(vector<unordered_map<Variable, Type>>& results, const vector<Variable>& parametric_names, size_t i, const unordered_map<Variable, Type>& current, const Types& types);
    static void print_depth();
    unordered_map<Variable, Type> retrievable_parameters;
    Types saved_types;
    bool complete_option_resolution(const Types& _types);
    bool start_option_resolution(const Types& _types);

    // helpers to perform variable assignment and gather tuples
    void assign_variable(const Type& type, const Variable& from, const Variable& to, size_t& p, bool error_on_non_primitives=false, bool check_mutables=true);
    vector<Variable> gather_tuple(size_t& p, Types& types, const Variable& curry);

    // gather return arguments and parse return statements (includes nested returns)
    vector<Variable> map_to_return(size_t& p, Types& types, bool is_zero_level);
    void parse_return(size_t& p, Variable next, Types& types);

    // parse expression
    Variable parse_if(size_t& p, Types& types, Variable curry, size_t first_token_pos);
    Variable parse_while(size_t& p, Types& types, Variable curry, size_t first_token_pos);
    Variable parse_on(size_t& p, Types& types, Variable curry, size_t first_token_pos);
    Variable parse_with(size_t& p, Types& types, Variable curry, size_t first_token_pos);
    Variable parse_buffer_create(size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos, Type type);
    Variable parse_buffer_expect(size_t& p, Types& types, Variable curry, size_t first_token_pos);
    Variable parse_buffer_len(size_t& p, Types& types, Variable curry);
    Variable parse_buffer_push(size_t& p, Types& types, Variable curry, size_t first_token_pos);
    Variable parse_buffer_put(size_t& p, Types& types, Variable curry, size_t first_token_pos);
    
    Variable parse_primitive(size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos);
    Variable parse_runtype(size_t& p, const Variable& first_token, Types& types, Variable curry, size_t first_token_pos);
    Variable parse_expression(size_t& p, const Variable& first_token, Types& types, const Variable &curry=EMPTY_VAR);
    Variable parse_expression_no_par(size_t& p, const Variable& first_token, Types& types, Variable curry=EMPTY_VAR);
    Variable call_type(size_t& p, Type& type, vector<Variable>& unpacks, const size_t first_token_pos, const Variable& first_token, Types& types);

    // parse directives inlined in code (@head, @link, @body, @finally, @fail, @release, @noborrow, @noshare, @buffer)
    void parse_directive(size_t& p, string next, Types& types);
    void parse_directive_head(size_t& p, string next);
    void parse_directive_link(size_t& p, string next);
    void parse_directive_body(size_t& p, string next, Types& types);
    void parse_directive_finally(size_t& p, string next, Types& types);
    void parse_directive_fail(size_t& p, string next, Types& types);
    void parse_directive_release(size_t& p, string next, Types& types);

    // parse expressions that identify the next variable (through dot notation for fields, indexed access, and, or, etc)
    Variable next_var(size_t& p, const Variable& first_token, Types& types, bool test=true);
    Variable next_var_and(Variable next, size_t& p, Types& types);
    Variable next_var_or(Variable next, size_t& p, Types& types);
    Variable next_var_field(Variable next, size_t& p, const Variable& first_token, Types& types, bool test, bool& skip);
    Variable next_var_buffer_ret_at(Variable next, size_t& p, Types& types);
    Variable next_var_buffer_at(Variable next, size_t& p, Types& types);
    Variable next_var_at(Variable next, size_t& p, Types& types);
public:
    void simplify();
    void prune();
    void rename(std::unordered_map<Variable, Variable>& renaming);
    static bool calls_on_heap;
    unordered_set<Variable> can_access_mutable_fields;
    unordered_map<Variable, Type> vars;
    inline bool contains(const Variable& var) const {
        return vars.find(var)!=vars.end() && vars.find(var)->second;
    }

    Variable buffer_ptr;
    Variable buffer_size;
    Variable buffer_release;
    static bool lsp;
    static int log_depth;
    size_t identifier;
    int choice_power;
    bool is_service;
    bool _is_primitive;
    bool lazy_compile;
    bool noborrow;
    bool nozero;
    bool single;
    bool unresolved_options;
    bool has_tried_to_resolve_before;
    bool noassign;
    bool noleftover;
    static bool debug;
    static bool export_docs;
    vector<Type> options;
    vector<Arg> args;
    shared_ptr<Import> imp;
    vector<Variable> packs;
    Variable alias_for;
    size_t pos, start, end, p;
    Variable name;
    Code vardecl, implementation;
    unordered_set<Code> errors;
    size_t number_of_calls;
    set<string> preamble;
    set<string> linker;
    unordered_set<Variable> singletons;
    unordered_set<Variable> acquired;
    unordered_map<Variable, Type> buffer_types;
    unordered_map<Variable, Variable> active_calls;
    unordered_map<Variable, Variable> original_calls;
    unordered_map<Variable, bool> released;
    unordered_map<Variable, bool> has_been_service_arg;
    unordered_map<Variable, bool> has_been_retrieved_as_immutable;
    unordered_map<Variable, Code> finals;              // resource closing code (transferred around)
    unordered_map<Variable, Type> parametric_types;    // type name resolution in signature (all argument types - even those not overloaded)
    unordered_map<Variable, unsigned long> alignments; // the type id that `nom` vlues represent
    unordered_set<Variable> mutables;
    vector<UpliftingStatus> uplifting;
    
    //vector<Variable> uplifting_targets;
    //vector<bool> uplifiting_is_loop;
    vector<Type>& get_options();
    vector<Type> get_lazy_options(Types& types);
    unordered_set<Variable> type_trackers;
    string raw_signature_state_name() const;

    // constructors
    Def(const string& builtin): choice_power(1), is_service(false), _is_primitive(true), lazy_compile(false), noborrow(false), nozero(false), unresolved_options(false), has_tried_to_resolve_before(false), noassign(false), noleftover(false), name(builtin), number_of_calls(0) {}
    Def(Types& types): choice_power(0), is_service(false), _is_primitive(false), lazy_compile(false), noborrow(false), nozero(false), unresolved_options(false), has_tried_to_resolve_before(false), noassign(false), noleftover(false), name(""), number_of_calls(0) {
        Types::last_type_id++;//  ensure that zero alignment has no associated type
        types.reverse_alignment_labels[Types::last_type_id] = this;
        types.alignment_labels[this] = Types::last_type_id;
        identifier = Types::last_type_id;
    } 
    inline void clear() {
        for(const auto& it : options)
            if(it && it.get()!=this)
                it->clear();
        options.clear();
        args.clear();
        packs.clear();
        errors.clear();
        preamble.clear();
        linker.clear();
        singletons.clear();
        acquired.clear();
        buffer_types.clear();
        active_calls.clear();
        released.clear();
        has_been_service_arg.clear();
        has_been_retrieved_as_immutable.clear();
        finals.clear();
        parametric_types.clear();
        alignments.clear(); 
        mutables.clear();
        uplifting.clear();
        // uplifting_targets.clear();
        // uplifiting_is_loop.clear();
        if(imp)
            imp->tokens.clear();
        imp = nullptr;
    }
    ~Def() = default;
    inline bool not_primitive() const {return !_is_primitive;}
    inline auto estimate_stack_size() const {return vars.size()*4+args.size()*4+packs.size()*4+1024;} // extra 1024 bytes for various bookkeeping that is too complicated to track exactly 
    inline auto estimate_stack_deallocation_size() const {return estimate_stack_size();} // have this be conservative for now

    // property managers for finals, errors, mutability, service calls, etc
    void add_preamble(const string& pre);
    void add_linker(const string& pre);
    void assert_options_validity(size_t& p);
    void coalesce_finals(const Variable& original);
    void notify_release(const Variable& original);
    void notify_service_arg(const Variable& original);
    bool can_mutate_any_part(const Variable& _text);
    bool can_mutate(const Variable& _text, size_t p);
    
    // various types of exports
    string signature_like(Types& types, vector<Variable> args);
    string signature(Types &types);
    Variable canonic_name();
    string raw_signature();
    string raw_signature_state();
    Def* canonic_type() {
        if(alias_for.exists()) 
            return vars[alias_for]->canonic_type();
        return this;
    }
    void end_block(size_t& p);

    // code converters
    Code rebase(const Code& impl, const Variable& var);
    Code rename_var(const Code& impl, const Variable& from, const Variable& to);
    Code rename_var(const Code& impl, const Variable& from, const Code& to);
    void parse(const shared_ptr<Import>& _imp, size_t& p, Types& types, bool with_signature=true);
    void parse_signature(size_t& p, Types& types);
    void parse_implementation(size_t& p, bool with_signature);
    void parse_no_implementation(size_t& p, Types& types, bool with_signature=true);
};

#endif // DEF_H