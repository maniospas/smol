@include std

smo Point(i64 x, i64 y) -> (x,y)
smo Field(Point start, Point end) -> @new

smo main()
    buffer buf(1,2,3,4)
    f = Field(buf)
    print(f.start.x)
