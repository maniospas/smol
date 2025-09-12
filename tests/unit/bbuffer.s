@include std.builtins

smo data(u64 id, @mut u64[] values) 
    -> @args

service main()
    @mut vals = u64[]
    :push(1)
    :push(2)
    p = data[]
    :push(data(10, vals))

    print(p[0].id)
    print(p[0].values[0])
    print(vals[0])
    --
