@include std.builtins
@include std.vec

service generate() -> vec:rand(1000)

service main()
    v = generate()
    sum = 0.0
    i = 0
    lim = u64:read
    while i<v:len-lim:u64
        @next i=i+1
        sum = sum+v[i]
        --
    print(sum)
    --