@include std.builtins

smo Type1(align, f64 value) -> @new
smo Type2(align, f64 value) -> @new

smo recognize(Type1 p) print("this is Type1") --
smo recognize(Type2 p) print("this is Type2") --

service main()
    p1 = align:Type1(1.0)
    p2 = align:Type2(2.0)
    recognize(p1) 
    recognize(p2) 
    --
