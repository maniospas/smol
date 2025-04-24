@include std

smo Channel(Buffer in, Buffer out) => @new

service increment(Channel channel, i64 inc)
    while(true)
        v = channel.receive().i64()
        channel.send(v+1)
        => true
    => true

service main()
    buffer buf(1,2,3,4)
    Field f(buf)
    print(f.start.x)

    f.start.x = i64(0)
    print(f.start.x)

    div res(1,0)
    print(res)
