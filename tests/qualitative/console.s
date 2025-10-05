@include std.core
@include std.file
@include std.mem

service main()
    @mut cons = WriteFile.console()
    cons.print("hello world!\n")
    printin("Press enter here to close the open console...")
    Stack.arena(2).read()
    @release cons // safely close the resource preemptively
    print("We are done. Press enter again...")
    Stack.arena(2).read()
