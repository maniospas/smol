@include std.core
@include std.rand

service main()
    rand = Rand()
    range(10).while next(@mut u64 i)
        print(rand.next())
    end end