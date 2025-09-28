@include std.core
@include std.mem  return Memory
@include std.os   return Process
@include std.time return time

service run(String command)
    @mut process = Process.open(command)
    // read everything there is from the process
    process.to_end()
    // Be explicit that the process is released
    // so that nobody accidentally returns it.
    // Releasng checks for failure of incomplete
    // status or non-zero exit code.
    @release process
    end

service std_test(String name)
    command = on Heap.dynamic() return "./smol tests/unit/"+name+".s --workers 1 --runtime eager 2>&1"
    // new memory surface because the previous one was made immutable 
    // by feeding into a service call
    on Heap.dynamic()
        if run(command).err.bool()
            print("[ \033[31mERROR\033[0m ] "+name+".s")
        end else
            print("[ \033[32mOK\033[0m ] "+name+".s")
    end end end

service all()
    // services are asynchronous co-routines
    std_test("buffer")
    std_test("bbuffer")
    std_test("bufferconst")
    std_test("buffergrow")
    std_test("effvec")
    std_test("fail")
    std_test("file")
    std_test("filesize")
    std_test("finally")
    //std_test("map")
    std_test("nom")
    //std_test("unsafe")
    std_test("mem")
    std_test("infinite")
    std_test("union")
    std_test("memtest")
    std_test("mutpoint")
    std_test("range_test")
    std_test("ref")
    std_test("strcat")
    std_test("vec")
    std_test("virtfile")
    std_test("accessvar")
    std_test("release") // THIS IS AN ERROR
    end

service main()
    tic = time()
    all().err // force synchronize by waiting to see if ther's an error code
    printin("Completed in ")
    printin(time()-tic)
    print(" sec")
    end