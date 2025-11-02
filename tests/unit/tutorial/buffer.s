// main.s
@include std.core
@include std.time

def data(u64 id, u64[] values) 
    return @args

service test(u64[] v)
    sleep(0.0)
    printin("size")
    print(v.len())

service main()
    @mut vals = u64[]
    .push(1)
    .push(2)

    range(100000)
    .while next(@mut u64& i)
        vals.push(i)

    p = data[]
    .push(data(10, vals))

    print(p[0].id)
    print(p[0].values[0])
    print(vals[0])