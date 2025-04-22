# smoλ

*A very low-level language.*

This language is designed to create zero-cost abstractions for managing complex data structures.
Under the hood, it transpiles to C++.

**Dependencies:** GCC
**Contact:** Emmanouil (Manios) Krasanakis
**License:** Apache 2.0

## Quick Peek

Since I'm currently developing the language, let's take a look at an example program.

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
As you can see, the language is tiny — really tiny! So tiny, in fact,
that it requires you to declare your own print functions and basic arithmetic operators.
However, it provides a direct-to-C++ interface that lets you bring in more powerful functionality.
The only built-in elements are the `main` function and a couple of number types.

Let's break down the code above piece by piece, starting with the simpler segments —
for example, you can write the addition across multiple lines like this:

```java
smo add(i64 x, i64 y)
    @body{i64 z=x+y;}
    => z
```

This tells us that we are defining an integer addition function with the corresponding arguments.
`smo` indicates that this definition should be inlined everywhere.
Inlining is even more optimization-friendly than simple C instructions because,
despite the illusion of data structures, most of them are converted to direct variable operations
(e.g., `f__start__x` represents `f.start.x` under the hood).
As a result, computations that don’t affect the outcome can often be dropped entirely.

The `=>` symbol indicates a return value, while `@body` allows us to write C code directly.
Variable assignments to the built-in data types are visible outside the C code as well.
Notice how *smoλ* does not require semicolons to separate commands — this is possible
because command boundaries are uniquely understood.
Functions end at their return statement or at the end of the file —
nested functions cannot be defined, so you will receive helpful error messages if you try.

Now, on to the data types.


```java
smo Point(i64 x, i64 y) => @new
smo Field(Point start, Point end) => @new
```

These lines declare some data types. The `smo` prefix indicates definitions
that will be inlined. In general, data and functions share the exact same interface.
The return statement for functions or data, denoted by `=>`, can yield either a single value or a tuple of values.
For example, a 2D point could be defined as: `smo Point(i64 x, i64 y) => (x, y)`.
Starting with `@new` is a shorthand for returning a tuple of the inputs.

### How are values used?

If you write, say, `Point p`, you can access all named intermediate or final values using `p.x` and `p.y`.
However, when the whole point is used, its return value is unpacked.
For example, writing `Point p1(p)` is equivalent to writing `Point p1(p.x, p.y)`.

Conversely, when declaring functions or data types that take others as arguments,
those arguments are unpacked into built-in values.
For example, you can construct a `Field` from four individual values,
or from a mixture like two values and a `Point`.
The syntax `Point p(2, 3) Field(1, p, 4)` is also valid.
However, you can add type annotations to avoid ambiguity — more on that later,
though this is often zero-cost as well.

### Final Notes

Finally, put all your code inside a `main` function.

> :warning: **Calling conventions are of the form:** `type name(arguments)`
> This design choice makes a lot of sense within the language's architecture,
> but more conventional syntax options will be added in the future.


