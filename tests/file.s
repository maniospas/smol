@include std.builtins
@include std.file

service main()
    endl = "\n":str[0]
    on File("README.md")
        Stack
        :allocate_volatile(1024)
        :while next_line(str &line)
            if line[line:len-1] == endl 
                line = line[0 to line:len-1]
                --
            print(line)
    ----
