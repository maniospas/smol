@include std.core
@include std.mem
@unsafe

smo vec3(f64 x, f64 y, f64 z) 
    return @args

service main()
    // allocate 24 bytes - enough to hold 3x f64
    @mut memory = Heap:allocate(24)  

    // create a buffer on this memory and push a number to it
    f64[memory]:push(1.5)

    // use the same memory in a new buffer of vec3, 
    // grow it to consider one element there 
    // (this keeps data there) 
    buf = vec3[memory]:expect(1)
    print(buf[0].x)
    return ended
