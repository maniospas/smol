@include std.core
@include std.mem
@unsafe

smo copy_state(@mut Arena arn) 
    return arn  // this is a workarround to dodge the @noborrow constraint of arenas when @unsafe is enabled

service main()
    @mut memory1 = Heap:arena(100) // allocate 100 bytes, & indicates a mutable variable
    @mut memory2 = copy_state(memory1) // we could only define this previously thanks to @unsafe

    test1 = memory1:copy("123":str)
    test2 = memory2:copy("456":str)
    print(test1)  // prints 456
    return ended
