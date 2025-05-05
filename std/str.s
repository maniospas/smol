smo string(ptr contents, u64 length, char first) -> @new
smo tostring(str raw)
    @head{#include <string.h>}
    @body{u64 length=strlen(raw);}
    @body{ptr contents=(void*)raw;}
    @body{char first=raw[0];}
    -> string(contents, length, first)

smo print(str message)
    @head{#include <stdio.h>}
    @body{printf("%s\n", message);}
    --

smo print(string message)
    @head{#include <stdio.h>}
    @body{printf("%s\n", (char*)message__contents);}
    --

smo eq(char x, char y)  @body{bool z=(x==y);} -> z
smo neq(char x, char y) @body{bool z=(x!=y);} -> z
smo eq(string x, string y) @body{bool z=(x__length==y__length)&&(x__first==y__first)&&(strcmp((char*)x__contents,(char*)y__contents)==0);} -> z
smo neq(string x, string y) @body{bool z=(x__length!=y__length)||(x__first!=y__first)||strcmp((char*)x__contents,(char*)y__contents);} -> z


smo len(string x) -> x.length

smo len(str x)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{u64 z = strlen(x);}
    -> z

smo add(string x, string y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = y__length;
        ptr contents = malloc(len_x + len_y + 1);
        if(contents){strcpy((char*)contents, (const char*)x__contents);strcat((char*)contents, (const char*)y__contents);char first=((char*)contents)[0];}
    }
    @finally{free(contents);}
    -> string(contents, add(x.length, y.length), first)

smo add(string x, str y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = strlen(y);
        ptr contents = malloc(len_x + len_y + 1);
        if(contents){strcpy((char*)contents, (const char*)x__contents);strcat((char*)contents, (const char*)y);char first=((char*)contents)[0];}
    }
    @finally{if(contents)free(contents);}
    -> string(contents, add(x.length, len_y), first)


smo add(str x, string y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = strlen(x);
        u64 len_y = y__length;
        ptr contents = malloc(len_x + len_y + 1);
        if(contents){strcpy((char*)contents, (const char*)x);strcat((char*)contents, (const char*)y__contents);char first=((char*)contents)[0];}
    }
    if(contents|exists()|not())
        @fail{printf("Failed to allocate string\n");}
        --
    @finally{if(contents)free(contents);}
    -> string(contents, add(len_x, y.length), first)

smo read(tostring)
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
        @fail{printf("Failed to read string of up to 1023 characters\n");}
        --
    -> string(contents, length, first)
