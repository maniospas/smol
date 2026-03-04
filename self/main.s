@include std.core
@include std.file
@include std.mem
@include std.map
@include self.utils

def Tokens(@mut Arena memory, u64 map_size)
    @mut name2id = new.StringHash(map_size)
    @mut names = str[].expect(map_size)
    @mut contents = u64[]
    return name2id, names, contents, memory

def push(@access @mut Tokens tokens, AllocatedString _token)
    @on tokens.memory
    token = str.copy(_token)
    id = tokens.name2id[token]
    tokens.names[id] = token
    tokens.contents.push(id)

def push(@access @mut Tokens tokens, cstr _token)
    token = _token.str()
    id = tokens.name2id[token]
    tokens.names[id] = token
    tokens.contents.push(id)

def len(@access @mut Tokens tokens)
    return tokens.contents.len()

def at(@access @mut Tokens tokens, u64 i)
    id = tokens.contents[i]
    return tokens.names[id]

def tokenize(@mut Arena memory, @mut ReadFile source)
    @mut tokens = Tokens(memory, 50000) // up to 50k different tokens, takes care of copying the tokens in the memory
    SYMBOLS = " \\/()@,.+-*\"'=!"
    SPACE = " ".first()
    TAB = "\t".first()
    SLASH = "\\".first()
    @on memory.allocate(1.MB()).circular() // 1 MB per line max
    while source.next_line(@mut str line)
        @mut pos = 0
        skip(line, pos, SPACE)
        skip(line, pos, TAB)
        @mut prev = pos
        range(pos, line.len())
        .while next(pos) 
            algorithm
                if (line[pos]==SLASH) and (line.len()>pos+1) and (line[pos+1]==SLASH)
                    pos = line.len()
                    prev = line.len()
                    return ok
                if line[pos].in(SYMBOLS).not()
                    return ok
                if pos>prev+1
                    tokens.push(line[prev to pos])
                if line[pos]!=SPACE
                    tokens.push(line[pos upto pos])
                prev = pos+1       
        if prev<pos
            tokens.push(line[prev to pos])
    return tokens

service main()
    @on Heap.allocate(10.MB()).arena()
    path = "tests/app/file.s"
    @mut tok = tokenize(ReadFile.open(path))
    printin(@all "Number of tokens: "tok.len()"\n")
    tok.len().range()
    .while next(@mut u64 i)
        print(tok[i])
    