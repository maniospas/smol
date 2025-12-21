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
    name = Heap.allocate(24).arena().read_name()
    
    @on Heap.dynamic()
    print(add(@all"Hi "name"!"))
    
    @on Stack.dynamic()
    print(add(@all"Hi "name"!"))

    @on Heap.allocate(1.KB()).arena()
    print(add(@all"Hi "name"!"))

    @on Stack.allocate(1.KB()).arena()
    print(add(@all"Hi "name"!"))

    @on Stack.allocate(1.KB()).circular()
    print(add(@all"Hi "name"!"))

    @on Heap.allocate(1.KB()).circular()
    print(add(@all"Hi "name"!"))
    