@include std.builtins

service abs(f64 x)
    if 0.0>x |-> 0.0-x
    -> x


service main()
    &message = "hello"
    print(message)
    message = "world"
    print(message)
    --