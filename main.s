@include std

service addmut(i64 &v1, i64 &v2)
    v1 = v1:add(v2)
    --

service main()
    v1 = 1
    v2 = 2
    addmut(v1,v2)
    print(v1)