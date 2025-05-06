@include std

service square(f64 x) 
    if(x<=(0.0))
        fail("Don't wanna!")
        --
    -> mul(x,x)
service zero() -> 0.0


service main()
    x = f64|read()
    y = square(x)
    if(y.err|bool())
        y = zero()
        --
    print(y)
