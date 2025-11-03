@include std.core
@include std.mem

// TODO: if we can make this work properly, we have finished implementing buffers properly
def HTML(nominal, @mut char[] output_buffer)
    @mut to_close = str[]
    return @args, to_close, output_buffer

def new(@access @mut HTML doc, str _element)
    element = _element.str()
    doc.to_close.push(element)

// def end(@access @mut HTML doc)
//     doc.contents.pop()

service main()
    @mut buf = char[Heap.allocate(MB(1))]
    @mut doc = nominal.HTML(buf)
    new(doc, "div")