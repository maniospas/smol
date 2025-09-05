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

@unsafe
@about "Standard library implementation of vectors that are allocated with safe memory management but use C pointers for element access."
@about print "Prints a vector to the console."
@about slice "Slices a vector from a given to an ending position. This is a transparent view of vector data."

@include std.builtins
@include std.rand
@include std.mem

smo Vec(nom, ptr contents, u64 size, ptr surface) -> @args
smo vector(Memory &memory, u64 size)
    mem = memory:allocate(size,f64)
    range(size):while next(u64 &i) 
        @body{((f64*)mem__mem)[i] = 0;}
    ---> nom:Vec(mem.mem, size, mem.mem)

smo len(Vec v) -> v.size
smo slice(Vec v, u64 from, u64 to) 
    if from >= to -> fail("Empty Vec slice")
    if to > v.size -> fail("Vec out of bounds")
    // so we have 0<=from < to <= v.size
    @body{ptr contents=(ptr)(&((f64*)v__contents)[from]);}
    -> nom:Vec(contents, to-from, v.surface)

smo vector(Memory &memory, Rand &rand, u64 size)
    mem = memory:allocate(size,f64)
    range(size):while next(u64 &i)
        value = rand:next
        @body{((f64*)mem__mem)[i] = value;}
    ---> nom:Vec(mem.mem, size, mem.mem)
smo vector(Rand &rand, Memory &memory, u64 size) 
    -> vector(memory, rand, size)

smo at(Vec v, u64 pos) 
    if pos>=v.size -> fail("Vec out of bounds")
    @body{f64 value = ((f64*)v__contents)[pos];} 
    -> value

smo put(Vec &v, u64 pos, f64 value)
    if pos>=v.size -> fail("Vec out of bounds")
    @body{((f64*)v__contents)[pos] = value;}
    -> v

smo dot(Vec x1, Vec x2)
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    &sum = 0.0
    &i=0 while i<x1.size @next i = i+1
        sum = x1
        :at(i)
        :mul(x2:at(i))
        :add(sum)
    ---> sum 

smo put(Vec &x1, Vec x2)
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    @body{for(u64 i=0;i<size;++i) ((f64*)x1__contents)[i] = ((f64*)x2__contents)[i];}
    --

smo add(Memory &memory, Vec x1, Vec x2)
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = memory:allocate(size,f64)
    @body{for(u64 i=0;i<size;++i) ((f64*)mem__mem)[i] = ((f64*)x1__contents)[i]+((f64*)x2__contents)[i];}
    -> nom:Vec(mem.mem, size, mem.mem)

smo sub(Memory &memory, Vec x1, Vec x2)
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = memory:allocate(size,f64)
    @body{for(u64 i=0;i<size;++i) ((f64*)mem__mem)[i] = ((f64*)x1__contents)[i]-((f64*)x2__contents)[i];}
    -> nom:Vec(mem.mem, size, mem.mem)

smo mul(Memory &memory, Vec x1, Vec x2)
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = memory:allocate(size,f64)
    @body{for(u64 i=0;i<size;++i) ((f64*)mem__mem)[i] = ((f64*)x1__contents)[i]*((f64*)x2__contents)[i];}
    -> nom:Vec(mem.mem, size, mem.mem)

smo div(Memory &memory, Vec x1, Vec x2)
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = memory:allocate(size,f64)
    @body{for(u64 i=0;i<size;++i) ((f64*)mem__mem)[i] = ((f64*)x1__contents)[i]/((f64*)x2__contents)[i];}
    -> nom:Vec(mem.mem, size, mem.mem)

smo add(Vec& result, Vec x1, Vec x2)
    if result.size!=x1.size -> fail("Incompatible Vec sizes")
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    @body{__builtin_assume(result__size==x1__size);}
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = result.contents
    @body{for(u64 i=0;i<size;++i) ((f64*)mem)[i] = ((f64*)x1__contents)[i]+((f64*)x2__contents)[i];}
    -> result

smo sub(Vec& result, Vec x1, Vec x2)
    if result.size!=x1.size -> fail("Incompatible Vec sizes")
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    @body{__builtin_assume(result__size==x1__size);}
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = result.contents
    @body{for(u64 i=0;i<size;++i) ((f64*)mem)[i] = ((f64*)x1__contents)[i]-((f64*)x2__contents)[i];}
    -> result

smo mul(Vec& result, Vec x1, Vec x2)
    if result.size!=x1.size -> fail("Incompatible Vec sizes")
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    @body{__builtin_assume(result__size==x1__size);}
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = result.contents
    @body{for(u64 i=0;i<size;++i) ((f64*)mem)[i] = ((f64*)x1__contents)[i]*((f64*)x2__contents)[i];}
    -> result

smo div(Vec& result, Vec x1, Vec x2)
    if result.size!=x1.size -> fail("Incompatible Vec sizes")
    if x1.size!=x2.size -> fail("Incompatible Vec sizes")
    @body{__builtin_assume(result__size==x1__size);}
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = result.contents
    @body{for(u64 i=0;i<size;++i) ((f64*)mem)[i] = ((f64*)x1__contents)[i]/((f64*)x2__contents)[i];}
    -> result

smo print(Vec v)
    size = if v.size>10 -> 10 else -> v.size
    printin("[")
    range(size)
    :while next(u64 &pos)
        if pos:bool 
            -> printin(" ")
        printin(v[pos])
        --
    if size!=v.size 
        -> printin(" ...")
    print("]")
    --