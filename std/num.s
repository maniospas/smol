// this file is realased under CC0 license

smo print(f64 message)
    @head{#include <stdio.h>}
    @body{printf("%.6f\n", message);}
    --
smo print(i64 message)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", message);}
    --
smo print(u64 message)
    @head{#include <stdio.h>}
    @body{printf("%lu\n", message);}
    --
smo print(bool message)
    @head{#include <stdio.h>}
    @body{message?printf("true\n"):printf("false\n");}
    --

smo le(i64 x, i64 y)  @body{bool z=x<=y;}   -> z
smo ge(i64 x, i64 y)  @body{bool z=x>=y;}   -> z
smo lt(i64 x, i64 y)  @body{bool z=x<y;}    -> z
smo gt(i64 x, i64 y)  @body{bool z=x>y;}    -> z
smo leq(i64 x, i64 y) @body{bool z=x<=y;}   -> z
smo geq(i64 x, i64 y) @body{bool z=x>=y;}   -> z
smo eq(i64 x, i64 y)  @body{bool z=(x==y);} -> z
smo neq(i64 x, i64 y) @body{bool z=(x!=y);} -> z

smo lt(f64 x, f64 y)  @body{bool z=x<y;}    -> z
smo gt(f64 x, f64 y)  @body{bool z=x>y;}    -> z
smo le(f64 x, f64 y)  @body{bool z=x<=y;}   -> z
smo ge(f64 x, f64 y)  @body{bool z=x>=y;}   -> z
smo leq(f64 x, f64 y) @body{bool z=x<=y;}   -> z
smo geq(f64 x, f64 y) @body{bool z=x>=y;}   -> z
smo eq(f64 x, f64 y)  @body{bool z=(x==y);} -> z
smo neq(f64 x, f64 y) @body{bool z=(x!=y);} -> z

smo eq(bool x, bool y)  @body{bool z=(x==y);} -> z
smo neq(bool x, bool y) @body{bool z=(x!=y);} -> z
smo not(bool x)         @body{bool z=(!x);} -> z

smo add(u64 x, u64 y) @body{u64 z=x+y;}     -> z
smo eq(u64 x, u64 y)  @body{bool z=(x==y);} -> z
smo exists(ptr x)     @body{bool z=(x);}    -> z

smo add(i64 x, i64 y) @body{i64 z=x+y;} -> z
smo mod(i64 x, i64 y) @body{i64 z=x%y;} -> z
smo sub(i64 x, i64 y) @body{i64 z=x-y;} -> z
smo mul(i64 x, i64 y) @body{i64 z=x*y;} -> z
smo div(i64 x, i64 y)
    @head{#include <stdio.h>}
    if(eq(y, 0))
        @fail{printf("Division by zero\n");}
        --
    @body{i64 z=x/y;}
    -> z

smo add(f64 x, f64 y) @body{f64 z=x+y;} -> z
smo sub(f64 x, f64 y) @body{f64 z=x-y;} -> z
smo mul(f64 x, f64 y) @body{f64 z=x*y;} -> z
smo div(f64 x, f64 y)
    @head{#include <stdio.h>}
    if(eq(y, 0.0))
        @fail{printf("Division by zero\n");}
        --
    @body{f64 z=x/y;}
    -> z

smo read(i64)
    @head{#include <stdio.h>}
    @body{i64 number = 0; bool success = scanf("%ld", &number);}
    if(success:eq(false))
        @fail{printf("Invalid integer\n");}
        --
    -> number

smo read(f64)
    @head{#include <stdio.h>}
    @body{f64 number = 0; bool success = scanf("%lf", &number);}
    if(success:eq(false))
        @fail{printf("Invalid number\n");}
        --
    -> number

