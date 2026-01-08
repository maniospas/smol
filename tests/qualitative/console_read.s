@include std.core
@include std.file
@include std.mem

service main()
    @mut cons = WriteFile.console()
    cons.print("what's your name? ")
    @on Stack.allocate(1024).arena()
    cons.next_line(@mut str s)
    print(@all "Hi "s.strip()"!")
    print("Press enter...")
    @release cons
    Heap.allocate(2).arena().read()
