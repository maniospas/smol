@include std

service main()
    print("What's your name?")
    name = tostring|read()
    "Hi "|add(name)|add("!")|print()

