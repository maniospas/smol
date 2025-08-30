@include std.builtins
@include std.file
@include std.mem

service main()
    &console = WriteFile:console()
    console:write("hello world!\n")
    printin("Press enter here to close the open console...")
    str:read
    @release console // safely close the resource preemptively
    print("We are done. Press enter again...")
    str:read
    --
