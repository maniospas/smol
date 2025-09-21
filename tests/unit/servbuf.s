@include std.core // basic arithmetics, etc

service samples()
    buf = u64[]
    :push(42)
    :push(10)
    return buf // return statement

service main()
    buf = samples()
    print(buf[0]) // prints 42
    -- // end block, buffer is deallocated here

