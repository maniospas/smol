@include std.builtins
@include std.mem

smo test()
    allocated = nom:allocate(stack, 128, f64)
    -> allocated

service main()
    s = test()
    --