@include std.core

service print_service(u64 x)
    -> print(x)

service main()
    range(10)
    :while next(u64 &i)
        print_service(i)
        --
    --
