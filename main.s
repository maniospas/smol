@include std

union Type(i64, f64, u64)

smo Point(Type x, Type y) -> x,y
smo print(Point p)
    print(p.x)
    --


smo main()
    value = f64(1)
    p = Point(value, value)
    print(p)
