@include std

smo Point(i64 x, i64 y) => (x,y)
smo Field(Point start, Point end) => @new

smo main()
    f64 i(0)
    print(i)

    buffer buf(1,2,3,4)
    Field f(buf)
    print(f.start.x)

    f.start.x = i64(0)
    print(f.start.x)

    div res(1,0)
    print(res)
