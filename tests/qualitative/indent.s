@include std.core

service main()
    range(5)
    .while next(@mut u64 i)
        print(i)
    print("the end")