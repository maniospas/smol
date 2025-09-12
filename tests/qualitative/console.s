@include std.builtins
@include std.file
@include std.mem

service main()
    @mut console = WriteFile:console()
    console:print("hello world!\n")
    printin("Press enter here to close the open console...")
    Stack:arena(2):read
    @release console // safely close the resource preemptively
    print("We are done. Press enter again...")
    Stack:arena(2):read
    --
