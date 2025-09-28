@include std.core
@include std.mem

def split(str query, str sep)
    @mut pos = 0
    @mut prev = 0
    while pos<query.len()-sep.len()
        if sep==query[pos to pos+sep.len()]
            if pos>prev
                print(query[prev to pos])
                end
            pos = pos+sep.len()
            prev = pos
            end
        pos = pos+1 
        end
    if prev<query.len() 
        query[prev to query.len()].print()
    end end

service main()
    print("Write some text to split:")
    on Heap.arena(4096)
        Heap.arena(4096).read().split(" ".str())
    end end
