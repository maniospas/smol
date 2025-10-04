@include std.core

def lambda(tag func, u64 n) 
    return @args

def ping(u64 n, cstr message)
    printin(message)
    print("ping")
    return :pong.lambda(n)

def pong(u64 n, cstr message)
    if n == 0
        return :done.lambda(u64)
    printin(message)
    print("pong")
    return :ping.lambda(n-1)

service main()
    @mut pending = :pong.lambda(2)
    while :done!=pending.func
        pending = 
            @dynamic(ping,pong)
            pending("next - ")
    end end 
