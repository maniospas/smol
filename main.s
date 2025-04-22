smo print(i64 x)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", x);}
    => true

smo add(i64 x, i64 y) @body{i64 z=x+y;} => z
smo sub(i64 x, i64 y) @body{i64 z=x-y;} => z
smo mul(i64 x, i64 y) @body{i64 z=x*y;} => z
smo div(i64 x, i64 y) @body{i64 z=x/y;} => z



smo Point(i64 x, i64 y) => (x,y)
smo Field(Point start, Point end) => @new

smo main()
    Point p1(1,2)
    Point p2(3,4)
    Field f(1, p1, 3)
    print(f.start.x)
    print(f.end.y)
    add i(f.start)
    print(i)

    buffer mem(p1)
