@indentation
@include std.core

union Type = i64 or u64 or f64

def Point(Type _x, Type _y)
    @mut x = _x
    @mut y = _y
    return x,y

def inc(@access @mut Point p)
    p.x = p.x+Point.Type(1)
    p.y = p.y+Point.Type(1)

service main()
    //print("Give a value: ")
    //&value = f64:read
    value = f64(1)
    @access p = Point(value, value)
    p.inc()
    print(p.x)