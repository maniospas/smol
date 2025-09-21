@include std.core
@include std.mem

def Segment(nominal, str value)
    return @args // return all inputs

def Segment(String _value)
    value = _value:str // convert from many string types
    return nominal:Segment(value)

def combine(Segment[] segments)
    @mut combined = "":str  // mutable null-terminated string
    on Stack:arena(1024)
        range(segments:len)
        :while next(@mut u64 i) 
            combined = str(combined+segments[i].value+" ")
            end
        end
    return combined

service main()
    segments = Segment[] // buffer
    :push("I think.":Segment)
    :push("Therefore I am.":Segment)
    print(segments:combine)

