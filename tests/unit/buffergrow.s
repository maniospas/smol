@include std.builtins
@include std.mem

service main()
    p = u64[]:expect(1)
    print(p[0])
    --