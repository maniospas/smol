@include std.core

def lambda(tag func, u64 n)
    return @args

def ping(u64 n, cstr message)
    printin(message)
    print("ping")
    return tag.pong.lambda(n)

def pong(u64 n, cstr message)
    if n == 0
        |return tag.done.lambda(u64)
    printin(message)
    print("pong")
    return tag.ping.lambda(n-1)

service main()
    @mut pending = tag.ping.lambda(2)
    while pending.func!=tag.done
        pending = @dynamic(ping,pong) pending("next - ")
    end end 
