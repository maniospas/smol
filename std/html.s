@include std.core
@include std.mem

// TODO: if we can make this work properly, we have finished implementing buffers properly

def move(@mut str from, @mut str[] buf)
    buf.push(from)
    from = "".str()

def HTML(nominal, @mut str[] contents)
    @mut to_close = str[]
    return @args, to_close

def div(@access @mut HTML doc)
    doc.contents.push("<div>":str)
    doc.to_close.push("<div>":str)

def e(@access @mut HTML doc)
    //doc.to_close[doc.to_close.len()] .= doc.contents
    return ok

def div(@access @mut HTML doc)
    //doc.contents.push("<div>".str())
    //doc.to_close.push("<div>".str())
    return ok