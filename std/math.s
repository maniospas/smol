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

@include std.core.num
@unsafe

@about 
"Standard library wrapping of C math operations."

@about cos
"Computes the cosine of an angle given in radians. Example:"
"<pre>print(cos(0.0))       // prints 1.0"
"\nprint(cos(0.5.pi()))  // prints approximately 0.0</pre>"

@about acos
"Computes the arc cosine (inverse cosine) of a value in the range [-1, 1]. "
"Returns an angle in radians. Example:"
"<pre>print(acos(1.0))     // prints 0.0"
"\nprint(acos(0.0))     // prints approximately 1.5708 (0.5.pi())</pre>"

@about sin
"Computes the sine of an angle given in radians. Example:"
"<pre>print(sin(0.0))       // prints 0.0"
"\nprint(sin(0.5.pi()))  // prints approximately 1.0</pre>"

@about asin
"Computes the arc sine (inverse sine) of a value in the range [-1, 1]. "
"Returns an angle in radians. Example:"
"<pre>print(asin(0.0))     // prints 0.0"
"\nprint(asin(1.0))     // prints approximately 1.5708 (0.5.pi())</pre>"

@about exp
"Computes the exponential function e^x. Example:"
"<pre>print(exp(1.0))  // prints approximately 2.71828"
"\nprint(exp(2.0))  // prints approximately 7.38906</pre>"

@about pi
"Multiplies a given number by π (pi). This is often used for angle "
"conversions. Example:"
"<pre>print(1.0.pi())  // prints approximately 3.14159"
"\nprint(0.5.pi()) // prints approximately 1.5708 (π/2)</pre>"

@about tan
"Computes the tangent of an angle given in radians. Example:"
"<pre>print(tan(0.0))        // prints 0.0"
"\nprint(tan(0.25.pi())) // prints approximately 1.0</pre>"

@about atan
"Computes the arc tangent (inverse tangent) of a value, returning an angle "
"in radians. Example:"
"<pre>print(atan(1.0)) // prints approximately 0.785398 (0.25.pi())"
"\nprint(atan(0.0)) // prints 0.0</pre>"

@about atan2
"Computes the arc tangent of y/x using the signs of both arguments to determine "
"the correct quadrant of the result. Returns an angle in radians. Example:"
"<pre>print(atan2(1.0, 1.0))   // prints approximately 0.785398 (0.25.pi())"
"\nprint(atan2(1.0, -1.0))  // prints approximately 2.35619 (0.75.pi())</pre>"

@about is_nan
"Checks if a floating-point number is 'not a number' (NaN). Example:"
"<pre>x = 0.0/0.0"
"\nif is_nan(x)"
"\n    print(\"x is NaN\")</pre>"

@about is_inf
"Checks if a floating-point number represents infinity (positive or "
"negative). Example:"
"<pre>x = 1.0/0.0"
"\nif is_inf(x)"
"\n    print(\"x is infinite\")</pre>"

@about sqrt
"Computes the square root of a number. Requires a non-negative input. "
"Example:"
"<pre>print(sqrt(9.0)) // prints 3.0"
"\nprint(sqrt(2.0)) // prints approximately 1.41421</pre>"

@about pow
"Computes the result of raising a base to an exponent (base^exponent). "
"Yields NaN if the base is negative. Example:"
"<pre>print(pow(2.0, 3.0)) // prints 8.0"
"\nprint(pow(9.0, 0.5)) // prints 3.0</pre>"

@about log
"Computes the natural logarithm (base e) of a number. Yields NaN on non-positive "
"input. Example:"
"<pre>print(log(exp(1.0))) // prints 1.0"
"\nprint(log(10.0))     // prints approximately 2.30259</pre>"


def cos(f64 x)
    @head{#include <math.h>}
    @body{f64 z = cos(x);}
    return z

def acos(f64 x)
    @head{#include <math.h>} 
    @body{f64 z = acos(x);}
    return z

def sin(f64 x)
    @head{#include <math.h>}
    @body{f64 z = sin(x);}
    return z

def asin(f64 x)
    @head{#include <math.h>} 
    @body{f64 z = asin(x);}
    return z

def exp(f64 x) 
    @head{#include <math.h>} 
    @body{f64 z = exp(x);}
    return z

def pi(f64 x) 
    @head{#include <math.h>} 
    @body{f64 z = x * M_PI;} 
    return z

def tan(f64 x)
    @head{#include <math.h>}
    @body{f64 z = tan(x);}
    return z

def atan(f64 x) 
    @head{#include <math.h>} 
    @body{f64 z = atan(x);}
    return z

def atan2(f64 y, f64 x) 
    @head{#include <math.h>} 
    @body{f64 z = atan2(y, x);} 
    return z

def is_nan(f64 x) 
    @body{bool z=(x!=x);} 
    return z

def is_inf(f64 x) 
    @head{#include <cmath>} 
    @body{bool z=isinf(x);}
    return z

def sqrt(f64 x)
    // if x<0.0
    //     @fail{printf("Root requires positive inputs\n");}
    @head{#include <math.h>}
    @body{f64 z = sqrt(x);}
    return z

def pow(f64 base, f64 exponent)
    // if base<0.0
    //     @fail{printf("Exponentiation requires non-negative base\n");} 
    @head{#include <math.h>}
    @body{f64 z = pow(base, exponent);}
    return z
    
def log(f64 x)
    // if x<=0.0 
    //     @fail{printf("Logarithm needs positive inputs\n");}
    @head{#include <math.h>}
    @body{f64 z = log(x);}
    return z