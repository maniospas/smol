@include std.builtins
@include std.file

service main()
    endl = "\n":str[0]
    on ReadFile:open("README.md")
        Stack
        :new_volatile(1024)
        :while next_line(str &line)
            if line:len:bool and line[line:len-1] == endl 
                line = line[0 to line:len-1]
                --
            print(line)
    ----
