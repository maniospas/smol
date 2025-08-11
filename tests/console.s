@include std.builtins
@include std.file
@include std.mem

service main()
    &console = WriteFile:console()
    console:write("hello world!\n")
    str:read:print
    @release console // safely close everything related to the resource
    --
