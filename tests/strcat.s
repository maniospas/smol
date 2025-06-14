@include std.builtins
@include std.buildstr
@include std.vec

smo vecbuffer(u64 size)
    next = vec(size)
    prev = vec(size)
    -> next, prev

service main()
    vb = vecbuffer(1000)
    x = vb.prev
    print(x)
    --
