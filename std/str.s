smo string(str raw)
    @head{#include <string.h>}
    @body{u64 length=strlen(raw);}
    @body{ptr contents=(void*)raw;}
    -> contents, length

smo print(str message)
    @head{#include <stdio.h>}
    @body{printf("%s\n", message);}
    --

smo print(string message)
    @head{#include <stdio.h>}
    @body{printf("%s\n", (char*)message__contents);}
    --

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
        ptr z = malloc(len_x + len_y + 1);
        if(z){strcpy((char*)z, (const char*)x__contents);strcat((char*)z, (const char*)y__contents);}
        ptr contents = (void*)z;
    }
    @finally{free(contents);}
    length = add(x.length, y.length)
    -> contents, length

smo add(string x, str y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = x__length;
        u64 len_y = strlen(y);
        ptr z = malloc(len_x + len_y + 1);
        if(z){strcpy((char*)z, (const char*)x__contents);strcat((char*)z, (const char*)y);}
        ptr contents = (void*)z;
    }
    @finally{free(contents);}
    length = add(x.length, len_y)
    -> contents, length


smo add(str x, string y)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 len_x = strlen(x);
        u64 len_y = y__length;
        ptr z = malloc(len_x + len_y + 1);
        if(z){strcpy((char*)z, (const char*)x);strcat((char*)z, (const char*)y__contents);}
        ptr contents = (void*)z;
    }
    if(contents|exists()|not())
        @fail{printf("Failed to allocate string\n");}
        --
    @finally{if(contents)free(contents);}
    length = add(len_x, y.length)
    -> contents, length

smo read(string)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr contents = malloc(1024);
        if(contents && fgets((char*)contents, 1024, stdin)) {
            u64 length = strlen((char*)contents);
            if(length > 0 && ((char*)contents)[length - 1] == '\n') ((char*)contents)[length - 1] = '\0';
        }
    }
    @finally{if(contents)free(contents);}
    if(contents|exists()|not())
        @fail{printf("Failed to read string of up to 1023 characters\n");}
        --
    -> contents, length
