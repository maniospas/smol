// this file is realased under CC0 license
@include std.num

smo str(ptr contents, u64 length, char first) -> @new
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
    if(contents:exists:not)
        @fail{printf("Failed to allocate str from number\n");}
        --
    @finally{if(contents)free(contents);}
    @finally{if(readbuf)free(readbuf);}
    -> str(contents, length, first)


smo str(f64 number)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <string.h>}
    @body{
        ptr readbuf = (ptr)malloc(32);
        if(readbuf) {
            u64 length = (u64)snprintf((char*)readbuf, sizeof(char)*32, "%f.6", number);
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
    if(contents:exists:not)
        @fail{printf("Failed to allocate str from number\n");}
        --
    @finally{if(contents)free(contents);}
    @finally{if(readbuf)free(readbuf);}
    -> str(contents, length, first)


smo str(cstr raw)
    @head{#include <string.h>}
    @body{u64 length=strlen(raw);}
    @body{ptr contents=(void*)raw;}
    @body{char first=raw[0];}
    -> str(contents, length, first)

smo print(cstr message)
    @head{#include <stdio.h>}
    @body{printf("%s\n", message);}
    --

smo print(str message)
    @head{#include <stdio.h>}
    @body{printf("%s\n", (char*)message__contents);}
    --

smo eq(char x, char y)  @body{bool z=(x==y);} -> z
smo neq(char x, char y) @body{bool z=(x!=y);} -> z
smo eq(str x, str y) @body{bool z=(x__length==y__length)&&(x__first==y__first)&&(strcmp((char*)x__contents,(char*)y__contents)==0);} -> z
smo neq(str x, str y) @body{bool z=(x__length!=y__length)||(x__first!=y__first)||strcmp((char*)x__contents,(char*)y__contents);} -> z
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
        ptr dealloc = _contents;
        ptr _contents = malloc(len_x + len_y + 1);
        if(_contents){strcpy((char*)_contents, (const char*)x__contents);strcat((char*)_contents, (const char*)y__contents);}
        if(dealloc) free(dealloc);
    }
    @finally _contents {if(_contents)free(_contents);}
    -> str(_contents, add(x.length, y.length), x.first)

smo add(str x, cstr y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = strlen(y);
        ptr dealloc = _contents;
        ptr _contents = malloc(len_x + len_y + 1);
        if(_contents){strcpy((char*)_contents, (const char*)x__contents);strcat((char*)_contents, (const char*)y);}
        if(dealloc) free(dealloc);
    }
    @finally _contents {if(_contents)free(_contents);}
    -> str(_contents, add(x.length, len_y), x.first)


smo add(cstr x, str y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = strlen(x);
        u64 len_y = y__length;
        ptr dealloc = _contents;
        ptr _contents = malloc(len_x + len_y + 1);
        if(_contents){strcpy((char*)_contents, (const char*)x);strcat((char*)_contents, (const char*)y__contents);char first=((char*)_contents)[0];}
        if(dealloc) free(dealloc);
    }
    if(_contents:exists:not())
        @fail{printf("Failed to allocate str\n");}
        --
    @finally _contents {if(_contents)free(_contents);}
    -> str(_contents, add(len_x, y.length), first)

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
    if(_contents:exists:not)
        @fail{printf("Failed to read str of up to 1023 characters\n");}
        --
    -> str(_contents, length, first)
