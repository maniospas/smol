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
#include "def.h"

int Def::temp = 0;
bool Def::calls_on_heap = true;
bool Def::debug = false;
bool Def::export_docs = false;
bool Def::markdown_errors = false;
unsigned long Types::last_type_id = 0;
bool log_type_resolution = false;
vector<Type> all_types;

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
const Variable NOM_VAR = Variable("nominal");
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
const Variable ALL_VAR = Variable("all");
const Variable TASK_VAR = Variable("__task");
const Variable STATE_VAR = Variable("__state");
const Variable STRUCT_VAR = Variable("struct");
const Variable ARGS_VAR = Variable("args");
const Variable VALUE_VAR = Variable("__value");
const Variable RET_VAR = Variable("__ret");
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

const Variable token_if = Variable("if(");
const Variable token_ifnot = Variable("if(!");
const Variable token_goto = Variable(")goto");
const Variable token_plus_one = Variable("+1");