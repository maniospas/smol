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
@include std.mem
@unsafe
@about "Standard library wrapping of C system calls and of process management using C popen."
@about Process     "A running process whose stdout can be read as a file-like object."
@about open        "Opens a Process given a command string. This starts the process and lets you read its output."
@about to_end      "Reads all remaining output from the process without returning it, moving to EOF.  Returns a boolean indicating whether \"Error:\" is part of the output."
@about next_chunk  "Reads the next chunk of process output into a provided buffer."
@about next_line   "Reads the next line of process output into a provided buffer."

smo Process(nom, ptr contents)
    @noborrow
    -> @new

smo open(Process&, CString _command)
    command = _command:nullstr.contents
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @head{
        #if defined(_WIN32) || defined(_WIN64)
        #define popen  _popen
        #define pclose _pclose
        #endif
    }
    @body{ptr contents = (ptr)popen((cstr)command, "r");}
    if contents:exists:not @fail{printf("Error: Failed to start process\n");} --
    @finally contents { if(contents) {pclose((FILE*)contents);} contents = 0; }
    -> nom:Process(contents)

smo to_end(Process &p)
    @head{#include <string.h>}
    @body{
        if(p__contents) {
            char buf[1024];
            bool err = false;
            while(fread(buf, 1, sizeof(buf), (FILE*)p__contents)) {if(strstr(buf, "Error:")) err = true;}

        }
    }
    -> err

smo next_chunk(DerivedMemory &reader, Process &p, str& value)
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = p__contents ? fread((char*)reader__contents__mem, 1, reader__contents__size, (FILE*)p__contents) : 0;
        if(reader__contents__size) ((char*)reader__contents__mem)[ (bytes_read < reader__contents__size) ? bytes_read : (reader__contents__size - 1) ] = '\0';
        ptr ret = bytes_read ? (ptr)reader__contents__mem : 0;
        char first = ((char*)reader__contents__mem)[0];
    }
    value = nom:str(ret, bytes_read, first, reader.contents.underlying)
    -> ret:bool

smo next_line(DerivedMemory &reader, Process &p, str& value)
    with p.contents:exists --
    @head{#include <stdio.h> #include <string.h> #include <stdlib.h>}
    @body{
        ptr ret = p__contents ? (ptr)fgets((char*)reader__contents__mem, reader__contents__size, (FILE*)p__contents) : 0;
        u64 bytes_read = ret ? strlen((char*)ret) : 0;
        char first = ((char*)reader__contents__mem)[0];
    }
    with value = nom:str(ret, bytes_read, first, reader.contents.underlying)
    ---> ret:bool

smo next_chunk(Process &p, DerivedMemory &memory, str& value) 
    -> next_chunk(memory, p, value)

smo next_line(Process &p, DerivedMemory &memory, str& value) 
    -> next_line(memory, p, value)

smo system(cstr command)
    @head{#include <stdlib.h>}
    @body{u64 result = system((char*)command);}
    if result!=0 -> fail("Error: System call failed")
    --

smo system(str command) 
    system(Stack:copy(command).memory:cstr)
    --

smo open(Process&, str command)
    mem = Stack:allocate(command.length+1, char)
    @body{
        char first = 0;
        if(mem__mem) {
            memcpy((char*)mem__mem, command__contents, command__length);
            ((char*)mem__mem)[command__length] = '\0';
        }
        // we need the following line as a means of casting void* to const char*
        // but we can do this only because Process is @noborrow so that the allocated
        // stack cannot be leaked (by the way, this would finalize Heap memory, so
        // we don't do it)
        cstr mem = (const char*)mem__mem; 
    }
    -> Process:open(mem)

