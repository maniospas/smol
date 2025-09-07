@include std.builtins
@include std.mem

smo point(f64 x, f64 y) 
    -> @args

service create()
    p = point[Heap:allocate(1024)]  // 1kB buffer limit
    :push(point(0.5, 2.2)) 
    :push(point(0.5, 4.0))
    -> p

service main()
    p = create()
    print(p[1].y)  // 4.0
    --
