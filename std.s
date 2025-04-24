smo print(f64 message)
    @head{#include <stdio.h>}
    @body{printf("%.6f\n", message);}
    => true
smo print(i64 message)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", message);}
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
