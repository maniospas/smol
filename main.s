@include std.builtins
@include std.vec
@include std.time

smo point(f64 x, f64 y) -> @new
union Elements (vec, point, f64, i64)
smo first(Elements elements)
    with value = elements:vec:at(0:u64) --
    else value = elements:point.x --
    else value = elements:f64 --
    -> value

service main()
    n = 1000000:u64
    x1 = vec:rand(n)
    x2 = vec:rand(n)
    tic = time()
    z = dot(x1,x2)
    print("Elapsed \{time()-tic} sec")
    print(z:first)
    print(point(1.0,2.0):first)
    --
