@include std

smo test()
    buf = buffer(1,2,3)
    print(buf:i64)
    print(buf:f64)
    --

service main()
    buf = test()
    --
