@include std.builtins
@include std.file
@include std.mem

smo tokenize(Memory &memory, File& f)
    token = "":str
    space = " ":str.first
    endl = "\n":str.first
    slash = "/":str.first
    lpar = "(":str.first
    rpar = ")":str.first

    &tokens = memory:allocate(1000000, u64) // programs are up to 8MB worth of instructions
    &num_tokens = 0

    Stack
    :read(f, 4096)
    :while next_line(str &line)
        &pos = 0
        &prev = 0
        while pos<line:len
            if(line[pos]==slash)and(pos<line:len-1)and(line[pos+1]==slash) |--
            if(line[pos]==space)or(line[pos]==endl)or(line[pos]==lpar)or(line[pos]==rpar)
                if prev<pos 
                    print(line[prev to pos])
                    //tokens:append(line[prev to pos])
                    tokens[num_tokens] = 
                    num_tokens = num_tokens + 1
                    --
                prev = pos+1
            --
            pos = pos+1
    ------


service main()
    path = "tests/main.s"
    Heap:tokenize(path:File)
    --