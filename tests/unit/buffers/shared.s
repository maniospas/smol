@include std.core
@include std.mem

service test(str[] test)
    print(test[0])


service main()
    @mut contents = Heap.allocate(1024)
    char[contents]
    .push("h".str().first)
    .push("i".str().first)
    print(contents.str(2))

    char[contents].expect(4).put(0, "H".str().first)
    print(contents.str(2))

    // our contract by functions is that they may not change mutables, so we are fine
    // def functions run sequentially, so it's also safe to 
    @mut memory = Heap.allocate(1024)
    @mut b1 = str[memory].push(str("hi"))
    @mut b2 = str[memory].expect(1) // creates a double free :-(
    test(b2)
    b1.push(str("h2")) // we have passed a mutable pointer
    print(b2[0])