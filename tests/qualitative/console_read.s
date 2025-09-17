@include std.core
@include std.file
@include std.mem

service main()
    @mut cons = WriteFile:console()
    cons:print("what's your name? ")
    on Stack:arena(1024)
        cons:next_line(str& s)
        print("Hi "+s:strip+"!")
        --
    print("Press enter...")
    @release cons
    Heap:arena(2):read
    --
