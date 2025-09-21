@include std.core 

smo point(f64 x, f64 y)
    return @args

smo circle(point center, f64 r)
    return @args

smo print(point p)
    printin("point (")
    printin(p.x)
    printin(",")
    printin(p.y)
    print(")")
    noreturn

smo print(circle c)
    printin("circle radious ")
    printin(c.r)
    printin(" centered at ")
    print(c.center)
    noreturn

smo add(point a, point b) 
    return point(a.x+b.x, a.y+b.y)

smo add(circle a, circle b) 
    return circle(a.center, a.r+b.r)

service main()
    p1 = point(1.0, 2.0)
    p2 = point(3.0, 4.0)
    c1 = circle(p1, 10.0)
    c2 = circle(p2, 10.0)
    print(add(p1,p2))
    print(add(c1,c2))
    noreturn