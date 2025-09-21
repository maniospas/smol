@include std.core

service affine(u64 x, u64 y, u64 z) 
    return (x+y)/z
service main()
    printin("a=") a = u64:read
    printin("b=") b = u64:read
    printin("c=") c = u64:read // give 0 occasionally to see failure
    result = affine(a,b,c)
    if result.err:bool print("We failed to execute the code") 
        |return ended
    printin("(a+b)/c=")
    print(result)