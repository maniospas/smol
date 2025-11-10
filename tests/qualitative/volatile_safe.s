@include std.core
@include std.mem


service main()
    on Stack.circular(12) // run operations on circular buffer on the stack
    print("aa"+"1234"+"567")