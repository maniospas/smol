@include std.core
@include std.mem

def sing_printer(f64 x)
    @mut i = 0
    while i<u64(x)
        print(i)
        if i==u64(x) 
            return i
        i = i+1
    print("the end")
    return 0

service main()
    x = f64.read()
    x.sing_printer()
