@include std.builtins
@include std.file
@include std.mem

service main()
    f = file("README.md")
    nom:chunks(f, 4096, heap):while next(str chunk) print(chunk) --
    --
