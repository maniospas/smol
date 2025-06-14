// Written in 2025 by Emmanouil Krasanakis (maniospas@hotmail.com)
//
// To the extent possible under law, the author has dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide.
// 
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 

@include std.builtins
@include std.rand

smo vec(nom, ptr contents, u64 size) -> @new
smo vec(u64 size)
    @body{ptr contents = new f64[size]();}
    @finally contents {if(contents)delete[] (f64*)contents; contents=0;}
    -> nom:vec(contents, size)

smo len(vec v) -> v.size
smo slice(vec v, u64 from, u64 to) 
    if from >= to -> fail("Empty vec slice")
    if to > v.size -> fail("Vec out of bounds")
    // so we have 0<=from < to <= v.size
    @body{ptr contents=(ptr)(&((f64*)v__contents)[from]);}
    -> nom:vec(contents, to-from)

smo rand(vec, u64 size)
    @body{ptr contents = new f64[size];}
    @finally contents {if(contents)delete[] (f64*)contents; contents=0;}
    i=0:u64 while i<size @next i = i+1:u64 
        value = rand()
        @body{((f64*)contents)[i] = value;}
    ---> nom:vec(contents, size)

smo at(vec v, u64 pos) 
    if pos>=v.size -> fail("Vec out of bounds")
    @body{f64 value = ((f64*)v__contents)[pos];} 
    -> value

smo put(vec& v, u64 pos, f64 value)
    if pos>=v.size -> fail("Vec out of bounds")
    @body{((f64*)v__contents)[pos] = value;}
    -> v

smo dot(vec x1, vec x2)
    if x1.size!=x2.size -> fail("Incompatible vec sizes")
    x2.size = x1.size // this helps the optimizer
    sum = 0.0
    i=0:u64 while i<x1.size @next i = i+1:u64
        sum = x1:at(i)
                :mul(x2:at(i))
                :add(sum)
    ---> sum 

smo add(vec x1, vec x2)
    if x1.size!=x2.size -> fail("Incompatible vec sizes")
    x2.size = x1.size // this helps the optimizer
    size = x1.size
    @body{ptr contents = new f64[size];}
    @body{for(u64 i=0;i<size;++i) ((f64*)contents)[i] = ((f64*)x1__contents)[i]+((f64*)x2__contents)[i];}
    @finally contents {if(contents)delete[] (f64*)contents; contents=0;}
    -> nom:vec(contents, size)

smo sub(vec x1, vec x2)
    if x1.size!=x2.size -> fail("Incompatible vec sizes")
    x2.size = x1.size // this helps the optimizer
    size = x1.size
    @body{ptr previous = contents;}
    @body{ptr contents = new f64[size];}
    @body{for(u64 i=0;i<size;++i) ((f64*)contents)[i] = ((f64*)x1__contents)[i]-((f64*)x2__contents)[i];}
    @body{if(previous)delete[] (f64*)previous;}
    @finally contents {if(contents)delete[] (f64*)contents; contents=0;}
    -> nom:vec(contents, size)

smo mul(vec x1, vec x2)
    if x1.size!=x2.size -> fail("Incompatible vec sizes")
    x2.size = x1.size // this helps the optimizer
    size = x1.size
    @body{ptr previous = contents;}
    @body{ptr contents = new f64[size];}
    @body{for(u64 i=0;i<size;++i) ((f64*)contents)[i] = ((f64*)x1__contents)[i]*((f64*)x2__contents)[i];}
    @body{if(previous)delete[] (f64*)previous;}
    @finally contents {if(contents)delete[] (f64*)contents; contents=0;}
    -> nom:vec(contents, size)

smo print(vec v)
    size = if v.size>10 -> 10 else -> v.size
    printin("[")
    range(size)
    :while next(u64 pos)
        if pos:bool -> printin(" ")
        printin(v[pos])
        --
    if size!=v.size -> printin(" ...")
    print("]")
    --