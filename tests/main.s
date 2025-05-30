@include std.builtins

// declare nominal range
smo range(nom, u64 start, u64 end) -> @new
// call by reference
smo next(range &r, u64 &value)
    value = r.start
    r.start = r.start + 1
    -> r.start <= r.end

service main()
    nom:range(0,10):while next(u64 value) 
        print(value) 
    ----
