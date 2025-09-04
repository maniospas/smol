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
#include <unordered_map>
#include <cctype>
#include "parser/tokenize.h"
#include "utils/common.h"
#include "utils/faststring.h"
#include "utils/base64.cpp"
#include <cctype>
#include <cstdlib>
#include <unordered_set>
#include <set>
#include <queue>  
#include "utils/segments.h"


using namespace std;

struct Def;
typedef shared_ptr<Def> Type;
typedef SegmentedString Variable;
typedef SegmentSequence Code;
const Variable BUFFER_VAR = Variable("__buffer");
const Variable LABEL_VAR = Variable("__label");
const Variable NEXT_VAR = Variable("__next");
const Variable BOOL_VAR = Variable("bool");
const Variable EMPTY_VAR = Variable("");
const Variable ZERO_VAR = Variable("0");
const Variable ASSIGN_VAR = Variable("=");
const Variable PLUS_VAR = Variable("+");
const Variable MUL_VAR = Variable("*");
const Variable REF_VAR = Variable("&");
const Variable MINUS_VAR = Variable("-");
const Variable GT_VAR = Variable(">");
const Variable NOM_VAR = Variable("nom");
const Variable U64_VAR = Variable("u64");
const Variable RELEASED_VAR = Variable("__released");
const Variable PTR_VAR = Variable("ptr");
const Variable ERRCODE_VAR = Variable("errcode");
const Variable IF_VAR = Variable("if");
const Variable FI_VAR = Variable("fi");
const Variable LE_VAR = Variable("le");
const Variable EL_VAR = Variable("el");
const Variable LPAR_VAR = Variable("(");
const Variable RPAR_VAR = Variable(")");
const Variable COMMA_VAR = Variable(",");
const Variable ELSE_VAR = Variable("else");
const Variable WHILE_VAR = Variable("while");
const Variable LOOP_VAR = Variable("loop");
const Variable ERR_VAR = Variable("err");
const Variable TASK_VAR = Variable("__task");
const Variable STATE_VAR = Variable("__state");
const Variable STRUCT_VAR = Variable("struct");
const Variable VALUE_VAR = Variable("__value");
const Variable AT_VAR = Variable("@");
const Variable DOT_VAR = Variable(".");
const Variable ARROW_VAR = Variable("->");
const Variable CURRY_VAR = Variable(":");
const Variable SEMICOLON_VAR = Variable(";\n");
const Variable COLON_VAR = Variable(":\n");
const Variable ENDL_VAR = Variable("\n");
const Variable COMP_LE_VAR = Variable("<=");
const Variable COMP_LT_VAR = Variable("<");
const Variable UNREACHABLE_VAR = Variable("__builtin_unreachable();\n");
const Variable TRANSIENT_VAR = Variable("__TRANSIENT(");
const Variable LBRACKET_VAR = Variable("[");
const Variable RBRACKET_VAR = Variable("]");

class Memory {
public:
    unordered_map<Variable, Type> vars;
    unordered_map<string, string> all_errors;
    unordered_map<string, size_t> suppressed;
    inline bool contains(const Variable& var) const {return vars.find(var)!=vars.end() && vars.find(var)->second;}
    Memory() = default;
};

class Arg {
public:
    Variable name;
    Type type;
    bool mut;
    Arg(const Variable& n, const Type& t, bool m):name(n),type(t),mut(m){}
};

class Types: public Memory {
public:
    static unsigned long last_type_id;
    Types() = default;
    shared_ptr<Import> imp;
    unordered_map<Def*, unsigned long> alignment_labels;
    unordered_map<unsigned long, Def*> reverse_alignment_labels;
};
unsigned long Types::last_type_id = 0;
bool log_type_resolution = false;


vector<Type> all_types;

