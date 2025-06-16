@include std.builtins
@include std.vec

smo pointr(f64 r, f64 &t)  // t is mutable (the returned t also becomes mutable)
    t = t*2.0
    -> r,t

smo point2d(f64 _x, f64 _y)
    &x = _x  // x is mutable
    &y = _y
    -> x,y

service main()
    &t0 = 90.0
    p = pointr(1.0, t0)    // the compiler would complain if t0 was not mutable
    p.t = 360.0
    print(t0)              // prints 180
    print(p.t)             // prints 360

    p2 = point2d(1.0, 2.0)
    p2.y = p2.y * 5.0
    print(p2.y)            // prints 10
    -- 
