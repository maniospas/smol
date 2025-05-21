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


smo file(str path) 
    // opens a file, creating an error if that fails
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{ptr contents = (ptr)fopen((char*)path__contents, "r");}
    @body{ptr reader = (ptr)malloc(256);}
    if reader:exists:not @fail{printf("Unable to allocate buffer for file read\n");} --
    if contents:exists:not @fail{printf("Unable to open file: %s\n", (char*)path__contents);} --
    @finally{if(contents)fclose((FILE*)contents);contents=0;if(reader)free(reader);reader=0;}
    -> align, contents, reader

smo file(cstr path) -> file(path:str)

smo chunk(file f)
    // reads from the file until either a new line is encountered, 
    // 256 characters have been read, or the file ends
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr fp = (FILE*)f__contents;
        ptr res = fgets((char*)f__reader, 256, (FILE*)fp);
        ptr contents = NULL;
        u64 length = 0;
        if((char*)res) {
            length = strlen((char*)f__reader);
            contents = malloc(length + 1);
            if (contents) {
                memcpy(contents, (char*)f__reader, length);
                ((char*)contents)[length] = '\0';
            }
        }
        char first = ((char*)contents)[0];
    }
    if(contents:exists:not) @fail{printf("Failed to read next line\n");} --
    -> str(contents, length, first)

smo ended(file f)
    // checks that the file has been closed
    @head{#include <stdio.h>}
    @body{
        char c = fgetc((FILE*)f__contents);
        bool has_ended = (c == EOF);
        if(!has_ended) ungetc(c, (FILE*)f__contents); 
    }
    -> has_ended