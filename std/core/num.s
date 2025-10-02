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
@about le      "Checks if the first number is less than or equal to the second and overloads the corresponding operator. Only the same number types can be compared, and explicit casts are required otherwise. Example demonstrating the need to use an f64 zero (0.0 and not 0) to compare with another read value of the same type: <pre>x = f64.read\nif x<0.0\n    return print(\"negative\")\nelse\n    return print(\"non-negative\")</pre>"
@about ge      "Checks if the first number is greater than or equal to the second and overloads the corresponding operator. Only the same number types can be compared, and explicit casts are required otherwise. Example demonstrating the need to use an f64 zero (0.0 and not 0) to compare with another read value of the same type: <pre>x = f64.read\nif x>0.0\n    return print(\"positive\")\nelse\n    return print(\"non-positive\")</pre>"
@about lt      "Checks if the first number is less than the second and overloads the corresponding operator. Example: <pre>print(1>=2)</pre>"
@about gt      "Checks if the first number is greater than the second and overloads the corresponding operator. Example:<pre>print(1>=2)</pre>"
@about leq     "Checks if the first number is less than or equal to the second."
@about geq     "Checks if the first number is greater than or equal to the second."
@about eq      "Checks if two primitives are equal and overloads the corresponding operator. Equality can be checked for all primitives, and is defined for other runtypes too in the standard library, such as strings. Example: <pre>print(1==2)</pre>"
@about neq     "Checks if two primitives are not equal and overloads the corresponding operator. Non-equality can be checked for all primitives, and is defined for other runtypes too in the standard library, such as strings. Example:<pre>print(1!=2)</pre>"
@about not     "Negation of a boolean. There is no equivalent operator, and currying-based notation should be used for manipulating single values. Here is a simple example, though this is often used in conditional statements. <pre>print(true.not)</pre>"
@about exists  "Checks if a pointer is non-null. Pointer access and manipulation is inherently unsafe and you should not encounter that in normal code writing. For those aiming to extend the standard library or who dabble with inherently unsafe use cases, this can be used to check for memory allocation failures and trigger a service failure to safely collapse the current execution state."
@about add     "Addition of two numbers of the same type and overloads the corresponding operator. Example: <pre>print(1+2)</pre>"
@about sub     "Subtraction of two numbers of the same type: Doing so for u64 will create a service failure if the result would be negative. Overloads the corresponding operator for numbers. Example that FAILS because the default integer type is u64. <pre>print(1-2)</pre>"
@about mul     "Multiplication of two numbers of the same type and overloads the corresponding operator. Example: <pre>print(3*2)</pre>"
@about div     "Division of two numbers of the same type: Division by zero for i64 or u64 creates a service failure, but for f64 it yields NaN. Overloads the corresponding operator. Here is an example that yields zero by performing integer division. <pre>print(1/2)</pre>"
@about mod     "Modulo operation for signed or unsigned integers. For i64, only positive divisors are allowed. Fails on zero divisor. Overloads the corresponding operator. Here is an example: <pre>print(1%2)</pre>"
@about negative "Returns the additive inverse (negation) of an i64 or f64. Does NOT overload any operation.  Having u64 as the default type helps avoid many spurious negation errors, especially when memory handling is concerned.<br><br>Both examples below print -1. <pre>print(0.i64-1.i64)\nprint(1.i64.negative)</pre>"
@about Number  "One of u64, f64, i64"

union Number 
    u64
    f64
    i64
    end

