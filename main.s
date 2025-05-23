@include std.builtins

service main()
    x = i64:read
    sgn = 
        if x>0        -> 1
        else->if x==0 -> 0
        else          -> 0-1
    print(sgn)
    --