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
#include "parser/common.h"
#include "parser/faststring.h"
#include "parser/base64.cpp"
#include <cctype>
#include <cstdlib>
#include <unordered_set>
#include <set>
#include <queue>  

using namespace std;

struct Def;
typedef shared_ptr<Def> Type;

class Memory {
public:
    unordered_map<string, Type> vars;
    unordered_set<string> all_errors;
    inline bool contains(const string& var) const {return vars.find(var)!=vars.end();}
    Memory() = default;
};


class Arg {
public:
    string name;
    Type type;
    bool mut;
    Arg(const string& n, const Type& t, bool m):name(n),type(t),mut(m){}
};

class Types: public Memory {
public:
    static unsigned long last_type_id;
    Types() = default;
    unordered_map<Def*, unsigned long> alignment_labels;
    unordered_map<unsigned long, Def*> reverse_alignment_labels;
};
unsigned long Types::last_type_id = 0;
bool log_type_resolution = false;


vector<Type> all_types;

class Def {
    static int temp;
    static string create_temp() {return "__"+numberToVar(++temp);}
    unordered_map<string, string> current_renaming;
    void parse_directive(const shared_ptr<Import>& imp, size_t& p, string next, Types& types);
    void assign_variable(const Type& type, const string& from, const string& to, const shared_ptr<Import>& i, size_t& p, bool error_on_non_primitives=false, bool check_mutables=true);
    string recommend_runtype(const Types& types, const string& candidate);
    string recommend_variable(const Types& types, const string& candidate);
    void parse_signature(const shared_ptr<Import>& imp, size_t& p, Types& types);
    void signature_until_position(vector<unordered_map<string, Type>>& results, const vector<string>& parametric_names, size_t i, const unordered_map<string, Type>& current, const Types& types);
    static void print_depth();
    
    void parse_return(const shared_ptr<Import>& imp, size_t& p, string next, Types& types);
    string parse_expression(const shared_ptr<Import>& imp, size_t& p, const string& first_token, Types& types, string curry="");
    string call_type(const shared_ptr<Import>& imp, size_t& p, Type& type, vector<string>& unpacks, const size_t first_token_pos, const string& first_token, const string& inherit_buffer, Types& types);
    string parse_expression_no_par(const shared_ptr<Import>& imp, size_t& p, const string& first_token, Types& types, string curry="");
    unordered_map<string, Type> retrievable_parameters;
public:
    static bool markdown_errors;
    static int log_depth;
    int choice_power;
    bool is_service;
    bool _is_primitive;
    bool lazy_compile;
    static bool debug;
    unordered_set<Type> options;
    vector<Arg> args;
    shared_ptr<Import> imp;
    Memory internalTypes;
    vector<string> packs;
    string finals_when_used;
    string alias_for;
    size_t pos, start, end;
    string name, vardecl, implementation, errors;
    set<string> preample;
    unordered_map<string, string> finals;         // resource closing code (transferred around)
    unordered_map<string, string> invalidators;   // also resource closing code (may happen at end of loop)
    unordered_map<string, Type> parametric_types; // type name resolution in signature (all argument types - even those not overloaded)
    unordered_map<string, Type> buffer_primitive_associations; // the type associated with buffers, nullptr if typecheck is needed
    unordered_map<string, unsigned long> alignments; // the type id nom vlues represent
    unordered_set<string> mutables;
    vector<string> uplifting_targets;
    vector<bool> uplifiting_is_loop;
    unordered_set<Type> get_options(Types& types);
    vector<Type> get_lazy_options(Types& types);
    unordered_set<string> type_trackers;
    void add_preample(const string& pre) {if(preample.find(pre)==preample.end()) preample.insert(pre);}
    void coallesce_finals(const string& original) {
        // TODO: optimize this
        unordered_set<string> previous;
        string current = original;
        previous.insert(current);
        while(current_renaming.find(current)!=current_renaming.end()) {
            current = current_renaming[current];
            if(previous.find(current)!=previous.end()) break;
            previous.insert(current);
            if(current==original) break;
            if(finals.find(current)!=finals.end()) {finals[original] += rename_var(finals[current], current, original);finals[current] = "";}
        }
    }

    Def(const string& builtin): choice_power(0), is_service(false), _is_primitive(true), lazy_compile(false), name(builtin), vardecl(""), implementation(""), errors("") {}
    Def(Types& types): choice_power(0), is_service(false), _is_primitive(false), lazy_compile(false), name(""), vardecl(""), implementation(""), errors("") {
        Types::last_type_id++;//  ensure that zero alignment has no associated type
        types.reverse_alignment_labels[Types::last_type_id] = this;
        types.alignment_labels[this] = Types::last_type_id;
    } 
    vector<string> gather_tuple(const shared_ptr<Import>& imp, size_t& p, Types& types, string& inherit_buffer, const string& curry);
    inline bool not_primitive() const {return !_is_primitive;}
    string next_var(const shared_ptr<Import>& i, size_t& p, const string& first_token, Types& types, bool test=true);
    string signature_like(Types& types, vector<string> args);
    string signature(Types &types);
    string canonic_name();
    string raw_signature();
    string rebase(const string& impl, const string& var);
    string rename_var(const string& impl, const string& from, const string& to);
    void parse(const shared_ptr<Import>& _imp, size_t& p, Types& types, bool with_signature=true);
    void end_block(const shared_ptr<Import>& i, size_t& p);
};

int Def::temp = 0;
bool Def::debug = false;
bool Def::markdown_errors = false;

#endif // DEF_H