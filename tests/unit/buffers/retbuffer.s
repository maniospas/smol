@include std.core


def strbuf(nominal, @mut str[] ref)
    return @args

def strbuf(String value)
    return nominal.strbuf(str[].push(value.str()))

def put(@access @mut strbuf buf, String value)
    return buf.ref[0] = value.str()

def str(@access @mut strbuf buf) 
    return buf.ref[0].str()

service main()
    @mut boxes = strbuf[]  // must be mutable to grant mutable access
    .push("first element".strbuf())
    .push("second element".strbuf())
    @mut b = boxes[0]
    b.put("overwritten element")
    
    print(b.str())
    print(boxes[0].str())
    print(boxes[1].str())