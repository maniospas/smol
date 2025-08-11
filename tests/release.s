@include std.builtins
@include std.map


service main() 
    &mem = Heap:allocate_arena(10000)
    on mem
        s = "123":str:copy
        &map = Map(100, str, u64)
        --
    @release mem
    map:put(s, 1) // ERROR - mem used in map has been released
    print(map["123"])
    --
