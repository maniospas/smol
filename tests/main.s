@include std.builtins
@include std.mem

smo zero(Memory, u64 n)
    v = nom:allocate(Memory, n, f64)
    i = 0 
    while i<n
        @next i = i+1
        v:put(i, 0.0)
    ---> v
 
smo dot(allocate x, allocate y)
    if x.size!=y.size -> fail("Mismatching size")
    with
        i = 0
        sum = x.Primitive:zero
        while i<x.size
            @next i = i+1 
            sum = sum + x[i]*y[i]
    -- else -----> sum // all closing statements

service main()
    n = 10000
    x = heap:zero(n)
    y = heap:zero(n)
    x:put(0, 0.1)
    y:put(0, 0.2)
    //z = add(x,y)
    print(dot(x,y))
    //print(z[0])
    --