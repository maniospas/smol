@include std.builtins

service main()
    &pos = 0
    &r = range(10)
    next(r, u64& i)
    print(i)
    print(pos)
    next(r, i)
    print(i)
    print(pos)