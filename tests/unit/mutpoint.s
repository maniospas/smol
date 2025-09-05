@include std.builtins

smo Point(f64 px, f64 py)
    &x = px
    &y = py
    -> x,y

smo TPoint(nom type, f64 px, f64 py)
    &x = px
    &y = py
    -> type, x,y


smo IPoint(nom type, f64 x, f64 y) -> @args

smo scale(Point &p, f64 factor) 
    // & in the signature is required to allow any modification
    // this is an overloaded method for both smo Point
    p.x = p.x*factor
    p.y = p.y*factor
    --

smo zero(Point &p)
    p = Point(0.0, 0.0)
    --

smo zero(IPoint &p)
    p = nom:IPoint(0.0, 0.0)
    // p.x = 2 // creates an ERROR (p is mutable as a whole only)
    --

service main()
    p = Point(1.0,1.0)  
    p.x = p.x + 1.0
    p:scale(5.0)
    print(p.x) // 10
    zero(p)
    print(p.x) // 0

    &ip = nom:IPoint(1.0,1.0)
    print(ip.x) // 1 
    zero(ip)
    print(ip.x) // 0


    tp = nom:TPoint(1.0,1.0)
    //tp:scale(5.0) // creates an ERROR
    --