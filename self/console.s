@include std.core
@include std.os

service main()
    @mut memory = Stack.allocate(4096)
    @mut memory_characters = char[memory].expect(128)
    @mut size = 0
    @mut running = true
    @mut input = "".str()

    while running
        ch = getch()
        if ch.is_enter()
            running = false
        elif ch.is_printable()
            memory_characters[size] = ch.to_char()
            size = size+1
        elif ch.is_backspace() and size>0 
            size = size-1
        input = memory.str(size)
        printin("\r")
        printin(input)
        print()
