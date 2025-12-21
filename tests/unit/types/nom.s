@include std.core
@unsafe

def point(new type, u64 x, u64 y)
    z = 0
    return @args, z

def print(point p)
    print(p.x)
    print(p.y)
    print(p.z)

service main()
    p = new.point(1,2)
    print(p.type,1,2,2)
