@include std.core
@include std.mem

def Segment(new, str value)
    // return all inputs 
    // function returns are tuples of named elements
    return @args

def Segment(String _value)
    // convert from many string types
    value = _value.str()
    return new.Segment(value)

def combine(Segment[] segments)
    @mut combined = "".str()  // mutable string with known size
    @on Stack.allocate(1.KB()).arena()      // automatically use as argument if needed (for string operations)
    segments
    .len()
    .range()
    .while next(@mut u64 i)
        combined = (add(@all combined segments[i].value " ")).str()
    return combined

service main()
    segments = Segment[] // buffer
    .push("I think.".Segment())
    .push("Therefore I am.".Segment())
    segments.combine().print()

