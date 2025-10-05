@include std.core
@include std.mem

service main()
    p = str[].expect(2)
    print(p[0])
    print(p[1])