@include std.core
@include std.mem

// TODO: if we can make this work properly, we have finished implementing buffers properly
def HTML(new, @mut char[] output_buffer)
    @mut to_close = str[]
    return @args, to_close  // TODO: returning output_buffer twice create an issue when returning the __dynamic part

def append(@mut char[] buf, String _element)
    element = _element.str()
    range(element.len())
    .while next(@mut u64 i)
        buf.push(element[i])

def append(@access @mut HTML self, String element)
    @mut buf = self.output_buffer
    buf.append(element)

def push(@access @mut HTML self, String _element)
    element = _element.str()
    self.to_close.push(element)
    @mut buf = self.output_buffer
    buf.append("<")
    buf.append(element)
    buf.append(">")
    return self.to_close.len()

def end(@access @mut HTML self, u64 index)
    @mut buf = self.output_buffer
    range((self.to_close.len()+1)-index)
    .while next(@mut u64 i)
        buf.append("</")
        buf.append(self.to_close.pop())
        buf.append(">")


def child(@access @mut HTML self, u64 index, String _element)
    @mut buf = self.output_buffer
    range((self.to_close.len())-index)
    .while next(@mut u64 i)
        buf.append("</")
        buf.append(self.to_close.pop())
        buf.append(">")
    
    element = _element.str()
    self.to_close.push(element)
    buf.append("<")
    buf.append(element)
    buf.append(">")
    return self.to_close.len()


service main()
    @mut memory = Heap.allocate(64.KB())
    @mut buf = char[memory]
    @on new.HTML(buf)
    
    body = push("body")

    state = body.child("div")
    state.child("p") append("my text")
    state.child("p") append("my text2")
    
    body.end()

    @on ok // deactivate html context
    print(memory.str(buf.len()))


