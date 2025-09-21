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
@about Vec   "Represents a vector stored on contiguous memory. Prefer using the <code>vector</code> initializer, which can also generate vectors "
             "from random number generators. Vectors always hold f64 to ensure that invalid computations are stored as NaNs. They are also "
             "tailored for scientific use, so implementations aim to cut even the smallest corners without compromising safety. Use buffers to work "
             "with collections of u64 data instead."
@about vector "Initializes a vector by using a provided memory allocator. The generated vector is zero-initialized. "
             "You can also provide a Rand random state imported from <code>std.rand</code> to initializ with uniformly random values in [0,1]. "
             "Example of generating a vector of 10 zero elements:<pre>vec = Heap:dynamic:vector(10)</pre>"
@about print "Prints a vector to the console. To avoid large prints, at most the first 10 elements are printed."
@about slice "Slices a vector from a given to an ending position. This is a transparent view of vector data."
@about add   "Adds two vectors element-by-element and stores the result on eiter a third mutable vector also of the same size, or on a "
             "newlly allocated one in the provided memory. This fails if vector sizes are incompatible, or if the provided Memory cannot allocate "
             "the required space. Example where an <code>on</code> context is used to allow operator overloading:"
             "<pre>@mut rnd = Rand()\non Heap:dynamic"
             "\n    v1 = rnd:vector(10)"
             "\n    v2 = rnd:vector(10)"
             "\n    v3 = v1+v2"
             "\n    --</pre>"
@about mul   "Multiplies two vectors element-by-element and stores the result on eiter a third mutable vector also of the same size, or on a "
             "newlly allocated one in the provided memory. This fails if vector sizes are incompatible, or if the provided Memory cannot allocate "
             "the required space. Example where an <code>on</code> context is used to allow operator overloading:"
             "<pre>@mut rnd = Rand()\non Heap:dynamic"
             "\n    v1 = rnd:vector(10)"
             "\n    v2 = rnd:vector(10)"
             "\n    v3 = v1*v2"
             "\n    --</pre>"
@about sub   "Substracts two vectors element-by-element and stores the result on eiter a third mutable vector also of the same size, or on a "
             "newlly allocated one in the provided memory. This fails if vector sizes are incompatible, or if the provided Memory cannot allocate "
             "the required space. Example where an <code>on</code> context is used to allow operator overloading:"
             "<pre>@mut rnd = Rand()\non Heap:dynamic"
             "\n    v1 = rnd:vector(10)"
             "\n    v2 = rnd:vector(10)"
             "\n    v3 = v1-v2"
             "\n    --</pre>"
@about div   "Divides two vectors element-by-element and stores the result on eiter a third mutable vector also of the same size, or on a "
             "newlly allocated one in the provided memory. This fails if vector sizes are incompatible, or if the provided Memory cannot allocate "
             "the required space. Division may create NaN values. Example where an <code>on</code> context is used to allow operator overloading:"
             "<pre>@mut rnd = Rand()\non Heap:dynamic"
             "\n    v1 = rnd:vector(10)"
             "\n    v2 = rnd:vector(10)"
             "\n    v3 = v1/v2"
             "\n    --</pre>"
@about len   "Retrieves the length of a vector."
@about at    "Retrieves a specific f64 element from a vector. This overloads the element access operation like this:<pre>vec = Rand():vector(Heap:dynamic, 10)\nprint(vev[0])</pre>"

@include std.core
@include std.rand
@include std.mem

smo Vec(nominal, ptr contents, u64 size, ptr surface) 
    return @args

smo vector(@mut Memory memory, u64 size)
    mem = memory:allocate(size,f64)
    range(size)
    :while next(@mut u64 i)
        @body{((f64*)mem__mem)[i] = 0;}
    --return nominal:Vec(mem.mem, size, mem.mem)

smo len(@access Vec v) 
    return v.size

smo slice(@access Vec v, u64 from, u64 to) 
    if from >= to 
        return fail("Empty Vec slice")
    if to > v.size
        return fail("Vec out of bounds")
    // so we have 0<=from < to <= v.size
    @body{ptr contents=(ptr)(&((f64*)v__contents)[from]);}
    return nominal:Vec(contents, to-from, v.surface)

smo vector(@mut Memory memory, @mut Rand rand, u64 size)
    mem = memory:allocate(size,f64)
    range(size)
    :while next(@mut u64 i)
        value = rand:next
        @body{((f64*)mem__mem)[i] = value;}
        noreturn
    return nominal:Vec(mem.mem, size, mem.mem)

smo vector(@mut Rand rand, @mut Memory memory, u64 size) 
    return vector(memory, rand, size)

