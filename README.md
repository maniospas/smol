# smoλ

*A safe & fast low-level language.*

![logo](./docs/smol.png)

Declare zero-cost safe abstractions for structural and nominal data. Transpile to performant C.


**Dependencies:** GCC<br>
**Contact:** Emmanouil (Manios) Krasanakis<br>
**License:** Apache 2.0

## [Docs](https://smolambda.netlify.app/)

## Quickstart

Here's two snippets that showcase several features on 
data structures and control flow respectively.
Visit the docs above for a comprehensive breakdown, 
but here's a summary of important commands. Everything,
from file I/O to string handling, is built from safe, near-zero-cost 
abstractions over bare-metal operations.

Data structures are structurally or nominally typed,
where in the nominal case the argument list starts with the special
`nom` type that is later returned. 
`smo` are functions that run 
and produce a list of outputs that work as a type. So
they are called *runtypes*. Named outputs can be accessed 
as fields. Use `@new` to refer to the list of inputs. 
Comma concatenation is flat. The `:` symbol is currying,
that is, passes the left-hand-side as the first argument.
Finally `->` is a returned value, `--` is a return with
no value, and services are runtypes that form failure barriers.
Grouping returns is a convenient way to also track code complexity.


```rust
@include std.builtins

// overloading a structural type
smo Point(f64 x, f64 y) -> @new 
smo Point(u64 x, u64 y) -> @new
// Field is nominal, Point will be the same for start and end
smo Field(nom, Point start, Point end) -> @new
smo operation(Field f, f64 multiple) 
    value = f.start.x + f.end.y
    -> value*multiple

service main()
    // type inference based on arguments
    p = Point(3.0,5.0)
    f = nom:Field(1.0,2.0,p)
    m = f64:read             // types can be args to determine type version
    print(f:operation(m))    // prints 6*m
    --
```


```rust
@include std.builtins

service main()
    print("Printing squares of 0,1,..,9")
    // declare i as mutable so that `next` can modify it
    range(10) // curried as first argument in the `next` call
    :while next(u64& i) 
        if i>=2 
            squared = i*i
            -> print(squared) // return from if with no-result (more consise than -- afterwards)
        else 
            -> print(i) 
    ---- // end `while`, then `main`
```


## Licenses

Different parts of this codebase are governed by different licenses:

- std/: CC0
- Prism.js: MIT License (see `vendor/prism/LICENSE`)
- Everything else: Apache2.0