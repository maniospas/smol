@include std.core

smo vec2d(nominal, u64 x, u64 y)
    return @args 

smo vec3d(nominal, vec2d super, u64 z)
    return @args

smo norm(vec2d v)
    return (v.x*v.x)+(v.y*v.y)

service main()
    v = nominal:vec3d(nominal:vec2d(1,2),3)
    print(v.super:norm)