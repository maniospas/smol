@include std.builtins
@include std.mem

smo read_name(Arena arena)
    //with arena.contents.MemoryDevice:is(Heap)
    print("What's your name?")
    &name = "":str
    while name:len==0 
        name = arena:read
    ---> name

service main()
    arena = Heap:allocate_arena(24)
    name = read_name(arena)
    print("Hi "+name+"!")
    --
