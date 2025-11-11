@include std.core
@include std.file

service main()
    end_line = "\n".str().first // get `\n` as a character

    @on Stack.circular(1024)
    ReadFile
    .open("README.md")
    .while next_line(@mut str line)
        if line.len().bool() and line[line.len()-1]==end_line 
            line = line[0 to line.len()-1]
        print(line)
