@include std.core
@include std.os

service main()
    @mut process = Process.open("./smol tests/unit/effvec.s")
    @on Dynamic.allocate(1024).circular()
    process
    .while next_line(@mut str x)
        printin(x)
    print("")