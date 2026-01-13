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

@about 
"Standard library wrapping of C basic arithmetics and printing."

@about print
"Prints a primitive number, character, or boolean to the console."

@about printin
"Prints a primitive number, character, or boolean to the console without "
"changing line."

@about le
"Checks if the first number is less than or equal to the second and overloads "
"the corresponding operator. Only the same number types can be compared, and "
"explicit casts are required otherwise. Example demonstrating the need to use "
"an f64 zero (0.0 and not 0) to compare with another read value of the same type: "
"<pre>x = f64.read()"
"\nif x<0.0"
"\n    return print(\"negative\")"
"\nelse"
"\n    return print(\"non-negative\")</pre>"

@about ge      "Checks if the first number is greater than or equal to the "
"second and overloads the corresponding operator. Only the same number types "
"can be compared, and explicit casts are required otherwise. Example demonstrating "
"the need to use an f64 zero (0.0 and not 0) to compare with another read value of "
"the same type: "
"<pre>x = f64.read()"
"\nif x>0.0"
"\n    return print(\"positive\")"
"\nelse"
"\n    return print(\"non-positive\")</pre>"

@about lt
"Checks if the first number is less than the second and overloads the "
"corresponding operator. Example: <pre>print(1>=2)</pre>"

@about gt
"Checks if the first number is greater than the second and overloads the "
"corresponding operator. Example:<pre>print(1>=2)</pre>"

@about leq
"Checks if the first number is less than or equal to the second."

@about geq
"Checks if the first number is greater than or equal to the second."

@about eq
"Checks if two primitives are equal and overloads the corresponding operator. "
"Equality can be checked for all primitives, and is also defined for other types "
"in the standard library, such as strings. Example: <pre>print(1==2)</pre>"

@about neq
"Checks if two primitives are not equal and overloads the corresponding operator. "
"Non-equality can be checked for all primitives, and is also defined for other "
"types in the standard library, such as strings. Example:<pre>print(1!=2)</pre>"

@about not
"Negation of a boolean. There is no equivalent operator, currying notation "
"should be used for manipulating single values. Here is a simple example, though "
"this is often used in conditional statements. <pre>print(true.not())</pre>"

@about exists
"Checks if a pointer is non-null. Pointer access and manipulation is inherently "
"unsafe and you should not encounter that in normal code writing. For those aiming "
"to extend the standard library or who dabble with inherently unsafe use cases, "
"this can be used to check for memory allocation failures and trigger a service "
"failure to safely collapse the current execution state."

@about add
"Addition of two numbers of the same type and overloads the corresponding operator. "
"Example: <pre>print(1+2)</pre>"

@about sub
"Subtraction of two numbers of the same type: Doing so for u64 will create a service "
"failure if the result would be negative. Overloads the corresponding operator for "
"numbers. Example that FAILS because the default integer type is u64. "
"Example: <pre>print(1-2)</pre>"

@about mul
"Multiplication of two numbers of the same type and overloads the corresponding operator. "
"Example: <pre>print(3*2)</pre>"

@about div
"Division of two numbers of the same type: Division by zero for i64 or u64 creates a "
"service failure, but for f64 it yields NaN. Overloads the corresponding operator. "
"Here is an example that yields zero by performing integer division. <pre>print(1/2)</pre>"

@about mod
"Modulo operation for signed or unsigned integers. For i64, only positive divisors are "
"allowed. Fails on zero divisor. Overloads the corresponding operator. "
"Example: <pre>print(1%2)</pre>"

@about lshift
"Performs a left shift on a signed or unsigned integer given an unsigned number of shifted "
"bits. Example: <pre>print(1.lshift(2))</pre>"

@about rshift
"Performs a right shift on a signed or unsigned integer given an unsigned number of shifted "
"bits. Example: <pre>print(8.rshift(2))</pre>"

@about negative 
"Returns the additive inverse (negation) of an i64 or f64. Does NOT overload any operation. "
"Having u64 as the default type helps avoid many spurious negation errors, especially when "
"memory handling is concerned.<br><br>Both examples below print -1. Example: "
"<pre>print(0.i64()-1.i64())"
"\nprint(1.i64)_.negative())</pre>"

@about Number
"One of u64, f64, i64"

@c_primitive u64 {unsigned long long}
@c_primitive i64 {long long}
@c_primitive f64 {double}
@c_primitive bool {int}
@c_primitive char {char}
@c_primitive ptr {void*}
@c_primitive tag {unsigned long long}
@c_primitive errcode {unsigned long long}

union Number = u64 or f64 or i64
def ok()

def i64(u64 x)
    @c_body{i64 z=x;}
    return z

def f64(u64 x)
    @c_body{f64 z=x;}
    return z

def f64(i64 x)
    @c_body{i64 z=x;}
    return z

def u64(i64 x)
    @c_body{u64 z=x;}
    return z

