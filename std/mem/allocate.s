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

smo Stack(nom) -> @new 
smo Heap(nom) -> @new
union MemoryDevice(Stack, Heap)
union Primitive(char, u64, f64, i64)
smo ContiguousMemory(nom, MemoryDevice, u64 size, Primitive, ptr mem) -> @new
smo is(Primitive value, Primitive) --
smo is(MemoryDevice, MemoryDevice) --

smo allocate(Stack, u64 size, Primitive) 
    @head{#include <cstdlib>}
    Primitive = Primitive
    @body{ptr mem=alloca(size*sizeof(Primitive));}
    if mem:bool:not -> fail("Failed to allocate Stack")
    @noshare mem
    -> nom:ContiguousMemory(Stack, size, Primitive, mem)

smo allocate(Heap, u64 size, Primitive)
    @head{#include <cstdlib>}
    Primitive = Primitive
    @body{ptr mem=malloc(size*sizeof(Primitive));}
    if mem:bool:not -> fail("Failed to allocate Heap")
    @finally mem {if(mem)free(mem);mem=0;}
    -> nom:ContiguousMemory(Heap, size, Primitive, mem)

smo allocate(MemoryDevice, u64 size) 
    -> allocate(MemoryDevice, size, char)

smo at(ContiguousMemory v, u64 pos) 
    if pos>=v.size -> fail("ContiguousMemory of bounds")
    with v.Primitive:is(u64) @body{u64 value = ((u64*)v__mem)[pos];}
    -- else v.Primitive:is(i64) @body{i64 value = ((i64*)v__mem)[pos];}
    -- else v.Primitive:is(f64) @body{f64 value = ((f64*)v__mem)[pos];}
    -- else v.Primitive:is(char) @body{char value = ((char*)v__mem)[pos];}
    ---> value
    
smo put(ContiguousMemory v, u64 pos, Primitive value)
    with v.Primitive:is(Primitive) --
    if pos>=v.size -> fail("ContiguousMemory of bounds")
    with value:is(u64) @body{((u64*)v__mem)[pos] = value;}
    -- else value:is(i64) @body{((i64*)v__mem)[pos] = value;}
    -- else value:is(f64) @body{((f64*)v__mem)[pos] = value;} 
    -- else value:is(char) @body{((char*)v__mem)[pos] = value;}
    ---> v