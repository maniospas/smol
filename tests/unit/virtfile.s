@include std.core
@include std.mem
@include std.file

service main()
    on Heap:dynamic
        do @mut file = WriteFile:temp(1024)
    file:print("hello world!")
    file:to_start
    on Stack:volatile(1024)
        do file:next_line(str& s)
    print(s)