@include std.core
@include std.os

service main()
    @mut process = Process.open("./smol tests/unit/effvec.s")
    on Dynamic.volatile(1024)
    process.while next_line(@mut str x)
        then printin(x)
    print("")