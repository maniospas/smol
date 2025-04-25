@include std

smo Point(i64 x, i64 y) => (x,y)
smo Field(Point start, Point end) => @new

smo main()
    i64 i(0)
    i = add(i, 1)
    i = i64(2)
    i = add(i,3)
    print(i)
