@include std.core

service main()
    print(1+2)      // 3
    print(2/3)      // integer division (u64): 0
    print(2.0/3.0)  // float division (f64): a decimal result
    minus_one = i64(0)-i64(1)
    print(minus_one) // -1