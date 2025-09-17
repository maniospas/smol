@include std.core -> String // as an example, load only string ops but nothing about numbers
@include std.mem  -> Memory
@include std.os   -> Process

service run(String command)
    @mut process = Process:open(command)
    // read everything there is from the process
    process:to_end
    // Be explicit that the process is released
    // so that nobody accidentally returns it.
    // Releasng checks for failure of incomplete
    // status or non-zero exit code.
    @release process
    --

service std_test(String name)
    on Heap:dynamic // memory surface for string concatenations
        redirect = " 2>&1"
        command = "./smol tests/unit/"+name+".s --runtime eager"+redirect
        --
    on Heap:dynamic // new memory surface because the previous one was mutated by feeding into service call
        if run(command).err:bool
            -> print("[ \033[31mERROR\033[0m ] "+name+".s")
        else 
            -> print("[ \033[32mOK\033[0m ] "+name+".s")
    ----

service main()
    // services are asynchronous co-routines
    std_test("buffers")
    std_test("bbuffer")
    std_test("bufferconst")
    std_test("buffergrow")
    std_test("effvec")
    std_test("fail")
    std_test("file")
    std_test("filesize")
    std_test("finally")
    std_test("map")
    std_test("nom")
    std_test("unsafe")
    std_test("mem")
    std_test("memtest")
    std_test("mutpoint")
    std_test("range_test")
    std_test("ref")
    std_test("strcat")
    std_test("vec")
    std_test("virtfile")
    std_test("accessvar")
    //std_test("release") // THIS IS AN ERROR
    --