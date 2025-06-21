// main.s
@include std.builtins

service main()
    x = 2.0
    y = 3.0
    print("Float division of 2/3")
    print(x/y)
    print("Is float division of 2/0 an infinity?")
    print(isinf(1.0/0.0))
    --