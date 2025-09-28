@include std.core

service test(u64 n, u64 last)
    if n==last
        fail("loop ended")
        |return @args
    return test(n+1, last)

service main()
    value = test(1, 0)
    print(value.n)
    end
