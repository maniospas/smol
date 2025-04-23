smo print(i64 x)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", x);}
    => true
smo if(bool condition) @body{if(!condition)goto __scope__finally;} => @scope

smo le(i64 x, i64 y) @body{bool z=x<y;} => z
smo ge(i64 x, i64 y) @body{bool z=x>y;} => z
smo leq(i64 x, i64 y) @body{bool z=x<=y;} => z
smo geq(i64 x, i64 y) @body{bool z=x>=y;} => z
smo eq(i64 x, i64 y) @body{bool z=(x==y);} => z
smo neq(i64 x, i64 y) @body{bool z=(x!=y);} => z

smo add(i64 x, i64 y) @body{i64 z=x+y;} => z
smo sub(i64 x, i64 y) @body{i64 z=x-y;} => z
smo mul(i64 x, i64 y) @body{i64 z=x*y;} => z
smo div(i64 x, i64 y)
    @head{#include <stdio.h>}
    eq comp(y, 0)
    if(comp)
        @fail{printf("Division by zero\n");}
        => true
    @body{i64 z=x/y;}
    => z

smo abs(i64 x)
    le check(x, 0)
    => check

smo Point(i64 x, i64 y) => (x,y)
smo Field(Point start, Point end) => @new


smo main()
    buffer buf(1,2,3,4)
    Field f(buf)
    print(f.start.x)

    f.start.x = i64(0)
    print(f.start.x)

    Field f2(buf)
    print(f2.start.x)

    div res(1,0)
    print(res)
