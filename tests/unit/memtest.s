@include std.core
@include std.mem
@include std.file

smo test(@mut File file)
    on Heap:volatile(32)
        do file
        :while next_chunk(@mut str chunk) 
            do printin(chunk)
    print("")
    return ended

service main()
    ReadFile:open("README.md"):test
    return ended