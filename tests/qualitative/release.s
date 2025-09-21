// this file demonstrates various errors that are correctly created

@include std.core
@include std.map
@include std.mem


service test() 
    @mut mem = Heap:arena(10000)
    @mut mapon = on mem
        s = "123":str:copy
        return map(100, str, u64)
    @release mem
    map:put(s, 1) // ERROR - mem used in map has been released
    print(map["123"])
    return map // ERROR - even if we comment the above two lines, we wouldn't be able to return something with a released segment

service main()
    test()