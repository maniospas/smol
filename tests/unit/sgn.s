@include std.core

def test_sgn(f64 x)
    s = algorithm
        if x>0.0 
            return "positive"
        return "negative" 
    print(s)

def test_while()
    algorithm range(10)
        .while next(@mut u64 i)
            if i==5 
                return ok
            print(i)
    print("ended")

service main()
    test_sgn(1.0)
    test_sgn(0.0-1.0)  
    test_while()
