@include std.core
@include std.mem

def split(str query, str sep)
    @mut pos = 0
    @mut prev = 0
    while pos<query.len()-sep.len()
        if sep==query[pos to pos+sep.len()]
            if pos>prev
                print(query[prev to pos])
            pos = pos+sep.len()
            prev = pos
        pos = pos+1
    if prev<query.len() 
        query[prev to query.len()].print()

service main()
    print("Write some text to split:")
    Heap.allocate(4096).arena().read().split(" ".str())
