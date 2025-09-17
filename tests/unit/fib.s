@include std.core -> Number
@include std.time -> sleep
@include std.mem -> Heap

service fib(u64 n)
    if n<2
        |-> 1
    -> fib(n-1)+fib(n-2)

service main()
    print(1:fib)
    print(2:fib)
    print(3:fib)
    --