@include std.builtins
@include std.vec
@include std.mem

smo one_hot(Memory &memory, u64 pos, u64 size)
    // Create intermediate (imd) vector as 
    // context and use it as first argument 
    // when needed. Intermediate values not
    // assigned to variables can be passed
    // as mutable arguments by design.
    -> on memory:Vec(size)
        // `:` is curries the left hand side
        // into the next call's first argument.
        // But we also have the vector context,
        // so `set(Vec&, u64, f64)` is called.
        // The latter returns the intermediate 
        // vector and we return that from `on` 
        // whose outcome is in turn returned 
        // by `one_hot`.
        -> pos:set(1.0)

service main() 
    &memory = Stack:allocate_arena(1024)
    // `on` context adds a first argument as needed (e.g. could use `on nom:Heap`)
    on memory 
        a = one_hot(1, 10)
        b = one_hot(1, 10)
        print(a*b) // calls add(Memory&, Vec, Vec)
    ----