class Def {
    static int temp;
    vector<Variable> map_to_return(const shared_ptr<Import>& imp, size_t& p, Types& types, bool is_zero_level);
    static string create_temp() {return "__"+numberToVar(++temp);}
    unordered_map<Variable, Variable> current_renaming;
    void parse_directive(const shared_ptr<Import>& imp, size_t& p, string next, Types& types);
    void assign_variable(const Type& type, const Variable& from, const Variable& to, const shared_ptr<Import>& i, size_t& p, bool error_on_non_primitives=false, bool check_mutables=true);
    string recommend_runtype(const Types& types, const Variable& candidate);
    string recommend_variable(const Types& types, const Variable& candidate);
    void parse_signature(const shared_ptr<Import>& imp, size_t& p, Types& types);
    void signature_until_position(vector<unordered_map<Variable, Type>>& results, const vector<Variable>& parametric_names, size_t i, const unordered_map<Variable, Type>& current, const Types& types);
    static void print_depth();
    void parse_return(const shared_ptr<Import>& imp, size_t& p, Variable next, Types& types);
    Variable parse_expression(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, const Variable &curry=EMPTY_VAR);
    Variable call_type(const shared_ptr<Import>& imp, size_t& p, Type& type, vector<Variable>& unpacks, const size_t first_token_pos, const Variable& first_token, Types& types);
    Variable parse_expression_no_par(const shared_ptr<Import>& imp, size_t& p, const Variable& first_token, Types& types, Variable curry=EMPTY_VAR);
    unordered_map<Variable, Type> retrievable_parameters;
    void parse_implementation(size_t& p, bool with_signature);
    Types saved_types;
    bool complete_option_resolution(const Types& _types);
    bool start_option_resolution(const Types& _types);
    bool can_mutate(const Variable& _text) {
        if(has_been_service_arg[_text]) return false;
        string text = _text.to_string();
        if(mutables.find(text)!=mutables.end()) return true;
        size_t pos = 0;
        while((pos = text.find("__", pos)) != std::string::npos) {
            std::string part = text.substr(0, pos);
            if (mutables.find(part) != mutables.end()) return true;
            pos += 2; // Move past the current "__"
        }
        return false;
    }
public:
    static bool markdown_errors;
    static int log_depth;
    size_t identifier;
    int choice_power;
    bool is_service;
    bool _is_primitive;
    bool lazy_compile;
    bool noborrow;
    bool unresolved_options;
    bool has_tried_to_resolve_before;
    static bool debug;
    static bool export_docs;
    vector<Type> options;
    vector<Arg> args;
    shared_ptr<Import> imp;
    Memory internalTypes;
    vector<Variable> packs;
    Variable alias_for;
    size_t pos, start, end;
    Variable name;
    Code vardecl, implementation, errors;
    size_t number_of_calls;
    Variable active_context;
    set<string> preample;
    set<string> linker;
    unordered_map<Variable, Type> buffer_types;
    unordered_map<Variable, Variable> active_calls;
    unordered_map<Variable, Variable> original_calls;
    unordered_map<Variable, bool> released;
    unordered_map<Variable, bool> has_been_service_arg;
    unordered_map<Variable, Code> finals;              // resource closing code (transferred around)
    unordered_map<Variable, Type> parametric_types;    // type name resolution in signature (all argument types - even those not overloaded)
    unordered_map<Variable, unsigned long> alignments; // the type id that `nom` vlues represent
    unordered_set<Variable> mutables;
    vector<Variable> uplifting_targets;
    vector<bool> uplifiting_is_loop;
    vector<Type>& get_options(const Types& types);
    vector<Type> get_lazy_options(Types& types);
    unordered_set<Variable> type_trackers;
    bool has_returned;
    string raw_signature_state_name() const;
    void add_preample(const string& pre) {if(preample.find(pre)==preample.end()) preample.insert(pre);}
    void add_linker(const string& pre) {if(linker.find(pre)==linker.end()) linker.insert(pre);}
    void coallesce_finals(const Variable& original) {
        unordered_set<Variable> visited;
        queue<Variable> q;
        unordered_set<Variable> group;
        q.push(original);
        visited.insert(original);
        while (!q.empty()) {
            Variable var = q.front();
            q.pop();
            group.insert(var);
            if(current_renaming.count(var)) {
                Variable next = current_renaming[var];
                if(visited.insert(next).second) q.push(next);
            }
            for(const auto& [k, v] : current_renaming) if(v == var && visited.insert(k).second) q.push(k);
        }
        // Coalesce all finals into the original
        for(const Variable& name : group) if(name != original && finals.count(name)) {
            finals[original] = finals[original] + rename_var(finals[name], name, original);
            finals[name] = Code();
        }
    }
    void notify_release(const Variable& original) {
        unordered_set<Variable> visited;
        queue<Variable> q;
        unordered_set<Variable> group;
        q.push(original);
        visited.insert(original);
        while (!q.empty()) {
            Variable var = q.front();
            q.pop();
            group.insert(var);
            if(current_renaming.count(var)) {
                Variable next = current_renaming[var];
                if(visited.insert(next).second) q.push(next);
            }
            for(const auto& [k, v] : current_renaming) if(v == var && visited.insert(k).second) q.push(k);
        }
        for(const Variable& name : group) released[name] = true;
    }
    void notify_service_arg(const Variable& original) {
        unordered_set<Variable> visited;
        queue<Variable> q;
        unordered_set<Variable> group;
        q.push(original);
        visited.insert(original);
        while (!q.empty()) {
            Variable var = q.front();
            q.pop();
            group.insert(var);
            if(current_renaming.count(var)) {
                Variable next = current_renaming[var];
                if(visited.insert(next).second) q.push(next);
            }
            for(const auto& [k, v] : current_renaming) if(v == var && visited.insert(k).second) q.push(k);
        }
        for(const Variable& name : group) mutables.erase(name);
        for(const Variable& name : group) has_been_service_arg[name] = true;
    }


