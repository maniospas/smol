@include std.core

service test(u64 n, u64 last)
    if n==last
        return @args
    ret = test(n+1, last)
    return ret.n, ret.last

service main()
    value = test(1, 0)
    if value.err.bool()
        print("We got an error message, so are entering this block")
        print(value.n)
        print("This message should never appear - value.n creates 'Unhandled error'")
    print(value.n)
