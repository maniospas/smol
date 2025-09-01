@include std.builtins
@include std.mem

smo read_name(Arena &arena)
    -> "maniospas"
    // print("What's your name?")
    // &name = "":str
    // while name:len==0 
    //     name = arena:read
    // ---> name

service main()
    name = Heap:arena(24):read_name
    on Heap:dynamic
        print("Hi "+name+"!")
    ----
