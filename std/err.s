// this file is realased under CC0 license

smo ok(errcode error)
    @body{bool isuser = (error==__USER__ERROR);}
    @body{bool isbuffer = (error==__BUFFER__ERROR);}
    if(isuser) @fail{printf("User error\n");} --
    if(isbuffer) @fail{printf("Buffer error\n");} --
    --

smo fail(cstr error)
    @fail {printf("%s", error);printf("\n");}
    --

smo fail(str error)
    @fail {printf("%s", (char*)error__contents);printf("\n");}
    --

smo print(errcode error)
    @head{#include <stdio.h>}
    @body{
        if(error==__USER__ERROR)printf("User error\n"); 
        else if(error==__BUFFER__ERROR)printf("Buffer error\n"); 
        else if(error==__UNHANDLED__ERROR)printf("Unhandled error\n"); 
        else if(error)printf("Unknown error");
        else printf("No error");
    }
    --
