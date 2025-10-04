@include std.core
@include std.vec
@include std.mem
 
service main() 
    rand = Rand(10)
    on Stack.dynamic()
        a = rand.vector(10)
        b = rand.vector(10)
        c = rand.vector(10)
        end
    on Stack.vector(10) 
        result = (a*b*c)+a+b+c
        end
    print(result)

