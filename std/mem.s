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
    if mem:bool:not -> fail("Failed to allocate Stack MemoryDevice")
    @noshare mem
    -> nom:ContiguousMemory(Stack, size, Primitive, mem)
smo allocate(Heap, u64 size, Primitive)
    @head{#include <cstdlib>}
    Primitive = Primitive
    @body{ptr mem=malloc(size*sizeof(Primitive));}
    if mem:bool:not -> fail("Failed to allocate Heap MemoryDevice")
    @finally mem {if(mem)free(mem);mem=0;}
    -> nom:ContiguousMemory(Heap, size, Primitive, mem)
smo at(allocate v, u64 pos) 
    if pos>=v.size -> fail("Out of bounds")
    with v.Primitive:is(u64) @body{u64 value = ((u64*)v__mem)[pos];}
    -- else v.Primitive:is(i64) @body{i64 value = ((i64*)v__mem)[pos];}
    -- else v.Primitive:is(f64) @body{f64 value = ((f64*)v__mem)[pos];}
    -- else v.Primitive:is(char) @body{char value = ((char*)v__mem)[pos];}
    ---> value
smo put(allocate v, u64 pos, Primitive value)
    with v.Primitive==Primitive --
    if pos>=v.size -> fail("Out of bounds")
    with value:u64==value @body{((u64*)v__mem)[pos] = value;}
    -- else value:i64==value @body{((i64*)v__mem)[pos] = value;}
    -- else value:f64==value @body{((f64*)v__mem)[pos] = value;} 
    -- else value:char==value @body{((char*)v__mem)[pos] = value;}
    ---> v
smo allocate(MemoryDevice, u64 size) -> allocate(MemoryDevice, size, char)

smo Arena(nom type, ContiguousMemory contents)
    with contents.Primitive:is(char)
    length = 0 
    ---> type, contents, length
smo allocate_arena(MemoryDevice, u64 size) -> nom:Arena(MemoryDevice:allocate(size, char))
smo allocate(Arena &self, u64 size) 
    if (self.length+size)>=self.contents.size -> fail("Out of bounds")
    ret = Heap:allocate_arena(0)
    @body{ret__contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{ret__size=size;}
    -> ret

smo len(Arena self) -> self.length
smo read(Arena &self)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));
        if(fgets((char*)_contents, self__contents__size-self__length, stdin)) {
            u64 length = strlen((char*)_contents);
            if(length > 0 && ((char*)_contents)[length - 1] == '\n') {
                length -= 1;
                ((char*)_contents)[length] = '\0';
                char first = ((char*)_contents)[0];
                self__length = self__length+length;
            }
            else if(length) {_contents = 0;}
        }
    }
    if _contents:exists:not -> fail("Tried to read more elements than remaining arena size")
    -> nom:str(_contents, length, first, self__contents__mem)

union Memory(MemoryDevice, Arena)
smo is(Arena, Arena) --