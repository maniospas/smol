@include std.builtins

service test(u64 x)
    -> print(x)


service main()
    test(0)
    test(1)
    test(2)
    test(3)
    --