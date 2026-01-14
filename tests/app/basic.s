@include std.core.num

def test(f64 x)
    sign = 0.0
    if le(x,1.0) 
        return 1.0
    return sign

service main()
    print(test(1.0))