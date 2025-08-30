// this file demonstrates various errors that are correctly created

@include std.builtins
@include std.map


service test() 
    &mem = Heap:new_arena(10000)
    on mem
        s = "123":str:copy
        &map = new_map(100, str, u64)
        --
    @release mem
    map:put(s, 1) // ERROR - mem used in map has been released
    print(map["123"])
    -> map // ERROR - even if we comment the above two lines, we wouldn't be able to return something with a released segment

service main()
    test()
    --