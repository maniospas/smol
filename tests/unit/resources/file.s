@include std.core
@include std.mem
    return Stack, KB, circular
@include std.file
    return ReadFile

service main()
    end_line = "\n".str().first // get `\n` as a character

    @on Stack.allocate(1.KB()).circular()
    ReadFile
    .open("README.md")
    .while next_line(@mut str line)
        if line.len().bool() and line[line.len()-1]==end_line 
            line = line[0 to line.len()-1]
        print(line)
