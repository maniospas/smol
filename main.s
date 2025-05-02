@include std

smo main()
    buf = buffer(0,1,2,3,4,5)
    slice = buf[u64(1):u64(3)]
    slice
        | i64()
        | print()
    print(i64(buf[u64(0)]))
    print(i64(buf))
    print(i64(slice))
    print(i64(slice))
