@include std.core
@include std.mem

def read_name(@mut Arena arn)
    return "maniospas"
    // print("What's your name?")
    // &name = "":str
    // while name:len==0 
    //     name = arena:read
    // --return name

service main()
    name = Heap.arena(24).read_name()
    
    @on Heap.dynamic()
    print("Hi "+name+"!")
    
    @on Stack.dynamic()
    print("Hi "+name+"!")

    @on Heap.arena(1024)
    print("Hi "+name+"!")

    @on Stack.arena(1024)
    print("Hi "+name+"!")

    @on Stack.circular(1024)
    print("Hi "+name+"!")

    @on Heap.circular(1024)
    print("Hi "+name+"!")
    