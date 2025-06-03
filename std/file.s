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
@include std.builtins.str
@include std.builtins.err
@include std.mem

smo file(nom, ptr contents) -> @new
smo file(str path) 
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{ptr contents = fopen((char*)path__contents, "r");}
    if contents:exists:not @fail{printf("Unable to open file: %.*s\n", (int)path__length, (char*)path__contents);} --
    @finally contents {if(contents)fclose((FILE*)contents);contents=0;}
    -> nom:file(contents)
smo file(cstr path) -> file(path:str)

smo chunks(nom type, file &f, u64 chunk_size, Memory)
    reader = nom:allocate(Memory, chunk_size, char)
    -> type, f, reader

smo next(chunks &self, str& value)
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = fread((char*)self__reader__mem, 1, self__reader__size, (FILE*)self__f__contents);
        if(!bytes_read) ((char*)self__reader__mem)[bytes_read] = '\0'; // Null-terminate for cstr compatibility
        ptr ret = bytes_read ? (ptr)self__reader__mem : 0;
        char first = ((char*)self__reader__mem)[0];
    }
    value = nom:str(ret, bytes_read, first)
    -> ret:bool

smo ended(file f)
    @head{#include <stdio.h>}
    @body{
        char c = fgetc((FILE*)f__contents);
        bool has_ended = (c == EOF);
        if(!has_ended) ungetc(c, (FILE*)f__contents); 
    }
    -> has_ended

smo isfile(str path)
    @head{#include <stdio.h>}
    @body{
        ptr f = fopen((char*)path__contents, "r");
        bool exists = (f != 0);
        if(f) fclose((FILE*)f);
    }
    -> exists
smo isfile(cstr path) -> isfile(path:str)

smo isdir(str path)
    @head{#include <sys/stat.h> #ifdef _WIN32 #define stat _stat #endif}
    @body{
        ptr info = (ptr)malloc(sizeof(struct stat));
        i64 status = stat((char*)path__contents, (struct stat*)info);
        bool is_dir = (status == 0 && (((struct stat*)info)->st_mode & S_IFMT) == S_IFDIR);
        free(info);
    }
    -> is_dir
smo isdir(cstr path) -> isdir(path:str)

smo removefile(str path)
    @head{#include <stdio.h>}
    @body{u64 status = remove((char*)path__contents);}
    if status:bool @fail{printf("Failed to remove file: %.*s\n", (int)path__length, (char*)path__contents);} --
    --
smo removefile(cstr path) -> removefile(path:str)