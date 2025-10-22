@include std.core

def Person(str name, u64 age)
    return @args

service main()
    p = Person("bob".str(), 50)
    print(p.name)
    print(p.age)