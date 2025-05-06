@include std

service square(f64 x) 
    fail("Don't wanna!")
    -> mul(x,x)

service main()
    y = square(2.0)
    if(y.err|bool())
        print("error")
        y = 0.0
        --
    print(y)
