@include std.core return Number
@include std.time return sleep, time

def sign(f64 x)
   s = capture
        if x>0.0 return "positive" 
        return "negative"
    print(s)
    end

service fib(u64 n)
    if n<=2 return 1
    return fib(n-1).add(fib(n-2))

service main()
    print("service computation")
    tic = time()
    fib(25).print()
    print(time()-tic)
    end
