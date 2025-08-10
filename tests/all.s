@include std.builtins
@include std.os

service main()
    // use `to_end` to consume the process to its end - is silent but creates failure on process error
    Process:open("./smol tests/effvec.s"):to_end
    Process:open("./smol tests/file.s"):to_end
    Process:open("./smol tests/finally.s"):to_end
    Process:open("./smol tests/map.s"):to_end
    Process:open("./smol tests/mem.s"):to_end
    Process:open("./smol tests/memtest.s"):to_end
    --