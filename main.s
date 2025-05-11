@include std

service get_age() 
    print("What's your age?")
    age = i64:read()
    if(age<=1) fail("Too young for this stuff") --
    if(age>=140) fail("Too old for this stuff") --
    -> age

service main()
    age = get_age()
    while(age.err:bool) age = get_age() --
    print("You've seen at least "
            :add(age:sub(1):str)
            :add(" years gone by."))
    --