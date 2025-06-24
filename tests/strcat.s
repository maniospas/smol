@include std.builtins

smo read_name()
    arn = memory.heap:arena(1024)   // arena allocator on the heap
    print("What's your name?")
    name = read(arn)
    -> name

service main()
    name = read_name()
    print("Hi "+name+"!")
    --

