@include std.core
@include std.mem

service test(u64 n, u64 last)
    Stack:arena(1024)
    print(n)
    if n==last
        |return @args
    ret = test(n+1, last)
    return ret.n, ret.last


service main()
    test(1, 0)
    end