def print(@access f64 message)
    @head{#include <stdio.h>}
    @body{printf("%.6f\n", message);}
    end
    
def print(@access i64 message)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", message);}
    end
    
def print(@access u64 message)
    @head{#include <stdio.h>}
    @body{printf("%lu\n", message);}
    end
    
def print(@access bool message)
    @head{#include <stdio.h>}
    @body{message?printf("true\n"):printf("false\n");}
    end
    
def print(@access char message)
    @head{#include <stdio.h>}
    @body{printf("%c\n", message);}
    end
    
def printin(@access f64 message)
    @head{#include <stdio.h>}
    @body{printf("%.6f", message);}
    end
    
def printin(@access i64 message)
    @head{#include <stdio.h>}
    @body{printf("%ld", message);}
    end
    
def printin(@access u64 message)
    @head{#include <stdio.h>}
    @body{printf("%lu", message);}
    end
    
def printin(@access bool message)
    @head{#include <stdio.h>}
    @body{message?printf("true"):printf("false");}
    end
    
def printin(@access char message)
    @head{#include <stdio.h>}
    @body{printf("%c", message);}
    end

def le(@access Number x, Number y)  
    @body{bool z=x<=y;}   
    return z

def ge(@access Number x, Number y)  
    @body{bool z=x>=y;}
    return z

def lt(@access Number x, Number y)  
    @body{bool z=x<y;}
    return z

def gt(@access Number x, Number y)
    @body{bool z=x>y;}
    return z

def leq(@access Number x, Number y)
    @body{bool z=x<=y;}
    return z

def geq(@access Number x, Number y)
    @body{bool z=x>=y;}
    return z

def eq(@access Number x, Number y)
    @body{bool z=(x==y);} 
    return z

def neq(@access Number x, Number y)
    @body{bool z=(x!=y);}
    return z

def eq(@access ptr x, ptr y)
    @body{bool z=(x==y);}
    return z

def neq(@access ptr x, ptr y)
    @body{bool z=(x!=y);} 
    return z

def eq(@access bool x, bool y)
    @body{bool z=(x==y);} 
    return z

def neq(@access bool x, bool y)
    @body{bool z=(x!=y);} 
    return z

def not(@access bool x)
    @body{bool z=(!x);}
    return z

def exists(@access ptr x)
    @body{bool z=(x);} 
    return z

def add(@access u64 x, u64 y)
    @body{u64 z=x+y;} 
    return z

def mul(@access u64 x, u64 y)
    @body{u64 z=x*y;}
    return z

def div(@access u64 x, u64 y)
    @head{#include <stdio.h>}
    if y==0 
        @fail{printf("Error: division by zero\n");} 
        end
    @head{#include <stdio.h>}
    @body{u64 z=x/y;}
    return z

def sub(@access u64 x, u64 y)
    @head{#include <stdio.h>}
    if y>x 
        @fail{printf("Error: unsigned substraction yielded a negative\n");} 
        end
    @body{u64 z=x-y;}
    return z

def mod(@access u64 x, u64 y) 
    @head{#include <stdio.h>}
    if y==0
        @fail{printf("Error: modulo by zero\n");}
        end
    @head{#include <stdio.h>}
    @body{u64 z=x%y;} 
    return z

def add(@access i64 x, i64 y) 
    @body{i64 z=x+y;} 
    return z

def mod(@access i64 x, i64 y)
    @head{#include <stdio.h>}
    if y<=i64(0)
        @fail{printf("Error: modulo by non-positive\n");} 
        end
    @head{#include <stdio.h>}
    @body{i64 z=x%y;}
    return z

def sub(@access i64 x, i64 y)
    @body{i64 z=x-y;}
    return z

def negative(@access i64 x)
    return sub(i64(0), x)

def mul(@access i64 x, i64 y)
    @body{i64 z=x*y;}
    return z

def div(@access i64 x, i64 y)
    @head{#include <stdio.h>}
    if y==i64(0)
        @fail{printf("Error: division by zero\n");} 
        end
    @head{#include <stdio.h>}
    @body{i64 z=x/y;}
    return z

def add(@access f64 x, f64 y) 
    @body{f64 z=x+y;} 
    return z

def sub(@access f64 x, f64 y)
    @body{f64 z=x-y;} 
    return z

def mul(@access f64 x, f64 y)
    @body{f64 z=x*y;} 
    return z

def negative(@access f64 x) 
    return sub(0.0, x)

def div(@access f64 x, f64 y) 
    @body{f64 z=x/y;} 
    return z

def eq(@access symbol x, symbol y)
    @body{bool z=(x==y);}
    return z

def neq(@access symbol x, symbol y)
    @body{bool z=(x!=y);}
    return z
