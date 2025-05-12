@include std

smo popstr(str value) -> value

service main()
    buf = buffer(str("hi"))
    s = buf:popstr
    print(s)
    print(s:len)
    --
