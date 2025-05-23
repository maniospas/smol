@include std.builtins
@include std.file

service main()
    f = file("README.md")
    s = "":str while f:ended:not s = s+f:chunk--
    print(s)
    --