    Def(const string& builtin): choice_power(0), is_service(false), _is_primitive(true), lazy_compile(false), noborrow(false), unresolved_options(false), has_tried_to_resolve_before(false), name(builtin), number_of_calls(0), has_returned(false) {}
    Def(Types& types): choice_power(0), is_service(false), _is_primitive(false), lazy_compile(false), noborrow(false), unresolved_options(false), has_tried_to_resolve_before(false), name(""), number_of_calls(0), has_returned(false) {
        Types::last_type_id++;//  ensure that zero alignment has no associated type
        types.reverse_alignment_labels[Types::last_type_id] = this;
        types.alignment_labels[this] = Types::last_type_id;
        identifier = Types::last_type_id;
    } 
    vector<Variable> gather_tuple(const shared_ptr<Import>& imp, size_t& p, Types& types, const Variable& curry);
    inline bool not_primitive() const {return !_is_primitive;}
    Variable next_var(const shared_ptr<Import>& i, size_t& p, const Variable& first_token, Types& types, bool test=true);
    string signature_like(Types& types, vector<Variable> args);
    string signature(Types &types);
    Variable canonic_name();
    string raw_signature();
    string raw_signature_state();
    Code rebase(const Code& impl, const Variable& var);
    void simplify();
    Code rename_var(const Code& impl, const Variable& from, const Variable& to);
    void parse(const shared_ptr<Import>& _imp, size_t& p, Types& types, bool with_signature=true);
    void parse_no_implementation(const shared_ptr<Import>& _imp, size_t& p, Types& types, bool with_signature=true);
    void end_block(const shared_ptr<Import>& i, size_t& p);
    Def* canonic_type() {
        if(alias_for.exists()) return internalTypes.vars[alias_for]->canonic_type();
        return this;
    }
};

int Def::temp = 0;
bool Def::debug = false;
bool Def::export_docs = false;
bool Def::markdown_errors = false;

#endif // DEF_H