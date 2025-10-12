@include std.core

service main()
    @mut i = 0
    limit = 5
    algorithm while true
        print(i)
        if i==limit
            return nil
        then i = i+1
        return nil  // runs if nothing else is returned
    print("ended while")
    print(i)