@include std.builtins
@include std.vec
@include std.mem

smo one_hot(Memory &memory, u64 pos, u64 size)
    -> on memory:Vec(size) // create temp vector and consider that a context to return
        pos:set(1.0)       // `:` is currying, but we already have the temp vector context, so basically `set(temp,pos,1.0)`
        --                 // ends code block

service main() 
    &memory = Stack:allocate_arena(1024) // stack arena allocator
    on memory // pass memory as first argument (including in overloaded operators) if functions not found
        a = one_hot(1, 10)
        b = one_hot(1, 10)
        print(a+b)
    ----
    