@include std.builtins
@include std.rand

service main()
    rand = Rand()
    range(10):while next(u64 &i)
        print(rand:next)
        print(rand:next)
    ----