smo ok(errcode error)
    @body{bool isuser = (error==__USER__ERROR);}
    @body{bool isbuffer = (error==__BUFFER__ERROR);}
    if(isuser) @fail{printf("User error\n");} --
    if(isbuffer) @fail{printf("Buffer error\n");} --
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