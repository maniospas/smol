@include std.core
@include std.file
@include std.mem
@include std.map

def skip(str line, @mut u64 pos, char c)
    range(pos, line.len())
    .while next(pos)
        if line[pos]!=c
            return ok

def in(char c, String _line)
    line = _line.str()
    line.len().range()
    .while next(@mut u64 pos)
        if line[pos]==c
            return true
    return false

def first(cstr c)
    return c.str().first

def grow_for_index(@mut str[] names, u64 id)
    if id>=names.len()
        names.expect((id-names.len())+1)

def tokenize(@mut Arena memory, @mut ReadFile source)
    map_size = 1024*1024
    @mut name2id = new.StringHash(map_size)
    @mut names = str[]
    @mut tokens = u64[]
    @on memory
    while source.next_line(@mut str line)
        @mut pos = 0
        skip(line, pos, " ".first())
        @mut prev = pos
        range(pos, line.len())
        .while next(pos) 
            algorithm
                if line[pos].in(" \\\n/()@,.").not()
                    return ok
                if prev>=pos
                    return ok
                token = line[prev to pos]
                id = name2id[token]
                names.grow_for_index(id)
                names[id] = token
                tokens.push(id)
                prev = pos+1
    return tokens, names, name2id

service main()
    path = "tests/app/file.s"
    @access @mut tok = Heap.allocate(10.MB()).arena().tokenize(ReadFile.open(path))
    printin(@all "Number of tokens: "tok.tokens.len()"\n")
    tok.tokens.len().range()
    .while next(u64& i) 
        id = tok.tokens[i]
        print(tok.names[id])
    