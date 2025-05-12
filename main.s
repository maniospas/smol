@include std

service main()
    name = str:read
    buf = buffer(str("hi"))
    s = buf:str
    print(s)
    print(s:len)
    --
