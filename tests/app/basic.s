@include std.core.num

def point1(f64 x, f64 y) // todo: nominal variations cannot be mixed with structural ones
    return @args

def point1(new, f64 x)
    return @args 

def point2(new, f64 x, f64 y)
    return @args

def point3(f64 x, f64 y)
    return point2(new, x, y)

def point4(f64 x, f64 y)
    return point3(x, y)

union Point = point1 or point2 or point3 // overlap between point2 and point3

def field(Point a, Point b) // only 3 variations (2 from point1, 1 from point2)
    return @args

service main()
    p1 = point1(1.0, 2.0)
    p2 = point4(1.0, 2.0)
    f = field(p2, p2)
    print(add(f.a.x, f.a.y))
