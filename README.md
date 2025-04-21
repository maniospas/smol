# smoλ

*A very low-level language.*

This is a language aimed at creating zero-cost abstractions over managing complicated data structures.
Under the hoods it transpiles to C++.

**Dependencies:** gcc<br>
**Contant:** Emmanouil (Manios) Krasanakis<br>
**License:** Apach 2

## Quick peek

Since I'm in the middle of developing the language, let's take a look at an example program.

```java
smo print(i64 x)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", x);}
    => true

smo add(i64 x, i64 y) @body{i64 z=x+y;} => z
smo sub(i64 x, i64 y) @body{i64 z=x-y;} => z
smo mul(i64 x, i64 y) @body{i64 z=x*y;} => z
smo div(i64 x, i64 y) @body{i64 z=x/y;} => z

smo Point(i64 x, i64 y) => @new
smo Field(Point start, Point end) => @new

smo main()
    Field f(1,2,3,4)
    print(f.start.x)
    print(f.end.y)
    add i(f.start.x, f.start.y)
    print(i)
```

As you can see, the language is tiny. Really tiny! So tiny, in fact,
that it needs you to declare your own prints and basic arithmetic operators.
But it has a direct-to-cpp interface that can bring in more powerful
stuff. The only built-in data types are the main function and a couple number types.

Let's take the above code piece-by-piece, starting from the simpler segments - write
the addition in multiple lines like this:

```java
smo add(i64 x, i64 y)
    @body{i64 z=x+y;}
    => z
```

This tells us that we are definining an integer addition with corresponding
arguments. `smo` indicates that this definition should be inlined everywhere.
Inlining is more optimization friendly than even simple C instructions
because, despite the illusion of data structures, those are for the most part
converted to direct variable operations (e.g., `f__start__x` represent `f.start.x`
under the hood) and therefore a bunch of computations can be dropped if they
do not affect the outcome.

The `=>` symbol indicates a returned value, whereas `@body` lets us write
some C code directly. Variable assignment to the
builtin datatypes are visible outside of C too. Notice how *smoλ* does not
require semicolons to separate commands because how to do so is uniquely
understood. Functions end at their return statement or at end of file -
nested functions cannot be defined so you will see helpful error messages.

Now on to the data types.

```java
smo Point(i64 x, i64 y) => @new
smo Field(Point start, Point end) => @new
```

These declare some data types. The `smo` prefix indicates definitions
that are going to be inlined. In general, data and functions have the
exact same interface. The return statement for functions/data `=>`
can yield either a single value or a tuple of values. For example, a 2D
point could be defined per `smo Point(i64 x, i64 y) => (x,y)`.
Starting with `@new` is a shorthand for returning a tuple of the inputs.

How are values used? If you write, say, `Point p` you can access all
named intermediate or final values per `p.x` and `p.y`. However, when
the whole point is used, its returned value is unpacked. For example,
writting `Point p1(p)` is equivallent to writting `Point p1(p.x,p.y)`.

Conversely, when declaring functions/data types with other ones as
arguments, these are unpacked to builtin values. For example, you can
construct a `Field` above from four values, from a mixture of two values
and a point, etc. The syntax `Point p(2,3) Field(1,p,4)` is also valid,
but you can add type annotations to prevent this issue - more on this
later, but it is often zero-cost too


Finally, put all your code in a `main` function.

:warning: Calling conventions are **type name(arguments)**. Somehow,
this makes a lot of sense in terms of the language's design, but
more conventional syntax options will be added to the future.


