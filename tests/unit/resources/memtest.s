@include std.core
@include std.mem
@include std.file

def test(@mut File file)
    @on Heap.allocate(32).circular()
    while file.next_chunk(@mut str chunk) 
        printin(chunk)
    print("")

service main()
    ReadFile
    .open("README.md")
    .test()
    return ok
