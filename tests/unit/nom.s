@include std.builtins
@unsafe

smo point(nominal type, u64 x, u64 y)
    z = 0
    -> @args, z

smo print(point p)
    print(p.x)
    print(p.y)
    print(p.z)
    --

service main()
    p = nominal:point(1,2)
    print(p.type,1,2,2)
    --