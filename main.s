@include std.builtins

service main()
    x = 1
    if x<0 -> print("negative")
    else if x==1 -> print("unit")
    else -> print("hi?")
    print("test")
    --