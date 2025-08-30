@include std.builtins
@include std.map

// ALL RELEASES IN THIS FILE SHOULD CREATE ERRORS IF UNCOMMENTED

service test(u64 x) 
    // @release x  // cannot release an argument
    --

service main()
    x = 1
    test(x)
    //@release x  // cannot release a service argument
    --