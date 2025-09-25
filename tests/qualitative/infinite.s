@include std.core

service test(u64 n, u64 last)
    print(n)
    if n==last
        fail("loop ended")
        |return @args
    return test(n+1, last)

service main()
    value = test(1, 10)
    print(value.n)
    end
