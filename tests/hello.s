@include std.builtins

service affine(u64 x, u64 y, u64 z) -> (x+y)/z
service main()
    a = u64:read("a=")
    b = u64:read("b=")
    c = u64:read("c=")
    result = affine(a,b,c)
    if result.err:bool print("We failed to execute the code") |--
    printin("(a+b)/c=")
    print(result)
    --