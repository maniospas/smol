smo str(ptr contents, u64 length, char first) -> @new
smo from(str, cstr raw)
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
        ptr contents = malloc(len_x + len_y + 1);
        if(contents){strcpy((char*)contents, (const char*)x__contents);strcat((char*)contents, (const char*)y__contents);char first=((char*)contents)[0];}
    }
    @finally{free(contents);}
    -> str(contents, add(x.length, y.length), first)

smo add(str x, cstr y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = strlen(y);
        ptr contents = malloc(len_x + len_y + 1);
        if(contents){strcpy((char*)contents, (const char*)x__contents);strcat((char*)contents, (const char*)y);char first=((char*)contents)[0];}
    }
    @finally{if(contents)free(contents);}
    -> str(contents, add(x.length, len_y), first)


smo add(cstr x, str y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = strlen(x);
        u64 len_y = y__length;
        ptr contents = malloc(len_x + len_y + 1);
        if(contents){strcpy((char*)contents, (const char*)x);strcat((char*)contents, (const char*)y__contents);char first=((char*)contents)[0];}
    }
    if(contents|exists()|not())
        @fail{printf("Failed to allocate str\n");}
        --
    @finally{if(contents)free(contents);}
    -> str(contents, add(len_x, y.length), first)

smo read(str)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr contents = malloc(1024);
        if(contents && fgets((char*)contents, 1024, stdin)) {
            u64 length = strlen((char*)contents);
            if(length > 0 && ((char*)contents)[length - 1] == '\n') {
                length -= 1;
                ((char*)contents)[length] = '\0';
                char first = ((char*)contents)[0];
            }
        }
    }
    @finally{if(contents)free(contents);}
    if(contents|exists()|not())
        @fail{printf("Failed to read str of up to 1023 characters\n");}
        --
    -> str(contents, length, first)
