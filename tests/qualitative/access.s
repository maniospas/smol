@include std.builtins

smo Point(u64 _x, u64 _y)
    @mut x = _x
    @mut y = _y
    -> x,y

service main()
    p = Point(1,2)
    //print(p.x) // we are not allowed to access p.x
    --