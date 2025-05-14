@include std
@include std.vec
@include std.time

service main()
    n = 100000:u64
    x1 = vec(n)
    x2 = vec(n)
    x1:put(0:u64, 1.0)
    x2:put(0:u64, 1.0)
    tic = time()
    z = dot(x1,x2)
    print(time()-tic)
    print(z)
    --