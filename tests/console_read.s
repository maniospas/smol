@include std.builtins
@include std.file
@include std.mem

service main()
    &console = WriteFile:console()
    console:write("what's your name? ")
    on Stack:allocate_arena(1024)
        console:next_line(str& s)
        print("Hi "+s:strip+"!")
        --
    print("Press enter...")
    @release console
    str:read
    --
