@include std

service main()
    print("What's your name?")
    name = string|read()
    "Hi "|add(name)|add("!")|print()
