@include std.core
    return print

service samples()
    buf = u64[]
    .push(42)
    .push(10)
    return buf // return statement

service main()
    buf = samples()
    print(buf[0]) // prints 42
