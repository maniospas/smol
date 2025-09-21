@include std.core
@include std.vec
@include std.mem
 
service main() 
    // add the stack as first argument to 
    // random vector constructors (those 
    // expect an allocator)
    rand = Rand(10)
    on nominal:Stack
        a = rand:vector(10)
        b = rand:vector(10)
        c = rand:vector(10)
        return ended
    // operator results in a preallocated vector 
    // that is eventually returned (only one 
    // allocation but we need operations to apply
    // sequentially)
    result = on Stack:vector(10) return (a*b*c)+a+b+c
    print(result)

