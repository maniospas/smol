@include std.num
@include std.err

smo vec(u64 size)
    @body{ptr contents = new f64[size];}
    @finally contents {if(contents)delete (f64*)contents; contents=0;}
    -> contents, size

smo at(vec v, u64 pos) 
    if pos>=v.size fail("Vec out of bounds") --
    @body{f64 value = ((f64*)v__contents)[pos];} 
    -> value

smo put(vec v, u64 pos, f64 value)
    @body{((f64*)v__contents)[pos] = value;}
    -> v

smo dot(vec x1, vec x2)
    if x1.size!=x2.size fail("Incompatible vec sizes") --
    sum = 0.0
    i=0:u64 while i<x1.size @next i = i+1:u64
        sum = x1:at(i)
                :mul(x2:at(i))
                :add(sum)
        --
    -> sum
