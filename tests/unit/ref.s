@include std.builtins
@include std.mem
@unsafe

smo copy_state(Arena &arena) -> arena  // this is a workarround to dodge the @noborrow constraint of arenas when @unsafe is enabled

service main()
    &memory1 = Heap:new_arena(100) // allocate 100 bytes, & indicates a mutable variable
    &memory2 = copy_state(memory1) // we could only define this previously thanks to @unsafe

    test1 = memory1:copy("123":str)
    test2 = memory2:copy("456":str)
    print(test1)  // prints 456
    --
