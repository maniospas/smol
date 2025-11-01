@indentation
@include std.core

def test_sgn()
    x = 1.0
    s = algorithm
        if x>0.0 return "positive"
        return "negative" 
    print(s)

def test_while()
    algorithm
        on range(10)
        while next(@mut u64 i)
            if i==5 
                return ok
            print(i)
        return ok
    print("ended")

service main()
    //test_sgn()  
    test_while()
