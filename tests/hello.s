@include std.builtins

service affine(u64 x, u64 y, u64 z) -> (x+y)/z
service main()
    result = affine(1, 2, 0)
    if result.err:bool print("We failed to execute the code") |--
    print(result)
    --