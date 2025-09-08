@include std.builtins
@include std.mem
@unsafe

smo point(f64 x, f64 y) 
    -> @args

smo create()
    &memory = Stack:allocate(1024)
    p = point[memory]  // 1kB buffer
    :push(point(1.5, 2.2))
    :push(point(0.5, 4.0))
    -> p

service main()
    p = create()
    a = p[0]
    b = p[1]
    print(a.x)  // 4.0
    --
