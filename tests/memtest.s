@include std.builtins
@include std.mem
@include std.file

smo test(File &file)
    on Heap:allocate_volatile(32)
        file:while next_chunk(str& chunk)
            printin(chunk)
        ----
    print("")
    --

service main()
    ReadFile:open("README.md"):test
    --