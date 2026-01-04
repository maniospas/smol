@include std.core
@unsafe

def test()
    x = 1
    y = 2
    print(x)
    @c_head{#include <cstdio>}
    @c_finally x {printf("Closing x=1\n");}
    @c_finally y {printf("Closing y=2\n");}
    return y

service main()
    y = test()
    print(y)
    print("Still in main")
    