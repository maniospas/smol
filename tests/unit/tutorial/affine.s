@include std.core

def affine(f64 x, f64 y, f64 z) 
    return (x+y)*z

service main()
    result = affine(1.0, 2.0, 3.0)
    print(result)