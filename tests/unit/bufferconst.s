@include std.core
@include std.mem
@unsafe 

smo point(f64 x, f64 y) 
    return @args

smo create(@mut ContiguousMemory memory)
    p = point[memory]
    return p

smo create()
    p = create(Heap:allocate(1024)) // 1kB buffer
    :push(point(1.5, 2.2))
    :push(point(0.5, 4.0))
    return p

service main()
    p = create()
    a = p[0]
    b = p[1]
    print(a.x)  // 4.0
    end
