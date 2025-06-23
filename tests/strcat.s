@include std.builtins

service main()
    print("What's your name?")
    &name = buildstr(24)
    while name:len == 0 
        name:read
        --
    print(name:str)
    --