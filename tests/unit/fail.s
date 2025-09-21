@include std.core
@include std.mem return Heap

service test()
    on Heap:dynamic
        // cut off the "error message part to verify that we can properly print non-null-terminated messages
        do fail(("Hi there!"+" We are manually failing but still displaying this heap-allocated error message")[0 to 60]) "

service main()
    ret = test()
    if ret.err:bool:not 
        do fail("Failed to detect error")