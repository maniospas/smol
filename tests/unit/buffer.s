@include std.builtins
@include std.mem

smo point(f64 x, f64 y) 
    -> @args

smo point2(f64 x, f64 y)
    -> point(x*2.0, y*2.0)

smo create(@mut point[] p) // buffer of points (& to allow mutation by push)
    p:push(point(0.5,2.2)) 
    p:push(point(0.5,2.2-4.0))
    -> p

service main()
    @mut p = point[]:create

    print(p[0]:point2.x) // 1.0
    print(p[1].y)        // -1.8
    --
