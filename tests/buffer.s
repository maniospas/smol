@include std.builtins


smo test(buffer buf)
    print(buf:len)
    --


service main()
    x = buffer(1,2,3)
    test(x)
    --

    