@include std.builtins
@include std.mem
@include std.file

smo test(String path)
    // If we create a chunk on the stack
    // instead of the heap, the compiler
    // would complain, because we can't
    // leak stack allocations are marked
    // as `@noshare`.
    // A `smo` runtype wouldn't have 
    // this issue because its inlined
    // within calling services.
    -> nom:chunks(path:file, 4096, heap)

smo main2()
    test("README.md")
    :while next(str& chunk)
        print(chunk)
    ----

smo abs(f64 x)
    if x<0.0 print("negative") |-> 0.0-x
    -> x


service main()
    x = f64:read:abs
    print(x)
    --