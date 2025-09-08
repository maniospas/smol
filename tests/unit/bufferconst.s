@include std.builtins
@include std.mem

smo point(f64 x, f64 y) 
    -> @args

service create()
    p = point[Stack:allocate(1024)]  // 1kB buffer
    :push(point(1.5, 2.2))
    :push(point(0.5, 4.0))

    -> p

service main()
    p = create()
    if p.err:bool:not
        print("created data")
        a = p.p[0]
        b = p.p[1]
        print(a.x)  // 4.0
    ----
