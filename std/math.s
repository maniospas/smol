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
@about "Standard library wrapping of C math operations."

smo cos(f64 x)
    @head{#include <math.h>}
    @body{f64 z = cos(x);}
    return z

smo acos(f64 x)
    @head{#include <math.h>} 
    @body{f64 z = acos(x);}
    return z

smo sin(f64 x)
    @head{#include <math.h>}
    @body{f64 z = sin(x);}
    return z

smo asin(f64 x)
    @head{#include <math.h>} 
    @body{f64 z = asin(x);}
    return z

smo exp(f64 x) 
    @head{#include <math.h>} 
    @body{f64 z = exp(x);}
    return z

smo pi(f64 x) 
    @head{#include <math.h>} 
    @body{f64 z = x * M_PI;} 
    return z

smo tan(f64 x)
    @head{#include <math.h>}
    @body{f64 z = tan(x);}
    return z

smo atan(f64 x) 
    @head{#include <math.h>} 
    @body{f64 z = atan(x);}
    return z

smo atan2(f64 y, f64 x) 
    @head{#include <math.h>} 
    @body{f64 z = atan2(y, x);} 
    return z

smo is_nan(f64 x) 
    @body{bool z=(x!=x);} 
    return z

smo is_inf(f64 x) 
    @head{#include <cmath>} 
    @body{bool z=std::isinf(x);}
    return z

smo sqrt(f64 x)
    if x<0.0 
        @fail{printf("Root requires positive inputs\n");} 
        --
    @head{#include <math.h>}
    @body{f64 z = sqrt(x);}
    return z

smo pow(f64 base, f64 exponent)
    if base<0.0 
        @fail{printf("Exponentiation requires non-negative base\n");} 
        --
    @head{#include <math.h>}
    @body{f64 z = pow(base, exponent);}
    return z
    
smo log(f64 x)
    if x<=0.0 
        @fail{printf("Logarithm needs positive inputs\n");} 
        --
    @head{#include <math.h>}
    @body{f64 z = log(x);}
    return z