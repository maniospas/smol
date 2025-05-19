@include std.builtins
@include std.vec
@include std.time


union Elements (vec, f64)
smo first(Elements elements)
    with 
        // currying notation calls `vec(element)`
        // `with` guards against missing types 
        // moves to the mandatory else if missing type
        // if there are missing types there too, an error is created
        elements:vec // "proves" that elements.size and elements:at can run
        if elements.size==0:u64 fail("No first element") --
        value = elements:at(0:u64) 
        --
    else value = elements --
    -> value // imperative way to declare the return value for simplicity

service main()
    n = 100000:u64
    x1 = vec:rand(n)
    x2 = vec:rand(n)
    tic = time()
    z = dot(x1,x2)
    print("Elapsed \{time()-tic} sec")
    print(first(z))
    --
