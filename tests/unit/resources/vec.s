@include std.core
@include std.vec
@include std.mem

def one_hot(@mut Memory memory, u64 pos, u64 size)
    @on memory.vector(size)
    return pos.put(1.0)

service main()
    @mut memory = Stack.arena(1024)
    @on memory
    a = one_hot(1, 10)
    b = one_hot(1, 10)
    print(a*b) // calls add(Memory&, Vec, Vec)
