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

@include std.mem.device
@unsafe
@about "Standard library implementation of arena allocation, marked as @noborrow but unsafely returned from constructors. Pointer arithmetics yield offsets within arenas."

smo Arena(nom type, ContiguousMemory contents)
    @noborrow
    length = 0
    size = contents.size
    with contents.Primitive:is(char)
    ---> type, contents, length, size

smo Volatile(nom type, ContiguousMemory contents)
    @noborrow  // we need this so that controlled_corrupt can properly analyze corruptions
    length = 0
    cycles = 0
    with contents.Primitive:is(char)
    ---> type, contents, length, cycles

smo controlled_corrupt(Volatile &self)
    if self.cycles:bool -> fail("Volatile corrupt detected that some data have already been corrupted by insufficient space instead.")
    @body{self__length=0;}
    --

union DerivedMemory
    Arena
    Volatile
    --

smo len(DerivedMemory &self) 
    -> self.contents.size

smo Dynamic(nom) 
    @noborrow
    @body{ptr acquired = __runtime_alloc(sizeof(ptr**));if(acquired)((ptr**)acquired)[0]=0;}
    size = 0
    allocated = 0
    @finally acquired {
        if(acquired) {
            for(u64 __dynamic_entry=0;__dynamic_entry<size;++__dynamic_entry) {
                __runtime_free(((ptr**)acquired)[0][__dynamic_entry]);                
            }
            __runtime_free(acquired);
            acquired=0;
            size = 0;
            allocated = 0;
        } 
    }
    -> @new, acquired, size, allocated, __dynamic_entry // TODO: investigate what __dynamic_entry needs to be tracked when calling Heap:new_dynamic

smo new_dynamic(Heap) 
    -> nom:Dynamic

smo new_dynamic(Stack) 
    -> nom:Stack
    
smo allocate(Dynamic& self, u64 size, Primitive)
    @head{#include <stdlib.h>}
    Primitive = Primitive
    if self.acquired:bool:not 
        -> fail("Did not initialize Dynamic")
    @body{
        u64 next_size = self__size+1;
        bool success = true;
        u64 self__allocated__prev = self__allocated;
        if(next_size>=self__allocated) {
            self__allocated = self__allocated+self__allocated/2+1; // ~50% growth strategy
            ptr next_acquired = (ptr)(((ptr**)self__acquired)[0]?__runtime_realloc(((ptr**)self__acquired)[0], self__allocated*sizeof(ptr), self__allocated__prev*sizeof(ptr)):__runtime_alloc(self__allocated*sizeof(ptr)));
            if(success=next_acquired) ((ptr**)self__acquired)[0] = (ptr*)next_acquired;
        }
        if(success) {
            ptr mem=(ptr)__runtime_alloc(size*sizeof(Primitive));
            if(success=mem) {
                ((ptr**)self__acquired)[0][self__size] = mem;
                self__size = next_size;
            } 
        }
    }
    if success:not 
        -> fail("Failed a Dynamic allocation")
    -> nom:ContiguousMemory(Heap, size, Primitive, mem, self.acquired)

smo allocate(Dynamic &self, u64 size) 
    -> allocate(self, size, char)

smo used(Arena &self)
    -> self.length

smo used(Volatile & self)
    -> 0

smo allocate(Arena &self, u64 size)
    if (self.length+size)>self.contents.size 
        -> fail("Failed an Arena allocation")
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    -> nom:ContiguousMemory(self.contents.MemoryDevice, size, char, _contents, self.contents.underlying)

smo allocate(Arena &self, u64 _size, Primitive) 
    Primitive = Primitive
    @body{u64 size = _size*sizeof(Primitive);}
    if (self.length+size)>self.contents.size 
        -> fail("Failed an Arena allocation")
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    -> nom:ContiguousMemory(self.contents.MemoryDevice, size, Primitive, _contents, self.contents.underlying)

smo allocate(Volatile &self, u64 size)
    if size>self.contents.size 
        -> fail("Failed an Volatile allocation")
    @body{if(self__length+size>self__contents__size) {self__length = 0;self__cycles=self__cycles+1;}}
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    -> nom:ContiguousMemory(self.contents.MemoryDevice, size, char, _contents, self.contents.underlying)

smo allocate(Volatile &self, u64 _size, Primitive) 
    Primitive = Primitive
    @body{u64 size = _size*sizeof(Primitive);}
    if size>self.contents.size -> fail("Failed a Volatile allocation")
    @body{if(self__length+size>self__contents__size) {self__length = 0;self__cycles=self__cycles+1;}}
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
            if(length && ((char*)_contents)[length - 1] == 13) {
                length -= 1;
                ((char*)_contents)[length] = 0;
            }
            if(length) {
                char first = ((char*)_contents)[0];
                self__length = self__length+length;
                length -= 1;
            }
        }
    }
    if _contents:exists:not 
        -> fail("Error: Tried to read more elements than remaining Arena size")
    -> nom:str(_contents, length, first, self__contents__mem)

union Memory
    MemoryDevice
    DerivedMemory
    Dynamic
    --

union BoundedMemory
    Arena
    Volatile
    --

smo is(Memory& self, Memory&) 
    -> self

smo new_arena(Memory& self, u64 size) 
    -> nom:Arena(self:allocate(size))
    
smo new_volatile(Memory& self, u64 size) 
    -> nom:Volatile(self:allocate(size))
