@include std.core
@include std.mem

service main()
    boxes = str[]
    :push("buffer start":str)
    :push("buffer end":str)
    b = boxes[0]
    print(b) // 100
