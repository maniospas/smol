@include std.builtins
@include std.file
@include std.mem

smo zero(u64 n)
    v = heap:allocate(n, f64)
    i = 0 
    while i<n 
        @next i = i+1 
        v:put(i, 0.0) 
        --
    -> v

smo dot(allocate x, allocate y)
    if x.size!=y.size -> fail("Mismatching size")
    i = 0 
    sum = 0:Primitive
    while i<x.size
        @next i = i+1 
        with sum = sum + x[i]*y[i] --
        else --
        -- 
    -> sum

smo add(allocate x, allocate y)
    if x.size!=y.size -> fail("Mismatching size")
    i = 0 
    z = Memory:allocate(x.size, Primitive)
    while i<x.size
        @next i = i+1 
        with z:put(i, x[i]+y[i]) --
        else --
        -- 
    -> sum

service main()
    n = 10000
    x = zero(n)
    y = zero(n)
    x:put(0, 0.1)
    y:put(0, 0.2)
    //z = add(x,y)
    print(dot(x,y))
    //print(z[0])
    --
