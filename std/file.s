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

smo ReadFile(nom, ptr contents)
    @noborrow
    -> @new
smo WriteFile(nom, ptr contents)
    @noborrow
    -> @new

union File(ReadFile, WriteFile)

smo File(String _path) 
    path = _path:str
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{ptr contents = fopen((char*)path__contents, "r");}
    if contents:exists:not @fail{printf("Failed to open file: %.*s\n", (int)path__length, (char*)path__contents);} --
    @finally contents {if(contents)fclose((FILE*)contents);contents=0;}
    -> nom:ReadFile(contents)

smo goto_start(File &f) 
    if f.contents:exists:not @fail{printf("Failed to move to start of closed file: %.*s\n", (int)path__length, (char*)path__contents);} --
    @body{fseek(f__contents, 0, SEEK_SET);}
    -> f

smo goto_end(WriteFile &f) 
    // only useful for moving to the end of write files. For read files, close them instead.
    @body{if(f__contents) fseek(f__contents, 0, SEEK_END);}
    -> f

smo close(File &f)
    @body{if(f__contents)fclose((FILE*)f__contents);f__contents = 0;}
    --

smo len(File &f)
    @head{#include <stdio.h>}
    @body{
        u64 pos = ftell((FILE*)f__contents);
        u64 size = 0;
        if (pos != -1L) {
            if (fseek((FILE*)f__contents, 0, SEEK_END) == 0) {
                size = ftell((FILE*)f__contents);
                fseek((FILE*)f__contents, pos, SEEK_SET);
            }
        }
    }
    -> size

smo write(WriteFile &f, String _s)
    s = _s:str
    @head{#include <stdio.h>}
    @body{
        u64 bytes_written = fwrite((char*)s__contents, 1, s__length, (FILE*)f__contents);
        bool success = (bytes_written == s__length);
    }
    if success:not @fail{printf("Failed to write to file: %.*s\n", (int)path__length, (char*)path__contents);} --
    ----

smo allocate_file(Memory& memory, u64 size)
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    mem = memory:allocate(size)
    @body {ptr contents = fmemopen(mem__mem, "w+");}
    @finally contents {if(contents)fclose((FILE*)contents);}
    -> nom:WriteFile(contents)
    
smo next_chunk(Volatile &memory, File &f, str& value)
    contents = memory.contents.mem
    size = memory.contents.size
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = f__contents?fread((char*)contents, 1, size, (FILE*)f__contents):f__contents;
        if(!bytes_read) ((char*)contents)[bytes_read] = '\0'; // Null-terminate for cstr compatibility of `first`
        ptr ret = bytes_read ? (ptr)contents : 0;
        char first = ((char*)contents)[0];
    }
    with value = nom:str(ret, bytes_read, first, memory.contents.underlying)
    ---> ret:bool

smo next_line(Volatile &memory, File &f, str& value)
    contents = memory.contents.mem
    size = memory.contents.size
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr ret = f__contents?(ptr)fgets((char*)contents, size, (FILE*)f__contents):f__contents;
        u64 bytes_read = ret ? strlen((char*)ret) : 0;
        char first = ((char*)contents)[0];
    }
    with value = nom:str(ret, bytes_read, first, memory.contents.underlying)
    ---> ret:bool

smo next_chunk(Arena &reader, File &f, str& value)
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = f__contents?fread((char*)reader__contents__mem, 1, reader__contents__size, (FILE*)f__contents):f__contents;
        if(!bytes_read) ((char*)reader__contents__mem)[bytes_read] = '\0'; // Null-terminate for cstr compatibility of `first`
        ptr ret = bytes_read ? (ptr)reader__contents__mem : 0;
        char first = ((char*)reader__contents__mem)[0];
    }
    value = nom:str(ret, bytes_read, first, reader.contents.mem:ptr)
    -> ret:bool

smo next_line(Arena &reader, File &f, str& value)
    with f.contents:exists -- // verify that we're using the correct read
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr ret = f__contents?(ptr)fgets((char*)reader__contents__mem, reader__contents__size, (FILE*)f__contents):f__contents;
        u64 bytes_read = ret ? strlen((char*)ret) : 0;
        char first = ((char*)reader__contents__mem)[0];
    }
    with value = nom:str(ret, bytes_read, first, reader.contents.mem:ptr)
    ---> ret:bool

smo next_chunk(File &f, Volatile &memory, str& value) -> next_chunk(memory, f, value)
smo next_line(File &f, Volatile &memory, str& value) -> next_line(memory, f, value)
smo next_chunk(File &f, Arena &memory, str& value) -> next_chunk(memory, f, value)
smo next_line(File &f, Arena &memory, str& value) -> next_line(memory, f, value)

smo ended(File &f)
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
    if status:bool @fail{printf("Failed to remove file - makre sure that it's not open: %.*s\n", (int)path__length, (char*)path__contents);}
    ----

smo create_file(String _path)
    path = _path:str
    @head{#include <stdio.h>}
    @head{
        #if defined(_WIN32) || defined(_WIN64)
            #include <direct.h>
            #define __SMOLANG_CREATE_FILE(path_cstr, out_file) fopen_s((FILE**)&(out_file), (char*)(path_cstr), "wx+")
        #else
            #define __SMOLANG_CREATE_FILE(path_cstr, out_file) (out_file) = fopen((char*)(path_cstr), "wx+")
        #endif
    }
    @body{
        ptr contents = 0;
        __SMOLANG_CREATE_FILE(path__contents, contents);
    }
    if contents:exists:not @fail{printf("Failed to create file - make sure that it does not exist: %.*s\n", (int)path__length, (char*)path__contents);}
    ---> nom:WriteFile(contents)

smo create_dir(String _path)
    path = _path:str
    @head{#if defined(_WIN32) || defined(_WIN64)
    #include <direct.h>
    #define __SMOLANG_CREATE_DIR(path_cstr, status) (status) = _mkdir((char*)(path_cstr))
    #else
    #include <sys/stat.h>
    #include <sys/types.h>
    #define __SMOLANG_CREATE_DIR(path_cstr, status) (status) = mkdir((char*)(path_cstr), 0777)
    #endif}
    @body{
        int status = -1;
        __SMOLANG_CREATE_DIR(path__contents, status);
        bool created = (status == 0);
    }
    if created:not @fail{printf("Failed to create directory. It may already exist (add an is_dir check) or operation unsupported.\n");}
    ----
