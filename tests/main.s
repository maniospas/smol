@include std.builtins
@include std.mem -> Memory, new_arena
@include std.file

smo file_reader(String path, Memory &memory)
    &file = ReadFile:open(path)
    endl = "\n":str.first
    on memory:new_arena(1024)
        file
        :while next_line(str &line)
            if line:len:bool 
            and (line[line:len-1]!=endl) 
            and file:ended:not 
                -> fail("Line size exceeded character limit")
            printin("line: ")
            printin(line)
        ----
    print("")
    --

service main()
    &memory = Stack:new_arena(1000000)
    file_reader("README.md", memory)
    --
