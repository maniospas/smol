@include std

service test()
    buf = buffer(1,2,3)
    print(buf:i64)
    fail("test")
    -> buf

service main()
    buf2 = test()
    if buf2:len:bool
        print(buf2:i64)
        print(buf2:f64)
    --
