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

@unsafe
@about "Standard library wrapping of C basic arithmetics and printing."
@about print   "Prints a primitive number, character, or boolean to the console."
@about printin "Prints a primitive number, character, or boolean to the console without changing line."
@about le      "Checks if the first number is less than or equal to the second and overloads the corresponding operator. Only the same number types can be compared, and explicit casts are required otherwise.<br><br>Here is an example demonstrating the need to use an f64 zero (0.0 and not 0) to compare with another read value of the same type: <pre>x=f64:read\nif x<0.0 -> print(\"negative\")\nelse -> print(\"non-negative\")</pre>"
@about ge      "Checks if the first number is greater than or equal to the second and overloads the corresponding operator. Only the same number types can be compared, and explicit casts are required otherwise.<br><br>Here is an example demonstrating the need to use an f64 zero (0.0 and not 0) to compare with another read value of the same type: <pre>x=f64:read\nif x>0.0 -> print(\"positive\")\nelse -> print(\"non-positive\")</pre>"
@about lt      "Checks if the first number is less than the second and overloads the corresponding operator. <br><br>Here is an example: <pre>print(1>=2)</pre>"
@about gt      "Checks if the first number is greater than the second and overloads the corresponding operator. <br><br>Here is an example:<pre>print(1>=2)</pre>"
@about leq     "Checks if the first number is less than or equal to the second."
@about geq     "Checks if the first number is greater than or equal to the second."
@about eq      "Checks if two primitives are equal and overloads the corresponding operator. Equality can be checked for all primitives, and is defined for other runtypes too in the standard library, such as strings.<br><br>Here is an example: <pre>print(1==2)</pre>"
@about neq     "Checks if two primitives are not equal and overloads the corresponding operator. Non-equality can be checked for all primitives, and is defined for other runtypes too in the standard library, such as strings.<br><br>Here is an example:<pre>print(1!=2)</pre>"
@about not     "Negation of a boolean. In general, for unary operations, there is NO equivalent operator to overload. This promotes a currying-based notation for manipulating single values. <br><br>Here is a simple example, though this is often used in conditional statements: <pre>print(true:not)</pre>"
@about exists  "Checks if a pointer is non-null. Pointer access and manipulation is inherently unsafe and you should not encounter that in normal code writing. For those aiming to extend the standard library or who dabble with inherently unsafe use cases, this can be used to check for memory allocation failures and trigger a service failure to safely collapse the current execution state."
@about add     "Addition of two numbers of the same type and overloads the corresponding operator. <br><br>Here is an example: <pre>print(1+2)</pre>"
@about sub     "Subtraction of two numbers of the same type. Doing so for u64 will create a service failure if the result would be negative. Overloads the corresponding operator for numbers.<br><br>Here is an example that FAILS because the default integer type is u64: <pre>print(1-2)</pre>"
@about mul     "Multiplication of two numbers of the same type and overloads the corresponding operator. <br><br>Here is an example: <pre>print(3*2)</pre>"
@about div     "Division of two numbers of the same type. Division by zero for i64 or u64 creates a service failure, but for f64 it yields NaN. Overloads the corresponding operator. Here is an example that yields zero by performing integer division: <pre>print(1/2)</pre>"
@about mod     "Modulo operation for signed or unsigned integers. For i64, only positive divisors are allowed. Fails on zero divisor. Overloads the corresponding operator. Here is an example: <pre>print(1%2)</pre>"
@about negative "Returns the additive inverse (negation) of an i64 or f64. Does NOT overload any operation.  Having u64 as the default type helps avoid many spurious negation errors, especially when memory handling is concerned.<br><br>Both examples below print -1: <pre>print(0:i64-1:i64)\nprint(1:i64:negative)</pre>"


union Number (u64, f64, i64)

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
smo printin(f64 message)
    @head{#include <stdio.h>}
    @body{printf("%.6f", message);}
    --
smo printin(i64 message)
    @head{#include <stdio.h>}
    @body{printf("%ld", message);}
    --
smo printin(u64 message)
    @head{#include <stdio.h>}
    @body{printf("%lu", message);}
    --
smo printin(bool message)
    @head{#include <stdio.h>}
    @body{message?printf("true"):printf("false");}
    --
smo printin(char message)
    @head{#include <stdio.h>}
    @body{printf("%c", message);}
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
smo not(bool x)         @body{bool z=(!x);}   -> z

smo exists(ptr x) @body{bool z=(x);} -> z

smo add(u64 x, u64 y) @body{u64 z=x+y;} -> z
smo mul(u64 x, u64 y) @body{u64 z=x*y;} -> z
smo div(u64 x, u64 y)
    if y==0 @fail{printf("Error: division by zero\n");} --
    @head{#include <stdio.h>}
    @body{u64 z=x/y;}
    -> z
smo sub(u64 x, u64 y)
    if y>x  @fail{printf("Error: unsigned substraction yielded a negative\n");} --
    @body{u64 z=x-y;}
    -> z
smo mod(u64 x, u64 y) 
    if y==0 @fail{printf("Error: modulo by zero\n");} --
    @head{#include <stdio.h>}
    @body{u64 z=x%y;} -> z

smo add(i64 x, i64 y) @body{i64 z=x+y;} -> z
smo mod(i64 x, i64 y) 
    if y<=0:i64 @fail{printf("Error: modulo by non-positive\n");} --
    @head{#include <stdio.h>}
    @body{i64 z=x%y;} -> z
smo sub(i64 x, i64 y) @body{i64 z=x-y;} -> z
smo negative(i64 x) -> sub(0:i64, x)
smo mul(i64 x, i64 y) @body{i64 z=x*y;} -> z
smo div(i64 x, i64 y)
    if y==0:i64 @fail{printf("Error: division by zero\n");} --
    @head{#include <stdio.h>}
    @body{i64 z=x/y;}
    -> z

smo add(f64 x, f64 y) @body{f64 z=x+y;} -> z
smo sub(f64 x, f64 y) @body{f64 z=x-y;} -> z
smo mul(f64 x, f64 y) @body{f64 z=x*y;} -> z
smo negative(f64 x) -> sub(0.0, x)
smo div(f64 x, f64 y) @body{f64 z=x/y;} -> z

smo eq(ptr x, ptr y) @body{bool z=(x==y);} -> z
smo neq(ptr x, ptr y) @body{bool z=(x!=y);} -> z