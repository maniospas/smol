@include std.core
@include std.mem :: Heap, KB, arena

service main()
    @mut memory = Heap.allocate(1.KB()).arena()
    s = memory.copy(str, "MYSTRING")
    print(s)
   