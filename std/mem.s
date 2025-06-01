@include std.builtins.num

smo stack(nom) -> @new
smo heap(nom) -> @new

smo allocate(stack, u64 size) 
    @body{ptr mem=alloca(size);}
    if mem:bool:not @fail{printf("Failed to allocate stack memory\n");} --
    -> mem

smo allocate(heap, u64 size)
    @body{ptr mem=malloc(size);}
    if mem:bool:not @fail{printf("Failed to allocate heap memory\n");} --
    @finally mem {if(mem)free(mem);mem=0;}
    -> mem

union Memory (stack, heap)