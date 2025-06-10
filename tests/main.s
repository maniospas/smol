@include std.builtins
@include std.mem  -> memory
@include std.file -> file, next, lines, ended

service main()
    f = file("README.md")
    endl = "\n":str.first
    nom
    :lines(f, 4096, memory.heap)
    :while next(str line)
        if line:len:bool and (line[line:len-1]!=endl) and f:ended:not -> fail("Line exceeded character limit")
        printin("line: ")
        printin(line)
        --
    print("")
    --
