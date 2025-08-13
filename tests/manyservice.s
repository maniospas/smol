@include std.builtins

service test3(u64 i)
    print(i)
    --

service test2(u64 i)
    test3(i)
    --

service test(u64 i)
    test2(i)
    --


service main()
    test(0)
    test(1)
    test(2)
    test(3)
    test(4)
    test(5)
    test(6)
    test(7)
    test(8)
    test(9)
    test(10)
    test(11)
    test(12)
    test(13)
    test(14)
    test(15)
    test(16)
    test(17)
    test(18)
    test(19)
    test(20)
    test(21)
    test(22)
    test(23)
    test(24)
    test(25)
    test(26)
    test(27)
    test(28)
    test(29)
    --

    