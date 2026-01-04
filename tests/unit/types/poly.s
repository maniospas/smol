@include std.core

def vec2d(new, u64 x, u64 y)
    return @args 

def vec3d(new, vec2d super, u64 z)
    return @args

def norm(vec2d v)
    return (v.x*v.x)+(v.y*v.y)

service main()
    v = new.vec3d(new.vec2d(1,2),3)
    print(v.super.norm())
    