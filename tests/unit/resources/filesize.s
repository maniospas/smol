@include std.core
@include std.file

service main()
    ReadFile
    .open("README.md")
    .len()
    .print()
    return nothing
