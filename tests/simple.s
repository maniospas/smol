@include std.builtins

service test(u64 x)
    -> print(x)

service main()
    range(10)
    :while next(u64& i)
        test(i)
    ----