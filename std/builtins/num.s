// Written in 2025 by Emmanouil Krasanakis (maniospas@hotmail.com)
//
// To the extent possible under law, the author has dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide.
// 
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 

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
smo print(char message)
    @head{#include <stdio.h>}
    @body{printf("%c\n", message);}
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

smo le(u64 x, u64 y)  @body{bool z=x<=y;}   -> z
smo ge(u64 x, u64 y)  @body{bool z=x>=y;}   -> z
smo lt(u64 x, u64 y)  @body{bool z=x<y;}    -> z
smo gt(u64 x, u64 y)  @body{bool z=x>y;}    -> z
smo leq(u64 x, u64 y) @body{bool z=x<=y;}   -> z
smo geq(u64 x, u64 y) @body{bool z=x>=y;}   -> z
smo eq(u64 x, u64 y)  @body{bool z=(x==y);} -> z
smo neq(u64 x, u64 y) @body{bool z=(x!=y);} -> z

smo eq(bool x, bool y)  @body{bool z=(x==y);} -> z
smo neq(bool x, bool y) @body{bool z=(x!=y);} -> z
smo not(bool x)         @body{bool z=(!x);} -> z
smo and(bool x, bool y) @body{bool z=x&&y;} -> z
smo or(bool x, bool y)  @body{bool z=x||y;} -> z

smo exists(ptr x)     @body{bool z=(x);}    -> z

smo add(u64 x, u64 y) @body{u64 z=x+y;}     -> z
smo mul(u64 x, u64 y) @body{u64 z=x*y;}     -> z
smo div(u64 x, u64 y)
    if y==0:u64 @fail{printf("Division by zero\n");} --
    @head{#include <stdio.h>}
    @body{u64 z=x/y;}
    -> z
smo sub(u64 x, u64 y)
    if y>x  @fail{printf("Unsigned substraction yielded a negative\n");} --
     @body{u64 z=x-y;}
     -> z

smo add(i64 x, i64 y) @body{i64 z=x+y;} -> z
smo mod(i64 x, i64 y) @body{i64 z=x%y;} -> z
smo sub(i64 x, i64 y) @body{i64 z=x-y;} -> z
smo negative(i64 x) -> sub(0, x)
smo mul(i64 x, i64 y) @body{i64 z=x*y;} -> z
smo div(i64 x, i64 y)
    if y==0 @fail{printf("Division by zero\n");} --
    @head{#include <stdio.h>}
    @body{i64 z=x/y;}
    -> z

smo add(f64 x, f64 y) @body{f64 z=x+y;} -> z
smo sub(f64 x, f64 y) @body{f64 z=x-y;} -> z
smo mul(f64 x, f64 y) @body{f64 z=x*y;} -> z
smo negative(f64 x) -> sub(0.0, x)
smo div(f64 x, f64 y)
    if y==0.0 @fail{printf("Division by zero\n");}--
    @head{#include <stdio.h>}
    @body{f64 z=x/y;}
    -> z

smo read(i64)
    @head{#include <stdio.h>}
    @body{
        i64 number = 0;
        char ch = 0;
        i64 result = scanf("%ld%c", &number, &ch);
        bool success = (result == 2 && ch == '\n');
    }
    if success:not @fail{printf("Invalid integer\n");} --
    -> number


smo read(f64)
    @head{#include <stdio.h>}
    @body{
        f64 number = 0;
        char ch = 0;
        i64 result = scanf("%lf%c", &number, &ch);
        bool success = (result == 2 && ch == '\n');
    }
    if success:not @fail{printf("Invalid number\n");} --
    -> number

