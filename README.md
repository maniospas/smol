# smoλ

*A safe & fast low-level language.*

![logo](./docs/smol.png)

This language is designed to create zero-cost abstractions for managing complex data structures.
Under the hood, it transpiles to C++.


**Dependencies:** GCC<br>
**Contact:** Emmanouil (Manios) Krasanakis<br>
**License:** Apache 2.0

## [Docs](https://smolambda.netlify.app/)

## Quickstart

Here's two snippets that showcase several features on 
data structures and control flow  respectively.
Visit the docs above for a comprehensive breakdown.

```rust
@include std

smo Point(i64 x, i64 y) -> @new // return x,y
smo Field(Point start, Point end) -> @new
smo operation(Field f) 
    value = f.start.x + f.end.y
    -> value

service main()
    p = Point(3,5)
    f = Field(1,2,p)
    print(f:operation()) // prints 6
    -- // return nothing
```


```rust
@include std

service main()
    print("Printing squares of 0,1,..,9")
    // @next computes the value but assigns it later
    i=0 while i<10 @next i = i+1 
        if i>=2 
            squared = i*i
            print(squared) 
            -- // return to signify end of condition and loop code
        else -> print(i) // concise syntax (print yields no value)
    ---- // end `while` then `main` in one line
```


## Licenses

Different parts of this codebase are governed by different licenses:

- std.s: CC0
- std/: CC0
- Prism.js: MIT License (see `vendor/prism/LICENSE`)
- Everything else: Apache2.0