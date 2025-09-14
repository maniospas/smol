@include std.core
@include std.file
@include std.mem

service main()
    @mut console = WriteFile:console()
    console:print("what's your name? ")
    on Stack:arena(1024)
        console:next_line(str& s)
        print("Hi "+s:strip+"!")
        --
    print("Press enter...")
    @release console
    Heap:arena(2):read
    --
