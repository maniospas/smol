@include std.builtins

smo Point(f64 px, f64 py)
    x = px
    y = py
    -> x,y

smo TPoint(nominal type, f64 px, f64 py)
    @mut x = px
    @mut y = py
    -> type, x,y

smo IPoint(nominal type, f64 x, f64 y) 
    -> @args

smo scale(@mut Point p, f64 factor) 
    //p.x = p.x*factor
    //p.y = p.y*factor
    --

smo zero(@mut Point p)
    p = Point(0.0, 0.0)
    --

smo zero(@mut IPoint p)
    p = nominal:IPoint(0.0, 0.0)
    // p.x = 2 // creates an ERROR (p is mutable as a whole only)
    --

service main()
    @mut p = Point(1.0,1.0)
    //p.x = p.x + 1.0
    p:scale(5.0)
    print(p.x) // 10
    //zero(p)
    print(p.x) // 0
    
    @mut ip = nominal:IPoint(1.0,1.0)
    print(ip.x) // 1 
    zero(ip)
    print(ip.x) // 0


    tp = nominal:TPoint(1.0,1.0)
    //tp:scale(5.0) // creates an ERROR
    --