@include std.core
@include std.mem
@include std.time

def Frame(u64 n, u64 a, u64 b)
    return @args

service main()
    n = 42
    tic = time()

    // Push initial tail-call state
    @mut stack = Frame[].push(Frame(n, 0, 1))
    @mut result = 0

    while stack.len().bool()
        f = stack.pop()
        if f.n == 0
            // Base case: finished — this returns final result
            result = f.a
        else
            // Tail call step:
            // Instead of replacing the frame, we PUSH the next state.
            // This is a proper trampoline.
            stack = stack.push(Frame(f.n - 1, f.b, f.a + f.b))

    printin("Fibonacci result:")
    print(result)
    print(time() - tic)
