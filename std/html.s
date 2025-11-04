@include std.core
@include std.mem

// TODO: if we can make this work properly, we have finished implementing buffers properly
def HTML(nominal, @mut char[] output_buffer)
    @mut to_close = str[]
    @mut position = 0
    return @args, position, to_close  // TODO: returning output_buffer twice create an issue when returning the __dynamic part

def push(@access @mut HTML self, String _element)
    element = _element.str()
    if self.position>=self.to_close.len() 
        self.to_close.push(element)
    else 
        self.to_close.put(self.position, element)
    self.position = self.position + 1
    range(element.len())
    .while next(@mut u64 i)
        self.output_buffer.push(element[i])
    return self.to_close.len()

def pop(@access @mut HTML self)
    self.position = self.position - 1
    range(self.to_close.len())
    .while next(@mut u64 i)
        self.output_buffer.push(self.to_close[i])


service main()
    @mut buf = char[Heap.allocate(MB(1))]
    @mut doc = nominal.HTML(buf)
    doc.push("div")
    doc.pop()


