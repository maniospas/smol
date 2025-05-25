@include std.builtins
@include std.vec

service main()
    v = vec:rand(1000:u64)
    sum = 0.0
    i = 0:u64 
    while i<v:len
        @next i=i+1:u64
        sum = sum+v:at(i) 
        --
    print(sum)
    --