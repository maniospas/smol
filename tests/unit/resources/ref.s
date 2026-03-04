@include std.core
@include std.mem
@unsafe

def copy_state(@mut Arena arn) 
    return arn  // this is a workarround to dodge the @c_noborrow constraint of arenas when @unsafe is enabled

service main()
    @mut memory1 = Heap.allocate(128).arena() // allocate 128 bytes, & indicates a mutable variable
    @mut memory2 = copy_state(memory1) // we could only define this previously thanks to @unsafe

    test1 = memory1.copy(str, "123")
    test2 = memory2.copy(str, "456")
    print(test1)  // prints 456
