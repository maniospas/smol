@include std

smo Point(i64 x, i64 y) -> @new
smo Field(Point start, Point end) -> @new

smo main()
    p = Point(3,4)
    f = Field(1,2,p)
    print(f.start.x)
    print(f.end.y)
    i = add(f.start.x, f.start.y)
    print(i)
