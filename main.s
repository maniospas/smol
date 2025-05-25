@include std.builtins
@include std.file

service contents(file f)
    ret = "":str 
    while f:ended:not 
        ret = ret+f:chunk
    ---> ret // -- ends while, then -> returns

service main()
    if "README.md":isfile:not print("Going to fail") --
    print("README.md":file:contents)
    --