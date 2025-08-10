@include std.builtins
@include std.mem
@unsafe
@about "Standard library wrapping of C system calls and of process management using C popen."
@about Process     "A running process whose stdout can be read as a file-like object."
@about open        "Opens a Process given a command string. This starts the process and lets you read its output."
@about to_end      "Reads all remaining output from the process without returning it, moving to EOF."
@about to_start    "Closes and restarts the process with the same command."
@about close       "Closes the process, terminating the pipe and freeing resources."
@about next_chunk  "Reads the next chunk of process output into a provided buffer."
@about next_line   "Reads the next line of process output into a provided buffer."

smo Process(nom, ptr contents, cstr command)
    @noborrow
    -> @new

smo open(Process&, cstr command)
    @head{
        #include <stdio.h>
        #include <string.h>
        #include <stdlib.h>
        #if defined(_WIN32) || defined(_WIN64)
        #define popen  _popen
        #define pclose _pclose
        #endif
    }
    @body{ptr contents = (ptr)popen((char*)command, "r");}
    if contents:exists:not @fail{printf("Failed to start process");} --
    @finally contents { if(contents) pclose((FILE*)contents); contents = 0; }
    -> nom:Process(contents, command)

smo to_end(Process &p)
    // pclose defined by Process anyway
    @body{
        if(p__contents) {
            char buf[1024];
            while(fread(buf, 1, sizeof(buf), (FILE*)p__contents) > 0) {}
            u64 status = pclose((FILE*)p__contents);
            p__contents = 0;
        }
    }
    if status!=0 -> fail("Process exited with non-zero status")
    --

smo close(Process &p)
    // pclose defined by Process anyway
    @body{
        if(p__contents) u64 status = pclose((FILE*)p__contents);
        p__contents = 0;
    }
    if status!=0 -> fail("Process exited with non-zero status")
    --

smo next_chunk(Volatile &memory, Process &p, str& value)
    contents = memory.contents.mem
    size = memory.contents.size
    @head{#include <stdio.h> #include <string.h> #include <stdlib.h>}
    @body{
        u64 bytes_read = p__contents ? fread((char*)contents, 1, size, (FILE*)p__contents) : 0;
        if(size) ((char*)contents)[ (bytes_read < size) ? bytes_read : (size - 1) ] = '\0';
        ptr ret = bytes_read ? (ptr)contents : 0;
        char first = ((char*)contents)[0];
    }
    with value = nom:str(ret, bytes_read, first, memory.contents.underlying)
    ---> ret:bool

smo next_line(Volatile &memory, Process &p, str& value)
    contents = memory.contents.mem
    size = memory.contents.size
    @head{#include <stdio.h> #include <string.h> #include <stdlib.h>}
    @body{
        ptr ret = p__contents ? (ptr)fgets((char*)contents, size, (FILE*)p__contents) : 0;
        u64 bytes_read = ret ? strlen((char*)ret) : 0;
        char first = ((char*)contents)[0];
    }
    with value = nom:str(ret, bytes_read, first, memory.contents.underlying)
    ---> ret:bool

smo next_chunk(Arena &reader, Process &p, str& value)
    @head{#include <stdio.h> #include <string.h> #include <stdlib.h>}
    @body{
        u64 bytes_read = p__contents ? fread((char*)reader__contents__mem, 1, reader__contents__size, (FILE*)p__contents) : 0;
        if(reader__contents__size) ((char*)reader__contents__mem)[ (bytes_read < reader__contents__size) ? bytes_read : (reader__contents__size - 1) ] = '\0';
        ptr ret = bytes_read ? (ptr)reader__contents__mem : 0;
        char first = ((char*)reader__contents__mem)[0];
    }
    value = nom:str(ret, bytes_read, first, reader.contents.mem:ptr)
    -> ret:bool

smo next_line(Arena &reader, Process &p, str& value)
    with p.contents:exists --
    @head{#include <stdio.h> #include <string.h> #include <stdlib.h>}
    @body{
        ptr ret = p__contents ? (ptr)fgets((char*)reader__contents__mem, reader__contents__size, (FILE*)p__contents) : 0;
        u64 bytes_read = ret ? strlen((char*)ret) : 0;
        char first = ((char*)reader__contents__mem)[0];
    }
    with value = nom:str(ret, bytes_read, first, reader.contents.mem:ptr)
    ---> ret:bool

smo next_chunk(Process &p, Volatile &memory, str& value) -> next_chunk(memory, p, value)
smo next_line(Process &p, Volatile &memory, str& value) -> next_line(memory, p, value)
smo next_chunk(Process &p, Arena &memory, str& value) -> next_chunk(memory, p, value)
smo next_line(Process &p, Arena &memory, str& value) -> next_line(memory, p, value)

smo system(cstr command)
    @head{#include <stdlib.h>}
    @body{u64 result = system((char*)command);}
    if result!=0 -> fail("System call failed")
    --

smo system(str command) 
    system(Stack:copy(command).memory:cstr)
    --
