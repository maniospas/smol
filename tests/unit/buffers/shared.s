@include std.core
@include std.mem

service test(str[] test)
    print(test[0])


service main()
    @mut contents = Heap.allocate(1024) // at this point, a typeless buffer
    char[contents]
    .push("h".str().first)
    .push("i".str().first)
    print(contents.str(2))

    char[contents].expect(4).put(0, "H".str().first)
    print(contents.str(2))

    //print(str[contents].expect(1).at(0)) // ERROR - correctly identifies that we cannot repurpose the memory

    // Our mutability contract is that we cannot use variable names
    // to modify their data, (and NOT guaranteeing that data cannot be
    // modified elsewhere). This means that we can unsafely
    // pass b2 to a different service. Now, the issue comes passing 
    @mut memory = Heap.allocate(1024)
    @mut b1 = str[memory].push(str("there"))
    b2 = str[memory].expect(1) // creates a double free :-(
    test(b2)
    b1.push(str("h2"))
    print(b2[0])