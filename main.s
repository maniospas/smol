smo print(i64 x)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", x);}
    => true

smo add(i64 x, i64 y) @body{i64 z=x+y;} => z
smo sub(i64 x, i64 y) @body{i64 z=x-y;} => z
smo mul(i64 x, i64 y) @body{i64 z=x*y;} => z
smo div(i64 x, i64 y) @body{i64 z=x/y;} => z

smo Point(@type, i64 x, i64 y) => @new
smo Field(@type, Point start, Point end) => @new

smo main()
    Point p1(@type, 1,2)
    Point p2(@type, 3,4)
    Field f(true, 1, p1, true,2)
    print(f.start.x)
    print(f.end.y)
    add i(f.start.x, f.start.y)
    print(i)
