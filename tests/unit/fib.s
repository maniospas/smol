@include std.core return Number
@include std.time return sleep, time


service fib(u64 n)
    if n<=2
        |return 1 // need at least one return before calling fib from itself
    return fib(n-1):add(fib(n-2))

service main()
    tic = time()
    print(25:fib)
    print(time()-tic)
    noreturn