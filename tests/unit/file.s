@include std.core
@include std.file

service main()
    endl = "\n".str().first // get `\n` as a character
    on Stack.volatile(1024)
        ReadFile
        .open("README.md")
        .while next_line(str &line)
            if line.len().bool() and line[line.len()-1]==endl 
               line = line[0 to line.len()-1]
               end
            print(line)
    end end end
    