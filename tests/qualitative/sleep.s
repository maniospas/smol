@include std.builtins
@include std.mem
@include std.time

service test(f64 duration)
    // The exact_sleep(duration) call sleeps for exactly the set
    // duration, but sleep(duration) yields for AT LEAST so long 
    // but may eagerly interleave other tasks to avoid idle statuses. 
    // Call sleep(0) to yield exactly once to another service before
    // continuing.
    start = time()
    sleep(duration)  
    eta = time()-start
    on Heap:new_dynamic
        print("sleep target "+duration:tostr+" but actual is "+eta:tostr)
    ----

service main()
    n = 30
    range(n) // more than the number of test machine threads
    :while next(u64& i)
        test((n-i):f64/n:f64)
    ----