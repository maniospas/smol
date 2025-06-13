@include std.builtins
@include std.buildstr
@include std.math -> log // import specific name

service main()
    n = 10
    max_chars_per_number = u64(n:f64:log/10.0:log)+2
    builder = nom:buildstr(n*max_chars_per_number)

    range(n):while next(u64 i)
        builder:push(i)
        builder:push(" ":str)
        --
    print(builder:str)
    --
