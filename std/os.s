@include std.builtins
@include std.mem
@unsafe
@about "Standard library wrapping of C system calls."

smo system(cstr command)
    @head{#include <cstdlib>}
    @body{u64 result = system((char*)command);}
    if result!=0 -> fail("System call failed")
    --

smo system(str command) 
    system(Stack:copy(command).memory:cstr)
    --
