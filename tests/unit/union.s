@include std.core

union Type
    i64 
    f64 
    u64

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
    value = 1:f64
    @access p = Point(value, value)
    p:inc()
    print(p.x)