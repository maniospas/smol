@include std.builtins
@include std.buildstr
@include std.vec

service main()
    x = vec:rand(20)
    print(x)
    --
