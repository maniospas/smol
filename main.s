@include std

smo Point(i64 x, i64 y) -> @new
smo print(Point p)
    print(p.x)
    print(p.y)
    --

smo inc(Point &p)
    p.x = p.x|add(1)
    p.y = p.y|add(1)
    --

smo main()
    value = i64(0)|read()
    p = Point(value,value)
    p|inc()
    p|print()
