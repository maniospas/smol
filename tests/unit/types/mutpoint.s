@include std.core

def Point(f64 px, f64 py)
    @mut x = px
    @mut y = py
    return x,y

def print(@access Point p)
    printin(p.x)
    printin(",")
    print(p.y)

def TPoint(f64 px, f64 py)
    x = px
    y = py
    return x, y

def IPoint(nominal, f64 x, f64 y) 
    return @args

def scale(@access @mut Point p, f64 factor) 
    p.x = p.x*factor
    p.y = p.y*factor

def zero(@access @mut Point p)
    p = Point(0.0, 0.0)

def zero(@mut IPoint p)
    p = nominal.IPoint(0.0, 0.0)
    // p.x = 0.0 // creates an ERROR (p is mutable as a whole only)

service main()
    @mut p = Point(1.0,1.0)
    p.scale(5.0)
    print(p) // 5.0, 5.0
    zero(p)
    print(p) // 0
    
    @mut ip = nominal.IPoint(1.0,1.0)
    print(ip.x) // 1 
    zero(ip)
    print(ip.x) // 0


    @mut tp = TPoint(1.0,1.0)
    tp.scale(5.0) // creates an error if we remove @mut from before tp
    return nothing