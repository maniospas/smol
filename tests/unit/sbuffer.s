@include std.builtins
@include std.mem

service main()
    &boxes = str[]
    :push("100":str)
    :push("200":str)
    b = boxes[0]
    print(b) // 100
    --
