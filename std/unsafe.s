@include std.builtins.num

smo malloc(u64 size)
    @body{ptr prev=mem;ptr mem=0;}
    if prev:bool @fail{printf("Trying to allocate already allocated memory\n");} --
    @body{ptr mem=malloc(size);}
    if mem:bool:not @fail{printf("Failed to allocate memory\n");} --
    @finally mem {if(mem)free(mem);mem=0;}
    -> mem