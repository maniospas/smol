@include std.core
@include std.mem

// TODO: if we can make this work properly, we have finished implementing buffers properly

def move(@mut str from, @mut str[] buf)
    buf:push(from)
    from = "":str
    end

def HTML(nominal, @mut str[] contents)
    @mut toclose = str[]
    return @args, toclose

def div(@access @mut HTML doc)
    doc.contents:push("<div>":str)
    doc.toclose:push("<div>":str)
    end

def e(@access @mut HTML doc)
    doc.toclose[doc.toclose:len]::move(doc.contents)
    end

def div(@access @mut HTML doc)
    doc.contents:push("<div>":str)
    doc.toclose:push("<div>":str)
    end