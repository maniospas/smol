@include std.core

smo Point(u64 _x, u64 _y)
    @mut x = _x
    @mut y = _y
    return x,y

service main()
    p = Point(1,2)
    //print(p.x) // we are not allowed to access p.x
    --