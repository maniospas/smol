@include std.builtins
@include std.file
@include std.mem

service reader()
    printin("give a number: ")
    value = f64:read
    -> value

service main()
    @mut messages = str[]
    x = reader()
    x.err:assert_ok
    messages:push("a number indeed: ":str)
    on Heap:dynamic
        messages:push(str(x):str)
        --
    messages:print
    // y = reader() // creates an error - async reading in services not allowed
    --
