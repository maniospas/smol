@include std.builtins

service read_name(arena arn)
    print("What's your name?")
    &name = "":str
    while name:len == 0 name = read(arn)
    --->name

service main()
    arn = memory.heap:arena(1024)   // arena allocator on the heap
    name = read_name(arn)
    print("Hi "+name+"!")
    --

