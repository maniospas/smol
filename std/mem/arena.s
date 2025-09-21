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

smo Arena(nominal type, ContiguousMemory contents)
    @noborrow
    length = 0
    size = contents.size
    with contents.Primitive:is(char) 
    --
    return type, contents, length, size

smo Volatile(nominal type, ContiguousMemory contents)
    @noborrow  // we need this so that controlled_corrupt can properly analyze corruptions
    length = 0
    cycles = 0
    with contents.Primitive:is(char)
    --
    return type, contents, length, cycles

smo controlled_corrupt(@access @mut Volatile self)
    if self.cycles:bool 
        return fail("Volatile corrupt detected that some data have already been corrupted by insufficient space instead.")
    @body{self__length=0;}
    return ended

union DerivedMemory
    Arena
    Volatile

smo len(@access @mut DerivedMemory self) 
    return self.contents.size

smo Dynamic(nominal) 
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
    return @args, acquired, size, allocated, __dynamic_entry // TODO: investigate what __dynamic_entry needs to be tracked when calling Heap:dynamic

smo dynamic(@access Heap) 
    return nominal:Dynamic

smo dynamic(@access Stack) 
    return nominal:Stack
    
smo allocate(@access @mut Dynamic self, u64 size, Primitive)
    @head{#include <stdlib.h>}
    primitive = Primitive
    if self.acquired:bool:not 
        return fail("Did not initialize Dynamic")
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
            ptr mem=(ptr)__runtime_alloc(size*sizeof(primitive));
            if(success=mem) {
                ((ptr**)self__acquired)[0][self__size] = mem;
                self__size = next_size;
            } 
        }
    }
    if success:not 
        return fail("Failed a Dynamic allocation")
    return nominal:ContiguousMemory(Heap, size, Primitive, mem, self.acquired)

smo allocate(@access @mut Dynamic self, u64 size) 
    return allocate(self, size, char)

smo used(@access @mut Arena self)
    return self.length

smo used(@access @mut Volatile self)
    return 0

smo allocate(@access @mut Arena self, u64 size)
    if (self.length+size)>self.contents.size 
        return fail("Failed an Arena allocation")
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    return nominal:ContiguousMemory(self.contents.MemoryDevice, size, char, _contents, self.contents.underlying)

smo allocate(@access @mut Arena self, u64 _size, Primitive) 
    primitive = Primitive
    @body{u64 size = _size*sizeof(primitive);}
    if (self.length+size)>self.contents.size 
        return fail("Failed an Arena allocation")
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    return nominal:ContiguousMemory(self.contents.MemoryDevice, size, Primitive, _contents, self.contents.underlying)

smo allocate(@access @mut Volatile self, u64 size)
    if size>self.contents.size 
        return fail("Failed an Volatile allocation")
    @body{if(self__length+size>self__contents__size) {self__length = 0;self__cycles=self__cycles+1;}}
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    return nominal:ContiguousMemory(self.contents.MemoryDevice, size, char, _contents, self.contents.underlying)

smo allocate(@access @mut Volatile self, u64 _size, Primitive) 
    primitive = Primitive
    @body{u64 size = _size*sizeof(primitive);}
    if size>self.contents.size return fail("Failed a Volatile allocation")
    @body{if(self__length+size>self__contents__size) {self__length = 0;self__cycles=self__cycles+1;}}
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length);}
    @body{self__length = self__length+size;}
    return nominal:ContiguousMemory(self.contents.MemoryDevice, size, Primitive, _contents, self.contents.underlying)

smo read(@access @mut Arena self)
    @acquire "std.terminal.read"
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    @body{
        if (self__length >= self__contents__size) {
            ptr _contents = 0;
        } else {
            char *dest = (char*)self__contents__mem + self__length;
            u64 maxlen = self__contents__size - self__length;

            if (fgets(dest, maxlen, stdin)) {
                u64 length = strlen(dest);

                // Trim CR or LF
                if (length && (dest[length - 1]==10 || dest[length - 1]==13)) {
                    dest[--length] = 0;
                }

                self__length += length;
                _contents = dest;
                char first = (length ? dest[0] : 0);
            } else {
                _contents = 0;
            }
        }
    }
    if _contents:exists:not 
        return fail("Error: Tried to read more elements than remaining Arena size or read failed")
    return nominal:str(_contents, length, first, self__contents__mem)

union Memory
    MemoryDevice
    DerivedMemory
    Dynamic

union BoundedMemory
    Arena
    Volatile

smo is(@access @mut Memory self, @mut Memory) 
    return self

smo arena(@access @mut Memory self, u64 size) 
    return nominal:Arena(self:allocate(size))
    
smo volatile(@access @mut Memory self, u64 size) 
    return nominal:Volatile(self:allocate(size))
