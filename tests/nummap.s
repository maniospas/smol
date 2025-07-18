@include std.builtins
@include std.map


service main()
    &map = Dynamic:Map(1000, str, u64)

    on Stack:allocate_volatile(32)
        range(100)
        :while next(u64& i)
            i = i%10
            key = "entry "+tostr(i) // both operations happen `on` volatile
            map:put(key, i)         // map is using its contructor's allocator to manage internal state
            controlled_corrupt()
    ----
    print(map["entry 2"])
    --
