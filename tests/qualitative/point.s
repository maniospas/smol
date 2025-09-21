@include std.core
@include std.vec

def pointr(f64 r, @mut f64 t)  // t is mutable (the returned t also becomes mutable)
    t = t*2.0
    return r,t

def point2d(f64 _x, f64 _y)
    @mut x = _x  // x is mutable
    @mut y = _y
    return x,y

service main()
    @mut t0 = 90.0
    @access p = pointr(1.0, t0)    // the compiler would complain if t0 was not mutable
    p.t = 360.0
    print(t0)              // prints 180
    print(p.t)             // prints 360

    @access p2 = point2d(1.0, 2.0)
    p2.y = p2.y * 5.0
    print(p2.y)            // prints 10
