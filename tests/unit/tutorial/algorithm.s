@include std.core

service main()
    @mut i = 0
    limit = 5
    algorithm
        while true
            print(i)
            if i==limit
                return ok
            i = i+1
        return ok  // runs if nothing else is returned
    print("ended while")
    print(i)