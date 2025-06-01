@include std.builtins
@include std.file
@include std.mem

service main()
    f = file("README.md")
    chunk = "":str
    nom:chunks(f, 4096, heap):while next(chunk) print(chunk) --
    --
