@include std.core
@include std.mem
@include std.time

def Frame(u64 n, u64 a, u64 b)
    return @args

service main()
    n = 42
    tic = time()

    @mut stack = Frame[].push(Frame(n, 0, 1))
    @mut result = 0

    while stack.len().bool()
        f = stack.pop()
        if f.n.bool()
            stack = stack.push(Frame(f.n-1, f.b, f.a + f.b))

    printin("Fibonacci result:")
    print(f.a)
    print(time() - tic)
