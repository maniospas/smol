@include std.builtins


smo system(cstr command)
    @head{#include <cstdlib>}
    @body{u64 result = system((char*)command);}
    if result!=0 -> fail("System call failed")
    --

smo system(str command) -> system(command:copy)
