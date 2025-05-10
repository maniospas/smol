# smoλ

*A very low-level language.*

This language is designed to create zero-cost abstractions for managing complex data structures.
Under the hood, it transpiles to C++.

**Dependencies:** GCC<br>
**Contact:** Emmanouil (Manios) Krasanakis<br>
**License:** Apache 2.0

## [Docs](https://maniospas.github.io/smol/)

## Quickstart

Here's a quickstart that showcases several core features. 
Visit the docs above for a comprehensive breakdown.

```cpp
@include std

smo Point(i64 x, i64 y) -> @new
smo Field(Point start, Point end) -> @new

service main()
    p = Point(3,5)
    f = Field(1,2,p)
    print(f.start.x+f.end.y) // 6
```


## Licenses

Different parts of this codebase are governed by different licenses:

- std.s: CC0
- std/: CC0
- Prism.js: MIT License (see `vendor/prism/LICENSE`)
- Everything else: Apache2.0