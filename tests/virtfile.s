@include std.builtins
@include std.mem
@include std.file

service main()
    &file = Heap:allocate_file(1024)
    file:write("hello world!")
    file:to_start
    on Stack:allocate_volatile(1024)
        file:next_line(str& s)
        --
    print(s)
    --