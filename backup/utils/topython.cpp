#include "topython.h"

string to_ctypes(const Type t) {
    if(t->name == "f64") 
        return "ctypes.c_double";
    if(t->name == "i64") 
        return "ctypes.c_long";
    if(t->name == "u64") 
        return "ctypes.c_uint64";
    if(t->name == "cstr") 
        return "ctypes.c_char_p";
    if(t->name == "ptr")   
        return "ctypes.c_void_p";
    return "ctypes.c_void_p";
}

string to_python_type(const Type t) {
    if(t->name == "f64") 
        return "(float, int)";
    if(t->name == "i64") 
        return "int";
    if(t->name == "u64") 
        return "int";
    if(t->name == "cstr") 
        return "(bytes, str)";
    return "object";
}