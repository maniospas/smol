@include std.builtins

smo split(str query, str sep)
    &pos = 0
    &prev = 0
    while pos<query:len-sep:len
        if sep==query[pos to pos+sep:len] 
            if pos>prev -> query[prev to pos]:print
            pos = pos+sep:len
            prev = pos
            --
        pos = pos+1 
        --
    if prev<query:len -> query[prev to query:len]:print
    -- 

service main()
    print("Write some text to split:")
    str:read:split(" ":str)
    --
