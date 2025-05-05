smo ok(errcode error)
    @body{bool isuser = (error==__USER__ERROR);}
    @body{bool isbuffer = (error==__BUFFER__ERROR);}
    if(isuser) @fail{printf("User error\n");} --
    if(isbuffer) @fail{printf("Buffer error\n");} --
    --
