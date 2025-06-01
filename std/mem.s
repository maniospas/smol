@include std.builtins.num

smo stack(nom) -> @new
smo heap(nom) -> @new
union Primitive (char, u64, f64, i64)

smo allocate(stack where, u64 size, Primitive primitive) 
    @head{#include <cstdlib>}
    @body{ptr mem=alloca(size*sizeof(primitive));}
    if mem:bool:not @fail{printf("Failed to allocate stack memory\n");} --
    -> where, mem, size, primitive

smo allocate(heap where, u64 size, Primitive primitive)
    @head{#include <cstdlib>}
    @body{ptr mem=malloc(size*sizeof(primitive));}
    if mem:bool:not @fail{printf("Failed to allocate heap memory\n");} --
    @finally mem {if(mem)free(mem);mem=0;}
    -> where, mem, size, primitive

smo at(allocate v, u64 pos) 
    if pos>=v.size -> fail("Out of bounds")
    p = v.primitive
    with p:u64==p @body{u64 value = ((u64*)v__mem)[pos];} --
    else p:i64==p @body{i64 value = ((i64*)v__mem)[pos];} --
    else p:f64==p @body{f64 value = ((f64*)v__mem)[pos];} -- 
    else p:char==p @body{char value = ((char*)v__mem)[pos];} --
    -> value

smo put(allocate v, u64 pos, Primitive value)
    if pos>=v.size -> fail("Out of bounds")
    with value:u64==value @body{((u64*)v__mem)[pos] = value;} --
    else value:i64==value @body{((i64*)v__mem)[pos] = value;} --
    else value:f64==value @body{((f64*)v__mem)[pos] = value;} --
    else value:char==value @body{((char*)v__mem)[pos] = value;} --
    -> v

union Memory (stack, heap)