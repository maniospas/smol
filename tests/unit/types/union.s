@include std.core :: i64, u64, f64, print, ok

union Type = i64 or u64 or f64

def Point(Type _x, Type _y)
    @mut x = _x
    @mut y = _y
    return x,y

def inc(@access @mut Point p)
    p.x = p.x+Point::Type(1)
    p.y = p.y+Point::Type(1)

service main()
    value = 1.f64()
    @access p = Point(value, value)
    p.inc()
    print(p.x)
