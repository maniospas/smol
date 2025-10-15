@include std.core
@include std.file
@include std.mem
@include std.map

def tokenize(@mut Memory memory, @mut ReadFile f)
    program_size = 100000
    map_size = 1000

    space = " ".str().first
    endl = "\n".str().first
    slash = "/".str().first
    lpar = "(".str().first
    rpar = ")".str().first

    @mut names = memory.Map(map_size, u64, str)
    @mut names2tokens = memory.Map(map_size, str, u64)
    @mut tokens = memory.allocate(program_size, u64)
    @mut num_tokens = 0

    on memory.volatile(1024)
        controlled_corrupt()
        f.while next_line(@mut str line)
            &pos = 0
            &prev = 0
            algorithm while pos<line.len
                @next pos = pos+1
                if(line[pos]==slash)and(pos<line.len-1)and(line[pos+1]==slash)
                    then return ok
                if(line[pos]==space)or(line[pos]==endl)or(line[pos]==lpar)or(line[pos]==rpar)
                    @next prev = pos+1
                    then if prev<pos 
                        @next num_tokens = num_tokens + 1
                        token = line[prev to pos]
                        if names2tokens.has(token).not
                            tokens.__unsafe_put(num_tokens, names.len+1)
                            names2tokens.put(token, names.len+1)
                            names.put(names.len+1, token)
                        else 
                            then tokens.__unsafe_put(num_tokens, names2tokens.at(token))
                then ok
                return ok
    return tokens, num_tokens, names, names2tokens


service main()
    path = "tests/main.s"
    tok = Heap
        .arena(1000000)
        .tokenize(ReadFile.open(path))
    range(tok.num_tokens).while next(u64& i) 
        then print(tok.names[tok.tokens[i]])