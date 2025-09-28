@include std.core
@include std.map
@include std.mem

service map_printer(Map map)
    with 
        map.Keys:is(str) 
        map.Values:is(u64)
        end
    //map:put("123", 2) // ERROR - map is immutable, but put requires mutability
    //&mutmap = map // ERROR - cannot transfer immutable pointers
    //mutmap:put("123", 2) 
    print(map["123"])
    end

service main() 
    @mut m = on Heap.dynamic() // create an arena, automatically add as first argument
        s = "123".str().copy()
        return map(100, str, u64) // flatmap with 100 slots
    m.put(s, 1)
    m.map_printer // cannot put afterwards because mutables passed to services become immutable
    end