smo at(@access Vec v, u64 pos) 
    if pos>=v.size
        return fail("Vec out of bounds")
    @body{f64 value = ((f64*)v__contents)[pos];} 
    return value

smo put(@access @mut Vec v, u64 pos, f64 value)
    if pos>=v.size
        return fail("Vec out of bounds")
    @body{((f64*)v__contents)[pos] = value;}
    return v

smo dot(@access Vec x1, @access Vec x2)
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @mut sum = 0.0
    @mut i=0 
    while i<x1.size 
        @next i = i+1
        sum = x1
        :at(i)
        :mul(x2:at(i))
        :add(sum)
        noreturn
    return sum 

smo put(@access @mut Vec x1, @access Vec x2)
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    @body{
        for(u64 i=0;i<size;++i) 
            ((f64*)x1__contents)[i] = ((f64*)x2__contents)[i];
    }
    --

smo add(@mut Memory memory, @access Vec x1, @access Vec x2)
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = memory:allocate(size,f64)
    @body{
        for(u64 i=0;i<size;++i)
            ((f64*)mem__mem)[i] = ((f64*)x1__contents)[i]+((f64*)x2__contents)[i];
    }
    return nominal:Vec(mem.mem, size, mem.mem)

smo sub(@mut Memory memory, @access Vec x1, @access Vec x2)
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = memory:allocate(size,f64)
    @body{
        for(u64 i=0;i<size;++i) 
            ((f64*)mem__mem)[i] = ((f64*)x1__contents)[i]-((f64*)x2__contents)[i];
    }
    return nominal:Vec(mem.mem, size, mem.mem)

smo mul(@mut Memory memory, @access Vec x1, @access Vec x2)
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = memory:allocate(size,f64)
    @body{
        for(u64 i=0;i<size;++i) 
            ((f64*)mem__mem)[i] = ((f64*)x1__contents)[i]*((f64*)x2__contents)[i];
    }
    return nominal:Vec(mem.mem, size, mem.mem)

smo div(@mut Memory memory, @access Vec x1, @access Vec x2)
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = memory:allocate(size,f64)
    @body{
        for(u64 i=0;i<size;++i) 
            ((f64*)mem__mem)[i] = ((f64*)x1__contents)[i]/((f64*)x2__contents)[i];
    }
    return nominal:Vec(mem.mem, size, mem.mem)

smo add(@access @mut Vec result, @access Vec x1, @access Vec x2)
    if result.size!=x1.size 
        return fail("Incompatible Vec sizes")
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @body{__builtin_assume(result__size==x1__size);}
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = result.contents
    @body{
        for(u64 i=0;i<size;++i) 
            ((f64*)mem)[i] = ((f64*)x1__contents)[i]+((f64*)x2__contents)[i];
    }
    return result

smo sub(@access @mut Vec result, @access Vec x1, @access Vec x2)
    if result.size!=x1.size 
        return fail("Incompatible Vec sizes")
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @body{__builtin_assume(result__size==x1__size);}
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = result.contents
    @body{
        for(u64 i=0;i<size;++i)
            ((f64*)mem)[i] = ((f64*)x1__contents)[i]-((f64*)x2__contents)[i];
    }
    return result

smo mul(@access @mut Vec result, @access Vec x1, @access Vec x2)
    if result.size!=x1.size 
        return fail("Incompatible Vec sizes")
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @body{__builtin_assume(result__size==x1__size);}
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = result.contents
    @body{
        for(u64 i=0;i<size;++i) 
            ((f64*)mem)[i] = ((f64*)x1__contents)[i]*((f64*)x2__contents)[i];
    }
    return result

smo div(@access @mut Vec result, @access Vec x1, @access Vec x2)
    if result.size!=x1.size 
        return fail("Incompatible Vec sizes")
    if x1.size!=x2.size 
        return fail("Incompatible Vec sizes")
    @body{__builtin_assume(result__size==x1__size);}
    @body{__builtin_assume(x1__size==x2__size);}
    size = x1.size
    mem = result.contents
    @body{
        for(u64 i=0;i<size;++i) 
            ((f64*)mem)[i] = ((f64*)x1__contents)[i]/((f64*)x2__contents)[i];
    }
    return result

smo print(@access Vec v)
    size = 
        if v.size>10 
            return 10 
        else 
            return v.size
    printin("[")
    range(size)
    :while next(@mut u64 pos)
        if pos:bool
            printin(" ")
            noreturn
        printin(v[pos])
        noreturn
    if size!=v.size 
        printin(" ...")
        noreturn
    print("]")
