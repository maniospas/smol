@include std.core

service main()
    @mut x = 1
    while x<10
        x = x+1
        printin(@all "x= "x"\n")
        range(10)
        .while next(@mut u64 y)
            printin(@all "y= "(10*x)+y"\n")
            y = y+1