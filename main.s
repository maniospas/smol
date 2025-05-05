@include std

service main()
    print("What's your name?")
    name = str|read()
    print("Hi "+(name)+("!"))
    if(str|from("Manios")==(name)) print("What's up creator?") --
