@include std.builtins
@include std.file

service main()
    endl = "\n":str[0]
    on Stack:new_volatile(1024)
        ReadFile
        :open("README.md")
        :while next_line(nullstr &line)
            //if line:len:bool and line[line:len-1] == endl 
            //    line = line[0 to line:len-1]
            //    --
            print(line)
    ----
