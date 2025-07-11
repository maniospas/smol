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
@unsafe
@about "Standard library implementation of file management that uses the C filesystem."

smo File(nom, ptr contents) -> @new
smo File(String _path) 
    path = _path:str
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{ptr contents = fopen((char*)path__contents, "r");}
    if contents:exists:not @fail{printf("Unable to open file: %.*s\n", (int)path__length, (char*)path__contents);} --
    @finally contents {if(contents)fclose((FILE*)contents);contents=0;}
    -> nom:File(contents)
smo read(Memory &memory, File f, u64 chunk_size) 
    reader = memory:allocate(chunk_size) 
    -> f, reader
smo read(Arena &memory, File f)
    reader = memory:allocate((memory.contents.size-memory.length)-1)
    -> f, reader

smo next_chunk(read &self, File f, str& value)
    with self.f.contents:exists -- // verify that we're using the correct read
    with contents = self.reader --
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = fread((char*)contents__mem, 1, contents__size, (FILE*)self__f__contents);
        if(!bytes_read) ((char*)contents__mem)[bytes_read] = '\0'; // Null-terminate for cstr compatibility of `first`
        ptr ret = bytes_read ? (ptr)contents__mem : 0;
        char first = ((char*)contents__mem)[0];
    }
    with value = nom:str(ret, bytes_read, first, contents.mem)
    ---> ret:bool
smo next_line(read &self, str& value)
    with self.f.contents:exists -- // verify that we're using the correct read
    with contents = self.reader --
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr ret = (ptr)fgets((char*)contents__mem, contents__size, (FILE*)self__f__contents);
        u64 bytes_read = ret ? strlen((char*)ret) : 0;
        char first = ((char*)contents__mem)[0];
    }
    with value = nom:str(ret, bytes_read, first, contents.mem)
    ---> ret:bool
smo next_chunk(File f, Arena &reader, str& value)
    with f.contents:exists -- // verify that we're using the correct read
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = fread((char*)reader__contents__mem, 1, reader__contents__size, (FILE*)f__contents);
        if(!bytes_read) ((char*)reader__contents__mem)[bytes_read] = '\0'; // Null-terminate for cstr compatibility of `first`
        ptr ret = bytes_read ? (ptr)reader__contents__mem : 0;
        char first = ((char*)reader__contents__mem)[0];
    }
    value = nom:str(ret, bytes_read, first, reader.contents.mem:ptr)
    -> ret:bool
smo next_line(File f, Arena &reader, str& value)
    with f.contents:exists -- // verify that we're using the correct read
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr ret = (ptr)fgets((char*)reader__contents__mem, reader__contents__size, (FILE*)f__contents);
        u64 bytes_read = ret ? strlen((char*)ret) : 0;
        char first = ((char*)reader__contents__mem)[0];
    }
    with value = nom:str(ret, bytes_read, first, reader.contents.mem:ptr)
    ---> ret:bool
smo ended(File f)
    @head{#include <stdio.h>}
    @body{
        char c = fgetc((FILE*)f__contents);
        bool has_ended = (c == EOF);
        if(!has_ended) ungetc(c, (FILE*)f__contents); 
    }
    -> has_ended
smo is_file(String _path)
    path = _path:str
    @head{#include <stdio.h>}
    @body{
        ptr f = fopen((char*)path__contents, "r");
        bool exists = (f != 0);
        if(f) fclose((FILE*)f);
    }
    -> exists
smo is_dir(String _path)
    path = _path:str
    @head{#include <sys/stat.h> #ifdef _WIN32 #define stat _stat #endif}
    @body{
        ptr info = (ptr)malloc(sizeof(struct stat));
        i64 status = stat((char*)path__contents, (struct stat*)info);
        bool is_dir = (status == 0 && (((struct stat*)info)->st_mode & S_IFMT) == S_IFDIR);
        free(info);
    }
    -> is_dir
smo remove_file(String _path)
    path = _path:str
    @head{#include <stdio.h>}
    @body{u64 status = remove((char*)path__contents);}
    if status:bool @fail{printf("Failed to remove file: %.*s\n", (int)path__length, (char*)path__contents);} 
    ----
