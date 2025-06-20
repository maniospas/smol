@include std.builtins
@include std.mem
@include std.file

service test()
    path = "README.md":str
    // this will fail if we create a chunk on the stack
    -> nom:chunks(path:file, 4096, heap)

service main()
    test()
    :while next(str& chunk)
        print(chunk)
    ----
