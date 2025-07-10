@include std.builtins
@include std.map


service main() 
    s = Heap:copy("123":str)      // forcefully move to heap
    on Heap:allocate_arena(10000) // automatically add the allocator as argument
        &map = Map(100, str, u64) // flatmap with 100 slots
        map:put(s:copy, 1)        // basically copy(arena, s) which is on top of the same memory as map
        --
    map:at("123"):print
    --
