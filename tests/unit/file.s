@include std.builtins
@include std.file

service main()
    endl = "\n":str[0]
    on Stack:volatile(1024)
        ReadFile
        :open("README.md")
        :while next_line(str &line)
            if line:len:bool and line[line:len-1] == endl 
               line = line[0 to line:len-1]
               --
            print(line)
    ----
