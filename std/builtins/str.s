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

smo str(align, ptr contents, u64 length, char first) -> @new
smo str(i64 number)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    @body{
        ptr readbuf = (ptr)malloc(32);
        if(readbuf) {
            u64 length = (u64)snprintf((char*)readbuf, sizeof(char)*32, "%ld", number);
            if (length < 32) {
                ptr contents = malloc(length + 1);
                if(contents) {
                    memcpy(contents, (char*)readbuf, length);
                    ((char*)contents)[length] = '\0';
                    char first = ((char*)contents)[0];
                }
            }
        }
    }
    if(contents:exists:not) @fail{printf("Failed to allocate str from number\n");} --
    @finally contents {if(contents)free(contents);}
    @finally readbuf {if(readbuf)free(readbuf);}
    -> align:str(contents, length, first)

smo str(f64 number)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    @body{
        ptr readbuf = (ptr)malloc(32);
        if(readbuf) {
            u64 length = (u64)snprintf((char*)readbuf, sizeof(char)*32, "%.6f", number);
            if (length < 32) {
                ptr contents = malloc(length + 1);
                if(contents) {
                    memcpy(contents, (char*)readbuf, length);
                    ((char*)contents)[length] = '\0';
                    char first = ((char*)contents)[0];
                }
            }
        }
    }
    if(contents:exists:not) @fail{printf("Failed to allocate str from number\n");} --
    @finally contents {if(contents)free(contents);}
    @finally readbuf {if(readbuf)free(readbuf);}
    -> align:str(contents, length, first)

smo str(cstr raw)
    @head{#include <string.h>}
    @body{u64 length=strlen(raw);}
    @body{ptr contents=(void*)raw;}
    @body{char first=raw[0];}
    -> align:str(contents, length, first)

smo print(cstr message)
    @head{#include <stdio.h>}
    @body{printf("%s\n", message);}
    --

smo print(str message)
    @head{#include <stdio.h>}
    @body{printf("%.*s\n", (int)message__length, (char*)message__contents);}
    --

smo substr(str s, u64 from, u64 to) 
    if to<from @fail{printf("Substring cannot end before it starts\n");} --
    if to>=s.length @fail{printf("Substring end must be at most at the length of the base string\n");} --
    // the above two conditions mean that from<=to<s.length
    // this means that s.length is never zero
    // therefore there is no need to check for length when computing first
    @body{
        ptr contents = (ptr)((char*)s__contents+from*sizeof(char));
        char first = from==to?'\0':((char*)s__contents)[0];
    }
    -> align:str(contents, to-from, first)
smo substr(cstr s, u64 from, u64 to) -> s:str:substr(from, to)

smo substr(str s, u64 from) 
    if from>=s.length @fail{printf("Substring beginning of base string size\n");} --
    @body{
        ptr contents = (ptr)((char*)s__contents+from*sizeof(char));
        char first = from+1==s__length?'\0':((char*)contents)[0];
    }
    -> align:str(contents, s.length-from, first)
smo substr(cstr s, u64 from) -> s:str:substr(from)

smo eq(char x, char y)  @body{bool z=(x==y);} -> z
smo neq(char x, char y) @body{bool z=(x!=y);} -> z
smo eq(str x, str y)
    @head{#include <string.h>}
    @body{bool z = (x__length != y__length) || memcmp(x__contents, y__contents, x__length) == 0;}
    -> z
smo neq(str x, str y)
    @head{#include <string.h>}
    @body{bool z = (x__length != y__length) || memcmp(x__contents, y__contents, x__length) != 0;} 
    -> z
smo len(str x) -> x.length

smo len(cstr x)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{u64 z = strlen(x);}
    -> z

smo add(str x, str y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = y__length;
        u64 total_len = len_x + len_y;
        ptr dealloc = _contents;
        ptr _contents = malloc(total_len);
        if(_contents) {
            memcpy((char*)_contents, (char*)x__contents, len_x);
            memcpy((char*)_contents + len_x, (char*)y__contents, len_y);
        }
        if(dealloc) free(dealloc);
    }
    @finally _contents {if(_contents)free(_contents);_contents=0;}
    -> align:str(_contents, len_x + len_y, x.first)

smo add(str x, cstr y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = strlen(y);
        u64 total_len = len_x + len_y;
        ptr dealloc = _contents;
        ptr _contents = malloc(total_len);
        if(_contents) {
            memcpy((char*)_contents, (char*)x__contents, len_x);
            memcpy((char*)_contents + len_x, (const char*)y, len_y);
        }
        if(dealloc) free(dealloc);
    }
    @finally _contents {if(_contents)free(_contents);_contents=0;}
    -> align:str(_contents, len_x + len_y, x.first)

smo add(cstr x, str y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = strlen(x);
        u64 len_y = y__length;
        u64 total_len = len_x + len_y;

        ptr dealloc = _contents;
        ptr _contents = malloc(total_len);
        char first = 0;
        if(_contents) {
            memcpy((char*)_contents, (const char*)x, len_x);
            memcpy((char*)_contents + len_x, (char*)y__contents, len_y);
            first = ((char*)_contents)[0];
        }
        if(dealloc) free(dealloc);
    }
    if (_contents:exists:not()) @fail{printf("Failed to allocate str\n");} --
    @finally _contents {if (_contents) free(_contents); _contents = 0;}
    -> align:str(_contents, len_x + len_y, first)

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
    }
    @finally _contents {if(_contents)free(_contents);}
    if(_contents:exists:not) @fail{printf("Failed to read str of up to 1023 characters\n");} --
    -> align:str(_contents, length, first)
