@include std.core
@include std.file
@include std.mem
@include std.map

def tokenize(@mut Arena memory, @mut ReadFile source)
    program_size = 100000
    map_size = 1000

    space = " ".str().first
    quote = "\"".str().first
    endl = "\n".str().first
    slash = "/".str().first
    lpar = "(".str().first
    rpar = ")".str().first
    meta = "@".str().first

    N = 1024*1024
    @mut name2id = new.StringHash(N)
    @mut names = str[].expect(N)
    @mut tokens = u64[]

    @on memory
    while source.next_line(@mut str line)
        @mut pos = 0
        if line.len().bool()
            while line[pos]==space
                pos = pos+1
        start_spaces = pos
        @mut prev = pos
        while pos<line.len()
            if(line[pos]==slash)and(pos<line.len()-1)and(line[pos+1]==slash)
                pos = line.len()
            elif(line[pos]==space)or(line[pos]==endl)or(line[pos]==lpar)or(line[pos]==rpar)or(line[pos]==quote)or(line[pos]==meta)
                if prev<pos
                    token = line[prev to pos]
                    id = name2id[token]
                    print(id)
                    print(token)
                    names[id] = token
                    tokens.push(id)
                prev = pos+1
            pos = pos+1
    return tokens, names, name2id


service main()
    path = "tests/app/file.s"
    @access @mut tok = Heap.allocate(10.MB()).arena().tokenize(ReadFile.open(path))
    print(tok.tokens.len())
    tok.tokens.len().range()
    .while next(u64& i) 
        id = tok.tokens[i]
        //print(tok.names[id])