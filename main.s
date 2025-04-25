@include std

smo Point(i64 x, i64 y) => (x,y)
smo Field(Point start, Point end) => @new

smo main()
    i = 2
    i = add(i,3)
    print(i)
