@include std.builtins
@include std.map


service main() 
    on Stack:allocate_arena(10000) // create an arena, automatically add as first argument
        s = "123":str:copy
        &map = Map(100, str, u64) // flatmap with 100 slots
        --
    map:put(s, 1)
    print(map["123"])
    --
