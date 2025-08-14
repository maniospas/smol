@include std.builtins
@include std.os

service std_test(String name)
    on Heap:allocate_dynamic // memory surface for string concatenations
        command = "./smol tests/"+name+".s --runtime eager"
        Process:open(command):to_end
        print("[ \033[32mOK\033[0m ] "+name)
    ----

service main()
    // services are asynchronous co-routines
    std_test("map")
    std_test("effvec")
    std_test("file")
    std_test("finally")
    std_test("mem")
    std_test("memtest")
    --