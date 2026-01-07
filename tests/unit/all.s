@include std.core
@include std.mem 
    return Memory
@include std.os  
    return Process
@include std.time
    return time

service run(@own String command)
    @mut process = Process.open(command)
    // read everything there is from the process
    process.to_end()
    // Be explicit that the process is released
    // so that nobody accidentally returns it.
    // Releasing checks for failure of incomplete
    // status or non-zero exit code.
    @release process

service std_test(@own String name)
    @on Heap.dynamic()
    command = add(@all "./smol tests/unit/"name".s --workers 1 --runtime eager 2>&1")

    // new memory surface because the previous one is made immutable by running the command
    // by feeding into a service call
    @on Heap.dynamic()
    if run(command).err.bool()
        printin(@all "[ \033[31mERROR\033[0m ] "name".s\n")
    else 
        printin(@all "[ \033[32mOK\033[0m ] "name".s\n")

service all()
    // services are asynchronous co-routines
    std_test("buffers/buffer")
    std_test("buffers/bbuffer")
    std_test("buffers/bufferconst")
    std_test("buffers/buffergrow")
    std_test("buffers/retbuffer")
    std_test("buffers/servbuf")
    std_test("resources/dynamic")
    std_test("resources/effvec")
    std_test("resources/fail")
    std_test("resources/file")
    std_test("resources/filesize")
    std_test("resources/finally")
    std_test("resources/mem")
    std_test("resources/memtest")
    std_test("resources/map")
    std_test("resources/ref")
    std_test("resources/strcat")
    std_test("resources/vec")
    std_test("resources/virtfile")
    std_test("service/fib")
    std_test("service/infinite")
    std_test("types/accessvar")
    std_test("types/circ")
    std_test("types/dataunion")
    std_test("types/mutpoint")
    std_test("types/nom")
    std_test("types/poly")
    std_test("types/pong")
    std_test("types/range_test")
    std_test("types/union")
    std_test("types/units")
    std_test("sgn")

service main()
    tic = time()
    all().err // force synchronization by waiting for the error code
    printin("Completed in ")
    printin(time()-tic)
    print(" sec")