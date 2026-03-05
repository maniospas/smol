@include std.core

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