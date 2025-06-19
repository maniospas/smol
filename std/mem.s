@include std.builtins.num
@include std.builtins.err


smo stack(nom) -> @new 
smo heap(nom) -> @new
smo memory(stack,heap) -- // provides memory.stack and memory.heap
union Memory(stack, heap)

union Primitive(char, u64, f64, i64)
smo zero(Primitive) -> 0:Primitive // basically Primitive(0)

// Create parametetric calls with unions or overloaded types.
// Skip argument names if they don't matter.
smo allocate(nom, stack, u64 size, Primitive) 
    @head{#include <cstdlib>}
    primitive = Primitive
    @body{ptr mem=alloca(size*sizeof(primitive));}
    if mem:bool:not -> fail("Failed to allocate stack memory")
    @noshare mem
    -> @new, mem

smo allocate(nom, heap, u64 size, Primitive)
    @head{#include <cstdlib>}
    primitive = Primitive
    @body{ptr mem=malloc(size*sizeof(primitive));}
    if mem:bool:not -> fail("Failed to allocate heap memory")
    @finally mem {if(mem)free(mem);mem=0;} // moved the value of `mem`
    -> @new, mem

// Type inference is lexically scoped: the same `allocate`
// is applied internally as the one passed as argument.
smo at(allocate v, u64 pos) 
    if pos>=v.size -> fail("Out of bounds")
    p = allocate.Primitive:zero
    with p:u64==p @body{u64 value = ((u64*)v__mem)[pos];}
    -- else p:i64==p @body{i64 value = ((i64*)v__mem)[pos];}
    -- else p:f64==p @body{f64 value = ((f64*)v__mem)[pos];}
    -- else p:char==p @body{char value = ((char*)v__mem)[pos];}
    ---> value

smo put(allocate v, u64 pos, Primitive value)
    with v.Primitive==Primitive --
    if pos>=v.size -> fail("Out of bounds")
    with value:u64==value @body{((u64*)v__mem)[pos] = value;}
    -- else value:i64==value @body{((i64*)v__mem)[pos] = value;}
    -- else value:f64==value @body{((f64*)v__mem)[pos] = value;} 
    -- else value:char==value @body{((char*)v__mem)[pos] = value;}
    ---> v