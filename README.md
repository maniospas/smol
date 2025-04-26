# smoλ

*A very low-level language.*

This language is designed to create zero-cost abstractions for managing complex data structures.
Under the hood, it transpiles to C++.

**Dependencies:** GCC<br>
**Contact:** Emmanouil (Manios) Krasanakis<br>
**License:** Apache 2.0

## Keywords

| Keyword                     | Description                                                                                                                                                                                           |
|-----------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `smo`                       | Introduces a data type / inlineable function. It can take any other data type as an argument.                                                                                                         |
| `service`                   | Introduces a function that works as a service; functionally identical to `smo`.                                                                                                                      |
| `i64`, `u64`, `f64`, `ptr`  | Primitive data types for signed integers, unsigned integers, doubles, and raw memory pointers (pointers are needed but unsafe—prefer `buffer`).                                                      |
| `buffer`                    | Memory-allocated buffer. The only advanced data type manually implemented by the language and the sole way to interact with the heap.                                                                |
| `->@new`                    | Returns all arguments so you don’t have to write them out explicitly—handy for treating `smo` as a data structure.                                                                                   |
| `->@scope`                  | Enters a new scope (shares variables from its parent but may declare new ones internally).                                                                                                           |
| `@head`, `@body`, `@fail`   | Inject C++ code under restricted conventions: `@head` adds headers, `@body` places code directly where invoked, `@fail` triggers a program-failure state (designed not to disrupt branch prediction). |
| `->`                        | Returns a value or tuple; marks the end of an `smo`, a `service`, or a scope.                                                                                                                        |
| `->>`, `->>>`, …            | Returns a value or tuple from the parent scope, the grand-parent scope, etc.                                                                                                                         |
| `--`                        | Signifies end of scope without returning a value.                                                                                                                                                    |


## Quick Peek

Since I'm currently developing the language, let's take a look at an example program.

```java
@include std

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
The language's core is tiny — really tiny! So tiny, in fact,
that print functions and basic arithmetic operators are part of the standard library.
However, there's a direct-to-C++ interface for more powerful functionality.
The only built-in elements are the the aforementioned keywords, `main` as the entrant
point of programs, and a couple of builtin types.

### smo

Let's start with a declaration from the standard library:

```java
smo add(i64 x, i64 y)
    @body{i64 z=x+y;}
    => z
```

This tells us that we are defining an integer addition function with the corresponding arguments.
`smo` indicates that the definition should be inlined everywhere.
Inlining is more optimization-friendly than simple C instructions because,
despite the illusion of data types, everything is to direct variable operations
(e.g., `f.start.x` is represented by `f__start__x` under the hood).
As a result, much more aggressive optimizations than normal can be performed by the compiler
for what would normally be complicated code.

Rreturn a value or tuple of values with `->`, whereas while `@body` lets us write C++ directly.
Variable assignments to the built-in data types are visible outside that source as well.
Notice how *smoλ* does not require semicolons to separate commands: boundaries are unique.
Everything ends at return statements or at the end of file.

### Data types

```java
smo Point(i64 x, i64 y) => @new
smo Field(Point start, Point end) => @new
```

These lines declare some data types. In general, data and functions share the exact same interface.
Starting with `@new` is a shorthand for returning a tuple of the inputs.
For example, the *Point* could also be defined as: `smo Point(i64 x, i64 y) => (x, y)`.

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

Even conditionals are second-class citizens in *smoλ* and are manually implemented in the standard library.
For example, below is an implementation of safe division. This evokes the `@fail` instruction,
which is the error handling mechanism of *smoλ* that safely terminates the current service. Notice
the usage of `--` to terminate the condition's block without returning a value.

```java
smo div(i64 x, i64 y)
    @head{#include <stdio.h>}
    iszero = eq(y, 0)
    if(iszero)
        @fail{printf("Division by zero\n");}
        --
    @body{i64 z=x/y;}
    -> z
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
    buffer buf(1,2,3,4)
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
    --
smo add(i64 x, i64 y) @body {i64 z=x+y;} -> z

smo main()
    i64 i(0)
    i = i64(2)
    print(i)
```


## Inclusion

You can include statements with the top-level include directive.
Here is an example of including the standard library. Paths
are separated by dots, and the *.s* extension is automatically appended.
*smoλ* keeps track of included files and creates an error if you
try to re-include some.

```java
@include std

smo main()
    i64 i(0)
    print(i)
```

**Note:** All instructions starting with `@` have non-visible effect on code.


## Overloading

You can overload `smo` definitions, though for safety only in the same file.
After overloading, types cannot be used in function signatures due to ambiguity that is
impossible to resolve under *smoλ*'s data representation model.

