@include std.builtins
@include std.os

service std_test(String name)
    on Heap:dynamic// memory surface for string concatenations
        redirect = " 2>&1"
        command = "./smol tests/unit/"+name+".s --runtime eager"+redirect
        if Process:open(command):to_end 
            -> print("[ \033[31mERROR\033[0m ] "+name)
        else 
            -> print("[ \033[32mOK\033[0m ] "+name)
    ----

service main()
    // services are asynchronous co-routines
    std_test("buffers")
    std_test("effvec")
    std_test("file")
    std_test("finally")
    std_test("map")
    std_test("mem")
    std_test("memtest")
    std_test("mutpoint")
    std_test("range_test")
    std_test("ref")
    std_test("strcat")
    std_test("vec")
    std_test("virtfile")
    //std_test("release") // THIS IS AN ERROR
    --