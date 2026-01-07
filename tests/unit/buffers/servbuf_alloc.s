@include std.core
@include std.mem

service samples()
    buf = u64[Heap.allocate(1024)]
    .push(42)
    .push(10)
    return buf // return statement

service main()
    @mut buf = samples()
    print(buf[0]) // prints 42