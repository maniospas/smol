@include std.core
@include std.mem

service main()
    @on Heap.allocate(1.KB()).arena()
    print(ncopy("test").memory.cstr()) // correctly prevent pointer field access - needs @unsafe