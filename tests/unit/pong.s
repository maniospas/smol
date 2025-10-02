@include std.core

def lambda(symbol func, u64 n)
    return @args

def ping(u64 n, cstr message)
    printin(message)
    print("ping")
    return symbol.pong.lambda(n)

def pong(u64 n, cstr message)
    if n == 0
        |return symbol.done.lambda(u64)
    printin(message)
    print("pong")
    return symbol.ping.lambda(n-1)

service main()
    @mut pending = symbol.ping.lambda(2)
    while pending.func!=symbol.done
        pending = @dynamic pending.func(pending.n, "next - ")
        // if pending.id==symbol.ping
        //     pending = ping(pending.n)
        // elif pending.id==symbol.pong
        //     pending = pong(pending.n)
        // else|end // end the loop (parent block of `if`)
    end end 
