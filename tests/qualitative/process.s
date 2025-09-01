@include std.builtins
@include std.os

service main()
    &process = Process:open("./smol tests/unit/effvec.s")
    on Dynamic:volatile(1024)
        process
        :while next_line(str &x)
            printin(x)
        ----
    print("")
    --