@include std.builtins

service main()
    @mut pos = 0
    @mut r = range(10)
    next(r, @mut u64 i)
    print(i)
    print(pos)
    next(r, i)
    print(i)
    print(pos)
    --