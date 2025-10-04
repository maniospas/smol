@include std.core

def test_sgn()
    x = 1.0
    s = capture 
        if x>0.0 return "positive" 
        return "negative"
    print(s)
    end

def test_while()
    value = capture 
        range(10)
        .while next(@mut u64 i)
            if i==5 return i
            print(i)
        end end
    print(value)
    end

service main()
    test_sgn()
    test_while()
    end
