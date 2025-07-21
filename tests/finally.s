@include std.builtins
@unsafe

smo test()
    x = 1
    print(x)
    @head{#include <cstdio>}
    @finally x {printf("Closing\n");}
    --

service main()
    test()
    --