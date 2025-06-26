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


smo copy(Memory &allocator, str s)
    // strings fresh out from the copy operation are null terminated
    mem = allocator:allocate(s.length, char)
    @body{
        char first = 0;
        if(mem__mem) {
            memcpy((char*)mem__mem, s__contents, s__length);
            ((char*)mem__mem)[s__length] = '\0';
            first = mem__mem[s__length-1];
        }
    }
    -> nom:str(mem.mem, s.length, first, mem.mem)

smo add(Memory &allocator, str x, str y)
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
    -> nom:str(_contents, len_x + len_y, x.first, _contents)

smo add(Memory &allocator, str x, cstr y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = strlen(y);
        u64 total_len = len_x + len_y;
    }
    mem = allocator:allocate(total_len, char)
    _contents = mem.mem
    @body{
        if(_contents) {
            memcpy((char*)_contents, (char*)x__contents, len_x);
            memcpy((char*)_contents + len_x, (const char*)y, len_y);
        }
    }
    -> nom:str(_contents, len_x + len_y, x.first, _contents)

smo add(Memory &allocator, cstr x, str y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = strlen(x);
        u64 len_y = y__length;
        u64 total_len = len_x + len_y;
    }
    mem = allocator:allocate(total_len, char)
    _contents = mem.mem
    @body{
        char first = 0;
        if(_contents) {
            memcpy((char*)_contents, (const char*)x, len_x);
            memcpy((char*)_contents + len_x, (char*)y__contents, len_y);
            first = ((char*)_contents)[0];
        }
    }
    -> nom:str(_contents, len_x + len_y, first, _contents)