@include std
@include std.vec
@include std.time

smo create_vector(u64 n) 
    ret = vec:rand(n)
    -> ret

service main()
    n = 100000:u64
    x1 = create_vector(n)
    x2 = create_vector(n)
    tic = time()
    z = dot(x1,x2)
    print("Elapsed "+str(time()-tic))
    print(z)
    --