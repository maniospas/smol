@include std.builtins

smo atrue() print("always true") -> true
smo afalse() print("alwas false") -> false

service main()
    print("Normal conditions")
    true and atrue()
    false or afalse()
    print("The rest are short-circuited away")
    false and atrue()
    true or afalse()
    --