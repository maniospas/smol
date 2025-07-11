@include std.builtins
@include std.file
@include std.mem
@include std.map

smo tokenize(Memory &memory, File& f)
    program_size = 100000
    map_size = 1000

    space = " ":str.first
    endl = "\n":str.first
    slash = "/":str.first
    lpar = "(":str.first
    rpar = ")":str.first

    &names = memory:Map(map_size, u64, str)
    &names2tokens = memory:Map(map_size, str, u64)
    &tokens = memory:allocate(program_size, u64)
    &num_tokens = 0

    Stack
        :read(f, 4096)
        :while next_line(str &line)
            &pos = 0
            &prev = 0
            while pos<line:len
                @next pos = pos+1
                if(line[pos]==slash)and(pos<line:len-1)and(line[pos+1]==slash) |--
                if(line[pos]==space)or(line[pos]==endl)or(line[pos]==lpar)or(line[pos]==rpar)
                    @next prev = pos+1
                    if prev<pos 
                        @next num_tokens = num_tokens + 1
                        token = line[prev to pos]
                        if names2tokens:has(token):not
                            tokens:put(num_tokens, names:len+1)
                            names2tokens:put(token, names:len+1)
                            names:put(names:len+1, token)
                            --
                        else 
                            tokens:put(num_tokens, names2tokens:at(token))
    -----------> tokens, num_tokens, names, names2tokens


service main()
    path = "tests/main.s"
    tok = Heap
        :allocate_arena(1000000)
        :tokenize(path:File)
    range(tok.num_tokens)
        :while next(u64& i) 
            print(tok.names[tok.tokens[i]])
    ----