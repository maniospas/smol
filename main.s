@include std.builtins

smo Point(f64 x, f64 y) -> @new

service main()
    buf = buffer(1.0,2.0)
    buf2 = buf:buffer
    buf2[0:u64]:put(0.0)
    print(buf2[0:u64]:f64)
    print(buf[0:u64]:f64)
    --
