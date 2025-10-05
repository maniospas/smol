@include std.core
@include std.mem
@include std.file

service main()
    on Heap.dynamic()
    @mut file = WriteFile.temp(1024)
    file.print("hello world!")
    file.to_start()

    on Stack.volatile(1024)
    file.next_line(str& s)
    print(s)
    end