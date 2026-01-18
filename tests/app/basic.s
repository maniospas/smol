@include std.core.num

def point(f64 x, f64 y)
    return @args

def test(f64 x)
    y = 1
    y = add(y,1)
    if le(x,1.0)
        return f64(y)
    return 0.0

service main()
    p = point(1.0, 2.0)
    y = p.x
    print(y)