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

@include std.mem.allocate
@unsafe
@about "Standard library implementation of arena allocation, which is marked as @noborrow but still unsafely returned from runtypes serving as constructors. Pointer arithmetics are also used to obtain offsets within arenas."

smo Arena (nom type, ContiguousMemory contents)
    @noborrow
    with contents.Primitive:is(char) --
    length = 0
    -> type, contents, length

smo len(Arena &self) 
    -> self.length

smo reserved(Arena &self) 
    -> self.contents.size

smo allocate_arena(MemoryDevice, u64 size)
    -> nom:Arena(MemoryDevice:allocate(size, char))

smo _arena(ContiguousMemory mem) 
    with &ret = nom:Arena(mem) 
    ---> ret  // TODO: Fix the reason this runtype is needed

smo allocate(Arena &self, u64 size)
    if (self.length+size)>self.contents.size -> fail("Failed an Arena allocation")
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    -> nom:ContiguousMemory(self.contents.MemoryDevice, size, char, _contents, self.contents.underlying)

smo allocate_arena(Arena &self, u64 size) 
    -> _arena(allocate(self, size))

smo allocate(Arena &self, u64 _size, Primitive) 
    Primitive = Primitive
    @body{u64 size = _size*sizeof(Primitive);}
    if (self.length+size)>self.contents.size -> fail("Failed an Arena allocation")
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    -> nom:ContiguousMemory(self.contents.MemoryDevice, size, Primitive, _contents, self.contents.underlying)

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
    if _contents:exists:not -> fail("Tried to read more elements than remaining Arena size")
    -> nom:str(_contents, length, first, self__contents__mem)

union Memory(MemoryDevice, Arena)
smo is(Arena&, Arena&) --
