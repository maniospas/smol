@include std.builtins
@include std.buildstr
@include std.vec

smo elements(nom, vec& v) -> @new
smo raw(vec &v) -> nom:elements(v)
smo invalid(vec v) -> v  // this should be invalid (needs mutating inputs to make the returned pointer mutating)

service main()
    x = vec:rand(1000)
    --