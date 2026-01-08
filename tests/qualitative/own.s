@include std.core
@include std.mem

def test1(@mut ContiguousMemory memory)
    @mut buf = u64[memory]
    buf.push(1)
    buf.push(2)
    buf.push(3)
    return memory


service main()
    @mut mem = Heap.allocate(1.KB())
    @mut mem2 = test1(mem)
    @mut buf = str[mem2].expect(1)
    print(buf[0])
