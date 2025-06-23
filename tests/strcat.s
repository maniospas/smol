@include std.builtins

service main()
    arn = memory.heap:arena(1024)   // arena allocator on the heap

    print("What's your name?")
    &name = "":str
    while name:len == 0 name = read(arn) --
    print("Hi "+name:str+"!")
    --
