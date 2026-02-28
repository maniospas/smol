@include std.core


def in(char c, cstr _line)
    line = _line.str()
    line.len().range()
    .while next(@mut u64 pos)
        printin(@all pos line[pos] c line[pos]==c "\n")
        if line[pos]==c
            return true
    return false

service main()
    print("a".str().first.in("abc"))