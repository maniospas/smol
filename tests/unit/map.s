@include std.core
@include std.mem
@include std.map

service map_printer(Map map)
    with map.Keys.is(str)
        print(map["123"])

service main() 
    on Heap.dynamic() // create an arena, automatically add as first argument
    s = "123".str().copy()
    @mut map = Map(100, str, u64) // flatmap with 100 slots
    map:put(s, 1)
    map:map_printer // cannot put afterwards because mutables passed to services become immutable
