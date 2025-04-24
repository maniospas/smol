smo print(f64 message) @head{#include <stdio.h>} @body{printf("%.6f\n", message);} => true
smo print(i64 message) @head{#include <stdio.h>} @body{printf("%ld\n", message);} => true
smo print(bool message) @head{#include <stdio.h>} @body{message?printf("true\n"):printf("false\n");} => true
smo if(bool condition) @body{if(!condition)goto __scope__finally;} => @scope

smo le(i64 x, i64 y) @body{bool z=x<y;} => z
smo ge(i64 x, i64 y) @body{bool z=x>y;} => z
smo leq(i64 x, i64 y) @body{bool z=x<=y;} => z
smo geq(i64 x, i64 y) @body{bool z=x>=y;} => z
smo eq(i64 x, i64 y) @body{bool z=(x==y);} => z
smo neq(i64 x, i64 y) @body{bool z=(x!=y);} => z

smo le(f64 x, f64 y) @body{bool z=x<y;} => z
smo ge(f64 x, f64 y) @body{bool z=x>y;} => z
smo leq(f64 x, f64 y) @body{bool z=x<=y;} => z
smo geq(f64 x, f64 y) @body{bool z=x>=y;} => z
smo eq(f64 x, f64 y) @body{bool z=(x==y);} => z
smo neq(f64 x, f64 y) @body{bool z=(x!=y);} => z
smo neq(i64 x, f64 y) @body{bool z=(x!=y);} => z

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

smo add(f64 x, f64 y) @body{f64 z=x+y;} => z
smo sub(f64 x, f64 y) @body{f64 z=x-y;} => z
smo mul(f64 x, f64 y) @body{f64 z=x*y;} => z
smo div(f64 x, f64 y)
    @head{#include <stdio.h>}
    f64 zero(0)
    eq comp(y, zero)
    if(comp)
        @fail{printf("Division by zero\n");}
        => true
    @body{f64 z=x/y;}
    => z
