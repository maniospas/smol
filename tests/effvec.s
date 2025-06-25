@include std.builtins
@include std.vec
@include std.mem
 
service main() 
    // add the stack as first argument to 
    // random vector constructors (those 
    // expect an allocator)
    on nom:Stack
        a = rand(10)
        b = rand(10)
        c = rand(10)
        --
    // operator results in a preallocated vector 
    // that is eventually returned (only one 
    // allocation but we need operations to apply
    // sequentially)
    result = on Stack:Vec(10) -> (a*b*c)+a+b+c
    print(result)
    --

