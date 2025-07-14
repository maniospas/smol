@include std.builtins

service main()
    &pos = 0
    next(range(10), u64& i)
    print(i)
    print(pos)