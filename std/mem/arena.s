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

@about
"Standard library implementation of arena allocation. Pointer arithmetics yield "
"offsets within arenas."

@about Arena
"A fixed-sized arena that can be cleared. Data stored on this could be zero-initialized."

@about Circular 
"A fixed-sized arena that can be cleared and circularly corrupted. Data stored on this "
"could be zero-initialized."

@about arena
"Allocates an Arena buffer of given size on the given Memory. Allocations on this can be "
"shared and corrupted."

@about circular 
"Allocates a Circular buffer a of given size on the given Memory. Allocations on this can "
"be shared and corrupted."

@about clear
"Clears an Arena or Circular arena by resetting its occupied length to zero. This can "
"lead to overwriting previous data."

def Arena(nominal type, ContiguousMemory contents)
    length = 0 
    return type, contents, length

def Circular(nominal type, ContiguousMemory contents)
    length = 0
    return type, contents, length

def clear(@access @mut Circular self)
    @body{self__length=0;}

def clear(@access @mut Arena self)
    @body{self__length=0;}

union Buffer = Arena or Circular

def len(@access @mut Buffer self) 
    return self.contents.size

def Dynamic(nominal) 
    @noborrow
    @body{
        ptr acquired = __runtime_alloc(sizeof(ptr**));
        if(acquired)((ptr**)acquired)[0]=0;
    }
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
    return @args, acquired, size, allocated, __dynamic_entry // TODO. investigate what __dynamic_entry needs to be tracked when calling Heap.dynamic

def dynamic(@access Heap) 
    return nominal.Dynamic()

def dynamic(@access Stack) 
    return nominal.Stack()
    
def allocate(@access @mut Dynamic self, u64 size)
    @head{#include <stdlib.h>}
    if self.acquired.bool().not()
        fail("Did not initialize Dynamic")
    @body{
        u64 next_size = self__size+1;
        bool success = true;
        u64 self__allocated__prev = self__allocated;
        if(next_size>=self__allocated) {
            self__allocated = self__allocated+self__allocated/2+1; // ~50% growth strategy
            ptr next_acquired = (ptr)(((ptr**)self__acquired)[0]?__runtime_realloc(((ptr**)self__acquired)[0], self__allocated*sizeof(ptr), self__allocated__prev*sizeof(ptr)):__runtime_alloc(self__allocated*sizeof(ptr)));
            if((success=next_acquired)) ((ptr**)self__acquired)[0] = (ptr*)next_acquired;
        }
        if(success) {
            ptr mem=(ptr)__runtime_alloc(size);
            if((success=mem)) {
                ((ptr**)self__acquired)[0][self__size] = mem;
                self__size = next_size;
            } 
        }
    }
    if success.not() 
        fail("Failed a Dynamic allocation")
    return nominal.ContiguousMemory(size, mem, self.acquired)

def used(@access @mut Buffer self)
    return self.length

def allocate(@access @mut Arena self, u64 size)
    if(self.length+size)>self.contents.size
        fail("Failed an Arena allocation")
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    return nominal.ContiguousMemory(size, _contents, self.contents.underlying)

def allocate(@access @mut Circular self, u64 size)
    if size>self.contents.size 
        fail("Failed an Circular allocation")
    @body{if(self__length+size>self__contents__size) {self__length = 0;}}
    @body{ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));}
    @body{self__length = self__length+size;}
    return nominal.ContiguousMemory(size, _contents, self.contents.underlying)

def read(@access @mut Arena self)
    @acquire "std.terminal.read"
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    @body{
        if(self__length >= self__contents__size) {
            ptr _contents = 0;
        } else {
            char *dest = (char*)self__contents__mem + self__length;
            u64 max_len = self__contents__size - self__length;
            if(fgets(dest, max_len, stdin)) {
                u64 length = strlen(dest);

                // Trim CR or LF
                if(length && (dest[length - 1]==10 || dest[length - 1]==13)) {
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
    if _contents.exists().not() 
        fail("Error: Tried to read more elements than remaining Arena size or read failed")
    return nominal.str(_contents, length, first, self__contents__mem)

union Memory = MemoryDevice or Buffer or Dynamic

def is(@access @mut Memory self, @mut Memory) 
    return self

def arena(@access @mut Memory self, u64 size) 
    return nominal.Arena(self.allocate(size))
    
def circular(@access @mut Memory self, u64 size) 
    return nominal.Circular(self.allocate(size))
