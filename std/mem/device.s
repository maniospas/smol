// Written in 2025 by Emmanouil Krasanakis (maniospas@hotmail.com)
//
// To the extent possible under law, the author has dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide.
// 
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 

@include std.builtins.num
@include std.builtins.err
@unsafe
@about "Standard library implementation of memory management that accounts for the stack and heap and depends on the runtime.h implementation of heap memory, and GCC implementation of alloca. Stack alloactions cannot be returned from services, as the stack is pruned when programming function calls end. Smo runtypes are not implemented as functions, so it is fine to return stack allocations from them."
@about Stack        "Represents call stack memory. Allocating on this is near-zero cost by being just an arithmetic addition but its total size is limited - typically up to a few megabytes. Prefer this for small localized data that need to be processed exceedingly fast."
@about Heap         "Random access memory (RAM) that can be allocated with __runtime_alloc. Writing to it and reading from it can be slow for programs that keep. Modern processors optimize heap usage by prefetching and caching nearby areas as the ones you access. For this reason, prefer creating Arena regions when you have a sense of the exact amount of data you will need. Allocating on the heap can leak memory under certain conditions, but the lnaguage's safety mechanism prevents this. Use other allocators in those cases. The standard library provides a Dynamic type that also accesses several heap allocations, though with an additional level of indirection. "
@about MemoryDevice "Refers to either stack or heap memory."
@about allocate     "Allocates memory on a predetermined device given a number of entries and an optional primitive data type. If the data type is not provided, char is assumed so that the number of entries becomes equal to the number of allocated bytes. Other standard library overloads implement allocation for more memory types, derived from the devices. Allocations throughout the standard library track the raw allocated memory so that usage is finally released only when the last dependent variable (e.g., the last string allocated on a heap arena) is no longer used. See ContiguousMemory."
@about ContiguousMemory "Represents allocated memory management. It keeps track of both currently used pointer addresses, for example if these are offsets of allocated base pointers with finally segments calling __runtime_free on those, and the underlying pointer addresses. Importantly, not all this information is retained after compilation, as most of it -perhaps all- is optimized away. But this structure still helps the compiler organize where to place memory releases, if needed. Users of the standard library will not generally work with this type, as it is highly unsafe to get its pointer fields and requires annotation for the language to allow that."
@about at           "Accesses a specific memory position of the corresponding base type. This operation includes bound checks."
@about __unsafe_put "Can modify an allocated memory. This operation cannot be callsed in safe files."

smo Stack(nom) 
    -> @args 

smo Heap(nom) 
    -> @args

union MemoryDevice
    Stack
    Heap
    --

union Primitive
    char
    u64
    f64
    i64
    --

smo ContiguousMemory (
        nom, 
        MemoryDevice, 
        u64 size,
        Primitive,
        ptr mem,
        ptr underlying
    ) 
    -> @args

smo is(Primitive self, Primitive) 
    -> self

smo allocate(Stack, u64 size, Primitive) 
    if size==0 -> fail("Cannot allocate zero size")
    @head{#include <stdlib.h>}
    Primitive = Primitive
    @body{ptr mem=alloca(size*sizeof(Primitive));}
    if mem:bool:not -> fail("Failed a Stack allocation")
    @noshare mem
    -> nom:ContiguousMemory(Stack, size, Primitive, mem, mem)

smo allocate(Heap, u64 size, Primitive)
    if size==0 -> fail("Cannot allocate zero size")
    @head{#include <stdlib.h>}
    Primitive = Primitive
    @body{ptr mem=__runtime_alloc(size*sizeof(Primitive));}
    if mem:bool:not 
        -> fail("Failed a Heap allocation")
    @finally mem {if(mem)__runtime_free(mem);mem=0;}
    -> nom:ContiguousMemory(Heap, size, Primitive, mem, mem)

smo allocate(MemoryDevice, u64 size) 
    -> allocate(MemoryDevice, size, char)

smo at(ContiguousMemory v, u64 pos) 
    if pos>=v.size -> fail("ContiguousMemory out of bounds")
    with v.Primitive:is(u64) @body{u64 value = ((u64*)v__mem)[pos];}
    -- else v.Primitive:is(i64) @body{i64 value = ((i64*)v__mem)[pos];}
    -- else v.Primitive:is(f64) @body{f64 value = ((f64*)v__mem)[pos];}
    -- else v.Primitive:is(char) @body{char value = ((char*)v__mem)[pos];}
    ---> value
    
smo __unsafe_put(ContiguousMemory v, u64 pos, Primitive value)
    with v.Primitive:is(Primitive) --
    if pos>=v.size -> fail("ContiguousMemory out of bounds")
    with value:is(u64) @body{((u64*)v__mem)[pos] = value;}
    -- else value:is(i64) @body{((i64*)v__mem)[pos] = value;}
    -- else value:is(f64) @body{((f64*)v__mem)[pos] = value;} 
    -- else value:is(char) @body{((char*)v__mem)[pos] = value;}
    ---> v