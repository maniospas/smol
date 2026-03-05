@include std.core
@include std.mem

service main()
    @mut m1 = Heap.allocate(1.KB())
    @mut m2 = Heap.allocate(1.KB())
    @mut ar1 = str[]
    @mut ar2 = str[]

    s1 = m1.arena().copy("test1")
    s2 = m2.arena().copy("test2") // TODO: probably from here

    ar1.push(s1)
    ar1.push(s2)
    @release m1
    print(ar1[0]) // TODO: this should not be possible
    print(ar1[1])