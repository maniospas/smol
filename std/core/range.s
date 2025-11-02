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

@include std.core.num
@about 
"Standard library implementation of u64 ranges."
@about range 
"Defines a u64 range as a structural type (instead of nominal type). When directly using variables as ranges, the position should be mutable. A couple of calling conventions are provided for default values of 0 for start and 1 for step."
@about next  
"Obtains the next element in the range. Using a combination of a range and next element traversal is safer than manually checking bounds."
"\n<br><br>Below is the main usage pattern. Notice that next's argument is an in-place constructed u64 number that is mutable to obtain the next value. "
"The function sets the next value, progresses the range's state, and returns whether the iteration ended. The first retrieved value is the starting element of the range. Example:"
"\n<pre>range(10)"
"\n.while next(@mut u64 i)"
"\n    then print(i)</pre>"

def range(u64 start, u64 sup, u64 step) 
    @mut pos = start 
    return @args, pos

def range(u64 start, u64 sup) 
    return range(start,sup,1)

def range(u64 sup)  
    return range(0,sup,1)

def next(
    @access @mut range self, 
    @mut u64 value
)
    value = self.pos 
    self.pos = self.pos+1
    return (self.pos)<=(self.sup) 
