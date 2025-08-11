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
@about ReadFile   "An opened file that is meant to be read only."
@about WriteFile  "An opened file that is meant to be read or write."
@about File       "A union between file types that allows common reading and positioning operations."
@about open       "Opens a File given a String path, in which case you might get service failure due to external factors. Opening a WriteFile, "
                  "may also cause service failure if the file already exists - in that case remove it first. On the other hand, a ReadFile must "
                  "already exist to be opened."
@about to_start   "Go to the beginning of a File. You can continue read or writing from there. May cause service failure due to external factors."
@about to_end     "Go to the end of a WriteFile. This is not implemented for ReadFile, as it makes more sense to just close the latter. May cause service failure due to external factors."
@about len        "Computes the size of a File in bytes."
@about write      "Writes a string on a WriteFile."
@about allocate_file "Creates a virtual file by of a given size on top of some memory allocator."
@about next_chunk "Reads the next chunk of a file while using it as an iterator. It accomodates Arena and Volatile memories "
                  "and different argument orders that allow you to use either the file or the memory as context."
                  "<br><br>Here is an example where volatile memory is used to avoid repeated or large allocations:"
                  "<pre>on Heap:allocate_volatile(1024)"
                  "\n    ReadFile"
                  "\n    :open(\"README.md\")"
                  "\n    :while next_chunk(str& chunk)"
                  "\n        print(chunk)"
                  "\n    ----</pre>"
@about next_line  "Reads the next line of a file while using it as an iterator. It accomodates Arena and Volatile memories "
                  "and different argument orders that allow you to use either the file or the memory as context."
                  "<br><br>Here is an example where volatile memory is used to avoid repeated or large allocations:"
                  "<pre>endl=\"n\":str.first // optimized to just setting the new line character"
                  "\non Heap:allocate_volatile(1024)"
                  "\n    ReadFile(\"README.md\")"
                  "\n    :open(\"README.md\")"
                  "\n    :while next_line(str& line)"
                  "\n        if line[line:len-1]==endl"
                  "\n             line = line[0 to line:len-1]"
                  "\n             --"
                  "\n        print(line)"
                  "\n    ----</pre>"
@about ended      "Checks if the ending of the file has been reached. This is normal to be true for WriteFile."
@about is_file    "Checks if a String path is a file system file."
@about is_dir     "Checks if a String path is a file system directory."
@about create_dir  "Creates a directory given a String path. May cause service failure due to external factors or if the directory already exists."
@about remove_file "Deletes a file from the system. May cause service failure due to external factors or if the file is already open."

smo ReadFile(nom, ptr contents)
    @noborrow
    -> @new
smo WriteFile(nom, ptr contents)
    @noborrow
    -> @new

union File(ReadFile, WriteFile)

smo open(ReadFile&, String _path) 
    path = _path:str
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{ptr contents = fopen((char*)path__contents, "r");}
    if contents:exists:not @fail{printf("Failed to open file: %.*s\n", (int)path__length, (char*)path__contents);} --
    @finally contents {if(contents)fclose((FILE*)contents);contents=0;}
    -> nom:ReadFile(contents)

smo to_start(File &f) 
    if f.contents:exists:not @fail{printf("Failed to move to start of closed file");} --
    @body{fseek((FILE*)f__contents, 0, SEEK_SET);}
    --

smo to_end(WriteFile &f) 
    // only useful for moving to the end of write files. For read files, close them instead.
    @body{if(f__contents) fseek((FILE*)f__contents, 0, SEEK_END);}
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
    if success:not @fail{printf("Failed to write to file: %.*s\n", (int)s__length, (char*)s__contents);} --
    ----

smo allocate_file(Memory& memory, u64 size)
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    // @head{
    //     #if defined(_WIN32) || defined(_WIN64)
    //         static FILE* fmemopen(void *buf, size_t size, const char *mode) {
    //             FILE *f = tmpfile();
    //             if (!f) return NULL;
    //             //if (buf && size > 0) {fwrite(buf, 1, size, f);rewind(f);}
    //             return f;
    //         }
    //     #endif
    // }
    mem = memory:allocate(size)
    @body {ptr contents = fmemopen(mem__mem, size, "w+");}
    @finally contents {if(contents)fclose((FILE*)contents);contents=0;}
    -> nom:WriteFile(contents)
    
smo next_chunk(Volatile &memory, File &f, str& value)
    contents = memory.contents.mem
    size = memory.contents.size
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = f__contents?fread((char*)contents, 1, size, (FILE*)f__contents):0;
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
        u64 bytes_read = f__contents?fread((char*)reader__contents__mem, 1, reader__contents__size, (FILE*)f__contents):0;
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

smo open(WriteFile&, String _path)
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

smo console(WriteFile&)
    @head{#include <stdio.h>}
    @head{
        #if defined(_WIN32) || defined(_WIN64)
            #include <windows.h>
            #define SMOLAMBDA_CONSOLE(f) AllocConsole(); {HANDLE hConsole = CreateFileA("CONOUT$", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL); if (hConsole != INVALID_HANDLE_VALUE) {int fd = _open_osfhandle((intptr_t)hConsole, 0); if (fd != -1) {(f) = (ptr)_fdopen(fd, "w"); if ((f)) setvbuf((FILE*)(f), NULL, _IONBF, 0);}}}
            #define SMOLAMBDA_CONSOLE_CLOSE(f) if(f)fclose((FILE*)(f)); FreeConsole();
            #include <io.h>
        #else
            #include <stdlib.h>
            #include <unistd.h>
            #include <pty.h>
            #include <fcntl.h>
            #define SMOLAMBDA_CONSOLE(f) {int master_fd, slave_fd; char slavename[128]; if (openpty(&master_fd, &slave_fd, slavename, NULL, NULL) != -1) {const char* terms[] = {"xterm", "konsole"}; const char* found = NULL; for (int i = 0; i < 2 && !found; i++) {char cmd[64]; snprintf(cmd, sizeof(cmd), "command -v %s >/dev/null 2>&1", terms[i]); if (system(cmd) == 0) found = terms[i];} if (found) {pid_t pid = fork(); if (pid == 0) {close(master_fd); if (strcmp(found, "xterm") == 0) execlp("xterm", "xterm", "-e", slavename, NULL); else if (strcmp(found, "konsole") == 0) execlp("konsole", "konsole", "-e", "socat", "-", slavename, NULL); _exit(1);} else {close(slave_fd); f = (ptr)fdopen(master_fd, "w"); if (f) setvbuf((FILE*)(f), NULL, _IONBF, 0);}} else {close(slave_fd); f = (ptr)fdopen(master_fd, "w"); if (f) setvbuf((FILE*)(f), NULL, _IONBF, 0);}}}
            #define SMOLAMBDA_CONSOLE_CLOSE(f) if(f)pclose((FILE*)f);
        #endif
    }
    @body{
        ptr f = 0;
        SMOLAMBDA_CONSOLE(f)
    }
    @finally f { // this prevents leaking open terminals
        SMOLAMBDA_CONSOLE_CLOSE(f)
        f = 0;
    }
    -> nom:WriteFile(f)
