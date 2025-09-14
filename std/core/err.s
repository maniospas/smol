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

@include std.core.num
@include std.core.str
@unsafe
@about "Standard library implementations of error utilities."
@about assert_ok "Checks if an error code corresponds to no error. If it does not, the service fails while printing the type of error. Error codes can be user errors, buffer errors, unknown errors, or no errors."
@about fail  "Causes the current service to fail given a String message. This creates a user error code."
@about print "Prints an interpretation of the error code. Error codes can be user errors, buffer errors, unknown errors, or no errors."

smo assert_ok(errcode error)
    @body{bool isuser = (error==__USER__ERROR);}
    @body{bool isbuffer = (error==__BUFFER__ERROR);}
    @body{bool iserror = (error==__BUFFER__ERROR);}
    @body{bool isunhandled = (error==__UNHANDLED__ERROR);}
    
    if isuser 
        @fail{printf("User error\n");} 
        --
    if isbuffer 
        @fail{printf("Buffer error\n");} 
        --
    if isunhandled 
        @fail{printf("Unhandled error\n");}
         --
    if iserror 
        @fail{printf("Unknown error\n");}
         --
    --

smo fail(cstr error)
    @head{#include <stdio.h>}
    @fail {printf("%s\n", error);}
    --

smo fail(str error)
    @head{#include <stdio.h>}
    @fail {printf("%s\n", (char*)error__contents);}
    --

smo print(errcode error)
    @head{#include <stdio.h>}
    @body{
        if(error==__USER__ERROR)
            printf("User error\n"); 
        else if(error==__BUFFER__ERROR)
            printf("Buffer error\n"); 
        else if(error==__UNHANDLED__ERROR)
            printf("Unhandled error\n"); 
        else if(error)
            printf("Unknown error\n");
        else 
            printf("No error\n");
    }
    -- 

smo assert(bool condition, cstr error)
    // prefer using this function as in the future constant evaluation of certain conditions will occur
    if condition:not fail(error)
    ----