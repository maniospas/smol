@include std.builtins
@include std.file

service contents(file f)
    ret = str("") 
    while f:ended:not 
        ret = ret+f:chunk
    ---> ret // -- ends while, then -> returns

service main()
    f = file("README.md")
    print(f:contents)
    --
