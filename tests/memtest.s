@include std.builtins
@include std.mem
@include std.file

smo test()
    f = file("README.md")
    -> nom:chunks(f, 4096, heap)

service test2()
    s = test()
    -> s,1 

service main()
    s = test2()
    --