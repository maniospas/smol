@include std.builtins
    

service main()
    s = "I like bananas!"
    substr = "":str
    s:split(" "):while next(substr) -> print(substr)
    --