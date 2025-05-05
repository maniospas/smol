@include std

union Type(i64, f64)
smo Point(Type x, Type y) -> @new
smo inc(Point &p)
    p.x = add(p.x, Type(1))
    p.y = add(p.y, Type(1))
    --

service main()
    value = i64|read()
    p = Point(value, value)
    p|inc() // this is a comment
    print(p.x)
