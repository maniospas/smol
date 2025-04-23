# smoλ

*A very low-level language.*

This language is designed to create zero-cost abstractions for managing complex data structures.
Under the hood, it transpiles to C++.

**Dependencies:** GCC
**Contact:** Emmanouil (Manios) Krasanakis
**License:** Apache 2.0

## Keywords

- `smo` - Introduces a data type/inlineable function. It can have any other data type as argument.
- `service` - Introduces a function that works as a service. Is exactly like `smo`
- `i64,u64,f64,ptr` -  Primitive data types corresponding to integers, unsigned integers, doubles, and memory pointers (the latter are needed but unsafe - use `buffer` instead).
- `buffer` - Memory-allocated buffer. The only advanced data type manually implemented by the langugage, and the only way to interact with the heap.
- `=>@new` - Returns all arguments to avoid explicitly writting them down. Handy for treating `smo` as a data structure.
- `=>@scope` - The command creates a new scope.
- `@head,@body,@fail` - Inject C++ code restricted to certain conventions. The first instruction is for adding headers, the second for placing directly where invoked, and the last one evokes a failing state of the program (without messing with branch prediction too much).
- `=>` - Returns a value. This marks the end of `smo`, `env`, or scopes.
- `=>>,=>>>`... - Forces the parent scope to return a value. Note that returned values should be aligned.

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
    Point p(3,4)
    Field f(1,2,p)
    print(f.start.x)
    print(f.end.y)
    add i(f.start.x, f.start.y)
    print(i)
```
As you can see, the language is tiny — really tiny! So tiny, in fact,
that it requires you to declare your own print functions and basic arithmetic operators.
However, it provides a direct-to-C++ interface for more powerful functionality.
The only built-in elements are the the aforementioned keywords, `main` as the entrant
point of programs, and a couple of builtin types.

### smo

Let's break down the code above piece by piece, starting with the simpler segments.
Write the addition across multiple lines like so:

```java
smo add(i64 x, i64 y)
    @body{i64 z=x+y;}
    => z
```

This tells us that we are defining an integer addition function with the corresponding arguments.
`smo` indicates that the definition should be inlined everywhere.
Inlining is even more optimization-friendly than simple C instructions because,
despite the illusion of organization, data are converted to direct variable operations
(e.g., `f.start.x` is represented by `f__start__x` under the hood).
As a result, much more aggressive optimizations than normal can be performed by the compiler
for what would normally be complicated code.

The `=>` symbol returns value -or a tuple of values- while `@body` allows us to write C++ code directly.
Variable assignments to the built-in data types are visible outside the code as well.
Notice how *smoλ* does not require semicolons to separate commands, as boundaries are unique.
Functions end at their return statement or at the end of the file.

### Data types

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
For example, writing `Point p1(p)` is equivalent to writing `Point p1(p.x, p.y)`. The unpacking is flat
in that everything is converted into a non-nested tuple before calling functions/creating data.

Conversely, when declaring functions or data types that take others as arguments,
those arguments are unpacked into built-in values.
For example, you can construct a `Field` from four individual values,
or from a mixture like two values and a `Point`.
The syntax `Point p(2, 3) Field(1, p, 4)` is also valid.
However, you can add type annotations to avoid ambiguity — more on that later,
though this is often zero-cost as well.

### Services

Put all your code inside a `main` function. <br>
**Unimplemented design:** In the future, there will exist services, with `main` being
one of them that will be treated as functions, will have clear communication rules,
and will operate across multiple threads.


## Some additional commands

There are some additional options for the main language that offer ease of use.

## Control flow

Even conditionals are second-class citizens in *smoλ*; They need to be manually implemented like
below. We will use everything to create a safe division. The latter evokes the `@fail` instruction,
which is the error handling mechanism of *smoλ*; it ends the current service completely - currently
terminating the progra but in the future you will be able to handle failing services.
There will also be a standard library in the future, but for now I am focusing on the language's core,
hence why we need to declare everything.

```java
smo print(i64 x)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", x);}
    => true
smo if(bool condition) @body{if(!condition)goto __scope__finally;} => @scope

smo le(i64 x, i64 y) @body{bool z=x<y;} => z
smo ge(i64 x, i64 y) @body{bool z=x>y;} => z
smo leq(i64 x, i64 y) @body{bool z=x<=y;} => z
smo geq(i64 x, i64 y) @body{bool z=x>=y;} => z
smo eq(i64 x, i64 y) @body{bool z=(x==y);} => z
smo neq(i64 x, i64 y) @body{bool z=(x!=y);} => z
smo and(bool x, bool y) @body{bool z=x&&y;} => z
smo or(bool x, bool y) @body{bool z=x||y;} => z

smo add(i64 x, i64 y) @body{i64 z=x+y;} => z
smo sub(i64 x, i64 y) @body{i64 z=x-y;} => z
smo mul(i64 x, i64 y) @body{i64 z=x*y;} => z

smo div(i64 x, i64 y)
    @head{#include <stdio.h>}
    i64 zero(0)
    eq comp(y, zero)
    if(comp)
        @fail{printf("Division by zero\n");}
        => true
    @body{i64 z=x/y;}
    => z
```

## Buffers

Sometimes you may want to handle dynamic memory.
This is achieved with the *buffer* type, which is
a special `smo` implementation hard-coded into the language.
This accepts a variadic number of arguments, can have
more of those be pushed onto it, and can have elements
be popped from the front when it is passed as an argument.
Below is an example. Use buffers to move around large chunks
of data.

```java
smo Point(i64 x, i64 y) => (x,y)
smo Field(Point start, Point end) => @new


smo main()
    i64 b1(1)
    i64 b2(2)
    i64 b3(3)
    i64 b4(4)

    buffer buf(b1,b2,b3,b4)
    Field f(buf)
    print(f.start.x)
```

## Assignments

Lastly, *smoλ* supports the assignment operator.
This dynamically sets or overwrites a value,
but the right-hand-side must always be a `smo`
call. Contrary to calling/constructing data based
on a number of arguments, it directly copies
values (buffer contents are not copied though).
Furthermore, it checks that both sides of the
assignment correspond to the exact same data.
You cannot assign to unitialized variables.
Here is an example:


```java
smo print(i64 x)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", x);}
    => true
smo add(i64 x, i64 y) @body {i64 z=x+y;} => z

smo main()
    i64 i(0)
    i = i64(2)
    print(i)
```

