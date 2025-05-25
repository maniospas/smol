# smoλ

*A safe & fast low-level language.*

![logo](./docs/smol.png)

Declare zero-cost safe abstractions for structural and nominal data. Transpile to performant C++.


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

smo Point(f64 x, f64 y) -> @new // return x,y
smo Field(Point start, Point end) -> @new
smo operation(Field f, f64 multiple) 
    value = f.start.x + f.end.y
    -> value*multiple

service main()
    p = Point(3.0,5.0)
    f = Field(1.0,2.0,p)
    print(f:operation(1.0)) // prints 6
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