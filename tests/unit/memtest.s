@include std.core
@include std.mem
@include std.file

smo test(@mut File file)
    on Heap:volatile(32)
        file
        :while next_chunk(@mut str chunk) 
            printin(chunk)
        end
    print("")
    end

service main()
    ReadFile
    :open("README.md")
    :test
    end
