@include std.core return Number
@include std.time return sleep, time

service fib(u64 n) 
    // it is very inefficient to set up this as a service
    // the main premise of services is that they're slow to start but safe for large operations
    if n<=2 
        return 1
    return fib(n-1).add(fib(n-2))

service main()
    print("service computation")
    tic = time()
    fib(5).print()
    print(time()-tic)
