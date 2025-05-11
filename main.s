@include std

smo add2(str v1, str v2)
    v1 = v1:add(v2)
    -> v1

service main()
    r1 = "aa":str
    r2 = "bb":str
    r1 = add2(r1,r2)
    print(r1)
