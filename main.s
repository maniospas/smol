@include std.builtins

smo Point(align, f64 x, f64 y) -> @new

service main()
    buf = buffer(align, 1.0, 0)
    buf2 = buf:buffer
    print(buf[1:u64]:f64)
    print(buf2[1:u64]:f64)
    --
