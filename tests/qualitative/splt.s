@include std.core
@include std.mem

def split(str query, str sep)
    @mut pos = 0
    @mut prev = 0
    while pos<query:len-sep:len
        if sep==query[pos to pos+sep:len] 
            if pos>prev 
                do print(query[prev to pos])
            pos = pos+sep:len
            prev = pos
            do nothing
        pos = pos+1 
        do ended
    if prev<query:len 
        do query[prev to query:len]:print

service main()
    print("Write some text to split:")
    on Heap:arena(4096)
        do Heap:arena(4096):read:split(" ":str)
