# smoλ

*A very low-level language.*

This language is designed to create zero-cost abstractions for managing complex data structures.
Under the hood, it transpiles to C++.

**Dependencies:** GCC<br>
**Contact:** Emmanouil (Manios) Krasanakis<br>
**License:** Apache 2.0

## [Docs](https://maniospas.github.io/smol/)

## Quick Peek

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


