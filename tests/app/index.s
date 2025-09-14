@include std.core
@include std.mem

smo Segment(nominal, str value)
    -> @args // return all inputs

smo Segment(String _value)
    value = _value:str // convert from many string types
    -> nominal:Segment(value)

smo combine(Segment[] segments)
    @mut combined = "":str  // mutable null-terminated string
    on Stack:arena(1024)
        range(segments:len)
        :while next(u64 &i)
            combined = str(combined+segments[i].value+" ")
            --
        --
    -> combined

service main()
    segments = Segment[] // buffer
    :push("I think.":Segment)
    :push("Therefore I am.":Segment)
    print(segments:combine)
    --