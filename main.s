@include std

service square(f64 x) 
    @fail{printf("Don't wanna!\n");}
    -> x*(x)

service main()
    y = square(2.0)|i64()
    print("What's your name?")
    name = str|read()
    "Hi "
        |add(name)
        |add("!")
        |print()
    if(str|from("Manios")==(name)) print("What's up creator?") --
