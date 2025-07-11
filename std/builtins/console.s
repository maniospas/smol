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
@unsafe
@about "Standard library wrapping and simplification of C console commands."

smo read(i64)
    @head{#include <stdio.h>}
    @body{
        i64 number = 0;
        char ch = 0;
        i64 result = scanf("%ld%c", &number, &ch);
        bool success = (result == 2 && ch == '\n');
    }
    if success:not @fail{printf("Error: invalid integer read\n");} --
    -> number

smo read(u64)
    @head{#include <stdio.h>}
    @body{
        u64 number = 0;
        char ch = 0;
        bool success = false;
        char first = getchar();
        if (first != '-' && first != EOF) {
            ungetc(first, stdin);
            i64 result = scanf("%lu%c", &number, &ch);
            success = (result == 2 && ch == '\n');
        }
    }
    if success:not @fail{printf("Error: invalid unsigned integer read\n");} --
    -> number

smo read(f64)
    @head{#include <stdio.h>}
    @body{
        f64 number = 0;
        char ch = 0;
        i64 result = scanf("%lf%c", &number, &ch);
        bool success = (result == 2 && ch == '\n');
    }
    if success:not @fail{printf("Error: invalid number read\n");} --
    -> number

smo read(str)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr _contents = malloc(1024);
        if(_contents && fgets((char*)_contents, 1024, stdin)) {
            u64 length = strlen((char*)_contents);
            if(length > 0 && ((char*)_contents)[length - 1] == '\n') {
                length -= 1;
                ((char*)_contents)[length] = '\0';
                char first = ((char*)_contents)[0];
            }
        }
        else if(_contents) {free(_contents);_contents=0;}
    }
    @finally _contents {if(_contents)free(_contents);_contents=0;}
    if(_contents:exists:not) @fail{printf("Failed to read str of up to 1023 characters\n");} --
    -> nom:str(_contents, length, first, _contents)