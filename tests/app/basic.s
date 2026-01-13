@include std.core.num

service main()
    x = f64(1)
    args = x,f64(2)
    args = f64(3),f64(3)
    //print(args.x)
    foo = add(args)
    print(foo)
    print(f64(1))
