@include std.core
@unsafe

smo test()
    x = 1
    y = 2
    print(x)
    @head{#include <cstdio>}
    @finally x {printf("Closing x=1\n");}
    @finally y {printf("Closing y=2\n");}
    -> y

service main()
    y = test()
    print(y)
    print("Still in main")
    --