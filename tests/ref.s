@include std.builtins
@include std.mem

service main()
    &memory1 = Heap:allocate_arena(100) // & indicates mutable variable
    &memory2 = memory1

    test1 = memory1:copy("123":str)
    test2 = memory2:copy("456":str)
    print(test1)  // prints 456
    --
