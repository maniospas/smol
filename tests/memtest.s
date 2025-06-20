@include std.builtins
@include std.mem
@include std.file

smo test(String path)
    // this will fail if we create a chunk on the stack
    -> nom:chunks(path:file, 4096, heap)

service main()
    test("README.md")
    :while next(str& chunk)
        print(chunk)
    ----
