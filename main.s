@include std

service square(f64 x) 
    -> x*(x)

service main()
    y = square(2.0)
    print(y)
    print("What's your name?")
    name = str|read()
    "Hi "
        |add(name)
        |add("!")
        |print()
    if(str|from("Manios")==(name)) print("What's up creator?") --
