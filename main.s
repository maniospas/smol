@include std

service test()
    buf = buffer(0,1,2,3,4)
    buf[0:u64]:put(200)
    -> buf

service main()    
    iterator = test()
    sum = 0 while iterator:len:bool sum = iterator:i64:add(sum) --
    print(sum)
    --