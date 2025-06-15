@include std.builtins
@include std.file
@include std.mem -> memory

smo tokenize(file& f)
    tokens = buffer()
    token = "":str
    space = " ":str.first
    endl = "\n":str.first
    slash = "/":str.first
    nom
    :lines(f, 4096, memory.stack)
    :while next(str line)
        pos = 0
        prev = 0
        while pos<line:len
            if(line[pos]==slash)and(pos<line:len-1)and(line[pos+1]==slash) ->-
            if(line[pos]==space)or(line[pos]==endl)
                if prev<pos 
                    print(line[prev to pos])
                    tokens:append(line[prev to pos])
                    --
                prev = pos+1
            --
            pos = pos+1
    ------


service main()
    path = "tests/main.s"
    tokenize(path:file)
    --