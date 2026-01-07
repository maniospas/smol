@include std.core
@include std.mem

service main()
    @mut mem = Heap.allocate(1024)
    @mut arn = mem.arena()
    @mut allocated = arn.allocate(128)
    @mut x = i64[allocated]
    x.push(1.i64().negative())
    x.push(2.i64().negative())

    @mut chars = arn.allocate(128)
    @mut char_buffer = char[chars]
    char_buffer.push("h".str().first)
    char_buffer.push("i".str().first)
    print(chars.str(3)) // this is SAFE because we have complete control and no out-of-bounds for `chars`


    @mut y = u64[mem].expect(2) // ERROR: mem.arena() transfers ownership to the arena
    print(y[0])
    