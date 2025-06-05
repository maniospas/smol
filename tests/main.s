@include std.builtins
@include std.mem
@include std.file


service main()
    f = file("README.md")
    nom:chunks(f, 4096, stack):while next(str chunk) print(chunk)
    ----