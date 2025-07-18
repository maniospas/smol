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

@include std.builtins.num
@unsafe
@about "Standard library implementation of the extensible string model based on C pointers and an implementation for const char arrays."
@about str     "A memory allocated string and converters from constant strings and booleans to the type. Other standard library implementations provide more converters."
@about String  "A union between str and constant strings <code>cstr</code>. Constant strings are those that generated by default when enclosing some text in quotients and are stored in the program memory."
               "\n<br><br>Main usage is to abstract an argument's type by converting it to str. The conversion is a zero cost abstraction in that needless operations will be removed. But it still augments constant strings with length and first element inform <i>if these are needed</i>. Here is an example:"
               "\n<pre>smo foo(String _s)"
               "\n    s = _s:str"
               "\n    ..."
               "\n    --</pre>"
@about IndependentString "A copy of the String union that can be used when a second argument is needed for a string of a potentially different variation."
@about is      "Compile-time check of a String exact type matching compared to an arbitrary type.<br>Example usage: <code>smo foo(String s) with s:is(str) ... -- else ...----</code>"
@about print   "Prints strings or bools to the console."
@about printin "Prints strings or bools to the console without evoking a new line at the end."
@about next    "Retrieves the next element over a Split string iteration. Example: <code>Split('I like bananas', ' '):while next(str& word) print(word) --</code>"
@about Split   "Splits a String given a query String. Optionally, you may also provide a starting position, where the default is 0. The result of the split can be iterated through with <code>next</code>. This does not allocate memory in that a substring is retrieved, so you might consider copying the splits - or store them on data structures like maps that automatically copy data if needed."

smo str(nom, ptr contents, u64 length, char first, ptr memory) -> @new
union String(cstr, str)
smo is(String, String) --

smo str(cstr raw)
    @head{#include <string.h>}
    @body{
        u64 length=strlen(raw);
        ptr contents=(ptr)raw;
        char first=raw[0];
        ptr noptr = (ptr)noptr; // use this to indicate a cstr
    }
    -> nom:str(contents, length, first, noptr)

smo str(bool value) 
    @head{cstr __truestr = "true";}
    @head{cstr __falsestr = "false";}
    if value @body{cstr _contents=__truestr;} --
    else @body{cstr _contents=__falsestr;} --
    -> str(_contents)

smo print(cstr message)
    @head{#include <stdio.h>}
    @body{printf("%s\n", message);}
    --

smo print(str message)
    @head{#include <stdio.h>}
    @body{printf("%.*s\n", (int)message__length, (char*)message__contents);}
    --

smo printin(cstr message)
    @head{#include <stdio.h>}
    @body{printf("%s", message);}
    --

smo printin(str message)
    @head{#include <stdio.h>}
    @body{printf("%.*s", (int)message__length, (char*)message__contents);}
    --

smo eq(char x, char y)  
    @body{bool z=(x==y);} 
    -> z

smo neq(char x, char y)
    @body{bool z=(x!=y);}
    -> z

smo slice(String self, u64 from, u64 to) 
    s = self:str
    if to<from @fail{printf("String slice cannot end before it starts\n");} --
    if to>s.length @fail{printf("String slice must end at most at the length of the base string\n");} --
    @body{
        ptr contents = (ptr)((char*)s__contents+from*sizeof(char));
        char first = from==to?'\0':((__builtin_constant_p(from) && from == 0) ? s__first : ((char*)s__contents)[from]);
    }
    -> nom:str(contents, to-from, first, s.contents)
smo slice(String self, u64 from) -> slice(self, from, 0)

union IndependentString(String)
smo eq(String _x, IndependentString _y)
    x = _x:str
    y = _y:str
    @head{#include <string.h>}
    @body{bool z = x__first==y__first && (x__length == y__length) && memcmp((char*)x__contents+1, (char*)y__contents+1, x__length-1) == 0;}
    -> z

smo neq(String _x, IndependentString _y)
    x = _x:str
    y = _y:str
    @head{#include <string.h>}
    @body{
    //printf("x: '%s', length: %zu\n", ((char*)x__contents), x__length - 1);
    //printf("y: '%s', length: %zu\n", ((char*)y__contents), y__length - 1);

    bool z = x__first != y__first ||
             (x__length != y__length) ||
             memcmp((char*)x__contents + 1, (char*)y__contents + 1, x__length - 1) != 0;
}

    -> z

smo len(str x) 
    -> x.length

smo len(cstr x)
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{u64 z = strlen(x);}
    -> z

smo at(str x, u64 pos) 
    if x__length<=pos @fail{printf("String index out of bounds\n");} --
    // trying to help the compiler below, but maybe it's too clever and it can optimize that
    @body{char z= (__builtin_constant_p(pos) && pos == 0) ? x__first: ((char*)x__contents)[pos];} 
    -> z

smo Split(nom, str query, str sep, u64 &pos) 
    -> @new
    
smo Split(String _query, IndependentString _sep) 
    -> nom:Split(_query:str, _sep:str, u64 &pos)

smo next(Split &self, str &value)
    ret = self.pos<self.query:len
    if ret 
        &searching = true
        prev = self.pos
        while (searching==true) and (self.pos<self.query:len-self.sep:len)
            if self.sep==self.query[self.pos to self.pos+self.sep:len] 
                if self.pos>prev value = self.query[prev to self.pos] searching = false --
                self.pos = self.pos+self.sep:len
            -- else 
                self.pos = self.pos+1
            ----
        if searching
            self.pos = self.query:len
            value = self.query[prev to self.pos] 
    -----> ret

