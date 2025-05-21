@include std.builtins
@include std.file


service contents(file f)
    ret = "":str
    while f:ended:not 
        ret = ret+f:chunk
    ---> ret // -- ends while, then -> returns

smo print(file f)
    accum = "":str
    while f:ended:not
        next = f:chunk
        if next:substr(next:len-1:u64)=="\n":str 
            accum = accum+next:substr(0:u64, next:len-1:u64)
            print(accum) 
            accum = "":str
            --
        else accum = accum+next --
        --
    
    if accum:len:bool print(accum) --
    --

service main()
    path = "README.md"
    if path:isfile:not print("Going to fail") --
    //print(path:file:contents)
    print(path:file)
    --
