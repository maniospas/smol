@include std.builtins
@include std.map


service main()
    // Dynamic memory is a bunch of heap memory allocations that are deallocated together.
    // We are using this for the whole map because it's better suited to managing strings
    // of potentially unknown sizes.
    &map = Dynamic:Map(1000, str, u64)

    // `on` adds some volatile memory as the first argument to functions needing it. Volatile 
    // memory could be corrupted at any point; good for single temporary vars.
    // controlled_corrupt allows corruptions only when it's called; good for multiple allocations.
    on Stack:allocate_volatile(32)
        range(100)
        :while next(u64& i)
            i = i%10
            key = "entry "+tostr(i) // the happen on volatile
            map:put(key, i)         // map is using its contructor's allocator to manage internal state
            controlled_corrupt()
    ----
    print(map["entry 2"])
    --
