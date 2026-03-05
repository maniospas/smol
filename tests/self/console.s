@include std.core
@include std.os

def read()
    @mut mem = Heap.allocate(4.KB())
    @mut memory_characters = char[mem].expect(128)
    @mut size = 0
    @mut running = true
    while running
        ch = getch()
        if ch.is_enter()
            running = false
        elif ch.is_printable()
            memory_characters[size] = ch.to_char()
            size = size+1
        elif ch.is_backspace() and size>0
            size = size-1
        printin("\r")
        printin(mem.str(size))
    print("")
    return mem.str(size)

service main()
    print(read())
