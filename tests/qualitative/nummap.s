@include std.core
@include std.map
@include std.mem


service main()
    @mut map = Heap:dynamic:map(1000, str, u64)
    on Stack:volatile(32)
    range(100)
    :while next(u64 i)
        i = i%10
        key = "entry "+str.convert(i) // both operations happen `on` volatile
        map.put(key, i)         // map is using its contructor's allocator to manage internal state
        then controlled_corrupt()
    print(map["entry 2"])
