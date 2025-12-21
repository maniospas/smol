@include std.core
@include std.mem 
    return Heap, KB, arena

service main()
    @mut memory = Heap.allocate(1.KB()).arena()
    s = memory.copy("MYSTRING".str())
    print(s)
   