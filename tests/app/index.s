@include std.core
@include std.mem

def Segment(nominal, str value)
    // return all inputs 
    // function returns are tuples of named elements
    return @args

def Segment(String _value)
    // convert from many string types
    value = _value:str 
    return nominal:Segment(value)

def combine(Segment[] segments)
    @mut combined = "":str  // mutable string with known size
    on Stack:arena(1024)    // automatically use as argument if needed (for string operations)
        range(segments:len)
        :while next(@mut u64 i) 
            combined = str(combined+segments[i].value+" ")
        end end
    return combined

service main()
    segments = Segment[] // buffer
    :push("I think.":Segment)
    :push("Therefore I am.":Segment)
    print(segments:combine)
    end

