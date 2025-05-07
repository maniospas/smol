@include std

service square(f64 x)
    if(x:le(0.0))
        fail("Don't wanna!")
        --
    -> mul(x,x)

service main()
    print("Give me a number to square")
    x = f64:read
    y = square(x)
    if(y.err:bool:not)
        print(y.err) 
        print(y)
        --
 