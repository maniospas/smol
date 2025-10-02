@include std.core return Number
@include std.time return sleep, time

service fib(u64 n)
    if n<=2
        |return 1
    return fib(n-1).add(fib(n-2))

service main()
    print("service computation")
    tic = time()
    fib(25).print()
    print(time()-tic)
    end
