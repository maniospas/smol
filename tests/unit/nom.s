@include std.core
@unsafe

smo point(nominal type, u64 x, u64 y)
    z = 0
    return @args, z

smo print(point p)
    print(p.x)
    print(p.y)
    print(p.z)
    end

service main()
    p = nominal:point(1,2)
    print(p.type,1,2,2)
    end
