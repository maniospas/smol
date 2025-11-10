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

@include std.core
@include std.mem.arena
@unsafe

@about 
"Standard library implementation of string operations using its own allocators "
"and C memory operations."

@about copy 
"Copies a string on a given Memory allocator. The result is nstr, that is, a "
"string variation is null-terminated. This operation may fail if the allocation "
"fails."

@about add  
"Overloads the + operator to concatenate two strings. The result is nstr, that "
"is, a string variation that is null-terminated. Example:"
"<pre>name = \"Mario\""
"\non Heap.arena(1024)"
"\n    message = \"It's a me, \"+name+\"!\""
"\n    end"
"\nprint(message)</pre>"

@about str
"Provides methods for converting numbers to strings that are stored on provided "
"Memory allocators. These are not necessarily null-terminated, so use nstr if that "
"is important."

@about nstr
"Provides methods for converting numbers to strings that are stored on provided "
"Memory allocators. The result is a null-terminated nstr."

def copy(@access @mut Memory allocator, String _s)
    s = _s.str()
    mem = allocator.allocate(s.length+1)
    @body{
        char first = 0;
        memcpy((char*)mem__mem, s__contents, s__length);
        ((char*)mem__mem)[s__length] = 0;
    }
    return nominal.nstr(mem.mem, s.length, first, mem.underlying)

def add(@access @mut Memory allocator, String _x, IndependentString _y)
    x = _x.str()
    y = _y.str()
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = y__length;
        u64 total_len = len_x + len_y ;
        char first = x__length?x__first:y__first;
    }
    mem = allocator.allocate(total_len+1)
    @body{bool would_corrupt = ((char*)x__memory>=((char*)mem__mem) && (char*)x__memory<=((char*)mem__mem)+len_x) || (((char*)y__memory)+len_x>=((char*)mem__mem) && (char*)y__memory<=((char*)mem__mem)+total_len);}
    if would_corrupt
        @fail{printf("String concatenation would corrupt one of the operands due to writing on its memory region - consider larger or non-overlapping circular buffers or arenas.\n");}
    _contents = mem.mem
    @body{
        memcpy((char*)_contents, (char*)x__contents, len_x);
        memcpy((char*)_contents + len_x, (char*)y__contents, len_y);
        ((char*)_contents)[total_len] = 0;
    }
    return nominal.nstr(_contents, total_len, first, mem.underlying)

def nstr(@access @mut Memory allocator, i64 number)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    mem = allocator.allocate(21)
    read_buffer = mem.mem
    @body{
        if(read_buffer) {
            u64 length = (u64)snprintf((char*)read_buffer, sizeof(char)*21, "%ld", number);
            if(length < 32) {
                ptr contents = malloc(length + 1);
                if(contents) {
                    memcpy(contents, (char*)read_buffer, length);
                    ((char*)contents)[length] = 0;
                    char first = ((char*)contents)[0];
                }
            }
        }
    }
    if contents.exists().not() 
        @fail{printf("Failed to allocate str from number\n");}
    return nominal.nstr(contents, length, first, mem.underlying)

def nstr(@access @mut Memory allocator, u64 number)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    mem = allocator.allocate(21)
    read_buffer = mem.mem
    @body{
        if(read_buffer) {
            u64 length = (u64)snprintf((char*)read_buffer, sizeof(char)*21, "%lu", number);
            if(length < 32) {
                ptr contents = malloc(length + 1);
                if(contents) {
                    memcpy(contents, (char*)read_buffer, length);
                    ((char*)contents)[length] = 0;
                    char first = ((char*)contents)[0];
                }
            }
        }
    }
    if contents.exists().not() 
        @fail{printf("Failed to allocate str from number\n");}
    return nominal.nstr(contents, length, first, mem.underlying)

def nstr(@access @mut Memory allocator, f64 number)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    mem = allocator.allocate(25)
    read_buffer = mem.mem
    @body{
        if(read_buffer) {
            u64 length = (u64)snprintf((char*)read_buffer, sizeof(char)*25, "%.6f", number);
            if(length < 32) {
                ptr contents = malloc(length + 1);
                if(contents) {
                    memcpy(contents, (char*)read_buffer, length);
                    ((char*)contents)[length] = 0;
                    char first = ((char*)contents)[0];
                }
            }
        }
    }
    if contents.exists().not() 
        @fail{printf("Failed to allocate str from number\n");}
    return nominal.nstr(contents, length, first, mem.underlying)

def str(@access ContiguousMemory region)
    @body{char first=region__size?((char*)region__mem)[0]:0;}
    return nominal.str(region.mem, region.size, first, region.underlying)

def str(@access ContiguousMemory region, u64 size)
    if size>region.size
        fail("Cannot allocate more than the available memory")
    @body{char first=region__size?((char*)region__mem)[0]:0;}
    return nominal.str(region.mem, size, first, region.underlying)

def str(@access @mut Memory allocator, u64 number)
    return nstr(allocator, number).str()

def str(@access @mut Memory allocator, i64 number)
    return nstr(allocator, number).str()

def str(@access @mut Memory allocator, f64 number)
    return nstr(allocator, number).str()