def print(@access f64 message)
    @c_head{#include <stdio.h>}
    @c_body{printf("%.6f\n", message);}
    
def print(@access i64 message)
    @c_head{#include <stdio.h>}
    @c_body{printf("%lld\n", (long long)message);}
    
def print(@access u64 message)
    @c_head{#include <stdio.h>}
    @c_body{printf("%llu\n", (unsigned long long)message);}
    
def print(@access bool message)
    @c_head{#include <stdio.h>}
    @c_body{message?printf("true\n"):printf("false\n");}
    
def print(@access char message)
    @c_head{#include <stdio.h>}
    @c_body{printf("%c\n", message);}
    
def printin(@access f64 message)
    @c_head{#include <stdio.h>}
    @c_body{printf("%.6f", message);}
    
def printin(@access i64 message)
    @c_head{#include <stdio.h>}
    @c_body{printf("%ld", message);}
    
def printin(@access u64 message)
    @c_head{#include <stdio.h>}
    @c_body{printf("%lu", message);}
    
def printin(@access bool message)
    @c_head{#include <stdio.h>}
    @c_body{message?printf("true"):printf("false");}
    
def printin(@access char message)
    @c_head{#include <stdio.h>}
    @c_body{printf("%c", message);}

def print()
    @c_head{#include <stdio.h>}
    @c_body{fflush(stdout);}

def le(@access Number x, Number y)
    @c_body{bool z=x<=y;}
    return z

def ge(@access Number x, Number y)
    @c_body{bool z=x>=y;}
    return z

def lt(@access Number x, Number y)
    @c_body{bool z=x<y;}
    return z

def gt(@access Number x, Number y)
    @c_body{bool z=x>y;}
    return z

def leq(@access Number x, Number y)
    @c_body{bool z=x<=y;}
    return z

def geq(@access Number x, Number y)
    @c_body{bool z=x>=y;}
    return z

def eq(@access Number x, Number y)
    @c_body{bool z=(x==y);}
    return z

def neq(@access Number x, Number y)
    @c_body{bool z=(x!=y);}
    return z

def eq(@access ptr x, ptr y)
    @c_body{bool z=(x==y);}
    return z

def neq(@access ptr x, ptr y)
    @c_body{bool z=(x!=y);} 
    return z

def eq(@access bool x, bool y)
    @c_body{bool z=(x==y);} 
    return z

def neq(@access bool x, bool y)
    @c_body{bool z=(x!=y);} 
    return z

def not(@access bool x)
    @c_body{bool z=(!x);}
    return z

def exists(@access ptr x)
    @c_body{bool z=(x);} 
    return z

def add(@access u64 x, u64 y)
    @c_body{u64 z=x+y;} 
    return z

def mul(@access u64 x, u64 y)
    @c_body{u64 z=x*y;}
    return z
 
def div(@access u64 x, u64 y)
    @c_head{#include <stdio.h>}
    if y==0 
        fail "division by zero"
    @c_body{u64 z=x/y;}
    return z

def sub(@access u64 x, u64 y)
    @c_head{#include <stdio.h>}
    if y>x 
        fail "unsigned subtraction yielded a negative"
    @c_body{u64 z=x-y;}
    return z

def mod(@access u64 x, u64 y) 
    @c_head{#include <stdio.h>}
    if y==0 
        fail "modulo by zero\n"
    @c_body{u64 z=x%y;} 
    return z

def lshift(@access u64 x, u64 y)
    @c_body{u64 z = x<<y;}
    return z

def rshift(@access u64 x, u64 y)
    @c_body{u64 z = x>>y;}
    return z

def xor(@access u64 x, u64 y)
    @c_body{u64 z = x ^ y;}
    return z

def bits(@access f64 x)
    @c_head{#include <stdint.h>}
    @c_body{
        union { double f; uint64_t u; } v;
        v.f = x;
        u64 z = v.u;
    }
    return z
    
def lshift(@access i64 x, u64 y)
    @c_body{i64 z = x<<y;}
    return z

def rshift(@access i64 x, u64 y)
    @c_body{i64 z = x>>y;}
    return z

def add(@access i64 x, i64 y) 
    @c_body{i64 z=x+y;} 
    return z

def mod(@access i64 x, i64 y)
    @c_head{#include <stdio.h>}
    if y<=i64(0) 
        fail "modulo by non-positive"
    @c_body{i64 z=x%y;}
    return z

def sub(@access i64 x, i64 y)
    @c_body{i64 z=x-y;}
    return z

def negative(@access i64 x)
    return sub(i64(0), x)

def mul(@access i64 x, i64 y)
    @c_body{i64 z=x*y;}
    return z

def div(@access i64 x, i64 y)
    @c_head{#include <stdio.h>}
    if y==i64(0) 
        fail "division by zero"
    @c_body{i64 z=x/y;}
    return z

def add(@access f64 x, f64 y) 
    @c_body{f64 z=x+y;} 
    return z

def sub(@access f64 x, f64 y)
    @c_body{f64 z=x-y;} 
    return z

def mul(@access f64 x, f64 y)
    @c_body{f64 z=x*y;} 
    return z

def negative(@access f64 x) 
    return sub(0.0, x)

def div(@access f64 x, f64 y) 
    @c_body{f64 z=x/y;} 
    return z

def eq(@access tag x, tag y)
    @c_body{bool z=(x==y);}
    return z

def neq(@access tag x, tag y)
    @c_body{bool z=(x!=y);}
    return z
