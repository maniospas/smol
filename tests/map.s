@include std.builtins
@include std.map


service main() 
    s = Heap:copy("123":str)      // forcefully move to heap
    on Heap:allocate_arena(10000) // automatically add the allocator as argument
        &map = Map(100, str, u64) // flatmap with 100 slots
        map:put(s, 1)
        --
    map["123"]:print
    --
