@include std.core
@include std.os
@unsafe

service main()
    @mut memory = Stack.allocate(4096)
    @mut size = 0
    @mut running = true
    while running
        ch = getch()
        if ch.is_char()
            memory.put(size, ch.to_char())
            size = size+1
        elif ch.is_backspace() and size>0 
            then size = size-1
        printin("\r")
        printin(memory.str(size))
        print()
        then ok
    then ok
