@include std.core
@include std.mem

smo Segment(nominal, str value)
    return @args // return all inputs

smo Segment(String _value)
    value = _value:str // convert from many string types
    return nominal:Segment(value)

smo combine(Segment[] segments)
    @mut combined = "":str  // mutable null-terminated string
    on Stack:arena(1024)
        do range(segments:len)
        :while next(@mut u64 i) 
            do combined = str(combined+segments[i].value+" ")
    return combined

service main()
    segments = Segment[] // buffer
    :push("I think.":Segment)
    :push("Therefore I am.":Segment)
    print(segments:combine)
    noreturn
    