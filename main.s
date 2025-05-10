@include std

smo PlanePoint(f64 x, f64 y, f64 z) -> @new
smo PlanePoint(f64 x, f64 y)
    print("Creating new point")
    z = 0.0
    -> PlanePoint(x, y, z)

smo print(PlanePoint a)
    "Point "
        :add(str(a.x))
        :add(", ")
        :add(str(a.y))
        :add(", ")
        :add(str(a.z))
        :print()
    --

service stradd(str s1, str s2)
    -> s1:add(s2)

service main()
    p = PlanePoint(1.0, 2.0)
    print(p)
    p2 = PlanePoint(p)
    print(p)
    --