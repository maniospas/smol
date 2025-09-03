@include std.builtins

smo data(u64 id, u64[] &values) 
    -> @struct

service main()
    &vals = u64[]:push(1):push(2)
    print(vals[0])
    &p = data[]:push(data(1, vals))
    print(p[0].values[0])
    --
