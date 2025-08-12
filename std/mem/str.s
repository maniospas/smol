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

@include std.builtins
@include std.mem.arena
@unsafe
@about "Standard library implementation of string operations using its own allocators and C memory operations."

smo copy(Memory &allocator, str _s)
    s = _s:str
    // strings fresh out from the copy operation are null terminated
    mem = allocator:allocate(s.length+1, char)
    @body{
        char first = 0;
        if(mem__mem) {
            memcpy((char*)mem__mem, s__contents, s__length);
            ((char*)mem__mem)[s__length] = '\0';
        }
    }
    -> nom:str(mem.mem, s.length, first, mem.underlying)

smo add(Memory &allocator, String _x, IndependentString _y)
    x = _x:str
    y = _y:str
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = y__length;
        u64 total_len = len_x + len_y;
    }
    mem = allocator:allocate(total_len, char)
    _contents = mem.mem
    @body{
        if(_contents) {
            memcpy((char*)_contents, (char*)x__contents, len_x);
            memcpy((char*)_contents + len_x, (char*)y__contents, len_y);
        }
    }
    -> nom:str(_contents, total_len, x.first, mem.underlying)

smo tostr(Memory &allocator, i64 number)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    mem = allocator:allocate(21, char)
    readbuf = mem.mem
    @body{
        if(readbuf) {
            u64 length = (u64)snprintf((char*)readbuf, sizeof(char)*21, "%ld", number);
            if (length < 32) {
                ptr contents = malloc(length + 1);
                if(contents) {
                    memcpy(contents, (char*)readbuf, length);
                    ((char*)contents)[length] = '\0';
                    char first = ((char*)contents)[0];
                }
            }
        }
    }
    if(contents:exists:not) @fail{printf("Failed to allocate str from number\n");} --
    -> nom:str(contents, length, first, mem.underlying)

smo tostr(Memory &allocator, u64 number)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    mem = allocator:allocate(21, char)
    readbuf = mem.mem
    @body{
        if(readbuf) {
            u64 length = (u64)snprintf((char*)readbuf, sizeof(char)*21, "%lu", number);
            if (length < 32) {
                ptr contents = malloc(length + 1);
                if(contents) {
                    memcpy(contents, (char*)readbuf, length);
                    ((char*)contents)[length] = '\0';
                    char first = ((char*)contents)[0];
                }
            }
        }
    }
    if(contents:exists:not) @fail{printf("Failed to allocate str from number\n");} --
    -> nom:str(contents, length, first, mem.underlying)

smo tostr(Memory &allocator, f64 number)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    mem = allocator:allocate(25, char)
    readbuf = mem.mem
    @body{
        if(readbuf) {
            u64 length = (u64)snprintf((char*)readbuf, sizeof(char)*25, "%.6f", number);
            if(length < 32) {
                ptr contents = malloc(length + 1);
                if(contents) {
                    memcpy(contents, (char*)readbuf, length);
                    ((char*)contents)[length] = '\0';
                    char first = ((char*)contents)[0];
                }
            }
        }
    }
    if(contents:exists:not) @fail{printf("Failed to allocate str from number\n");} --
    -> nom:str(contents, length, first, mem.underlying)