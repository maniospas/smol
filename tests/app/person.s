@include std.core

def Person(String _name, u64 age)
    name = _name.str()
    return name, age

service main()
    p = Person("bob", 50)
    print(p.name)
    print(p.age)