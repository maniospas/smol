@include std

smo Point(i64 x, i64 y) z=1 -> @new

smo main()
    Point p(1,2)
    p.z = 50
    p = Point(2,3)
    print(p.z)
    print(p.x)
