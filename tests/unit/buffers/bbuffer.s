@include std.core

def data(
    u64 id, 
    u64[] values
) 
    return @args

service main()
    @mut vals = u64[]
    .push(1)
    .push(2)
    p = data[]
    .push(data(10, vals))

    print(p[0].id)
    print(p[0].values[0])
    print(vals[0])