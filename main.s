@include std

smo Point(i64 x, i64 y) -> @new

smo main()
    p = Point(1,2)
    buf = buffer(p)
    z = Point(buf).x
    print(z)
