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

smo file(str path, u64 chunk_size) 
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{ptr contents = (ptr)fopen((char*)path__contents, "r");}
    @body{ptr reader = (ptr)malloc(4096);}
    if reader:exists:not @fail{printf("Unable to allocate buffer for file read\n");} --
    if contents:exists:not @fail{printf("Unable to open file: %.*s\n", (int)path__length, (char*)path__contents);} --
    @finally contents {if(contents)fclose((FILE*)contents);contents=0;}
    @finally reader {if(reader)free(reader);reader=0;}
    -> align, contents, reader, chunk_size

smo file(cstr path, u64 chunk_size) -> file(path:str, chunk_size)
smo file(cstr path) -> file(path:str, 4096:u64)
smo file(str path) -> file(path, 4096:u64)

smo chunk_line(file f)
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        cstr ret = (cstr)fgets((char*)f__reader, f__chunk_size, (FILE*)f__contents);
        if(!ret) ((char*)f__reader)[0] = '\0';
        ptr err = (ptr)ret;
    }
    if err:exists:not @fail{printf("File read error (maybe the file has ended)\n");} --
    -> ret

smo chunk(file f)
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = fread((char*)f__reader, 1, f__chunk_size, (FILE*)f__contents);
        if(!bytes_read) ((char*)f__reader)[bytes_read] = '\0'; // Null-terminate for cstr compatibility
        ptr ret = bytes_read ? (ptr)f__reader : NULL;
        char first = ((char*)f__reader)[0];
    }
    if ret:exists:not @fail{printf("File read error (maybe the file has ended)\n");} --
    -> align:str(ret, bytes_read, first)


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
        ptr f = (ptr)fopen((char*)path__contents, "r");
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