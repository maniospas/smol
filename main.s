@include std

smo addmut(str &v1, str &v2)
    v1 = v1:add(v2)
    --

service main()
    r1 = "aa":str
    r2 = "bb":str
    addmut(r1,r2)
    print(r1)
