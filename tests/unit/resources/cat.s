@include std.core
@include std.mem

service main()
    name = "there"
    @on Heap.dynamic()
    greeting = add(@all "Hi "name"!")
    print(greeting)
    printin(@all "Hello, I'm "name".\n") // does not use any memory
