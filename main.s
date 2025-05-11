@include std

smo Point(f64 x, f64 y) -> @new
smo Point() 
    start = Point(0.0, 0.0)
    -> start // as a single argument it is directly unpacked


service main()
    s = Point()
    print(s.x) // not s.start.x
    --