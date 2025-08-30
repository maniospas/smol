@include std.builtins
@include std.map

service map_printer(Map map)
    with 
        map.Keys:is(str) 
        map.Values:is(u64)
        --
    //map:put("123", 2) // ERROR - map is immutable, but put requires mutability
    //&mutmap = map // ERROR - cannot transfer immutable pointers
    //mutmap:put("123", 2) 
    print(map["123"])
    --

service main() 
    on Heap:new_dynamic // create an arena, automatically add as first argument
        s = "123":str:copy
        &map = new_map(100, str, u64) // flatmap with 100 slots
        --
    map:put(s, 1)
    map:map_printer // cannot put afterwards because mutables passed to services become immutable

    --
