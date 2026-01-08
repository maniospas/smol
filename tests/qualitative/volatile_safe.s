@include std.core
@include std.mem


service main()
    @on Stack.allocate(12).circular() // run operations on circular buffer on the stack
    add(@all "aa".str() "1234".str() "567".str()).print()