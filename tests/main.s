@include std.builtins
@include std.mem  -> memory
@include std.file -> file, chunks, next



service main()
    f = file("README.md")
    nom
    :chunks(f, 4096, memory.heap)
    :while next(str chunk) 
        print(chunk)
    ----
