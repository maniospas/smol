@include std
@include std.vec
@include std.time

service main()
    n = 100000:u64
    x1 = vec:rand(n)
    x2 = vec:rand(n)
    tic = time()
    z = dot(x1,x2)
    print("Elapsed \{time()-tic} sec")
    print(z)
    --
