@include std

smo add_service(str v1, str v2) 
    i = 0
    while(i<10)
        v2 = v2:add("c")
        i = i+1
        --
    -> v1:add(v2)

service main()
    r1 = "aa":str
    r2 = "bb":str
    r1 = add_service(r1,r2)
    print(r1)
    