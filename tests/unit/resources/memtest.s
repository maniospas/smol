@include std.core
@include std.mem
@include std.file

def test(@mut File file)
    on Heap.volatile(32)
    while file.next_chunk(@mut str chunk) 
        printin(chunk)
        end
    print("")
    end

service main()
    ReadFile
    .open("README.md")
    .test()
    end
