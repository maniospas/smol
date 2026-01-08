@include std.core
@include std.mem
@include std.time

service test(@own f64 duration)
    // The exact_sleep(duration) call sleeps for exactly the set
    // duration, but sleep(duration) yields for AT LEAST so long 
    // but may eagerly interleave other tasks to avoid idle statuses. 
    // Call sleep(0) to yield exactly once to another service before
    // continuing.
    start = time()
    sleep(duration)
    eta = time()-start
    @on Heap.allocate(512).circular()
    printin(@all "sleep target "duration" but actual is "eta"\n")

service main()
    n = 30      // can comfortable go up to 100000
    range(n)    // more than the number of test machine threads
    .while next(u64& i)
        test((n-i).f64()/n.f64())
    