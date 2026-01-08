@include std.core
@include std.mem

service test(@own str s)
    @on Heap.allocate(1.KB()).arena()
    return s,1 // todo: if we don't add ,1 the code fails to synchronize, copying also fails

service main()
    print("start")
    @mut s = "123".str()
    s2 = test(s)
    print(s2.s)