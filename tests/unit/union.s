@include std.core

union Type
    i64 
    f64 
    u64
    --

smo Point(Type _x, Type _y)
    &x = _x
    &y = _y
    -> x,y

smo inc(Point &p)
    p.x = p.x+Point.Type(1)
    p.y = p.y+Point.Type(1)
    --

service main()
    //print("Give a value: ")
    //&value = f64:read
    value = 1:f64
    p = Point(value, value)
    p:inc()
    print(p.x)
    --