@include std.builtins
@include std.os

smo std_test(String _name)
    // use `to_end` to consume the process to its end - is silent but creates failure on process error
    name = _name:str
    on nom:Dynamic
        command = "./smol tests/"+name+".s"
        Process:open(command):to_end
        printin("[ \033[32mOK\033[0m ] ")
        print(name)
    ----

service main()
    std_test("effvec")
    std_test("file")
    std_test("finally")
    std_test("map")
    std_test("mem")
    std_test("memtest")
    --