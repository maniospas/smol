@include std.core

def test_sgn()
    x = 1.0
    s = algorithm
        if x>0.0 return "positive"
        return "negative" 
    print(s)

def test_while()
    algorithm
        range(10)
        .while next(@mut u64 i)
            if i==5 return nil
            then print(i)
        return nil
    print("ended")

service main()
    test_sgn()  
    test_while()
