@include std

smo Point(i64 x, i64 y) -> @new

smo main()
    buf = buffer(1,2)
    print(Point(buf).x)
