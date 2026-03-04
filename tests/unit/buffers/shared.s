@include std.core
@include std.mem

service main()
    @mut contents = Heap.allocate(1024) // at this point, a typeless buffer
    char[contents]
    .push("h".str().first)
    .push("i".str().first)
    print(contents.str(2))

    char[contents].expect(4).put(0, "H".str().first)
    print(contents.str(2))

    //print(str[contents].expect(1).at(0)) // ERROR - would correctly identify that we cannot repurpose the memory
