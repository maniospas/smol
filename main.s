@include std

service square(f64 x) 
    fail("Don't wanna!") // manually fail
    -> mul(x,x)
service main()
    y = square(2.0)
    if(y.err:bool) print("Something went wrong") --
    else print(y) --
    --