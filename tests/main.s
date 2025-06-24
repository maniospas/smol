@include std.builtins
@include std.mem
@include std.file

service main()
    file = File("README.md")
    endl = "\n":str.first

    Heap
    :allocate_arena(1024)
    :read(file)
    :while next_line(str &line)
        if line:len:bool and (line[line:len-1]!=endl) and file:ended:not -> fail("Line exceeded character limit")
        printin("line: ")
        printin(line)
        --
    print("")
    --
